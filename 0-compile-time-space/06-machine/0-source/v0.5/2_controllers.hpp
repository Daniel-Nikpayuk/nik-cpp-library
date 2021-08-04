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

	// e1e: starts with heap one empty, ends with heap one empty.
	// e2e: starts with heaps zero and one empty, ends with heaps zero and one empty.

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
		static constexpr instr_type align_s_all__insert_at_s_front = instruction
		<
			MN::align_s_all__insert_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type shift_r_block__insert_at_s_back = instruction
		<
			MN::shift_r_block__insert_at_s_back, Note
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
		static constexpr instr_type copy_s_block__insert_at_h0_back = instruction
		<
			MN::copy_s_block__insert_at_h0_back, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type copy_s_pos__insert_at_h0_front_opt = instruction // optimizer
		<
			MN::copy_s_pos__insert_at_h0_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type copy_s_pos__insert_at_h0_back_opt = instruction // optimizer
		<
			MN::copy_s_pos__insert_at_h0_back, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type copy_s_block__insert_at_h2_front = instruction
		<
			MN::copy_s_block__insert_at_h2_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type copy_s_pos__insert_at_h2_front_opt = instruction // optimizer
		<
			MN::copy_s_pos__insert_at_h2_front, Note
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
		static constexpr instr_type move_h1_all__insert_at_s_front = instruction
		<
			MN::move_h1_all__insert_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_h1_all__value_at_s_front = instruction
		<
			MN::move_h1_all__value_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_h2_first__insert_at_s_front = instruction
		<
			MN::move_h2_first__insert_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_h2_first__replace_at_s_pos_opt = instruction // optimizer
		<
			MN::move_h2_first__replace_at_s_pos, Note

		>;

		template<key_type Note = _zero>
		static constexpr instr_type apply_h0_all__move__insert_at_s_front = instruction
		<
			MN::apply_h0_all__move__insert_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type apply_h0_all__move__replace_at_s_pos_opt = instruction // optimizer
		<
			MN::apply_h0_all__move__replace_at_s_pos, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type compel_h0_all__move__replace_at_s_pos_opt = instruction // optimizer
		<
			MN::compel_h0_all__move__replace_at_s_pos, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type compel_h0_all__move__insert_at_s_front = instruction
		<
			MN::compel_h0_all__move__insert_at_s_front, Note
		>;

		// heap -> heap:

		template<key_type Note = _zero>
		static constexpr instr_type apply_h0_all__move__replace_at_h0_front = instruction
		<
			MN::apply_h0_all__move__replace_at_h0_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type compel_h0_all__move__replace_at_h0_front = instruction
		<
			MN::compel_h0_all__move__replace_at_h0_front, Note
		>;

	// interposers:

		template<index_type Obj, key_type Note = _zero>
		static constexpr instr_type copy_i_pos__insert_at_h0_front = instruction
		<
			MN::copy_i_pos__insert_at_h0_front, Note, Obj
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

		template<key_type Name, index_type Note, key_type SubName, key_type SubNote, index_type... Vs> // helper
		static constexpr instr_type patch_instruction = instruction
		<
			CI::patchname(Name, Note), CI::patchnote(Name, Note), SubName, SubNote, Vs...
		>;

		template<key_type SubName, key_type SubNote, index_type... Vs>
		static constexpr instr_type linear = patch_instruction
		<
			MN::linear, sizeof...(Vs), SubName, SubNote, Vs...
		>;

		template<key_type SubName, key_type SubNote, index_type... Vs>
		static constexpr instr_type control = patch_instruction
		<
			MN::control, sizeof...(Vs), SubName, SubNote, Vs...
		>;

	//	template<key_type SubName, key_type SubNote, index_type... Vs>
	//	static constexpr instr_type user = patch_instruction
	//	<
	//		MN::user, sizeof...(Vs), SubName, SubNote, Vs...
	//	>;

		template<key_type SubName, key_type SubNote, index_type... Vs>
		static constexpr instr_type user = instruction
		<
			MN::call, MN::user, SubName, SubNote, Vs...
		>;

	// recursors:

		template<key_type Note = _zero>
		static constexpr instr_type recurse__insert_at_h0_front = instruction
		<
			MN::recurse__insert_at_h0_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type trampoline__insert_at_h0_front = instruction
		<
			MN::trampoline__insert_at_h0_front, Note
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

			static constexpr key_type make_r_segment__insert_at_s_back		= 1; // <machine>

			static constexpr key_type drop_s_segment				= 2; // <list>

			static constexpr key_type fold_s_segment__replace_at_s_front		= 3; // <machine>
			static constexpr key_type roll_s_segment__replace_at_s_front		= 4; // <machine>

			// stack -> heap:

			static constexpr key_type move_s_segment__insert_at_h0_front		= 5; // <mutators>
			static constexpr key_type move_s_segment__insert_at_h1_back		= 6; // <mutators>
	};

	using BN = BlockName;

