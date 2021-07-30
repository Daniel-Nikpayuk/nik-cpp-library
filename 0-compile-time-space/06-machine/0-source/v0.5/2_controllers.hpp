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
		static constexpr instr_type move_s_block__insert_at_s_back = instruction
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
		static constexpr instr_type move_s_block__insert_at_h0_front = instruction
		<
			MN::move_s_block__insert_at_h0_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_s_block__insert_at_h1_back = instruction
		<
			MN::move_s_block__insert_at_h1_back, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_s_first__replace_at_h1_value = instruction
		<
			MN::move_s_first__replace_at_h1_value, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type copy_s_block__insert_at_h0_front = instruction
		<
			MN::copy_s_block__insert_at_h0_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type copy_s_pos__insert_at_h0_front_opt = instruction // optimizer
		<
			MN::copy_s_pos__insert_at_h0_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type copy_s_block__insert_at_h1_back = instruction
		<
			MN::copy_s_block__insert_at_h1_back, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type copy_s_pos__insert_at_h1_back_opt = instruction // optimizer
		<
			MN::copy_s_pos__insert_at_h1_back, Note
		>;

		// heap -> stack:

		template<key_type Note = _zero>
		static constexpr instr_type move_h0_first__insert_at_s_front = instruction
		<
			MN::move_h0_first__insert_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_h0_first__insert_at_s_pos_opt = instruction // optimizer
		<
			MN::move_h0_first__insert_at_s_pos, Note

		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_h0_first__replace_at_s_pos_opt = instruction // optimizer
		<
			MN::move_h0_first__replace_at_s_pos, Note

		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_h0_first__insert_at_h3_value = instruction
		<
			MN::move_h0_first__insert_at_h3_value, Note

		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_h1_all__insert_at_s_front = instruction
		<
			MN::move_h1_all__insert_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_h1_all__pack_at_s_front = instruction
		<
			MN::move_h1_all__pack_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_h3_all__insert_at_h0_front = instruction
		<
			MN::move_h3_all__insert_at_h0_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type apply_h1_all__move__insert_at_h0_front = instruction
		<
			MN::apply_h1_all__move__insert_at_h0_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type apply_h1_all__move__replace_at_s_pos_opt = instruction // optimizer
		<
			MN::apply_h1_all__move__replace_at_s_pos, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type compel_h1_all__move__insert_at_h0_front = instruction
		<
			MN::compel_h1_all__move__insert_at_h0_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type compel_h1_all__move__replace_at_s_pos_opt = instruction // optimizer
		<
			MN::compel_h1_all__move__replace_at_s_pos, Note
		>;

	// interposers:

		template<key_type Note = MT::unary>
		static constexpr instr_type skip = instruction
		<
			MN::skip, Note
		>;

		template<index_type Val, key_type Note = _zero>
		static constexpr instr_type branch = instruction // shifts label value:
		<
			MN::branch, Note, Val+1
		>;

		template<key_type Note = PT::recall>
		static constexpr instr_type pass = instruction
		<
			MN::pass, Note
		>;

		template<key_type SubName, index_type... Vs>
		static constexpr instr_type block = instruction
		<
			MN::block, _zero, SubName, _zero, Vs...
		>;

		template<key_type SubName, key_type SubNote, index_type... Vs>
		static constexpr instr_type linear = instruction
		<
			MN::linear, CallInstr::patch(sizeof...(Vs)), SubName, SubNote, Vs...
		>;

		template<key_type Name, index_type... Vs>
		static constexpr instr_type call = instruction
		<
			MN::call, Name, sizeof...(Vs), Vs...
		>;

	// recursion:

		template<key_type Note = _zero>
		static constexpr instr_type recurse = instruction
		<
			MN::recurse, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type trampoline = instruction
		<
			MN::trampoline, Note
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

			static constexpr key_type drop_s_segment				= 1; // <list>

			static constexpr key_type make_i_segment__insert_at_s_back		= 2; // <machine>

			static constexpr key_type fold_s_segment__replace_at_s_front		= 3; // <machine>
			static constexpr key_type roll_s_segment__replace_at_s_front		= 4; // <machine>

			// stack -> heap:

			static constexpr key_type move_s_segment__insert_at_h0_front		= 5; // <mutators>
			static constexpr key_type move_s_segment__insert_at_h1_back		= 6; // <mutators>
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
		struct block_controller<BN::drop_s_segment, filler...>
		{
			template<key_type Cont = MN::pass>
			static constexpr instr_type result = instruction<MN::drop_s_block, Cont>;
		};

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
		struct block_controller<BN::move_s_segment__insert_at_h0_front, filler...>
		{
			template<key_type Cont = MN::pass>
			static constexpr instr_type result = instruction<MN::move_s_block__insert_at_h0_front, Cont>;
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
		static constexpr instr_type drop_s_segment = block
		<
			BN::drop_s_segment, Pos
		>;

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
		static constexpr instr_type move_s_segment__insert_at_h0_front = block
		<
			BN::move_s_segment__insert_at_h0_front, Pos
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

			static constexpr index_type copy_s_pos__insert_at_h0_front		=  2; // <mutators>, opt
			static constexpr index_type copy_s_pos__insert_at_h1_back		=  3; // <mutators>, opt

			// heap -> stack:

			static constexpr index_type move_h0_first__insert_at_s_pos		=  4; // <mutators>, opt
			static constexpr index_type move_h0_first__replace_at_s_pos		=  5; // <mutators>, opt

			static constexpr index_type apply_h1_all__move__replace_at_s_pos	=  6; // <machine>, opt

			static constexpr index_type compel_h1_all__move__replace_at_s_pos	=  7; // <machine>, opt

	// (level 2)

		// mutators:

			static constexpr index_type erase					=  8;
			static constexpr index_type insert					=  9;
			static constexpr index_type replace					= 10;

		// near linear:

			static constexpr index_type lift					= 11;
			static constexpr index_type stem					= 12;
			static constexpr index_type costem					= 13;
			static constexpr index_type cycle					= 14;

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
				move_s_segment__insert_at_h1_back<Pos>,
				drop_s_block<>, // first
				move_h1_all__insert_at_s_front<>,
				Cont
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::move_s_pos__insert_at_s_back, filler...>
		{
			template<index_type Pos, instr_type Cont = pass<>>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				move_s_block__insert_at_s_back<>, // first
				move_h1_all__insert_at_s_front<>,
				Cont
			>;
		};

		// stack -> heap:

		template<key_type... filler>
		struct linear_controller<LN::copy_s_pos__insert_at_h0_front, filler...>
		{
			template<index_type Pos, instr_type Cont = pass<>>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				copy_s_block__insert_at_h0_front<>, // first
				move_h1_all__insert_at_s_front<>,
				Cont
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::copy_s_pos__insert_at_h1_back, filler...>
		{
			template<index_type Pos, instr_type Cont = pass<>>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				copy_s_block__insert_at_h1_back<>, // first
				move_h1_all__insert_at_s_front<>,
				Cont
			>;
		};

		// heap -> stack:

		template<key_type... filler>
		struct linear_controller<LN::move_h0_first__insert_at_s_pos, filler...>
		{
			template<index_type Pos, instr_type Cont = pass<>>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				move_h0_first__insert_at_s_front<>,
				move_h1_all__insert_at_s_front<>,
				Cont
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::move_h0_first__replace_at_s_pos, filler...>
		{
			template<index_type Pos, instr_type Cont = pass<>>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				drop_s_block<>, // first
				move_h0_first__insert_at_s_front<>,
				move_h1_all__insert_at_s_front<>,
				Cont
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::apply_h1_all__move__replace_at_s_pos, filler...>
		{
			template<index_type Pos, instr_type Cont = pass<>>
			static constexpr label_type result = label
			<
				apply_h1_all__move__insert_at_h0_front<>,
				move_s_segment__insert_at_h1_back<Pos>,
				drop_s_block<>, // first
				move_h0_first__insert_at_s_front<>,
				move_h1_all__insert_at_s_front<>,
				Cont
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::compel_h1_all__move__replace_at_s_pos, filler...>
		{
			template<index_type Pos, instr_type Cont = pass<>>
			static constexpr label_type result = label
			<
				compel_h1_all__move__insert_at_h0_front<>,
				move_s_segment__insert_at_h1_back<Pos>,
				drop_s_block<>, // first
				move_h0_first__insert_at_s_front<>,
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
			else return linear<LN::drop_s_pos, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type drop_s_pos = f_drop_s_pos<Pos>();

		//

		template<index_type Pos>
		static constexpr instr_type f_move_s_pos__insert_at_s_back()
		{
			if constexpr (MI::is_opt(Pos)) return move_s_pos__insert_at_s_back_opt<Pos>;
			else return linear<LN::move_s_pos__insert_at_s_back, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type move_s_pos__insert_at_s_back = f_move_s_pos__insert_at_s_back<Pos>();

		// stack -> heap:

		template<index_type Pos>
		static constexpr instr_type f_copy_s_pos__insert_at_h0_front()
		{
			if constexpr (MI::is_opt(Pos)) return copy_s_pos__insert_at_h0_front_opt<Pos>;
			else return linear<LN::copy_s_pos__insert_at_h0_front, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type copy_s_pos__insert_at_h0_front = f_copy_s_pos__insert_at_h0_front<Pos>();

		//

		template<index_type Pos>
		static constexpr instr_type f_copy_s_pos__insert_at_h1_back()
		{
			if constexpr (MI::is_opt(Pos)) return copy_s_pos__insert_at_h1_back_opt<Pos>;
			else return linear<LN::copy_s_pos__insert_at_h1_back, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type copy_s_pos__insert_at_h1_back = f_copy_s_pos__insert_at_h1_back<Pos>();

		// heap -> stack:

		template<index_type Pos>
		static constexpr instr_type f_move_h0_first__insert_at_s_pos()
		{
			if constexpr (MI::is_opt(Pos)) return move_h0_first__insert_at_s_pos_opt<Pos>;
			else return linear<LN::move_h0_first__insert_at_s_pos, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type move_h0_first__insert_at_s_pos = f_move_h0_first__insert_at_s_pos<Pos>();

		//

		template<index_type Pos>
		static constexpr instr_type f_move_h0_first__replace_at_s_pos()
		{
			if constexpr (MI::is_opt(Pos)) return move_h0_first__replace_at_s_pos_opt<Pos>;
			else return linear<LN::move_h0_first__replace_at_s_pos, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type move_h0_first__replace_at_s_pos = f_move_h0_first__replace_at_s_pos<Pos>();

		//

		template<index_type Pos>
		static constexpr instr_type f_apply_h1_all__move__replace_at_s_pos()
		{
			if constexpr (MI::is_opt(Pos)) return apply_h1_all__move__replace_at_s_pos_opt<Pos>;
			else return linear<LN::apply_h1_all__move__replace_at_s_pos, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type apply_h1_all__move__replace_at_s_pos =
			f_apply_h1_all__move__replace_at_s_pos<Pos>();

		//

		template<index_type Pos>
		static constexpr instr_type f_compel_h1_all__move__replace_at_s_pos()
		{
			if constexpr (MI::is_opt(Pos)) return compel_h1_all__move__replace_at_s_pos_opt<Pos>;
			else return linear<LN::compel_h1_all__move__replace_at_s_pos, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type compel_h1_all__move__replace_at_s_pos =
			f_compel_h1_all__move__replace_at_s_pos<Pos>();

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
				copy_s_pos__insert_at_h0_front<Obj>,
				move_h0_first__insert_at_s_pos<Pos>,
				Cont
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::replace, filler...>
		{
			template<index_type Pos, index_type Obj, instr_type Cont = pass<>>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h0_front<Obj>,
				move_h0_first__replace_at_s_pos<Pos>,
				Cont
			>;
		};

	// register:

		template<key_type... filler>
		struct linear_controller<LN::go_to, filler...>
		{
			template<index_type Pos>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h0_front<Pos>,
				instruction<MN::pass, PT::reindex>
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::go_to_label, filler...>
		{
			// goto label exists for use in linear controllers,
			// but is optimized away for the register dispatcher.

			template<key_type...>
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
				move_h0_first__replace_at_s_pos<Pos>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::save, filler...>
		{
			template<index_type Pos>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h0_front<Pos>,
				move_h0_first__insert_at_h3_value<>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::restore, filler...>
		{
			template<index_type Pos>
			static constexpr label_type result = label
			<
				move_h3_all__insert_at_h0_front<>,
				move_h0_first__replace_at_s_pos<Pos>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::test, filler...>
		{
			template<index_type Op, index_type... Args>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h1_back<Op>,
				copy_s_pos__insert_at_h1_back<Args>...,
				apply_h1_all__move__insert_at_h0_front<>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::check, filler...>
		{
			template<index_type Op, index_type... Args>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h1_back<Op>,
				copy_s_pos__insert_at_h1_back<Args>...,
				compel_h1_all__move__insert_at_h0_front<>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::apply, filler...>
		{
			template<index_type Pos, index_type Op, index_type... Args>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h1_back<Op>,
				copy_s_pos__insert_at_h1_back<Args>...,
				apply_h1_all__move__replace_at_s_pos<Pos>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_controller<LN::compel, filler...>
		{
			template<index_type Pos, index_type Op, index_type... Args>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h1_back<Op>,
				copy_s_pos__insert_at_h1_back<Args>...,
				compel_h1_all__move__replace_at_s_pos<Pos>,
				pass<>
			>;
		};

/***********************************************************************************************************************/

// syntactic sugar (level 2):

	// mutators:

			template<index_type Pos>
			static constexpr instr_type erase = linear
			<
				LN::erase, _zero, Pos
			>;

			template<index_type Pos, index_type Obj>
			static constexpr instr_type insert = linear
			<
				LN::insert, _zero, Pos, Obj
			>;

			template<index_type Pos, index_type Obj>
			static constexpr instr_type replace = linear
			<
				LN::replace, _zero, Pos, Obj
			>;

	// register:

		template<index_type Pos>
		static constexpr instr_type goto_using = linear
		<
			LN::go_to, _zero, Pos
		>;

		template<index_type Val>
		static constexpr instr_type goto_label = linear // shifts label value:
		<
			LN::go_to_label, _one, Val+1
		>;

		template<index_type Pos, index_type Obj>
		static constexpr instr_type assign_using = linear // convenience
		<
			LN::replace, _zero, Pos, Obj
		>;

		template<index_type Pos, index_type Val>
		static constexpr instr_type assign_label = linear // shifts label value:
		<
			LN::assign_label, _one, Val+1, Pos
		>;

		template<index_type Pos>
		static constexpr instr_type save = linear
		<
			LN::save, _zero, Pos
		>;

		template<index_type Pos>
		static constexpr instr_type restore = linear
		<
			LN::restore, _zero, Pos
		>;

		template<index_type Op, index_type... Args>
		static constexpr instr_type test = linear
		<
			LN::test, _zero, Op, Args...
		>;

		template<index_type Act, index_type... Args>
		static constexpr instr_type check = linear
		<
			LN::check, _zero, Act, Args...
		>;

		template<index_type Pos, index_type Op, index_type... Args>
		static constexpr instr_type apply = linear
		<
			LN::apply, _zero, Pos, Op, Args...
		>;

		template<index_type Pos, index_type Act, index_type... Args>
		static constexpr instr_type compel = linear
		<
			LN::compel, _zero, Pos, Act, Args...
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

