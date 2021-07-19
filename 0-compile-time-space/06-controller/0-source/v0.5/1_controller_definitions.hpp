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

// controller definitions source:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block controller:

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
		static constexpr instr_type drop_s_block = instruction
		<
			MN::drop_s_block, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_s_block__insert_at_s_back = instruction
		<
			MN::move_s_block__insert_at_s_back, Note
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
		static constexpr instr_type copy_s_block__insert_at_h0_front = instruction
		<
			MN::copy_s_block__insert_at_h0_front, Note
		>;

	// interposers:

		template<key_type Arch, key_type Name, index_type... Vs>
		static constexpr instr_type call = instruction
		<
			MN::call, Arch, Name, Vs...
		>;

			template<key_type Name, index_type Pos>
			static constexpr instr_type block_call		= call<CallNote::block, Name, Pos>;

			template<key_type Name, index_type... Vs>
			static constexpr instr_type linear_call		= call<CallNote::linear, Name, Vs...>;

			template<key_type Name, index_type... Vs>
			static constexpr instr_type user_call		= call<CallNote::user, Name, Vs...>;

		template<key_type Note = _zero>
		static constexpr instr_type pass = instruction
		<
			MN::pass, Note
		>;

/***********************************************************************************************************************/

// names:

	struct BlockName
	{
		// halters:

			static constexpr key_type stop						=  0;

		// passers:

			// stack -> stack:

			static constexpr key_type drop_s_segment				=  1;
			static constexpr key_type move_s_segment__insert_at_s_back		=  2;

			static constexpr key_type fold_s_segment__pos_at_h0_first		=  3;
			static constexpr key_type roll_s_segment__pos_at_h0_first		=  4;

			// stack -> heap:

			static constexpr key_type move_s_segment__insert_at_h0_back		=  5;
			static constexpr key_type move_s_segment__insert_at_h1_back		=  6;
	};

	using BN = BlockName;

/***********************************************************************************************************************/

// inventory:

	template<key_type, key_type...> struct block_controller;

	//

	template<key_type... filler>
	struct block_controller<BN::stop, filler...>
	{
		template<key_type Cont = MN::first>
		static constexpr instr_type result = instruction<MN::drop_s_block, Cont>;
	};

	template<key_type... filler>
	struct block_controller<BN::drop_s_segment, filler...>
	{
		template<key_type Cont = MN::pass>
		static constexpr instr_type result = instruction<MN::drop_s_block, Cont>;
	};

	template<key_type... filler>
	struct block_controller<BN::move_s_segment__insert_at_s_back, filler...>
	{
		template<key_type Cont = MN::pass>
		static constexpr instr_type result = instruction<MN::move_s_block__insert_at_s_back, Cont>;
	};

	template<key_type... filler>
	struct block_controller<BN::fold_s_segment__pos_at_h0_first, filler...>
	{
		template<key_type Cont = MN::pass>
		static constexpr instr_type result = instruction<MN::fold_s_block__op_at_h0_first, Cont>;
	};

	template<key_type... filler>
	struct block_controller<BN::roll_s_segment__pos_at_h0_first, filler...>
	{
		template<key_type Cont = MN::pass>
		static constexpr instr_type result = instruction<MN::roll_s_block__act_at_h0_first, Cont>;
	};

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

