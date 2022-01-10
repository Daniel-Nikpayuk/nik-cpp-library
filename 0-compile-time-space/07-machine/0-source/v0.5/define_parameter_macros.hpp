/************************************************************************************************************************
**
** Copyright 2021-2022 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
**
** This file is part of nik_cpp_library.
**
** nik_cpp_library is free software: you can redistribute it and/or modify it under the terms
** of the GNU General Public License as published by the Free Software Foundation, either version 3
** of the License, or (at your option) any later version.
**
** nik_cpp_library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
** without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with nik_cpp_library.
** If not, see <http://www.gnu.org/licenses/>.
**
************************************************************************************************************************/

// define parameter macros source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// preamble:

	#define NIK_0_COMMA												\
															\
		// blank space.

	#define NIK_1_COMMA												\
															\
		,

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block:

/***********************************************************************************************************************/

// upper array blocks:

	#define NIK_UPPER_1_ARRAY_BLOCK(_i_, _s_)									\
															\
		_i_[_s_+  0]

	#define NIK_UPPER_2_ARRAY_BLOCK(_i_, _s_)									\
															\
		_i_[_s_+  1]

	#define NIK_UPPER_4_ARRAY_BLOCK(_i_, _s_)									\
															\
		_i_[_s_+  2], _i_[_s_+  3]

	#define NIK_UPPER_8_ARRAY_BLOCK(_i_, _s_)									\
															\
		_i_[_s_+  4], _i_[_s_+  5], _i_[_s_+  6], _i_[_s_+  7]

	#define NIK_UPPER_16_ARRAY_BLOCK(_i_, _s_)									\
															\
		_i_[_s_+  8], _i_[_s_+  9], _i_[_s_+ 10], _i_[_s_+ 11],							\
		_i_[_s_+ 12], _i_[_s_+ 13], _i_[_s_+ 14], _i_[_s_+ 15]

	#define NIK_UPPER_32_ARRAY_BLOCK(_i_, _s_)									\
															\
		_i_[_s_+ 16], _i_[_s_+ 17], _i_[_s_+ 18], _i_[_s_+ 19],							\
		_i_[_s_+ 20], _i_[_s_+ 21], _i_[_s_+ 22], _i_[_s_+ 23],							\
		_i_[_s_+ 24], _i_[_s_+ 25], _i_[_s_+ 26], _i_[_s_+ 27],							\
		_i_[_s_+ 28], _i_[_s_+ 29], _i_[_s_+ 30], _i_[_s_+ 31]

	#define NIK_UPPER_64_ARRAY_BLOCK(_i_, _s_)									\
															\
		_i_[_s_+ 32], _i_[_s_+ 33], _i_[_s_+ 34], _i_[_s_+ 35],							\
		_i_[_s_+ 36], _i_[_s_+ 37], _i_[_s_+ 38], _i_[_s_+ 39],							\
		_i_[_s_+ 40], _i_[_s_+ 41], _i_[_s_+ 42], _i_[_s_+ 43],							\
		_i_[_s_+ 44], _i_[_s_+ 45], _i_[_s_+ 46], _i_[_s_+ 47],							\
		_i_[_s_+ 48], _i_[_s_+ 49], _i_[_s_+ 50], _i_[_s_+ 51],							\
		_i_[_s_+ 52], _i_[_s_+ 53], _i_[_s_+ 54], _i_[_s_+ 55],							\
		_i_[_s_+ 56], _i_[_s_+ 57], _i_[_s_+ 58], _i_[_s_+ 59],							\
		_i_[_s_+ 60], _i_[_s_+ 61], _i_[_s_+ 62], _i_[_s_+ 63]
                                                                    
	#define NIK_UPPER_128_ARRAY_BLOCK(_i_, _s_)									\
															\
		_i_[_s_+ 64], _i_[_s_+ 65], _i_[_s_+ 66], _i_[_s_+ 67],							\
		_i_[_s_+ 68], _i_[_s_+ 69], _i_[_s_+ 70], _i_[_s_+ 71],							\
		_i_[_s_+ 72], _i_[_s_+ 73], _i_[_s_+ 74], _i_[_s_+ 75],							\
		_i_[_s_+ 76], _i_[_s_+ 77], _i_[_s_+ 78], _i_[_s_+ 79],							\
		_i_[_s_+ 80], _i_[_s_+ 81], _i_[_s_+ 82], _i_[_s_+ 83],							\
		_i_[_s_+ 84], _i_[_s_+ 85], _i_[_s_+ 86], _i_[_s_+ 87],							\
		_i_[_s_+ 88], _i_[_s_+ 89], _i_[_s_+ 90], _i_[_s_+ 91],							\
		_i_[_s_+ 92], _i_[_s_+ 93], _i_[_s_+ 94], _i_[_s_+ 95],							\
		_i_[_s_+ 96], _i_[_s_+ 97], _i_[_s_+ 98], _i_[_s_+ 99],							\
		_i_[_s_+100], _i_[_s_+101], _i_[_s_+102], _i_[_s_+103],							\
		_i_[_s_+104], _i_[_s_+105], _i_[_s_+106], _i_[_s_+107],							\
		_i_[_s_+108], _i_[_s_+109], _i_[_s_+110], _i_[_s_+111],							\
		_i_[_s_+112], _i_[_s_+113], _i_[_s_+114], _i_[_s_+115],							\
		_i_[_s_+116], _i_[_s_+117], _i_[_s_+118], _i_[_s_+119],							\
		_i_[_s_+120], _i_[_s_+121], _i_[_s_+122], _i_[_s_+123],							\
		_i_[_s_+124], _i_[_s_+125], _i_[_s_+126], _i_[_s_+127]

	#define NIK_UPPER_256_ARRAY_BLOCK(_i_, _s_)									\
															\
		_i_[_s_+128], _i_[_s_+129], _i_[_s_+130], _i_[_s_+131],							\
		_i_[_s_+132], _i_[_s_+133], _i_[_s_+134], _i_[_s_+135],							\
		_i_[_s_+136], _i_[_s_+137], _i_[_s_+138], _i_[_s_+139],							\
		_i_[_s_+140], _i_[_s_+141], _i_[_s_+142], _i_[_s_+143],							\
		_i_[_s_+144], _i_[_s_+145], _i_[_s_+146], _i_[_s_+147],							\
		_i_[_s_+148], _i_[_s_+149], _i_[_s_+150], _i_[_s_+151],							\
		_i_[_s_+152], _i_[_s_+153], _i_[_s_+154], _i_[_s_+155],							\
		_i_[_s_+156], _i_[_s_+157], _i_[_s_+158], _i_[_s_+159],							\
		_i_[_s_+160], _i_[_s_+161], _i_[_s_+162], _i_[_s_+163],							\
		_i_[_s_+164], _i_[_s_+165], _i_[_s_+166], _i_[_s_+167],							\
		_i_[_s_+168], _i_[_s_+169], _i_[_s_+170], _i_[_s_+171],							\
		_i_[_s_+172], _i_[_s_+173], _i_[_s_+174], _i_[_s_+175],							\
		_i_[_s_+176], _i_[_s_+177], _i_[_s_+178], _i_[_s_+179],							\
		_i_[_s_+180], _i_[_s_+181], _i_[_s_+182], _i_[_s_+183],							\
		_i_[_s_+184], _i_[_s_+185], _i_[_s_+186], _i_[_s_+187],							\
		_i_[_s_+188], _i_[_s_+189], _i_[_s_+190], _i_[_s_+191],							\
															\
		_i_[_s_+192], _i_[_s_+193], _i_[_s_+194], _i_[_s_+195],							\
		_i_[_s_+196], _i_[_s_+197], _i_[_s_+198], _i_[_s_+199],							\
		_i_[_s_+200], _i_[_s_+201], _i_[_s_+202], _i_[_s_+203],							\
		_i_[_s_+204], _i_[_s_+205], _i_[_s_+206], _i_[_s_+207],							\
		_i_[_s_+208], _i_[_s_+209], _i_[_s_+210], _i_[_s_+211],							\
		_i_[_s_+212], _i_[_s_+213], _i_[_s_+214], _i_[_s_+215],							\
		_i_[_s_+216], _i_[_s_+217], _i_[_s_+218], _i_[_s_+219],							\
		_i_[_s_+220], _i_[_s_+221], _i_[_s_+222], _i_[_s_+223],							\
		_i_[_s_+224], _i_[_s_+225], _i_[_s_+226], _i_[_s_+227],							\
		_i_[_s_+228], _i_[_s_+229], _i_[_s_+230], _i_[_s_+231],							\
		_i_[_s_+232], _i_[_s_+233], _i_[_s_+234], _i_[_s_+235],							\
		_i_[_s_+236], _i_[_s_+237], _i_[_s_+238], _i_[_s_+239],							\
		_i_[_s_+240], _i_[_s_+241], _i_[_s_+242], _i_[_s_+243],							\
		_i_[_s_+244], _i_[_s_+245], _i_[_s_+246], _i_[_s_+247],							\
		_i_[_s_+248], _i_[_s_+249], _i_[_s_+250], _i_[_s_+251],							\
		_i_[_s_+252], _i_[_s_+253], _i_[_s_+254], _i_[_s_+255]

	#define NIK_UPPER_512_ARRAY_BLOCK(_i_, _s_)									\
															\
		_i_[_s_+256], _i_[_s_+257], _i_[_s_+258], _i_[_s_+259],							\
		_i_[_s_+260], _i_[_s_+261], _i_[_s_+262], _i_[_s_+263],							\
		_i_[_s_+264], _i_[_s_+265], _i_[_s_+266], _i_[_s_+267],							\
		_i_[_s_+268], _i_[_s_+269], _i_[_s_+270], _i_[_s_+271],							\
		_i_[_s_+272], _i_[_s_+273], _i_[_s_+274], _i_[_s_+275],							\
		_i_[_s_+276], _i_[_s_+277], _i_[_s_+278], _i_[_s_+279],							\
		_i_[_s_+280], _i_[_s_+281], _i_[_s_+282], _i_[_s_+283],							\
		_i_[_s_+284], _i_[_s_+285], _i_[_s_+286], _i_[_s_+287],							\
		_i_[_s_+288], _i_[_s_+289], _i_[_s_+290], _i_[_s_+291],							\
		_i_[_s_+292], _i_[_s_+293], _i_[_s_+294], _i_[_s_+295],							\
		_i_[_s_+296], _i_[_s_+297], _i_[_s_+298], _i_[_s_+299],							\
		_i_[_s_+300], _i_[_s_+301], _i_[_s_+302], _i_[_s_+303],							\
		_i_[_s_+304], _i_[_s_+305], _i_[_s_+306], _i_[_s_+307],							\
		_i_[_s_+308], _i_[_s_+309], _i_[_s_+310], _i_[_s_+311],							\
		_i_[_s_+312], _i_[_s_+313], _i_[_s_+314], _i_[_s_+315],							\
		_i_[_s_+316], _i_[_s_+317], _i_[_s_+318], _i_[_s_+319],							\
															\
		_i_[_s_+320], _i_[_s_+321], _i_[_s_+322], _i_[_s_+323],							\
		_i_[_s_+324], _i_[_s_+325], _i_[_s_+326], _i_[_s_+327],							\
		_i_[_s_+328], _i_[_s_+329], _i_[_s_+330], _i_[_s_+331],							\
		_i_[_s_+332], _i_[_s_+333], _i_[_s_+334], _i_[_s_+335],							\
		_i_[_s_+336], _i_[_s_+337], _i_[_s_+338], _i_[_s_+339],							\
		_i_[_s_+340], _i_[_s_+341], _i_[_s_+342], _i_[_s_+343],							\
		_i_[_s_+344], _i_[_s_+345], _i_[_s_+346], _i_[_s_+347],							\
		_i_[_s_+348], _i_[_s_+349], _i_[_s_+350], _i_[_s_+351],							\
		_i_[_s_+352], _i_[_s_+353], _i_[_s_+354], _i_[_s_+355],							\
		_i_[_s_+356], _i_[_s_+357], _i_[_s_+358], _i_[_s_+359],							\
		_i_[_s_+360], _i_[_s_+361], _i_[_s_+362], _i_[_s_+363],							\
		_i_[_s_+364], _i_[_s_+365], _i_[_s_+366], _i_[_s_+367],							\
		_i_[_s_+368], _i_[_s_+369], _i_[_s_+370], _i_[_s_+371],							\
		_i_[_s_+372], _i_[_s_+373], _i_[_s_+374], _i_[_s_+375],							\
		_i_[_s_+376], _i_[_s_+377], _i_[_s_+378], _i_[_s_+379],							\
		_i_[_s_+380], _i_[_s_+381], _i_[_s_+382], _i_[_s_+383],							\
															\
		_i_[_s_+384], _i_[_s_+385], _i_[_s_+386], _i_[_s_+387],							\
		_i_[_s_+388], _i_[_s_+389], _i_[_s_+390], _i_[_s_+391],							\
		_i_[_s_+392], _i_[_s_+393], _i_[_s_+394], _i_[_s_+395],							\
		_i_[_s_+396], _i_[_s_+397], _i_[_s_+398], _i_[_s_+399],							\
		_i_[_s_+400], _i_[_s_+401], _i_[_s_+402], _i_[_s_+403],							\
		_i_[_s_+404], _i_[_s_+405], _i_[_s_+406], _i_[_s_+407],							\
		_i_[_s_+408], _i_[_s_+409], _i_[_s_+410], _i_[_s_+411],							\
		_i_[_s_+412], _i_[_s_+413], _i_[_s_+414], _i_[_s_+415],							\
		_i_[_s_+416], _i_[_s_+417], _i_[_s_+418], _i_[_s_+419],							\
		_i_[_s_+420], _i_[_s_+421], _i_[_s_+422], _i_[_s_+423],							\
		_i_[_s_+424], _i_[_s_+425], _i_[_s_+426], _i_[_s_+427],							\
		_i_[_s_+428], _i_[_s_+429], _i_[_s_+430], _i_[_s_+431],							\
		_i_[_s_+432], _i_[_s_+433], _i_[_s_+434], _i_[_s_+435],							\
		_i_[_s_+436], _i_[_s_+437], _i_[_s_+438], _i_[_s_+439],							\
		_i_[_s_+440], _i_[_s_+441], _i_[_s_+442], _i_[_s_+443],							\
		_i_[_s_+444], _i_[_s_+445], _i_[_s_+446], _i_[_s_+447],							\
															\
		_i_[_s_+448], _i_[_s_+449], _i_[_s_+450], _i_[_s_+451],							\
		_i_[_s_+452], _i_[_s_+453], _i_[_s_+454], _i_[_s_+455],							\
		_i_[_s_+456], _i_[_s_+457], _i_[_s_+458], _i_[_s_+459],							\
		_i_[_s_+460], _i_[_s_+461], _i_[_s_+462], _i_[_s_+463],							\
		_i_[_s_+464], _i_[_s_+465], _i_[_s_+466], _i_[_s_+467],							\
		_i_[_s_+468], _i_[_s_+469], _i_[_s_+470], _i_[_s_+471],							\
		_i_[_s_+472], _i_[_s_+473], _i_[_s_+474], _i_[_s_+475],							\
		_i_[_s_+476], _i_[_s_+477], _i_[_s_+478], _i_[_s_+479],							\
		_i_[_s_+480], _i_[_s_+481], _i_[_s_+482], _i_[_s_+483],							\
		_i_[_s_+484], _i_[_s_+485], _i_[_s_+486], _i_[_s_+487],							\
		_i_[_s_+488], _i_[_s_+489], _i_[_s_+490], _i_[_s_+491],							\
		_i_[_s_+492], _i_[_s_+493], _i_[_s_+494], _i_[_s_+495],							\
		_i_[_s_+496], _i_[_s_+497], _i_[_s_+498], _i_[_s_+499],							\
		_i_[_s_+500], _i_[_s_+501], _i_[_s_+502], _i_[_s_+503],							\
		_i_[_s_+504], _i_[_s_+505], _i_[_s_+506], _i_[_s_+507],							\
		_i_[_s_+508], _i_[_s_+509], _i_[_s_+510], _i_[_s_+511]

