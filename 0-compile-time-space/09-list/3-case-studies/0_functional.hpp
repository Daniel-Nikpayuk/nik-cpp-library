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

// functional:

	#include nik_import(../../.., interpret, store, architect, v_0_5, gcc, dynamic, name)
	#include nik_import(../../.., interpret, constant, architect, v_0_5, gcc, dynamic, name)
	#include nik_import(../../.., interpret, machine, architect, v_0_5, gcc, dynamic, name)

	using machine_module = nik_module(interpret, machine, architect, v_0_5, gcc); // temporary to call *start*

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// names:

/***********************************************************************************************************************/

	struct FunctionalNames
	{
		static constexpr key_type reverse_v0	= 0;
		static constexpr key_type reverse_v1	= 1;

		static constexpr key_type left_v0	= 2;
		static constexpr key_type right_v0	= 3;
		static constexpr key_type merge_v0	= 4;
		static constexpr key_type sort_v0	= 5;
	};

	using FN = FunctionalNames;

	template<key_type, key_type...> struct T_user_program_functional;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// reverse (version 0):

/***********************************************************************************************************************/

	template<>
	struct T_user_program_functional<FN::reverse_v0> : public T_user_program
	{
		template
		<
			// registers:

				index_type front	= 0,

			// lists:

				index_type out_list	= 0,
				index_type in_list	= 1,

			// labels:

				index_type loop		= 1,
				index_type done		= 2
		>
		static constexpr auto lines = controller
		<
			label // loop:
			<
				is_null     < in_list            >,
				branch      < done               >,
				car         < front    , in_list >,
				cons_assign < out_list , front   >,
				cdr_assign  < in_list            >,
				cycle       <                    >
			>,

			label // done:
			<
				argument    < out_list           >
			>
		>;
	};

/***********************************************************************************************************************/

	template<auto list, auto front = _zero>
	constexpr auto reverse_v0 = machine_module::template start
	<
		T_user_program_functional<FN::reverse_v0>, front

	>(U_null_Vs, U_null_Vs, list);

/***********************************************************************************************************************/

// perf:

//		print_reverse_v0< U_pack_Vs<0, 1, 2, 3, 4, 5> >():

//			gcc compile time:		gcc run time:
//			                                
//			                                auto_pack<5, 4, 3, 2, 1, 0>
//			                                
//			real	0m0.987s                real	0m0.002s
//			user	0m0.887s                user	0m0.002s
//			sys	0m0.101s                sys	0m0.001s
//			                                
//			clang compile time:             clang run time:
//			                                
//			                                auto_pack<5, 4, 3, 2, 1, 0>
//			                                
//			real	0m1.425s                real	0m0.003s
//			user	0m1.273s                user	0m0.001s
//			sys	0m0.117s                sys	0m0.002s

/***********************************************************************************************************************/

// convenience functions:

//	template<auto list>
//	void print_reverse_v0() { printf("reverse: %d\n", reverse_v0<list>); }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// functions (local):

/***********************************************************************************************************************/

// is null:

	struct E_is_null
	{
		template<auto... Vs>
		static constexpr bool is_null(nik_avpcr(auto_pack<Vs...>*)) { return (sizeof...(Vs) == 0); }

		template<auto List>
		static constexpr bool result = is_null(List);
	};

	constexpr auto I_is_null = U_store_T<E_is_null>;

/***********************************************************************************************************************/

// cons:

	struct E_cons
	{
		template<auto V, auto... Vs>
		static constexpr auto cons(nik_avpcr(auto_pack<Vs...>*)) { return U_pack_Vs<V, Vs...>; }

		template<auto V, auto List>
		static constexpr auto result = cons<V>(List);
	};

	constexpr auto I_cons = U_store_T<E_cons>;

/***********************************************************************************************************************/

// push:

	struct E_push
	{
		template<auto V, auto... Vs>
		static constexpr auto push(nik_avpcr(auto_pack<Vs...>*)) { return U_pack_Vs<Vs..., V>; }

		template<auto V, auto List>
		static constexpr auto result = push<V>(List);
	};

	constexpr auto I_push = U_store_T<E_push>;