// syntactic sugar:

	// halters:

		template<index_type Pos>
		static constexpr instr_type stop = block_call
		<
			BN::stop, Pos
		>;

	// passers:

		// stack -> stack:

		template<index_type Pos>
		static constexpr instr_type drop_s_segment = block_call
		<
			BN::drop_s_segment, Pos
		>;

		template<index_type Pos>
		static constexpr instr_type move_s_segment__insert_at_s_back = block_call
		<
			BN::move_s_segment__insert_at_s_back, Pos
		>;

	//	template<index_type Pos>
	//	static constexpr instr_type fold_s_segment__pos_at_h0_first = block_call
	//	<
	//		BN::fold_s_segment__pos_at_h0_first, Pos
	//	>;

	//	template<index_type Pos>
	//	static constexpr instr_type roll_s_segment__pos_at_h0_first = block_call
	//	<
	//		BN::roll_s_segment__pos_at_h0_first, Pos
	//	>;

		// stack -> heap:

		template<index_type Pos>
		static constexpr instr_type move_s_segment__insert_at_h0_back = block_call
		<
			BN::move_s_segment__insert_at_h0_back, Pos
		>;

		template<index_type Pos>
		static constexpr instr_type move_s_segment__insert_at_h1_back = block_call
		<
			BN::move_s_segment__insert_at_h1_back, Pos
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// variadic controller:

/***********************************************************************************************************************/

// instructions:

	// halters:

		// none.

	// passers:

		// stack -> stack:

	//	template<key_type Note = _zero>
	//	static constexpr instr_type fold_s_segment__pos_at_h0_first = instruction
	//	<
	//		MN::fold_s_segment__pos_at_h0_first, Note
	//	>;

	//	template<key_type Note = _zero>
	//	static constexpr instr_type roll_s_segment__pos_at_h0_first = instruction
	//	<
	//		MN::roll_s_segment__pos_at_h0_first, Note
	//	>;

		// stack -> heap:

		// none.

		// heap -> stack:

		template<key_type Note = _zero>
		static constexpr instr_type move_h0_all__insert_at_s_front = instruction
		<
			MN::move_h0_all__insert_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type move_h1_all__insert_at_s_front = instruction
		<
			MN::move_h1_all__insert_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type copy_h0_all__insert_at_s_front = instruction
		<
			MN::copy_h0_all__insert_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type copy_h1_all__insert_at_s_front = instruction
		<
			MN::copy_h1_all__insert_at_s_front, Note
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
		static constexpr instr_type compel_h0_all__move__insert_at_s_front = instruction
		<
			MN::compel_h0_all__move__insert_at_s_front, Note
		>;

		template<key_type Note = _zero>
		static constexpr instr_type compel_h0_all__replace_h0_all = instruction
		<
			MN::compel_h0_all__replace_h0_all, Note
		>;

/***********************************************************************************************************************/

// names:

	struct VN
	{
		// passers:

			// stack -> stack:

			static constexpr key_type drop_s_pos					= 0;
			static constexpr key_type move_s_pos__insert_at_s_back			= 1;

			// stack -> heap:

			static constexpr key_type move_s_pos__insert_at_h0_front		= 2;
			static constexpr key_type copy_s_pos__insert_at_h0_front		= 3;

			// heap -> stack:

			static constexpr key_type move_h0_all__insert_at_s_pos			= 4;
			static constexpr key_type move_h0_all__replace_at_s_pos			= 5;

			static constexpr key_type apply_h0_all__move__replace_at_s_pos		= 6;
			static constexpr key_type compel_h0_all__move__replace_at_s_pos		= 7;
	};

/***********************************************************************************************************************/

// inventory:

	template<key_type, key_type...> struct variadic_controller;

	//

	template<key_type... filler>
	struct variadic_controller<VN::drop_s_pos, filler...>
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
	struct variadic_controller<VN::move_s_pos__insert_at_s_back, filler...>
	{
		template<index_type Pos, instr_type Cont = pass<>>
		static constexpr label_type result = label
		<
			move_s_segment__insert_at_h0_back<Pos>,
			move_s_block__insert_at_s_back<>,
			move_h0_all__insert_at_s_front<>,
			Cont
		>;
	};

	template<key_type... filler>
	struct variadic_controller<VN::move_s_pos__insert_at_h0_front, filler...>
	{
		template<index_type Obj, instr_type Cont = pass<>>
		static constexpr label_type result = label
		<
			move_s_segment__insert_at_h1_back<Obj>,
			move_s_block__insert_at_h0_front<>,
			move_h1_all__insert_at_s_front<>,
			Cont
		>;
	};

	template<key_type... filler>
	struct variadic_controller<VN::copy_s_pos__insert_at_h0_front, filler...>
	{
		template<index_type Obj, instr_type Cont = pass<>>
		static constexpr label_type result = label
		<
			move_s_segment__insert_at_h1_back<Obj>,
			copy_s_block__insert_at_h0_front<>,
			move_h1_all__insert_at_s_front<>,
			Cont
		>;
	};

	template<key_type... filler>
	struct variadic_controller<VN::move_h0_all__insert_at_s_pos, filler...>
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
	struct variadic_controller<VN::move_h0_all__replace_at_s_pos, filler...>
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
	struct variadic_controller<VN::apply_h0_all__move__replace_at_s_pos, filler...>
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
	struct variadic_controller<VN::compel_h0_all__move__replace_at_s_pos, filler...>
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

