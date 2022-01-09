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

	#include nik_import(../../.., interpret, cache, architect, v_0_5, gcc, dynamic, name)
	#include nik_import(../../.., interpret, constant, architect, v_0_5, gcc, dynamic, name)
	#include nik_import(../../.., interpret, machine, architect, v_0_5, gcc, dynamic, name)

	using machine_module = nik_module(interpret, machine, architect, v_0_5, gcc); // temporary to call *start*

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// functions (local):

	template<typename T, auto V>
	constexpr auto is_value(T v) { return (v == V); }

	template<typename T, auto V>
	constexpr auto subtract_by(T v) { return v-V; }

	template<typename T1, typename T2>
	constexpr auto multiply(T1 v1, T2 v2) { return v1*v2; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// names:

/***********************************************************************************************************************/

	struct FactorialNames
	{
		static constexpr key_type naive		= 0;
		static constexpr key_type fast		= 1;
	};

	using FN = FactorialNames;

	template<key_type, key_type...> struct T_user_program_factorial;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register (naive) factorial:

/***********************************************************************************************************************/

	template<>
	struct T_user_program_factorial<FN::naive> : public T_user_program
	{
		template<auto... Args> static constexpr auto loop_label = label<Args...>;
		template<auto... Args> static constexpr auto  adj_label = label<Args...>;
		template<auto... Args> static constexpr auto done_label = label<Args...>;

		template
		<
			// registers:

				index_type val		= 0,
				index_type n		= 1,
				index_type is_zero	= 2,
				index_type dec		= 3,
				index_type mult		= 4,
				index_type fact_prog	= 5,

			// labels:

				index_type loop		= 1,
				index_type adj		= 2,
				index_type done		= 3
		>
		static constexpr auto lines = controller
		<
			loop_label
			<
				test     < is_zero   , n                       >,
				branch   < done                                >,
				adj_call < val       , fact_prog , adj  , val
					 , n         , is_zero   , dec  , mult
					 , fact_prog , loop      , adj  , done >,
				apply    < val       , mult      , n    , val  >,
				at       < val                                 >
			>,

			adj_label
			<
				apply    < n         , dec       , n           >,
				recurse  <                                     >
			>,

			done_label
			<
				at       < val                                 >
			>
		>;
	};

/***********************************************************************************************************************/

	template<auto n>
	constexpr auto f_naive_factorial()
	{
		using n_type = decltype(n);

		constexpr n_type val		= _one;
		constexpr auto is_zero_op	= is_value<n_type, n_type{_zero}>;
		constexpr auto dec_op		= subtract_by<n_type, n_type{_one}>;
		constexpr auto mult_op		= multiply<n_type, n_type>;
		constexpr auto fact_prog	= U_type_T<T_user_program_factorial<FN::naive>>;

		return machine_module::template start
		<
			T_user_program_factorial<FN::naive>,
				val, n, is_zero_op, dec_op, mult_op, fact_prog
		>();
	}

	template<auto n>
	constexpr auto naive_factorial = f_naive_factorial<n>();

/*
	template<auto n, auto d>
	constexpr auto f_naive_factorial()
	{
		using n_type = decltype(n);

		constexpr auto contr		= S_user_factorial_contr<FN::naive>::template result<>;

		constexpr n_type val		= _one;
		constexpr auto is_zero_op	= is_value<n_type, n_type{_zero}>;
		constexpr auto dec_op		= subtract_by<n_type, n_type{_one}>;
		constexpr auto mult_op		= multiply<n_type, n_type>;

		return start
		<
			register_machine, contr, d,
			val, n, is_zero_op, dec_op, mult_op
		>();
	}

	template<auto n, depth_type d = 500>
	constexpr auto naive_factorial = f_naive_factorial<n, d>();
*/

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

// off by one (user) factorial controller:

/***********************************************************************************************************************/

/*
	template
	<
		// registers:

			index_type val		= 0,
			index_type n		= 1,
			index_type is_zero	= 2,
			index_type dec		= 3,
			index_type mult		= 4,
			index_type algo		= 5,

		// labels:

			index_type done		= 0
	>
	constexpr auto off_by_one_factorial_contr = controller
	<
		label // done:
		<
			user    < FN::naive, algo , val , val , n , is_zero , dec , mult >,
			apply   < val      , dec  , val                                  >,
			stop    < val                                                    >
		>
	>;
*/

/***********************************************************************************************************************/

/*
	template<auto n, auto d>
	constexpr auto f_off_by_one_factorial()
	{
		using n_type = decltype(n);

		constexpr auto contr		= off_by_one_factorial_contr<>;

		constexpr n_type val		= _one;
		constexpr auto is_zero_op	= is_value<n_type, n_type{_zero}>;
		constexpr auto dec_op		= subtract_by<n_type, n_type{_one}>;
		constexpr auto mult_op		= multiply<n_type, n_type>;
		constexpr auto algo		= U_pack_Bs<S_user_factorial_contr>;

		return start
		<
			register_machine, contr, d,
			val, n, is_zero_op, dec_op, mult_op, algo
		>();
	}

	template<auto n, depth_type d = 500>
	constexpr auto off_by_one_factorial = f_off_by_one_factorial<n, d>();
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register (pair) factorial:

/***********************************************************************************************************************/

/*
	template<>
	struct S_user_factorial_contr<FN::fast>
	{
		template
		<
			// registers:

				index_type p		= 0,
				index_type n		= 1,
				index_type is_zero	= 2,
				index_type dec		= 3,
				index_type mult		= 4,

			// labels:

				index_type loop		= 0,
				index_type done		= 1
		>
		static constexpr auto lines = controller
		<
			label // loop:
			<
				test       < is_zero , n            >,
				branch     < done                   >,
				apply      < p       , mult , p , n >,
				apply      < n       , dec      , n >,
				goto_label < loop                   >
			>,

			label // done:
			<
				stop       < p                      >
			>
		>;
	};
*/

/***********************************************************************************************************************/

/*
	template<auto n, auto d>
	constexpr auto f_fast_factorial()
	{
		using n_type = decltype(n);

		constexpr auto contr		= S_user_factorial_contr<FN::fast>::template result<>;

		constexpr n_type p		= _one;
		constexpr auto is_zero_op	= is_value<n_type, n_type{_zero}>;
		constexpr auto dec_op		= subtract_by<n_type, n_type{_one}>;
		constexpr auto mult_op		= multiply<n_type, n_type>;

		return start
		<
			register_machine, contr, d,
			p, n, is_zero_op, dec_op, mult_op
		>();
	}

	template<auto n, depth_type d = 500>
	constexpr auto fast_factorial = f_fast_factorial<n, d>();
*/

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

