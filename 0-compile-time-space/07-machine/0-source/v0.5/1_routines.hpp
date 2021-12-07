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

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// instructions:

public:

/***********************************************************************************************************************/

// interposers:

	template<key_type Note = MT::id>
	static constexpr instr_type pause = instruction
	<
		MN::pause, Note
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type save = instruction
	<
		MN::save, Note
	>;

		// call instructions are required by the stage2 machine to have mem, loc info.

	template<key_type Note, key_type Subname, key_type Subnote, key_type Mem, key_type Loc, index_type... Args>
	static constexpr instr_type call = instruction
	<
		MN::call, Note, Subname, Subnote, Mem, Loc, Args...
	>;

		// specifies block instructions:

		template
		<
			key_type Subname, key_type Mem, key_type Loc,
			index_type Pos, key_type Coname, key_type Conote
		>
		static constexpr instr_type call_block_program = call
		<
			MT::block, Subname, MT::id, Mem, Loc, Pos, Coname, Conote
		>;

		template<key_type Subname, key_type Subnote, key_type Mem, key_type Loc, index_type... Args>
		static constexpr instr_type call_linear_program = call
		<
			MT::linear, Subname, Subnote, Mem, Loc, Args...
		>;

		template<key_type Subname, key_type Subnote, key_type Mem, key_type Loc, index_type... Args>
		static constexpr instr_type call_user_program = call
		<
			MT::user, Subname, Subnote, Mem, Loc, Args...
		>;

	template<key_type Note = MT::id>
	static constexpr instr_type pass = instruction
	<
		MN::pass, Note
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type branch = instruction
	<
		MN::branch, Note
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type go_to = instruction
	<
		MN::go_to, Note
	>;

// halters:

	template<key_type Note = MT::id>
	static constexpr instr_type first = instruction
	<
		MN::first, Note
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type rest = instruction
	<
		MN::rest, Note
	>;

// debuggers:

	template<key_type Note = MT::id>
	static constexpr instr_type depth = instruction
	<
		MN::depth, Note
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type dump = instruction
	<
		MN::dump, Note
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type registers = instruction
	<
		MN::registers, Note
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type arguments = instruction
	<
		MN::arguments, Note
	>;

// passers:

	template<key_type Note = MT::id>
	static constexpr instr_type drop_r_block = instruction
	<
		MN::drop_r_block, Note
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type move_h0_first__insert_at_r_front = instruction
	<
		MN::move_h0_first__insert_at_r_front, Note
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type move_h1_all__insert_at_r_front = instruction
	<
		MN::move_h1_all__insert_at_r_front, Note
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type apply_h0_all__move__replace_at_h0_front = instruction
	<
		MN::apply_h0_all__move__insert_at_r_front, Note
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type apply_h0_all__move__insert_at_r_front = instruction
	<
		MN::apply_h0_all__move__insert_at_r_front, Note
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type compel_h0_all__move__replace_at_h0_front = instruction
	<
		MN::compel_h0_all__move__insert_at_r_front, Note
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type compel_h0_all__move__insert_at_r_front = instruction
	<
		MN::compel_h0_all__move__insert_at_r_front, Note
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block:

	// Block programs consist of two block instructions and some machine
	// modifiers: As such they can be optimized into a single instruction.

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers:

/***********************************************************************************************************************/

// unpack instruction segment, insert at heap one back:

	template<key_type... filler>
	struct block_program<BN::unpack_i_segment__insert_at_h1_back, filler...> : public block_program<filler...>
	{
		template<key_type Coname, key_type Conote>
		static constexpr instr_type controller = instruction
		<
			MN::unpack_i_block__insert_at_h1_back, MT::id,
			Coname, Conote
		>;
	};

	using bp_unpack_i_segment__insert_at_h1_back = block_program<BN::unpack_i_segment__insert_at_h1_back>;

/***********************************************************************************************************************/

