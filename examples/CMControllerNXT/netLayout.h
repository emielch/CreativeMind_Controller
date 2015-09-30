#include <Arduino.h>

uint16_t nLed0[] = {1000,1001,1002,1003,1004};
uint16_t nLed1[] = {400,401,402,403,404};
uint16_t nLed2[] = {0,1,2,3,4};
uint16_t nLed3[] = {1400,1401,1402,1403,1404};
uint16_t nLed4[] = {600,601,602,603,604};
uint16_t nLed5[] = {800,801,802,803,804};
uint16_t nLed6[] = {44,45,46,47,48};
uint16_t nLed7[] = {891,892,893,894,895};
uint16_t nLed8[] = {968,969,970,971,972};
uint16_t nLed9[] = {1056,1057,1058,1059,1060};
uint16_t nLed10[] = {82,83,84,85,86};
uint16_t nLed11[] = {485,486,487,488,489};
uint16_t nLed12[] = {666,667,668,669,670};
uint16_t nLed13[] = {1424,1425,1426,1427,1428};
uint16_t nLed14[] = {529,530,531,532,533};
uint16_t nLed15[] = {716,717,718,719,720};
uint16_t nLed16[] = {302,303,304,305,306};
uint16_t nLed17[] = {763,764,765,766,767};
uint16_t nLed18[] = {1504,1505,1506,1507,1508};
uint16_t nLed19[] = {921,922,923,924,925};
uint16_t nLed20[] = {1484,1485,1486,1487,1488};
uint16_t nLed21[] = {322,323,324,325,326};
uint16_t nLed22[] = {1462,1463,1464,1465,1466};
uint16_t nLed23[] = {231,232,233,234,235};
uint16_t nLed24[] = {128,129,130,131,132};
uint16_t nLed25[] = {1356,1357,1358,1359,1360};
uint16_t nLed26[] = {249,250,251,252,253};
uint16_t nLed27[] = {1200,1201,1202,1203,1204};
uint16_t nLed28[] = {642,643,644,645,646};
uint16_t nLed29[] = {1118,1119,1120,1121,1122};
  //2-6
uint16_t cLed0[] = {5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43};
  //6-10
uint16_t cLed1[] = {49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81};
  //10-25
uint16_t cLed2[] = {87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112};
  //25-24
uint16_t cLed3[] = {113,114,115,116,117,118,119,120,121,122,123,124,125,126,127};
  //24-13
uint16_t cLed4[] = {133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162};
  //13-14
uint16_t cLed5[] = {163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193};
  //28-23
uint16_t cLed6[] = {200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230};
  //23-26
uint16_t cLed7[] = {236,237,238,239,240,241,242,243,244,245,246,247,248};
  //26-16
uint16_t cLed8[] = {254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,299,300,301};
  //16-21
uint16_t cLed9[] = {307,308,309,310,311,312,313,314,315,316,317,318,319,320,321};
  //21-22
uint16_t cLed10[] = {327,328,329,330,331,332,333,334,335,336,337,338,339,340,341,342,343,344,345,346};
  //1-27
uint16_t cLed11[] = {405,406,407,408,409,410,411,412,413,414,415,416,417,418,419,420,421,422,423,424,425,426,427,428,429,430,431};
  //27-11
uint16_t cLed12[] = {432,433,434,435,436,437,438,439,440,441,442,443,444,445,446,447,448,449,450,451,452,453,454,455,456,457,458,459,460,461,462,463,464,465,466,467,468,469};
  //11-24
uint16_t cLed13[] = {470,471,472,473,474,475,476,477,478,479,480,481,482,483,484};
  //11-10
uint16_t cLed14[] = {490,491,492,493,494,495,496,497,498,499,500,501,502,503,504};
  //10-14
uint16_t cLed15[] = {505,506,507,508,509,510,511,512,513,514,515,516,517,518,519,520,521,522,523,524,525,526,527,528};
  //14-6
uint16_t cLed16[] = {534,535,536,537,538,539,540,541,542,543,544,545,546,547,548,549,550,551,552,553,554,555,556,557,558,559,560,561,562,563,564,565,566,567,568,569};
  //4-28
uint16_t cLed17[] = {605,606,607,608,609,610,611,612,613,614,615,616,617,618,619,620,621,622,623,624,625,626,627,628,629,630,631,632,633,634,635,636,637,638,639,640,641};
  //28-12
