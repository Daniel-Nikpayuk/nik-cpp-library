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

	#include nik_import(., interpret, functor, architect, v_0_5, gcc, dynamic, name)
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

//	#include"0-compile-time-space/07-machine/3-case-studies/0_factorial.hpp"
//	#include"0-compile-time-space/07-machine/3-case-studies/1_fibonacci.hpp"
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

	using machine_module = nik_module(interpret, machine, architect, v_0_5, gcc);

	//

/*
	template<auto n, auto d, auto... Vs>
	constexpr auto f_list_at(void(*)(auto_pack<Vs...>*))
	{
		using LD = typename machine_module::LD;

		constexpr auto c = machine_module::template label
		<
			machine_module::template stop<n>
		>;

		return machine_module::template start<LD, c, d, 1, 0, Vs...>();
	}

	template<typename List, auto n, auto d = 500>
	constexpr auto list_at = f_list_at<n, d>(U_type_T<List>);
*/

/*
	template<auto n, auto d>
	constexpr auto f_index_sequence()
	{
		using LD = typename machine_module::LD;

		constexpr auto c = machine_module::template label
		<
			machine_module::template make_i_segment__insert_at_s_back<n>,
			machine_module::template pack<>
		>;

		return machine_module::template start<LD, c, d, 1, 0>();
	}

	template<auto n, auto d = 500>
	constexpr auto index_sequence = f_index_sequence<n, d>();
*/

	template<auto n, auto d, auto... Vs>
	constexpr auto f_list_erase(void(*)(auto_pack<Vs...>*))
	{
		using LD = typename machine_module::LD;

		constexpr auto c = machine_module::template label
		<
			machine_module::template erase<n>,
			machine_module::template pack<>
		>;

		return machine_module::template start<LD, c, d, 1, 0, Vs...>();
	}

	template<typename List, auto n, auto d = 500>
	constexpr auto list_erase = f_list_erase<n, d>(U_type_T<List>);

/***********************************************************************************************************************/

	constexpr auto ulist_5 = U_pack_Vs<5, -12, 7, 9, 0>;
//	constexpr auto ulist_4 = list_erase<T_type_U<ulist_5>, 2>;

	int main(int argc, char *argv[])
	{
	//	printf("%d\n", ulist_5);
	//	printf("%d\n", ulist_4);

	//	printf("%d\n", index_sequence<11>);
	//	printf("%d\n", list_at<list_1000, 887>);
	//	printf("%llu\n", r_fibonacci<utype(5)>);
	//	printf("%llu\n", rp_factorial<utype(20)>);

		return 0;
	}

