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

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// functions (local):

	template<typename T, auto V>
	constexpr auto subtract_by(T v) { return v-V; }

	template<typename T1, typename T2>
	constexpr auto add(T1 v1, T2 v2) { return v1+v2; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/


	struct FibonacciNames
	{
		static constexpr key_type naive		= 0;
		static constexpr key_type fast		= 1;
	};

	using FN = FibonacciNames;

	template<key_type, key_type...> struct S_user_fibonacci_contr;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register (naive) fibonacci:

/***********************************************************************************************************************/

	template<>
	struct S_user_fibonacci_contr<FN::naive>
	{
		template
		<
			// registers:

				index_type val			= 0,
				index_type m			= 1,
				index_type n			= 2,
				index_type is_0_or_1		= 3,
				index_type dec			= 4,
				index_type add			= 5,

			// labels:

				index_type loop			= 0,
				index_type done			= 1
		>
		static constexpr auto result = controller
		<
			label // loop:
			<
				test    < is_0_or_1 , n           >,
				branch  < done                    >,
				apply   < n         , dec , n     >,
				recurse < m                       >,
				apply   < n         , dec , n     >,
				recurse < n                       >,
				apply   < val       , add , m , n >,
				stop    < val                     >
			>,

			label // done:
			<
				stop    < val                     >
			>
		>;
	};

/***********************************************************************************************************************/

	template<typename T>
	static constexpr bool is_0_or_1_value(T n) { return n == 0 || n == 1; }

	template<auto n, auto d>
	static constexpr auto f_naive_fibonacci()
	{
		using n_type = decltype(n);

		constexpr auto contr		= S_user_fibonacci_contr<FN::naive>::template result<>;

		constexpr n_type val		= _one;
		constexpr n_type m		= _zero;
		constexpr auto is_0_or_1_op	= is_0_or_1_value<n_type>;
		constexpr auto dec_op		= subtract_by<n_type, n_type{_one}>;
		constexpr auto add_op		= add<n_type, n_type>;

		return start
		<
			register_machine, contr, d,
			val, m, n, is_0_or_1_op, dec_op, add_op
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

