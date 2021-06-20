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

// find:

namespace ocli_testing
{
	using namespace list_operators;

/***********************************************************************************************************************/

// find first:

	void simple_find_first_test()
	{
		using mspec = range_map_spec
		<
			s_type, _id_
		>;

		using fspec = find_first_spec
		<
			s_type, is_less_than<s_type, s_type(0)>
		>;

		array<s_type> arr;

		map<mspec>(arr.begin(), s_type(0), arr.length());

		arr[17] = -3;

		auto [ ff_val, ff_msg ] = find_first<fspec>(arr.begin(), arr.end());

		printf("%lld\n", s_type(ff_val - arr.begin()));
	}

/*
							Interval::closed, Direction::forward

						>(map_arr, map_arr + 57);//map_end);
		printf("%s\n", is_value<Interrupt, Interrupt::before_value>(ff_msg) ? "true" : "false");
		printf("%s\n", is_value<Interrupt, Interrupt::before_act>(ff_msg) ? "true" : "false");
*/

/***********************************************************************************************************************/

	// find all:

	void simple_find_all_test()
	{
		using mspec = range_map_spec
		<
			s_type, _id_
		>;

		using fspec = find_all_spec
		<
			s_type, is_less_than<s_type, s_type(0)>
		>;

		array<s_type> arr;

		map<mspec>(arr.begin(), s_type(0), arr.length());

		arr[8] = -1;
		arr[17] = -4;

		array<s_type*, 2> found;

		find_all<fspec>(found.begin(), arr.begin(), arr.end());

		printf("%lld\n", s_type(found[0] - arr.begin()));
		printf("%lld\n", s_type(found[1] - arr.begin()));
	}

/***********************************************************************************************************************/

}