/***********************************************************************************************************************/

// upper auto:

	#define NIK_UPPER_1_AUTO_VS											\
															\
		auto   V0

	#define NIK_UPPER_2_AUTO_VS											\
															\
		auto   V1

	#define NIK_UPPER_4_AUTO_VS											\
															\
		auto   V2, auto   V3

	#define NIK_UPPER_8_AUTO_VS											\
															\
		auto   V4, auto   V5, auto   V6, auto   V7

	#define NIK_UPPER_16_AUTO_VS											\
															\
		auto   V8, auto   V9, auto  V10, auto  V11, auto  V12, auto  V13, auto  V14, auto  V15

	#define NIK_UPPER_32_AUTO_VS											\
															\
		auto  V16, auto  V17, auto  V18, auto  V19, auto  V20, auto  V21, auto  V22, auto  V23,			\
		auto  V24, auto  V25, auto  V26, auto  V27, auto  V28, auto  V29, auto  V30, auto  V31

	#define NIK_UPPER_64_AUTO_VS											\
															\
		auto  V32, auto  V33, auto  V34, auto  V35, auto  V36, auto  V37, auto  V38, auto  V39,			\
		auto  V40, auto  V41, auto  V42, auto  V43, auto  V44, auto  V45, auto  V46, auto  V47,			\
		auto  V48, auto  V49, auto  V50, auto  V51, auto  V52, auto  V53, auto  V54, auto  V55,			\
		auto  V56, auto  V57, auto  V58, auto  V59, auto  V60, auto  V61, auto  V62, auto  V63

	#define NIK_UPPER_128_AUTO_VS											\
															\
		auto  V64, auto  V65, auto  V66, auto  V67, auto  V68, auto  V69, auto  V70, auto  V71,			\
		auto  V72, auto  V73, auto  V74, auto  V75, auto  V76, auto  V77, auto  V78, auto  V79,			\
		auto  V80, auto  V81, auto  V82, auto  V83, auto  V84, auto  V85, auto  V86, auto  V87,			\
		auto  V88, auto  V89, auto  V90, auto  V91, auto  V92, auto  V93, auto  V94, auto  V95,			\
		auto  V96, auto  V97, auto  V98, auto  V99, auto V100, auto V101, auto V102, auto V103,			\
		auto V104, auto V105, auto V106, auto V107, auto V108, auto V109, auto V110, auto V111,			\
		auto V112, auto V113, auto V114, auto V115, auto V116, auto V117, auto V118, auto V119,			\
		auto V120, auto V121, auto V122, auto V123, auto V124, auto V125, auto V126, auto V127

	#define NIK_UPPER_256_AUTO_VS											\
															\
		auto V128, auto V129, auto V130, auto V131, auto V132, auto V133, auto V134, auto V135,			\
		auto V136, auto V137, auto V138, auto V139, auto V140, auto V141, auto V142, auto V143,			\
		auto V144, auto V145, auto V146, auto V147, auto V148, auto V149, auto V150, auto V151,			\
		auto V152, auto V153, auto V154, auto V155, auto V156, auto V157, auto V158, auto V159,			\
		auto V160, auto V161, auto V162, auto V163, auto V164, auto V165, auto V166, auto V167,			\
		auto V168, auto V169, auto V170, auto V171, auto V172, auto V173, auto V174, auto V175,			\
		auto V176, auto V177, auto V178, auto V179, auto V180, auto V181, auto V182, auto V183,			\
		auto V184, auto V185, auto V186, auto V187, auto V188, auto V189, auto V190, auto V191,			\
															\
		auto V192, auto V193, auto V194, auto V195, auto V196, auto V197, auto V198, auto V199,			\
		auto V200, auto V201, auto V202, auto V203, auto V204, auto V205, auto V206, auto V207,			\
		auto V208, auto V209, auto V210, auto V211, auto V212, auto V213, auto V214, auto V215,			\
		auto V216, auto V217, auto V218, auto V219, auto V220, auto V221, auto V222, auto V223,			\
		auto V224, auto V225, auto V226, auto V227, auto V228, auto V229, auto V230, auto V231,			\
		auto V232, auto V233, auto V234, auto V235, auto V236, auto V237, auto V238, auto V239,			\
		auto V240, auto V241, auto V242, auto V243, auto V244, auto V245, auto V246, auto V247,			\
		auto V248, auto V249, auto V250, auto V251, auto V252, auto V253, auto V254, auto V255

	#define NIK_UPPER_512_AUTO_VS											\
															\
		auto V256, auto V257, auto V258, auto V259, auto V260, auto V261, auto V262, auto V263,			\
		auto V264, auto V265, auto V266, auto V267, auto V268, auto V269, auto V270, auto V271,			\
		auto V272, auto V273, auto V274, auto V275, auto V276, auto V277, auto V278, auto V279,			\
		auto V280, auto V281, auto V282, auto V283, auto V284, auto V285, auto V286, auto V287,			\
		auto V288, auto V289, auto V290, auto V291, auto V292, auto V293, auto V294, auto V295,			\
		auto V296, auto V297, auto V298, auto V299, auto V300, auto V301, auto V302, auto V303,			\
		auto V304, auto V305, auto V306, auto V307, auto V308, auto V309, auto V310, auto V311,			\
		auto V312, auto V313, auto V314, auto V315, auto V316, auto V317, auto V318, auto V319,			\
															\
		auto V320, auto V321, auto V322, auto V323, auto V324, auto V325, auto V326, auto V327,			\
		auto V328, auto V329, auto V330, auto V331, auto V332, auto V333, auto V334, auto V335,			\
		auto V336, auto V337, auto V338, auto V339, auto V340, auto V341, auto V342, auto V343,			\
		auto V344, auto V345, auto V346, auto V347, auto V348, auto V349, auto V350, auto V351,			\
		auto V352, auto V353, auto V354, auto V355, auto V356, auto V357, auto V358, auto V359,			\
		auto V360, auto V361, auto V362, auto V363, auto V364, auto V365, auto V366, auto V367,			\
		auto V368, auto V369, auto V370, auto V371, auto V372, auto V373, auto V374, auto V375,			\
		auto V376, auto V377, auto V378, auto V379, auto V380, auto V381, auto V382, auto V383,			\
															\
		auto V384, auto V385, auto V386, auto V387, auto V388, auto V389, auto V390, auto V391,			\
		auto V392, auto V393, auto V394, auto V395, auto V396, auto V397, auto V398, auto V399,			\
		auto V400, auto V401, auto V402, auto V403, auto V404, auto V405, auto V406, auto V407,			\
		auto V408, auto V409, auto V410, auto V411, auto V412, auto V413, auto V414, auto V415,			\
		auto V416, auto V417, auto V418, auto V419, auto V420, auto V421, auto V422, auto V423,			\
		auto V424, auto V425, auto V426, auto V427, auto V428, auto V429, auto V430, auto V431,			\
		auto V432, auto V433, auto V434, auto V435, auto V436, auto V437, auto V438, auto V439,			\
		auto V440, auto V441, auto V442, auto V443, auto V444, auto V445, auto V446, auto V447,			\
															\
		auto V448, auto V449, auto V450, auto V451, auto V452, auto V453, auto V454, auto V455,			\
		auto V456, auto V457, auto V458, auto V459, auto V460, auto V461, auto V462, auto V463,			\
		auto V464, auto V465, auto V466, auto V467, auto V468, auto V469, auto V470, auto V471,			\
		auto V472, auto V473, auto V474, auto V475, auto V476, auto V477, auto V478, auto V479,			\
		auto V480, auto V481, auto V482, auto V483, auto V484, auto V485, auto V486, auto V487,			\
		auto V488, auto V489, auto V490, auto V491, auto V492, auto V493, auto V494, auto V495,			\
		auto V496, auto V497, auto V498, auto V499, auto V500, auto V501, auto V502, auto V503,			\
		auto V504, auto V505, auto V506, auto V507, auto V508, auto V509, auto V510, auto V511