/***********************************************************************************************************************/

// car:

	struct E_car
	{
		template<auto V, auto... Vs>
		static constexpr auto car(nik_avpcr(auto_pack<V, Vs...>*)) { return V; }

		template<auto List>
		static constexpr auto result = car(List);
	};

	constexpr auto I_car = U_store_T<E_car>;

/***********************************************************************************************************************/

// cdr:

	struct E_cdr
	{
		template<auto V, auto... Vs>
		static constexpr auto cdr(nik_avpcr(auto_pack<V, Vs...>*)) { return U_pack_Vs<Vs...>; }

		template<auto List>
		static constexpr auto result = cdr(List);
	};

	constexpr auto I_cdr = U_store_T<E_cdr>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// reverse (version 1):

/***********************************************************************************************************************/

	template<>
	struct T_user_program_functional<FN::reverse_v1> : public T_user_program
	{
		template
		<
			// registers:

				index_type res		= 0,
				index_type list		= 1,
				index_type is_null	= 2,
				index_type push		= 3,
				index_type car		= 4,
				index_type cdr		= 5,
				index_type rev_prog	= 6,

			// labels:

				index_type loop		= 1,
				index_type done		= 2
		>
		static constexpr auto lines = controller
		<
			label // loop:
			<
				check  < is_null  , list                   >,
				branch < done                              >,
				compel < res      , car      , list        >,
				compel < list     , cdr      , list        >,
				call   < list     , rev_prog , res  , list
				       , is_null  , push     , car  , cdr
				       , rev_prog , loop     , done        >,
				compel < list     , push     , res  , list >,
				value  < list                              >
			>,

			label // done:
			<
				value  < list                              >
			>
		>;
	};

/***********************************************************************************************************************/

	template<auto list>
	constexpr auto f_reverse_v1()
	{
		constexpr auto res		= _zero;
		constexpr auto is_null_op	= I_is_null;
		constexpr auto push_op		= I_push;
		constexpr auto car_op		= I_car;
		constexpr auto cdr_op		= I_cdr;
		constexpr auto rev_prog		= U_store_T<T_user_program_functional<FN::reverse_v1>>;

		return machine_module::template start
		<
			T_user_program_functional<FN::reverse_v1>,
				res, list, is_null_op, push_op, car_op, cdr_op, rev_prog
		>(U_null_Vs);
	}

	template<auto list>
	constexpr auto reverse_v1 = f_reverse_v1<list>();

/***********************************************************************************************************************/

// perf:

//		print_reverse_v1< U_pack_Vs<0, 1, 2, 3, 4, 5> >():

//			gcc compile time:		gcc run time:
//			                        	
//			                        	auto_pack<5, 4, 3, 2, 1, 0>
//			                        	
//			real	0m1.859s        	real	0m0.002s
//			user	0m1.764s        	user	0m0.002s
//			sys	0m0.094s        	sys	0m0.001s
//			                        	
//			clang compile time:     	clang run time:
//			                        	
//			                        	auto_pack<5, 4, 3, 2, 1, 0>
//			                        	
//			real	0m3.947s        	real	0m0.002s
//			user	0m3.416s        	user	0m0.002s
//			sys	0m0.350s        	sys	0m0.001s

/***********************************************************************************************************************/

// convenience functions:

//	template<auto list>
//	void print_reverse_v1() { printf("reverse: %d\n", reverse_v1<list>); }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// merge (version 0):

