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

	#include nik_import(., interpret, cache, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, constant, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., interpret, pair, architect, v_0_5, gcc, dynamic, name)
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
//	#include"0-compile-time-space/07-machine/4-testing/0_unit_tests.hpp"
//	#include"0-compile-time-space/10-list/2-testing/unit_lists.hpp"

// run time space:

//	#include nik_import(., compile, procedure, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, continuation, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, signature, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, one_cycle, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, near_linear, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, typed_stack, architect, v_0_5, gcc, dynamic, name)
//	#include nik_import(., compile, typed_machine, architect, v_0_5, gcc, dynamic, name)

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

// original catenate:

/*
	// pattern match:

		template<typename> struct pattern_match_list;

		template<template<auto...> class ListName, auto... Values>
		struct pattern_match_list<ListName<Values...>>
		{
			template
			<
				template
				<
					template<auto...> class, typename, auto...

				> class Continuation, typename Type, auto... Args
			>
			using induct = Continuation<ListName, Type, Args..., Values...>;
		};

		//

		template<auto...> struct value_list		  { };

	// cons:

		template<template<auto...> class ListName, typename _NA_, auto... Values>
		using cons_cont = ListName<Values...>;

		template<typename... Types>
		using cons = typename pattern_match_list<value_list<>>::template induct
		<
			cons_cont, void, U_type_T<Types>...
		>;

	// catenate:

		template<template<auto...> class ListName, typename List2, auto... Values>
		using catenate_cont = typename pattern_match_list<List2>::template induct
		<
			cons_cont, void, Values...
		>;

		template<typename List1, typename List2>
		using catenate = typename pattern_match_list<List1>::template induct
		<
			catenate_cont, List2
		>;
*/

/***********************************************************************************************************************/

// alternate catenate:

/*
	struct list
	{
		template
		<
			typename Continuation, typename Type, auto... Ws,
			template<auto...> class ListName, auto... Vs
		>
		static constexpr auto induct(void(*)(ListName<Vs...>*))
		{
			return Continuation::template result<ListName, Type, Ws..., Vs...>;
		}
	};

	struct cons_cont
	{
		template<template<auto...> class ListName, typename _NA_, auto... Vs>
		static constexpr auto result = U_type_T<ListName<Vs...>>;
	};

	struct catenate_cont
	{
		template<template<auto...> class ListName, typename List2, auto... Vs>
		static constexpr auto result = list::template induct<cons_cont, void, Vs...>(U_type_T<List2>);
	};

	template<typename List1, typename List2>
	constexpr auto U_catenate_TxT = list::template induct<catenate_cont, List2>(U_type_T<List1>);
*/

/***********************************************************************************************************************/

/*
	template<typename> struct pattern_match_auto_list;

	template<template<auto...> class ListName, auto... Vs>
	struct pattern_match_auto_list<ListName<Vs...>>
	{
		template
		<
			template
			<
				template<auto...> class, typename, auto...

			> class Continuation, typename Type, auto... Args
		>
		static constexpr auto induct()
		{
			return Continuation<ListName, Type, Args..., Values...>;
		}
	};

	template<typename List1, typename List2>
	constexpr auto U_catenate_TxT = pattern_match_auto_list<List1>::template induct
	<
		catenate_cont, List2
	>;
*/

/***********************************************************************************************************************/

// multi catenate:

	template<typename> struct pattern_match_list;

	template<template<auto...> class ListName, auto... Vs>
	struct pattern_match_list<ListName<Vs...>>
	{
		template<typename Continuation, auto... Ws, typename... Ts>
		static constexpr auto induct(Ts... As)
		{
			return Continuation::template result<ListName, Ws..., Vs...>(As...);
		}
	};

	struct cons_cont
	{
		template<template<auto...> class ListName, auto... Vs>
		static constexpr auto result()
		{
			return U_type_T<ListName<Vs...>>;
		}
	};

	struct catenate_cont
	{
		template<template<auto...> class ListName, auto... Vs, typename L2, typename... Ls>
		static constexpr auto result(void(*)(L2*), Ls... As)
		{
			if constexpr (sizeof...(Ls) == 0)

				return pattern_match_list<L2>::template induct<cons_cont, Vs...>();
			else
				return pattern_match_list<L2>::template induct<catenate_cont, Vs...>(As...);
		}
	};

	template<typename L1, typename L2, typename... Ls>
	constexpr auto U_catenate_TxT = pattern_match_list<L1>::template induct<catenate_cont>(U_type_T<L2>, U_type_T<Ls>...);

/***********************************************************************************************************************/

	constexpr int square(int x) { return x*x; }

	int main(int argc, char *argv[])
	{
		printf("%d\n", U_catenate_TxT<auto_pack<1, 2>, auto_pack<3, 4>, auto_pack<5, 6>>);

	//	constexpr auto attr = function_module::template attr_to_variable<function_module::attr_by_cval>;
	//	printf("%s\n", function_module::template attr_is_immutable<attr> ? "true" : "false");
	//	printf("%s\n", function_module::template attr_is_variable<attr> ? "true" : "false");

	//	printf("%d\n", apply<J_add>(5, 7));

		return 0;
	}

