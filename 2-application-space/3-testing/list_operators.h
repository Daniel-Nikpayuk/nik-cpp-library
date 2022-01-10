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

#ifndef LIST_OPERATORS_H
#define LIST_OPERATORS_H

#include"../a-source.hpp"
#include"prerequisites.hpp"

/***********************************************************************************************************************/

namespace ocli_testing
{

/***********************************************************************************************************************/

// repeat:

	void simple_repeat_test();

/***********************************************************************************************************************/

// map:

	void simple_map_test();
	void reverse_map_test();
	void convoluted_map_test();

/***********************************************************************************************************************/

// fold:

	void simple_fold_test();

/***********************************************************************************************************************/

// find:

	void simple_find_first_test();
	void simple_find_all_test();

/***********************************************************************************************************************/

}

#endif

