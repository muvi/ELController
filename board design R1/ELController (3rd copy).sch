EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
Title "EL Controller"
Date "2021-10-16"
Rev "0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:Q_NMOS_DGS Q2
U 1 1 61C657FD
P 6750 5150
F 0 "Q2" H 6955 5196 50  0000 L CNN
F 1 "TN2130" H 6955 5105 50  0000 L CNN
F 2 "" H 6950 5250 50  0001 C CNN
F 3 "~" H 6750 5150 50  0001 C CNN
	1    6750 5150
	-1   0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_DGS Q4
U 1 1 61CAA215
P 10350 5150
F 0 "Q4" H 10555 5196 50  0000 L CNN
F 1 "TN2130" H 10555 5105 50  0000 L CNN
F 2 "" H 10550 5250 50  0001 C CNN
F 3 "~" H 10350 5150 50  0001 C CNN
	1    10350 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R15
U 1 1 61D01942
P 9250 4150
F 0 "R15" H 9320 4196 50  0000 L CNN
F 1 "1meg" H 9320 4105 50  0000 L CNN
F 2 "1meg" V 9180 4150 50  0001 C CNN
F 3 "~" H 9250 4150 50  0001 C CNN
	1    9250 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_DGS Q3
U 1 1 61E907DD
P 10350 4300
F 0 "Q3" H 10555 4254 50  0000 L CNN
F 1 "TP5335" H 10555 4345 50  0000 L CNN
F 2 "" H 10550 4400 50  0001 C CNN
F 3 "~" H 10350 4300 50  0001 C CNN
	1    10350 4300
	1    0    0    1   
$EndComp
$Comp
L Device:Q_PMOS_DGS Q1
U 1 1 61E9A9B6
P 6750 4300
F 0 "Q1" H 6955 4254 50  0000 L CNN
F 1 "TP5335" H 6955 4345 50  0000 L CNN
F 2 "" H 6950 4400 50  0001 C CNN
F 3 "~" H 6750 4300 50  0001 C CNN
	1    6750 4300
	-1   0    0    1   
$EndComp
Wire Wire Line
	6650 5450 6650 5350
Wire Wire Line
	10450 5450 10450 5350
Wire Wire Line
	10450 4000 10450 4100
Wire Wire Line
	6650 4000 6650 4100
$Comp
L Diode:BZM55Cxx D4
U 1 1 61FA4971
P 9850 4150
F 0 "D4" V 9804 4230 50  0000 L CNN
F 1 "ZMM5235B" V 9895 4230 50  0000 L CNN
F 2 "Diode_SMD:D_MicroMELF" H 9850 3975 50  0001 C CNN
F 3 "http://www.vishay.com/docs/85597/bzm55.pdf" H 9850 4150 50  0001 C CNN
	1    9850 4150
	0    1    1    0   
$EndComp
$Comp
L Diode:BZM55Cxx D3
U 1 1 61FC7B68
P 7000 5300
F 0 "D3" V 6954 5380 50  0000 L CNN
F 1 "ZMM5235B" V 7045 5380 50  0000 L CNN
F 2 "Diode_SMD:D_MicroMELF" H 7000 5125 50  0001 C CNN
F 3 "http://www.vishay.com/docs/85597/bzm55.pdf" H 7000 5300 50  0001 C CNN
	1    7000 5300
	0    1    1    0   
$EndComp
Wire Wire Line
	6650 5450 7000 5450
Wire Wire Line
	6950 5150 7000 5150
$Comp
L Device:R R16
U 1 1 61FD2F23
P 9250 4450
F 0 "R16" H 9320 4496 50  0000 L CNN
F 1 "1meg" H 9320 4405 50  0000 L CNN
F 2 "" V 9180 4450 50  0001 C CNN
F 3 "~" H 9250 4450 50  0001 C CNN
	1    9250 4450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R10
U 1 1 61DE1D7A
P 7550 5300
F 0 "R10" H 7620 5346 50  0000 L CNN
F 1 "1meg" H 7620 5255 50  0000 L CNN
F 2 "" V 7480 5300 50  0001 C CNN
F 3 "~" H 7550 5300 50  0001 C CNN
	1    7550 5300
	1    0    0    -1  
$EndComp
Connection ~ 7000 5450
Wire Wire Line
	7550 5450 7000 5450
Wire Wire Line
	7000 5150 7550 5150
Connection ~ 7000 5150
$Comp
L Diode:BZM55Cxx D5
U 1 1 61FEA854
P 9950 5300
F 0 "D5" V 9904 5380 50  0000 L CNN
F 1 "ZMM5235B" V 9995 5380 50  0000 L CNN
F 2 "Diode_SMD:D_MicroMELF" H 9950 5125 50  0001 C CNN
F 3 "http://www.vishay.com/docs/85597/bzm55.pdf" H 9950 5300 50  0001 C CNN
	1    9950 5300
	0    1    1    0   
$EndComp
Connection ~ 9950 5450
Wire Wire Line
	9950 5450 10450 5450
$Comp
L Device:R R17
U 1 1 61FEBF08
P 9600 5300
F 0 "R17" H 9670 5346 50  0000 L CNN
F 1 "1meg" H 9670 5255 50  0000 L CNN
F 2 "" V 9530 5300 50  0001 C CNN
F 3 "~" H 9600 5300 50  0001 C CNN
	1    9600 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 5450 9950 5450
