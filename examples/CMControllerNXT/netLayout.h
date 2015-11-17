#include <Arduino.h>
uint16_t coreLeds[] =
{1000,1001,1002,1003,1004,
400,401,402,403,404,
0,1,2,3,4,
1400,1401,1402,1403,1404,
600,601,602,603,604,
800,801,802,803,804};

Segment seg[] = {
   Segment(1000,1004),  // 0
   Segment(400,404),  // 1
   Segment(0,4),  // 2
   Segment(1400,1404),  // 3
   Segment(600,604),  // 4
   Segment(800,804),  // 5
   Segment(44,48),  // 6
   Segment(891,895),  // 7
   Segment(968,972),  // 8
   Segment(1056,1060),  // 9
   Segment(82,86),  // 10
   Segment(485,489),  // 11
   Segment(666,670),  // 12
   Segment(1424,1428),  // 13
   Segment(529,533),  // 14
   Segment(716,720),  // 15
   Segment(302,306),  // 16
   Segment(763,767),  // 17
   Segment(1504,1508),  // 18
   Segment(921,925),  // 19
   Segment(1484,1488),  // 20
   Segment(322,326),  // 21
   Segment(1462,1466),  // 22
   Segment(231,235),  // 23
   Segment(128,132),  // 24
   Segment(1356,1360),  // 25
   Segment(249,253),  // 26
   Segment(1200,1204),  // 27
   Segment(642,646),  // 28
   Segment(1118,1122), // 29
   Segment(5,43), // 30
   Segment(49,81),  // 31
   Segment(87,112), // 32
   Segment(113,127),  // 33
   Segment(133,162),  // 34
   Segment(163,193),  // 35
   Segment(200,230),  // 36
   Segment(236,248),  // 37
   Segment(254,301),  // 38
   Segment(307,321),  // 39
   Segment(327,346),  // 40
   Segment(405,431),  // 41
   Segment(432,469),  // 42
   Segment(470,484),  // 43
   Segment(490,504),  // 44
   Segment(505,528),  // 45
   Segment(534,569),  // 46
   Segment(605,641),  // 47
   Segment(647,665),  // 48
   Segment(671,697),  // 49
   Segment(698,715),  // 50
   Segment(721,762),  // 51
   Segment(805,838),  // 52
   Segment(839,890),  // 53
   Segment(896,920),  // 54
   Segment(926,967),  // 55
   Segment(973,993),  // 56
   Segment(1005,1055),  // 57
   Segment(1061,1081),  // 58
   Segment(1082,1109),  // 59
   Segment(1110,1117),  // 60
   Segment(1123,1144),  // 61
   Segment(1145,1174),  // 62
   Segment(1175,1191),  // 63
   Segment(1205,1235),  // 64
   Segment(1236,1277),  // 65
   Segment(1278,1300),  // 66
   Segment(1301,1321),  // 67
   Segment(1322,1355),  // 68
   Segment(1361,1394),  // 69
   Segment(1405,1423),  // 70
   Segment(1429,1461),  // 71
   Segment(1467,1483),  // 72
   Segment(1489,1503),  // 73
   Segment(1509,1531), // 74

   Segment(sizeof(coreLeds)/2,coreLeds) // 75
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
//  &seg[30],
  &seg[31],
  &seg[46]
};

Segment *seg7Conn[] = {
//  &seg[52],
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
//  &seg[57],
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
//  &seg[70],
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
//  &seg[41],
  &seg[42],
  &seg[64]
};

Segment *seg28Conn[] = {
  &seg[36],
//  &seg[47],
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

