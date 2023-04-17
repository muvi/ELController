INSERT INTO supply(vendor, part, vendor_part, manufacturer_part, cost, on_order, sum_payed, sum_ordered)
SELECT
  ordered.vendor,
  part.part,
  ordered.vendor_part,
  ordered.manufacturer_part,
  ordered.cost,
  0 AS on_order,
  ordered.cost * ordered.sum_ordered AS sum_payed,
  ordered.sum_ordered
FROM (
WITH ordered(value, vendor, vendor_part, manufacturer_part, cost, sum_ordered) AS
(VALUES
("9.1pF", "mouser", "791-0603N9R1C500CT", "0603N9R1C500CT", 0.053, 20),
("1nF Y2", "mouser", "80-C901U102MZWDBAP", "C901U102MZWDBA7317", 0.148, 30),
("22uF", "mouser", "187-CL21A226MOQNNNE", "CL21A226MOQNNNE", 0.127, 20),
("4.7uF", "mouser", "187-CL21A475KAQNNNF", "CL21A475KAQNNNF", 0.074, 40),
("680pF", "mouser", "710-885012206033", "885012206033", 0.02, 10),
("4.7nF", "mouser", "710-885012206087", "885012206087", 0.017, 10),
("FM4007W", "mouser", "583-FM4007W-W", "FM4007W-W", 0.14, 10),
("1V8", "mouser", "771-BZX8450-C1V8-QR", "BZX8450-C1V8-QR", 0.134, 15),
("36V", "mouser", "863-MM3Z36VT1G", "MM3Z36VT1G", 0.127, 10),
("PMEG3050EP,115", "mouser", "771-PMEG3050EP115", "PMEG3050EP,115", 0.438, 10),
("PTVS13VS1UTR,115", "mouser", "771-PTVS13VS1UTR115", "PTVS13VS1UTR,115", 0.109, 10),
("BAT54A_R1_00001", "mouser", "241-BAT54A_R1_00001", "BAT54A_R1_00001", 0.142, 10),
("3V3", "mouser", "583-ZMM5226B", "ZMM5226B", 0.108, 10),
("SMAJ6.0A-W", "mouser", "583-SMAJ6.0A-W", "SMAJ6.0A-W", 0.108, 20),
("PRTR5V0U2X", "mouser", "771-PRTR5V0U2X-T/R", "PRTR5V0U2X,215", 0.407, 15),
("F 5A 32V", "mouser", "667-ERB-RE5R00V", "ERB-RE5R00V", 0.211, 20),
("220@100MHz", "mouser", "810-MMZ1608Y221BTD25", "MMZ1608Y221BTD25", 0.068, 20),
("Barrel jack 5.5x2.1mm", "digikey", "839-54-00164CT-ND", "54-00164", 0.588, 10),
("JTAG 10 pin", "digikey", "1175-1627-ND", "3220-10-0100-00", 0.513, 10),
("NC3FAH2", "mouser", "523-AC3FAH2-AU-PRE", "AC3FAH2-AU-PRE", 0.783, 5),
("NC3MAH-0", "mouser", "523-AC3MAH-AU-PRE", "AC3MAH-AU-PRE", 0.755, 5),
("USB C (USB 2.0)", "mouser", "640-USB4510031A", "USB4510-03-1-A", 0.574, 10),
("22uH", "mouser", "710-7447706220", "7447706220", 0.983, 10),
("6.8uH", "mouser", "963-LBC3225T6R8MR", "LBC3225T6R8MR", 0.122, 20),
("2.2uH", "mouser", "810-TFM201610ALVA2R2", "TFM201610ALVA2R2MTAA", 0.549, 10),
("3.3mH", "mouser", "994-RFS1317-335KL", "RFS1317-335KL", 1.18, 100),
("RZM001P02", "mouser", "755-RZM001P02T2L", "RZM001P02T2L", 0.096, 100),
("RQ3G100GN", "mouser", "755-RQ3G100GNTB", "RQ3G100GNTB", 0.383, 10),
("RK7002BMT116", "mouser", "755-RK7002BMT116", "RK7002BMT116", 0.17, 10),
("Si7119DN", "mouser", "781-SI7119DN-T1-E3", "SI7119DN-T1-E3", 0.697, 100),
("STN4NF20L", "mouser", "511-STN4NF20L", "STN4NF20L", 0.556, 100),
("10k", "mouser", "603-RC0603JR-0710KL", "RC0603JR-0710KL", 0.005, 200),
("560", "mouser", "603-RC0603JR-07560RL", "RC0603JR-07560RL", 0.013, 30),
("1.2k", "mouser", "791-RMC1/16-122JTP", "RMC1/16-122JTP", 0.013, 30),
("2.2k", "mouser", "603-RC0603FR-072K2L", "RC0603FR-072K2L", 0.015, 30),
("4.7k", "mouser", "791-RMC1/16-472JTP", "RMC1/16-472JTP", 0.013, 30),
("510", "mouser", "603-RC0603JR-07510RL", "RC0603JR-07510RL", 0.005, 200),
("1k", "mouser", "603-RC0603FR-071KL", "RC0603FR-071KL", 0.006, 125),
("10meg 200V", "mouser", "791-MR12W1005FTL", "MR12W1005FTL", 0.083, 20),
("22k 1%", "mouser", "652-CR0603FX-2202ELF", "CR0603-FX-2202ELF", 0.014, 25),
("22", "mouser", "301-22-RC", "301-22-RC", 0.011, 10),
("680 1%", "mouser", "652-CR0603FX-6800ELF", "CR0603-FX-6800ELF", 0.015, 25),
("0", "mouser", "652-CR0603-J/-000ELF", "CR0603-J/-000ELF", 0.005, 125),
("220 1/8W", "mouser", "660-RK73B1JTTDD221J", "RK73B1JTTDD221J", 0.019, 10),
("1meg", "mouser", "603-RC0603JR-131ML", "RC0603JR-131ML", 0.013, 30),
("16k", "mouser", "791-RMC16K163FTP", "RMC16K163FTP", 0.016, 10),
("5.1k", "mouser", "791-WR06X512JTL", "WR06X512 JTL", 0.013, 20),
("10meg", "mouser", "603-RC0603JR-0710ML", "RC0603JR-0710ML", 0.013, 15),
("330", "mouser", "652-CR0603-JW-331ELF", "CR0603-JW-331ELF", 0.007, 10),
("100 1/4W", "mouser", "603-RC0805FR-13100RL", "RC0805FR-13100RL", 0.011, 200),
("2.2k", "mouser", "301-2.2K-RC", "301-2.2K-RC", 0.004, 100),
("DIP 12", "mouser", "490-DS01C-254-S-12BE", "DS01C-254-S-12BE", 0.974, 6),
("Pushbutton", "mouser", "642-MJTP1230", "MJTP1230", 0.074, 25),
("750032050", "mouser", "710-750032050", "750032050", 4.34, 16),
("6N137", "digikey", "160-1794-1-ND", "6N137S-TA1", 0.3306, 200),
("ATSAMD21J15B-M", "mouser", "556-ATSAMD21J15B-MFT", "ATSAMD21J15B-MFT", 2.35, 25),
("MP5000A", "mouser", "946-MP5000ADQ-LF-Z", "MP5000ADQ-LF-Z", 1.2, 10),
("74ACT14", "mouser", "863-MC74ACT14DR2G", "MC74ACT14DR2G", 0.464, 10),
("PDSE1-S5-S5", "mouser", "490-PDSE1-S5-S5-D", "PDSE1-S5-S5-D", 2.7, 18),
("BD93291EFJ", "mouser", "755-BD93291EFJ-E2", "BD93291EFJ-E2", 0.888, 10),
("MAX485CSA+T", "digikey", "MAX485CSA+TCT-ND", "MAX485CSA+T", 3.242, 10),
("SSPT7F-7PF20-R", "mouser", "628-SSPT7F-7PF20PPM", "SSPT7F-7PF20-R", 0.553, 10),
("TPSMB210A", "mouser", "576-TPSMB210A", "TPSMB210A", 0.562, 10)
)
SELECT *
FROM ordered
  ) AS ordered
  LEFT JOIN part ON part.value = ordered.value
  LEFT JOIN vendor ON vendor.vendor = ordered.vendor
  --LEFT JOIN supply ON supply.part = part.part
--WHERE supply.part IS NOT NULL
--WHERE vendor.vendor IS NULL