Wire Wire Line
	9600 5150 9950 5150
Connection ~ 9950 5150
Wire Wire Line
	9950 5150 10150 5150
$Comp
L Diode:BZM55Cxx D2
U 1 1 61FEF10B
P 7000 4150
F 0 "D2" V 6954 4230 50  0000 L CNN
F 1 "ZMM5235B" V 7045 4230 50  0000 L CNN
F 2 "Diode_SMD:D_MicroMELF" H 7000 3975 50  0001 C CNN
F 3 "http://www.vishay.com/docs/85597/bzm55.pdf" H 7000 4150 50  0001 C CNN
	1    7000 4150
	0    1    1    0   
$EndComp
Connection ~ 7000 4000
Wire Wire Line
	7000 4000 6650 4000
$Comp
L Device:R R8
U 1 1 61FEFE02
P 8000 4150
F 0 "R8" H 8070 4196 50  0000 L CNN
F 1 "1meg" H 8070 4105 50  0000 L CNN
F 2 "" V 7930 4150 50  0001 C CNN
F 3 "~" H 8000 4150 50  0001 C CNN
	1    8000 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9850 4000 10450 4000
Wire Wire Line
	9850 4300 10150 4300
Connection ~ 9850 4000
Wire Wire Line
	6950 4300 7000 4300
$Comp
L Device:R R9
U 1 1 6202C51E
P 8000 4450
F 0 "R9" H 8070 4496 50  0000 L CNN
F 1 "1meg" H 8070 4405 50  0000 L CNN
F 2 "" V 7930 4450 50  0001 C CNN
F 3 "~" H 8000 4450 50  0001 C CNN
	1    8000 4450
	1    0    0    -1  
$EndComp
Connection ~ 8000 4300
$Comp
L Device:R R3
U 1 1 6206543C
P 6950 4650
F 0 "R3" V 7157 4650 50  0000 C CNN
F 1 "470" V 7066 4650 50  0000 C CNN
F 2 "" V 6880 4650 50  0001 C CNN
F 3 "~" H 6950 4650 50  0001 C CNN
	1    6950 4650
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R24
U 1 1 620986F4
P 10700 4650
F 0 "R24" V 10907 4650 50  0000 C CNN
F 1 "470" V 10816 4650 50  0000 C CNN
F 2 "" V 10630 4650 50  0001 C CNN
F 3 "~" H 10700 4650 50  0001 C CNN
	1    10700 4650
	0    -1   -1   0   
$EndComp
Connection ~ 9250 4300
$Comp
L Connector_Generic:Conn_01x02 J3
U 1 1 61E0AF16
P 8600 6000
F 0 "J3" V 8472 5812 50  0000 R CNN
F 1 "JST SM" V 8563 5812 50  0000 R CNN
F 2 "" H 8600 6000 50  0001 C CNN
F 3 "~" H 8600 6000 50  0001 C CNN
	1    8600 6000
	0    -1   1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 61E4B678
P 8300 1550
F 0 "R6" V 8093 1550 50  0000 C CNN
F 1 "560" V 8184 1550 50  0000 C CNN
F 2 "" V 8230 1550 50  0001 C CNN
F 3 "~" H 8300 1550 50  0001 C CNN
	1    8300 1550
	0    1    1    0   
$EndComp
$Comp
L Device:R R11
U 1 1 61E57BE8
P 8600 1650
F 0 "R11" V 8807 1650 50  0000 C CNN
F 1 "1k2" V 8716 1650 50  0000 C CNN
F 2 "" V 8530 1650 50  0001 C CNN
F 3 "~" H 8600 1650 50  0001 C CNN
	1    8600 1650
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R13
U 1 1 61E57BEE
P 8900 1750
F 0 "R13" V 9107 1750 50  0000 C CNN
F 1 "2k2" V 9016 1750 50  0000 C CNN
F 2 "" V 8830 1750 50  0001 C CNN
F 3 "~" H 8900 1750 50  0001 C CNN
	1    8900 1750
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R18
U 1 1 61E5D082
P 9200 1850
F 0 "R18" V 9407 1850 50  0000 C CNN
F 1 "4k7" V 9316 1850 50  0000 C CNN
F 2 "" V 9130 1850 50  0001 C CNN
F 3 "~" H 9200 1850 50  0001 C CNN
	1    9200 1850
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R12
U 1 1 61E5D094
P 8600 2050
F 0 "R12" V 8393 2050 50  0000 C CNN
F 1 "1k2" V 8484 2050 50  0000 C CNN
F 2 "" V 8530 2050 50  0001 C CNN
F 3 "~" H 8600 2050 50  0001 C CNN
	1    8600 2050
	0    1    1    0   
$EndComp
$Comp
L Device:R R14
U 1 1 61E6067C
P 8900 2150
F 0 "R14" V 9107 2150 50  0000 C CNN
F 1 "2k2" V 9016 2150 50  0000 C CNN
F 2 "" V 8830 2150 50  0001 C CNN
F 3 "~" H 8900 2150 50  0001 C CNN
	1    8900 2150
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R19
U 1 1 61E60682
P 9200 2250
F 0 "R19" V 8993 2250 50  0000 C CNN
F 1 "4k7" V 9084 2250 50  0000 C CNN
F 2 "" V 9130 2250 50  0001 C CNN
F 3 "~" H 9200 2250 50  0001 C CNN
	1    9200 2250
	0    1    1    0   