/***********************************************************************************************************************/

// upper values:

	#define NIK_UPPER_1_VS												\
															\
		  V0

	#define NIK_UPPER_2_VS												\
															\
		  V1

	#define NIK_UPPER_4_VS												\
															\
		  V2,   V3

	#define NIK_UPPER_8_VS												\
															\
		  V4,   V5,   V6,   V7

	#define NIK_UPPER_16_VS												\
															\
		  V8,   V9,  V10,  V11,  V12,  V13,  V14,  V15

	#define NIK_UPPER_32_VS												\
															\
		 V16,  V17,  V18,  V19,  V20,  V21,  V22,  V23,  V24,  V25,  V26,  V27,  V28,  V29,  V30,  V31

	#define NIK_UPPER_64_VS												\
															\
		 V32,  V33,  V34,  V35,  V36,  V37,  V38,  V39,  V40,  V41,  V42,  V43,  V44,  V45,  V46,  V47,		\
		 V48,  V49,  V50,  V51,  V52,  V53,  V54,  V55,  V56,  V57,  V58,  V59,  V60,  V61,  V62,  V63

	#define NIK_UPPER_128_VS											\
															\
		 V64,  V65,  V66,  V67,  V68,  V69,  V70,  V71,  V72,  V73,  V74,  V75,  V76,  V77,  V78,  V79,		\
		 V80,  V81,  V82,  V83,  V84,  V85,  V86,  V87,  V88,  V89,  V90,  V91,  V92,  V93,  V94,  V95,		\
		 V96,  V97,  V98,  V99, V100, V101, V102, V103, V104, V105, V106, V107, V108, V109, V110, V111,		\
		V112, V113, V114, V115, V116, V117, V118, V119, V120, V121, V122, V123, V124, V125, V126, V127

	#define NIK_UPPER_256_VS											\
															\
		V128, V129, V130, V131, V132, V133, V134, V135, V136, V137, V138, V139, V140, V141, V142, V143,		\
		V144, V145, V146, V147, V148, V149, V150, V151, V152, V153, V154, V155, V156, V157, V158, V159,		\
		V160, V161, V162, V163, V164, V165, V166, V167, V168, V169, V170, V171, V172, V173, V174, V175,		\
		V176, V177, V178, V179, V180, V181, V182, V183, V184, V185, V186, V187, V188, V189, V190, V191,		\
															\
		V192, V193, V194, V195, V196, V197, V198, V199, V200, V201, V202, V203, V204, V205, V206, V207,		\
		V208, V209, V210, V211, V212, V213, V214, V215, V216, V217, V218, V219, V220, V221, V222, V223,		\
		V224, V225, V226, V227, V228, V229, V230, V231, V232, V233, V234, V235, V236, V237, V238, V239,		\
		V240, V241, V242, V243, V244, V245, V246, V247, V248, V249, V250, V251, V252, V253, V254, V255

	#define NIK_UPPER_512_VS											\
															\
		V256, V257, V258, V259, V260, V261, V262, V263, V264, V265, V266, V267, V268, V269, V270, V271,		\
		V272, V273, V274, V275, V276, V277, V278, V279, V280, V281, V282, V283, V284, V285, V286, V287,		\
		V288, V289, V290, V291, V292, V293, V294, V295, V296, V297, V298, V299, V300, V301, V302, V303,		\
		V304, V305, V306, V307, V308, V309, V310, V311, V312, V313, V314, V315, V316, V317, V318, V319,		\
															\
		V320, V321, V322, V323, V324, V325, V326, V327, V328, V329, V330, V331, V332, V333, V334, V335,		\
		V336, V337, V338, V339, V340, V341, V342, V343, V344, V345, V346, V347, V348, V349, V350, V351,		\
		V352, V353, V354, V355, V356, V357, V358, V359, V360, V361, V362, V363, V364, V365, V366, V367,		\
		V368, V369, V370, V371, V372, V373, V374, V375, V376, V377, V378, V379, V380, V381, V382, V383,		\
															\
		V384, V385, V386, V387, V388, V389, V390, V391, V392, V393, V394, V395, V396, V397, V398, V399,		\
		V400, V401, V402, V403, V404, V405, V406, V407, V408, V409, V410, V411, V412, V413, V414, V415,		\
		V416, V417, V418, V419, V420, V421, V422, V423, V424, V425, V426, V427, V428, V429, V430, V431,		\
		V432, V433, V434, V435, V436, V437, V438, V439, V440, V441, V442, V443, V444, V445, V446, V447,		\
															\
		V448, V449, V450, V451, V452, V453, V454, V455, V456, V457, V458, V459, V460, V461, V462, V463,		\
		V464, V465, V466, V467, V468, V469, V470, V471, V472, V473, V474, V475, V476, V477, V478, V479,		\
		V480, V481, V482, V483, V484, V485, V486, V487, V488, V489, V490, V491, V492, V493, V494, V495,		\
		V496, V497, V498, V499, V500, V501, V502, V503, V504, V505, V506, V507, V508, V509, V510, V511

