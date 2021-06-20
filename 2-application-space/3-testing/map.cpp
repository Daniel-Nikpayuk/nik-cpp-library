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

#include"list_operators.h"

/***********************************************************************************************************************/

// map:

namespace ocli_testing
{
	using namespace list_operators;

/***********************************************************************************************************************/

	void simple_map_test()
	{
		using spec = range_map_spec
		<
			s_type, _id_
		>;

		array<s_type> arr;

		map<spec>(arr.begin(), s_type(0), arr.length());

		print_sarray(arr.begin(), arr.end());
	}

/***********************************************************************************************************************/

	void reverse_map_test()
	{
		using spec = range_map_spec
		<
			s_type, _id_,
			Interval::opening, Direction::backward,
			Interval::opening, Direction::backward
		>;

		array<s_type> arr;

		map<spec>(arr.end(), arr.length(), s_type(0));

		print_sarray(arr.begin(), arr.end());
	}

/***********************************************************************************************************************/

	void convoluted_map_test()
	{
		using spec = range_map_spec
		<
			s_type, _id_,
			Interval::closing, Direction::forward,
			Interval::opening, Direction::backward
		>;

		array<s_type> arr;

		map<spec>(arr.begin(), arr.length(), s_type(0));

		print_sarray(arr.begin(), arr.end());
	}

/***********************************************************************************************************************/

}

