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

// routines source:

	// Linear calling works because each of its controllers take register positions as input.
	// The whole purpose after all is to mutate the registers in ways eventually meaningful
	// to Turing complete register machines. Any instructions that interpret parameters
	// differently has a hardcoded machine.

	// e1e: starts with heap one empty, ends with heap one empty.
	// e2e: starts with heaps zero and one empty, ends with heaps zero and one empty.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// instructions:

public:

/***********************************************************************************************************************/

// interposers:

	template<key_type Note = _zero>
	static constexpr instr_type pause = instruction
	<
		MN::pause, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type sleep = instruction
	<
		MN::sleep, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type branch = instruction
	<
		MN::branch, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type go_to = instruction
	<
		MN::go_to, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type shift_r_block__insert_at_s_back = instruction
	<
		MN::shift_r_block__insert_at_s_back, Note
	>;

	template<key_type Note, key_type Subname, key_type Subnote, key_type... Args>
	static constexpr instr_type load = instruction
	<
		MN::load, Note, Subname, Subnote, Args...
	>;

		template<key_type Subname, key_type... Args>
		static constexpr instr_type load_block = instruction
		<
			MN::load, MT::block, Subname, _zero, Args...
		>;

		template<key_type Subname, key_type Subnote, key_type... Args>
		static constexpr instr_type load_linear = instruction
		<
			MN::load, MT::linear, Subname, Subnote, Args...
		>;

		template<key_type Subname, key_type Subnote, key_type... Args>
		static constexpr instr_type load_turing = instruction
		<
			MN::load, MT::turing, Subname, Subnote, Args...
		>;

		template<key_type Subname, key_type Subnote, key_type... Args>
		static constexpr instr_type load_user = instruction
		<
			MN::load, MT::user, Subname, Subnote, Args...
		>;

	template<key_type Note = _zero>
	static constexpr instr_type restack = instruction
	<
		MN::restack, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type call = instruction
	<
		MN::call, Note
	>;

// halters:

	template<key_type Note = _zero>
	static constexpr instr_type result = instruction
	<
		MN::result, Note
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

	template<key_type Note = _zero>
	static constexpr instr_type stack = instruction
	<
		MN::stack, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type heaps = instruction
	<
		MN::heaps, Note
	>;

// passers:

	// stack -> stack:

	template<key_type Note = _zero>
	static constexpr instr_type drop_s_block = instruction
	<
		MN::drop_s_block, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type drop_s_pos = instruction
	<
		MN::drop_s_pos, Note
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
	static constexpr instr_type copy_s_pos__insert_at_h0_front = instruction
	<
		MN::copy_s_pos__insert_at_h0_front, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type copy_s_pos__insert_at_h0_back = instruction
	<
		MN::copy_s_pos__insert_at_h0_back, Note
	>;

	// heap -> stack:

	template<key_type Note = _zero>
	static constexpr instr_type move_h0_first__insert_at_s_front = instruction
	<
		MN::move_h0_first__insert_at_s_front, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type move_h0_first__insert_at_s_pos = instruction
	<
		MN::move_h0_first__insert_at_s_pos, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type move_h0_first__replace_at_s_pos = instruction
	<
		MN::move_h0_first__replace_at_s_pos, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type move_h1_all__insert_at_s_front = instruction
	<
		MN::move_h1_all__insert_at_s_front, Note
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// halters:

/***********************************************************************************************************************/

// stop:

	template<key_type... filler>
	struct block_program<BN::stop, filler...> : public block_program<filler...>
	{
		static constexpr instr_type controller	= instruction<MN::drop_s_block, MN::first>;
	};

		template<index_type Pos>
		static constexpr instr_type stop = load_block			// subnote exists for consistency
		<								// with linear/turing programs.
			MN::load, MT::block, BN::stop, _zero, Pos
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (stack -> stack):

/***********************************************************************************************************************/

