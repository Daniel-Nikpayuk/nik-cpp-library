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

// controllers source:

	// Linear calling works because each of its controllers take register positions as input.
	// The whole purpose after all is to mutate the registers in ways eventually meaningful
	// to Turing complete register machines. Any instructions that interpret parameters
	// differently has a hardcoded machine.

	// define cycle<> instruction as an alias for goto ?

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// atomic:

/***********************************************************************************************************************/

// instructions:

	// halters:

		template<key_type Note = _zero>
		static constexpr instr_type pause = instruction
		<
			MN::pause, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type first = instruction
		<
			MN::first, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type rest = instruction
		<
			MN::rest, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type pack = instruction
		<
			MN::pack, Note
		>;

	// debuggers:

		template<key_type Note = _zero>
		static constexpr instr_type depth = instruction
		<
			MN::depth, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type dump = instruction
		<
			MN::dump, Note
		>;

	// passers:

		// stack -> stack:

		template<key_type Note = _zero>
		static constexpr instr_type sizeof_s_all__insert_at_s_front = instruction
		<
			MN::sizeof_s_all__insert_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type map_s_all__op_at_h0_first = instruction
		<
			MN::map_s_all__op_at_h0_first, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type map_s_all__act_at_h0_first = instruction
		<
			MN::map_s_all__act_at_h0_first, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type map_s_all__arr_at_h0_first = instruction
		<
			MN::map_s_all__arr_at_h0_first, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type align_s_all__insert_at_s_front = instruction
		<
			MN::align_s_all__insert_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type drop_s_block = instruction
		<
			MN::drop_s_block, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type drop_s_pos_opt = instruction // optimizer
		<
			MN::drop_s_pos, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type drop_s_all = instruction
		<
			MN::drop_s_all, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type shift_i_block__insert_at_s_back = instruction
		<
			MN::shift_i_block__insert_at_s_back, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_s_first__insert_at_s_back = instruction // block
		<
			MN::move_s_block__insert_at_s_back, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_s_pos__insert_at_s_back_opt = instruction // optimizer
		<
			MN::move_s_pos__insert_at_s_back, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type fold_s_block__op_at_h0_first = instruction
		<
			MN::fold_s_block__op_at_h0_first, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type roll_s_block__act_at_h0_first = instruction
		<
			MN::roll_s_block__act_at_h0_first, Note
		>;

		// stack -> heap:

		template<key_type Note = _zero>
		static constexpr instr_type move_s_block__insert_at_h0_back = instruction
		<
			MN::move_s_block__insert_at_h0_back, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_s_block__insert_at_h1_back = instruction
		<
			MN::move_s_block__insert_at_h1_back, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_s_first__replace_h0_value = instruction
		<
			MN::move_s_first__replace_h0_value, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type copy_s_block__insert_at_h0_back = instruction
		<
			MN::copy_s_block__insert_at_h0_back, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type copy_s_pos__insert_at_h0_back_opt = instruction // optimizer
		<
			MN::copy_s_pos__insert_at_h0_back, Note
		>;

		// heap -> stack:

		template<key_type Note = _zero>
		static constexpr instr_type move_h0_all__insert_at_s_front = instruction
		<
			MN::move_h0_all__insert_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_h0_all__insert_at_s_pos_opt = instruction // optimizer
		<
			MN::move_h0_all__insert_at_s_pos, Note

		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_h0_all__replace_at_s_pos_opt = instruction // optimizer
		<
			MN::move_h0_all__replace_at_s_pos, Note

		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_h0_all__pack_at_s_front = instruction
		<
			MN::move_h0_all__pack_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_h1_all__insert_at_s_front = instruction
		<
			MN::move_h1_all__insert_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type apply_h0_all__move__insert_at_s_front = instruction
		<
			MN::apply_h0_all__move__insert_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type apply_h0_all__replace_h0_all = instruction
		<
			MN::apply_h0_all__replace_h0_all, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type apply_h0_all__move__replace_at_s_pos_opt = instruction // optimizer
		<
			MN::apply_h0_all__move__replace_at_s_pos, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type compel_h0_all__move__insert_at_s_front = instruction
		<
			MN::compel_h0_all__move__insert_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type compel_h0_all__replace_h0_all = instruction
		<
			MN::compel_h0_all__replace_h0_all, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type compel_h0_all__move__replace_at_s_pos_opt = instruction // optimizer
		<
			MN::compel_h0_all__move__replace_at_s_pos, Note
		>;

	// interposers:

		template<key_type Note = MT::unary>
		static constexpr instr_type skip = instruction
		<
			MN::skip, Note
		>;

		template<index_type Pos, key_type Note = _zero>
		static constexpr instr_type branch = instruction
		<
			MN::branch, Note, Pos
		>;

		template<key_type Note = PT::recall>
		static constexpr instr_type pass = instruction
		<
			MN::pass, Note
		>;

		template<key_type Name, index_type... Vs>
		static constexpr instr_type block = instruction
		<
			MN::block, _zero, Name, Vs...
		>;

		template<key_type Name, index_type... Vs>
		static constexpr instr_type linear = instruction
		<
			MN::linear, CallInstr::patch(sizeof...(Vs)), Name, _zero, Vs...
		>;

		template<key_type Name, index_type... Vs>
		static constexpr instr_type call = instruction
		<
			MN::call, Name, sizeof...(Vs), Vs...
		>;

	// reflection:

		template<index_type Length, key_type Note = _zero>
		static constexpr instr_type reg_size = instruction
		<
			MN::reg_size, Note, Length
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compounds:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block:

