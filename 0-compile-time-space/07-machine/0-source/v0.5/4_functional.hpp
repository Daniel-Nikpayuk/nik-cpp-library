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

// functional source:

private:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// instructions:

/***********************************************************************************************************************/

	struct FunctionalInstr : public MachineInstr
	{
		static constexpr index_type action				= 3;
		static constexpr index_type policy				= 4;
	};

	using FI = FunctionalInstr;

/***********************************************************************************************************************/

// actions:

	struct FunctionalAction
	{
		static constexpr key_type id					=  0;
		static constexpr key_type identity				= id; // convenience for
										      // default params.

		static constexpr index_type cons				=  2;
		static constexpr index_type push				=  3;
		static constexpr index_type car					=  4;
		static constexpr index_type cdr					=  5;

		static constexpr index_type op_map				=  6;
		static constexpr index_type act_map				=  7;

		static constexpr index_type op_zip				=  8;
		static constexpr index_type act_zip				=  9;
	};

	using FA = FunctionalAction;

/***********************************************************************************************************************/

// policies:

	struct FunctionalPolicy
	{
		static constexpr key_type id					=  0;
		static constexpr key_type identity				= id; // convenience for
										      // default params.

		static constexpr key_type insert_at_r_front			=  1;
		static constexpr key_type replace_at_a0				=  2;
	};

	using FP = FunctionalPolicy;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block:

	// Block programs consist of two block instructions and some machine
	// modifiers: As such they can be optimized into a single instruction.

/***********************************************************************************************************************/

// names:

	struct BlockName
	{
		static constexpr key_type id					=  0;
		static constexpr key_type identity				= id; // convenience for
										      // default params.
		static constexpr key_type unpack_i_segment			=  1;
		static constexpr key_type move_r_segment			=  2;
		static constexpr key_type move_r_large_segment			=  3;
		static constexpr key_type fold_r_large_segment			=  4;

		static constexpr key_type move_a_segment			=  5;
		static constexpr key_type move_a_large_segment			=  6;
		static constexpr key_type catenate_a_large_segment		=  7;
		static constexpr key_type map_a_large_segment			=  8;
		static constexpr key_type zip_a_large_segment			=  9;
	};

	using BN = BlockName;

/***********************************************************************************************************************/

// programs:

	template<key_type...>
	struct large_block_program : public block_program<>
	{
		static constexpr index_type max_note(index_type n)
		{
			return	(n >= _2_9) ? 9 :
				(n >= _2_8) ? 8 :
				(n >= _2_7) ? 7 :
				(n >= _2_6) ? 6 :
				(n >= _2_5) ? 5 :
				(n >= _2_4) ? 4 :
				(n >= _2_3) ? 3 :
				(n >= _2_2) ? 2 :
				(n >= _2_1) ? 1 : 0 ;
		}

		static constexpr index_type max_index2(index_type n)
		{
			return	(n >= _2_9) ? _2_9 :
				(n >= _2_8) ? _2_8 :
				(n >= _2_7) ? _2_7 :
				(n >= _2_6) ? _2_6 :
				(n >= _2_5) ? _2_5 :
				(n >= _2_4) ? _2_4 :
				(n >= _2_3) ? _2_3 :
				(n >= _2_2) ? _2_2 :
				(n >= _2_1) ? _2_1 :
				(n >= _2_0) ? _2_0 : 0 ;
		}
	};

	using T_large_block_program			= large_block_program<>;
	static constexpr auto U_large_block_program	= U_type_T<large_block_program<>>;

/***********************************************************************************************************************/

// move register large segment:

	template<key_type... filler>
	struct block_program<BN::move_r_large_segment, filler...> : public large_block_program<filler...>
	{
		template<key_type Coname, key_type Conote, key_type BPolicy>
		static constexpr instr_type lines = instruction
		<
			MN::move_r_block, Coname, Conote, BPolicy
		>;
	};

	// interface:

		template<index_type Pos, key_type Conote>
		static constexpr instr_type drop_r_large_segment = call_block_program
		<
			BN::move_r_large_segment,
			CP::id, // return the value
			Pos,
			MN::value, Conote,
			BP::drop
		>;

		template<index_type Pos>
		static constexpr instr_type move_r_large_segment__insert_at_h1_back = call_block_program
		<
			BN::move_r_large_segment,
			CP::load,
			Pos,
			MN::machinate, MT::unwind,
			BP::insert_at_h1_back
		>;

	// syntactic sugar:

		template<index_type Pos> static constexpr instr_type at = drop_r_large_segment<Pos, MT::first>;
		template<index_type Pos> static constexpr instr_type left = drop_r_large_segment<Pos, MT::h1>;
		template<index_type Pos> static constexpr instr_type right = drop_r_large_segment<Pos, MT::registers>;

		// how to do a regstr_left, regstr_right where the pos is first gotten from the register?
		// program calls which get the values from h0 directly!

		// Nope! With user programs (at least), you can designate a register as the location of a program
		// to create. You don't actually need to start it with that program, you can create it along
		// the way!