$EndComp
$Comp
L Device:R R7
U 1 1 61E60688
P 8300 1950
F 0 "R7" V 8507 1950 50  0000 C CNN
F 1 "560" V 8416 1950 50  0000 C CNN
F 2 "" V 8230 1950 50  0001 C CNN
F 3 "~" H 8300 1950 50  0001 C CNN
	1    8300 1950
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR012
U 1 1 61EBD7DC
P 6850 2700
F 0 "#PWR012" H 6850 2450 50  0001 C CNN
F 1 "GND" H 6855 2527 50  0000 C CNN
F 2 "" H 6850 2700 50  0001 C CNN
F 3 "" H 6850 2700 50  0001 C CNN
	1    6850 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R22
U 1 1 61EE835E
P 6650 1950
F 0 "R22" V 6443 1950 50  0000 C CNN
F 1 "10k" V 6534 1950 50  0000 C CNN
F 2 "" V 6580 1950 50  0001 C CNN
F 3 "~" H 6650 1950 50  0001 C CNN
	1    6650 1950
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 6238FCB8
P 8250 6150
F 0 "C?" V 7998 6150 50  0000 C CNN
F 1 "C" V 8089 6150 50  0000 C CNN
F 2 "" H 8288 6000 50  0001 C CNN
F 3 "~" H 8250 6150 50  0001 C CNN
	1    8250 6150
	0    1    1    0   
$EndComp
Text Notes 8650 6200 0    50   ~ 0
Filter output!
Wire Wire Line
	10450 4500 10450 4800
Wire Wire Line
	6650 4500 6650 4800
Text GLabel 10100 1550 2    50   Output ~ 0
CONFIG1
Text GLabel 10100 1950 2    50   Output ~ 0
CONFIG2
Text GLabel 7050 4850 0    50   Input ~ 0
CH1+
$Comp
L power:+3V3 #PWR?
U 1 1 624A5E19
P 10950 4650
F 0 "#PWR?" H 10950 4500 50  0001 C CNN
F 1 "+3V3" H 10965 4823 50  0000 C CNN
F 2 "" H 10950 4650 50  0001 C CNN
F 3 "" H 10950 4650 50  0001 C CNN
	1    10950 4650
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 624A738B
P 6750 4650
F 0 "#PWR?" H 6750 4500 50  0001 C CNN
F 1 "+3V3" H 6765 4823 50  0000 C CNN
F 2 "" H 6750 4650 50  0001 C CNN
F 3 "" H 6750 4650 50  0001 C CNN
	1    6750 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	10850 4650 10950 4650
Wire Wire Line
	6650 4800 6150 4800
Wire Wire Line
	6150 4800 6150 5800
Connection ~ 6650 4800
Wire Wire Line
	6650 4800 6650 4950
Wire Wire Line
	10450 4800 10900 4800
Wire Wire Line
	10900 4800 10900 5800
Connection ~ 10450 4800
Wire Wire Line
	10450 4800 10450 4950
$Comp
L MCU_Microchip_SAMD:ATSAMD21G15B-A U?
U 1 1 6256D24A
P 2550 5150
F 0 "U?" H 2550 3161 50  0000 C CNN
F 1 "ATSAMD21G15B-A" H 2550 3070 50  0000 C CNN
F 2 "Package_QFP:TQFP-48_7x7mm_P0.5mm" H 3450 3300 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/SAM_D21_DA1_Family_Data%20Sheet_DS40001882E.pdf" H 2550 6150 50  0001 C CNN
	1    2550 5150
	1    0    0    -1  