uint16_t cLed18[] = {647,648,649,650,651,652,653,654,655,656,657,658,659,660,661,662,663,664,665};
  //12-15
uint16_t cLed19[] = {671,672,673,674,675,676,677,678,679,680,681,682,683,684,685,686,687,688,689,690,691,692,693,694,695,696,697};
  //15-16
uint16_t cLed20[] = {698,699,700,701,702,703,704,705,706,707,708,709,710,711,712,713,714,715};
  //15-17
uint16_t cLed21[] = {721,722,723,724,725,726,727,728,729,730,731,732,733,734,735,736,737,738,739,740,741,742,743,744,745,746,747,748,749,750,751,752,753,754,755,756,757,758,759,760,761,762};
  //5-7
uint16_t cLed22[] = {805,806,807,808,809,810,811,812,813,814,815,816,817,818,819,820,821,822,823,824,825,826,827,828,829,830,831,832,833,834,835,836,837,838};
  //7-20
uint16_t cLed23[] = {839,840,841,842,843,844,845,846,847,848,849,850,851,852,853,854,855,856,857,858,859,860,861,862,863,864,865,866,867,868,869,870,871,872,873,874,875,876,877,878,879,880,881,882,883,884,885,886,887,888,889,890};
  //7-19
uint16_t cLed24[] = {896,897,898,899,900,901,902,903,904,905,906,907,908,909,910,911,912,913,914,915,916,917,918,919,920};
  //7-8
uint16_t cLed25[] = {926,927,928,929,930,931,932,933,934,935,936,937,938,939,940,941,942,943,944,945,946,947,948,949,950,951,952,953,954,955,956,957,958,959,960,961,962,963,964,965,966,967};
  //8-9
uint16_t cLed26[] = {973,974,975,976,977,978,979,980,981,982,983,984,985,986,987,988,989,990,991,992,993};
  //0-9
uint16_t cLed27[] = {1005,1006,1007,1008,1009,1010,1011,1012,1013,1014,1015,1016,1017,1018,1019,1020,1021,1022,1023,1024,1025,1026,1027,1028,1029,1030,1031,1032,1033,1034,1035,1036,1037,1038,1039,1040,1041,1042,1043,1044,1045,1046,1047,1048,1049,1050,1051,1052,1053,1054,1055};
  //9-12
uint16_t cLed28[] = {1061,1062,1063,1064,1065,1066,1067,1068,1069,1070,1071,1072,1073,1074,1075,1076,1077,1078,1079,1080,1081};
  //12-29
uint16_t cLed29[] = {1082,1083,1084,1085,1086,1087,1088,1089,1090,1091,1092,1093,1094,1095,1096,1097,1098,1099,1100,1101,1102,1103,1104,1105,1106,1107,1108,1109};
  //29-23
uint16_t cLed30[] = {1110,1111,1112,1113,1114,1115,1116,1117};
  //29-8
uint16_t cLed31[] = {1123,1124,1125,1126,1127,1128,1129,1130,1131,1132,1133,1134,1135,1136,1137,1138,1139,1140,1141,1142,1143,1144};
  //8-13
uint16_t cLed32[] = {1145,1146,1147,1148,1149,1150,1151,1152,1153,1154,1155,1156,1157,1158,1159,1160,1161,1162,1163,1164,1165,1166,1167,1168,1169,1170,1171,1172,1173,1174};
  //8-15
uint16_t cLed33[] = {1175,1176,1177,1178,1179,1180,1181,1182,1183,1184,1185,1186,1187,1188,1189,1190,1191};
  //27-26
uint16_t cLed34[] = {1205,1206,1207,1208,1209,1210,1211,1212,1213,1214,1215,1216,1217,1218,1219,1220,1221,1222,1223,1224,1225,1226,1227,1228,1229,1230,1231,1232,1233,1234,1235};
  //26-17
uint16_t cLed35[] = {1236,1237,1238,1239,1240,1241,1242,1243,1244,1245,1246,1247,1248,1249,1250,1251,1252,1253,1254,1255,1256,1257,1258,1259,1260,1261,1262,1263,1264,1265,1266,1267,1268,1269,1270,1271,1272,1273,1274,1275,1276,1277};
  //17-21
uint16_t cLed36[] = {1278,1279,1280,1281,1282,1283,1284,1285,1286,1287,1288,1289,1290,1291,1292,1293,1294,1295,1296,1297,1298,1299,1300};
  //17-19
