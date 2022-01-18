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

// fibonacci:

	#include nik_import(../../.., interpret, cache, architect, v_0_5, gcc, dynamic, name)
	#include nik_import(../../.., interpret, constant, architect, v_0_5, gcc, dynamic, name)
	#include nik_import(../../.., interpret, machine, architect, v_0_5, gcc, dynamic, name)

	using machine_module = nik_module(interpret, machine, architect, v_0_5, gcc); // temporary to call *start*

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

	template<key_type, key_type...> struct T_user_program_fibonacci;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register (naive) fibonacci:

/***********************************************************************************************************************/

	template<>
	struct T_user_program_fibonacci<FN::naive> : public T_user_program
	{
		template
		<
			// registers:

				index_type res			= 0,
				index_type m			= 1,
				index_type n			= 2,
				index_type is_0_or_1		= 3,
				index_type dec1			= 4,
				index_type dec2			= 5,
				index_type add			= 6,
				index_type fib_prog		= 7,

			// labels:

				index_type loop			= 1,
				index_type adj1			= 2,
				index_type adj2			= 3,
				index_type done			= 4
		>
		static constexpr auto lines = controller
		<
			label // loop:
			<
				test     < is_0_or_1 , n                               >,
				branch   < done                                        >,
				adj_call < m         , fib_prog , adj1
				         , res       , m        , n        , is_0_or_1
				         , dec1      , dec2     , add      , fib_prog  >,
				adj_call < n         , fib_prog , adj2
				         , res       , m        , n        , is_0_or_1
				         , dec1      , dec2     , add      , fib_prog  >,
				apply    < res       , add      , m    , n             >,
				value    < res                                         >
			>,

			label // adj1:
			<
				apply    < n         , dec1     , n                    >,
				restart  <                                             >
			>,

			label // adj2:
			<
				apply    < n         , dec2     , n                    >,
				restart  <                                             >
			>,

			label // done:
			<
				value    < res                                         >
			>
		>;
	};

/***********************************************************************************************************************/

	template<typename T>
	static constexpr bool is_0_or_1_value(T n) { return n == 0 || n == 1; }

	template<auto n>
	static constexpr auto f_naive_fibonacci()
	{
		using n_type = decltype(n);

		constexpr n_type res		= _one;
		constexpr n_type m		= _zero;
		constexpr auto is_0_or_1_op	= is_0_or_1_value<n_type>;
		constexpr auto dec1_op		= subtract_by<n_type, n_type{_one}>;
		constexpr auto dec2_op		= subtract_by<n_type, n_type{_two}>;
		constexpr auto add_op		= add<n_type, n_type>;
		constexpr auto fib_prog		= U_type_T<T_user_program_fibonacci<FN::naive>>;

		return machine_module::template start
		<
			T_user_program_fibonacci<FN::naive>,
				res, m, n, is_0_or_1_op, dec1_op, dec2_op, add_op, fib_prog

		>(U_null_Vs);
	}

	template<auto n>
	constexpr auto naive_fibonacci = f_naive_fibonacci<n>();

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

//		printf("%llu\n", fibonacci<utype(13)>); internal call:

//			gcc compile time:		gcc run time:
//			                                
//			                                naive fibonacci(13): 377
//			                                
//			real	0m15.474s               real	0m0.002s
//			user	0m14.695s               user	0m0.003s
//			sys	0m0.750s                sys	0m0.000s
//			                                
//			clang compile time:             clang run time:
//			                                
//			                                naive fibonacci(13): 377
//			                                
//			real	2m48.237s               real	0m0.002s
//			user	2m37.733s               user	0m0.001s
//			sys	0m5.798s                sys	0m0.002s

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

