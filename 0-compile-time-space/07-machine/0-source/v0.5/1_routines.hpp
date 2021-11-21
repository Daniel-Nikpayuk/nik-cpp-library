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

	template<key_type Note, key_type Subname, index_type... Args>
	static constexpr instr_type pose = instruction
	<
		MN::pose, Note, Subname, Args...
	>;

		// specifies block instructions:

		template<key_type Subname, key_type Mem, key_type Loc>
		static constexpr instr_type pose_block = pose
		<
			MT::block, Subname, Mem, Loc
		>;

		template<key_type Subname, key_type Subnote, index_type... Args>
		static constexpr instr_type pose_linear = pose
		<
			MT::linear, Subname, Subnote, Args...
		>;

		template<key_type Subname, key_type Subnote, index_type... Args>
		static constexpr instr_type pose_turing = pose
		<
			MT::turing, Subname, Subnote, Args...
		>;

		template<key_type Subname, key_type Subnote, index_type... Args>
		static constexpr instr_type pose_user = pose
		<
			MT::user, Subname, Subnote, Args...
		>;

	template<key_type Note, key_type Subname, index_type... Args>
	static constexpr instr_type load = instruction
	<
		MN::load, Note, Subname, Args...
	>;

		// specifies block instructions:

		template<key_type Subname, key_type Mem, key_type Loc, index_type Pos>
		static constexpr instr_type load_block = load
		<
			MT::block, Subname, Mem, Loc, Pos
		>;

		template<key_type Subname, key_type Subnote, index_type... Args>
		static constexpr instr_type load_linear = load
		<
			MT::linear, Subname, Subnote, Args...
		>;

		template<key_type Subname, key_type Subnote, index_type... Args>
		static constexpr instr_type load_turing = load
		<
			MT::turing, Subname, Subnote, Args...
		>;

		template<key_type Subname, key_type Subnote, index_type... Args>
		static constexpr instr_type load_user = load
		<
			MT::user, Subname, Subnote, Args...
		>;

	template<key_type Note = _zero>
	static constexpr instr_type reload = instruction
	<
		MN::reload, Note
	>;

	template<key_type Note = _zero, key_type Mem = MM::na, key_type Loc = MM::na>
	static constexpr instr_type call = instruction
	<
		MN::call, Note, Mem, Loc
	>;

		template<key_type Note = _zero>
		static constexpr instr_type call__insert_at_s_front = call
		<
			Note, MM::stack, MM::front
		>;

	template<key_type Note = _zero>
	static constexpr instr_type pass = instruction
	<
		MN::pass, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type ship = instruction
	<
		MN::ship, Note
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

// halters:

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

	template<key_type Note = _zero>
	static constexpr instr_type unpack_i_block = instruction
	<
		MN::unpack_i_block, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type drop_s_block = instruction
	<
		MN::drop_s_block, Note
	>;

	template<key_type Mem, key_type Loc, key_type Note = _zero>
	static constexpr instr_type move_s_block = instruction
	<
		MN::move_s_block, Note, Mem, Loc
	>;

	template<key_type Mem, key_type Loc, key_type Note = _zero>
	static constexpr instr_type move_h0_all = instruction
	<
		MN::move_h0_all, Note, Mem, Loc
	>;

	template<key_type Mem, key_type Loc, key_type Note = _zero>
	static constexpr instr_type move_h1_all = instruction
	<
		MN::move_h1_all, Note, Mem, Loc
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers:

/***********************************************************************************************************************/

// :

	template<key_type... filler>
	struct block_program<BN::unpack_i_segment, filler...> : public block_program<filler...>
	{
		template<key_type Mem, key_type Loc>
		static constexpr instr_type controller = instruction<MN::unpack_i_block, MN::pass, Mem, Loc>;
	};

		template<index_type = _zero>
		static constexpr instr_type pose__unpack_i_segment = pose_block
		<
			BN::unpack_i_segment, MM::heap_zero, MM::back
		>;

		template<index_type Pos>
		static constexpr instr_type load__unpack_i_segment = load_block
		<
			BN::unpack_i_segment, MM::heap_zero, MM::back, Pos
		>;