/***********************************************************************************************************************/

// names:

	struct BlockName
	{
		// halters:

			static constexpr key_type stop						= 0;

		// passers:

			// stack -> stack:

			static constexpr key_type make_i_segment__insert_at_s_back		= 1; // <machine>

			static constexpr key_type fold_s_segment__replace_at_s_front		= 2; // <machine>
			static constexpr key_type roll_s_segment__replace_at_s_front		= 3; // <machine>

			// stack -> heap:

			static constexpr key_type move_s_segment__insert_at_h0_back		= 4; // <mutators>
			static constexpr key_type move_s_segment__insert_at_h1_back		= 5; // <mutators>
	};

	using BN = BlockName;

/***********************************************************************************************************************/

// inventory (level 0):

	// halters:

		template<key_type... filler>
		struct block_controller<BN::stop, filler...>
		{
			template<key_type Cont = MN::first>
			static constexpr instr_type result = instruction<MN::drop_s_block, Cont>;
		};

	// passers:

		// stack -> stack:

		template<key_type... filler>
		struct block_controller<BN::make_i_segment__insert_at_s_back, filler...>
		{
			template<key_type Cont = MN::pass>
			static constexpr instr_type result = instruction<MN::shift_i_block__insert_at_s_back, Cont>;
		};

		template<key_type... filler>
		struct block_controller<BN::fold_s_segment__replace_at_s_front, filler...>
		{
			template<key_type Cont = MN::pass>
			static constexpr instr_type result = instruction<MN::fold_s_block__op_at_h0_first, Cont>;
		};

		template<key_type... filler>
		struct block_controller<BN::roll_s_segment__replace_at_s_front, filler...>
		{
			template<key_type Cont = MN::pass>
			static constexpr instr_type result = instruction<MN::roll_s_block__act_at_h0_first, Cont>;
		};

		// stack -> heap:

		template<key_type... filler>
		struct block_controller<BN::move_s_segment__insert_at_h0_back, filler...>
		{
			template<key_type Cont = MN::pass>
			static constexpr instr_type result = instruction<MN::move_s_block__insert_at_h0_back, Cont>;
		};

		template<key_type... filler>
		struct block_controller<BN::move_s_segment__insert_at_h1_back, filler...>
		{
			template<key_type Cont = MN::pass>
			static constexpr instr_type result = instruction<MN::move_s_block__insert_at_h1_back, Cont>;
		};

/***********************************************************************************************************************/

// syntactic sugar (level 0):

	// halters:

		template<index_type Pos>
		static constexpr instr_type stop = block
		<
			BN::stop, Pos
		>;

	// passers:

		// stack -> stack:

		template<index_type Pos>
		static constexpr instr_type make_i_segment__insert_at_s_back = block
		<
			BN::make_i_segment__insert_at_s_back, Pos
		>;

		template<index_type Pos>
		static constexpr instr_type fold_s_segment__replace_at_s_front = block
		<
			BN::fold_s_segment__replace_at_s_front, Pos
		>;

		template<index_type Pos>
		static constexpr instr_type roll_s_segment__replace_at_s_front = block
		<
			BN::roll_s_segment__replace_at_s_front, Pos
		>;

		// stack -> heap:

		template<index_type Pos>
		static constexpr instr_type move_s_segment__insert_at_h0_back = block
		<
			BN::move_s_segment__insert_at_h0_back, Pos
		>;

		template<index_type Pos>
		static constexpr instr_type move_s_segment__insert_at_h1_back = block
		<
			BN::move_s_segment__insert_at_h1_back, Pos
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear:

