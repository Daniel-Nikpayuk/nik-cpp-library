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

// halters:

	// value:

	template<key_type Note>
	static constexpr instr_type value = instruction
	<
		MN::value, Note
	>;

		template<key_type...> static constexpr instr_type first			= value < MT::first         >;
		template<key_type...> static constexpr instr_type rest			= value < MT::rest          >;
		template<key_type...> static constexpr instr_type depth			= value < MT::depth         >;
		template<key_type...> static constexpr instr_type dump			= value < MT::dump          >;
		template<key_type...> static constexpr instr_type registers		= value < MT::registers     >;
		template<key_type...> static constexpr instr_type arguments		= value < MT::arguments     >;

// interoperators:

	// call:

		// call instructions are required by the between machine to have mem, loc info.

	template<key_type Note, key_type Subname, key_type Policy, index_type... Args>
	static constexpr instr_type call_program = instruction
	<
		MN::call, Note, Subname, Policy, Args...
	>;

		template<key_type Subname, key_type Policy, index_type Pos, key_type Coname, key_type Conote>
		static constexpr instr_type call_block_program = call_program
		<
			MT::block, Subname, Policy, Pos, Coname, Conote
		>;

		template<key_type Subname, key_type Policy, index_type... Args>
		static constexpr instr_type call_linear_program = call_program
		<
			MT::linear, Subname, Policy, Args...
		>;

		template<index_type Pos, index_type Prog, index_type... Args>
		static constexpr instr_type call = call_program // call user program
		<
			MT::user, MN::id, MT::id, Pos, Prog, Args...
		>;

	// detour:

	template<key_type Note>
	static constexpr instr_type detour = instruction
	<
		MN::detour, Note
	>;

		template<key_type...> static constexpr instr_type internal	= detour < MT::call >;
		template<key_type...> static constexpr instr_type overwrite	= detour < MT::load >;

	//	template<key_type Policy, index_type... Args>
	//	static constexpr instr_type call_between_program = call_program
	//	<
	//		MT::between, MN::id, Policy, Args...
	//	>;

	// machinate:

	template<key_type Note>
	static constexpr instr_type machinate = instruction
	<
		MN::machinate, Note
	>;

		template<key_type...> static constexpr instr_type pause			= machinate < MT::pause   >;
		template<key_type...> static constexpr instr_type unwind_linear		= machinate < MT::linear  >;
		template<key_type...> static constexpr instr_type unwind_preuser	= machinate < MT::preuser >;
		template<key_type...> static constexpr instr_type unwind_user		= machinate < MT::user    >;
		template<key_type...> static constexpr instr_type unwind		= machinate < MT::unwind  >;
		template<key_type...> static constexpr instr_type reindex		= machinate < MT::reindex >;

// passers:

	// block:

	template<key_type...>
	static constexpr instr_type drop_r_block = instruction
	<
		MN::drop_r_block, MT::id
	>;

	template<key_type...>
	static constexpr instr_type fold_r_block = instruction
	<
		MN::fold_r_block, MT::id
	>;

	template<key_type...>
	static constexpr instr_type roll_r_block = instruction
	<
		MN::roll_r_block, MT::id
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

	// user:

	template<key_type Value>
	static constexpr instr_type copy_i_value__insert_at_h0_front = instruction
	<
		MN::copy_i_value, MT::insert_at_h0_front, Value
	>;

	template<key_type Pos>
	static constexpr instr_type branch = instruction
	<
		MN::branch, MT::id, Pos
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

	// syntactic sugar:

		// linear:

		template<key_type...>
		static constexpr instr_type make_linear_program =
			block_program<BN::unpack_i_segment__insert_at_h0_back>::template lines
			<
				MN::machinate, MT::linear
			>;

		// user:

		template<index_type Pos>
		static constexpr instr_type make_user_program = call_block_program
		<
			BN::unpack_i_segment__insert_at_h0_back,
			MT::call, // corresponds to an optimization.
			Pos,
			MN::machinate, MT::user
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

		template<key_type Policy, index_type Pos, key_type Coname, key_type Conote>
		static constexpr instr_type drop_r_segment = call_block_program
		<
			BN::drop_r_segment,
			Policy,
			Pos,
			Coname, Conote
		>;

	// syntactic sugar:

		template<index_type Pos>
		static constexpr instr_type at = drop_r_segment
		<
			MT::id,
			Pos,
			MN::value, MT::first
		>;

		template<index_type Pos>
		static constexpr instr_type copy_r_pos__insert_at_h0_front = drop_r_segment
		<
			MT::insert_at_h0_front,
			Pos,
			MN::value, MT::first
		>;

		template<index_type Pos>
		static constexpr instr_type copy_r_pos__insert_at_h0_back = drop_r_segment
		<
			MT::insert_at_h0_back,
			Pos,
			MN::value, MT::first
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
			MT::load,
			Pos,
			MN::machinate, MT::unwind
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

		template<key_type Policy, index_type Pos>
		static constexpr instr_type fold_r_segment = call_block_program
		<
			BN::fold_r_segment,
			Policy,
			Pos,
			MN::value, MT::first
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

		template<key_type Policy, index_type Pos>
		static constexpr instr_type roll_r_segment = call_block_program
		<
			BN::roll_r_segment,
			Policy,
			Pos,
			MN::value, MT::first
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear:

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
			MT::load,
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
			MT::load,
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
			MT::load,
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
			MT::call, // ?
			Pos, Obj
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// interoperators:

/***********************************************************************************************************************/

// run (user):

	template<key_type... filler>
	struct linear_program<LN::run, filler...> : public T_linear_program
	{
		template<index_type Obj, index_type Pos, index_type Size>
		static constexpr label_type lines = label
		<
			copy_r_pos__insert_at_h0_back<Obj>,
			move_r_segment__insert_at_h1_back<Pos>,
			make_user_program<Size>
		>;
	};

	// interface:

		template<index_type Obj, index_type Pos, index_type Size>
		static constexpr instr_type run_user_program = call_linear_program
		<
			LN::run,
			MT::load,
			Pos, Obj, Size
		>;

/***********************************************************************************************************************/

// call (user):

/*
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

		template<index_type...>
		static constexpr instr_type call_user_program = call_linear_program
		<
			LN::call,
			MT::singleton
		>;
*/

/***********************************************************************************************************************/

// instruction goto:

/*
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
			MT::call, // ?
			Pos
		>;
*/

/***********************************************************************************************************************/

// register goto:

/*
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
			MT::call, // ?
			Pos
		>;
*/

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
			apply_h0_all__replace_at_h0_front<>,
			unwind<>
		>;
	};

	// interface:

		template<index_type Op, index_type... Args>
		static constexpr instr_type test = call_linear_program
		<
			LN::test,
			MT::load,
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
			MT::load,
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
			MT::load,
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
			MT::load,
			Pos, Op, Args...
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

