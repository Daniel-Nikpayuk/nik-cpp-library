/************************************************************************************************************************
**
** Copyright 2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

// lists:

	// In terms of performance I am working with:

		//   gcc nesting depth:  900
		// clang nesting depth: 1024

	// The following (non-empty) lists consist of the following numbers:

	//	-2, 0, 1, 2, 3, 4, 5, 6, 7, 9, 11, 12, 223, 1729

	// The numbers are (weakly) mixed, with the exception of
	// 1729, which occurs exactly 3 times in each list,
	// and is located at (weakly) random positions.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

	#include nik_import(../../.., interpret, functor, architect, v_0_5, gcc, dynamic, name)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// list 0:

		// rows:       0
		// columns:    0
		// length:     0
		// 1729:       not applicable

	using list_0 = auto_pack
	<
	>;

/***********************************************************************************************************************/

// list 50:

		// rows:         5
		// columns:     10
		// length:      50
		// 1729:        42, 48, 49

	using list_50 = auto_pack
	<
	     5, 3,   12,  9, 7,     5, 3,  12,    9,    7,
	    -2, 0,  223, 11, 7,     6, 5,   4,    3,    2,
	     4, 4,    4,  4, 4,     4, 4,   4,    4,    4,
	     6, 5,    4,  3, 2,    -2, 0, 223,   11,    7,
	     1, 3, 1729,  3, 1,     1, 3,   6, 1729, 1729
	>;

/***********************************************************************************************************************/

// list 100:

		// rows:         5
		// columns:     20
		// length:     100
		// 1729:        49, 67, 95

	using list_100 = auto_pack
	<
	     5, 3,  12,  9, 7,     5, 3,   12,  9,    7,     5, 3,  12,  9, 7,       5, 3,  12,  9, 7,
	    -2, 0, 223, 11, 7,     6, 5,    4,  3,    2,     6, 5,   4,  3, 2,       6, 5,   4,  3, 2,
	     4, 4,   4,  4, 4,     4, 4,    4,  4, 1729,     4, 4,   4,  4, 4,       4, 4,   4,  4, 4,
	     6, 5,   4,  3, 2,    -2, 0, 1729, 11,    7,    -2, 0, 223, 11, 7,      -2, 0, 223, 11, 7,
	     1, 3,   6,  3, 1,     1, 3,    6,  3,    1,     1, 3,   6,  3, 1,    1729, 3,   6,  3, 1
	>;

/***********************************************************************************************************************/

// list 150:

		// rows:        10
		// columns:     25
		// length:     150
		// 1729:         6, 79, 109

	using list_150 = auto_pack
	<
	     5, 3,  12,  9,    7,     5, 1729,  12,  9,    7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0, 223, 11,    7,     6,    5,   4,  3,    2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,
	     4, 4,   4,  4,    4,     4,    4,   4,  4,    4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5,   4,  3, 1729,    -2,    0, 223, 11,    7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     1, 3,   6,  3,    1,     1,    3,   6,  3, 1729,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,

	     5, 3,  12,  9,    7,
	    -2, 0, 223, 11,    7,
	     4, 4,   4,  4,    4,
	     6, 5,   4,  3,    2,
	     1, 3,   6,  3,    1
	>;

/***********************************************************************************************************************/

// list 200:

		// rows:        10
		// columns:     25
		// length:     200
		// 1729:        45, 153, 163

	using list_200 = auto_pack
	<
	     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,       5, 3,  12,  9, 7,
	    -2, 0, 223, 11, 7,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,    1729, 5,   4,  3, 2,
	     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,       4, 4,   4,  4, 4,
	     6, 5,   4,  3, 2,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,      -2, 0, 223, 11, 7,
	     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,       1, 3,   6,  3, 1,

	     5, 3,  12,  9, 7,     5, 3,  12,    9, 7,     5, 3,  12,    9, 7,
	    -2, 0, 223, 11, 7,    -2, 0, 223,   11, 7,    -2, 0, 223, 1729, 7,
	     4, 4,   4,  4, 4,     4, 4,   4, 1729, 4,     4, 4,   4,    4, 4,
	     6, 5,   4,  3, 2,     6, 5,   4,    3, 2,     6, 5,   4,    3, 2,
	     1, 3,   6,  3, 1,     1, 3,   6,    3, 1,     1, 3,   6,    3, 1
	>;

/***********************************************************************************************************************/

// list 250:

		// rows:        10
		// columns:     25
		// length:     250
		// 1729:        28, 72, 198

	using list_250 = auto_pack
	<
	     5, 3,  12,    9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,     5, 3,   12,    9, 7,
	    -2, 0, 223, 1729, 7,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,     6, 5,    4,    3, 2,
	     4, 4,   4,    4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,     4, 4, 1729,    4, 4,
	     6, 5,   4,    3, 2,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,    -2, 0,  223,   11, 7,
	     1, 3,   6,    3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,     1, 3,    6,    3, 1,

	     5, 3,  12,    9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,     5, 3,   12,    9, 7,
	    -2, 0, 223,   11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,    -2, 0,  223,   11, 7,
	     4, 4,   4,    4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,     4, 4,    4, 1729, 4,
	     6, 5,   4,    3, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,     6, 5,    4,    3, 2,
	     1, 3,   6,    3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,     1, 3,    6,    3, 1
	>;