/***********************************************************************************************************************/

// names:

	struct LinearName
	{
	// (level 1)

		// passers:

			// stack -> stack:

			static constexpr index_type drop_s_pos					=  0; // <mutators>, opt
			static constexpr index_type move_s_pos__insert_at_s_back		=  1; // <near linear>, opt

			// stack -> heap:

			static constexpr index_type copy_s_pos__insert_at_h0_back		=  2; // <mutators>, opt

			// heap -> stack:

			static constexpr index_type move_h0_all__insert_at_s_pos		=  3; // <mutators>, opt
			static constexpr index_type move_h0_all__replace_at_s_pos		=  4; // <mutators>, opt

			static constexpr index_type apply_h0_all__move__replace_at_s_pos	=  5; // <machine>, opt

			static constexpr index_type compel_h0_all__move__replace_at_s_pos	=  6; // <machine>, opt

	// (level 2)

		// mutators:

			static constexpr index_type erase					=  7;
			static constexpr index_type insert					=  8;
			static constexpr index_type replace					=  9;

		// near linear:

			static constexpr index_type lift					= 10;
			static constexpr index_type stem					= 11;
			static constexpr index_type costem					= 12;
			static constexpr index_type cycle					= 13;

			static constexpr index_type left					= 14;

		// register:

			static constexpr index_type go_to					= 15;
			static constexpr index_type go_to_label					= 16;

			static constexpr index_type assign_label				= 17;

			static constexpr index_type save					= 18;
			static constexpr index_type restore					= 19;

			static constexpr index_type test					= 20;
			static constexpr index_type check					= 21;

			static constexpr index_type apply					= 22;
			static constexpr index_type compel					= 23;

		// constants:

			static constexpr instr_type lift_instr		= instruction<lift, _zero>;
			static constexpr instr_type stem_instr		= instruction<stem, _zero>;
			static constexpr instr_type cycle_instr		= instruction<cycle, _zero>;
	};

	using LN = LinearName;

/***********************************************************************************************************************/