/***********************************************************************************************************************/

// inventory (level 0):

	template<key_type, key_type...> struct block_space;

	// halters:

		template<key_type... filler>
		struct block_space<BN::stop, filler...>
		{
			template<index_type...>
			static constexpr instr_type result = instruction<MN::drop_s_block, MN::first>;
		};

	// passers:

		// stack -> stack:

		template<key_type... filler>
		struct block_space<BN::make_r_segment__insert_at_s_back, filler...>
		{
			template<index_type...>
			static constexpr instr_type result = instruction<MN::shift_r_block__insert_at_s_back, MN::pass>;
		};

		template<key_type... filler>
		struct block_space<BN::drop_s_segment, filler...>
		{
			template<index_type...>
			static constexpr instr_type result = instruction<MN::drop_s_block, MN::pass>;
		};

		template<key_type... filler>
		struct block_space<BN::fold_s_segment__replace_at_s_front, filler...>
		{
			template<index_type...>
			static constexpr instr_type result = instruction<MN::fold_s_block__op_at_h0_first, MN::pass>;
		};

		template<key_type... filler>
		struct block_space<BN::roll_s_segment__replace_at_s_front, filler...>
		{
			template<index_type...>
			static constexpr instr_type result = instruction<MN::roll_s_block__act_at_h0_first, MN::pass>;
		};

		// stack -> heap:

		template<key_type... filler>
		struct block_space<BN::move_s_segment__insert_at_h0_front, filler...>
		{
			template<index_type...>
			static constexpr instr_type result = instruction<MN::move_s_block__insert_at_h0_front, MN::pass>;
		};

		template<key_type... filler>
		struct block_space<BN::move_s_segment__insert_at_h1_back, filler...>
		{
			template<index_type...>
			static constexpr instr_type result = instruction<MN::move_s_block__insert_at_h1_back, MN::pass>;
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
		static constexpr instr_type make_r_segment__insert_at_s_back = block
		<
			BN::make_r_segment__insert_at_s_back, Pos
		>;

		template<index_type Pos>
		static constexpr instr_type drop_s_segment = block
		<
			BN::drop_s_segment, Pos
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
			static constexpr index_type copy_s_pos__insert_at_h0_back		=  3; // <mutators>, opt

			static constexpr index_type copy_s_pos__insert_at_h2_front		=  4; // <mutators>, opt

			// heap -> stack:

			static constexpr index_type move_h0_first__insert_at_s_pos		=  5; // <mutators>, opt
			static constexpr index_type move_h0_first__replace_at_s_pos		=  6; // <mutators>, opt

			static constexpr index_type move_h2_first__replace_at_s_pos		=  7; // <mutators>, opt

			static constexpr index_type apply_h0_all__move__replace_at_s_pos	=  8; // <machine>, opt

			static constexpr index_type compel_h0_all__move__replace_at_s_pos	=  9; // <machine>, opt

	// (level 2)

		// mutators:

			static constexpr index_type erase					= 10;
			static constexpr index_type insert					= 11;
			static constexpr index_type replace					= 12;

		// control:

			static constexpr index_type go_to					= 13;
			static constexpr index_type go_to_label					= 14;

			static constexpr index_type assign_label				= 15;

			static constexpr index_type save					= 16;
			static constexpr index_type restore					= 17;

			static constexpr index_type test					= 18;
			static constexpr index_type check					= 19;

			static constexpr index_type apply					= 20;
			static constexpr index_type compel					= 21;
	};

	using LN = LinearName;

