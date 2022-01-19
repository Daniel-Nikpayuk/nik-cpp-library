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

// routines source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// instructions:

public:

/***********************************************************************************************************************/

// halters:

	// value:

	template<key_type Note>
	static constexpr instr_type _value = instruction // *value* keyword is reserved for user use.
	<
		MN::value, Note
	>;

		template<key_type...> static constexpr instr_type first			= _value < MT::first     >;
		template<key_type...> static constexpr instr_type rest			= _value < MT::rest      >;
		template<key_type...> static constexpr instr_type depth			= _value < MT::depth     >;
		template<key_type...> static constexpr instr_type dump			= _value < MT::dump      >;
		template<key_type...> static constexpr instr_type registers		= _value < MT::registers >;
		template<key_type...> static constexpr instr_type arguments		= _value < MT::arguments >;

		//

		template<key_type...> static constexpr instr_type argument_zero		= _value < MT::a0        >;

// interoperators:

	// call:

		// call instructions are required by the between machine to have mem, loc info.

	template<key_type Note, key_type Subname, key_type Policy, index_type... Args>
	static constexpr instr_type call_program = instruction
	<
		MN::call, Note, Subname, Policy, Args...
	>;

		template<key_type Subname, key_type Policy, index_type Pos, key_type Coname, key_type Conote, key_type BPolicy>
		static constexpr instr_type call_block_program = call_program
		<
			MT::block, Subname, Policy, Pos, Coname, Conote, BPolicy
		>;

		template<key_type Subname, key_type Policy, index_type... Args>
		static constexpr instr_type call_linear_program = call_program
		<
			MT::linear, Subname, Policy, Args...
		>;

		template<index_type Pos, index_type Prog, index_type... Args>
		static constexpr instr_type call = call_program // call user program
		<
			MT::user, MN::id, MT::load, Pos, Prog, T_user_program::initial_i, Args...
		>;

		template<index_type Pos, index_type Prog, index_type Adj, index_type... Args>
		static constexpr instr_type adj_call = call_program // call adjusted user program
		<
			MT::user, MN::call, MT::load, Pos, Prog, Adj, Args...
		>;

	// detour:

	template<key_type Policy>
	static constexpr instr_type detour_call = instruction
	<
		MN::detour, MT::call, MN::id, Policy
	>;

		template<key_type...>
		static constexpr instr_type apply_user__insert_at_r_front = detour_call<CP::insert_at_r_front>;

	// machinate:

	template<key_type Note>
	static constexpr instr_type machinate = instruction
	<
		MN::machinate, Note
	>;

		template<key_type...> static constexpr instr_type pause			= machinate < MT::pause   >;
		template<key_type...> static constexpr instr_type unwind		= machinate < MT::unwind  >;
		template<key_type...> static constexpr instr_type unmake		= machinate < MT::user    >;