// syntactic sugar:

		template<index_type Pos>
		static constexpr instr_type drop_s_pos = linear_call
		<
			VN::drop_s_pos, MI::patch(Pos), Pos
		>;

		template<index_type Pos, key_type Note = _zero>
		static constexpr instr_type move_s_pos__insert_at_s_back = linear_call
		<
			VN::move_s_pos__insert_at_s_back, Note, Pos
		>;

		template<index_type Obj>
		static constexpr instr_type move_s_pos__insert_at_h0_front = linear_call
		<
			VN::move_s_pos__insert_at_h0_front, MI::patch(Obj), Obj
		>;

		template<index_type Obj>
		static constexpr instr_type copy_s_pos__insert_at_h0_front = linear_call
		<
			VN::copy_s_pos__insert_at_h0_front, MI::patch(Obj), Obj
		>;

		template<index_type Pos>
		static constexpr instr_type move_h0_all__insert_at_s_pos = linear_call
		<
			VN::move_h0_all__insert_at_s_pos, MI::patch(Pos), Pos
		>;

		template<index_type Pos>
		static constexpr instr_type move_h0_all__replace_at_s_pos = linear_call
		<
			VN::move_h0_all__replace_at_s_pos, MI::patch(Pos), Pos
		>;

		template<index_type Pos>
		static constexpr instr_type apply_h0_all__move__replace_at_s_pos = linear_call
		<
			VN::apply_h0_all__move__replace_at_s_pos, MI::patch(Pos), Pos
		>;

		template<index_type Pos>
		static constexpr instr_type compel_h0_all__move__replace_at_s_pos = linear_call
		<
			VN::compel_h0_all__move__replace_at_s_pos, MI::patch(Pos), Pos
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// permutatic controller:

/***********************************************************************************************************************/

// names:

	struct PN
	{
		// passers:

			static constexpr key_type erase			= 0;
			static constexpr key_type insert		= 1;
			static constexpr key_type replace		= 2;

			static constexpr key_type apply_replace		= 3;
			static constexpr key_type compel_replace	= 4;
			static constexpr key_type test_replace		= 5;
			static constexpr key_type check_replace		= 6;
	};

/***********************************************************************************************************************/

// instructions:

	// skip

/***********************************************************************************************************************/