// :

	template<key_type... filler>
	struct block_program<BN::make_r_segment__insert_at_s_back, filler...> : public block_program<filler...>
	{
		static constexpr instr_type controller = instruction<MN::shift_r_block__insert_at_s_back, MN::sleep>;
	};

		template<index_type Pos>
		static constexpr instr_type make_r_segment__insert_at_s_back = load_block
		<
			BN::make_r_segment__insert_at_s_back, Pos
		>;

/***********************************************************************************************************************/

// :

	template<key_type... filler>
	struct block_program<BN::drop_s_segment, filler...> : public block_program<filler...>
	{
		static constexpr instr_type controller = instruction<MN::drop_s_block, MN::sleep>;
	};

		template<index_type Pos>
		static constexpr instr_type drop_s_segment = load_block
		<
			BN::drop_s_segment, Pos
		>;

/***********************************************************************************************************************/

// :

	template<key_type... filler>
	struct block_program<BN::fold_s_segment__replace_at_s_front, filler...> : public block_program<filler...>
	{
		static constexpr instr_type controller = instruction<MN::fold_s_block__op_at_h0_first, MN::sleep>;
	};

		template<index_type Pos>
		static constexpr instr_type fold_s_segment__replace_at_s_front = load_block
		<
			BN::fold_s_segment__replace_at_s_front, Pos
		>;

/***********************************************************************************************************************/

// :

	template<key_type... filler>
	struct block_program<BN::roll_s_segment__replace_at_s_front, filler...> : public block_program<filler...>
	{
		static constexpr instr_type controller = instruction<MN::roll_s_block__act_at_h0_first, MN::sleep>;
	};

		template<index_type Pos>
		static constexpr instr_type roll_s_segment__replace_at_s_front = load_block
		<
			BN::roll_s_segment__replace_at_s_front, Pos
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (stack -> heap):

/***********************************************************************************************************************/

// :

	template<key_type... filler>
	struct block_program<BN::move_s_segment__insert_at_h0_front, filler...> : public block_program<filler...>
	{
		static constexpr instr_type controller = instruction<MN::move_s_block__insert_at_h0_front, MN::sleep>;
	};

		template<index_type Pos>
		static constexpr instr_type move_s_segment__insert_at_h0_front = load_block
		<
			BN::move_s_segment__insert_at_h0_front, Pos
		>;

/***********************************************************************************************************************/