/***********************************************************************************************************************/

// list 500:

		// rows:        20
		// columns:     25
		// length:     500
		// 1729:       129, 391, 452

	using list_500 = auto_pack
	<
	     5, 3,   12,  9,    7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,     5,    3,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0,  223, 11,    7,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,     6,    5,   4,  3, 2,     6, 5,   4,  3, 2,
	     4, 4,    4,  4,    4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,     4,    4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5,    4,  3,    2,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,    -2,    0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     1, 3,    6,  3,    1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,     1,    3,   6,  3, 1,     1, 3,   6,  3, 1,

	     5, 3,   12,  9, 1729,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,     5,    3,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0,  223, 11,    7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,    -2,    0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     4, 4,    4,  4,    4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,     4,    4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5,    4,  3,    2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,     6,    5,   4,  3, 2,     6, 5,   4,  3, 2,
	     1, 3,    6,  3,    1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,     1,    3,   6,  3, 1,     1, 3,   6,  3, 1,

	     5, 3,   12,  9,    7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,     5,    3,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0,  223, 11,    7,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,     6,    5,   4,  3, 2,     6, 5,   4,  3, 2,
	     4, 4,    4,  4,    4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,     4,    4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5,    4,  3,    2,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,    -2,    0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     1, 3,    6,  3,    1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,     1,    3,   6,  3, 1,     1, 3,   6,  3, 1,

	     5, 3,   12,  9,    7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,     5, 1729,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0,  223, 11,    7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,    -2,    0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     4, 4,    4,  4,    4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,     4,    4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5, 1729,  3,    2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,     6,    5,   4,  3, 2,     6, 5,   4,  3, 2,
	     1, 3,    6,  3,    1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,     1,    3,   6,  3, 1,     1, 3,   6,  3, 1
	>;

/***********************************************************************************************************************/

// list 750:

		// rows:        30
		// columns:     25
		// length:     750
		// 1729:       38, 285, 578

	using list_750 = auto_pack
	<
	     5, 3,  12,    9, 7,     5, 3,  12,  9, 7,       5, 3,  12,    9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0, 223,   11, 7,     6, 5,   4,  3, 2,       6, 5,   4, 1729, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,
	     4, 4,   4,    4, 4,     4, 4,   4,  4, 4,       4, 4,   4,    4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5,   4,    3, 2,    -2, 0, 223, 11, 7,      -2, 0, 223,   11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     1, 3,   6,    3, 1,     1, 3,   6,  3, 1,       1, 3,   6,    3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,

	     5, 3,  12,    9, 7,     5, 3,  12,  9, 7,       5, 3,  12,    9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0, 223,   11, 7,    -2, 0, 223, 11, 7,      -2, 0, 223,   11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     4, 4,   4,    4, 4,     4, 4,   4,  4, 4,       4, 4,   4,    4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5,   4,    3, 2,     6, 5,   4,  3, 2,       6, 5,   4,    3, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,
	     1, 3,   6,    3, 1,     1, 3,   6,  3, 1,       1, 3,   6,    3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,

	     5, 3,  12,    9, 7,     5, 3,  12,  9, 7,       5, 3,  12,    9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0, 223,   11, 7,     6, 5,   4,  3, 2,    1729, 5,   4,    3, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,
	     4, 4,   4,    4, 4,     4, 4,   4,  4, 4,       4, 4,   4,    4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5,   4,    3, 2,    -2, 0, 223, 11, 7,      -2, 0, 223,   11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     1, 3,   6,    3, 1,     1, 3,   6,  3, 1,       1, 3,   6,    3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,

	     5, 3,  12,    9, 7,     5, 3,  12,  9, 7,       5, 3,  12,    9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0, 223,   11, 7,    -2, 0, 223, 11, 7,      -2, 0, 223,   11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     4, 4,   4,    4, 4,     4, 4,   4,  4, 4,       4, 4,   4,    4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5,   4,    3, 2,     6, 5,   4,  3, 2,       6, 5,   4,    3, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,
	     1, 3,   6,    3, 1,     1, 3,   6,  3, 1,       1, 3,   6,    3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,

	     5, 3,  12,    9, 7,     5, 3,  12,  9, 7,       5, 3,  12,    9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0, 223,   11, 7,     6, 5,   4,  3, 2,       6, 5,   4,    3, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,
	     4, 4,   4,    4, 4,     4, 4,   4,  4, 4,       4, 4,   4,    4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5,   4, 1729, 2,    -2, 0, 223, 11, 7,      -2, 0, 223,   11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     1, 3,   6,    3, 1,     1, 3,   6,  3, 1,       1, 3,   6,    3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,

	     5, 3,  12,    9, 7,     5, 3,  12,  9, 7,       5, 3,  12,    9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0, 223,   11, 7,    -2, 0, 223, 11, 7,      -2, 0, 223,   11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     4, 4,   4,    4, 4,     4, 4,   4,  4, 4,       4, 4,   4,    4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5,   4,    3, 2,     6, 5,   4,  3, 2,       6, 5,   4,    3, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,
	     1, 3,   6,    3, 1,     1, 3,   6,  3, 1,       1, 3,   6,    3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1
	>;