// drop register segment:

	template<key_type... filler>
	struct block_program<BN::drop_r_segment, filler...> : public block_program<filler...>
	{
		template<key_type Coname, key_type Conote>
		static constexpr instr_type controller = instruction
		<
			MN::drop_r_block, MT::id,
			Coname, Conote
		>;
	};

	// interface:

		template
		<
			key_type Mem, key_type Loc,
			index_type Pos,
			key_type Coname, key_type Conote
		>
		static constexpr instr_type call__drop_r_segment = call_block_program
		<
			BN::drop_r_segment,
			Mem, Loc,
			Pos,
			Coname, Conote
		>;

		template<index_type Pos, key_type Loc>
		static constexpr instr_type call__copy_r_pos__insert_at_h0 = call__drop_r_segment
		<
			PM::heap_zero, Loc,
			Pos,
			MN::first, MT::id
		>;

	// syntactic sugar:

		template<index_type Pos, key_type Mem = PM::id, key_type Loc = PL::id>
		static constexpr instr_type call__at = call__drop_r_segment
		<
			Mem, Loc,
			Pos,
			MN::first, MT::id
		>;

		template<index_type Pos>
		static constexpr instr_type call__copy_r_pos__insert_at_h0_front = call__copy_r_pos__insert_at_h0
		<
			Pos, PL::front
		>;

		template<index_type Pos>
		static constexpr instr_type call__copy_r_pos__insert_at_h0_back = call__copy_r_pos__insert_at_h0
		<
			Pos, PL::back
		>;

/***********************************************************************************************************************/

// move register segment, insert at heap one back:

	template<key_type... filler>
	struct block_program<BN::move_r_segment__insert_at_h1_back, filler...> : public block_program<filler...>
	{
		template<key_type Coname, key_type Conote>
		static constexpr instr_type controller = instruction
		<
			MN::move_r_block__insert_at_h1_back, MT::id,
			Coname, Conote
		>;
	};

	// interface:

		template<index_type Pos>
		static constexpr instr_type call__move_r_segment__insert_at_h1_back = call_block_program
		<
			BN::move_r_segment__insert_at_h1_back,
			PM::stage2, PL::id,
			Pos,
			MN::pass, MT::id
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear:

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
			copy_r_pos__insert_at_h0_front<Pos>,
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

	// interface:

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
			move_h0_first__replace_at_r_pos<Pos>,
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
/***********************************************************************************************************************/

// mutators:

/***********************************************************************************************************************/

// erase:

	template<key_type... filler>
	struct linear_program<LN::erase, filler...> : public linear_program<filler...>
	{
		template<index_type Pos>
		static constexpr label_type controller = label
		<
			call__move_r_segment__insert_at_h1_back<Pos>,
			drop_r_block<>,
			move_h1_all__insert_at_r_front<>,
			pass<>
		>;
	};

	// interface:

		template<index_type Pos>
		static constexpr instr_type call__erase = call_linear_program
		<
			LN::erase, MT::id,
			PM::stage2, PL::id,
			Pos
		>;

/***********************************************************************************************************************/

// insert:

	template<key_type... filler>
	struct linear_program<LN::insert, filler...> : public linear_program<>
	{
		template<index_type Pos, index_type Obj>
		static constexpr label_type controller = label
		<
			call__copy_r_pos__insert_at_h0_front<Obj>,
			call__move_r_segment__insert_at_h1_back<Pos>,
			move_h0_first__insert_at_r_front<>,
			move_h1_all__insert_at_r_front<>,
			pass<>
		>;
	};

	// interface:

		template<index_type Pos, index_type Obj>
		static constexpr instr_type call__insert = call_linear_program
		<
			LN::insert, MT::id,
			PM::stage2, PL::id,
			Pos, Obj
		>;

/***********************************************************************************************************************/

