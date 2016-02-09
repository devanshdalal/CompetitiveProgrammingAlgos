#include<cstdio>
using namespace std;
int ki;
int se[3200]={1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190, 210, 231, 253, 276, 300, 325, 351, 378, 406, 435, 465, 496, 528, 561, 595, 630, 666, 703, 741, 780, 820, 861, 903, 946, 990, 1035, 1081, 1128, 1176, 1225, 1275, 1326, 1378, 1431, 1485, 1540, 1596, 1653, 1711, 1770, 1830, 1891, 1953, 2016, 2080, 2145, 2211, 2278, 2346, 2415, 2485, 2556, 2628, 2701, 2775, 2850, 2926, 3003, 3081, 3160, 3240, 3321, 3403, 3486, 3570, 3655, 3741, 3828, 3916, 4005, 4095, 4186, 4278, 4371, 4465, 4560, 4656, 4753, 4851, 4950, 5050, 5151, 5253, 5356, 5460, 5565, 5671, 5778, 5886, 5995, 6105, 6216, 6328, 6441, 6555, 6670, 6786, 6903, 7021, 7140, 7260, 7381, 7503, 7626, 7750, 7875, 8001, 8128, 8256, 8385, 8515, 8646, 8778, 8911, 9045, 9180, 9316, 9453, 9591, 9730, 9870, 10011, 10153, 10296, 10440, 10585, 10731, 10878, 11026, 11175, 11325, 11476, 11628, 11781, 11935, 12090, 12246, 12403, 12561, 12720, 12880, 13041, 13203, 13366, 13530, 13695, 13861, 14028, 14196, 14365, 14535, 14706, 14878, 15051, 15225, 15400, 15576, 15753, 15931, 16110, 16290, 16471, 16653, 16836, 17020, 17205, 17391, 17578, 17766, 17955, 18145, 18336, 18528, 18721, 18915, 19110, 19306, 19503, 19701, 19900, 20100, 20301, 20503, 20706, 20910, 21115, 21321, 21528, 21736, 21945, 22155, 22366, 22578, 22791, 23005, 23220, 23436, 23653, 23871, 24090, 24310, 24531, 24753, 24976, 25200, 25425, 25651, 25878, 26106, 26335, 26565, 26796, 27028, 27261, 27495, 27730, 27966, 28203, 28441, 28680, 28920, 29161, 29403, 29646, 29890, 30135, 30381, 30628, 30876, 31125, 31375, 31626, 31878, 32131, 32385, 32640, 32896, 33153, 33411, 33670, 33930, 34191, 34453, 34716, 34980, 35245, 35511, 35778, 36046, 36315, 36585, 36856, 37128, 37401, 37675, 37950, 38226, 38503, 38781, 39060, 39340, 39621, 39903, 40186, 40470, 40755, 41041, 41328, 41616, 41905, 42195, 42486, 42778, 43071, 43365, 43660, 43956, 44253, 44551, 44850, 45150, 45451, 45753, 46056, 46360, 46665, 46971, 47278, 47586, 47895, 48205, 48516, 48828, 49141, 49455, 49770, 50086, 50403, 50721, 51040, 51360, 51681, 52003, 52326, 52650, 52975, 53301, 53628, 53956, 54285, 54615, 54946, 55278, 55611, 55945, 56280, 56616, 56953, 57291, 57630, 57970, 58311, 58653, 58996, 59340, 59685, 60031, 60378, 60726, 61075, 61425, 61776, 62128, 62481, 62835, 63190, 63546, 63903, 64261, 64620, 64980, 65341, 65703, 66066, 66430, 66795, 67161, 67528, 67896, 68265, 68635, 69006, 69378, 69751, 70125, 70500, 70876, 71253, 71631, 72010, 72390, 72771, 73153, 73536, 73920, 74305, 74691, 75078, 75466, 75855, 76245, 76636, 77028, 77421, 77815, 78210, 78606, 79003, 79401, 79800, 80200, 80601, 81003, 81406, 81810, 82215, 82621, 83028, 83436, 83845, 84255, 84666, 85078, 85491, 85905, 86320, 86736, 87153, 87571, 87990, 88410, 88831, 89253, 89676, 90100, 90525, 90951, 91378, 91806, 92235, 92665, 93096, 93528, 93961, 94395, 94830, 95266, 95703, 96141, 96580, 97020, 97461, 97903, 98346, 98790, 99235, 99681, 100128, 100576, 101025, 101475, 101926, 102378, 102831, 103285, 103740, 104196, 104653, 105111, 105570, 106030, 106491, 106953, 107416, 107880, 108345, 108811, 109278, 109746, 110215, 110685, 111156, 111628, 112101, 112575, 113050, 113526, 114003, 114481, 114960, 115440, 115921, 116403, 116886, 117370, 117855, 118341, 118828, 119316, 119805, 120295, 120786, 121278, 121771, 122265, 122760, 123256, 123753, 124251, 124750, 125250, 125751, 126253, 126756, 127260, 127765, 128271, 128778, 129286, 129795, 130305, 130816, 131328, 131841, 132355, 132870, 133386, 133903, 134421, 134940, 135460, 135981, 136503, 137026, 137550, 138075, 138601, 139128, 139656, 140185, 140715, 141246, 141778, 142311, 142845, 143380, 143916, 144453, 144991, 145530, 146070, 146611, 147153, 147696, 148240, 148785, 149331, 149878, 150426, 150975, 151525, 152076, 152628, 153181, 153735, 154290, 154846, 155403, 155961, 156520, 157080, 157641, 158203, 158766, 159330, 159895, 160461, 161028, 161596, 162165, 162735, 163306, 163878, 164451, 165025, 165600, 166176, 166753, 167331, 167910, 168490, 169071, 169653, 170236, 170820, 171405, 171991, 172578, 173166, 173755, 174345, 174936, 175528, 176121, 176715, 177310, 177906, 178503, 179101, 179700, 180300, 180901, 181503, 182106, 182710, 183315, 183921, 184528, 185136, 185745, 186355, 186966, 187578, 188191, 188805, 189420, 190036, 190653, 191271, 191890, 192510, 193131, 193753, 194376, 195000, 195625, 196251, 196878, 197506, 198135, 198765, 199396, 200028, 200661, 201295, 201930, 202566, 203203, 203841, 204480, 205120, 205761, 206403, 207046, 207690, 208335, 208981, 209628, 210276, 210925, 211575, 212226, 212878, 213531, 214185, 214840, 215496, 216153, 216811, 217470, 218130, 218791, 219453, 220116, 220780, 221445, 222111, 222778, 223446, 224115, 224785, 225456, 226128, 226801, 227475, 228150, 228826, 229503, 230181, 230860, 231540, 232221, 232903, 233586, 234270, 234955, 235641, 236328, 237016, 237705, 238395, 239086, 239778, 240471, 241165, 241860, 242556, 243253, 243951, 244650, 245350, 246051, 246753, 247456, 248160, 248865, 249571, 250278, 250986, 251695, 252405, 253116, 253828, 254541, 255255, 255970, 256686, 257403, 258121, 258840, 259560, 260281, 261003, 261726, 262450, 263175, 263901, 264628, 265356, 266085, 266815, 267546, 268278, 269011, 269745, 270480, 271216, 271953, 272691, 273430, 274170, 274911, 275653, 276396, 277140, 277885, 278631, 279378, 280126, 280875, 281625, 282376, 283128, 283881, 284635, 285390, 286146, 286903, 287661, 288420, 289180, 289941, 290703, 291466, 292230, 292995, 293761, 294528, 295296, 296065, 296835, 297606, 298378, 299151, 299925, 300700, 301476, 302253, 303031, 303810, 304590, 305371, 306153, 306936, 307720, 308505, 309291, 310078, 310866, 311655, 312445, 313236, 314028, 314821, 315615, 316410, 317206, 318003, 318801, 319600, 320400, 321201, 322003, 322806, 323610, 324415, 325221, 326028, 326836, 327645, 328455, 329266, 330078, 330891, 331705, 332520, 333336, 334153, 334971, 335790, 336610, 337431, 338253, 339076, 339900, 340725, 341551, 342378, 343206, 344035, 344865, 345696, 346528, 347361, 348195, 349030, 349866, 350703, 351541, 352380, 353220, 354061, 354903, 355746, 356590, 357435, 358281, 359128, 359976, 360825, 361675, 362526, 363378, 364231, 365085, 365940, 366796, 367653, 368511, 369370, 370230, 371091, 371953, 372816, 373680, 374545, 375411, 376278, 377146, 378015, 378885, 379756, 380628, 381501, 382375, 383250, 384126, 385003, 385881, 386760, 387640, 388521, 389403, 390286, 391170, 392055, 392941, 393828, 394716, 395605, 396495, 397386, 398278, 399171, 400065, 400960, 401856, 402753, 403651, 404550, 405450, 406351, 407253, 408156, 409060, 409965, 410871, 411778, 412686, 413595, 414505, 415416, 416328, 417241, 418155, 419070, 419986, 420903, 421821, 422740, 423660, 424581, 425503, 426426, 427350, 428275, 429201, 430128, 431056, 431985, 432915, 433846, 434778, 435711, 436645, 437580, 438516, 439453, 440391, 441330, 442270, 443211, 444153, 445096, 446040, 446985, 447931, 448878, 449826, 450775, 451725, 452676, 453628, 454581, 455535, 456490, 457446, 458403, 459361, 460320, 461280, 462241, 463203, 464166, 465130, 466095, 467061, 468028, 468996, 469965, 470935, 471906, 472878, 473851, 474825, 475800, 476776, 477753, 478731, 479710, 480690, 481671, 482653, 483636, 484620, 485605, 486591, 487578, 488566, 489555, 490545, 491536, 492528, 493521, 494515, 495510, 496506, 497503, 498501, 499500, 500500, 501501, 502503, 503506, 504510, 505515, 506521, 507528, 508536, 509545, 510555, 511566, 512578, 513591, 514605, 515620, 516636, 517653, 518671, 519690, 520710, 521731, 522753, 523776, 524800, 525825, 526851, 527878, 528906, 529935, 530965, 531996, 533028, 534061, 535095, 536130, 537166, 538203, 539241, 540280, 541320, 542361, 543403, 544446, 545490, 546535, 547581, 548628, 549676, 550725, 551775, 552826, 553878, 554931, 555985, 557040, 558096, 559153, 560211, 561270, 562330, 563391, 564453, 565516, 566580, 567645, 568711, 569778, 570846, 571915, 572985, 574056, 575128, 576201, 577275, 578350, 579426, 580503, 581581, 582660, 583740, 584821, 585903, 586986, 588070, 589155, 590241, 591328, 592416, 593505, 594595, 595686, 596778, 597871, 598965, 600060, 601156, 602253, 603351, 604450, 605550, 606651, 607753, 608856, 609960, 611065, 612171, 613278, 614386, 615495, 616605, 617716, 618828, 619941, 621055, 622170, 623286, 624403, 625521, 626640, 627760, 628881, 630003, 631126, 632250, 633375, 634501, 635628, 636756, 637885, 639015, 640146, 641278, 642411, 643545, 644680, 645816, 646953, 648091, 649230, 650370, 651511, 652653, 653796, 654940, 656085, 657231, 658378, 659526, 660675, 661825, 662976, 664128, 665281, 666435, 667590, 668746, 669903, 671061, 672220, 673380, 674541, 675703, 676866, 678030, 679195, 680361, 681528, 682696, 683865, 685035, 686206, 687378, 688551, 689725, 690900, 692076, 693253, 694431, 695610, 696790, 697971, 699153, 700336, 701520, 702705, 703891, 705078, 706266, 707455, 708645, 709836, 711028, 712221, 713415, 714610, 715806, 717003, 718201, 719400, 720600, 721801, 723003, 724206, 725410, 726615, 727821, 729028, 730236, 731445, 732655, 733866, 735078, 736291, 737505, 738720, 739936, 741153, 742371, 743590, 744810, 746031, 747253, 748476, 749700, 750925, 752151, 753378, 754606, 755835, 757065, 758296, 759528, 760761, 761995, 763230, 764466, 765703, 766941, 768180, 769420, 770661, 771903, 773146, 774390, 775635, 776881, 778128, 779376, 780625, 781875, 783126, 784378, 785631, 786885, 788140, 789396, 790653, 791911, 793170, 794430, 795691, 796953, 798216, 799480, 800745, 802011, 803278, 804546, 805815, 807085, 808356, 809628, 810901, 812175, 813450, 814726, 816003, 817281, 818560, 819840, 821121, 822403, 823686, 824970, 826255, 827541, 828828, 830116, 831405, 832695, 833986, 835278, 836571, 837865, 839160, 840456, 841753, 843051, 844350, 845650, 846951, 848253, 849556, 850860, 852165, 853471, 854778, 856086, 857395, 858705, 860016, 861328, 862641, 863955, 865270, 866586, 867903, 869221, 870540, 871860, 873181, 874503, 875826, 877150, 878475, 879801, 881128, 882456, 883785, 885115, 886446, 887778, 889111, 890445, 891780, 893116, 894453, 895791, 897130, 898470, 899811, 901153, 902496, 903840, 905185, 906531, 907878, 909226, 910575, 911925, 913276, 914628, 915981, 917335, 918690, 920046, 921403, 922761, 924120, 925480, 926841, 928203, 929566, 930930, 932295, 933661, 935028, 936396, 937765, 939135, 940506, 941878, 943251, 944625, 946000, 947376, 948753, 950131, 951510, 952890, 954271, 955653, 957036, 958420, 959805, 961191, 962578, 963966, 965355, 966745, 968136, 969528, 970921, 972315, 973710, 975106, 976503, 977901, 979300, 980700, 982101, 983503, 984906, 986310, 987715, 989121, 990528, 991936, 993345, 994755, 996166, 997578, 998991, 1000405, 1001820, 1003236, 1004653, 1006071, 1007490, 1008910, 1010331, 1011753, 1013176, 1014600, 1016025, 1017451, 1018878, 1020306, 1021735, 1023165, 1024596, 1026028, 1027461, 1028895, 1030330, 1031766, 1033203, 1034641, 1036080, 1037520, 1038961, 1040403, 1041846, 1043290, 1044735, 1046181, 1047628, 1049076, 1050525, 1051975, 1053426, 1054878, 1056331, 1057785, 1059240, 1060696, 1062153, 1063611, 1065070, 1066530, 1067991, 1069453, 1070916, 1072380, 1073845, 1075311, 1076778, 1078246, 1079715, 1081185, 1082656, 1084128, 1085601, 1087075, 1088550, 1090026, 1091503, 1092981, 1094460, 1095940, 1097421, 1098903, 1100386, 1101870, 1103355, 1104841, 1106328, 1107816, 1109305, 1110795, 1112286, 1113778, 1115271, 1116765, 1118260, 1119756, 1121253, 1122751, 1124250, 1125750, 1127251, 1128753, 1130256, 1131760, 1133265, 1134771, 1136278, 1137786, 1139295, 1140805, 1142316, 1143828, 1145341, 1146855, 1148370, 1149886, 1151403, 1152921, 1154440, 1155960, 1157481, 1159003, 1160526, 1162050, 1163575, 1165101, 1166628, 1168156, 1169685, 1171215, 1172746, 1174278, 1175811, 1177345, 1178880, 1180416, 1181953, 1183491, 1185030, 1186570, 1188111, 1189653, 1191196, 1192740, 1194285, 1195831, 1197378, 1198926, 1200475, 1202025, 1203576, 1205128, 1206681, 1208235, 1209790, 1211346, 1212903, 1214461, 1216020, 1217580, 1219141, 1220703, 1222266, 1223830, 1225395, 1226961, 1228528, 1230096, 1231665, 1233235, 1234806, 1236378, 1237951, 1239525, 1241100, 1242676, 1244253, 1245831, 1247410, 1248990, 1250571, 1252153, 1253736, 1255320, 1256905, 1258491, 1260078, 1261666, 1263255, 1264845, 1266436, 1268028, 1269621, 1271215, 1272810, 1274406, 1276003, 1277601, 1279200, 1280800, 1282401, 1284003, 1285606, 1287210, 1288815, 1290421, 1292028, 1293636, 1295245, 1296855, 1298466, 1300078, 1301691, 1303305, 1304920, 1306536, 1308153, 1309771, 1311390, 1313010, 1314631, 1316253, 1317876, 1319500, 1321125, 1322751, 1324378, 1326006, 1327635, 1329265, 1330896, 1332528, 1334161, 1335795, 1337430, 1339066, 1340703, 1342341, 1343980, 1345620, 1347261, 1348903, 1350546, 1352190, 1353835, 1355481, 1357128, 1358776, 1360425, 1362075, 1363726, 1365378, 1367031, 1368685, 1370340, 1371996, 1373653, 1375311, 1376970, 1378630, 1380291, 1381953, 1383616, 1385280, 1386945, 1388611, 1390278, 1391946, 1393615, 1395285, 1396956, 1398628, 1400301, 1401975, 1403650, 1405326, 1407003, 1408681, 1410360, 1412040, 1413721, 1415403, 1417086, 1418770, 1420455, 1422141, 1423828, 1425516, 1427205, 1428895, 1430586, 1432278, 1433971, 1435665, 1437360, 1439056, 1440753, 1442451, 1444150, 1445850, 1447551, 1449253, 1450956, 1452660, 1454365, 1456071, 1457778, 1459486, 1461195, 1462905, 1464616, 1466328, 1468041, 1469755, 1471470, 1473186, 1474903, 1476621, 1478340, 1480060, 1481781, 1483503, 1485226, 1486950, 1488675, 1490401, 1492128, 1493856, 1495585, 1497315, 1499046, 1500778, 1502511, 1504245, 1505980, 1507716, 1509453, 1511191, 1512930, 1514670, 1516411, 1518153, 1519896, 1521640, 1523385, 1525131, 1526878, 1528626, 1530375, 1532125, 1533876, 1535628, 1537381, 1539135, 1540890, 1542646, 1544403, 1546161, 1547920, 1549680, 1551441, 1553203, 1554966, 1556730, 1558495, 1560261, 1562028, 1563796, 1565565, 1567335, 1569106, 1570878, 1572651, 1574425, 1576200, 1577976, 1579753, 1581531, 1583310, 1585090, 1586871, 1588653, 1590436, 1592220, 1594005, 1595791, 1597578, 1599366, 1601155, 1602945, 1604736, 1606528, 1608321, 1610115, 1611910, 1613706, 1615503, 1617301, 1619100, 1620900, 1622701, 1624503, 1626306, 1628110, 1629915, 1631721, 1633528, 1635336, 1637145, 1638955, 1640766, 1642578, 1644391, 1646205, 1648020, 1649836, 1651653, 1653471, 1655290, 1657110, 1658931, 1660753, 1662576, 1664400, 1666225, 1668051, 1669878, 1671706, 1673535, 1675365, 1677196, 1679028, 1680861, 1682695, 1684530, 1686366, 1688203, 1690041, 1691880, 1693720, 1695561, 1697403, 1699246, 1701090, 1702935, 1704781, 1706628, 1708476, 1710325, 1712175, 1714026, 1715878, 1717731, 1719585, 1721440, 1723296, 1725153, 1727011, 1728870, 1730730, 1732591, 1734453, 1736316, 1738180, 1740045, 1741911, 1743778, 1745646, 1747515, 1749385, 1751256, 1753128, 1755001, 1756875, 1758750, 1760626, 1762503, 1764381, 1766260, 1768140, 1770021, 1771903, 1773786, 1775670, 1777555, 1779441, 1781328, 1783216, 1785105, 1786995, 1788886, 1790778, 1792671, 1794565, 1796460, 1798356, 1800253, 1802151, 1804050, 1805950, 1807851, 1809753, 1811656, 1813560, 1815465, 1817371, 1819278, 1821186, 1823095, 1825005, 1826916, 1828828, 1830741, 1832655, 1834570, 1836486, 1838403, 1840321, 1842240, 1844160, 1846081, 1848003, 1849926, 1851850, 1853775, 1855701, 1857628, 1859556, 1861485, 1863415, 1865346, 1867278, 1869211, 1871145, 1873080, 1875016, 1876953, 1878891, 1880830, 1882770, 1884711, 1886653, 1888596, 1890540, 1892485, 1894431, 1896378, 1898326, 1900275, 1902225, 1904176, 1906128, 1908081, 1910035, 1911990, 1913946, 1915903, 1917861, 1919820, 1921780, 1923741, 1925703, 1927666, 1929630, 1931595, 1933561, 1935528, 1937496, 1939465, 1941435, 1943406, 1945378, 1947351, 1949325, 1951300, 1953276, 1955253, 1957231, 1959210, 1961190, 1963171, 1965153, 1967136, 1969120, 1971105, 1973091, 1975078, 1977066, 1979055, 1981045, 1983036, 1985028, 1987021, 1989015, 1991010, 1993006, 1995003, 1997001, 1999000, 2001000, 2003001, 2005003, 2007006, 2009010, 2011015, 2013021, 2015028, 2017036, 2019045, 2021055, 2023066, 2025078, 2027091, 2029105, 2031120, 2033136, 2035153, 2037171, 2039190, 2041210, 2043231, 2045253, 2047276, 2049300, 2051325, 2053351, 2055378, 2057406, 2059435, 2061465, 2063496, 2065528, 2067561, 2069595, 2071630, 2073666, 2075703, 2077741, 2079780, 2081820, 2083861, 2085903, 2087946, 2089990, 2092035, 2094081, 2096128, 2098176, 2100225, 2102275, 2104326, 2106378, 2108431, 2110485, 2112540, 2114596, 2116653, 2118711, 2120770, 2122830, 2124891, 2126953, 2129016, 2131080, 2133145, 2135211, 2137278, 2139346, 2141415, 2143485, 2145556, 2147628, 2149701, 2151775, 2153850, 2155926, 2158003, 2160081, 2162160, 2164240, 2166321, 2168403, 2170486, 2172570, 2174655, 2176741, 2178828, 2180916, 2183005, 2185095, 2187186, 2189278, 2191371, 2193465, 2195560, 2197656, 2199753, 2201851, 2203950, 2206050, 2208151, 2210253, 2212356, 2214460, 2216565, 2218671, 2220778, 2222886, 2224995, 2227105, 2229216, 2231328, 2233441, 2235555, 2237670, 2239786, 2241903, 2244021, 2246140, 2248260, 2250381, 2252503, 2254626, 2256750, 2258875, 2261001, 2263128, 2265256, 2267385, 2269515, 2271646, 2273778, 2275911, 2278045, 2280180, 2282316, 2284453, 2286591, 2288730, 2290870, 2293011, 2295153, 2297296, 2299440, 2301585, 2303731, 2305878, 2308026, 2310175, 2312325, 2314476, 2316628, 2318781, 2320935, 2323090, 2325246, 2327403, 2329561, 2331720, 2333880, 2336041, 2338203, 2340366, 2342530, 2344695, 2346861, 2349028, 2351196, 2353365, 2355535, 2357706, 2359878, 2362051, 2364225, 2366400, 2368576, 2370753, 2372931, 2375110, 2377290, 2379471, 2381653, 2383836, 2386020, 2388205, 2390391, 2392578, 2394766, 2396955, 2399145, 2401336, 2403528, 2405721, 2407915, 2410110, 2412306, 2414503, 2416701, 2418900, 2421100, 2423301, 2425503, 2427706, 2429910, 2432115, 2434321, 2436528, 2438736, 2440945, 2443155, 2445366, 2447578, 2449791, 2452005, 2454220, 2456436, 2458653, 2460871, 2463090, 2465310, 2467531, 2469753, 2471976, 2474200, 2476425, 2478651, 2480878, 2483106, 2485335, 2487565, 2489796, 2492028, 2494261, 2496495, 2498730, 2500966, 2503203, 2505441, 2507680, 2509920, 2512161, 2514403, 2516646, 2518890, 2521135, 2523381, 2525628, 2527876, 2530125, 2532375, 2534626, 2536878, 2539131, 2541385, 2543640, 2545896, 2548153, 2550411, 2552670, 2554930, 2557191, 2559453, 2561716, 2563980, 2566245, 2568511, 2570778, 2573046, 2575315, 2577585, 2579856, 2582128, 2584401, 2586675, 2588950, 2591226, 2593503, 2595781, 2598060, 2600340, 2602621, 2604903, 2607186, 2609470, 2611755, 2614041, 2616328, 2618616, 2620905, 2623195, 2625486, 2627778, 2630071, 2632365, 2634660, 2636956, 2639253, 2641551, 2643850, 2646150, 2648451, 2650753, 2653056, 2655360, 2657665, 2659971, 2662278, 2664586, 2666895, 2669205, 2671516, 2673828, 2676141, 2678455, 2680770, 2683086, 2685403, 2687721, 2690040, 2692360, 2694681, 2697003, 2699326, 2701650, 2703975, 2706301, 2708628, 2710956, 2713285, 2715615, 2717946, 2720278, 2722611, 2724945, 2727280, 2729616, 2731953, 2734291, 2736630, 2738970, 2741311, 2743653, 2745996, 2748340, 2750685, 2753031, 2755378, 2757726, 2760075, 2762425, 2764776, 2767128, 2769481, 2771835, 2774190, 2776546, 2778903, 2781261, 2783620, 2785980, 2788341, 2790703, 2793066, 2795430, 2797795, 2800161, 2802528, 2804896, 2807265, 2809635, 2812006, 2814378, 2816751, 2819125, 2821500, 2823876, 2826253, 2828631, 2831010, 2833390, 2835771, 2838153, 2840536, 2842920, 2845305, 2847691, 2850078, 2852466, 2854855, 2857245, 2859636, 2862028, 2864421, 2866815, 2869210, 2871606, 2874003, 2876401, 2878800, 2881200, 2883601, 2886003, 2888406, 2890810, 2893215, 2895621, 2898028, 2900436, 2902845, 2905255, 2907666, 2910078, 2912491, 2914905, 2917320, 2919736, 2922153, 2924571, 2926990, 2929410, 2931831, 2934253, 2936676, 2939100, 2941525, 2943951, 2946378, 2948806, 2951235, 2953665, 2956096, 2958528, 2960961, 2963395, 2965830, 2968266, 2970703, 2973141, 2975580, 2978020, 2980461, 2982903, 2985346, 2987790, 2990235, 2992681, 2995128, 2997576, 3000025, 3002475, 3004926, 3007378, 3009831, 3012285, 3014740, 3017196, 3019653, 3022111, 3024570, 3027030, 3029491, 3031953, 3034416, 3036880, 3039345, 3041811, 3044278, 3046746, 3049215, 3051685, 3054156, 3056628, 3059101, 3061575, 3064050, 3066526, 3069003, 3071481, 3073960, 3076440, 3078921, 3081403, 3083886, 3086370, 3088855, 3091341, 3093828, 3096316, 3098805, 3101295, 3103786, 3106278, 3108771, 3111265, 3113760, 3116256, 3118753, 3121251, 3123750, 3126250, 3128751, 3131253, 3133756, 3136260, 3138765, 3141271, 3143778, 3146286, 3148795, 3151305, 3153816, 3156328, 3158841, 3161355, 3163870, 3166386, 3168903, 3171421, 3173940, 3176460, 3178981, 3181503, 3184026, 3186550, 3189075, 3191601, 3194128, 3196656, 3199185, 3201715, 3204246, 3206778, 3209311, 3211845, 3214380, 3216916, 3219453, 3221991, 3224530, 3227070, 3229611, 3232153, 3234696, 3237240, 3239785, 3242331, 3244878, 3247426, 3249975, 3252525, 3255076, 3257628, 3260181, 3262735, 3265290, 3267846, 3270403, 3272961, 3275520, 3278080, 3280641, 3283203, 3285766, 3288330, 3290895, 3293461, 3296028, 3298596, 3301165, 3303735, 3306306, 3308878, 3311451, 3314025, 3316600, 3319176, 3321753, 3324331, 3326910, 3329490, 3332071, 3334653, 3337236, 3339820, 3342405, 3344991, 3347578, 3350166, 3352755, 3355345, 3357936, 3360528, 3363121, 3365715, 3368310, 3370906, 3373503, 3376101, 3378700, 3381300, 3383901, 3386503, 3389106, 3391710, 3394315, 3396921, 3399528, 3402136, 3404745, 3407355, 3409966, 3412578, 3415191, 3417805, 3420420, 3423036, 3425653, 3428271, 3430890, 3433510, 3436131, 3438753, 3441376, 3444000, 3446625, 3449251, 3451878, 3454506, 3457135, 3459765, 3462396, 3465028, 3467661, 3470295, 3472930, 3475566, 3478203, 3480841, 3483480, 3486120, 3488761, 3491403, 3494046, 3496690, 3499335, 3501981, 3504628, 3507276, 3509925, 3512575, 3515226, 3517878, 3520531, 3523185, 3525840, 3528496, 3531153, 3533811, 3536470, 3539130, 3541791, 3544453, 3547116, 3549780, 3552445, 3555111, 3557778, 3560446, 3563115, 3565785, 3568456, 3571128, 3573801, 3576475, 3579150, 3581826, 3584503, 3587181, 3589860, 3592540, 3595221, 3597903, 3600586, 3603270, 3605955, 3608641, 3611328, 3614016, 3616705, 3619395, 3622086, 3624778, 3627471, 3630165, 3632860, 3635556, 3638253, 3640951, 3643650, 3646350, 3649051, 3651753, 3654456, 3657160, 3659865, 3662571, 3665278, 3667986, 3670695, 3673405, 3676116, 3678828, 3681541, 3684255, 3686970, 3689686, 3692403, 3695121, 3697840, 3700560, 3703281, 3706003, 3708726, 3711450, 3714175, 3716901, 3719628, 3722356, 3725085, 3727815, 3730546, 3733278, 3736011, 3738745, 3741480, 3744216, 3746953, 3749691, 3752430, 3755170, 3757911, 3760653, 3763396, 3766140, 3768885, 3771631, 3774378, 3777126, 3779875, 3782625, 3785376, 3788128, 3790881, 3793635, 3796390, 3799146, 3801903, 3804661, 3807420, 3810180, 3812941, 3815703, 3818466, 3821230, 3823995, 3826761, 3829528, 3832296, 3835065, 3837835, 3840606, 3843378, 3846151, 3848925, 3851700, 3854476, 3857253, 3860031, 3862810, 3865590, 3868371, 3871153, 3873936, 3876720, 3879505, 3882291, 3885078, 3887866, 3890655, 3893445, 3896236, 3899028, 3901821, 3904615, 3907410, 3910206, 3913003, 3915801, 3918600, 3921400, 3924201, 3927003, 3929806, 3932610, 3935415, 3938221, 3941028, 3943836, 3946645, 3949455, 3952266, 3955078, 3957891, 3960705, 3963520, 3966336, 3969153, 3971971, 3974790, 3977610, 3980431, 3983253, 3986076, 3988900, 3991725, 3994551, 3997378, 4000206, 4003035, 4005865, 4008696, 4011528, 4014361, 4017195, 4020030, 4022866, 4025703, 4028541, 4031380, 4034220, 4037061, 4039903, 4042746, 4045590, 4048435, 4051281, 4054128, 4056976, 4059825, 4062675, 4065526, 4068378, 4071231, 4074085, 4076940, 4079796, 4082653, 4085511, 4088370, 4091230, 4094091, 4096953, 4099816, 4102680, 4105545, 4108411, 4111278, 4114146, 4117015, 4119885, 4122756, 4125628, 4128501, 4131375, 4134250, 4137126, 4140003, 4142881, 4145760, 4148640, 4151521, 4154403, 4157286, 4160170, 4163055, 4165941, 4168828, 4171716, 4174605, 4177495, 4180386, 4183278, 4186171, 4189065, 4191960, 4194856, 4197753, 4200651, 4203550, 4206450, 4209351, 4212253, 4215156, 4218060, 4220965, 4223871, 4226778, 4229686, 4232595, 4235505, 4238416, 4241328, 4244241, 4247155, 4250070, 4252986, 4255903, 4258821, 4261740, 4264660, 4267581, 4270503, 4273426, 4276350, 4279275, 4282201, 4285128, 4288056, 4290985, 4293915, 4296846, 4299778, 4302711, 4305645, 4308580, 4311516, 4314453, 4317391, 4320330, 4323270, 4326211, 4329153, 4332096, 4335040, 4337985, 4340931, 4343878, 4346826, 4349775, 4352725, 4355676, 4358628, 4361581, 4364535, 4367490, 4370446, 4373403, 4376361, 4379320, 4382280, 4385241, 4388203, 4391166, 4394130, 4397095, 4400061, 4403028, 4405996, 4408965, 4411935, 4414906, 4417878, 4420851, 4423825, 4426800, 4429776, 4432753, 4435731, 4438710, 4441690, 4444671, 4447653, 4450636, 4453620, 4456605, 4459591, 4462578, 4465566, 4468555, 4471545, 4474536, 4477528, 4480521, 4483515, 4486510, 4489506, 4492503, 4495501, 4498500, 4501500, 4504501, 4507503, 4510506, 4513510, 4516515, 4519521, 4522528, 4525536, 4528545, 4531555, 4534566, 4537578, 4540591, 4543605, 4546620, 4549636, 4552653, 4555671, 4558690, 4561710, 4564731, 4567753, 4570776, 4573800, 4576825, 4579851, 4582878, 4585906, 4588935, 4591965, 4594996, 4598028, 4601061, 4604095, 4607130, 4610166, 4613203, 4616241, 4619280, 4622320, 4625361, 4628403, 4631446, 4634490, 4637535, 4640581, 4643628, 4646676, 4649725, 4652775, 4655826, 4658878, 4661931, 4664985, 4668040, 4671096, 4674153, 4677211, 4680270, 4683330, 4686391, 4689453, 4692516, 4695580, 4698645, 4701711, 4704778, 4707846, 4710915, 4713985, 4717056, 4720128, 4723201, 4726275, 4729350, 4732426, 4735503, 4738581, 4741660, 4744740, 4747821, 4750903, 4753986, 4757070, 4760155, 4763241, 4766328, 4769416, 4772505, 4775595, 4778686, 4781778, 4784871, 4787965, 4791060, 4794156, 4797253, 4800351, 4803450, 4806550, 4809651, 4812753, 4815856, 4818960, 4822065, 4825171, 4828278, 4831386, 4834495, 4837605, 4840716, 4843828, 4846941, 4850055, 4853170, 4856286, 4859403, 4862521, 4865640, 4868760, 4871881, 4875003, 4878126, 4881250, 4884375, 4887501, 4890628, 4893756, 4896885, 4900015, 4903146, 4906278, 4909411, 4912545, 4915680, 4918816, 4921953, 4925091, 4928230, 4931370, 4934511, 4937653, 4940796, 4943940, 4947085, 4950231, 4953378, 4956526, 4959675, 4962825, 4965976, 4969128, 4972281, 4975435, 4978590, 4981746, 4984903, 4988061, 4991220, 4994380, 4997541, 5000703, 5003866, 5007030, 5010195, 5013361, 5016528, 5019696, 5022865, 5026035, 5029206, 5032378, 5035551, 5038725, 5041900, 5045076, 5048253, 5051431, 5054610, 5057790, 5060971, 5064153, 5067336, 5070520, 5073705, 5076891, 5080078, 5083266, 5086455, 5089645, 5092836, 5096028, 5099221, 5102415, 5105610, 5108806, 5112003, 5115201, 5118400, 5121600 };