/***********************************************************************************************************************/

// list 1000:

		// rows:        40
		// columns:     25
		// length:    1000
		// 1729:       704, 862, 887

	using list_1000 = auto_pack
	<
	     5, 3,  12,  9,    7,     5, 3,  12,  9, 7,     5, 3,   12,  9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0, 223, 11,    7,     6, 5,   4,  3, 2,     6, 5,    4,  3, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,
	     4, 4,   4,  4,    4,     4, 4,   4,  4, 4,     4, 4,    4,  4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5,   4,  3,    2,    -2, 0, 223, 11, 7,    -2, 0,  223, 11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     1, 3,   6,  3,    1,     1, 3,   6,  3, 1,     1, 3,    6,  3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,

	     5, 3,  12,  9,    7,     5, 3,  12,  9, 7,     5, 3,   12,  9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0, 223, 11,    7,    -2, 0, 223, 11, 7,    -2, 0,  223, 11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     4, 4,   4,  4,    4,     4, 4,   4,  4, 4,     4, 4,    4,  4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5,   4,  3,    2,     6, 5,   4,  3, 2,     6, 5,    4,  3, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,
	     1, 3,   6,  3,    1,     1, 3,   6,  3, 1,     1, 3,    6,  3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,

	     5, 3,  12,  9,    7,     5, 3,  12,  9, 7,     5, 3,   12,  9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0, 223, 11,    7,     6, 5,   4,  3, 2,     6, 5,    4,  3, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,
	     4, 4,   4,  4,    4,     4, 4,   4,  4, 4,     4, 4,    4,  4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5,   4,  3,    2,    -2, 0, 223, 11, 7,    -2, 0,  223, 11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     1, 3,   6,  3,    1,     1, 3,   6,  3, 1,     1, 3,    6,  3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,

	     5, 3,  12,  9,    7,     5, 3,  12,  9, 7,     5, 3,   12,  9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0, 223, 11,    7,    -2, 0, 223, 11, 7,    -2, 0,  223, 11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     4, 4,   4,  4,    4,     4, 4,   4,  4, 4,     4, 4,    4,  4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5,   4,  3,    2,     6, 5,   4,  3, 2,     6, 5,    4,  3, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,
	     1, 3,   6,  3,    1,     1, 3,   6,  3, 1,     1, 3,    6,  3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,

	     5, 3,  12,  9,    7,     5, 3,  12,  9, 7,     5, 3,   12,  9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0, 223, 11,    7,     6, 5,   4,  3, 2,     6, 5,    4,  3, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,
	     4, 4,   4,  4,    4,     4, 4,   4,  4, 4,     4, 4,    4,  4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5,   4,  3,    2,    -2, 0, 223, 11, 7,    -2, 0,  223, 11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     1, 3,   6,  3,    1,     1, 3,   6,  3, 1,     1, 3,    6,  3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,

	     5, 3,  12,  9,    7,     5, 3,  12,  9, 7,     5, 3,   12,  9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0, 223, 11,    7,    -2, 0, 223, 11, 7,    -2, 0,  223, 11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     4, 4,   4,  4,    4,     4, 4,   4,  4, 4,     4, 4,    4,  4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5,   4,  3, 1729,     6, 5,   4,  3, 2,     6, 5,    4,  3, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,
	     1, 3,   6,  3,    1,     1, 3,   6,  3, 1,     1, 3,    6,  3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,

	     5, 3,  12,  9,    7,     5, 3,  12,  9, 7,     5, 3,   12,  9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0, 223, 11,    7,     6, 5,   4,  3, 2,     6, 5,    4,  3, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,
	     4, 4,   4,  4,    4,     4, 4,   4,  4, 4,     4, 4,    4,  4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5,   4,  3,    2,    -2, 0, 223, 11, 7,    -2, 0,  223, 11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     1, 3,   6,  3,    1,     1, 3,   6,  3, 1,     1, 3, 1729,  3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1,

	     5, 3,  12,  9,    7,     5, 3,  12,  9, 7,     5, 3, 1729,  9, 7,     5, 3,  12,  9, 7,     5, 3,  12,  9, 7,
	    -2, 0, 223, 11,    7,    -2, 0, 223, 11, 7,    -2, 0,  223, 11, 7,    -2, 0, 223, 11, 7,    -2, 0, 223, 11, 7,
	     4, 4,   4,  4,    4,     4, 4,   4,  4, 4,     4, 4,    4,  4, 4,     4, 4,   4,  4, 4,     4, 4,   4,  4, 4,
	     6, 5,   4,  3,    2,     6, 5,   4,  3, 2,     6, 5,    4,  3, 2,     6, 5,   4,  3, 2,     6, 5,   4,  3, 2,
	     1, 3,   6,  3,    1,     1, 3,   6,  3, 1,     1, 3,    6,  3, 1,     1, 3,   6,  3, 1,     1, 3,   6,  3, 1
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