uint16_t cLed37[] = {1301,1302,1303,1304,1305,1306,1307,1308,1309,1310,1311,1312,1313,1314,1315,1316,1317,1318,1319,1320,1321};
  //19-25
uint16_t cLed38[] = {1322,1323,1324,1325,1326,1327,1328,1329,1330,1331,1332,1333,1334,1335,1336,1337,1338,1339,1340,1341,1342,1343,1344,1345,1346,1347,1348,1349,1350,1351,1352,1353,1354,1355};
  //25-23
uint16_t cLed39[] = {1361,1362,1363,1364,1365,1366,1367,1368,1369,1370,1371,1372,1373,1374,1375,1376,1377,1378,1379,1380,1381,1382,1383,1384,1385,1386,1387,1388,1389,1390,1391,1392,1393,1394};
  //3-13
uint16_t cLed40[] = {1405,1406,1407,1408,1409,1410,1411,1412,1413,1414,1415,1416,1417,1418,1419,1420,1421,1422,1423};
  //13-22
uint16_t cLed41[] = {1429,1430,1431,1432,1433,1434,1435,1436,1437,1438,1439,1440,1441,1442,1443,1444,1445,1446,1447,1448,1449,1450,1451,1452,1453,1454,1455,1456,1457,1458,1459,1460,1461};
  //22-20
uint16_t cLed42[] = {1467,1468,1469,1470,1471,1472,1473,1474,1475,1476,1477,1478,1479,1480,1481,1482,1483};
  //20-18
uint16_t cLed43[] = {1489,1490,1491,1492,1493,1494,1495,1496,1497,1498,1499,1500,1501,1502,1503};
  //18-22
uint16_t cLed44[] = {1509,1510,1511,1512,1513,1514,1515,1516,1517,1518,1519,1520,1521,1522,1523,1524,1525,1526,1527,1528,1529,1530,1531};