$EndComp
$Sheet
S 5050 900  950  1150
U 625B9D7D
F0 "Power supply" 50
F1 "power.sch" 50
$EndSheet
$Sheet
S 3850 2250 1050 950 
U 625DE2BD
F0 "connectivity" 50
F1 "connectivity.sch" 50
$EndSheet
Text GLabel 1850 3550 0    50   Input ~ 0
XIN32
Text GLabel 1850 3650 0    50   Input ~ 0
XOUT32
Text GLabel 1850 3750 0    50   Input ~ 0
CONFIG1
Text GLabel 1850 3850 0    50   Input ~ 0
VREF
Text GLabel 1850 3950 0    50   Input ~ 0
CONFIG2
Text GLabel 1850 4050 0    50   Input ~ 0
CONFIG3
Text GLabel 1850 4150 0    50   Input ~ 0
CH1+
Text GLabel 1850 4250 0    50   Input ~ 0
CH1-
Text GLabel 1850 4350 0    50   Input ~ 0
CH2+
Text GLabel 1850 4450 0    50   Input ~ 0
CH2-
Text GLabel 1850 4550 0    50   Input ~ 0
CH3+
Text GLabel 1850 4650 0    50   Input ~ 0
CH3-
Text GLabel 1850 4750 0    50   Input ~ 0
CH4+
Text GLabel 1850 4850 0    50   Input ~ 0
CH4-
Text GLabel 1850 4950 0    50   Input ~ 0
GPIO1
Text GLabel 1850 5050 0    50   Input ~ 0
GPIO2
Text GLabel 1850 5150 0    50   Input ~ 0
GPIO3
Text GLabel 1850 5250 0    50   Input ~ 0
GPIO4
Text GLabel 1850 5350 0    50   Input ~ 0
CH5+
Text GLabel 1850 5450 0    50   Input ~ 0
CH5-
Text GLabel 1850 5550 0    50   Input ~ 0
GPIO5
Text GLabel 1850 5650 0    50   Input ~ 0
GPIO6
Text GLabel 1850 5750 0    50   Input ~ 0
DMX_TX
Text GLabel 1850 5850 0    50   Input ~ 0
DMX_RX
Text GLabel 1850 5950 0    50   Input ~ 0
USB_D-
Text GLabel 1850 6050 0    50   Input ~ 0
USB_D+
Text GLabel 1850 6250 0    50   Input ~ 0
LED1
Text GLabel 1850 6350 0    50   Input ~ 0
LED2
Text GLabel 1850 6550 0    50   Input ~ 0
SWCLK
Text GLabel 1850 6650 0    50   Input ~ 0
SWDIO
Text GLabel 1850 6850 0    50   Input ~ 0
RESET
Text GLabel 3250 3750 2    50   Input ~ 0
CH6+
Text GLabel 3250 3850 2    50   Input ~ 0
CH6-
Text GLabel 3250 4350 2    50   Input ~ 0
CH7+
Text GLabel 3250 4450 2    50   Input ~ 0
CH7-
Text GLabel 3250 4550 2    50   Input ~ 0
CH8+
Text GLabel 3250 4650 2    50   Input ~ 0
CH8-
Text GLabel 3250 5750 2    50   Input ~ 0
CH9+
Text GLabel 3250 5850 2    50   Input ~ 0
CH9-
$Comp
L power:GND #PWR?
U 1 1 6268E12D
P 3100 7050
F 0 "#PWR?" H 3100 6800 50  0001 C CNN
F 1 "GND" H 3105 6877 50  0000 C CNN
F 2 "" H 3100 7050 50  0001 C CNN
F 3 "" H 3100 7050 50  0001 C CNN
	1    3100 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 7050 2650 7050
Connection ~ 2650 7050
Wire Wire Line
	2650 7050 3100 7050
$Comp
L power:+3V3 #PWR?
U 1 1 6269C515
P 2450 3100
F 0 "#PWR?" H 2450 2950 50  0001 C CNN
F 1 "+3V3" H 2465 3273 50  0000 C CNN
F 2 "" H 2450 3100 50  0001 C CNN
F 3 "" H 2450 3100 50  0001 C CNN
	1    2450 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 3250 2550 3250
Wire Wire Line
	2450 3250 2450 3100
Connection ~ 2450 3250
Connection ~ 2550 3250
Wire Wire Line
	2550 3250 2450 3250
$Comp
L power:+3.3VA #PWR?
U 1 1 626A3560
P 2850 3100
F 0 "#PWR?" H 2850 2950 50  0001 C CNN
F 1 "+3.3VA" H 2865 3273 50  0000 C CNN
F 2 "" H 2850 3100 50  0001 C CNN
F 3 "" H 2850 3100 50  0001 C CNN
	1    2850 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 3100 2850 3250
$Comp
L Device:C C?
U 1 1 626B8ABB
P 1200 3400
F 0 "C?" H 1315 3446 50  0000 L CNN
F 1 "1uF" H 1315 3355 50  0000 L CNN
F 2 "" H 1238 3250 50  0001 C CNN
F 3 "~" H 1200 3400 50  0001 C CNN
	1    1200 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 3250 1200 3250
$Comp
L power:GND #PWR?
U 1 1 626C3E48
P 1200 3550
F 0 "#PWR?" H 1200 3300 50  0001 C CNN
F 1 "GND" H 1205 3377 50  0000 C CNN
F 2 "" H 1200 3550 50  0001 C CNN
F 3 "" H 1200 3550 50  0001 C CNN
	1    1200 3550
	1    0    0    -1  
$EndComp
Text Notes 250  3150 0    50   ~ 0
ESR of at most 1 ohm required.\nHowever a cheap ceramic capacitor is available.\nCeramic capacitors usually have low ESR.
$Comp
L Device:C C?
U 1 1 62715A86
P 1400 1150
F 0 "C?" H 1515 1196 50  0000 L CNN
F 1 "100nF" H 1515 1105 50  0000 L CNN
F 2 "" H 1438 1000 50  0001 C CNN
F 3 "~" H 1400 1150 50  0001 C CNN
	1    1400 1150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 62738205
P 1900 1150
F 0 "C?" H 2015 1196 50  0000 L CNN
F 1 "100nF" H 2015 1105 50  0000 L CNN
F 2 "" H 1938 1000 50  0001 C CNN
F 3 "~" H 1900 1150 50  0001 C CNN
	1    1900 1150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 62738A18
P 2400 1150
F 0 "C?" H 2515 1196 50  0000 L CNN
F 1 "100nF" H 2515 1105 50  0000 L CNN
F 2 "" H 2438 1000 50  0001 C CNN
F 3 "~" H 2400 1150 50  0001 C CNN
	1    2400 1150
	1    0    0    -1  
