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

	#include nik_import(../../.., interpret, cache, architect, v_0_5, gcc, dynamic, name)
	#include nik_import(../../.., interpret, constant, architect, v_0_5, gcc, dynamic, name)
	#include nik_import(../../.., interpret, machine, architect, v_0_5, gcc, dynamic, name)

	using machine_module = nik_module(interpret, machine, architect, v_0_5, gcc); // temporary to call *start*

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// functions (local):

/***********************************************************************************************************************/

// is null:

	struct E_is_null
	{
		template<auto... Vs>
		static constexpr bool is_null(void(*)(auto_pack<Vs...>*)) { return (sizeof...(Vs) == 0); }

		template<auto List>
		static constexpr bool result = is_null(List);
	};

	constexpr auto I_is_null = U_type_T<E_is_null>;

/***********************************************************************************************************************/

// cons:

	struct E_cons
	{
		template<auto V, auto... Vs>
		static constexpr auto cons(void(*)(auto_pack<Vs...>*)) { return U_pack_Vs<V, Vs...>; }

		template<auto V, auto List>
		static constexpr auto result = cons<V>(List);
	};

	constexpr auto I_cons = U_type_T<E_cons>;

/***********************************************************************************************************************/

// push:

	struct E_push
	{
		template<auto V, auto... Vs>
		static constexpr auto push(void(*)(auto_pack<Vs...>*)) { return U_pack_Vs<Vs..., V>; }

		template<auto V, auto List>
		static constexpr auto result = push<V>(List);
	};

	constexpr auto I_push = U_type_T<E_push>;

/***********************************************************************************************************************/

// car:

	struct E_car
	{
		template<auto V, auto... Vs>
		static constexpr auto car(void(*)(auto_pack<V, Vs...>*)) { return V; }

		template<auto List>
		static constexpr auto result = car(List);
	};

	constexpr auto I_car = U_type_T<E_car>;

/***********************************************************************************************************************/

// cdr:

	struct E_cdr
	{
		template<auto V, auto... Vs>
		static constexpr auto cdr(void(*)(auto_pack<V, Vs...>*)) { return U_pack_Vs<Vs...>; }

		template<auto List>
		static constexpr auto result = cdr(List);
	};

	constexpr auto I_cdr = U_type_T<E_cdr>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// names:

/***********************************************************************************************************************/

	struct FunctionalNames
	{
		static constexpr key_type reverse	= 0;
		static constexpr key_type left		= 1;
		static constexpr key_type right		= 2;
		static constexpr key_type merge		= 3;
		static constexpr key_type sort		= 4;
	};

	using FN = FunctionalNames;

	template<key_type, key_type...> struct T_user_program_functional;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// reverse:

/***********************************************************************************************************************/

	template<>
	struct T_user_program_functional<FN::reverse> : public T_user_program
	{
		template
		<
			// registers:

				index_type val		= 0,
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
				compel < val      , car      , list        >,
				compel < list     , cdr      , list        >,
				call   < list     , rev_prog , val  , list
				       , is_null  , push     , car  , cdr
				       , rev_prog , loop     , done        >,
				compel < list     , push     , val  , list >,
				at     < list                              >
			>,

			label // done:
			<
				at     < list                              >
			>
		>;
	};

/***********************************************************************************************************************/

	template<auto list>
	constexpr auto f_reverse()
	{
		constexpr auto val		= _zero;
		constexpr auto is_null_op	= I_is_null;
		constexpr auto push_op		= I_push;
		constexpr auto car_op		= I_car;
		constexpr auto cdr_op		= I_cdr;
		constexpr auto rev_prog		= U_type_T<T_user_program_functional<FN::reverse>>;

		return machine_module::template start
		<
			T_user_program_functional<FN::reverse>,
				val, list, is_null_op, push_op, car_op, cdr_op, rev_prog
		>();
	}

	template<auto list>
	constexpr auto reverse = f_reverse<list>();

/***********************************************************************************************************************/

// perf:

//		print_reverse< U_pack_Vs<0, 1, 2, 3, 4, 5> >():

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
//	void print_reverse() { printf("reverse(%d): %d\n", list, reverse<list>); }

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