/***********************************************************************************************************************/

// :

	template<key_type... filler>
	struct block_program<BN::drop_s_segment, filler...> : public block_program<filler...>
	{
		template<key_type Mem, key_type Loc>
		static constexpr instr_type controller = instruction<MN::drop_s_block, MN::pass, Mem, Loc>;
	};

		template<index_type = _zero>
		static constexpr instr_type pose__drop_s_segment = pose_block
		<
			BN::drop_s_segment, MM::not_applicable, MM::not_applicable
		>;

		template<index_type Pos>
		static constexpr instr_type load__drop_s_segment = load_block
		<
			BN::drop_s_segment, MM::not_applicable, MM::not_applicable, Pos
		>;

/***********************************************************************************************************************/

// :

	template<key_type... filler>
	struct block_program<BN::move_s_segment, filler...> : public block_program<filler...>
	{
		template<key_type Mem, key_type Loc>
		static constexpr instr_type controller = instruction<MN::move_s_block, MN::pass, Mem, Loc>;
	};

		template<key_type Mem, key_type Loc>
		static constexpr instr_type pose__move_s_segment = pose_block
		<
			BN::move_s_segment, Mem, Loc
		>;

		template<key_type Mem, key_type Loc, index_type Pos>
		static constexpr instr_type load__move_s_segment = load_block
		<
			BN::move_s_segment, Mem, Loc, Pos
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers:

/***********************************************************************************************************************/

// :

/*
	template<key_type... filler>
	struct linear_program<LN::apply_h0_all__move__replace_at_s_pos, filler...> : public linear_program<> // e1e
	{
		template<index_type Pos>
		static constexpr label_type controller = label
		<
			move_s_segment__insert_at_h1_back<Pos>,
			drop_s_block<>, // first
			apply_h0_all__move__insert_at_s_front<>,
			move_h1_all__insert_at_s_front<>,
			pass<>
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
		static constexpr label_type controller = label
		<
			move_s_segment__insert_at_h1_back<Pos>,
			drop_s_block<>, // first
			compel_h0_all__move__insert_at_s_front<>,
			move_h1_all__insert_at_s_front<>,
			pass<>
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
		static constexpr label_type controller = label
		<
			drop_s_pos<Pos>,
			pass<>
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
		static constexpr label_type controller = label
		<
			copy_s_pos__insert_at_h0_front<Obj>,
			move_h0_first__insert_at_s_pos<Pos>,
			pass<>
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
		static constexpr label_type controller = label
		<
			copy_s_pos__insert_at_h0_front<Obj>,
			move_h0_first__replace_at_s_pos<Pos>,
			pass<>
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
		static constexpr label_type controller = label
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
		static constexpr label_type controller = label
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
		static constexpr label_type controller = label
		<
			copy_i_pos__insert_at_h0_front<Obj>,
			move_h0_first__replace_at_s_pos<Pos>,
			pass<>
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
		static constexpr label_type controller = label
		<
			copy_s_pos__insert_at_h2_front<Args>...,
			pass<>
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
		static constexpr label_type controller = label
		<
			move_h2_first__replace_at_s_pos<Args>...,
			pass<>
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
		static constexpr label_type controller = label
		<
			copy_s_pos__insert_at_h0_back<Op>,
			copy_s_pos__insert_at_h0_back<Args>...,
			apply_h0_all__move__replace_at_h0_front<>,
			pass<>
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
		static constexpr label_type controller = label
		<
			copy_s_pos__insert_at_h0_back<Op>,
			copy_s_pos__insert_at_h0_back<Args>...,
			compel_h0_all__move__replace_at_h0_front<>,
			pass<>
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
		static constexpr label_type controller = label
		<
			copy_s_pos__insert_at_h0_back<Op>,
			copy_s_pos__insert_at_h0_back<Args>...,
			apply_h0_all__move__replace_at_s_pos<Pos>,
			pass<>
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
		static constexpr label_type controller = label
		<
			copy_s_pos__insert_at_h0_back<Op>,
			copy_s_pos__insert_at_h0_back<Args>...,
			compel_h0_all__move__replace_at_s_pos<Pos>,
			pass<>
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