$EndComp
$Comp
L Device:Ferrite_Bead FB?
U 1 1 627422F9
P 3700 1150
F 0 "FB?" V 3426 1150 50  0000 C CNN
F 1 "50@20MHz, 220@100MHz" V 3517 1150 50  0000 C CNN
F 2 "" V 3630 1150 50  0001 C CNN
F 3 "~" H 3700 1150 50  0001 C CNN
	1    3700 1150
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 6274CD70
P 950 1150
F 0 "C?" H 1065 1196 50  0000 L CNN
F 1 "10uF" H 1065 1105 50  0000 L CNN
F 2 "" H 988 1000 50  0001 C CNN
F 3 "~" H 950 1150 50  0001 C CNN
	1    950  1150
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 6274DE51
P 950 900
F 0 "#PWR?" H 950 750 50  0001 C CNN
F 1 "+3V3" H 965 1073 50  0000 C CNN
F 2 "" H 950 900 50  0001 C CNN
F 3 "" H 950 900 50  0001 C CNN
	1    950  900 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 6274E670
P 950 1400
F 0 "#PWR?" H 950 1150 50  0001 C CNN
F 1 "GND" H 955 1227 50  0000 C CNN
F 2 "" H 950 1400 50  0001 C CNN
F 3 "" H 950 1400 50  0001 C CNN
	1    950  1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 1300 1900 1300
Wire Wire Line
	950  1300 950  1400
Connection ~ 950  1300
Connection ~ 1400 1300
Wire Wire Line
	1400 1300 950  1300
Connection ~ 1900 1300
Wire Wire Line
	1900 1300 1400 1300
Wire Wire Line
	2400 1000 1900 1000
Wire Wire Line
	950  1000 950  900 
Connection ~ 950  1000
Connection ~ 1400 1000
Wire Wire Line
	1400 1000 950  1000
Connection ~ 1900 1000
Wire Wire Line
	1900 1000 1400 1000
$Comp
L Device:C C?
U 1 1 62761E5B
P 4050 1300
F 0 "C?" H 4165 1346 50  0000 L CNN
F 1 "10uF" H 4165 1255 50  0000 L CNN
F 2 "" H 4088 1150 50  0001 C CNN
F 3 "~" H 4050 1300 50  0001 C CNN
	1    4050 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 627628D0
P 4550 1300
F 0 "C?" H 4665 1346 50  0000 L CNN
F 1 "100nF" H 4665 1255 50  0000 L CNN
F 2 "" H 4588 1150 50  0001 C CNN
F 3 "~" H 4550 1300 50  0001 C CNN
	1    4550 1300
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 62763A34
P 3050 1050
F 0 "#PWR?" H 3050 900 50  0001 C CNN
F 1 "+3V3" H 3065 1223 50  0000 C CNN
F 2 "" H 3050 1050 50  0001 C CNN
F 3 "" H 3050 1050 50  0001 C CNN
	1    3050 1050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR?
U 1 1 627665BF
P 4550 1050
F 0 "#PWR?" H 4550 900 50  0001 C CNN
F 1 "+3.3VA" H 4565 1223 50  0000 C CNN
F 2 "" H 4550 1050 50  0001 C CNN
F 3 "" H 4550 1050 50  0001 C CNN
	1    4550 1050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62768583
P 4550 1550
F 0 "#PWR?" H 4550 1300 50  0001 C CNN
F 1 "GND" H 4555 1377 50  0000 C CNN
F 2 "" H 4550 1550 50  0001 C CNN
F 3 "" H 4550 1550 50  0001 C CNN
	1    4550 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 1150 4050 1150
Wire Wire Line
	4550 1150 4550 1050
Connection ~ 4550 1150
Connection ~ 4050 1150
Wire Wire Line
	4050 1150 4550 1150
Wire Wire Line
	4050 1450 4550 1450
Wire Wire Line
	4550 1450 4550 1550
Connection ~ 4550 1450
Wire Wire Line
	3550 1150 3050 1150
Wire Wire Line
	3050 1150 3050 1050
$Comp
L Device:Crystal_GND23 Y?
U 1 1 6285A245
P 2850 1800
F 0 "Y?" H 3050 2050 50  0000 L CNN
F 1 "SSP-T7-F, MS1V-T1K" H 3050 1950 50  0000 L CNN
F 2 "" H 2850 1800 50  0001 C CNN
F 3 "~" H 2850 1800 50  0001 C CNN
	1    2850 1800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 628AB208
P 2850 2100
F 0 "#PWR?" H 2850 1850 50  0001 C CNN
F 1 "GND" H 2855 1927 50  0000 C CNN
F 2 "" H 2850 2100 50  0001 C CNN
F 3 "" H 2850 2100 50  0001 C CNN
	1    2850 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 628AF0C3
P 3200 1950
F 0 "C?" H 3315 1996 50  0000 L CNN
F 1 "15pF" H 3315 1905 50  0000 L CNN
F 2 "" H 3238 1800 50  0001 C CNN
F 3 "~" H 3200 1950 50  0001 C CNN
	1    3200 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 628AFA2E
P 2500 1950
F 0 "C?" H 2200 2000 50  0000 L CNN
F 1 "15pF" H 2200 1900 50  0000 L CNN
F 2 "" H 2538 1800 50  0001 C CNN
F 3 "~" H 2500 1950 50  0001 C CNN
	1    2500 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 1800 3200 1800
Wire Wire Line
	2500 2100 2650 2100
Connection ~ 2850 2100
Wire Wire Line
	2850 2100 3200 2100
Wire Wire Line
	2500 1800 2700 1800
Wire Wire Line
	2850 1600 2650 1600
Wire Wire Line
	2650 1600 2650 2100