// inventory (level 1):

	// passers:

		// stack -> stack

		template<key_type... filler>
		struct linear_controller<LN::drop_s_pos, filler...>
		{
			template<index_type Pos, instr_type Cont = pass<>>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h0_back<Pos>,
				drop_s_block<>,
				move_h0_all__insert_at_s_front<>,
				Cont
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::move_s_pos__insert_at_s_back, filler...>
		{
			template<index_type Pos, instr_type Cont = pass<>>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h0_back<Pos>,
				move_s_first__insert_at_s_back<>,
				move_h0_all__insert_at_s_front<>,
				Cont
			>;
		};

		// stack -> heap:

		template<key_type... filler>
		struct linear_controller<LN::copy_s_pos__insert_at_h0_back, filler...>
		{
			template<index_type Pos, instr_type Cont = pass<>>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				copy_s_block__insert_at_h0_back<>,
				move_h1_all__insert_at_s_front<>,
				Cont
			>;
		};

		// heap -> stack:

		template<key_type... filler>
		struct linear_controller<LN::move_h0_all__insert_at_s_pos, filler...>
		{
			template<index_type Pos, instr_type Cont = pass<>>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				move_h0_all__insert_at_s_front<>,
				move_h1_all__insert_at_s_front<>,
				Cont
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::move_h0_all__replace_at_s_pos, filler...>
		{
			template<index_type Pos, instr_type Cont = pass<>>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				drop_s_block<>,
				move_h0_all__insert_at_s_front<>,
				move_h1_all__insert_at_s_front<>,
				Cont
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::apply_h0_all__move__replace_at_s_pos, filler...>
		{
			template<index_type Pos, instr_type Cont = pass<>>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				drop_s_block<>,
				apply_h0_all__move__insert_at_s_front<>,
				move_h1_all__insert_at_s_front<>,
				Cont
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::compel_h0_all__move__replace_at_s_pos, filler...>
		{
			template<index_type Pos, instr_type Cont = pass<>>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				drop_s_block<>,
				compel_h0_all__move__insert_at_s_front<>,
				move_h1_all__insert_at_s_front<>,
				Cont
			>;
		};

/***********************************************************************************************************************/

// syntactic sugar (level 1):

	// passers:

		// stack -> stack:

		template<index_type Pos>
		static constexpr instr_type f_drop_s_pos()
		{
			if constexpr (MI::is_opt(Pos)) return drop_s_pos_opt<Pos>;

			return linear<LN::drop_s_pos, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type drop_s_pos = f_drop_s_pos<Pos>();

		//

		template<index_type Pos>
		static constexpr instr_type f_move_s_pos__insert_at_s_back()
		{
			if constexpr (MI::is_opt(Pos)) return move_s_pos__insert_at_s_back_opt<Pos>;

			return linear<LN::move_s_pos__insert_at_s_back, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type move_s_pos__insert_at_s_back = f_move_s_pos__insert_at_s_back<Pos>();

		// stack -> heap:

		template<index_type Pos>
		static constexpr instr_type f_copy_s_pos__insert_at_h0_back()
		{
			if constexpr (MI::is_opt(Pos)) return copy_s_pos__insert_at_h0_back_opt<Pos>;

			return linear<LN::copy_s_pos__insert_at_h0_back, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type copy_s_pos__insert_at_h0_back = f_copy_s_pos__insert_at_h0_back<Pos>();

		// heap -> stack:

		template<index_type Pos>
		static constexpr instr_type f_move_h0_all__insert_at_s_pos()
		{
			if constexpr (MI::is_opt(Pos)) return move_h0_all__insert_at_s_pos_opt<Pos>;

			return linear<LN::move_h0_all__insert_at_s_pos, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type move_h0_all__insert_at_s_pos = f_move_h0_all__insert_at_s_pos<Pos>();

		//

		template<index_type Pos>
		static constexpr instr_type f_move_h0_all__replace_at_s_pos()
		{
			if constexpr (MI::is_opt(Pos)) return move_h0_all__replace_at_s_pos_opt<Pos>;

			return linear<LN::move_h0_all__replace_at_s_pos, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type move_h0_all__replace_at_s_pos = f_move_h0_all__replace_at_s_pos<Pos>();

		//

		template<index_type Pos>
		static constexpr instr_type f_apply_h0_all__move__replace_at_s_pos()
		{
			if constexpr (MI::is_opt(Pos)) return apply_h0_all__move__replace_at_s_pos_opt<Pos>;

			return linear<LN::apply_h0_all__move__replace_at_s_pos, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type apply_h0_all__move__replace_at_s_pos =
			f_apply_h0_all__move__replace_at_s_pos<Pos>();

		//

		template<index_type Pos>
		static constexpr instr_type f_compel_h0_all__move__replace_at_s_pos()
		{
			if constexpr (MI::is_opt(Pos)) return compel_h0_all__move__replace_at_s_pos_opt<Pos>;

			return linear<LN::compel_h0_all__move__replace_at_s_pos, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type compel_h0_all__move__replace_at_s_pos =
			f_compel_h0_all__move__replace_at_s_pos<Pos>();

/***********************************************************************************************************************/

// inventory (level 2):

	// mutators:

		template<key_type... filler>
		struct linear_controller<LN::erase, filler...>
		{
			template<index_type Pos, instr_type Cont = pass<>>
			static constexpr label_type result = label
			<
				drop_s_pos<Pos>,
				Cont
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::insert, filler...>
		{
			template<index_type Pos, index_type Obj, instr_type Cont = pass<>>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h0_back<Obj>,
				move_h0_all__insert_at_s_pos<Pos>,	// includes undefined behaviour.
				Cont
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::replace, filler...>
		{
			template<index_type Pos, index_type Obj, instr_type Cont = pass<>>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h0_back<Obj>,
				move_h0_all__replace_at_s_pos<Pos>,	// includes undefined behaviour.
				Cont
			>;
		};

	// near linear:

	//	template<na_type N>
	//	static constexpr np_type n_lift = n_continuation<NP::lift, N>;

		// lift:

		//	constexpr auto nc = controller_module::template call_contr<n::appl(c, i, j)>;

	//	template<na_type P, na_type B, na_type N>
	//	static constexpr np_type n_stem = n_continuation<NP::stem, P, B, N>;

		// stem:

		//	constexpr auto nc	= controller_module::template skip_contr
		//				<
		//					n::cond(c, i, j), n::appl2(c, i, j), n::appl1(c, i, j)
		//				>;

		// costem
		// cycle

	//	template<key_type... filler>
	//	struct linear_controller<LN::left, filler...>
	//	{
	//		template<index_type Pos, instr_type Cont = pass<>>
	//		static constexpr label_type result = label
	//		<
	//			move_s_segment__insert_at_h1_back<Pos>,
	//			clear<>,
	//			move_h1_all__insert_at_s_front<>,
	//			Cont
	//		>;
	//	};

	// register:

		template<key_type... filler>
		struct linear_controller<LN::go_to, filler...>
		{
			template<index_type Pos>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h0_back<Pos>,
				instruction<MN::pass, PT::reindex>
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::go_to_label, filler...>
		{
			// goto label exists for use in linear controllers,
			// but is optimized away for the register dispatcher.

			template<index_type Pos>
			static constexpr label_type result = label
			<
				instruction<MN::pass, PT::reindex>
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::assign_label, filler...>
		{
			template<index_type Pos>
			static constexpr label_type result = label
			<
				move_h0_all__replace_at_s_pos<Pos>,
				pass<>
			>;
		};

		// save

	//	template<index_type Pos, index_type Obj, pa_type Cont = pass<>>
	//	static constexpr auto restore_contr = linear_controller
	//	<
	//		move_s_pos__insert_at_h0_back<Obj>,
	//		move_h0_all__replace_at_s_pos<Pos>,
	//		Cont
	//	>;

		template<key_type... filler>
		struct linear_controller<LN::test, filler...>
		{
			template<index_type Op, index_type... Args>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h0_back<Op>,
				copy_s_pos__insert_at_h0_back<Args>...,
				apply_h0_all__replace_h0_all<>,			// includes undefined behaviour.
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::check, filler...>
		{
			template<index_type Op, index_type... Args>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h0_back<Op>,
				copy_s_pos__insert_at_h0_back<Args>...,
				compel_h0_all__replace_h0_all<>,		// includes undefined behaviour.
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::apply, filler...>
		{
			template<index_type Pos, index_type Op, index_type... Args>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h0_back<Op>,
				copy_s_pos__insert_at_h0_back<Args>...,
				apply_h0_all__move__replace_at_s_pos<Pos>,	// includes undefined behaviour.
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::compel, filler...>
		{
			template<index_type Pos, index_type Op, index_type... Args>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h0_back<Op>,
				copy_s_pos__insert_at_h0_back<Args>...,
				compel_h0_all__move__replace_at_s_pos<Pos>,	// includes undefined behaviour.
				pass<>
			>;
		};

/***********************************************************************************************************************/

// syntactic sugar (level 2):

	// mutators:

			template<index_type Pos>
			static constexpr instr_type erase = linear
			<
				LN::erase, Pos
			>;

			template<index_type Pos, index_type Obj>
			static constexpr instr_type insert = linear
			<
				LN::insert, Pos, Obj
			>;

			template<index_type Pos, index_type Obj>
			static constexpr instr_type replace = linear
			<
				LN::replace, Pos, Obj
			>;

	// near linear:

		// lift
		// stem
		// costem
		// cycle

	// register:

		template<index_type Pos>
		static constexpr instr_type goto_using = linear
		<
			LN::go_to, Pos
		>;

		template<index_type Val>
		static constexpr instr_type goto_label = instruction
		<
			MN::linear, LT::direct, LN::go_to_label, _one, Val
		>;

		template<index_type Pos, index_type Obj>
		static constexpr instr_type assign_using = linear // convenience
		<
			LN::replace, Pos, Obj
		>;

		template<index_type Val, index_type Pos>
		static constexpr instr_type assign_label = instruction
		<
			MN::linear, LT::direct, LN::assign_label, _one, Val, Pos
		>;

	//	template<index_type Pos, key_type Note = _zero>
	//	static constexpr instr_type save = instruction
	//	<
	//		MN::save, Note, Pos
	//	>;

	//	template<index_type Pos, key_type Note = _zero>
	//	static constexpr instr_type restore = instruction
	//	<
	//		MN::restore, Note, Pos
	//	>;

		template<index_type Op, index_type... Args>
		static constexpr instr_type test = linear
		<
			LN::test, Op, Args...
		>;

		template<index_type Act, index_type... Args>
		static constexpr instr_type check = linear
		<
			LN::check, Act, Args...
		>;

		template<index_type Pos, index_type Op, index_type... Args>
		static constexpr instr_type apply = linear
		<
			LN::apply, Pos, Op, Args...
		>;

		template<index_type Pos, index_type Act, index_type... Args>
		static constexpr instr_type compel = linear
		<
			LN::compel, Pos, Act, Args...
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