Segment seg[] = {
   Segment( sizeof(nLed0)/2, nLed0 ), // 0
   Segment( sizeof(nLed1)/2, nLed1 ), // 1
   Segment( sizeof(nLed2)/2, nLed2 ), // 2
   Segment( sizeof(nLed3)/2, nLed3 ), // 3
   Segment( sizeof(nLed4)/2, nLed4 ), // 4
   Segment( sizeof(nLed5)/2, nLed5 ), // 5
   Segment( sizeof(nLed6)/2, nLed6 ), // 6
   Segment( sizeof(nLed7)/2, nLed7 ), // 7
   Segment( sizeof(nLed8)/2, nLed8 ), // 8
   Segment( sizeof(nLed9)/2, nLed9 ), // 9
   Segment( sizeof(nLed10)/2, nLed10 ), // 10
   Segment( sizeof(nLed11)/2, nLed11 ), // 11
   Segment( sizeof(nLed12)/2, nLed12 ), // 12
   Segment( sizeof(nLed13)/2, nLed13 ), // 13
   Segment( sizeof(nLed14)/2, nLed14 ), // 14
   Segment( sizeof(nLed15)/2, nLed15 ), // 15
   Segment( sizeof(nLed16)/2, nLed16 ), // 16
   Segment( sizeof(nLed17)/2, nLed17 ), // 17
   Segment( sizeof(nLed18)/2, nLed18 ), // 18
   Segment( sizeof(nLed19)/2, nLed19 ), // 19
   Segment( sizeof(nLed20)/2, nLed20 ), // 20
   Segment( sizeof(nLed21)/2, nLed21 ), // 21
   Segment( sizeof(nLed22)/2, nLed22 ), // 22
   Segment( sizeof(nLed23)/2, nLed23 ), // 23
   Segment( sizeof(nLed24)/2, nLed24 ), // 24
   Segment( sizeof(nLed25)/2, nLed25 ), // 25
   Segment( sizeof(nLed26)/2, nLed26 ), // 26
   Segment( sizeof(nLed27)/2, nLed27 ), // 27
   Segment( sizeof(nLed28)/2, nLed28 ), // 28
   Segment( sizeof(nLed29)/2, nLed29 ), // 29
   Segment( sizeof(cLed0)/2, cLed0 ), // 30
   Segment( sizeof(cLed1)/2, cLed1 ), // 31
   Segment( sizeof(cLed2)/2, cLed2 ), // 32
   Segment( sizeof(cLed3)/2, cLed3 ), // 33
   Segment( sizeof(cLed4)/2, cLed4 ), // 34
   Segment( sizeof(cLed5)/2, cLed5 ), // 35
   Segment( sizeof(cLed6)/2, cLed6 ), // 36
   Segment( sizeof(cLed7)/2, cLed7 ), // 37
   Segment( sizeof(cLed8)/2, cLed8 ), // 38
   Segment( sizeof(cLed9)/2, cLed9 ), // 39
   Segment( sizeof(cLed10)/2, cLed10 ), // 40
   Segment( sizeof(cLed11)/2, cLed11 ), // 41
   Segment( sizeof(cLed12)/2, cLed12 ), // 42
   Segment( sizeof(cLed13)/2, cLed13 ), // 43
   Segment( sizeof(cLed14)/2, cLed14 ), // 44
   Segment( sizeof(cLed15)/2, cLed15 ), // 45
   Segment( sizeof(cLed16)/2, cLed16 ), // 46
   Segment( sizeof(cLed17)/2, cLed17 ), // 47
   Segment( sizeof(cLed18)/2, cLed18 ), // 48
   Segment( sizeof(cLed19)/2, cLed19 ), // 49
   Segment( sizeof(cLed20)/2, cLed20 ), // 50
   Segment( sizeof(cLed21)/2, cLed21 ), // 51
   Segment( sizeof(cLed22)/2, cLed22 ), // 52
   Segment( sizeof(cLed23)/2, cLed23 ), // 53
   Segment( sizeof(cLed24)/2, cLed24 ), // 54
   Segment( sizeof(cLed25)/2, cLed25 ), // 55
   Segment( sizeof(cLed26)/2, cLed26 ), // 56
   Segment( sizeof(cLed27)/2, cLed27 ), // 57
   Segment( sizeof(cLed28)/2, cLed28 ), // 58
   Segment( sizeof(cLed29)/2, cLed29 ), // 59
   Segment( sizeof(cLed30)/2, cLed30 ), // 60
   Segment( sizeof(cLed31)/2, cLed31 ), // 61
   Segment( sizeof(cLed32)/2, cLed32 ), // 62
   Segment( sizeof(cLed33)/2, cLed33 ), // 63
   Segment( sizeof(cLed34)/2, cLed34 ), // 64
   Segment( sizeof(cLed35)/2, cLed35 ), // 65
   Segment( sizeof(cLed36)/2, cLed36 ), // 66
   Segment( sizeof(cLed37)/2, cLed37 ), // 67
   Segment( sizeof(cLed38)/2, cLed38 ), // 68
   Segment( sizeof(cLed39)/2, cLed39 ), // 69
   Segment( sizeof(cLed40)/2, cLed40 ), // 70
   Segment( sizeof(cLed41)/2, cLed41 ), // 71
   Segment( sizeof(cLed42)/2, cLed42 ), // 72
   Segment( sizeof(cLed43)/2, cLed43 ), // 73
   Segment( sizeof(cLed44)/2, cLed44 )  // 74
};

Segment *seg0Conn[] = {
  &seg[57]
};

Segment *seg1Conn[] = {
  &seg[41]
};

Segment *seg2Conn[] = {
  &seg[30]
};

Segment *seg3Conn[] = {
  &seg[70]
};

Segment *seg4Conn[] = {
  &seg[47]
};

Segment *seg5Conn[] = {
  &seg[52]
};

Segment *seg6Conn[] = {
  &seg[30],
  &seg[31],
  &seg[46]
};

Segment *seg7Conn[] = {
  &seg[52],
  &seg[53],
  &seg[54],
  &seg[55]
};

Segment *seg8Conn[] = {
  &seg[55],
  &seg[56],
  &seg[61],
  &seg[62],
  &seg[63]
};

Segment *seg9Conn[] = {
  &seg[56],
  &seg[57],
  &seg[58]
};

Segment *seg10Conn[] = {
  &seg[31],
  &seg[32],
  &seg[44],
  &seg[45]
};

Segment *seg11Conn[] = {
  &seg[42],
  &seg[43],
  &seg[44]
};

Segment *seg12Conn[] = {
  &seg[48],
  &seg[49],
  &seg[58],
  &seg[59]
};

Segment *seg13Conn[] = {
  &seg[34],
  &seg[35],
  &seg[62],
  &seg[70],
  &seg[71]
};