/***********************************************************************************************************************/

// upper operation values:

	#define NIK_UPPER_1_OP_VS											\
															\
		  V0)

	#define NIK_UPPER_2_OP_VS											\
															\
		  V1)

	#define NIK_UPPER_4_OP_VS											\
															\
		  V2),   V3)

	#define NIK_UPPER_8_OP_VS											\
															\
		  V4),   V5),   V6),   V7)

	#define NIK_UPPER_16_OP_VS											\
															\
		  V8),   V9),  V10),  V11),  V12),  V13),  V14),  V15)

	#define NIK_UPPER_32_OP_VS											\
															\
		 V16),  V17),  V18),  V19),  V20),  V21),  V22),  V23),							\
		 V24),  V25),  V26),  V27),  V28),  V29),  V30),  V31)

	#define NIK_UPPER_64_OP_VS											\
															\
		 V32),  V33),  V34),  V35),  V36),  V37),  V38),  V39),							\
		 V40),  V41),  V42),  V43),  V44),  V45),  V46),  V47),							\
		 V48),  V49),  V50),  V51),  V52),  V53),  V54),  V55),							\
		 V56),  V57),  V58),  V59),  V60),  V61),  V62),  V63)

	#define NIK_UPPER_128_OP_VS											\
															\
		 V64),  V65),  V66),  V67),  V68),  V69),  V70),  V71),							\
		 V72),  V73),  V74),  V75),  V76),  V77),  V78),  V79),							\
		 V80),  V81),  V82),  V83),  V84),  V85),  V86),  V87),							\
		 V88),  V89),  V90),  V91),  V92),  V93),  V94),  V95),							\
		 V96),  V97),  V98),  V99), V100), V101), V102), V103),							\
		V104), V105), V106), V107), V108), V109), V110), V111),							\
		V112), V113), V114), V115), V116), V117), V118), V119),							\
		V120), V121), V122), V123), V124), V125), V126), V127)

	#define NIK_UPPER_256_OP_VS											\
															\
		V128), V129), V130), V131), V132), V133), V134), V135),							\
		V136), V137), V138), V139), V140), V141), V142), V143),							\
		V144), V145), V146), V147), V148), V149), V150), V151),							\
		V152), V153), V154), V155), V156), V157), V158), V159),							\
		V160), V161), V162), V163), V164), V165), V166), V167),							\
		V168), V169), V170), V171), V172), V173), V174), V175),							\
		V176), V177), V178), V179), V180), V181), V182), V183),							\
		V184), V185), V186), V187), V188), V189), V190), V191),							\
															\
		V192), V193), V194), V195), V196), V197), V198), V199),							\
		V200), V201), V202), V203), V204), V205), V206), V207),							\
		V208), V209), V210), V211), V212), V213), V214), V215),							\
		V216), V217), V218), V219), V220), V221), V222), V223),							\
		V224), V225), V226), V227), V228), V229), V230), V231),							\
		V232), V233), V234), V235), V236), V237), V238), V239),							\
		V240), V241), V242), V243), V244), V245), V246), V247),							\
		V248), V249), V250), V251), V252), V253), V254), V255)

	#define NIK_UPPER_512_OP_VS											\
															\
		V256), V257), V258), V259), V260), V261), V262), V263),							\
		V264), V265), V266), V267), V268), V269), V270), V271),							\
		V272), V273), V274), V275), V276), V277), V278), V279),							\
		V280), V281), V282), V283), V284), V285), V286), V287),							\
		V288), V289), V290), V291), V292), V293), V294), V295),							\
		V296), V297), V298), V299), V300), V301), V302), V303),							\
		V304), V305), V306), V307), V308), V309), V310), V311),							\
		V312), V313), V314), V315), V316), V317), V318), V319),							\
															\
		V320), V321), V322), V323), V324), V325), V326), V327),							\
		V328), V329), V330), V331), V332), V333), V334), V335),							\
		V336), V337), V338), V339), V340), V341), V342), V343),							\
		V344), V345), V346), V347), V348), V349), V350), V351),							\
		V352), V353), V354), V355), V356), V357), V358), V359),							\
		V360), V361), V362), V363), V364), V365), V366), V367),							\
		V368), V369), V370), V371), V372), V373), V374), V375),							\
		V376), V377), V378), V379), V380), V381), V382), V383),							\
															\
		V384), V385), V386), V387), V388), V389), V390), V391),							\
		V392), V393), V394), V395), V396), V397), V398), V399),							\
		V400), V401), V402), V403), V404), V405), V406), V407),							\
		V408), V409), V410), V411), V412), V413), V414), V415),							\
		V416), V417), V418), V419), V420), V421), V422), V423),							\
		V424), V425), V426), V427), V428), V429), V430), V431),							\
		V432), V433), V434), V435), V436), V437), V438), V439),							\
		V440), V441), V442), V443), V444), V445), V446), V447),							\
															\
		V448), V449), V450), V451), V452), V453), V454), V455),							\
		V456), V457), V458), V459), V460), V461), V462), V463),							\
		V464), V465), V466), V467), V468), V469), V470), V471),							\
		V472), V473), V474), V475), V476), V477), V478), V479),							\
		V480), V481), V482), V483), V484), V485), V486), V487),							\
		V488), V489), V490), V491), V492), V493), V494), V495),							\
		V496), V497), V498), V499), V500), V501), V502), V503),							\
		V504), V505), V506), V507), V508), V509), V510), V511)

