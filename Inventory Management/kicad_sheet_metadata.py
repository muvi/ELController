#
# KiCad python module for reading sheet meta data from a given netlist
#
# Remember these files use UTF8 encoding
#
# No string formatting is used on purpose as the only string formatting that
# is current compatible with python 2.4+ to 3.0+ is the '%' method, and that
# is due to be deprecated in 3.0+ soon
#

"""
    @package
    Helper module for reading sheet meta data
"""


from __future__ import print_function
from enum import Enum
import kicad_netlist_reader

class kicad_token(Enum):
    BEGIN = 1
    END = 2
    VALUE = 3

class kicad_element():
    def __init__(self, parent):
        self.parent = parent
        self.values = []
        self.children = {}
    
    def getValue(self, index=0):
        return self.values[index]
    
    def getValues(self):
        return self.values
    
    def getChild(self, name):
        return self.children[name]
    
    def getChildren(self):
        return self.children
    
    def getParent(self):
        return self.parent
    
    def addValue(self, value):
        self.values.append(value)
    
    def addChild(self, childName):
        child = kicad_element(self)
        self.children[childName] = child
        return child

class kicad_parser():
    
    def __init__(self, fname):
        file = open(fname)
        tokens = self.lex(file)
        self.ast = self.parse(tokens)
    
    def getRoot(self):
        return self.ast
    
    def get(self, path, index = 0):
        currentElement = self.ast
        for p in path:
            currentElement = currentElement.getChild(p)
        values = currentElement.getValues()
        if index < 0:
            return values
        elif index >= len(values):
            return None
        else: return values[index]
    
    def lex(self, file):
        tokens = []
        value = ''
        valueStarted = False
        quoteOpen = False
        quoteClosed = False
        content = file.read()
        
        for c in content:
            processOtherTokens = True
            
            if valueStarted:
                if quoteClosed:
                    if c == '"':
                        quoteClosed = False
                        value += '"'
                        processOtherTokens = False
                    else:
                        tokens.append((kicad_token.VALUE, value))
                        value = ''
                        quoteOpen = False
                        quoteClosed = False
                        valueStarted = False
                elif quoteOpen:
                    processOtherTokens = False
                    if c == '"':
                        quoteClosed = True
                    else:
                        value += c
                elif c in ['(', ')', ' ', '\n', '\t', '"']:
                    tokens.append((kicad_token.VALUE, value))
                    value = ''
                    quoteOpen = False
                    quoteClosed = False
                    valueStarted = False
                else:
                    value += c
                    processOtherTokens = False
        
            if processOtherTokens:
                if c == '(':
                    tokens.append((kicad_token.BEGIN, '('))
                elif c == ')':
                    tokens.append((kicad_token.END, '('))
                elif c in [' ', '\t', '\n']:
                    pass
                elif c == '"':
                    valueStarted = True
                    quoteOpen = True
                else:
                    valueStarted = True
                    value = c
        return tokens
    
    def expect(self, value, expected):
        if value != expected:
            raise IOError(value + ' got, but ' + expected + ' expected')
    
    def parse(self, tokens):
        currentElement = kicad_element(None)
        result = currentElement
        newElement = False
        i = 0
        for (token, value) in tokens:
            if i == 0:
                self.expect(token, kicad_token.BEGIN)
                i = 1
            elif i == 1:
                self.expect(token, kicad_token.VALUE)
                self.expect(value, 'kicad_sch')
                i = 2
            elif newElement:
                self.expect(token, kicad_token.VALUE)
                currentElement = currentElement.addChild(value)
                newElement = False
            elif token == kicad_token.BEGIN:
                newElement = True
            elif token == kicad_token.END:
                currentElement = currentElement.getParent()
            elif token == kicad_token.VALUE:
                currentElement.addValue(value)
            else:
                raise IOError(token + ' is not a valid token')
        return result

class sheet_metadata():

    def __init__(self, netlist):
        file = netlist.getSource()
        try:
            self.parser = kicad_parser(file)
        except IOError as e:
            print( __file__, ":", e, file=sys.stderr )
            sys.exit(-1)
    
    def getTitle(self):
        return self.parser.get(['title_block', 'title'])
    
    def getRevision(self):
        return self.parser.get(['title_block', 'rev'])
    
    def getUUID(self):
        return self.parser.get(['uuid'])
    
    def getField(self, fieldPath, index = 0):
        return self.parser.get(fieldPath, index)