// inventory:

	template<key_type, key_type...> struct permutatic_controller;

	//

	template<key_type... filler>
	struct permutatic_controller<PN::erase, filler...>
	{
		template<index_type Pos, instr_type Cont = pass<>>
		static constexpr label_type result = label
		<
			drop_s_pos<Pos>,
			Cont
		>;
	};

	template<key_type... filler>
	struct permutatic_controller<PN::insert, filler...>
	{
		template<index_type Pos, index_type Obj, instr_type Cont = pass<>>
		static constexpr label_type result = label
		<
			copy_s_pos__insert_at_h0_front<Obj>,
			move_h0_all__insert_at_s_pos<Pos>,	// includes undefined behaviour.
			Cont
		>;
	};

	template<key_type... filler>
	struct permutatic_controller<PN::replace, filler...>
	{
		template<index_type Pos, index_type Obj, instr_type Cont = pass<>>
		static constexpr label_type result = label
		<
			copy_s_pos__insert_at_h0_front<Obj>,
			move_h0_all__replace_at_s_pos<Pos>,	// includes undefined behaviour.
			Cont
		>;
	};

	template<key_type... filler>
	struct permutatic_controller<PN::apply_replace, filler...>
	{
		template<index_type Pos, index_type Op, index_type... RArgs>
		static constexpr label_type result = label
		<
			copy_s_pos__insert_at_h0_front<RArgs>...,

			copy_s_pos__insert_at_h0_front<Op>,
			apply_h0_all__move__replace_at_s_pos<Pos>,	// includes undefined behaviour.
			pass<>
		>;
	};

	template<key_type... filler>
	struct permutatic_controller<PN::compel_replace, filler...>
	{
		template<index_type Pos, index_type Op, index_type... RArgs>
		static constexpr label_type result = label
		<
			copy_s_pos__insert_at_h0_front<RArgs>...,

			copy_s_pos__insert_at_h0_front<Op>,
			compel_h0_all__move__replace_at_s_pos<Pos>,	// includes undefined behaviour.
			pass<>
		>;
	};

	template<key_type... filler>
	struct permutatic_controller<PN::test_replace, filler...>
	{
		template<index_type Op, index_type... RArgs>
		static constexpr label_type result = label
		<
			copy_s_pos__insert_at_h0_front<RArgs>...,

			copy_s_pos__insert_at_h0_front<Op>,
			apply_h0_all__replace_h0_all<>,			// includes undefined behaviour.
			pass<>
		>;
	};

	template<key_type... filler>
	struct permutatic_controller<PN::check_replace, filler...>
	{
		template<index_type Op, index_type... RArgs>
		static constexpr label_type result = label
		<
			copy_s_pos__insert_at_h0_front<RArgs>...,

			copy_s_pos__insert_at_h0_front<Op>,
			compel_h0_all__replace_h0_all<>,		// includes undefined behaviour.
			pass<>
		>;
	};

/***********************************************************************************************************************/

// syntactic sugar:

	//	template<index_type Pos>
	//	static constexpr instr_type  = linear_call
	//	<
	//		VN::, MI::patch(Pos), Pos
	//	>;

	//	template<index_type Pos>
	//	static constexpr instr_type erase = linear_call
	//	<
	//		LN::erase, Pos
	//	>;

	//	template<index_type Pos>
	//	static constexpr instr_type insert = linear_call
	//	<
	//		LN::insert, Pos
	//	>;

	//	template<index_type Pos>
	//	static constexpr instr_type replace = linear_call
	//	<
	//		LN::replace, Pos
	//	>;

	//	template<index_type Pos>
	//	static constexpr instr_type apply_replace = linear_call
	//	<
	//		LN::apply_replace, Pos
	//	>;

	//	template<index_type Pos>
	//	static constexpr instr_type compel_replace = linear_call
	//	<
	//		LN::compel_replace, Pos
	//	>;

	//	template<index_type Pos>
	//	static constexpr instr_type test_replace = linear_call
	//	<
	//		LN::test_replace, Pos
	//	>;

	//	template<index_type Pos>
	//	static constexpr instr_type check_replace = linear_call
	//	<
	//		LN::check_replace, Pos
	//	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// distributic controller:

/***********************************************************************************************************************/

// names:

	struct DN
	{
		// halters:

			static constexpr key_type halt			= 0;

		// passers:

			static constexpr key_type size_of		= 1;
			static constexpr key_type clear			= 2;
			static constexpr key_type map			= 3;
			static constexpr key_type plot			= 4;
			static constexpr key_type align			= 5;

			static constexpr key_type lift			= 6;
			static constexpr key_type stem			= 7;
			static constexpr key_type costem		= 8;
			static constexpr key_type cycle			= 9;

		// constants:

			static constexpr instr_type lift_instr		= instruction<lift, _zero>;
			static constexpr instr_type stem_instr		= instruction<stem, _zero>;
			static constexpr instr_type halt_instr		= instruction<halt, _zero>;
			static constexpr instr_type cycle_instr		= instruction<cycle, _zero>;
	};

