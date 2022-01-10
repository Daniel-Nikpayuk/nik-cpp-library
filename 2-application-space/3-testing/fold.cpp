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

#include"list_operators.h"

/***********************************************************************************************************************/

// fold:

namespace ocli_testing
{
	using namespace list_operators;

/***********************************************************************************************************************/

		// assumes simple map test:

	void simple_fold_test()
	{
		using mspec = range_map_spec
		<
			s_type, _id_
		>;

		using fspec = fold_spec
		<
			s_type,
			add<s_type>
		>;

		array<s_type> arr;

		map<mspec>(arr.begin(), s_type(0), arr.length());

		s_type value = fold<fspec>(s_type(0), arr.begin(), arr.end());

		printf("fold value: %lld\n", value);
		printf("base value: %lld\n", s_type((arr.length()-1)*arr.length()/2));
	}

/***********************************************************************************************************************/

}

