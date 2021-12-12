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

		// call instructions are required by the between machine to have mem, loc info.

	template<key_type Note, key_type Subname, key_type Mem, key_type Loc, index_type... Args>
	static constexpr instr_type call_program = instruction
	<
		MN::call, Note, Subname, Mem, Loc, Args...
	>;

		template<key_type Mem, key_type Loc, index_type... Args>
		static constexpr instr_type call_between_program = call_program
		<
			MT::between, MN::id, Mem, Loc, Args...
		>;

		template
		<
			key_type Subname, key_type Mem, key_type Loc,
			index_type Pos, key_type Coname, key_type Conote
		>
		static constexpr instr_type call_block_program = call_program
		<
			MT::block, Subname, Mem, Loc, Pos, Coname, Conote
		>;

		template<key_type Subname, key_type Mem, key_type Loc, index_type... Args>
		static constexpr instr_type call_linear_program = call_program
		<
			MT::linear, Subname, Mem, Loc, Args...
		>;

		template<index_type Pos, index_type Prog, index_type... Args>
		static constexpr instr_type call = call_program // call user program
		<
			MT::user, MN::id, PM::stage2, PL::id, Pos, Prog, Args...
		>;

	template<key_type Note = MT::id>
	static constexpr instr_type unwind = instruction
	<
		MN::unwind, Note
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type overwrite = instruction
	<
		MN::overwrite, Note
	>;

		template<key_type...>
		static constexpr instr_type reindex = overwrite
		<
			MT::reindex
		>;

	template<key_type Pos, key_type Note = MT::id>
	static constexpr instr_type branch = instruction
	<
		MN::branch, Note, Pos
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

	template<key_type Value, key_type Note = MT::id>
	static constexpr instr_type copy_i_value__insert_at_h0_front = instruction
	<
		MN::copy_i_value__insert_at_h0_front, Note, Value
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type drop_r_block = instruction
	<
		MN::drop_r_block, Note
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type fold_r_block = instruction
	<
		MN::fold_r_block, Note
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type roll_r_block = instruction
	<
		MN::roll_r_block, Note
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
	static constexpr instr_type apply_h0_all__return_value = instruction
	<
		MN::apply_h0_all__return_value, Note
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type apply_h0_all__move__insert_at_r_front = instruction
	<
		MN::apply_h0_all__move__insert_at_r_front, Note
	>;

	template<key_type Note = MT::id>
	static constexpr instr_type compel_h0_all__return_value = instruction
	<
		MN::compel_h0_all__return_value, Note
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

// unpack instruction segment, insert at heap zero back:

	template<key_type... filler>
	struct block_program<BN::unpack_i_segment__insert_at_h0_back, filler...> : public block_program<filler...>
	{
		template<key_type Coname, key_type Conote>
		static constexpr instr_type lines = instruction
		<
			MN::unpack_i_block__insert_at_h0_back, Coname, Conote
		>;
	};

	// interface:

		template<index_type Pos, key_type Conote>
		static constexpr instr_type unpack_i_segment__insert_at_h0_back = call_block_program
		<
			BN::unpack_i_segment__insert_at_h0_back,
			PM::stage2, PL::id,
			Pos,
			MN::make, Conote
		>;

	// syntactic sugar:

		template<key_type Conote>
		static constexpr instr_type make_unpack_i_segment__insert_at_h0_back =
			block_program<BN::unpack_i_segment__insert_at_h0_back>::template lines
			<
				MN::make, Conote
			>;

/***********************************************************************************************************************/