Segment *seg14Conn[] = {
  &seg[35],
  &seg[45],
  &seg[46]
};

Segment *seg15Conn[] = {
  &seg[49],
  &seg[50],
  &seg[51],
  &seg[63]
};

Segment *seg16Conn[] = {
  &seg[38],
  &seg[39],
  &seg[50]
};

Segment *seg17Conn[] = {
  &seg[51],
  &seg[65],
  &seg[66],
  &seg[67]
};

Segment *seg18Conn[] = {
  &seg[73],
  &seg[74]
};

Segment *seg19Conn[] = {
  &seg[54],
  &seg[67],
  &seg[68]
};

Segment *seg20Conn[] = {
  &seg[53],
  &seg[72],
  &seg[73]
};

Segment *seg21Conn[] = {
  &seg[39],
  &seg[40],
  &seg[66]
};

Segment *seg22Conn[] = {
  &seg[40],
  &seg[71],
  &seg[72],
  &seg[74]
};

Segment *seg23Conn[] = {
  &seg[36],
  &seg[37],
  &seg[60],
  &seg[69]
};

Segment *seg24Conn[] = {
  &seg[33],
  &seg[34],
  &seg[43]
};

Segment *seg25Conn[] = {
  &seg[32],
  &seg[33],
  &seg[68],
  &seg[69]
};

Segment *seg26Conn[] = {
  &seg[37],
  &seg[38],
  &seg[64],
  &seg[65]
};

Segment *seg27Conn[] = {
  &seg[41],
  &seg[42],
  &seg[64]
};

Segment *seg28Conn[] = {
  &seg[36],
  &seg[47],
  &seg[48]
};

Segment *seg29Conn[] = {
  &seg[59],
  &seg[60],
  &seg[61]
};

Segment *seg30Conn[] = {
  &seg[2],
  &seg[6]
};

Segment *seg31Conn[] = {
  &seg[6],
  &seg[10]
};

Segment *seg32Conn[] = {
  &seg[10],
  &seg[25]
};

Segment *seg33Conn[] = {
  &seg[25],
  &seg[24]
};

Segment *seg34Conn[] = {
  &seg[24],
  &seg[13]
};

Segment *seg35Conn[] = {
  &seg[13],
  &seg[14]
};

Segment *seg36Conn[] = {
  &seg[28],
  &seg[23]
};

Segment *seg37Conn[] = {
  &seg[23],
  &seg[26]
};

Segment *seg38Conn[] = {
  &seg[26],
  &seg[16]
};

Segment *seg39Conn[] = {
  &seg[16],
  &seg[21]
};

Segment *seg40Conn[] = {
  &seg[21],
  &seg[22]
};

Segment *seg41Conn[] = {
  &seg[1],
  &seg[27]
};

Segment *seg42Conn[] = {
  &seg[27],
  &seg[11]
};

Segment *seg43Conn[] = {
  &seg[11],
  &seg[24]
};

Segment *seg44Conn[] = {
  &seg[11],
  &seg[10]
};

Segment *seg45Conn[] = {
  &seg[10],
  &seg[14]
};

Segment *seg46Conn[] = {
  &seg[14],
  &seg[6]
};

Segment *seg47Conn[] = {
  &seg[4],
  &seg[28]
};

Segment *seg48Conn[] = {
  &seg[28],
  &seg[12]
};

Segment *seg49Conn[] = {
  &seg[12],
  &seg[15]
};

Segment *seg50Conn[] = {
  &seg[15],
  &seg[16]
};

Segment *seg51Conn[] = {
  &seg[15],
  &seg[17]
};

Segment *seg52Conn[] = {
  &seg[5],
  &seg[7]
};

Segment *seg53Conn[] = {
  &seg[7],
  &seg[20]
};

Segment *seg54Conn[] = {
  &seg[7],
  &seg[19]
};

Segment *seg55Conn[] = {
  &seg[7],
  &seg[8]
};

Segment *seg56Conn[] = {
  &seg[8],
  &seg[9]
};

Segment *seg57Conn[] = {
  &seg[0],
  &seg[9]
};

Segment *seg58Conn[] = {
  &seg[9],
  &seg[12]
};

Segment *seg59Conn[] = {
  &seg[12],
  &seg[29]
};

Segment *seg60Conn[] = {
  &seg[29],
  &seg[23]
};