Connection ~ 2650 2100
Wire Wire Line
	2650 2100 2850 2100
Text GLabel 2400 1800 0    50   Input ~ 0
XIN32
Text GLabel 3300 1800 2    50   Input ~ 0
XOUT32
Wire Wire Line
	3200 1800 3300 1800
Connection ~ 3200 1800
Wire Wire Line
	2400 1800 2500 1800
Connection ~ 2500 1800
Wire Wire Line
	8100 1550 8150 1550
Wire Wire Line
	8100 1650 8450 1650
Wire Wire Line
	8750 1750 8100 1750
Wire Wire Line
	8100 1850 9050 1850
$Comp
L Switch:SW_DIP_x12 SW1
U 1 1 61E33825
P 7800 2150
F 0 "SW1" H 7800 3017 50  0000 C CNN
F 1 "SW_DIP_x12" H 7800 2926 50  0000 C CNN
F 2 "" H 7800 2150 50  0001 C CNN
F 3 "~" H 7800 2150 50  0001 C CNN
	1    7800 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 629A7EA0
P 8600 2450
F 0 "R?" V 8393 2450 50  0000 C CNN
F 1 "1k2" V 8484 2450 50  0000 C CNN
F 2 "" V 8530 2450 50  0001 C CNN
F 3 "~" H 8600 2450 50  0001 C CNN
	1    8600 2450
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 629A7EA6
P 8900 2550
F 0 "R?" V 9107 2550 50  0000 C CNN
F 1 "2k2" V 9016 2550 50  0000 C CNN
F 2 "" V 8830 2550 50  0001 C CNN
F 3 "~" H 8900 2550 50  0001 C CNN
	1    8900 2550
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 629A7EAC
P 9200 2650
F 0 "R?" V 8993 2650 50  0000 C CNN
F 1 "4k7" V 9084 2650 50  0000 C CNN
F 2 "" V 9130 2650 50  0001 C CNN
F 3 "~" H 9200 2650 50  0001 C CNN
	1    9200 2650
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 629A7EB2
P 8300 2350
F 0 "R?" V 8507 2350 50  0000 C CNN
F 1 "560" V 8416 2350 50  0000 C CNN
F 2 "" V 8230 2350 50  0001 C CNN
F 3 "~" H 8300 2350 50  0001 C CNN
	1    8300 2350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8100 1950 8150 1950
Wire Wire Line
	8100 2050 8450 2050
Wire Wire Line
	8750 2150 8100 2150
Wire Wire Line
	8100 2250 9050 2250
Wire Wire Line
	8100 2350 8150 2350
Wire Wire Line
	8100 2450 8450 2450
Wire Wire Line
	8100 2550 8750 2550
Wire Wire Line
	8100 2650 9050 2650
Text Label 9950 1550 2    50   ~ 0
CONFIG_SW1
Text Label 9950 1650 2    50   ~ 0
CONFIG_SW2
Text Label 9950 1750 2    50   ~ 0
CONFIG_SW3
Text Label 9950 1850 2    50   ~ 0
CONFIG_SW4
Text Label 9950 1950 2    50   ~ 0
CONFIG_SW5
Text Label 9950 2050 2    50   ~ 0
CONFIG_SW6
Text Label 9950 2150 2    50   ~ 0
CONFIG_SW7
Text Label 9950 2250 2    50   ~ 0
CONFIG_SW8
Text Label 9950 2350 2    50   ~ 0
CONFIG_SW9
Text Label 9950 2450 2    50   ~ 0
CONFIG_SW10
Text Label 9950 2550 2    50   ~ 0
CONFIG_SW11
Text Label 9950 2650 2    50   ~ 0
CONFIG_SW12
Text Label 6900 1550 0    50   ~ 0
CONFIG_SW1
Text Label 6900 1650 0    50   ~ 0
CONFIG_SW2
Text Label 6900 1750 0    50   ~ 0
CONFIG_SW3
Text Label 6900 1850 0    50   ~ 0
CONFIG_SW4
Text Label 6900 1950 0    50   ~ 0
CONFIG_SW5
Text Label 6900 2050 0    50   ~ 0
CONFIG_SW6
Text Label 6900 2150 0    50   ~ 0
CONFIG_SW7
Text Label 6900 2250 0    50   ~ 0
CONFIG_SW8
Text Label 6900 2350 0    50   ~ 0
CONFIG_SW9
Text Label 6900 2450 0    50   ~ 0
CONFIG_SW10
Text Label 6900 2550 0    50   ~ 0
CONFIG_SW11
Text Label 6900 2650 0    50   ~ 0
CONFIG_SW12
Wire Wire Line
	8750 1650 9950 1650
Wire Wire Line
	9050 1750 9950 1750
Wire Wire Line
	9350 1850 9950 1850
Wire Wire Line
	8750 2050 9950 2050
Wire Wire Line
	9050 2150 9950 2150
Wire Wire Line
	9350 2250 9950 2250
Wire Wire Line
	8750 2450 9950 2450
Wire Wire Line
	9050 2550 9950 2550
Wire Wire Line
	9350 2650 9950 2650
Wire Wire Line
	8100 1550 8100 1650
Connection ~ 8100 1550
Connection ~ 8100 1650
Wire Wire Line
	7500 1650 7500 1750
Wire Wire Line
	8100 1750 8100 1850