/***********************************************************************************************************************/

// instructions:

	// passers:

	//	template<index_type Pos, key_type Note = _zero>
	//	static constexpr instr_type erase = instruction
	//	<
	//		MN::erase, Note, Pos
	//	>;

	//	template<index_type Pos, index_type Obj, key_type Note = _zero>
	//	static constexpr instr_type insert = instruction
	//	<
	//		MN::insert, Note, Pos, Obj
	//	>;

	//	template<index_type Pos, index_type Obj, key_type Note = _zero>
	//	static constexpr instr_type replace = instruction
	//	<
	//		MN::replace, Note, Pos, Obj
	//	>;

	////	template<index_type Pos, index_type Op, key_type Note = _zero>
	////	static constexpr instr_type fold = instruction
	////	<
	////		MN::fold, Note, Pos, Op
	////	>;

	////	template<index_type Pos, index_type Op, key_type Note = _zero>
	////	static constexpr instr_type roll = instruction
	////	<
	////		MN::roll, Note, Pos, Op
	////	>;

	//	template<index_type Pos, index_type Op, index_type... Args>
	//	static constexpr instr_type apply = instruction
	//	<
	//		MN::apply, MI::arity(sizeof...(Args)), Pos, Op, Args...
	//	>;

	//	template<index_type Pos, index_type Op, index_type... Args>
	//	static constexpr instr_type compel = instruction
	//	<
	//		MN::compel, MI::arity(sizeof...(Args)), Pos, Op, Args...
	//	>;

	//	template<index_type Op, index_type... Args>
	//	static constexpr instr_type test = instruction
	//	<
	//		MN::test, MI::arity(sizeof...(Args)), Op, Args...
	//	>;

	//	template<index_type Op, index_type... Args>
	//	static constexpr instr_type check = instruction
	//	<
	//		MN::check, MI::arity(sizeof...(Args)), Op, Args...
	//	>;

	//	template<key_type Note = MI::unary>
	//	static constexpr instr_type skip = instruction
	//	<
	//		MN::skip, Note
	//	>;

/***********************************************************************************************************************/

// inventory:

	template<key_type, key_type...> struct distributic_controller;

	//

	// template<key_type... filler>
	// struct distributic_controller<DN::drop_s_block, filler...>
	// {
	// 	template<instr_type Cont = pass<>>
	// 	static constexpr auto result = linear_controller<drop_s_block<>, Cont>;
	// };

	// step:

	//	template<da_type Appl, da_type Cont = pass<>>
	//	static constexpr auto step_contr = distributic_controller<Appl, Cont>;

	// skip:

	//	template<da_type Test, da_type Ante, da_type Conse, da_type Cont = pass<>>
	//	static constexpr auto skip_contr = distributic_controller<Test, skip<MI::binary>, Ante, Cont, Conse, Cont>;

	// left:

	//	template<index_type Pos, pa_type Cont = pass<>>
	//	static constexpr auto left_contr = permutatic_controller
	//	<

	//	>;

/***********************************************************************************************************************/

// syntactic sugar:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// near linear controller:

/***********************************************************************************************************************/

// names:

	struct NN
	{
		// passers:

			static constexpr key_type assign				= 0;

			static constexpr key_type branch				= 1;
			static constexpr key_type go_to__next_at_h0_front		= 2;
			static constexpr key_type go_to					= 3;

			static constexpr key_type save					= 4;
			static constexpr key_type restore				= 5;
	};

/***********************************************************************************************************************/