// drop register segment:

	template<key_type... filler>
	struct block_program<BN::drop_r_segment, filler...> : public block_program<filler...>
	{
		template<key_type Coname, key_type Conote>
		static constexpr instr_type lines = instruction
		<
			MN::drop_r_block, Coname, Conote
		>;
	};

	// interface:

		template
		<
			key_type Mem, key_type Loc,
			index_type Pos,
			key_type Coname, key_type Conote
		>
		static constexpr instr_type drop_r_segment = call_block_program
		<
			BN::drop_r_segment,
			Mem, Loc,
			Pos,
			Coname, Conote
		>;

		template<index_type Pos, key_type Loc>
		static constexpr instr_type copy_r_pos__insert_at_h0 = drop_r_segment
		<
			PM::heap_zero, Loc,
			Pos,
			MN::first, MT::id
		>;

	// syntactic sugar:

		template<index_type Pos, key_type Mem = PM::id, key_type Loc = PL::id>
		static constexpr instr_type at = drop_r_segment
		<
			Mem, Loc,
			Pos,
			MN::first, MT::id
		>;

		template<index_type Pos>
		static constexpr instr_type copy_r_pos__insert_at_h0_front = copy_r_pos__insert_at_h0
		<
			Pos, PL::front
		>;

		template<index_type Pos>
		static constexpr instr_type copy_r_pos__insert_at_h0_back = copy_r_pos__insert_at_h0
		<
			Pos, PL::back
		>;

/***********************************************************************************************************************/

// fold register segment:

	template<key_type... filler>
	struct block_program<BN::fold_r_segment, filler...> : public block_program<filler...>
	{
		template<key_type Coname, key_type Conote>
		static constexpr instr_type lines = instruction
		<
			MN::fold_r_block, Coname, Conote
		>;
	};

	// interface:

		template
		<
			index_type Pos,
			key_type Mem = PM::registers, key_type Loc = PL::front
		>
		static constexpr instr_type fold_r_segment = call_block_program
		<
			BN::fold_r_segment,
			Mem, Loc,
			Pos,
			MN::first, MT::id
		>;

/***********************************************************************************************************************/

// roll register segment:

	template<key_type... filler>
	struct block_program<BN::roll_r_segment, filler...> : public block_program<filler...>
	{
		template<key_type Coname, key_type Conote>
		static constexpr instr_type lines = instruction
		<
			MN::roll_r_block, Coname, Conote
		>;
	};

	// interface:

		template
		<
			index_type Pos,
			key_type Mem = PM::registers, key_type Loc = PL::front
		>
		static constexpr instr_type roll_r_segment = call_block_program
		<
			BN::roll_r_segment,
			Mem, Loc,
			Pos,
			MN::first, MT::id
		>;

/***********************************************************************************************************************/

// move register segment, insert at heap one back:

	template<key_type... filler>
	struct block_program<BN::move_r_segment__insert_at_h1_back, filler...> : public block_program<filler...>
	{
		template<key_type Coname, key_type Conote>
		static constexpr instr_type lines = instruction
		<
			MN::move_r_block__insert_at_h1_back, Coname, Conote
		>;
	};

	// interface:

		template<index_type Pos>
		static constexpr instr_type move_r_segment__insert_at_h1_back = call_block_program
		<
			BN::move_r_segment__insert_at_h1_back,
			PM::stage2, PL::id,
			Pos,
			MN::unwind, MT::id
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// interoperators:

/***********************************************************************************************************************/

// save:

//	template<key_type... filler>
//	struct linear_program<LN::save, filler...> : public T_linear_program
//	{
//		template<index_type... Args>
//		static constexpr label_type lines = label
//		<
//			copy_r_pos__insert_at_h2_back<Args>...
//		>;
//	};

	// interface:

		template<index_type... Args>
		static constexpr instr_type save = call_linear_program
		<
			LN::save,
			PM::stage2, PL::id,
			Args...
		>;

/***********************************************************************************************************************/

// make (user):

	template<key_type... filler>
	struct linear_program<LN::make, filler...> : public T_linear_program
	{
		template<index_type Obj, index_type Pos, index_type Size>
		static constexpr label_type lines = label
		<
			copy_r_pos__insert_at_h0_back<Obj>,
			move_r_segment__insert_at_h1_back<Pos>,
			unpack_i_segment__insert_at_h0_back<Size, MT::user>
		>;
	};

	// interface:

		template<index_type Obj, index_type Pos, index_type Size>
		static constexpr instr_type make_user_program = call_linear_program
		<
			LN::make,
			PM::stage2, PL::id,
			Pos, Obj, Size
		>;

/***********************************************************************************************************************/

