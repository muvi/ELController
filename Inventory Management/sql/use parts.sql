UPDATE part
SET
  amount = used.amount_available - used.amount_needed
FROM (
  SELECT
    project.project,
    bom.designator,
    bom.designator_nr,
    part.value,
    part.part,
    part.location,
    COUNT(*) AS amount_needed,
	amount AS amount_available
  FROM bom
    LEFT JOIN project ON project.project = bom.project
    LEFT JOIN part ON part.part = bom.part
  WHERE project.short = 'elcontroller2'
    AND bom.designator || bom.designator_nr IN ('C44', 'R45', 'R175', 'R174', 'D15', 'D14', 'J9', 'R43', 'R40', 'C9', 'C139', 'C16', 'C137', 'C18', 'C19', 'C50', 'C49', 'C56', 'C55', 'C2', 'C3', 'C4', 'C93', 'R28', 'C126', 'U2', 'Y1', 'C7', 'C8', 'R39', 'Q4', 'C42', 'D9', 'D7', 'F1', 'D8', 'FL1', 'C6', 'C5', 'FB1', 'C1', 'C135', 'C136', 'L23', 'FB4', 'D19', 'R35', 'R34', 'R176', 'R36', 'C127', 'C129', 'C131', 'C128', 'C130', 'C132', 'R31', 'R33', 'R42', 'U43', 'U45', 'U44', 'R16', 'R17', 'R5', 'R10', 'R15', 'R4', 'R9', 'R14', 'R3', 'R8', 'R13', 'R2', 'R7', 'R12', 'R1', 'R6', 'R11', 'R26', 'D4', 'R23', 'D10', 'R41', 'R44', 'C43', 'U9', 'D11', 'D12', 'D13', 'C22', 'R32', 'C23', 'R30', 'U4', 'R29', 'Q3', 'D5', 'R27', 'R24', 'D6', 'FB2', 'C37', 'C25', 'C36', 'R37', 'L5', 'R38', 'C38', 'U8', 'C35', 'C24', 'C12', 'C14', 'C13', 'R25', 'U3', 'C11', 'D2', 'D18', 'D3', 'D16', 'R22', 'D17', 'Q9', 'Q6', 'Q15', 'Q12', 'R57', 'R49', 'R73', 'R65', 'R67', 'R75', 'R51', 'R59', 'R18', 'C29', 'C30', 'C32', 'C33', 'C26', 'C27', 'L3', 'L4', 'L2', 'C31', 'C34', 'C28', 'C101', 'C100', 'C99', 'C98', 'C97', 'C96', 'C65', 'C94', 'R54', 'R46', 'R70', 'R62', 'R21', 'C10', 'C51', 'C52', 'C45', 'C46', 'C47', 'C48', 'C53', 'C54', 'R58', 'R50', 'R74', 'R66', 'R19', 'R72', 'R63', 'R55', 'R47', 'R56', 'R48', 'R72', 'R64', 'R69', 'R77', 'R53', 'R61', 'R60', 'R52', 'R76', 'R68', 'Q8', 'Q5', 'Q14', 'Q11', 'Q2', 'Q10', 'Q7', 'Q16', 'Q13', 'U12', 'U10', 'U16', 'U14', 'U13', 'U11', 'U17', 'U15', 'U1', 'T1', 'L1', 'J4', 'J3', 'D1', 'J2', 'SW3', 'SW4', 'SW5', 'SW6', 'SW1', 'U42', 'J5', 'U5', 'U6', 'U7', 'L6', 'L7', 'L8', 'L9', 'C21', 'C40', 'C41', 'C39', 'C17', 'C141', 'J10', 'J11')
  GROUP BY part.part
) AS used
WHERE part.part = used.part