// passers:

	// block:

	template<key_type...>
	static constexpr instr_type drop_r_first = instruction	// optimization: We call the single block machine
	<							// directly, but still provide computational context.
		MN::move_r_block, _zero, MT::id, BP::drop
	>;

	// linear:

	template<key_type...>
	static constexpr instr_type move_h0_first__insert_at_r_front = instruction
	<
		MN::move_h0_first, MT::insert_at_r_front
	>;

	template<key_type...>
	static constexpr instr_type move_h1_all__insert_at_r_front = instruction
	<
		MN::move_h1_all, MT::insert_at_r_front
	>;

	// near linear:

	template<index_type...>
	static constexpr instr_type swap__r_and_a0 = instruction
	<
		MN::swap, MT::r_and_a0
	>;

	template<index_type...>
	static constexpr instr_type swap__a0_and_a1 = instruction
	<
		MN::swap, MT::a0_and_a1
	>;

	template<index_type...>
	static constexpr instr_type swap__a0_and_a2 = instruction
	<
		MN::swap, MT::a0_and_a2
	>;

	template<index_type...>
	static constexpr instr_type swap__a1_and_a2 = instruction
	<
		MN::swap, MT::a1_and_a2
	>;

	template<index_type...>
	static constexpr instr_type a0_is_null__insert_at_h0_front = instruction
	<
		MN::a0_is_null, MT::insert_at_h0_front
	>;

	template<index_type...>
	static constexpr instr_type cons_r_a0__replace_at_a0 = instruction
	<
		MN::construct_r_a0, MT::replace_at_a0, FA::cons
	>;

	template<index_type...>
	static constexpr instr_type push_r_a0__replace_at_a0 = instruction
	<
		MN::construct_r_a0, MT::replace_at_a0, FA::push
	>;

	template<index_type...>
	static constexpr instr_type car_a0__insert_at_r_front = instruction
	<
		MN::select_a0, MT::id, FA::car, FP::insert_at_r_front
	>;

	template<index_type...>
	static constexpr instr_type cdr_a0__replace_at_a0 = instruction
	<
		MN::select_a0, MT::id, FA::cdr, FP::replace_at_a0
	>;

	template<index_type Action>
	static constexpr instr_type map_a0__replace_at_a0 = instruction
	<
		MN::select_a0, MT::id, Action, FP::replace_at_a0
	>;

	template<index_type...>
	static constexpr instr_type cat_a0_a1__replace_at_a0 = instruction
	<
		MN::catenate_a0_a1, MT::replace_at_a0
	>;

	template<index_type Action>
	static constexpr instr_type zip_a0_a1__replace_at_a0 = instruction
	<
		MN::zip_a0_a1, MT::replace_at_a0, Action
	>;

	// user:

	template<key_type...>
	static constexpr instr_type cycle = instruction
	<
		MN::go_to, MT::first
	>;

	template<key_type Index>
	static constexpr instr_type branch = instruction
	<
		MN::go_to, MT::conditional, Index
	>;

	template<key_type...>
	static constexpr instr_type apply_h0_all__insert_at_r_front = instruction
	<
		MN::apply_h0_all, MT::insert_at_r_front
	>;

	template<key_type...>
	static constexpr instr_type apply_h0_all__replace_at_h0_front = instruction
	<
		MN::apply_h0_all, MT::replace_at_h0_front
	>;

	template<key_type...>
	static constexpr instr_type compel_h0_all__insert_at_r_front = instruction
	<
		MN::compel_h0_all, MT::insert_at_r_front
	>;

	template<key_type...>
	static constexpr instr_type compel_h0_all__replace_at_h0_front = instruction
	<
		MN::compel_h0_all, MT::replace_at_h0_front
	>;

	// optimizations:

	template<key_type Note, key_type Pos>
	static constexpr instr_type copy_r_pos = instruction
	<
		MN::copy_r_pos, Note, Pos
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block:

	// Block programs consist of two block instructions and some machine
	// modifiers: As such they can be optimized into a single instruction.

/***********************************************************************************************************************/

// unpack instruction segment (, insert at heap one back):

	template<key_type... filler>
	struct block_program<BN::unpack_i_segment, filler...> : public block_program<filler...>
	{
		template<key_type Coname, key_type Conote, key_type BPolicy>
		static constexpr instr_type lines = instruction
		<
			MN::unpack_i_block, Coname, Conote, BPolicy
		>;
	};

	// interface:

		template<key_type Conote>
		static constexpr instr_type bind_program = block_program<BN::unpack_i_segment>::template lines
		<
			MN::machinate, Conote, BP::insert_at_h1_back
		>;

	// syntactic sugar:

		template<key_type...> static constexpr instr_type bind_linear_program	= bind_program < MT::linear >;
		template<key_type...> static constexpr instr_type bind_user_program	= bind_program < MT::user1  >;

/***********************************************************************************************************************/