/***********************************************************************************************************************/

// upper action values:

	#define NIK_UPPER_1_ACT_VS											\
															\
		  V0>

	#define NIK_UPPER_2_ACT_VS											\
															\
		  V1>

	#define NIK_UPPER_4_ACT_VS											\
															\
		  V2>,   V3>

	#define NIK_UPPER_8_ACT_VS											\
															\
		  V4>,   V5>,   V6>,   V7>

	#define NIK_UPPER_16_ACT_VS											\
															\
		  V8>,   V9>,  V10>,  V11>,  V12>,  V13>,  V14>,  V15>

	#define NIK_UPPER_32_ACT_VS											\
															\
		 V16>,  V17>,  V18>,  V19>,  V20>,  V21>,  V22>,  V23>,							\
		 V24>,  V25>,  V26>,  V27>,  V28>,  V29>,  V30>,  V31>

	#define NIK_UPPER_64_ACT_VS											\
															\
		 V32>,  V33>,  V34>,  V35>,  V36>,  V37>,  V38>,  V39>,							\
		 V40>,  V41>,  V42>,  V43>,  V44>,  V45>,  V46>,  V47>,							\
		 V48>,  V49>,  V50>,  V51>,  V52>,  V53>,  V54>,  V55>,							\
		 V56>,  V57>,  V58>,  V59>,  V60>,  V61>,  V62>,  V63>

	#define NIK_UPPER_128_ACT_VS											\
															\
		 V64>,  V65>,  V66>,  V67>,  V68>,  V69>,  V70>,  V71>,							\
		 V72>,  V73>,  V74>,  V75>,  V76>,  V77>,  V78>,  V79>,							\
		 V80>,  V81>,  V82>,  V83>,  V84>,  V85>,  V86>,  V87>,							\
		 V88>,  V89>,  V90>,  V91>,  V92>,  V93>,  V94>,  V95>,							\
		 V96>,  V97>,  V98>,  V99>, V100>, V101>, V102>, V103>,							\
		V104>, V105>, V106>, V107>, V108>, V109>, V110>, V111>,							\
		V112>, V113>, V114>, V115>, V116>, V117>, V118>, V119>,							\
		V120>, V121>, V122>, V123>, V124>, V125>, V126>, V127>

	#define NIK_UPPER_256_ACT_VS											\
															\
		V128>, V129>, V130>, V131>, V132>, V133>, V134>, V135>,							\
		V136>, V137>, V138>, V139>, V140>, V141>, V142>, V143>,							\
		V144>, V145>, V146>, V147>, V148>, V149>, V150>, V151>,							\
		V152>, V153>, V154>, V155>, V156>, V157>, V158>, V159>,							\
		V160>, V161>, V162>, V163>, V164>, V165>, V166>, V167>,							\
		V168>, V169>, V170>, V171>, V172>, V173>, V174>, V175>,							\
		V176>, V177>, V178>, V179>, V180>, V181>, V182>, V183>,							\
		V184>, V185>, V186>, V187>, V188>, V189>, V190>, V191>,							\
															\
		V192>, V193>, V194>, V195>, V196>, V197>, V198>, V199>,							\
		V200>, V201>, V202>, V203>, V204>, V205>, V206>, V207>,							\
		V208>, V209>, V210>, V211>, V212>, V213>, V214>, V215>,							\
		V216>, V217>, V218>, V219>, V220>, V221>, V222>, V223>,							\
		V224>, V225>, V226>, V227>, V228>, V229>, V230>, V231>,							\
		V232>, V233>, V234>, V235>, V236>, V237>, V238>, V239>,							\
		V240>, V241>, V242>, V243>, V244>, V245>, V246>, V247>,							\
		V248>, V249>, V250>, V251>, V252>, V253>, V254>, V255>

	#define NIK_UPPER_512_ACT_VS											\
															\
		V256>, V257>, V258>, V259>, V260>, V261>, V262>, V263>,							\
		V264>, V265>, V266>, V267>, V268>, V269>, V270>, V271>,							\
		V272>, V273>, V274>, V275>, V276>, V277>, V278>, V279>,							\
		V280>, V281>, V282>, V283>, V284>, V285>, V286>, V287>,							\
		V288>, V289>, V290>, V291>, V292>, V293>, V294>, V295>,							\
		V296>, V297>, V298>, V299>, V300>, V301>, V302>, V303>,							\
		V304>, V305>, V306>, V307>, V308>, V309>, V310>, V311>,							\
		V312>, V313>, V314>, V315>, V316>, V317>, V318>, V319>,							\
															\
		V320>, V321>, V322>, V323>, V324>, V325>, V326>, V327>,							\
		V328>, V329>, V330>, V331>, V332>, V333>, V334>, V335>,							\
		V336>, V337>, V338>, V339>, V340>, V341>, V342>, V343>,							\
		V344>, V345>, V346>, V347>, V348>, V349>, V350>, V351>,							\
		V352>, V353>, V354>, V355>, V356>, V357>, V358>, V359>,							\
		V360>, V361>, V362>, V363>, V364>, V365>, V366>, V367>,							\
		V368>, V369>, V370>, V371>, V372>, V373>, V374>, V375>,							\
		V376>, V377>, V378>, V379>, V380>, V381>, V382>, V383>,							\
															\
		V384>, V385>, V386>, V387>, V388>, V389>, V390>, V391>,							\
		V392>, V393>, V394>, V395>, V396>, V397>, V398>, V399>,							\
		V400>, V401>, V402>, V403>, V404>, V405>, V406>, V407>,							\
		V408>, V409>, V410>, V411>, V412>, V413>, V414>, V415>,							\
		V416>, V417>, V418>, V419>, V420>, V421>, V422>, V423>,							\
		V424>, V425>, V426>, V427>, V428>, V429>, V430>, V431>,							\
		V432>, V433>, V434>, V435>, V436>, V437>, V438>, V439>,							\
		V440>, V441>, V442>, V443>, V444>, V445>, V446>, V447>,							\
															\
		V448>, V449>, V450>, V451>, V452>, V453>, V454>, V455>,							\
		V456>, V457>, V458>, V459>, V460>, V461>, V462>, V463>,							\
		V464>, V465>, V466>, V467>, V468>, V469>, V470>, V471>,							\
		V472>, V473>, V474>, V475>, V476>, V477>, V478>, V479>,							\
		V480>, V481>, V482>, V483>, V484>, V485>, V486>, V487>,							\
		V488>, V489>, V490>, V491>, V492>, V493>, V494>, V495>,							\
		V496>, V497>, V498>, V499>, V500>, V501>, V502>, V503>,							\
		V504>, V505>, V506>, V507>, V508>, V509>, V510>, V511>