int div[3200]={0, 1, 3, 3, 3, 3, 5, 8, 5, 3, 7, 7, 3, 7, 15, 7, 5, 5, 7, 15, 7, 3, 11, 17, 5, 7, 15, 7, 7, 7, 9, 19, 7, 7, 23, 11, 3, 7, 23, 11, 7, 7, 7, 23, 11, 3, 15, 23, 8, 11, 15, 7, 7, 15, 23, 23, 7, 3, 15, 15, 3, 11, 35, 23, 15, 7, 7, 15, 15, 7, 17, 17, 3, 11, 23, 15, 15, 7, 15, 39, 9, 3, 15, 31, 7, 7, 23, 11, 11, 23, 15, 15, 7, 7, 39, 19, 5, 17, 35, 11, 7, 7, 11, 47, 15, 3, 15, 15, 7, 15, 31, 15, 7, 15, 15, 23, 11, 7, 47, 35, 5, 7, 15, 15, 23, 11, 13, 27, 15, 7, 15, 31, 7, 15, 47, 11, 7, 7, 15, 31, 7, 7, 47, 47, 7, 11, 23, 7, 11, 11, 11, 35, 23, 15, 31, 15, 3, 7, 39, 39, 19, 9, 7, 31, 15, 3, 23, 35, 11, 23, 23, 7, 7, 23, 47, 31, 7, 3, 23, 23, 7, 15, 23, 23, 15, 15, 15, 31, 31, 7, 23, 23, 3, 15, 47, 11, 11, 11, 17, 35, 7, 7, 31, 31, 7, 11, 47, 31, 31, 15, 7, 15, 7, 7, 47, 47, 7, 7, 31, 31, 15, 7, 19, 89, 17, 3, 15, 15, 7, 31, 47, 11, 11, 23, 15, 15, 15, 7, 31, 31, 5, 17, 23, 23, 23, 15, 23, 23, 15, 7, 23, 47, 7, 15, 63, 15, 7, 15, 31, 47, 11, 3, 23, 47, 15, 15, 15, 7, 15, 15, 15, 63, 15, 11, 47, 15, 3, 11, 71, 23, 7, 7, 7, 31, 31, 15, 59, 44, 11, 15, 15, 7, 11, 23, 23, 47, 15, 7, 47, 47, 7, 7, 31, 31, 23, 11, 15, 31, 15, 7, 23, 23, 3, 23, 47, 7, 7, 15, 47, 47, 15, 15, 39, 59, 11, 7, 23, 23, 31, 15, 7, 23, 11, 7, 63, 31, 5, 11, 31, 31, 23, 23, 23, 47, 15, 3, 15, 15, 11, 47, 79, 19, 7, 15, 15, 31, 15, 3, 35, 53, 5, 11, 47, 31, 15, 7, 15, 47, 23, 15, 31, 15, 7, 31, 47, 23, 31, 15, 15, 31, 7, 3, 27, 111, 15, 11, 23, 7, 15, 31, 35, 35, 7, 7, 47, 23, 3, 15, 95, 23, 7, 15, 15, 39, 39, 15, 47, 23, 7, 15, 15, 15, 23, 23, 39, 39, 15, 7, 31, 31, 3, 11, 35, 35, 23, 15, 15, 31, 31, 7, 31, 31, 7, 31, 31, 15, 15, 7, 23, 107, 35, 7, 15, 31, 7, 7, 47, 23, 17, 35, 15, 15, 7, 15, 95, 23, 3, 15, 63, 15, 15, 15, 15, 63, 15, 3, 23, 47, 15, 15, 23, 23, 15, 23, 47, 47, 11, 3, 39, 79, 7, 15, 47, 23, 23, 11, 11, 23, 23, 11, 15, 31, 15, 47, 95, 31, 15, 7, 15, 31, 7, 3, 35, 71, 15, 23, 23, 7, 15, 31, 35, 71, 15, 7, 31, 31, 15, 15, 47, 23, 11, 11, 7, 47, 23, 7, 63, 47, 11, 23, 47, 31, 15, 15, 23, 23, 7, 11, 95, 31, 3, 7, 39, 39, 31, 15, 7, 23, 35, 23, 47, 47, 7, 15, 31, 7, 11, 23, 63, 127, 15, 3, 15, 31, 7, 19, 59, 11, 15, 15, 15, 31, 15, 23, 107, 35, 5, 11, 31, 31, 15, 15, 23, 71, 23, 3, 23, 47, 15, 15, 31, 15, 15, 63, 31, 15, 15, 7, 35, 35, 7, 23, 23, 23, 23, 7, 19, 79, 31, 15, 47, 23, 3, 15, 95, 23, 7, 7, 15, 63, 15, 7, 63, 79, 9, 15, 31, 15, 47, 23, 11, 23, 7, 7, 31, 47, 23, 23, 83, 27, 7, 7, 15, 63, 31, 7, 29, 59, 23, 47, 31, 7, 7, 15, 31, 47, 23, 7, 31, 31, 3, 15, 47, 47, 47, 23, 15, 15, 15, 15, 79, 39, 3, 23, 71, 11, 7, 15, 47, 47, 15, 7, 23, 47, 15, 15, 31, 31, 31, 15, 7, 47, 23, 7, 47, 47, 7, 7, 47, 23, 15, 31, 47, 95, 15, 7, 31, 15, 7, 23, 35, 23, 31, 63, 31, 15, 7, 3, 47, 95, 11, 11, 15, 23, 35, 11, 23, 83, 27, 15, 31, 15, 3, 23, 119, 39, 23, 11, 15, 63, 31, 7, 23, 47, 7, 11, 47, 31, 31, 15, 15, 31, 15, 15, 63, 31, 3, 15, 95, 23, 7, 15, 15, 47, 23, 7, 63, 31, 15, 31, 15, 7, 11, 35, 35, 47, 15, 7, 63, 63, 15, 31, 95, 47, 15, 7, 7, 15, 15, 15, 71, 71, 7, 15, 31, 7, 15, 31, 59, 89, 11, 7, 31, 63, 31, 15, 23, 11, 19, 19, 15, 31, 15, 15, 63, 63, 7, 23, 95, 15, 7, 7, 11, 71, 47, 7, 23, 23, 7, 15, 47, 71, 23, 15, 31, 63, 15, 3, 47, 71, 5, 7, 15, 23, 35, 35, 47, 31, 23, 23, 31, 15, 7, 47, 71, 11, 15, 15, 15, 63, 15, 3, 39, 79, 7, 11, 47, 31, 31, 31, 23, 35, 23, 31, 63, 15, 3, 7, 63, 31, 17, 17, 15, 63, 15, 3, 23, 47, 15, 39, 39, 15, 15, 15, 55, 111, 15, 7, 71, 71, 15, 31, 47, 23, 15, 7, 7, 23, 47, 15, 31, 63, 7, 15, 31, 15, 31, 15, 23, 47, 7, 7, 63, 95, 11, 11, 59, 19, 15, 47, 23, 15, 7, 15, 143, 35, 7, 15, 31, 15, 7, 15, 31, 127, 63, 7, 15, 31, 23, 23, 47, 23, 11, 23, 15, 31, 15, 7, 95, 71, 11, 23, 23, 15, 31, 15, 17, 71, 31, 7, 23, 47, 7, 23, 95, 15, 7, 15, 47, 71, 11, 3, 23, 47, 15, 31, 63, 31, 47, 23, 19, 39, 15, 15, 31, 15, 3, 15, 95, 95, 31, 15, 15, 31, 15, 7, 95, 47, 7, 15, 31, 15, 11, 47, 47, 35, 11, 3, 31, 31, 7, 31, 79, 59, 47, 31, 15, 31, 31, 7, 23, 23, 7, 47, 95, 31, 15, 7, 31, 63, 7, 7, 47, 95, 15, 7, 23, 11, 23, 23, 7, 39, 39, 15, 79, 79, 11, 11, 31, 15, 11, 11, 23, 95, 31, 15, 31, 15, 7, 47, 95, 31, 15, 23, 23, 15, 23, 23, 95, 95, 7, 11, 23, 31, 31, 7, 23, 107, 35, 7, 31, 31, 3, 15, 47, 11, 11, 23, 47, 47, 15, 7, 31, 127, 31, 31, 31, 7, 15, 31, 23, 47, 15, 7, 47, 23, 7, 15, 79, 79, 31, 15, 7, 47, 23, 11, 71, 23, 7, 31, 31, 15, 39, 39, 31, 31, 7, 7, 63, 63, 7, 11, 71, 47, 15, 15, 31, 31, 23, 11, 41, 41, 3, 31, 95, 23, 15, 15, 47, 95, 31, 7, 15, 31, 15, 15, 31, 31, 47, 23, 7, 31, 15, 11, 107, 71, 15, 23, 47, 15, 7, 23, 59, 79, 15, 3, 31, 63, 31, 31, 23, 11, 7, 15, 31, 95, 23, 7, 95, 47, 3, 7, 31, 31, 23, 23, 23, 47, 47, 23, 31, 15, 3, 23, 143, 23, 15, 31, 31, 63, 31, 7, 35, 161, 17, 7, 15, 7, 15, 15, 31, 95, 11, 15, 63, 15, 3, 15, 95, 47, 31, 31, 15, 31, 31, 15, 79, 39, 9, 29, 23, 15, 31, 31, 23, 23, 15, 7, 47, 95, 7, 7, 31, 63, 31, 15, 15, 31, 31, 15, 47, 47, 23, 71, 95, 15, 11, 11, 31, 127, 15, 3, 15, 31, 7, 23, 143, 23, 15, 15, 15, 31, 7, 15, 159, 39, 7, 15, 47, 23, 15, 15, 11, 71, 23, 3, 15, 63, 31, 31, 79, 39, 23, 23, 31, 31, 7, 3, 47, 47, 3, 23, 47, 23, 47, 15, 15, 31, 31, 31, 47, 47, 15, 31, 47, 23, 15, 15, 31, 47, 23, 15, 95, 95, 7, 7, 15, 15, 47, 47, 35, 71, 15, 7, 31, 31, 15, 23, 95, 31, 7, 15, 31, 127, 31, 3, 35, 53, 11, 15, 31, 15, 7, 31, 79, 99, 39, 15, 63, 31, 3, 7, 23, 23, 47, 47, 15, 15, 15, 15, 63, 63, 15, 47, 47, 15, 15, 7, 35, 71, 7, 7, 63, 63, 15, 31, 111, 27, 15, 31, 15, 23, 23, 15, 47, 47, 7, 15, 63, 47, 35, 11, 15, 95, 47, 7, 31, 31, 15, 63, 47, 11, 7, 31, 31, 15, 7, 3, 59, 119, 15, 31, 47, 35, 23, 7, 11, 71, 71, 11, 23, 23, 3, 15, 127, 63, 27, 13, 15, 31, 15, 31, 95, 47, 7, 11, 23, 15, 47, 23, 23, 47, 15, 23, 71, 47, 7, 15, 95, 23, 15, 15, 15, 127, 31, 3, 31, 31, 7, 31, 31, 7, 11, 47, 95, 47, 15, 7, 31, 63, 7, 11, 59, 79, 31, 15, 31, 31, 15, 7, 47, 95, 7, 15, 31, 15, 31, 47, 95, 143, 17, 3, 15, 47, 23, 15, 23, 23, 47, 23, 7, 31, 31, 15, 71, 71, 7, 19, 159, 63, 15, 7, 11, 47, 15, 15, 95, 23, 11, 47, 63, 15, 15, 31, 15, 23, 23, 7, 47, 95, 15, 15, 31, 31, 31, 15, 29, 59, 15, 7, 15, 47, 11, 35, 107, 23, 15, 7, 15, 63, 31, 7, 47, 95, 15, 23, 23, 15, 31, 31, 23, 47, 15, 15, 127, 31, 7, 31, 143, 35, 11, 23, 15, 31, 31, 7, 23, 23, 15, 47, 47, 15, 7, 31, 63, 95, 23, 3, 39, 39, 3, 7, 47, 95, 31, 7, 15, 47, 23, 15, 79, 79, 15, 31, 31, 7, 23, 47, 47, 47, 7, 7, 31, 63, 15, 15, 63, 31, 47, 47, 31, 63, 15, 7, 71, 35, 3, 15, 63, 31, 15, 7, 27, 167, 71, 11, 15, 15, 7, 15, 47, 47, 31, 47, 23, 31, 15, 7, 127, 95, 8, 35, 47, 15, 15, 15, 23, 23, 23, 23, 47, 23, 11, 47, 79, 19, 7, 7, 23, 143, 47, 15, 47, 95, 15, 7, 31, 15, 23, 47, 31, 31, 7, 15, 127, 63, 7, 11, 71, 23, 15, 15, 7, 47, 23, 7, 95, 191, 31, 15, 15, 7, 11, 23, 47, 71, 23, 15, 63, 31, 7, 31, 63, 31, 23, 11, 15, 63, 63, 31, 47, 23, 3, 31, 63, 15, 15, 7, 39, 79, 7, 7, 71, 71, 7, 15, 95, 47, 31, 63, 31, 23, 11, 11, 95, 31, 7, 15, 31, 31, 39, 19, 11, 95, 63, 7, 15, 15, 7, 23, 95, 63, 31, 31, 15, 15, 15, 15, 107, 53, 7, 15, 31, 47, 47, 31, 31, 63, 31, 7, 15, 47, 11, 23, 71, 23, 23, 23, 63, 63, 7, 3, 39, 119, 23, 47, 47, 15, 31, 15, 11, 47, 31, 15, 63, 63, 7, 7, 63, 63, 15, 15, 15, 47, 47, 7, 47, 71, 17, 23, 15, 15, 23, 47, 95, 47, 7, 11, 95, 31, 11, 59, 59, 23, 15, 7, 7, 31, 63, 15, 47, 47, 3, 19, 79, 15, 7, 7, 23, 143, 23, 7, 31, 63, 31, 31, 79, 19, 31, 63, 31, 31, 7, 7, 47, 47, 15, 23, 71, 23, 7, 15, 63, 127, 15, 3, 23, 47, 15, 47, 71, 11, 15, 31, 15, 31, 31, 15, 111, 111, 11, 11, 31, 95, 71, 23, 23, 23, 15, 7, 31, 31, 3, 23, 143, 47, 31, 31, 31, 31, 7, 7, 71, 71, 15, 31, 31, 7, 23, 23, 19, 119, 23, 15, 63, 31, 15, 15, 71, 71, 23, 23, 15, 31, 15, 7, 63, 63, 15, 31, 63, 15, 15, 47, 71, 47, 15, 7, 47, 95, 7, 7, 47, 47, 15, 7, 15, 95, 47, 15, 47, 23, 3, 31, 63, 7, 15, 15, 31, 127, 63, 15, 15, 31, 15, 23, 35, 35, 47, 15, 7, 31, 31, 31, 239, 59, 3, 7, 31, 31, 15, 23, 71, 179, 29, 3, 23, 23, 15, 31, 31, 31, 23, 47, 31, 31, 15, 3, 47, 95, 7, 11, 47, 31, 31, 31, 43, 43, 23, 23, 63, 31, 7, 31, 47, 35, 47, 31, 31, 47, 11, 3, 31, 127, 15, 15, 63, 15, 23, 47, 47, 47, 15, 23, 47, 31, 7, 31, 319, 39, 7, 7, 7, 31, 31, 7, 35, 35, 15, 63, 31, 31, 31, 15, 31, 47, 11, 3, 47, 95, 7, 7, 23, 23, 39, 59, 47, 63, 31, 7, 47, 47, 7, 47, 71, 23, 15, 15, 47, 95, 15, 7, 47, 95, 15, 7, 63, 31, 15, 15, 15, 63, 31, 31, 95, 23, 3, 15, 63, 15, 23, 23, 19, 159, 63, 15, 31, 31, 23, 35, 35, 11, 7, 15, 47, 47, 15, 15, 127, 63, 7, 31, 31, 15, 23, 23, 23, 35, 47, 31, 31, 31, 7, 23, 167, 55, 35, 17, 15, 31, 7, 7, 95, 191, 15, 15, 31, 15, 31, 31, 31, 63, 15, 7, 47, 47, 15, 15, 71, 71, 15, 7, 15, 143, 35, 3, 39, 59, 23, 63, 63, 15, 15, 31, 23, 23, 7, 7, 63, 31, 7, 47, 95, 47, 47, 31, 15, 15, 15, 15, 71, 143, 15, 15, 63, 15, 7, 7, 47, 191, 31, 7, 31, 63, 7, 15, 47, 23, 47, 23, 7, 15, 23, 47, 127, 63, 7, 11, 47, 63, 63, 31, 23, 47, 31, 7, 39, 39, 7, 15, 39, 19, 7, 47, 47, 47, 47, 15, 95, 47, 7, 15, 15, 15, 23, 11, 31, 127, 31, 15, 31, 15, 7, 63, 191, 23, 7, 23, 71, 95, 15, 11, 143, 95, 7, 7, 15, 7, 31, 31, 17, 53, 23, 15, 31, 31, 15, 15, 63, 63, 31, 31, 31, 95, 23, 7, 47, 47, 15, 47, 95, 15, 7, 15, 39, 79, 31, 7, 47, 47, 3, 15, 47, 47, 63, 15, 7, 39, 59, 11, 47, 95, 15, 31, 63, 15, 11, 23, 47, 47, 7, 7, 31, 63, 47, 35, 71, 47, 31, 15, 7, 31, 15, 15, 191, 47, 7, 31, 127, 31, 7, 7, 15, 95, 23, 15, 63, 15, 7, 15, 47, 23, 23, 47, 15, 31, 31, 7, 59, 149, 9, 15, 31, 31, 31, 15, 47, 95, 31, 7, 23, 47, 15, 63, 127, 15, 15, 31, 47, 71, 23, 7, 23, 71, 11, 7, 15, 15, 47, 95, 111, 55, 7, 7, 63, 31, 7, 23, 71, 23, 15, 31, 31, 63, 15, 3, 47, 95, 35, 71, 31, 15, 15, 15, 23, 95, 31, 3, 31, 63, 7, 7, 79, 159, 47, 11, 7, 15, 31, 31, 47, 23, 3, 35, 71, 7, 15, 31, 63, 63, 15, 15, 63, 127, 31, 15, 23, 23, 31, 31, 31, 47, 23, 15, 95, 95, 7, 23, 119, 39, 23, 11, 11, 47, 31, 15, 63, 63, 15, 39, 79, 31, 15, 15, 31, 31, 7, 7, 143, 71, 7, 23, 23, 23, 23, 23, 59, 59, 47, 15, 15, 31, 15, 47, 71, 23, 31, 15, 15, 95, 47, 7, 31, 63, 15, 23, 71, 23, 23, 23, 23, 95, 15, 15, 95, 23, 3, 7, 71, 71, 31, 31, 15, 63, 31, 7, 47, 47, 15, 15, 15, 15, 47, 71, 95, 63, 7, 3, 31, 63, 7, 23, 143, 95, 31, 15, 15, 15, 31, 15, 49, 49, 3, 15, 63, 47, 23, 15, 71, 161, 17, 7, 63, 63, 7, 15, 63, 15, 23, 47, 15, 31, 15, 7, 47, 23, 15, 63, 63, 15, 15, 31, 47, 191, 63, 15, 47, 47, 15, 15, 47, 23, 7, 31, 31, 23, 11, 15, 255, 127, 7, 7, 15, 23, 71, 23, 11, 23, 23, 23, 63, 63, 7, 23, 119, 19, 7, 7, 31, 63, 15, 7, 35, 143, 31, 31, 63, 31, 31, 15, 15, 95, 47, 23, 47, 15, 7, 31, 95, 47, 23, 11, 15, 63, 31, 7, 55, 55, 7, 47, 47, 7, 7, 47, 71, 47, 31, 7, 47, 95, 15, 31, 95, 47, 31, 15, 7, 47, 47, 7, 23, 23, 7, 31, 63, 63, 47, 11, 39, 79, 7, 7, 31, 47, 23, 31, 95, 23, 31, 31, 7, 15, 7, 7, 95, 191, 23, 23, 63, 15, 7, 15, 47, 143, 23, 7, 31, 15, 15, 63, 95, 23, 19, 79, 63, 31, 15, 15, 95, 95, 7, 11, 23, 31, 31, 7, 15, 63, 31, 15, 95, 95, 15, 47, 71, 11, 7, 15, 31, 63, 31, 23, 119, 79, 15, 15, 31, 15, 23, 23, 11, 71, 47, 31, 63, 15, 3, 11, 143, 47, 7, 7, 7, 63, 63, 15, 95, 71, 11, 15, 31, 31, 31, 31, 63, 95, 11, 3, 31, 127, 31, 15, 23, 35, 35, 23, 31, 63, 31, 15, 63, 31, 7, 79, 79, 7, 15, 31, 47, 47, 23, 11, 23, 47, 7, 15, 79, 79, 95, 23, 15, 47, 11, 7, 95, 47, 3, 7, 63, 31, 15, 31, 31, 63, 15, 7, 31, 31, 31, 95, 71, 35, 23, 31, 31, 31, 15, 3, 71, 143, 15, 23, 47, 31, 31, 15, 17, 71, 47, 35, 47, 31, 7, 15, 63, 15, 23, 47, 47, 47, 7, 3, 35, 143, 15, 23, 47, 7, 15, 31, 79, 79, 15, 31, 111, 27, 3, 15, 95, 47, 15, 15, 31, 143, 143, 15, 31, 63, 15, 15, 15, 15, 23, 23, 23, 47, 31, 7, 47, 95, 7, 15, 111, 111, 31, 15, 31, 31, 23, 23, 71, 35, 7, 31, 31, 7, 15, 31, 63, 191, 23, 3, 31, 63, 7, 15, 95, 23, 31, 31, 7, 15, 7, 23, 239, 79, 7, 11, 47, 31, 31, 31, 23, 47, 15, 7, 47, 71, 47, 31, 63, 63, 15, 15, 31, 79, 19, 3, 47, 47, 7, 63, 63, 15, 23, 23, 47, 95, 63, 15, 15, 31, 15, 47, 143, 47, 15, 7, 15, 63, 15, 3, 63, 287, 35, 15, 15, 15, 31, 31, 23, 35, 23, 15, 63, 31, 11, 23, 79, 39, 17, 35, 15, 63, 31, 7, 47, 23, 11, 47, 63, 31, 15, 31, 63, 31, 15, 31, 191, 47, 3, 7, 23, 23, 31, 15, 15, 95, 47, 15, 79, 79, 15, 47, 47, 15, 39, 19, 47, 191, 31, 7, 15, 31, 7, 23, 95, 15, 15, 31, 15, 15, 31, 31, 71, 71, 7, 7, 47, 47, 31, 31, 39, 159, 31, 7, 63, 31, 7, 31, 47, 23, 23, 47, 63, 31, 7, 3, 63, 63, 7, 23, 47, 47, 23, 15, 47, 95, 31, 15, 63, 63, 7, 31, 287, 35, 7, 15, 31, 47, 11, 7, 47, 95, 47, 23, 15, 15, 71, 71, 31, 31, 15, 15, 31, 63, 15, 23, 143, 47, 31, 15, 15, 63, 15, 3, 59, 59, 7, 31, 63, 31, 23, 35, 35, 35, 23, 23, 95, 31, 7, 15, 31, 95, 95, 15, 7, 15, 31, 15, 47, 95, 7, 23, 95, 31, 31, 31, 83, 167 };

int getchar_unlocked()  {return getchar();}
inline void fastRead_int(int &x) {
	register int c = getchar_unlocked();
	x = 0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	for(; c>47 && c<58 ; c = getchar_unlocked()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
}

int main(){
	int t,n,i,j,k,min;
	scanf("%d",&t);
	//sort(div,div+3200);
	while(t--){
		fastRead_int(n);
		for(i=0;i<3200;i++){
			if(div[i]==n) break;
		}
		printf("%d\n",se[i]);
	}
	return 0;
}