/***********************************************************************************************************************/

// inventory (level 1):

	template<key_type, key_type...> struct linear_space;

	// passers:

		// stack -> stack

		template<key_type... filler>
		struct linear_space<LN::drop_s_pos, filler...> // e1e
		{
			template<index_type Pos>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				drop_s_block<>, // first
				move_h1_all__insert_at_s_front<>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_space<LN::move_s_pos__insert_at_s_back, filler...> // e1e
		{
			template<index_type Pos>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				move_s_block__insert_at_s_back<>, // first
				move_h1_all__insert_at_s_front<>,
				pass<>
			>;
		};

		// stack -> heap:

		template<key_type... filler>
		struct linear_space<LN::copy_s_pos__insert_at_h0_front, filler...> // e1e
		{
			template<index_type Pos>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				copy_s_block__insert_at_h0_front<>, // first
				move_h1_all__insert_at_s_front<>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_space<LN::copy_s_pos__insert_at_h0_back, filler...> // e1e
		{
			template<index_type Pos>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				copy_s_block__insert_at_h0_back<>, // first
				move_h1_all__insert_at_s_front<>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_space<LN::copy_s_pos__insert_at_h2_front, filler...> // e1e
		{
			template<index_type Pos>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				copy_s_block__insert_at_h2_front<>, // first
				move_h1_all__insert_at_s_front<>,
				pass<>
			>;
		};

		// heap -> stack:

		template<key_type... filler>
		struct linear_space<LN::move_h0_first__insert_at_s_pos, filler...> // e1e
		{
			template<index_type Pos>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				move_h0_first__insert_at_s_front<>,
				move_h1_all__insert_at_s_front<>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_space<LN::move_h0_first__replace_at_s_pos, filler...> // e1e
		{
			template<index_type Pos>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				drop_s_block<>, // first
				move_h0_first__insert_at_s_front<>,
				move_h1_all__insert_at_s_front<>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_space<LN::move_h2_first__replace_at_s_pos, filler...> // e1e
		{
			template<index_type Pos>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				drop_s_block<>, // first
				move_h2_first__insert_at_s_front<>,
				move_h1_all__insert_at_s_front<>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_space<LN::apply_h0_all__move__replace_at_s_pos, filler...> // e1e
		{
			template<index_type Pos>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				drop_s_block<>, // first
				apply_h0_all__move__insert_at_s_front<>,
				move_h1_all__insert_at_s_front<>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_space<LN::compel_h0_all__move__replace_at_s_pos, filler...> // e1e
		{
			template<index_type Pos>
			static constexpr label_type result = label
			<
				move_s_segment__insert_at_h1_back<Pos>,
				drop_s_block<>, // first
				compel_h0_all__move__insert_at_s_front<>,
				move_h1_all__insert_at_s_front<>,
				pass<>
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
		static constexpr instr_type f_copy_s_pos__insert_at_h0_back()
		{
			if constexpr (MI::is_opt(Pos)) return copy_s_pos__insert_at_h0_back_opt<Pos>;
			else return linear<LN::copy_s_pos__insert_at_h0_back, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type copy_s_pos__insert_at_h0_back = f_copy_s_pos__insert_at_h0_back<Pos>();

		//

		template<index_type Pos>
		static constexpr instr_type f_copy_s_pos__insert_at_h2_front()
		{
			if constexpr (MI::is_opt(Pos)) return copy_s_pos__insert_at_h2_front_opt<Pos>;
			else return linear<LN::copy_s_pos__insert_at_h2_front, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type copy_s_pos__insert_at_h2_front = f_copy_s_pos__insert_at_h2_front<Pos>();

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
		static constexpr instr_type f_move_h2_first__replace_at_s_pos()
		{
			if constexpr (MI::is_opt(Pos)) return move_h2_first__replace_at_s_pos_opt<Pos>;
			else return linear<LN::move_h2_first__replace_at_s_pos, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type move_h2_first__replace_at_s_pos = f_move_h2_first__replace_at_s_pos<Pos>();

		//

		template<index_type Pos>
		static constexpr instr_type f_apply_h0_all__move__replace_at_s_pos()
		{
			if constexpr (MI::is_opt(Pos)) return apply_h0_all__move__replace_at_s_pos_opt<Pos>;
			else return linear<LN::apply_h0_all__move__replace_at_s_pos, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type apply_h0_all__move__replace_at_s_pos =
			f_apply_h0_all__move__replace_at_s_pos<Pos>();

		//

		template<index_type Pos>
		static constexpr instr_type f_compel_h0_all__move__replace_at_s_pos()
		{
			if constexpr (MI::is_opt(Pos)) return compel_h0_all__move__replace_at_s_pos_opt<Pos>;
			else return linear<LN::compel_h0_all__move__replace_at_s_pos, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type compel_h0_all__move__replace_at_s_pos =
			f_compel_h0_all__move__replace_at_s_pos<Pos>();

/***********************************************************************************************************************/

// inventory (level 2):

	// mutators:

		template<key_type... filler>
		struct linear_space<LN::erase, filler...> // e1e
		{
			template<index_type Pos>
			static constexpr label_type result = label
			<
				drop_s_pos<Pos>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_space<LN::insert, filler...> // e1e
		{
			template<index_type Pos, index_type Obj>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h0_front<Obj>,
				move_h0_first__insert_at_s_pos<Pos>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_space<LN::replace, filler...> // e1e
		{
			template<index_type Pos, index_type Obj>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h0_front<Obj>,
				move_h0_first__replace_at_s_pos<Pos>,
				pass<>
			>;
		};

	// control:

		template<key_type... filler>
		struct linear_space<LN::go_to, filler...> // e1e
		{
			template<index_type Pos>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h0_front<Pos>,
				instruction<MN::pass, PT::reindex>
			>;
		};

		template<key_type... filler>
		struct linear_space<LN::go_to_label, filler...>
		{
			// goto label is optimized for register dispatchers, 
			// but is still required for linear controllers,
			// and incase it is the first label instruction.

			template<index_type Obj>
			static constexpr label_type result = label
			<
				copy_i_pos__insert_at_h0_front<Obj>,
				instruction<MN::pass, PT::reindex>
			>;
		};

		template<key_type... filler>
		struct linear_space<LN::assign_label, filler...> // e1e
		{
			template<index_type Pos, index_type Obj>
			static constexpr label_type result = label
			<
				copy_i_pos__insert_at_h0_front<Obj>,
				move_h0_first__replace_at_s_pos<Pos>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_space<LN::save, filler...> // e1e
		{
			template<index_type... Args>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h2_front<Args>...,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_space<LN::restore, filler...> // e1e
		{
			template<index_type... Args>
			static constexpr label_type result = label
			<
				move_h2_first__replace_at_s_pos<Args>...,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_space<LN::test, filler...> // e2e
		{
			template<index_type Op, index_type... Args>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h0_back<Op>,
				copy_s_pos__insert_at_h0_back<Args>...,
				apply_h0_all__move__replace_at_h0_front<>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_space<LN::check, filler...> // e2e
		{
			template<index_type Op, index_type... Args>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h0_back<Op>,
				copy_s_pos__insert_at_h0_back<Args>...,
				compel_h0_all__move__replace_at_h0_front<>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_space<LN::apply, filler...> // e2e
		{
			template<index_type Pos, index_type Op, index_type... Args>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h0_back<Op>,
				copy_s_pos__insert_at_h0_back<Args>...,
				apply_h0_all__move__replace_at_s_pos<Pos>,
				pass<>
			>;
		};

		template<key_type... filler>
		struct linear_space<LN::compel, filler...> // e2e
		{
			template<index_type Pos, index_type Op, index_type... Args>
			static constexpr label_type result = label
			<
				copy_s_pos__insert_at_h0_back<Op>,
				copy_s_pos__insert_at_h0_back<Args>...,
				compel_h0_all__move__replace_at_s_pos<Pos>,
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

	// control:

		template<index_type Pos>
		static constexpr instr_type goto_using = linear
		<
			LN::go_to, _zero, Pos
		>;

		template<index_type Val>
		static constexpr instr_type goto_label = linear // shifts label value:
		<
			LN::go_to_label, _zero, Val+1
		>;

		template<index_type Pos, index_type Obj>
		static constexpr instr_type assign_using = linear // convenience
		<
			LN::replace, _zero, Pos, Obj
		>;

		template<index_type Pos, index_type Val>
		static constexpr instr_type assign_label = linear // shifts label value:
		<
			LN::assign_label, _zero, Pos, Val+1
		>;

		template<index_type... Args>
		static constexpr instr_type save = linear
		<
			LN::save, _zero, Args...
		>;

		template<index_type... Args>
		static constexpr instr_type restore = linear
		<
			LN::restore, _zero, Args...
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

// control:

/***********************************************************************************************************************/

// names:

	struct ControlName
	{
	// (level 3)

		// recursors:

			static constexpr index_type user	= 0;
			static constexpr index_type recurse	= 1;
	};

	using CN = ControlName;

/***********************************************************************************************************************/

// inventory (level 3):

	template<key_type, key_type...> struct control_space;

	// interposers:

		template<key_type... filler>
		struct control_space<CN::user, filler...>
		{
			template
			<
				// labels:

					index_type Trampoline,
					index_type Done,

				// registers:

					index_type Obj,
					index_type Pos,
					index_type... Args
			>
			static constexpr contr_type result = controller
			<
				label // Call
				<
					copy_s_pos__insert_at_h0_front  < Obj                         >,
					copy_s_pos__insert_at_h0_back   < Args                        >...,
					instruction                     < MN::user   , CT::subroutine >,
					branch                          < Trampoline                  >,
					goto_label                      < Done                        >
				>,

				label // Trampoline
				<
					trampoline__insert_at_h0_front  <                             >,
					branch                          < Trampoline                  >,
					goto_label                      < Done                        >
				>,

				label // Done
				<
					move_h0_first__replace_at_s_pos < Pos                         >,
					pass                            <                             >
				>
			>;
		};

	// recursors:

		template<key_type... filler>
		struct control_space<CN::recurse, filler...>
		{
			template
			<
				// registers:

					index_type Pos,

				// labels:

					index_type Recurse	= 0,
					index_type Trampoline	= 1,
					index_type Done		= 2
			>
			static constexpr contr_type result = controller
			<
				label // Recurse
				<
					recurse__insert_at_h0_front     <            >,
					branch                          < Trampoline >,
					goto_label                      < Done       >
				>,

				label // Trampoline
				<
					trampoline__insert_at_h0_front  <            >,
					branch                          < Trampoline >,
					goto_label                      < Done       >
				>,

				label // Done
				<
					move_h0_first__replace_at_s_pos < Pos        >,
					pass                            <            >
				>
			>;
		};

/***********************************************************************************************************************/

// syntactic sugar (level 3):

	// mutators:

		template<index_type Pos>
		static constexpr instr_type recurse = control
		<
			CN::recurse, _zero, Pos
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