/***********************************************************************************************************************/

// array blocks:

	#define NIK_2_0_ARRAY_BLOCK(_i_, _s_)										\
															\
		NIK_UPPER_1_ARRAY_BLOCK(_i_, _s_)

	#define NIK_2_1_ARRAY_BLOCK(_i_, _s_)										\
															\
		NIK_UPPER_1_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_2_ARRAY_BLOCK(_i_, _s_)

	#define NIK_2_2_ARRAY_BLOCK(_i_, _s_)										\
															\
		NIK_UPPER_1_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_2_ARRAY_BLOCK(_i_, _s_),					\
		NIK_UPPER_4_ARRAY_BLOCK(_i_, _s_)

	#define NIK_2_3_ARRAY_BLOCK(_i_, _s_)										\
															\
		NIK_UPPER_1_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_2_ARRAY_BLOCK(_i_, _s_),					\
		NIK_UPPER_4_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_8_ARRAY_BLOCK(_i_, _s_)

	#define NIK_2_4_ARRAY_BLOCK(_i_, _s_)										\
															\
		NIK_UPPER_1_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_2_ARRAY_BLOCK(_i_, _s_),					\
		NIK_UPPER_4_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_8_ARRAY_BLOCK(_i_, _s_),					\
		NIK_UPPER_16_ARRAY_BLOCK(_i_, _s_)

	#define NIK_2_5_ARRAY_BLOCK(_i_, _s_)										\
															\
		NIK_UPPER_1_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_2_ARRAY_BLOCK(_i_, _s_),					\
		NIK_UPPER_4_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_8_ARRAY_BLOCK(_i_, _s_),					\
		NIK_UPPER_16_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_32_ARRAY_BLOCK(_i_, _s_)

	#define NIK_2_6_ARRAY_BLOCK(_i_, _s_)										\
															\
		NIK_UPPER_1_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_2_ARRAY_BLOCK(_i_, _s_),					\
		NIK_UPPER_4_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_8_ARRAY_BLOCK(_i_, _s_),					\
		NIK_UPPER_16_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_32_ARRAY_BLOCK(_i_, _s_),					\
		NIK_UPPER_64_ARRAY_BLOCK(_i_, _s_)

	#define NIK_2_7_ARRAY_BLOCK(_i_, _s_)										\
															\
		NIK_UPPER_1_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_2_ARRAY_BLOCK(_i_, _s_),					\
		NIK_UPPER_4_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_8_ARRAY_BLOCK(_i_, _s_),					\
		NIK_UPPER_16_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_32_ARRAY_BLOCK(_i_, _s_),					\
		NIK_UPPER_64_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_128_ARRAY_BLOCK(_i_, _s_)

	#define NIK_2_8_ARRAY_BLOCK(_i_, _s_)										\
															\
		NIK_UPPER_1_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_2_ARRAY_BLOCK(_i_, _s_),					\
		NIK_UPPER_4_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_8_ARRAY_BLOCK(_i_, _s_),					\
		NIK_UPPER_16_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_32_ARRAY_BLOCK(_i_, _s_),					\
		NIK_UPPER_64_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_128_ARRAY_BLOCK(_i_, _s_),				\
		NIK_UPPER_256_ARRAY_BLOCK(_i_, _s_)

	#define NIK_2_9_ARRAY_BLOCK(_i_, _s_)										\
															\
		NIK_UPPER_1_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_2_ARRAY_BLOCK(_i_, _s_),					\
		NIK_UPPER_4_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_8_ARRAY_BLOCK(_i_, _s_),					\
		NIK_UPPER_16_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_32_ARRAY_BLOCK(_i_, _s_),					\
		NIK_UPPER_64_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_128_ARRAY_BLOCK(_i_, _s_),				\
		NIK_UPPER_256_ARRAY_BLOCK(_i_, _s_), NIK_UPPER_512_ARRAY_BLOCK(_i_, _s_)

/***********************************************************************************************************************/

