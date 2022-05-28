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

#include<cstdio>

/***********************************************************************************************************************/

#include"inclusive.hpp"

/***********************************************************************************************************************/

// compile time space:

	#include nik_import(., interpret, generic, architect, v_1_0, gcc, dynamic, name)
	#include nik_import(., interpret, store, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, constant, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, pair, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, boolean, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, pointer, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, reference, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, array, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, machine, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, pack, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, list, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, function, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, colist, architect, v_1_0, gcc, dynamic, name)

//	#include"0-compile-time-space/07-machine/3-case-studies/0_factorial.hpp"
//	#include"0-compile-time-space/07-machine/3-case-studies/1_fibonacci.hpp"
//	#include"0-compile-time-space/07-machine/3-case-studies/2_functional.hpp"
//	#include"0-compile-time-space/07-machine/4-testing/0_unit_tests.hpp"
//	#include"0-compile-time-space/09-list/2-testing/unit_lists.hpp"

// run time space:

//	#include nik_import(., compile, procedure, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., compile, continuation, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., compile, signature, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., compile, one_cycle, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., compile, near_linear, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., compile, typed_stack, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., compile, typed_machine, architect, v_1_0, gcc, dynamic, name)

//	using store_module		= nik_module(interpret, store, architect, v_1_0, gcc);
//	using array_module		= nik_module(interpret, array, architect, v_1_0, gcc);
//	using machine_module		= nik_module(interpret, machine, architect, v_1_0, gcc);
//	using list_module		= nik_module(interpret, list, architect, v_1_0, gcc);
//	using function_module		= nik_module(interpret, function, architect, v_1_0, gcc);
//	using one_cycle_module		= nik_module(compile, one_cycle, architect, v_1_0, gcc);
//	using near_linear_module	= nik_module(compile, near_linear, architect, v_1_0, gcc);

/***********************************************************************************************************************/

	using u_type			= unsigned long long;
	using s_type			= signed long long;
	using size_type			= s_type;

	/*
	using StoreKey			= typename store_module::StoreKey;
//	constexpr auto U_StoreApply	= store_module::template U_store_T<typename store_module::StoreApply>;
	constexpr auto U_StoreApply	= store_module::U_StoreApply;
	*/

/***********************************************************************************************************************/

	constexpr int sq(int x) { return x*x; }

	struct Sq
	{
		template<int x>
		constexpr static int result = x*x;
	};

	constexpr auto U_Sq = U_store_T<Sq>;

	constexpr auto pack0 = U_pack_Vs<1, 2, 3>;

	int main(int argc, char *argv[])
	{
	//	printf("%d\n", apply<sq, 5>);
	//	printf("%d\n", apply<U_Sq, 5>);

		printf("%s\n", apply<U_StoreApply, StoreKey::is_auto_pack, 5> ? "true" : "false");
		printf("%s\n", apply<U_StoreApply, StoreKey::is_auto_pack, U_Sq> ? "true" : "false");
		printf("%s\n", apply<U_StoreApply, StoreKey::is_auto_pack, pack0> ? "true" : "false");
		printf("%s\n", apply<U_StoreApply, StoreKey::same, 5, 7> ? "true" : "false");
		printf("%s\n", apply<U_StoreApply, StoreKey::same, 5, 5> ? "true" : "false");

		return 0;
	}

