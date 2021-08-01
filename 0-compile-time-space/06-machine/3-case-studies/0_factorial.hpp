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

// factorial:

	#include nik_import(../../.., interpret, constant, architect, v_0_5, gcc, dynamic, name)
	#include nik_import(../../.., interpret, machine, architect, v_0_5, gcc, dynamic, name)
	#include nik_import(../../.., interpret, function, architect, v_0_5, gcc, dynamic, title)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register (naive) factorial:

/***********************************************************************************************************************/

	template
	<
		// labels:

			index_type loop		= 0,
			index_type done		= 1,

		// registers:

			index_type val		= 0,
			index_type n		= 1,
			index_type eq		= 2,
			index_type sub		= 3,
			index_type mult		= 4,
			index_type c_0		= 5,
			index_type c_1		= 6
	>
	constexpr auto naive_fact_contr = controller
	<
		label // loop:
		<
			test         < eq        , n          , c_0       >,
			branch       < done                               >,
			save         < n                                  >,
			apply        < n         , sub        , n   , c_1 >,
			recurse      <                                    >,
			restore      < val       , n                      >,
			apply        < val       , mult       , n   , val >,
			goto_label   < done                               >
		>,

		label // done:
		<
			stop         < val                                >
		>
	>;

/***********************************************************************************************************************/

	template<auto n, auto d>
	constexpr auto f_naive_factorial()
	{
		using n_type = decltype(n);

		constexpr n_type val		= _one;
		constexpr auto eq_op		= nik_function_S_equal::template result <n_type, n_type>;
		constexpr auto sub_op		= nik_function_S_subtract::template result<n_type, n_type>;
		constexpr auto mult_op		= nik_function_S_multiply::template result<n_type, n_type>;
		constexpr n_type c_0		= _zero;
		constexpr n_type c_1		= _one;

		return start
		<
			register_machine, naive_fact_contr<>, d,
			val, n, eq_op, sub_op, mult_op, c_0, c_1
		>();
	}

	template<auto n, depth_type d = 500>
	constexpr auto naive_factorial = f_naive_factorial<n, d>();

/***********************************************************************************************************************/

// perf:

//		printf("%llu\n", naive_factorial<utype(5)>);

//			gcc compile time:		gcc run time:
//			                                
//			                                120
//			                                
//			real	0m0.893s                real	0m0.002s
//			user	0m0.809s                user	0m0.000s
//			sys	0m0.085s                sys	0m0.002s
//			                                
//			clang compile time:             clang run time:
//			                                
//			                                120
//			                                
//			real	0m1.134s                real	0m0.001s
//			user	0m1.036s                user	0m0.001s
//			sys	0m0.081s                sys	0m0.000s

//		printf("%llu\n", naive_factorial<utype(20)>);

//			gcc compile time:		gcc run time:
//			                                
//			                                2432902008176640000
//			                                
//			real	0m2.177s                real	0m0.002s
//			user	0m2.050s                user	0m0.000s
//			sys	0m0.125s                sys	0m0.002s
//			                                
//			clang compile time:             clang run time:
//			                                
//			                                2432902008176640000
//			                                
//			real	0m3.405s                real	0m0.002s
//			user	0m3.252s                user	0m0.002s
//			sys	0m0.130s                sys	0m0.000s

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template
	<
		// labels:

			index_type fact_loop	= 0,
			index_type fact_done	= 1,

		// registers:

			index_type p		= 0,
			index_type n		= 1,
			index_type eq		= 2,
			index_type sub		= 3,
			index_type mult		= 4,
			index_type c_0		= 5,
			index_type c_1		= 6
	>
	constexpr auto pair_fact_contr = controller
	<
		label // fact loop:
		<
			test       < eq        , n        , c_0       >,
			branch     < fact_done                        >,
			apply      < p         , mult , p , n         >,
			apply      < n         , sub      , n   , c_1 >,
			goto_label < fact_loop                        >
		>,

		label // fact done:
		<
			stop       < p                                >
		>
	>;

/***********************************************************************************************************************/

	template<auto n, auto d>
	constexpr auto f_fast_factorial()
	{
		using n_type = decltype(n);

		constexpr n_type p		= _one;
		constexpr auto eq_op		= nik_function_S_equal::template result<n_type, n_type>;
		constexpr auto sub_op		= nik_function_S_subtract::template result<n_type, n_type>;
		constexpr auto mult_op		= nik_function_S_multiply::template result<n_type, n_type>;
		constexpr n_type c_0		= _zero;
		constexpr n_type c_1		= _one;

		return start
		<
			register_machine, pair_fact_contr<>, d,
			p, n, eq_op, sub_op, mult_op, c_0, c_1
		>();
	}

	template<auto n, depth_type d = 500>
	constexpr auto fast_factorial = f_fast_factorial<n, d>();

/***********************************************************************************************************************/

// perf:

//		printf("%llu\n", fast_factorial<utype(5)>);

//			gcc compile time:		gcc run time:
//			                                
//			                                120
//			                                
//			real	0m0.761s                real	0m0.002s
//			user	0m0.678s                user	0m0.002s
//			sys	0m0.083s                sys	0m0.000s
//			                                
//			clang compile time:             clang run time:
//			                                
//			                                120
//			                                
//			real	0m1.068s                real	0m0.002s
//			user	0m0.933s                user	0m0.000s
//			sys	0m0.089s                sys	0m0.002s

//		printf("%llu\n", r_factorial<utype(20)>);

//			gcc compile time:		gcc run time:
//			                                
//			                                2432902008176640000
//			                                
//			real	0m1.052s                real	0m0.002s
//			user	0m0.966s                user	0m0.001s
//			sys	0m0.087s                sys	0m0.000s
//			                                
//			clang compile time:             clang run time:
//			                                
//			                                2432902008176640000
//			                                
//			real	0m1.533s                real	0m0.001s
//			user	0m1.426s                user	0m0.001s
//			sys	0m0.082s                sys	0m0.000s

/***********************************************************************************************************************/

// convenience functions:

//	template<utype n>
//	void print_naive_factorial() { printf("naive factorial(%llu): %llu\n", n, naive_factorial<n>); }

//	template<utype n>
//	void print_fast_factorial() { printf("fast factorial(%llu): %llu\n", n, fast_factorial<n>); }

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