// call (user):

	template<key_type... filler>
	struct linear_program<LN::call, filler...> : public T_linear_program
	{
		template<index_type Mem, index_type Loc>
		static constexpr label_type lines = label
		<
			call_between_program<Mem, Loc>,
			move_h1_all__insert_at_r_front<>,
			unwind<MT::user>
		>;
	};

	// interface:

		template<index_type Mem = PM::stage2, index_type Loc = PL::id>
		static constexpr instr_type call_user_program = call_linear_program
		<
			LN::call,
			Mem, Loc
		>;

/***********************************************************************************************************************/

// restore:

//	template<key_type... filler>
//	struct linear_program<LN::restore, filler...> : public T_linear_program
//	{
//		template<index_type... Args>
//		static constexpr label_type lines = label
//		<
//			copy_h2_front__insert_at_r_pos<Args>...
//		>;
//	};

	// interface:

		template<index_type... Args>
		static constexpr instr_type restore = call_linear_program
		<
			LN::restore,
			PM::stage2, PL::id,
			Args...
		>;

/***********************************************************************************************************************/

// instruction goto:

	template<key_type... filler>
	struct linear_program<LN::instr_goto, filler...> : public T_linear_program
	{
		template<index_type Pos>
		static constexpr label_type lines = label
		<
			copy_i_value__insert_at_h0_front<Pos>,
			reindex<>
		>;
	};

	// interface:

		template<index_type Pos>
		static constexpr instr_type instr_goto = call_linear_program
		<
			LN::instr_goto,
			PM::stage2, PL::id,
			Pos
		>;

/***********************************************************************************************************************/

// register goto:

	template<key_type... filler>
	struct linear_program<LN::regstr_goto, filler...> : public T_linear_program
	{
		template<index_type Pos>
		static constexpr label_type lines = label
		<
			copy_r_pos__insert_at_h0_front<Pos>,
			reindex<>
		>;
	};

	// interface:

		template<index_type Pos>
		static constexpr instr_type regstr_goto = call_linear_program
		<
			LN::regstr_goto,
			PM::stage2, PL::id,
			Pos
		>;

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
			drop_r_block<>,
			move_h1_all__insert_at_r_front<>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Pos>
		static constexpr instr_type erase = call_linear_program
		<
			LN::erase,
			PM::stage2, PL::id,
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
			PM::stage2, PL::id,
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
			drop_r_block<>,
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
			PM::stage2, PL::id,
			Pos, Obj
		>;

	// syntactic sugar:

		template<index_type Pos, index_type Obj>
		static constexpr instr_type regstr_assign = replace
		<
			Pos, Obj
		>;

/***********************************************************************************************************************/

// instruction assign:

	template<key_type... filler>
	struct linear_program<LN::instr_assign, filler...> : public T_linear_program
	{
		template<index_type Pos, index_type Obj>
		static constexpr label_type lines = label
		<
			copy_i_value__insert_at_h0_front<Obj>,
			move_r_segment__insert_at_h1_back<Pos>,
			drop_r_block<>,
			move_h0_first__insert_at_r_front<>,
			move_h1_all__insert_at_r_front<>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Pos, index_type Obj>
		static constexpr instr_type instr_assign = call_linear_program
		<
			LN::instr_assign,
			PM::stage2, PL::id,
			Pos, Obj
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers:

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
			apply_h0_all__return_value<>
		>;
	};

	// interface:

		template<index_type Op, index_type... Args>
		static constexpr instr_type test = call_linear_program
		<
			LN::test,
			PM::heap_zero, PL::front,
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
			compel_h0_all__return_value<>
		>;
	};

	// interface:

		template<index_type Op, index_type... Args>
		static constexpr instr_type check = call_linear_program
		<
			LN::check,
			PM::heap_zero, PL::front,
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
			drop_r_block<>,
			apply_h0_all__move__insert_at_r_front<>,
			move_h1_all__insert_at_r_front<>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Pos, index_type Op, index_type... Args>
		static constexpr instr_type apply = call_linear_program
		<
			LN::apply,
			PM::stage2, PL::id,
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
			drop_r_block<>,
			compel_h0_all__move__insert_at_r_front<>,
			move_h1_all__insert_at_r_front<>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Pos, index_type Op, index_type... Args>
		static constexpr instr_type compel = call_linear_program
		<
			LN::compel,
			PM::stage2, PL::id,
			Pos, Op, Args...
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