// replace:

	template<key_type... filler>
	struct linear_program<LN::replace, filler...> : public linear_program<>
	{
		template<index_type Pos, index_type Obj>
		static constexpr label_type controller = label
		<
			call__copy_r_pos__insert_at_h0_front<Obj>,
			call__move_r_segment__insert_at_h1_back<Pos>,
			drop_r_block<>,
			move_h0_first__insert_at_r_front<>,
			move_h1_all__insert_at_r_front<>,
			pass<>
		>;
	};

	// interface:

		template<index_type Pos, index_type Obj>
		static constexpr instr_type call__replace = call_linear_program
		<
			LN::replace, MT::id,
			PM::stage2, PL::id,
			Pos, Obj
		>;

	// syntactic sugar:

		template<index_type Pos, index_type Obj>
		static constexpr instr_type assign_using = call__replace
		<
			Pos, Obj
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers:

/***********************************************************************************************************************/

// test:

	template<key_type... filler>
	struct linear_program<LN::test, filler...> : public linear_program<>
	{
		template<index_type Op, index_type... Args>
		static constexpr label_type controller = label
		<
			call__copy_r_pos__insert_at_h0_back<Op>,
			call__copy_r_pos__insert_at_h0_back<Args>...,
			apply_h0_all__move__replace_at_h0_front<>,
			pass<>
		>;
	};

	// interface:

		template<index_type Op, index_type... Args>
		static constexpr instr_type call__test = call_linear_program
		<
			LN::test, MT::id,
			PM::stage2, PL::id,
			Op, Args...
		>;

/***********************************************************************************************************************/

// check:

	template<key_type... filler>
	struct linear_program<LN::check, filler...> : public linear_program<>
	{
		template<index_type Op, index_type... Args>
		static constexpr label_type controller = label
		<
			call__copy_r_pos__insert_at_h0_back<Op>,
			call__copy_r_pos__insert_at_h0_back<Args>...,
			compel_h0_all__move__replace_at_h0_front<>,
			pass<>
		>;
	};

	// interface:

		template<index_type Op, index_type... Args>
		static constexpr instr_type call__check = call_linear_program
		<
			LN::check, MT::id,
			PM::stage2, PL::id,
			Op, Args...
		>;

/***********************************************************************************************************************/

// apply:

	template<key_type... filler>
	struct linear_program<LN::apply, filler...> : public linear_program<>
	{
		template<index_type Pos, index_type Op, index_type... Args>
		static constexpr label_type controller = label
		<
			call__copy_r_pos__insert_at_h0_back<Op>,
			call__copy_r_pos__insert_at_h0_back<Args>...,
			call__move_r_segment__insert_at_h1_back<Pos>,
			drop_r_block<>,
			apply_h0_all__move__insert_at_r_front<>,
			move_h1_all__insert_at_r_front<>,
			pass<>
		>;
	};

	// interface:

		template<index_type Pos, index_type Op, index_type... Args>
		static constexpr instr_type call__apply = call_linear_program
		<
			LN::apply, MT::id,
			PM::stage2, PL::id,
			Pos, Op, Args...
		>;

/***********************************************************************************************************************/

// compel:

	template<key_type... filler>
	struct linear_program<LN::compel, filler...> : public linear_program<>
	{
		template<index_type Pos, index_type Op, index_type... Args>
		static constexpr label_type controller = label
		<
			call__copy_r_pos__insert_at_h0_back<Op>,
			call__copy_r_pos__insert_at_h0_back<Args>...,
			call__move_r_segment__insert_at_h1_back<Pos>,
			drop_r_block<>,
			compel_h0_all__move__insert_at_r_front<>,
			move_h1_all__insert_at_r_front<>,
			pass<>
		>;
	};

	// interface:

		template<index_type Pos, index_type Op, index_type... Args>
		static constexpr instr_type call__compel = call_linear_program
		<
			LN::compel, MT::id,
			PM::stage2, PL::id,
			Pos, Op, Args...
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