// move register segment:

	template<key_type... filler>
	struct block_program<BN::move_r_segment, filler...> : public block_program<filler...>
	{
		template<key_type Coname, key_type Conote, key_type BPolicy>
		static constexpr instr_type lines = instruction
		<
			MN::move_r_block, Coname, Conote, BPolicy
		>;
	};

	// interface:

		template<key_type Policy, index_type Pos, key_type Coname, key_type Conote>
		static constexpr instr_type drop_r_segment = call_block_program
		<
			BN::move_r_segment,
			Policy,
			Pos,
			Coname, Conote,
			BP::drop
		>;

		//	template<key_type Policy, index_type Pos>
		//	static constexpr instr_type left = drop_r_segment
		//	<
		//		Policy,
		//		Pos,
		//		MN::value, MT::heap_one
		//	>;

		//	template<key_type Policy, index_type Pos>
		//	static constexpr instr_type right = drop_r_segment
		//	<
		//		Policy,
		//		Pos,
		//		MN::value, MT::registers
		//	>;

		template<index_type Pos>
		static constexpr instr_type move_r_segment__insert_at_h1_back = call_block_program
		<
			BN::move_r_segment,
			CP::load,
			Pos,
			MN::machinate, MT::unwind,
			BP::insert_at_h1_back
		>;

	// syntactic sugar:

		template<index_type Pos>
		static constexpr instr_type value = drop_r_segment
		<
			CP::id, // return the value
			Pos,
			MN::value, MT::first
		>;

			template<key_type Note, index_type Pos>
			static constexpr auto dispatch_copy_r_pos()
			{
				if constexpr (MI::is_opt(Pos)) return copy_r_pos<Note, Pos>;
				else
				{
					constexpr auto policy = (Note == MT::insert_at_h0_front) ?
								 CP::insert_at_h0_front          :
								 CP::insert_at_h0_back           ;

					return drop_r_segment<policy, Pos, MN::value, MT::first>;
				}
			}

		template<index_type Pos>
		static constexpr instr_type copy_r_pos__insert_at_h0_front = dispatch_copy_r_pos<MT::insert_at_h0_front, Pos>();

		template<index_type Pos>
		static constexpr instr_type copy_r_pos__insert_at_h0_back = dispatch_copy_r_pos<MT::insert_at_h0_back, Pos>();

/***********************************************************************************************************************/

// fold register segment:

	template<key_type... filler>
	struct block_program<BN::fold_r_segment, filler...> : public block_program<filler...>
	{
		template<key_type Coname, key_type Conote, key_type BPolicy>
		static constexpr instr_type lines = instruction
		<
			MN::fold_r_block, Coname, Conote, BPolicy
		>;
	};

	// syntactic sugar:

		template<index_type Pos>
		static constexpr instr_type fold_r_segment__op_at_h0_first = call_block_program
		<
			BN::fold_r_segment,
			CP::id, // return the value
			Pos,
			MN::value, MT::first,
			BP::op_at_h0_first
		>;

		template<index_type Pos>
		static constexpr instr_type fold_r_segment__act_at_h0_first = call_block_program
		<
			BN::fold_r_segment,
			CP::id, // return the value
			Pos,
			MN::value, MT::first,
			BP::act_at_h0_first
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear:

/***********************************************************************************************************************/

// swap argument zero and:

		template<index_type Arg>
		static constexpr auto dispatch_swap_a0_and()
		{
			if constexpr (Arg == 1) return swap__a0_and_a1<>;
			else                    return swap__a0_and_a2<>;
		}

	template<index_type Arg>
	static constexpr auto swap_a0_and = dispatch_swap_a0_and<Arg>();

		template<index_type Arg>
		static constexpr auto U_dispatch_swap_a0_and()
		{
			if constexpr (Arg == 0) return U_null_Vs;
			else                    return U_opt_pack_Vs<dispatch_swap_a0_and<Arg>()>;
		}

	template<index_type Arg>
	static constexpr auto U_swap_a0_and = U_dispatch_swap_a0_and<Arg>();

/***********************************************************************************************************************/

// dispatch linear:

	template
	<
		index_type Arg, auto action,
		key_type Name, key_type Policy, key_type... Params
	>
	static constexpr auto dispatch_linear()
	{
		if constexpr (Arg == 0)	return action;
		else			return call_linear_program<Name, Policy, Arg, Params...>;
	}

/***********************************************************************************************************************/

// dispatch construct:

	template<index_type Arg, index_type Obj, auto action_r_a0__replace_at_a0>
	static constexpr auto dispatch_construct()
	{
		return ML::safe_label
		(
			U_opt_pack_Vs < copy_r_pos__insert_at_h0_back<Obj> >,
			U_swap_a0_and < Arg                                >,
			U_opt_pack_Vs < action_r_a0__replace_at_a0         >,
			U_swap_a0_and < Arg                                >,
			U_opt_pack_Vs < unwind<>                           >
		);
	}

/***********************************************************************************************************************/