/***********************************************************************************************************************/

	template<>
	struct T_user_program_functional<FN::merge_v0> : public T_user_program
	{
		template
		<
			// registers:

				index_type l_front	= 0,
				index_type r_front	= 1,
				index_type less_than	= 2,

			// lists:

				index_type out_list	= 0,
				index_type left_list	= 1,
				index_type right_list	= 2,

			// labels:

				index_type loop_l	= 1,
				index_type loop_r	= 2,
				index_type done_l	= 3,
				index_type done_r	= 4
		>
		static constexpr auto lines = controller
		<
			label // loop_l:
			<
				is_null     < left_list                         >,
				branch      < done_l                            >,
				is_null     < right_list                        >,
				branch      < done_r                            >,
				car         < l_front    , left_list            >,
				car         < r_front    , right_list           >,
				check       < less_than  , l_front    , r_front >,
				branch      < loop_r                            >,
				push_assign < out_list   , r_front              >,
				cdr_assign  < right_list                        >,
				cycle       <                                   >
			>,

			label // loop_r:
			<
				push_assign < out_list   , l_front              >,
				cdr_assign  < left_list                         >,
				cycle       <                                   >
			>,

			label // done_l:
			<
				cat_assign  < out_list   , right_list           >,
				argument    < out_list                          >
			>,

			label // done_r:
			<
				cat_assign  < out_list   , left_list            >,
				argument    < out_list                          >
			>
		>;
	};

/***********************************************************************************************************************/

	template<auto list1, auto list2, auto less_than>
	static constexpr auto f_merge_v0()
	{
		constexpr auto l_front = _zero;
		constexpr auto r_front = _zero;

		return machine_module::template start
		<
			T_user_program_functional<FN::merge_v0>, l_front, r_front, less_than

		>(U_null_Vs, U_null_Vs, list1, list2);
	}

	template<auto list1, auto list2, auto less_than>
	constexpr auto merge_v0 = f_merge_v0<list1, list2, less_than>();

/***********************************************************************************************************************/

// convenience functions:

//	template<auto list1, auto list2, auto less_than>
//	void print_merge_v0() { printf("merge: %d\n", merge_v0<list1, list2, less_than>); }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// sort (version 0):

/***********************************************************************************************************************/

	template<>
	struct T_user_program_functional<FN::sort_v0> : public T_user_program
	{
		template
		<
			// registers:

				index_type l_front	= 0,
				index_type r_front	= 1,
				index_type less_than	= 2,

			// lists:

				index_type out_list	= 0,
				index_type left_list	= 1,
				index_type right_list	= 2,

			// labels:

				index_type loop_l	= 1,
				index_type loop_r	= 2,
				index_type done_l	= 3,
				index_type done_r	= 4
		>
		static constexpr auto lines = controller
		<
			label // loop_l:
			<
				is_null     < left_list                         >,
				branch      < done_l                            >,
				is_null     < right_list                        >,
				branch      < done_r                            >,
				car         < l_front    , left_list            >,
				car         < r_front    , right_list           >,
				check       < less_than  , l_front    , r_front >,
				branch      < loop_r                            >,
				push_assign < out_list   , r_front              >,
				cdr_assign  < right_list                        >,
				cycle       <                                   >

				call        < res       , fact_prog , adj  , res
				            , n         , is_zero   , dec  , mult
				            , fact_prog , loop      , adj  , done >,
			>,

			label // loop_r:
			<
				push_assign < out_list   , l_front              >,
				cdr_assign  < left_list                         >,
				cycle       <                                   >
			>,

			label // done_l:
			<
				cat_assign  < out_list   , right_list           >,
				argument    < out_list                          >
			>,

			label // done_r:
			<
				cat_assign  < out_list   , left_list            >,
				argument    < out_list                          >
			>
		>;
	};

/***********************************************************************************************************************/

	template<auto list1, auto list2, auto less_than>
	static constexpr auto f_sort_v0()
	{
		constexpr auto l_front = _zero;
		constexpr auto r_front = _zero;

		return machine_module::template start
		<
			T_user_program_functional<FN::sort_v0>, l_front, r_front, less_than

		>(U_null_Vs, U_null_Vs, list1, list2);
	}

	template<auto list1, auto list2, auto less_than>
	constexpr auto sort_v0 = f_sort_v0<list1, list2, less_than>();

/***********************************************************************************************************************/

// convenience functions:

//	template<auto list1, auto list2, auto less_than>
//	void print_sort_v0() { printf("sort: %d\n", sort_v0<list1, list2, less_than>); }

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

