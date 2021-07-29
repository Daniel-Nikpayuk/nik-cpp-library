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
//	#include nik_import(., interpret, machine, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, pack, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, function, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, list, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, colist, architect, v_0_5, gcc, dynamic, name)

//	#include"0-compile-time-space/06-machine/3-case-studies/0_factorial.hpp"
	#include"0-compile-time-space/06-machine/3-case-studies/1_fibonacci.hpp"
//	#include"0-compile-time-space/09-list/2-testing/unit_lists.hpp"

// run time space:

//	#include nik_import(., compile, procedure, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, continuation, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, signature, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, one_cycle, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, near_linear, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, typed_stack, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, typed_machine, architect, v_0_5, gcc, dynamic, name)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	using utype = unsigned long long;

/***********************************************************************************************************************/

	int main(int argc, char *argv[])
	{
	//	printf("%llu\n", naive_fibonacci<utype(5)>); // fib(13): clang over 5 minutes!
		printf("%llu\n", builtin_naive_fibonacci<utype(13)>); // 1.82s (gcc) / 2.33s (clang)

	//	printf("%llu\n", factorial<utype(20)>);
	//	printf("%llu\n", naive_factorial<utype(5)>);
	//	printf("%llu\n", fast_factorial<utype(20)>);
	
		return 0;
	}