/***********************************************************************************************************************/

// fold register large segment:

	template<key_type... filler>
	struct block_program<BN::fold_r_large_segment, filler...> : public large_block_program<filler...>
	{
		template<key_type Coname, key_type Conote, key_type BPolicy>
		static constexpr instr_type lines = instruction
		<
			MN::fold_r_block, Coname, Conote, BPolicy
		>;
	};

	// interface:

		// The qualifier is ignored in the name as it is assumed "large".

		template<index_type Pos, key_type BPolicy>
		static constexpr instr_type fold_r_segment = call_block_program
		<
			BN::fold_r_large_segment,
			CP::id, // return the value
			Pos,
			MN::value, MT::first,
			BPolicy
		>;

	// syntactic sugar:

		template<index_type Pos>
		static constexpr instr_type fold_r_segment__op_at_h0_first = fold_r_segment
		<
			Pos, BP::op_at_h0_first
		>;

		template<index_type Pos>
		static constexpr instr_type fold_r_segment__act_at_h0_first = fold_r_segment
		<
			Pos, BP::act_at_h0_first
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear:

/***********************************************************************************************************************/

// names:

	struct LinearName
	{
			static constexpr key_type id					=  0;
			static constexpr key_type identity				= id; // convenience for
											      // default params.

		// near linear:

		// mutators:

			static constexpr key_type erase					=  1;
			static constexpr key_type insert				=  2;
			static constexpr key_type replace				=  3;

		// user:

			static constexpr key_type make					=  4;
			static constexpr key_type run					=  5;

			static constexpr key_type test					=  6;
			static constexpr key_type check					=  7;

			static constexpr key_type apply					=  8;
			static constexpr key_type compel				=  9;
	};

	using LN = LinearName;

/***********************************************************************************************************************/

// swap (one):

		template<index_type Arg>
		static constexpr auto dispatch_swap1()
		{
			if constexpr (Arg == 1) return swap__a0_and_a1<>;
			else                    return swap__a0_and_a2<>;
		}

	template<index_type Arg>
	static constexpr auto swap1 = dispatch_swap1<Arg>();

		template<index_type Arg>
		static constexpr auto U_dispatch_swap1()
		{
			if constexpr (Arg == 0) return U_null_Vs;
			else                    return U_opt_pack_Vs<dispatch_swap1<Arg>()>;
		}

	template<index_type Arg>
	static constexpr auto U_swap1 = U_dispatch_swap1<Arg>();

/***********************************************************************************************************************/

// swap (two):

		template<index_type Pos, index_type Arg, bool is_f>
		static constexpr auto U_dispatch_swap2()
		{
			if constexpr (Pos == 0)
			{
				if constexpr (Arg == 1)		return U_null_Vs; // 2:
				else				return U_opt_pack_Vs<swap__a1_and_a2<>>;
			}
			else if constexpr (Pos == 1)
			{
				if constexpr (Arg == 0)		return U_opt_pack_Vs<swap__a0_and_a1<>>;
				else if constexpr (is_f)	return U_opt_pack_Vs // 2, f:
								<
									swap__a0_and_a1<>,
									swap__a1_and_a2<>
								>;
				else				return U_opt_pack_Vs // 2, b:
								<
									swap__a1_and_a2<>,
									swap__a0_and_a1<>
								>;
			}
			else // 2:
			{
				if constexpr (Arg == 1)		return U_opt_pack_Vs<swap__a0_and_a2<>>;
				else if constexpr (is_f)	return U_opt_pack_Vs // 0, f:
								<
									swap__a0_and_a2<>,
									swap__a1_and_a2<>
								>;
				else				return U_opt_pack_Vs // 0, b:
								<
									swap__a1_and_a2<>,
									swap__a0_and_a2<>
								>;
			}
		}

	template<index_type Pos, index_type Arg>
	static constexpr auto U_fswap2 = U_dispatch_swap2<Pos, Arg, true>();

	template<index_type Pos, index_type Arg>
	static constexpr auto U_bswap2 = U_dispatch_swap2<Pos, Arg, false>();