// block auto:

	#define NIK_2_0_AUTO_VS												\
															\
		NIK_UPPER_1_AUTO_VS

	#define NIK_2_1_AUTO_VS												\
															\
		NIK_UPPER_1_AUTO_VS, NIK_UPPER_2_AUTO_VS

	#define NIK_2_2_AUTO_VS												\
															\
		NIK_UPPER_1_AUTO_VS, NIK_UPPER_2_AUTO_VS, NIK_UPPER_4_AUTO_VS

	#define NIK_2_3_AUTO_VS												\
															\
		NIK_UPPER_1_AUTO_VS, NIK_UPPER_2_AUTO_VS, NIK_UPPER_4_AUTO_VS, NIK_UPPER_8_AUTO_VS

	#define NIK_2_4_AUTO_VS												\
															\
		NIK_UPPER_1_AUTO_VS, NIK_UPPER_2_AUTO_VS, NIK_UPPER_4_AUTO_VS, NIK_UPPER_8_AUTO_VS,			\
		NIK_UPPER_16_AUTO_VS

	#define NIK_2_5_AUTO_VS												\
															\
		NIK_UPPER_1_AUTO_VS, NIK_UPPER_2_AUTO_VS, NIK_UPPER_4_AUTO_VS, NIK_UPPER_8_AUTO_VS,			\
		NIK_UPPER_16_AUTO_VS, NIK_UPPER_32_AUTO_VS

	#define NIK_2_6_AUTO_VS												\
															\
		NIK_UPPER_1_AUTO_VS, NIK_UPPER_2_AUTO_VS, NIK_UPPER_4_AUTO_VS, NIK_UPPER_8_AUTO_VS,			\
		NIK_UPPER_16_AUTO_VS, NIK_UPPER_32_AUTO_VS, NIK_UPPER_64_AUTO_VS

	#define NIK_2_7_AUTO_VS												\
															\
		NIK_UPPER_1_AUTO_VS, NIK_UPPER_2_AUTO_VS, NIK_UPPER_4_AUTO_VS, NIK_UPPER_8_AUTO_VS,			\
		NIK_UPPER_16_AUTO_VS, NIK_UPPER_32_AUTO_VS, NIK_UPPER_64_AUTO_VS, NIK_UPPER_128_AUTO_VS

	#define NIK_2_8_AUTO_VS												\
															\
		NIK_UPPER_1_AUTO_VS, NIK_UPPER_2_AUTO_VS, NIK_UPPER_4_AUTO_VS, NIK_UPPER_8_AUTO_VS,			\
		NIK_UPPER_16_AUTO_VS, NIK_UPPER_32_AUTO_VS, NIK_UPPER_64_AUTO_VS, NIK_UPPER_128_AUTO_VS,		\
		NIK_UPPER_256_AUTO_VS

	#define NIK_2_9_AUTO_VS												\
															\
		NIK_UPPER_1_AUTO_VS, NIK_UPPER_2_AUTO_VS, NIK_UPPER_4_AUTO_VS, NIK_UPPER_8_AUTO_VS,			\
		NIK_UPPER_16_AUTO_VS, NIK_UPPER_32_AUTO_VS, NIK_UPPER_64_AUTO_VS, NIK_UPPER_128_AUTO_VS,		\
		NIK_UPPER_256_AUTO_VS, NIK_UPPER_512_AUTO_VS

/***********************************************************************************************************************/

// block values:

	#define NIK_2_0_VS												\
															\
		NIK_UPPER_1_VS

	#define NIK_2_1_VS												\
															\
		NIK_UPPER_1_VS, NIK_UPPER_2_VS

	#define NIK_2_2_VS												\
															\
		NIK_UPPER_1_VS, NIK_UPPER_2_VS, NIK_UPPER_4_VS

	#define NIK_2_3_VS												\
															\
		NIK_UPPER_1_VS, NIK_UPPER_2_VS, NIK_UPPER_4_VS, NIK_UPPER_8_VS

	#define NIK_2_4_VS												\
															\
		NIK_UPPER_1_VS, NIK_UPPER_2_VS, NIK_UPPER_4_VS, NIK_UPPER_8_VS,						\
		NIK_UPPER_16_VS

	#define NIK_2_5_VS												\
															\
		NIK_UPPER_1_VS, NIK_UPPER_2_VS, NIK_UPPER_4_VS, NIK_UPPER_8_VS,						\
		NIK_UPPER_16_VS, NIK_UPPER_32_VS

	#define NIK_2_6_VS												\
															\
		NIK_UPPER_1_VS, NIK_UPPER_2_VS, NIK_UPPER_4_VS, NIK_UPPER_8_VS,						\
		NIK_UPPER_16_VS, NIK_UPPER_32_VS, NIK_UPPER_64_VS

	#define NIK_2_7_VS												\
															\
		NIK_UPPER_1_VS, NIK_UPPER_2_VS, NIK_UPPER_4_VS, NIK_UPPER_8_VS,						\
		NIK_UPPER_16_VS, NIK_UPPER_32_VS, NIK_UPPER_64_VS, NIK_UPPER_128_VS

	#define NIK_2_8_VS												\
															\
		NIK_UPPER_1_VS, NIK_UPPER_2_VS, NIK_UPPER_4_VS, NIK_UPPER_8_VS,						\
		NIK_UPPER_16_VS, NIK_UPPER_32_VS, NIK_UPPER_64_VS, NIK_UPPER_128_VS,					\
		NIK_UPPER_256_VS

	#define NIK_2_9_VS												\
															\
		NIK_UPPER_1_VS, NIK_UPPER_2_VS, NIK_UPPER_4_VS, NIK_UPPER_8_VS,						\
		NIK_UPPER_16_VS, NIK_UPPER_32_VS, NIK_UPPER_64_VS, NIK_UPPER_128_VS,					\
		NIK_UPPER_256_VS, NIK_UPPER_512_VS

/***********************************************************************************************************************/

