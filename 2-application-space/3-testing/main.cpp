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

#include"../c-tests.hpp"

/***********************************************************************************************************************/

	int main(int argc, char *argv[])
	{
		using namespace ocli_testing;
	//	using namespace numerical_analysis;
	//	using namespace extended_numbers;

	//	print_number(39275);

	// list operators:

		// repeat:

			simple_repeat_test();

		// map:

			simple_map_test();
			reverse_map_test();
			convoluted_map_test();

		// fold:

			simple_fold_test();

		// find:

		//	simple_find_first_test();
		//	simple_find_all_test();

	// numerical analysis:

		// range fold:

			simple_sum_test();
			simple_prod_test();

		return 0;
	}

