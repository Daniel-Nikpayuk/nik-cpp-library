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

#include<cstdio>

/***********************************************************************************************************************/

#include"inclusive.hpp"

/***********************************************************************************************************************/

// compile time space:

//	#include nik_import(., interpret, functor, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, constant, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, boolean, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, pointer, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, reference, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, array, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, controller, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, machine, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, pack, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, list, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, function, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, colist, architect, v_0_5, gcc, dynamic, name)
  
//	#include"0-compile-time-space/07-machine/3-case-studies/0_factorial.hpp"
//	#include"0-compile-time-space/07-machine/3-case-studies/1_fibonacci.hpp"
//	#include"0-compile-time-space/09-list/2-testing/unit_lists.hpp"

// run time space:

//	#include nik_import(., compile, composition, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, endoposition, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, signature, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, near_linear, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, one_cycle, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, typed_stack, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, typed_machine, architect, v_0_5, gcc, dynamic, name)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	using utype = unsigned long long;

/*
	struct s_int
	{
		int x;

		s_int(int _x) : x(_x) { }
	};

	constexpr int & get_x(s_int & s) { return s.x; }

	constexpr auto func	= do_compose<multiply_by<int, 2>, add_by<int, 1>>;
	constexpr auto asgn	= assign<get_x, func, get_x>;
*/

	int main(int argc, char *argv[])
	{
	//	s_int s(5);
	//	asgn(s);

	//	printf("%d\n", get_x(s));

	//	printf("%d\n", at<list_1000, 887>);
	//	printf("%llu\n", r_fibonacci<utype(5)>);
	//	printf("%llu\n", rp_factorial<utype(20)>);

		return 0;
	}