Connection ~ 8100 1750
Connection ~ 8100 1850
Wire Wire Line
	8100 1950 8100 2050
Connection ~ 8100 1950
Connection ~ 8100 2050
Wire Wire Line
	8100 2150 8100 2250
Connection ~ 8100 2150
Connection ~ 8100 2250
Wire Wire Line
	8100 2350 8100 2450
Connection ~ 8100 2350
Connection ~ 8100 2450
Wire Wire Line
	8100 2550 8100 2650
Connection ~ 8100 2550
Connection ~ 8100 2650
Wire Wire Line
	7500 2050 7500 2150
Wire Wire Line
	7500 2450 7500 2550
Wire Wire Line
	6900 1650 7500 1650
Connection ~ 7500 1650
Wire Wire Line
	7500 1750 6900 1750
Connection ~ 7500 1750
Wire Wire Line
	6900 2450 7500 2450
Connection ~ 7500 2450
Wire Wire Line
	6900 2150 7500 2150
Connection ~ 7500 2150
Wire Wire Line
	7500 2050 6900 2050
Connection ~ 7500 2050
Wire Wire Line
	6900 2550 7500 2550
Connection ~ 7500 2550
Wire Wire Line
	7500 2650 6850 2650
Wire Wire Line
	6850 2650 6850 2700
Wire Wire Line
	6850 2250 6850 2650
Wire Wire Line
	6850 2250 7500 2250
Connection ~ 6850 2650
Wire Wire Line
	7500 1850 6850 1850
Connection ~ 6850 2250
$Comp
L power:+3V3 #PWR?
U 1 1 62BE0430
P 6500 1300
F 0 "#PWR?" H 6500 1150 50  0001 C CNN
F 1 "+3V3" H 6515 1473 50  0000 C CNN
F 2 "" H 6500 1300 50  0001 C CNN
F 3 "" H 6500 1300 50  0001 C CNN
	1    6500 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 1850 6850 2250
Wire Wire Line
	6800 1950 7500 1950
$Comp
L Device:R R?
U 1 1 62BED998
P 6650 1550
F 0 "R?" V 6443 1550 50  0000 C CNN
F 1 "10k" V 6534 1550 50  0000 C CNN
F 2 "" V 6580 1550 50  0001 C CNN
F 3 "~" H 6650 1550 50  0001 C CNN
	1    6650 1550
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 62BEE453
P 6650 2350
F 0 "R?" V 6443 2350 50  0000 C CNN
F 1 "10k" V 6534 2350 50  0000 C CNN
F 2 "" V 6580 2350 50  0001 C CNN
F 3 "~" H 6650 2350 50  0001 C CNN
	1    6650 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	6800 2350 7500 2350
Wire Wire Line
	6800 1550 7500 1550
Wire Wire Line
	6500 1300 6500 1550
Connection ~ 6500 1550
Wire Wire Line
	6500 1550 6500 1950
Connection ~ 6500 1950
Wire Wire Line
	6500 1950 6500 2350
Text GLabel 10100 2350 2    50   Output ~ 0
CONFIG3
Wire Wire Line
	8450 1550 10100 1550
Wire Wire Line
	8450 1950 10100 1950
Wire Wire Line
	8450 2350 10100 2350
$Comp
L Device:LED_Dual_CACA D?
U 1 1 6326F793
P 4800 4250
F 0 "D?" V 4846 4040 50  0000 R CNN
F 1 "LED_Dual_CACA" V 4755 4040 50  0000 R CNN
F 2 "" H 4830 4250 50  0001 C CNN
F 3 "~" H 4830 4250 50  0001 C CNN
	1    4800 4250
	0    -1   -1   0   
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 63271DE1
P 4700 3800
F 0 "#PWR?" H 4700 3650 50  0001 C CNN
F 1 "+3V3" H 4715 3973 50  0000 C CNN
F 2 "" H 4700 3800 50  0001 C CNN
F 3 "" H 4700 3800 50  0001 C CNN
	1    4700 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 3800 4700 3950
Wire Wire Line
	4700 3950 4900 3950
Connection ~ 4700 3950
Text GLabel 4350 4850 0    50   Input ~ 0
LED1
Text GLabel 5250 4850 2    50   Input ~ 0
LED2
$Comp
L Device:R R?
U 1 1 6327FD66
P 4550 4850
F 0 "R?" V 4343 4850 50  0000 C CNN
F 1 "470" V 4434 4850 50  0000 C CNN
F 2 "" V 4480 4850 50  0001 C CNN
F 3 "~" H 4550 4850 50  0001 C CNN
	1    4550 4850
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 63280BC2
P 5050 4850
F 0 "R?" V 4843 4850 50  0000 C CNN
F 1 "470" V 4934 4850 50  0000 C CNN
F 2 "" V 4980 4850 50  0001 C CNN
F 3 "~" H 5050 4850 50  0001 C CNN
	1    5050 4850
	0    1    1    0   
$EndComp
Wire Wire Line
	4400 4850 4350 4850
Wire Wire Line
	5200 4850 5250 4850
Wire Wire Line
	4900 4850 4900 4550
Wire Wire Line
	4700 4550 4700 4850
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 61DB2E42
P 9350 5150
F 0 "Q?" H 9555 5196 50  0000 L CNN
F 1 "TN2130" H 9555 5105 50  0000 L CNN
F 2 "" H 9550 5250 50  0001 C CNN
F 3 "~" H 9350 5150 50  0001 C CNN
	1    9350 5150
	-1   0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 61DB42F0
