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

	#include nik_import(., interpret, cache, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, constant, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, pair, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, boolean, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, pointer, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, reference, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, array, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, machine, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, pack, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, list, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, function, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, colist, architect, v_0_5, gcc, dynamic, name)

//	#include"0-compile-time-space/07-machine/3-case-studies/0_factorial.hpp"
//	#include"0-compile-time-space/07-machine/3-case-studies/1_fibonacci.hpp"
//	#include"0-compile-time-space/07-machine/3-case-studies/2_functional.hpp"
//	#include"0-compile-time-space/07-machine/4-testing/0_unit_tests.hpp"
//	#include"0-compile-time-space/09-list/2-testing/unit_lists.hpp"

// run time space:

//	#include nik_import(., compile, procedure, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, continuation, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, signature, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, one_cycle, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, near_linear, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, typed_stack, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, typed_machine, architect, v_0_5, gcc, dynamic, name)

	using machine_module		= nik_module(interpret, machine, architect, v_0_5, gcc);
//	using list_module		= nik_module(interpret, list, architect, v_0_5, gcc);
//	using function_module		= nik_module(interpret, function, architect, v_0_5, gcc);
//	using one_cycle_module		= nik_module(compile, one_cycle, architect, v_0_5, gcc);
//	using near_linear_module	= nik_module(compile, near_linear, architect, v_0_5, gcc);

/***********************************************************************************************************************/

	using u_type		= unsigned long long;
	using s_type		= signed long long;
	using size_type		= s_type;

/***********************************************************************************************************************/

// array:

/*
	template<typename Type, size_type n = 20>
	struct array
	{
		size_type array_length;
		Type array_begin[n];
		Type *array_end;

		array() : array_length(n), array_end(array_begin + array_length) { }

		size_type length()			{ return array_length; }

		Type * begin() 				{ return array_begin; }
		Type * end() 				{ return array_end; }

		Type & operator [] (size_type k)	{ return array_begin[k]; }
	};
*/

/***********************************************************************************************************************/

// (independent) print array:

/*
	template<typename InIter>
	constexpr void print_sarray(InIter i, InIter e)
	{
		printf("%s", "\n");

		while (i != e) printf("%lld, ", *i++);

		printf("%s", "\n");
	}
*/

/***********************************************************************************************************************/

/*
	void simple_map_test()
	{
		using spec = near_linear_module::template range_map_spec
		<
			s_type, function_module::U_id
		>;

		array<s_type> arr;

		one_cycle_module::map<spec>(arr.begin(), s_type{0}, s_type{0});//arr.length());

		print_sarray(arr.begin(), arr.end());
	}
*/

/***********************************************************************************************************************/

/*
	using utype = unsigned long long;

	struct LT { template<auto V1, auto V2> static constexpr bool result = (V1 < V2); };
	constexpr auto U_LT = U_type_T<LT>;

	template<auto list1, auto list2, auto less_than>
	void print_merge_v0() { printf("merge: %d\n", merge_v0<list1, list2, less_than>); }

	constexpr auto l0 = U_pack_Vs<0, 1, 2, 3, 4, 5>;
*/

//	static constexpr unsigned arr[] = { 0, 1, 2, 3, 4 };

/***********************************************************************************************************************/

	using index_type = unsigned;
	using array_type = index_type const*;

/***********************************************************************************************************************/

/*
	template<index_type... Vs>
	constexpr index_type array[] = { Vs... };

	template<index_type... Vs>
	constexpr auto make_array_v1()
	{
		constexpr index_type local_array[] = { Vs... };

		return local_array;
	}

	template<index_type... Vs>
	constexpr auto make_array_v2()
	{
		return array<Vs...>;
	}

	constexpr auto arr2 = make_array_v2<1, 2, 3>();
*/

/***********************************************************************************************************************/

/*
	constexpr auto range_3 = U_pack_Vs<0, 1, 2>;

	template<index_type N>
	struct split_array
	{
		index_type locs[N];
		index_type poses[N];

		constexpr split_array(array_type arr, index_type offset) : locs{}, poses{}
		{
			for (index_type j=0, k=offset; j < N; ++j, k+=2)
			{
				locs[j]  = arr[k];
				poses[j] = arr[k+1];
			}
		}
	};

	template<array_type arr>
	constexpr auto splay()
	{
		constexpr index_type size = (arr[0] >> 1);

		return split_array<size>(arr, 1);
	}

	template<auto sa, auto... Is>
	constexpr auto unpack(void(*)(auto_pack<Is...>*))
	{
		constexpr auto val = sa();

		return U_pack_Vs
		<
			array<val.locs[Is]...>,
			array<val.poses[Is]...>
		>;
	}

	template<array_type arr>
	constexpr auto split()
	{
		constexpr auto sa = splay<arr>;

		return unpack<sa>(range_3);
	}

	template<auto locs, auto poses> constexpr auto car(void(*)(auto_pack<locs, poses>*)) { return locs; }
	template<auto locs, auto poses> constexpr auto cdr(void(*)(auto_pack<locs, poses>*)) { return poses; }

	constexpr index_type arr[]	= { 6, 0, 1, 2, 3, 4, 5 };

	constexpr auto split_arr	= split<arr>();
*/

/***********************************************************************************************************************/

	constexpr auto test_spec = machine_module::template test_spec<>;

/***********************************************************************************************************************/

	int main(int argc, char *argv[])
	{
		printf("%u\n", test_spec[10]);

		return 0;
	}

	//	printf("%d\n", get_value(pack));

	//	printf("%d\n", machine_module::template Fast<3>::U_even_index_sequence);

	//	print_merge_v0<l0, l0, U_LT>();

	//	printf("%d\n", list_module::template U_catenate_TxTxTs<auto_pack<0, 1>, auto_pack<2, 3>, auto_pack<4, 5>>);

	//	constexpr auto attr = function_module::template attr_to_variable<function_module::attr_by_cval>;
	//	printf("%s\n", function_module::template attr_is_immutable<attr> ? "true" : "false");
	//	printf("%s\n", function_module::template attr_is_variable<attr> ? "true" : "false");

	//	printf("%d\n", apply<J_add>(5, 7));

