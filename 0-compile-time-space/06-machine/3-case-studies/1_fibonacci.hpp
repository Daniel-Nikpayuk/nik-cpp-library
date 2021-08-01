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

// fibonacci:

	#include nik_import(../../.., interpret, constant, architect, v_0_5, gcc, dynamic, name)
	#include nik_import(../../.., interpret, machine, architect, v_0_5, gcc, dynamic, name)
	#include nik_import(../../.., interpret, function, architect, v_0_5, gcc, dynamic, title)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register (naive) fibonacci:

/***********************************************************************************************************************/

	template
	<
		// labels:

			index_type loop			= 0,
			index_type done			= 1,

		// registers:

			index_type m			= 0,
			index_type n			= 1,
			index_type eq			= 2,
			index_type sub			= 3,
			index_type add			= 4,
			index_type c_0			= 5,
			index_type c_1			= 6
	>
	constexpr auto naive_fib_contr = controller
	<
		label // loop:
		<
			test         < eq        , n          , c_1       >,
			branch       < done                               >,
			test         < eq        , n          , c_0       >,
			branch       < done                               >,
			apply        < n         , sub        , n   , c_1 >,
			recurse      <                                    >,
			apply        < n         , sub        , n   , c_1 >,
			recurse      <                                    >,
			restore      < n         , m                      >,
			apply        < m         , add        , m   , n   >,
			goto_label   < done                               >
		>,

		label // done:
		<
			stop       < m                                    >
		>
	>;

/***********************************************************************************************************************/

	template<auto n, auto d>
	static constexpr auto f_naive_fibonacci()
	{
		using n_type = decltype(n);

		constexpr n_type m		= _one;
		constexpr auto eq_op		= nik_function_S_equal::template result<n_type, n_type>;
		constexpr auto sub_op		= nik_function_S_subtract::template result<n_type, n_type>;
		constexpr auto add_op		= nik_function_S_add::template result<n_type, n_type>;
		constexpr n_type c_0		= _zero;
		constexpr n_type c_1		= _one;

		return start
		<
			register_machine, naive_fib_contr<>, d,
			m, n, eq_op, sub_op, add_op, c_0, c_1
		>();
	}

	template<auto n, depth_type d = 500>
	constexpr auto naive_fibonacci = f_naive_fibonacci<n, d>();

/***********************************************************************************************************************/

// perf:

//		printf("%llu\n", fibonacci<utype(5)>);

//			gcc compile time:		gcc run time:
//			                                
//			                                5
//			                                
//			real	0m1.965s                real	0m0.002s
//			user	0m1.845s                user	0m0.000s
//			sys	0m0.117s                sys	0m0.002s
//			                                
//			clang compile time:             clang run time:
//			                                
//			                                5
//			                                
//			real	0m2.985s                real	0m0.001s
//			user	0m2.722s                user	0m0.001s
//			sys	0m0.160s                sys	0m0.000s

//		printf("%llu\n", fibonacci<utype(13)>);

//			gcc compile time:		gcc run time:
//			                                
//			                                233
//			                                
//			real	1m15.504s               real	0m0.002s
//			user	1m10.839s               user	0m0.001s
//			sys	0m2.786s                sys	0m0.000s
//			                                
//			clang compile time:             clang run time:
//			                                
//			                                233
//			                                
//			real	2m3.677s                real	0m0.001s
//			user	1m58.793s               user	0m0.000s
//			sys	0m3.142s                sys	0m0.001s

//		printf("%llu\n", fibonacci<utype(14)>);

//			gcc compile time:		gcc run time:
//			                                
//			                                static assert error: nesting depth exceeded.
//			                                
//			real	1m21.179s               real	0m0.002s
//			user	1m16.767s               user	0m0.000s
//			sys	0m2.818s                sys	0m0.002s
//			                                
//			clang compile time:             clang run time:
//			                                
//			                                static assert error: nesting depth exceeded.
//			                                
//			real	2m16.306s               real	0m0.002s
//			user	2m12.003s               user	0m0.002s
//			sys	0m3.413s                sys	0m0.000s

//		print_fibonacci<14>(); improved nesting depth:

//			gcc compile time:		gcc run time:
//			                                
//                                                      fibonacci(14): 377
//			                                
//			real	2m6.003s                real	0m0.024s
//			user	1m59.559s               user	0m0.004s
//			sys	0m4.512s                sys	0m0.000s
//			                                
//			clang compile time:             clang run time:
//			                                
//			                                fibonacci(14): 377
//                                                      
//			real	3m42.702s               real	0m0.035s
//			user	3m23.063s               user	0m0.003s
//			sys	0m6.119s                sys	0m0.000s

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register (fixed memory) fibonacci:

/***********************************************************************************************************************/

// for testing:

		template<typename Type>
		constexpr Type _fixed_fib(Type n, bool t, Type a, Type b)
		{
			return	n ? _fixed_fib(n-1, !t, a + (!t ? b : 0), (t ? a : 0) + b) : (t ? a : b);
		}

		template<typename Type>
		constexpr Type fixed_fib(Type n)
		{
			return _fixed_fib(n, false, Type(0), Type(1));
		}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