Segment *seg61Conn[] = {
  &seg[29],
  &seg[8]
};

Segment *seg62Conn[] = {
  &seg[8],
  &seg[13]
};

Segment *seg63Conn[] = {
  &seg[8],
  &seg[15]
};

Segment *seg64Conn[] = {
  &seg[27],
  &seg[26]
};

Segment *seg65Conn[] = {
  &seg[26],
  &seg[17]
};

Segment *seg66Conn[] = {
  &seg[17],
  &seg[21]
};

Segment *seg67Conn[] = {
  &seg[17],
  &seg[19]
};

Segment *seg68Conn[] = {
  &seg[19],
  &seg[25]
};

Segment *seg69Conn[] = {
  &seg[25],
  &seg[23]
};

Segment *seg70Conn[] = {
  &seg[3],
  &seg[13]
};

Segment *seg71Conn[] = {
  &seg[13],
  &seg[22]
};

Segment *seg72Conn[] = {
  &seg[22],
  &seg[20]
};

Segment *seg73Conn[] = {
  &seg[20],
  &seg[18]
};

Segment *seg74Conn[] = {
  &seg[18],
  &seg[22]
};

void setNN(){
  seg[0].setNN(NEURON, sizeof(seg0Conn)/4, seg0Conn);
  seg[1].setNN(NEURON, sizeof(seg1Conn)/4, seg1Conn);
  seg[2].setNN(NEURON, sizeof(seg2Conn)/4, seg2Conn);
  seg[3].setNN(NEURON, sizeof(seg3Conn)/4, seg3Conn);
  seg[4].setNN(NEURON, sizeof(seg4Conn)/4, seg4Conn);
  seg[5].setNN(NEURON, sizeof(seg5Conn)/4, seg5Conn);
  seg[6].setNN(NEURON, sizeof(seg6Conn)/4, seg6Conn);
  seg[7].setNN(NEURON, sizeof(seg7Conn)/4, seg7Conn);
  seg[8].setNN(NEURON, sizeof(seg8Conn)/4, seg8Conn);
  seg[9].setNN(NEURON, sizeof(seg9Conn)/4, seg9Conn);
  seg[10].setNN(NEURON, sizeof(seg10Conn)/4, seg10Conn);
  seg[11].setNN(NEURON, sizeof(seg11Conn)/4, seg11Conn);
  seg[12].setNN(NEURON, sizeof(seg12Conn)/4, seg12Conn);
  seg[13].setNN(NEURON, sizeof(seg13Conn)/4, seg13Conn);
  seg[14].setNN(NEURON, sizeof(seg14Conn)/4, seg14Conn);
  seg[15].setNN(NEURON, sizeof(seg15Conn)/4, seg15Conn);
  seg[16].setNN(NEURON, sizeof(seg16Conn)/4, seg16Conn);
  seg[17].setNN(NEURON, sizeof(seg17Conn)/4, seg17Conn);
  seg[18].setNN(NEURON, sizeof(seg18Conn)/4, seg18Conn);
  seg[19].setNN(NEURON, sizeof(seg19Conn)/4, seg19Conn);
  seg[20].setNN(NEURON, sizeof(seg20Conn)/4, seg20Conn);
  seg[21].setNN(NEURON, sizeof(seg21Conn)/4, seg21Conn);
  seg[22].setNN(NEURON, sizeof(seg22Conn)/4, seg22Conn);
  seg[23].setNN(NEURON, sizeof(seg23Conn)/4, seg23Conn);
  seg[24].setNN(NEURON, sizeof(seg24Conn)/4, seg24Conn);
  seg[25].setNN(NEURON, sizeof(seg25Conn)/4, seg25Conn);
  seg[26].setNN(NEURON, sizeof(seg26Conn)/4, seg26Conn);
  seg[27].setNN(NEURON, sizeof(seg27Conn)/4, seg27Conn);
  seg[28].setNN(NEURON, sizeof(seg28Conn)/4, seg28Conn);
  seg[29].setNN(NEURON, sizeof(seg29Conn)/4, seg29Conn);
  seg[30].setNN(SYNAPSE, sizeof(seg30Conn)/4, seg30Conn);
  seg[31].setNN(SYNAPSE, sizeof(seg31Conn)/4, seg31Conn);
  seg[32].setNN(SYNAPSE, sizeof(seg32Conn)/4, seg32Conn);
  seg[33].setNN(SYNAPSE, sizeof(seg33Conn)/4, seg33Conn);
  seg[34].setNN(SYNAPSE, sizeof(seg34Conn)/4, seg34Conn);
  seg[35].setNN(SYNAPSE, sizeof(seg35Conn)/4, seg35Conn);
  seg[36].setNN(SYNAPSE, sizeof(seg36Conn)/4, seg36Conn);
  seg[37].setNN(SYNAPSE, sizeof(seg37Conn)/4, seg37Conn);
  seg[38].setNN(SYNAPSE, sizeof(seg38Conn)/4, seg38Conn);
  seg[39].setNN(SYNAPSE, sizeof(seg39Conn)/4, seg39Conn);
  seg[40].setNN(SYNAPSE, sizeof(seg40Conn)/4, seg40Conn);
  seg[41].setNN(SYNAPSE, sizeof(seg41Conn)/4, seg41Conn);
  seg[42].setNN(SYNAPSE, sizeof(seg42Conn)/4, seg42Conn);
  seg[43].setNN(SYNAPSE, sizeof(seg43Conn)/4, seg43Conn);
  seg[44].setNN(SYNAPSE, sizeof(seg44Conn)/4, seg44Conn);
  seg[45].setNN(SYNAPSE, sizeof(seg45Conn)/4, seg45Conn);
  seg[46].setNN(SYNAPSE, sizeof(seg46Conn)/4, seg46Conn);
  seg[47].setNN(SYNAPSE, sizeof(seg47Conn)/4, seg47Conn);
  seg[48].setNN(SYNAPSE, sizeof(seg48Conn)/4, seg48Conn);
  seg[49].setNN(SYNAPSE, sizeof(seg49Conn)/4, seg49Conn);
  seg[50].setNN(SYNAPSE, sizeof(seg50Conn)/4, seg50Conn);
  seg[51].setNN(SYNAPSE, sizeof(seg51Conn)/4, seg51Conn);
  seg[52].setNN(SYNAPSE, sizeof(seg52Conn)/4, seg52Conn);
  seg[53].setNN(SYNAPSE, sizeof(seg53Conn)/4, seg53Conn);
  seg[54].setNN(SYNAPSE, sizeof(seg54Conn)/4, seg54Conn);
  seg[55].setNN(SYNAPSE, sizeof(seg55Conn)/4, seg55Conn);
  seg[56].setNN(SYNAPSE, sizeof(seg56Conn)/4, seg56Conn);
  seg[57].setNN(SYNAPSE, sizeof(seg57Conn)/4, seg57Conn);
  seg[58].setNN(SYNAPSE, sizeof(seg58Conn)/4, seg58Conn);
  seg[59].setNN(SYNAPSE, sizeof(seg59Conn)/4, seg59Conn);
  seg[60].setNN(SYNAPSE, sizeof(seg60Conn)/4, seg60Conn);
  seg[61].setNN(SYNAPSE, sizeof(seg61Conn)/4, seg61Conn);
  seg[62].setNN(SYNAPSE, sizeof(seg62Conn)/4, seg62Conn);
  seg[63].setNN(SYNAPSE, sizeof(seg63Conn)/4, seg63Conn);
  seg[64].setNN(SYNAPSE, sizeof(seg64Conn)/4, seg64Conn);
  seg[65].setNN(SYNAPSE, sizeof(seg65Conn)/4, seg65Conn);
  seg[66].setNN(SYNAPSE, sizeof(seg66Conn)/4, seg66Conn);
  seg[67].setNN(SYNAPSE, sizeof(seg67Conn)/4, seg67Conn);
  seg[68].setNN(SYNAPSE, sizeof(seg68Conn)/4, seg68Conn);
  seg[69].setNN(SYNAPSE, sizeof(seg69Conn)/4, seg69Conn);
  seg[70].setNN(SYNAPSE, sizeof(seg70Conn)/4, seg70Conn);
  seg[71].setNN(SYNAPSE, sizeof(seg71Conn)/4, seg71Conn);
  seg[72].setNN(SYNAPSE, sizeof(seg72Conn)/4, seg72Conn);
  seg[73].setNN(SYNAPSE, sizeof(seg73Conn)/4, seg73Conn);
  seg[74].setNN(SYNAPSE, sizeof(seg74Conn)/4, seg74Conn);
}


