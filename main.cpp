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
//#include<ctime>
//#include<cstdlib>

/***********************************************************************************************************************/

#include"inclusive.hpp"

/***********************************************************************************************************************/

// compile time space:

//	#include nik_import(., interpret, generic, architect, v_1_0, gcc, dynamic, name)
	#include nik_import(., interpret, store, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, constant, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, pair, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, boolean, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, reference, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, pointer, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, array, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, machine, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, list, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, function, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, colist, architect, v_1_0, gcc, dynamic, name)
//	#include nik_import(., interpret, pack, architect, v_1_0, gcc, dynamic, name)

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

	using generic_module		= nik_module(interpret, generic, architect, v_1_0, gcc);
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

	using index_type		= typename generic_module::index_type;
	using size_type			= s_type;

/***********************************************************************************************************************/

	template<typename... Ts> struct tuple { };

	template<typename T, typename... Ts>
	struct tuple<T, Ts...> : public tuple<Ts...>
	{
		T value;

		constexpr tuple(const T & v, const Ts &... vs) : value(v), tuple<Ts...>(vs...) { }
	};

	template<index_type n, typename T, typename... Ts>
	constexpr auto & _tuple_value(tuple<T, Ts...> *t)
	{
		if constexpr (n == 0) return t->value;
		else
		{
			tuple<Ts...> *nt = t;
			return _tuple_value<n-1, Ts...>(nt);
		}
	}

	template<index_type n, typename T, typename... Ts>
	constexpr auto & tuple_value(tuple<T, Ts...> & t) { return _tuple_value<n, T, Ts...>(&t); }

/***********************************************************************************************************************/

	constexpr void _id_() { }

	// lift:

		template<index_type, auto, typename> struct _lift;

		template<index_type O, auto f, index_type... Is>
		struct _lift<O, f, auto_pack<Is...>>
		{
			template<auto cont, typename T, typename... Ts>
			constexpr static tuple<T, Ts...> & result(tuple<T, Ts...> & t)
			{
				tuple_value<O>(t) = f(tuple_value<Is>(t)...);

				return cont(t);
			}
		};

		template<index_type O, auto f, index_type... Is>
		constexpr auto lift = U_store_T<_lift<O, f, auto_pack<Is...>>>;

	// test:

		template<auto, typename> struct _test;

		template<auto p, index_type... Is>
		struct _test<p, auto_pack<Is...>>
		{
			template<auto cont, typename T, typename... Ts>
			constexpr static tuple<T, Ts...> & result(tuple<T, Ts...> & t)
			{
				return cont(t, p(tuple_value<Is>(t)...));
			}
		};

		template<auto p, index_type... Is>
		constexpr auto test = U_store_T<_test<p, auto_pack<Is...>>>;

	// branch:

		template<auto label>
		struct _branch
		{
			template<auto cont, typename T, typename... Ts>
			constexpr static tuple<T, Ts...> & result(tuple<T, Ts...> & t, bool cond)
			{
				if (cond) return label(t);
				else      return cont(t);
			}
		};

		template<auto label>
		constexpr auto branch = U_store_T<_branch<label>>;

	// compose:

		template<typename F, typename G>
		struct _compose
		{
			template<auto cont, typename T, typename... Ts>
			constexpr static tuple<T, Ts...> & result(tuple<T, Ts...> & t)
			{
				constexpr bool is_id = store_apply<StoreKey::same, cont, _id_>;

				if constexpr (is_id)

					return t;
				else
					return F::template result
					<
						G::template result<cont, T, Ts...>
					>(t);
			}
		};

		template<auto UF, auto UG>
		constexpr auto compose = U_store_T<_compose<T_store_U<UF>, T_store_U<UG>>>;

	// endopose:

	template<typename, auto...>
	constexpr auto endopose = false;

	template<typename T, typename... Ts, auto F, auto cont>
	constexpr auto endopose<tuple<T, Ts...>, F, cont> = T_store_U<F>::template result<cont, T, Ts...>;

	template<typename Tuple, auto F, auto F0, auto F1, auto... Fs>
	constexpr auto endopose<Tuple, F, F0, F1, Fs...> = endopose<Tuple, compose<F, F0>, F1, Fs...>;

/***********************************************************************************************************************/

/*
	constexpr float multiply(float x, float y) { return x*y; }

	template
	<
		index_type i = 0,
		index_type c = 1,
		index_type f = 2
	>
	constexpr auto algo = endopose
	<
		tuple < int , char , float >,

		lift < f , multiply , f , i >,
		lift < f , multiply , f , f >,

		tuple_value<f, int, char, float>
	>;
*/

/***********************************************************************************************************************/

// default version:

/*
	constexpr u_type pair_factorial(u_type n, u_type p)
	{
		if (n == 0) return p;
		else        return pair_factorial(n-1, p*n);
	}

	constexpr u_type factorial(u_type n)
	{
		return pair_factorial(n, 1);
	}
*/

/***********************************************************************************************************************/

	constexpr bool    is_zero  (u_type n)           { return (n == 0); }
	constexpr u_type multiply  (u_type m, u_type n) { return m*n; }
	constexpr u_type decrement (u_type n)		{ return n-1; }

	struct Factorial
	{
		using Tuple = tuple<u_type, u_type>;

		constexpr static Tuple & start (Tuple &);
		constexpr static Tuple & done  (Tuple &);

		template<index_type n = 0, index_type p = 1>
		constexpr static auto program = endopose
		<
			Tuple,

			test   < is_zero , n >,
			branch < done        >,

			lift   < p , multiply  , n , p >,
			lift   < n , decrement , n     >,

			start
		>;
	};

	constexpr Factorial::Tuple & Factorial::start (Factorial::Tuple & t) { return Factorial::template program<>(t); }
	constexpr Factorial::Tuple & Factorial::done  (Factorial::Tuple & t) { return t; }

	constexpr u_type factorial(u_type n)
	{
		Factorial::Tuple t(n, 1);

		return tuple_value<1>(Factorial::start(t));
	}

/***********************************************************************************************************************/

	int main(int argc, char *argv[])
	{
		printf("%llu\n", factorial(argc));

	//	srand(time(NULL));
	//	printf("%llu\n", factorial(rand() % 10));

		return 0;
	}