// block operations:

	#define NIK_2_0_OPS												\
															\
		op(

	#define NIK_2_1_OPS												\
															\
		NIK_2_0_OPS NIK_2_0_OPS

	#define NIK_2_2_OPS												\
															\
		NIK_2_1_OPS NIK_2_1_OPS

	#define NIK_2_3_OPS												\
															\
		NIK_2_2_OPS NIK_2_2_OPS

	#define NIK_2_4_OPS												\
															\
		NIK_2_3_OPS NIK_2_3_OPS

	#define NIK_2_5_OPS												\
															\
		NIK_2_4_OPS NIK_2_4_OPS

	#define NIK_2_6_OPS												\
															\
		NIK_2_5_OPS NIK_2_5_OPS

	#define NIK_2_7_OPS												\
															\
		NIK_2_6_OPS NIK_2_6_OPS

	#define NIK_2_8_OPS												\
															\
		NIK_2_7_OPS NIK_2_7_OPS

	#define NIK_2_9_OPS												\
															\
		NIK_2_8_OPS NIK_2_8_OPS

/***********************************************************************************************************************/

// block actions:

	#define NIK_2_0_ACTS												\
															\
		act::template result<

	#define NIK_2_1_ACTS												\
															\
		NIK_2_0_ACTS NIK_2_0_ACTS

	#define NIK_2_2_ACTS												\
															\
		NIK_2_1_ACTS NIK_2_1_ACTS

	#define NIK_2_3_ACTS												\
															\
		NIK_2_2_ACTS NIK_2_2_ACTS

	#define NIK_2_4_ACTS												\
															\
		NIK_2_3_ACTS NIK_2_3_ACTS

	#define NIK_2_5_ACTS												\
															\
		NIK_2_4_ACTS NIK_2_4_ACTS

	#define NIK_2_6_ACTS												\
															\
		NIK_2_5_ACTS NIK_2_5_ACTS

	#define NIK_2_7_ACTS												\
															\
		NIK_2_6_ACTS NIK_2_6_ACTS

	#define NIK_2_8_ACTS												\
															\
		NIK_2_7_ACTS NIK_2_7_ACTS

	#define NIK_2_9_ACTS												\
															\
		NIK_2_8_ACTS NIK_2_8_ACTS

/***********************************************************************************************************************/

// block operation values:

	#define NIK_2_0_OP_VS												\
															\
		NIK_UPPER_1_OP_VS

	#define NIK_2_1_OP_VS												\
															\
		NIK_UPPER_1_OP_VS, NIK_UPPER_2_OP_VS

	#define NIK_2_2_OP_VS												\
															\
		NIK_UPPER_1_OP_VS, NIK_UPPER_2_OP_VS, NIK_UPPER_4_OP_VS

	#define NIK_2_3_OP_VS												\
															\
		NIK_UPPER_1_OP_VS, NIK_UPPER_2_OP_VS, NIK_UPPER_4_OP_VS, NIK_UPPER_8_OP_VS

	#define NIK_2_4_OP_VS												\
															\
		NIK_UPPER_1_OP_VS, NIK_UPPER_2_OP_VS, NIK_UPPER_4_OP_VS, NIK_UPPER_8_OP_VS,				\
		NIK_UPPER_16_OP_VS

	#define NIK_2_5_OP_VS												\
															\
		NIK_UPPER_1_OP_VS, NIK_UPPER_2_OP_VS, NIK_UPPER_4_OP_VS, NIK_UPPER_8_OP_VS,				\
		NIK_UPPER_16_OP_VS, NIK_UPPER_32_OP_VS

	#define NIK_2_6_OP_VS												\
															\
		NIK_UPPER_1_OP_VS, NIK_UPPER_2_OP_VS, NIK_UPPER_4_OP_VS, NIK_UPPER_8_OP_VS,				\
		NIK_UPPER_16_OP_VS, NIK_UPPER_32_OP_VS, NIK_UPPER_64_OP_VS

	#define NIK_2_7_OP_VS												\
															\
		NIK_UPPER_1_OP_VS, NIK_UPPER_2_OP_VS, NIK_UPPER_4_OP_VS, NIK_UPPER_8_OP_VS,				\
		NIK_UPPER_16_OP_VS, NIK_UPPER_32_OP_VS, NIK_UPPER_64_OP_VS, NIK_UPPER_128_OP_VS

	#define NIK_2_8_OP_VS												\
															\
		NIK_UPPER_1_OP_VS, NIK_UPPER_2_OP_VS, NIK_UPPER_4_OP_VS, NIK_UPPER_8_OP_VS,				\
		NIK_UPPER_16_OP_VS, NIK_UPPER_32_OP_VS, NIK_UPPER_64_OP_VS, NIK_UPPER_128_OP_VS,			\
		NIK_UPPER_256_OP_VS

	#define NIK_2_9_OP_VS												\
															\
		NIK_UPPER_1_OP_VS, NIK_UPPER_2_OP_VS, NIK_UPPER_4_OP_VS, NIK_UPPER_8_OP_VS,				\
		NIK_UPPER_16_OP_VS, NIK_UPPER_32_OP_VS, NIK_UPPER_64_OP_VS, NIK_UPPER_128_OP_VS,			\
		NIK_UPPER_256_OP_VS, NIK_UPPER_512_OP_VS

/***********************************************************************************************************************/

// block action values:

	#define NIK_2_0_ACT_VS												\
															\
		NIK_UPPER_1_ACT_VS

	#define NIK_2_1_ACT_VS												\
															\
		NIK_UPPER_1_ACT_VS, NIK_UPPER_2_ACT_VS

	#define NIK_2_2_ACT_VS												\
															\
		NIK_UPPER_1_ACT_VS, NIK_UPPER_2_ACT_VS, NIK_UPPER_4_ACT_VS

	#define NIK_2_3_ACT_VS												\
															\
		NIK_UPPER_1_ACT_VS, NIK_UPPER_2_ACT_VS, NIK_UPPER_4_ACT_VS, NIK_UPPER_8_ACT_VS

	#define NIK_2_4_ACT_VS												\
															\
		NIK_UPPER_1_ACT_VS, NIK_UPPER_2_ACT_VS, NIK_UPPER_4_ACT_VS, NIK_UPPER_8_ACT_VS,				\
		NIK_UPPER_16_ACT_VS

	#define NIK_2_5_ACT_VS												\
															\
		NIK_UPPER_1_ACT_VS, NIK_UPPER_2_ACT_VS, NIK_UPPER_4_ACT_VS, NIK_UPPER_8_ACT_VS,				\
		NIK_UPPER_16_ACT_VS, NIK_UPPER_32_ACT_VS

	#define NIK_2_6_ACT_VS												\
															\
		NIK_UPPER_1_ACT_VS, NIK_UPPER_2_ACT_VS, NIK_UPPER_4_ACT_VS, NIK_UPPER_8_ACT_VS,				\
		NIK_UPPER_16_ACT_VS, NIK_UPPER_32_ACT_VS, NIK_UPPER_64_ACT_VS

	#define NIK_2_7_ACT_VS												\
															\
		NIK_UPPER_1_ACT_VS, NIK_UPPER_2_ACT_VS, NIK_UPPER_4_ACT_VS, NIK_UPPER_8_ACT_VS,				\
		NIK_UPPER_16_ACT_VS, NIK_UPPER_32_ACT_VS, NIK_UPPER_64_ACT_VS, NIK_UPPER_128_ACT_VS

	#define NIK_2_8_ACT_VS												\
															\
		NIK_UPPER_1_ACT_VS, NIK_UPPER_2_ACT_VS, NIK_UPPER_4_ACT_VS, NIK_UPPER_8_ACT_VS,				\
		NIK_UPPER_16_ACT_VS, NIK_UPPER_32_ACT_VS, NIK_UPPER_64_ACT_VS, NIK_UPPER_128_ACT_VS,			\
		NIK_UPPER_256_ACT_VS

	#define NIK_2_9_ACT_VS												\
															\
		NIK_UPPER_1_ACT_VS, NIK_UPPER_2_ACT_VS, NIK_UPPER_4_ACT_VS, NIK_UPPER_8_ACT_VS,				\
		NIK_UPPER_16_ACT_VS, NIK_UPPER_32_ACT_VS, NIK_UPPER_64_ACT_VS, NIK_UPPER_128_ACT_VS,			\
		NIK_UPPER_256_ACT_VS, NIK_UPPER_512_ACT_VS

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// variadic:

/***********************************************************************************************************************/

// fast auto:

	#define NIK_0_FAST_AUTO_VS

		// blank space.

	#define NIK_1_FAST_AUTO_VS											\
															\
		auto V0

	#define NIK_2_FAST_AUTO_VS											\
															\
		auto V0, auto V1

	#define NIK_3_FAST_AUTO_VS											\
															\
		auto V0, auto V1, auto V2

	#define NIK_4_FAST_AUTO_VS											\
															\
		auto V0, auto V1, auto V2, auto V3

	#define NIK_5_FAST_AUTO_VS											\
															\
		auto V0, auto V1, auto V2, auto V3, auto V4

	#define NIK_6_FAST_AUTO_VS											\
															\
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5

	#define NIK_7_FAST_AUTO_VS											\
															\
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6

	#define NIK_8_FAST_AUTO_VS											\
															\
		auto V0, auto V1, auto V2, auto V3, auto V4, auto V5, auto V6, auto V7

/***********************************************************************************************************************/

// fast values:

	#define NIK_0_FAST_VS

		// blank space.

	#define NIK_1_FAST_VS												\
															\
		V0

	#define NIK_2_FAST_VS												\
															\
		V0, V1

	#define NIK_3_FAST_VS												\
															\
		V0, V1, V2

	#define NIK_4_FAST_VS												\
															\
		V0, V1, V2, V3

	#define NIK_5_FAST_VS												\
															\
		V0, V1, V2, V3, V4

	#define NIK_6_FAST_VS												\
															\
		V0, V1, V2, V3, V4, V5

	#define NIK_7_FAST_VS												\
															\
		V0, V1, V2, V3, V4, V5, V6

	#define NIK_8_FAST_VS												\
															\
		V0, V1, V2, V3, V4, V5, V6, V7

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