// :

	template<key_type... filler>
	struct block_program<BN::move_s_segment__insert_at_h1_back, filler...> : public block_program<filler...>
	{
		static constexpr instr_type controller = instruction<MN::move_s_block__insert_at_h1_back, MN::sleep>;
	};

		template<index_type Pos>
		static constexpr instr_type move_s_segment__insert_at_h1_back = load_block
		<
			BN::move_s_segment__insert_at_h1_back, Pos
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (stack -> stack):

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::drop_s_pos, filler...> : public linear_program<> // e1e
	{
		template<index_type Pos>
		static constexpr label_type result = label
		<
			move_s_segment__insert_at_h1_back<Pos>,
			drop_s_block<>, // first
			move_h1_all__insert_at_s_front<>,
			sleep<>
		>;
	};

		template<index_type Pos>
		static constexpr instr_type f_drop_s_pos()
		{
			if constexpr (MI::is_opt(Pos)) return drop_s_pos_opt<Pos>;
			else return linear<LN::drop_s_pos, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type drop_s_pos = f_drop_s_pos<Pos>();
*/

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::move_s_pos__insert_at_s_back, filler...> : public linear_program<> // e1e
	{
		template<index_type Pos>
		static constexpr label_type result = label
		<
			move_s_segment__insert_at_h1_back<Pos>,
			move_s_block__insert_at_s_back<>, // first
			move_h1_all__insert_at_s_front<>,
			sleep<>
		>;
	};

		template<index_type Pos>
		static constexpr instr_type f_move_s_pos__insert_at_s_back()
		{
			if constexpr (MI::is_opt(Pos)) return move_s_pos__insert_at_s_back_opt<Pos>;
			else return linear<LN::move_s_pos__insert_at_s_back, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type move_s_pos__insert_at_s_back = f_move_s_pos__insert_at_s_back<Pos>();
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (stack -> heap):

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::copy_s_pos__insert_at_h0_front, filler...> : public linear_program<> // e1e
	{
		template<index_type Pos>
		static constexpr label_type result = label
		<
			move_s_segment__insert_at_h1_back<Pos>,
			copy_s_block__insert_at_h0_front<>, // first
			move_h1_all__insert_at_s_front<>,
			sleep<>
		>;
	};

		template<index_type Pos>
		static constexpr instr_type f_copy_s_pos__insert_at_h0_front()
		{
			if constexpr (MI::is_opt(Pos)) return copy_s_pos__insert_at_h0_front_opt<Pos>;
			else return linear<LN::copy_s_pos__insert_at_h0_front, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type copy_s_pos__insert_at_h0_front = f_copy_s_pos__insert_at_h0_front<Pos>();
*/

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::copy_s_pos__insert_at_h0_back, filler...> : public linear_program<> // e1e
	{
		template<index_type Pos>
		static constexpr label_type result = label
		<
			move_s_segment__insert_at_h1_back<Pos>,
			copy_s_block__insert_at_h0_back<>, // first
			move_h1_all__insert_at_s_front<>,
			sleep<>
		>;
	};

		template<index_type Pos>
		static constexpr instr_type f_copy_s_pos__insert_at_h0_back()
		{
			if constexpr (MI::is_opt(Pos)) return copy_s_pos__insert_at_h0_back_opt<Pos>;
			else return linear<LN::copy_s_pos__insert_at_h0_back, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type copy_s_pos__insert_at_h0_back = f_copy_s_pos__insert_at_h0_back<Pos>();
*/

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::copy_s_pos__insert_at_h2_front, filler...> : public linear_program<> // e1e
	{
		template<index_type Pos>
		static constexpr label_type result = label
		<
			move_s_segment__insert_at_h1_back<Pos>,
			copy_s_block__insert_at_h2_front<>, // first
			move_h1_all__insert_at_s_front<>,
			sleep<>
		>;
	};

		template<index_type Pos>
		static constexpr instr_type f_copy_s_pos__insert_at_h2_front()
		{
			if constexpr (MI::is_opt(Pos)) return copy_s_pos__insert_at_h2_front_opt<Pos>;
			else return linear<LN::copy_s_pos__insert_at_h2_front, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type copy_s_pos__insert_at_h2_front = f_copy_s_pos__insert_at_h2_front<Pos>();
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (heap -> stack):

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::move_h0_first__insert_at_s_pos, filler...> : public linear_program<> // e1e
	{
		template<index_type Pos>
		static constexpr label_type result = label
		<
			move_s_segment__insert_at_h1_back<Pos>,
			move_h0_first__insert_at_s_front<>,
			move_h1_all__insert_at_s_front<>,
			sleep<>
		>;
	};

		template<index_type Pos>
		static constexpr instr_type f_move_h0_first__insert_at_s_pos()
		{
			if constexpr (MI::is_opt(Pos)) return move_h0_first__insert_at_s_pos_opt<Pos>;
			else return linear<LN::move_h0_first__insert_at_s_pos, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type move_h0_first__insert_at_s_pos = f_move_h0_first__insert_at_s_pos<Pos>();
*/

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::move_h0_first__replace_at_s_pos, filler...> : public linear_program<> // e1e
	{
		template<index_type Pos>
		static constexpr label_type result = label
		<
			move_s_segment__insert_at_h1_back<Pos>,
			drop_s_block<>, // first
			move_h0_first__insert_at_s_front<>,
			move_h1_all__insert_at_s_front<>,
			sleep<>
		>;
	};

		template<index_type Pos>
		static constexpr instr_type f_move_h0_first__replace_at_s_pos()
		{
			if constexpr (MI::is_opt(Pos)) return move_h0_first__replace_at_s_pos_opt<Pos>;
			else return linear<LN::move_h0_first__replace_at_s_pos, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type move_h0_first__replace_at_s_pos = f_move_h0_first__replace_at_s_pos<Pos>();
*/

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::move_h2_first__replace_at_s_pos, filler...> : public linear_program<> // e1e
	{
		template<index_type Pos>
		static constexpr label_type result = label
		<
			move_s_segment__insert_at_h1_back<Pos>,
			drop_s_block<>, // first
			move_h2_first__insert_at_s_front<>,
			move_h1_all__insert_at_s_front<>,
			sleep<>
		>;
	};

		template<index_type Pos>
		static constexpr instr_type f_move_h2_first__replace_at_s_pos()
		{
			if constexpr (MI::is_opt(Pos)) return move_h2_first__replace_at_s_pos_opt<Pos>;
			else return linear<LN::move_h2_first__replace_at_s_pos, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type move_h2_first__replace_at_s_pos = f_move_h2_first__replace_at_s_pos<Pos>();
*/

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::apply_h0_all__move__replace_at_s_pos, filler...> : public linear_program<> // e1e
	{
		template<index_type Pos>
		static constexpr label_type result = label
		<
			move_s_segment__insert_at_h1_back<Pos>,
			drop_s_block<>, // first
			apply_h0_all__move__insert_at_s_front<>,
			move_h1_all__insert_at_s_front<>,
			sleep<>
		>;
	};

		template<index_type Pos>
		static constexpr instr_type f_apply_h0_all__move__replace_at_s_pos()
		{
			if constexpr (MI::is_opt(Pos)) return apply_h0_all__move__replace_at_s_pos_opt<Pos>;
			else return linear<LN::apply_h0_all__move__replace_at_s_pos, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type apply_h0_all__move__replace_at_s_pos =
			f_apply_h0_all__move__replace_at_s_pos<Pos>();
*/

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::compel_h0_all__move__replace_at_s_pos, filler...> : public linear_program<> // e1e
	{
		template<index_type Pos>
		static constexpr label_type result = label
		<
			move_s_segment__insert_at_h1_back<Pos>,
			drop_s_block<>, // first
			compel_h0_all__move__insert_at_s_front<>,
			move_h1_all__insert_at_s_front<>,
			sleep<>
		>;
	};

		template<index_type Pos>
		static constexpr instr_type f_compel_h0_all__move__replace_at_s_pos()
		{
			if constexpr (MI::is_opt(Pos)) return compel_h0_all__move__replace_at_s_pos_opt<Pos>;
			else return linear<LN::compel_h0_all__move__replace_at_s_pos, _zero, Pos>;
		}

		template<index_type Pos>
		static constexpr instr_type compel_h0_all__move__replace_at_s_pos =
			f_compel_h0_all__move__replace_at_s_pos<Pos>();
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// mutators:

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::erase, filler...> : public linear_program<> // e1e
	{
		template<index_type Pos>
		static constexpr label_type result = label
		<
			drop_s_pos<Pos>,
			sleep<>
		>;
	};

		template<index_type Pos>
		static constexpr instr_type erase = linear
		<
			LN::erase, _zero, Pos
		>;
*/

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::insert, filler...> : public linear_program<> // e1e
	{
		template<index_type Pos, index_type Obj>
		static constexpr label_type result = label
		<
			copy_s_pos__insert_at_h0_front<Obj>,
			move_h0_first__insert_at_s_pos<Pos>,
			sleep<>
		>;
	};

		template<index_type Pos, index_type Obj>
		static constexpr instr_type insert = linear
		<
			LN::insert, _zero, Pos, Obj
		>;
*/

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::replace, filler...> : public linear_program<> // e1e
	{
		template<index_type Pos, index_type Obj>
		static constexpr label_type result = label
		<
			copy_s_pos__insert_at_h0_front<Obj>,
			move_h0_first__replace_at_s_pos<Pos>,
			sleep<>
		>;
	};

		template<index_type Pos, index_type Obj>
		static constexpr instr_type replace = linear
		<
			LN::replace, _zero, Pos, Obj
		>;

		template<index_type Pos, index_type Obj>
		static constexpr instr_type assign_using = linear // convenience
		<
			LN::replace, _zero, Pos, Obj
		>;
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// control:

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::go_to, filler...> : public linear_program<> // e1e
	{
		template<index_type Pos>
		static constexpr label_type result = label
		<
			copy_s_pos__insert_at_h0_front<Pos>,
			instruction<MN::pass, PT::reindex>
		>;
	};

		template<index_type Pos>
		static constexpr instr_type goto_using = linear
		<
			LN::go_to, _zero, Pos
		>;
*/

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::go_to_label, filler...> : public linear_program<>
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

		template<index_type Val>
		static constexpr instr_type goto_label = linear // shifts label value:
		<
			LN::go_to_label, _zero, Val+1
		>;
*/

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::assign_label, filler...> : public linear_program<> // e1e
	{
		template<index_type Pos, index_type Obj>
		static constexpr label_type result = label
		<
			copy_i_pos__insert_at_h0_front<Obj>,
			move_h0_first__replace_at_s_pos<Pos>,
			sleep<>
		>;
	};

		template<index_type Pos, index_type Val>
		static constexpr instr_type assign_label = linear // shifts label value:
		<
			LN::assign_label, _zero, Pos, Val+1
		>;
*/

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::save, filler...> : public linear_program<> // e1e
	{
		template<index_type... Args>
		static constexpr label_type result = label
		<
			copy_s_pos__insert_at_h2_front<Args>...,
			sleep<>
		>;
	};

		template<index_type... Args>
		static constexpr instr_type save = linear
		<
			LN::save, _zero, Args...
		>;
*/

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::restore, filler...> : public linear_program<> // e1e
	{
		template<index_type... Args>
		static constexpr label_type result = label
		<
			move_h2_first__replace_at_s_pos<Args>...,
			sleep<>
		>;
	};

		template<index_type... Args>
		static constexpr instr_type restore = linear
		<
			LN::restore, _zero, Args...
		>;
*/

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::test, filler...> : public linear_program<> // e2e
	{
		template<index_type Op, index_type... Args>
		static constexpr label_type result = label
		<
			copy_s_pos__insert_at_h0_back<Op>,
			copy_s_pos__insert_at_h0_back<Args>...,
			apply_h0_all__move__replace_at_h0_front<>,
			sleep<>
		>;
	};

		template<index_type Op, index_type... Args>
		static constexpr instr_type test = linear
		<
			LN::test, _zero, Op, Args...
		>;
*/

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::check, filler...> : public linear_program<> // e2e
	{
		template<index_type Op, index_type... Args>
		static constexpr label_type result = label
		<
			copy_s_pos__insert_at_h0_back<Op>,
			copy_s_pos__insert_at_h0_back<Args>...,
			compel_h0_all__move__replace_at_h0_front<>,
			sleep<>
		>;
	};

		template<index_type Act, index_type... Args>
		static constexpr instr_type check = linear
		<
			LN::check, _zero, Act, Args...
		>;
*/

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::apply, filler...> : public linear_program<> // e2e
	{
		template<index_type Pos, index_type Op, index_type... Args>
		static constexpr label_type result = label
		<
			copy_s_pos__insert_at_h0_back<Op>,
			copy_s_pos__insert_at_h0_back<Args>...,
			apply_h0_all__move__replace_at_s_pos<Pos>,
			sleep<>
		>;
	};

		template<index_type Pos, index_type Op, index_type... Args>
		static constexpr instr_type apply = linear
		<
			LN::apply, _zero, Pos, Op, Args...
		>;
*/

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::compel, filler...> : public linear_program<> // e2e
	{
		template<index_type Pos, index_type Op, index_type... Args>
		static constexpr label_type result = label
		<
			copy_s_pos__insert_at_h0_back<Op>,
			copy_s_pos__insert_at_h0_back<Args>...,
			compel_h0_all__move__replace_at_s_pos<Pos>,
			sleep<>
		>;
	};

		template<index_type Pos, index_type Act, index_type... Args>
		static constexpr instr_type compel = linear
		<
			LN::compel, _zero, Pos, Act, Args...
		>;
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