// instructions:

	// syntactic sugar:

	//	template<na_type N>
	//	static constexpr np_type n_lift = n_continuation<NP::lift, N>;

	//	template<na_type P, na_type B, na_type N>
	//	static constexpr np_type n_stem = n_continuation<NP::stem, P, B, N>;

	//	template<na_type B>
	//	static constexpr np_type n_halt = n_continuation<NP::halt, B>;

	//	static constexpr np_type n_cycle = n_continuation<NP::cycle>;

	// passers:

	//	template<key_type Note = _zero>
	//	static constexpr instr_type size_of = instruction
	//	<
	//		MN::size_of, Note
	//	>;

	//	template<key_type Note = _zero>
	//	static constexpr instr_type clear = instruction
	//	<
	//		MN::clear, Note
	//	>;

	//	template<key_type Note = _zero>
	//	static constexpr instr_type map = instruction
	//	<
	//		MN::map, Note
	//	>;

	//	template<key_type Note = _zero>
	//	static constexpr instr_type plot = instruction
	//	<
	//		MN::plot, Note
	//	>;

	//	template<key_type Note = _zero>
	//	static constexpr instr_type align = instruction
	//	<
	//		MN::align, Note
	//	>;

/***********************************************************************************************************************/

// syntactic sugar:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register controller:

/***********************************************************************************************************************/

// spec:

	struct RN
	{
	};

/***********************************************************************************************************************/

// instructions:

	// passers:

	//	template<index_type Pos, index_type Obj, key_type Note = _zero>
	//	static constexpr instr_type assign = instruction
	//	<
	//		MN::assign, Note, Pos, Obj
	//	>;

	//	template<index_type Pos, key_type Note = _zero>
	//	static constexpr instr_type branch = instruction
	//	<
	//		MN::branch, Note, Pos
	//	>;

	//	template<key_type Next = _zero> // Next ?
	//	static constexpr instr_type goto__next_at_h0_front = instruction
	//	<
	//		MN::go_to__next_at_h0_front, Next
	//	>;

	//	template<index_type Pos>
	//	static constexpr instr_type goto_label = instruction
	//	<
	//		MN::go_to, MD::contr, Pos
	//	>;

	//	template<index_type Pos>
	//	static constexpr instr_type goto_using = instruction
	//	<
	//		MN::go_to, MD::regtr, Pos
	//	>;

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

/***********************************************************************************************************************/

// inventory:

	template<key_type, key_type...> struct near_linear_controller;

	//

/*
	template<key_type... filler>
	struct permutatic_controller<PN::left, filler...>
	{
		template<index_type Pos, instr_type Cont = pass<>>
		static constexpr label_type result = label
		<
			move_s_segment__insert_at_h1_back<Pos>,
			clear<>,
			move_h1_all__insert_at_s_front<>,
			Cont
		>;
	};

	template<key_type... filler>
	struct permutatic_controller<PN::roll, filler...>
	{
		template<instr_type Cont = pass<>>
		static constexpr label_type result = label
		<
			roll_s_segment__pos_at_h0_first<>,
			Cont
		>;
	};
*/

	// template<key_type... filler>
	// struct near_linear_controller<NN::drop_s_block, filler...>
	// {
	// 	template<instr_type Cont = pass<>>
	// 	static constexpr auto result = linear_controller<drop_s_block<>, Cont>;
	// };

	// go_to:

	//	template<index_type Pos>
	//	static constexpr auto go_to_contr = permutatic_controller
	//	<
	//		copy_s_pos__insert_at_h0_front<Pos>,

	//		goto__next_at_h0_front<>
	//	>;

	// restore:

	//	template<index_type Pos, index_type Obj, pa_type Cont = pass<>>
	//	static constexpr auto restore_contr = permutatic_controller
	//	<
	//		move_s_pos__insert_at_h0_front<Obj>,
	//		move_h0_all__replace_at_s_pos<Pos>,

	//		Cont
	//	>;

/***********************************************************************************************************************/

// syntactic sugar:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