// argument position:

	template<key_type... filler>
	struct linear_program<LN::a_pos, filler...> : public T_linear_program
	{
		template<index_type Arg>
		static constexpr label_type lines = label
		<
			swap_a0_and<Arg>,
			argument_zero<>
		>;
	};

	// interface:

		template<index_type Arg>
		static constexpr instr_type argument = dispatch_linear
		<
			Arg,
			argument_zero<>,
			LN::a_pos,
			CP::id
		>();

/***********************************************************************************************************************/

// argument position is null, insert at heap zero front:

	template<key_type... filler>
	struct linear_program<LN::a_pos_is_null__insert_at_h0_front, filler...> : public T_linear_program
	{
		template<index_type Arg>
		static constexpr label_type lines = label
		<
			swap_a0_and<Arg>,
			a0_is_null__insert_at_h0_front<>,
			swap_a0_and<Arg>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Arg>
		static constexpr instr_type is_null = dispatch_linear
		<
			Arg,
			a0_is_null__insert_at_h0_front<>,
			LN::a_pos_is_null__insert_at_h0_front,
			CP::load
		>();

/***********************************************************************************************************************/

// cons register position argument position, replace at argument position:

	template<key_type... filler>
	struct linear_program<LN::cons_r_pos_a_pos__replace_at_a_pos, filler...> : public T_linear_program
	{
		template<index_type Arg, index_type Obj>
		static constexpr label_type lines = dispatch_construct
		<
			Arg, Obj,
			cons_r_a0__replace_at_a0<>
		>();
	};

	// interface:

		template<index_type Arg, index_type Obj>
		static constexpr instr_type cons_assign = call_linear_program
		<
			LN::cons_r_pos_a_pos__replace_at_a_pos,
			CP::load,
			Arg, Obj
		>;

/***********************************************************************************************************************/

// push register position argument position, replace at argument position:

	template<key_type... filler>
	struct linear_program<LN::push_r_pos_a_pos__replace_at_a_pos, filler...> : public T_linear_program
	{
		template<index_type Arg, index_type Obj>
		static constexpr label_type lines = dispatch_construct
		<
			Arg, Obj,
			push_r_a0__replace_at_a0<>
		>();
	};

	// interface:

		template<index_type Arg, index_type Obj>
		static constexpr instr_type push_assign = call_linear_program
		<
			LN::push_r_pos_a_pos__replace_at_a_pos,
			CP::load,
			Arg, Obj
		>;

/***********************************************************************************************************************/

// car argument position, insert at register front:

	template<key_type... filler>
	struct linear_program<LN::car_a_pos__replace_at_r_pos, filler...> : public T_linear_program
	{
		template<index_type Pos, index_type Arg>
		static constexpr label_type lines = ML::safe_label
		(
			U_opt_pack_Vs
			<
				move_r_segment__insert_at_h1_back<Pos>,
				drop_r_first<>
			>,
			U_swap_a0_and < Arg                             >,
			U_opt_pack_Vs < car_a0__insert_at_r_front<>     >,
			U_swap_a0_and < Arg                             >,
			U_opt_pack_Vs
			<
				move_h1_all__insert_at_r_front<>,
				unwind<>
			>
		);
	};

	// interface:

		template<index_type Pos, index_type Arg>
		static constexpr instr_type car = call_linear_program
		<
			LN::car_a_pos__replace_at_r_pos,
			CP::load,
			Pos, Arg
		>;

/***********************************************************************************************************************/

// cdr argument position, replace at argument position:

	template<key_type... filler>
	struct linear_program<LN::cdr_a_pos__replace_at_a_pos, filler...> : public T_linear_program
	{
		template<index_type Arg>
		static constexpr label_type lines = label
		<
			swap_a0_and<Arg>,
			cdr_a0__replace_at_a0<>,
			swap_a0_and<Arg>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Arg>
		static constexpr instr_type cdr_assign = dispatch_linear
		<
			Arg,
			cdr_a0__replace_at_a0<>,
			LN::cdr_a_pos__replace_at_a_pos,
			CP::load
		>();

/***********************************************************************************************************************/

// map argument position, replace at argument position:

	template<key_type... filler>
	struct linear_program<LN::map_a_pos__replace_at_a_pos, filler...> : public T_linear_program
	{
		template<index_type Arg, key_type Action>
		static constexpr label_type lines = label
		<
			swap_a0_and<Arg>,
			map_a0__replace_at_a0<Action>,
			swap_a0_and<Arg>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Arg, key_type Action>
		static constexpr instr_type map_assign = dispatch_linear
		<
			Arg,
			map_a0__replace_at_a0<Action>,
			LN::map_a_pos__replace_at_a_pos,
			CP::load,
			Action
		>();

	// syntactic sugar:

		template<index_type Arg> static constexpr instr_type op_map_assign	= map_assign<Arg, FA::op_map>;
		template<index_type Arg> static constexpr instr_type act_map_assign	= map_assign<Arg, FA::act_map>;

/***********************************************************************************************************************/

// catenate argument zero argument two, replace at argument zero:

/*
	template<key_type... filler>
	struct linear_program<LN::cat_a_pos_a_pos__replace_at_a_pos, filler...> : public T_linear_program
	{
		template<index_type Pos, index_type Arg>
		static constexpr label_type lines = label
		<
			rotate_forward<Pos>,
			swap_forward<Arg>,
			cat_a0_a1__replace_at_a0<>,
			swap__backward<Arg>,
			rotate_backward<Pos>,
			unwind<>
		>;
	};

	// interface:

			template<index_type Pos, index_type Arg>
			static constexpr auto dispatch_cat_assign()
			{
				if constexpr (Arg == 1)	return cat_a0_a1__replace_at_a0<>;
				else			return call_linear_program
							<
								LN::cat_a0_a2__replace_at_a0,
								CP::load
							>;
			}

		template<index_type Pos, index_type Arg>
		static constexpr instr_type cat_assign = dispatch_cat_assign<Pos, Arg>();
*/

/***********************************************************************************************************************/

// zip argument zero argument two, replace at argument zero:

/*
	template<key_type... filler>
	struct linear_program<LN::zip_a0_a2__replace_at_a0, filler...> : public T_linear_program
	{
		template<key_type Action>
		static constexpr label_type lines = label
		<
			swap__a1_and_a2<>,
			zip_a0_a1__replace_at_a0<Action>,
			swap__a1_and_a2<>,
			unwind<>
		>;
	};

	// interface:

			template<index_type Pos, index_type Arg, key_type Action>
			static constexpr auto dispatch_zip_assign()
			{
				if constexpr (Pos == 0)
				{
					if constexpr (Arg == 1)

						return zip_a0_a1__replace_at_a0<Action>;

					else
						return call_linear_program
						<
							LN::zip_a_pos_a_pos__replace_at_a_pos,
							CP::load,
							Pos, Arg, Action
						>;
				}
				else
					return call_linear_program
					<
						LN::zip_a_pos_a_pos__replace_at_a_pos,
						CP::load,
						Pos, Arg, Action
					>;
			}

		template<index_type Pos, index_type Arg>
		static constexpr instr_type op_zip_assign	= dispatch_zip_assign<Pos, Arg, FA::op_zip>();

		template<index_type Pos, index_type Arg>
		static constexpr instr_type act_zip_assign	= dispatch_zip_assign<Pos, Arg, FA::act_zip>();
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// mutators:

/***********************************************************************************************************************/

// erase:

	template<key_type... filler>
	struct linear_program<LN::erase, filler...> : public linear_program<filler...>
	{
		template<index_type Pos>
		static constexpr label_type lines = label
		<
			move_r_segment__insert_at_h1_back<Pos>,
			drop_r_first<>,
			move_h1_all__insert_at_r_front<>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Pos>
		static constexpr instr_type erase = call_linear_program
		<
			LN::erase,
			CP::load,
			Pos
		>;

/***********************************************************************************************************************/

// insert:

	template<key_type... filler>
	struct linear_program<LN::insert, filler...> : public T_linear_program
	{
		template<index_type Pos, index_type Obj>
		static constexpr label_type lines = label
		<
			copy_r_pos__insert_at_h0_front<Obj>,
			move_r_segment__insert_at_h1_back<Pos>,
			move_h0_first__insert_at_r_front<>,
			move_h1_all__insert_at_r_front<>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Pos, index_type Obj>
		static constexpr instr_type insert = call_linear_program
		<
			LN::insert,
			CP::load,
			Pos, Obj
		>;

/***********************************************************************************************************************/

// replace:

	template<key_type... filler>
	struct linear_program<LN::replace, filler...> : public T_linear_program
	{
		template<index_type Pos, index_type Obj>
		static constexpr label_type lines = label
		<
			copy_r_pos__insert_at_h0_front<Obj>,
			move_r_segment__insert_at_h1_back<Pos>,
			drop_r_first<>,
			move_h0_first__insert_at_r_front<>,
			move_h1_all__insert_at_r_front<>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Pos, index_type Obj>
		static constexpr instr_type replace = call_linear_program
		<
			LN::replace,
			CP::load,
			Pos, Obj
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// user:

/***********************************************************************************************************************/

// make:

	template<key_type... filler>
	struct linear_program<LN::make, filler...> : public T_linear_program
	{
		template<index_type Prog>
		static constexpr label_type lines = label
		<
			copy_r_pos__insert_at_h0_back<Prog>,
			unmake<>
		>;
	};

	// interface:

		template<index_type Prog>
		static constexpr label_type make_user_program = linear_program<LN::make>::template lines<Prog>;

/***********************************************************************************************************************/

// run:

	template<key_type... filler>
	struct linear_program<LN::run, filler...> : public T_linear_program
	{
		template<index_type Pos>
		static constexpr label_type lines = label
		<
			move_r_segment__insert_at_h1_back<Pos>,
			drop_r_first<>,
			apply_user__insert_at_r_front<>,
			move_h1_all__insert_at_r_front<>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Pos>
		static constexpr label_type run_user_program = linear_program<LN::run>::template lines<Pos>;

/***********************************************************************************************************************/

// test:

	template<key_type... filler>
	struct linear_program<LN::test, filler...> : public T_linear_program
	{
		template<index_type Op, index_type... Args>
		static constexpr label_type lines = label
		<
			copy_r_pos__insert_at_h0_back<Op>,
			copy_r_pos__insert_at_h0_back<Args>...,
			apply_h0_all__replace_at_h0_front<>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Op, index_type... Args>
		static constexpr instr_type test = call_linear_program
		<
			LN::test,
			CP::load,
			Op, Args...
		>;

/***********************************************************************************************************************/

// check:

	template<key_type... filler>
	struct linear_program<LN::check, filler...> : public T_linear_program
	{
		template<index_type Op, index_type... Args>
		static constexpr label_type lines = label
		<
			copy_r_pos__insert_at_h0_back<Op>,
			copy_r_pos__insert_at_h0_back<Args>...,
			compel_h0_all__replace_at_h0_front<>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Op, index_type... Args>
		static constexpr instr_type check = call_linear_program
		<
			LN::check,
			CP::load,
			Op, Args...
		>;

/***********************************************************************************************************************/

// apply:

	template<key_type... filler>
	struct linear_program<LN::apply, filler...> : public T_linear_program
	{
		template<index_type Pos, index_type Op, index_type... Args>
		static constexpr label_type lines = label
		<
			copy_r_pos__insert_at_h0_back<Op>,
			copy_r_pos__insert_at_h0_back<Args>...,
			move_r_segment__insert_at_h1_back<Pos>,
			drop_r_first<>,
			apply_h0_all__insert_at_r_front<>,
			move_h1_all__insert_at_r_front<>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Pos, index_type Op, index_type... Args>
		static constexpr instr_type apply = call_linear_program
		<
			LN::apply,
			CP::load,
			Pos, Op, Args...
		>;

/***********************************************************************************************************************/

// compel:

	template<key_type... filler>
	struct linear_program<LN::compel, filler...> : public T_linear_program
	{
		template<index_type Pos, index_type Op, index_type... Args>
		static constexpr label_type lines = label
		<
			copy_r_pos__insert_at_h0_back<Op>,
			copy_r_pos__insert_at_h0_back<Args>...,
			move_r_segment__insert_at_h1_back<Pos>,
			drop_r_first<>,
			compel_h0_all__insert_at_r_front<>,
			move_h1_all__insert_at_r_front<>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Pos, index_type Op, index_type... Args>
		static constexpr instr_type compel = call_linear_program
		<
			LN::compel,
			CP::load,
			Pos, Op, Args...
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