/***********************************************************************************************************************/

// dispatch linear (one):

	template
	<
		index_type Arg, auto action,
		key_type Name, key_type Policy, key_type... Params
	>
	static constexpr auto dispatch_linear1()
	{
		if constexpr (Arg == 0)	return action;
		else			return call_linear_program<Name, Policy, Arg, Params...>;
	}

/***********************************************************************************************************************/

// dispatch linear (two):

	template
	<
		index_type Pos, index_type Arg, auto action,
		key_type Name, key_type Policy, key_type... Params
	>
	static constexpr auto dispatch_linear2()
	{
		if constexpr (Pos == 0 && Arg == 1)	return action;
		else					return call_linear_program<Name, Policy, Pos, Arg, Params...>;
	}

/***********************************************************************************************************************/

// dispatch construct:

	template<index_type Arg, index_type Obj, auto action_r_a0__replace_at_a0>
	static constexpr auto dispatch_construct()
	{
		return ML::safe_label
		(
			U_opt_pack_Vs < copy_r_pos__insert_at_h0_back<Obj> >,
			U_swap1       < Arg                                >,
			U_opt_pack_Vs < action_r_a0__replace_at_a0         >,
			U_swap1       < Arg                                >,
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
			swap1<Arg>,
			argument_zero<>
		>;
	};

	// interface:

		template<index_type Arg>
		static constexpr instr_type argument = dispatch_linear1
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
			swap1<Arg>,
			a0_is_null__insert_at_h0_front<>,
			swap1<Arg>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Arg>
		static constexpr instr_type is_null = dispatch_linear1
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
			U_swap1       < Arg                             >,
			U_opt_pack_Vs < car_a0__insert_at_r_front<>     >,
			U_swap1       < Arg                             >,
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
			swap1<Arg>,
			cdr_a0__replace_at_a0<>,
			swap1<Arg>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Arg>
		static constexpr instr_type cdr_assign = dispatch_linear1
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
			swap1<Arg>,
			map_a0__replace_at_a0<Action>,
			swap1<Arg>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Arg, key_type Action>
		static constexpr instr_type map_assign = dispatch_linear1
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

// catenate argument position argument position, replace at argument position:

	template<key_type... filler>
	struct linear_program<LN::cat_a_pos_a_pos__replace_at_a_pos, filler...> : public T_linear_program
	{
		template<index_type Pos, index_type Arg>
		static constexpr label_type lines = ML::safe_label
		(
		 	U_null_Vs,
			U_fswap2      < Pos                        , Arg >,
			U_opt_pack_Vs < cat_a0_a1__replace_at_a0<>       >,
			U_bswap2      < Pos                        , Arg >,
			U_opt_pack_Vs < unwind<>                         >
		);
	};

	// interface:

		template<index_type Pos, index_type Arg>
		static constexpr instr_type cat_assign = dispatch_linear2
		<
			Pos, Arg,
			cat_a0_a1__replace_at_a0<>,
			LN::cat_a_pos_a_pos__replace_at_a_pos,
			CP::load
		>();

/***********************************************************************************************************************/

// zip argument position argument position, replace at argument position:

	template<key_type... filler>
	struct linear_program<LN::zip_a_pos_a_pos__replace_at_a_pos, filler...> : public T_linear_program
	{
		template<index_type Pos, index_type Arg, key_type Action>
		static constexpr label_type lines = ML::safe_label
		(
		 	U_null_Vs,
			U_fswap2      < Pos                              , Arg >,
			U_opt_pack_Vs < zip_a0_a1__replace_at_a0<Action>       >,
			U_bswap2      < Pos                              , Arg >,
			U_opt_pack_Vs < unwind<>                               >
		);
	};

	// interface:

		template<index_type Pos, index_type Arg, key_type Action>
		static constexpr instr_type zip_assign = dispatch_linear2
		<
			Pos, Arg,
			zip_a0_a1__replace_at_a0<Action>,
			LN::zip_a_pos_a_pos__replace_at_a_pos,
			CP::load,
			Action
		>();

	// syntactic sugar:

		template<index_type Pos, index_type Arg>
		static constexpr instr_type op_zip_assign	= zip_assign<Pos, Arg, FA::op_zip>;

		template<index_type Pos, index_type Arg>
		static constexpr instr_type act_zip_assign	= zip_assign<Pos, Arg, FA::act_zip>;

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
/***********************************************************************************************************************/