P 7900 5150
F 0 "Q?" H 8105 5196 50  0000 L CNN
F 1 "TN2130" H 8105 5105 50  0000 L CNN
F 2 "" H 8100 5250 50  0001 C CNN
F 3 "~" H 7900 5150 50  0001 C CNN
	1    7900 5150
	1    0    0    -1  
$EndComp
Connection ~ 9600 5450
Wire Wire Line
	7550 5450 8000 5450
Connection ~ 7550 5450
Connection ~ 9600 5150
Wire Wire Line
	9550 5150 9600 5150
Wire Wire Line
	9250 5350 9250 5450
Connection ~ 9250 5450
Wire Wire Line
	9250 5450 9600 5450
Wire Wire Line
	7550 5150 7700 5150
Connection ~ 7550 5150
Wire Wire Line
	8000 5350 8000 5450
Connection ~ 8000 5450
Connection ~ 8000 4000
Wire Wire Line
	7000 4000 8000 4000
Connection ~ 9250 4000
Wire Wire Line
	9250 4000 9850 4000
Wire Wire Line
	9250 4300 9850 4300
Connection ~ 9850 4300
Wire Wire Line
	7000 4300 8000 4300
Connection ~ 7000 4300
Connection ~ 8650 4000
Wire Wire Line
	8650 4000 9250 4000
Connection ~ 8650 5450
Wire Wire Line
	8650 5450 9250 5450
Wire Wire Line
	8000 5450 8650 5450
Wire Wire Line
	8000 4000 8650 4000
Wire Wire Line
	8700 5800 10900 5800
Wire Wire Line
	6150 5800 8600 5800
$Comp
L el_components:LTV-846S U?
U 1 1 61F4051D
P 7400 4750
F 0 "U?" H 7400 5075 50  0000 C CNN
F 1 "LTV-846S" H 7400 4984 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 7200 4550 50  0001 L CIN
F 3 "https://www.mouser.de/datasheet/2/239/LTV_8X6_series-2887056.pdf" H 7400 4750 50  0001 L CNN
	1    7400 4750
	1    0    0    -1  
$EndComp
$Comp
L Diode:BZM55Cxx D?
U 1 1 61F535A6
P 8650 5300
F 0 "D?" V 8604 5380 50  0000 L CNN
F 1 "ZMM5235B" V 8695 5380 50  0000 L CNN
F 2 "Diode_SMD:D_MicroMELF" H 8650 5125 50  0001 C CNN
F 3 "http://www.vishay.com/docs/85597/bzm55.pdf" H 8650 5300 50  0001 C CNN
	1    8650 5300
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 61F54080
P 8650 4150
F 0 "R?" H 8720 4196 50  0000 L CNN
F 1 "1meg" H 8720 4105 50  0000 L CNN
F 2 "" V 8580 4150 50  0001 C CNN
F 3 "~" H 8650 4150 50  0001 C CNN
	1    8650 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 4850 9250 4600
Wire Wire Line
	8000 4900 8000 4600
Wire Wire Line
	9150 4950 9150 4850
Wire Wire Line
	9150 4850 9250 4850
Wire Wire Line
	8000 4950 9150 4950
Wire Wire Line
	9250 4950 9250 4900
Wire Wire Line
	9250 4900 8000 4900
Wire Wire Line
	8650 4300 8650 4650
Wire Wire Line
	7700 5150 7700 4850
Connection ~ 7700 5150
Wire Wire Line
	7700 4650 8650 4650
Connection ~ 8650 4650
Wire Wire Line
	8650 4650 8650 5150
Wire Wire Line
	6750 4650 6800 4650
Wire Wire Line
	7050 4850 7100 4850
$Comp
L el_components:LTV-846S U?
U 2 1 62018E4C
P 9850 4750
F 0 "U?" H 9850 5075 50  0000 C CNN
F 1 "LTV-846S" H 9850 4984 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 9650 4550 50  0001 L CIN
F 3 "https://www.mouser.de/datasheet/2/239/LTV_8X6_series-2887056.pdf" H 9850 4750 50  0001 L CNN
	2    9850 4750
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9550 4850 9550 5150
Connection ~ 9550 5150
Wire Wire Line
	9550 4650 8650 4650
Text GLabel 10150 4850 2    50   Input ~ 0
CH1-
Wire Wire Line
	10550 4650 10150 4650
$Comp
L el_components:VHV #PWR?
U 1 1 61F06438
P 8650 4000
F 0 "#PWR?" H 8650 3850 50  0001 C CNN
F 1 "VHV" H 8665 4173 50  0000 C CNN
F 2 "" H 8650 4000 50  0001 C CNN
F 3 "" H 8650 4000 50  0001 C CNN
	1    8650 4000
	1    0    0    -1  
$EndComp
$Comp
L el_components:GNDHV #PWR?
U 1 1 61F077C4
P 8650 5450
F 0 "#PWR?" H 8650 5200 50  0001 C CNN
F 1 "GNDHV" H 8655 5277 50  0000 C CNN
F 2 "" H 8650 5450 50  0001 C CNN
F 3 "" H 8650 5450 50  0001 C CNN
	1    8650 5450
	1    0    0    -1  
$EndComp
$EndSCHEMATC
