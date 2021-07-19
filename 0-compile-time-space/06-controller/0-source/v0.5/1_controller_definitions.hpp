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
			static constexpr instr_type variadic_call	= call<CallNote::variadic, Name, Vs...>;

			template<key_type Name, index_type... Vs>
			static constexpr instr_type permutatic_call	= call<CallNote::permutatic, Name, Vs...>;

			template<key_type Name, index_type... Vs>
			static constexpr instr_type distributic_call	= call<CallNote::distributic, Name, Vs...>;

			template<key_type Name, index_type... Vs>
			static constexpr instr_type near_linear_call	= call<CallNote::near_linear, Name, Vs...>;

			template<key_type Name, index_type... Vs>
			static constexpr instr_type register_call	= call<CallNote::user, Name, Vs...>;

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
		template<instr_type Cont = MN::first>
		static constexpr instr_type result = instruction<MN::drop_s_block, Cont>;
	};

	template<key_type... filler>
	struct block_controller<BN::drop_s_segment, filler...>
	{
		template<instr_type Cont = MN::pass>
		static constexpr instr_type result = instruction<MN::drop_s_block, Cont>;
	};

	template<key_type... filler>
	struct block_controller<BN::move_s_segment__insert_at_s_back, filler...>
	{
		template<instr_type Cont = MN::pass>
		static constexpr instr_type result = instruction<MN::move_s_block__insert_at_s_back, Cont>;
	};

	template<key_type... filler>
	struct block_controller<BN::fold_s_segment__pos_at_h0_first, filler...>
	{
		template<instr_type Cont = MN::pass>
		static constexpr instr_type result = instruction<MN::fold_s_block__op_at_h0_first, Cont>;
	};

	template<key_type... filler>
	struct block_controller<BN::roll_s_segment__pos_at_h0_first, filler...>
	{
		template<instr_type Cont = MN::pass>
		static constexpr instr_type result = instruction<MN::roll_s_block__act_at_h0_first, Cont>;
	};

	template<key_type... filler>
	struct block_controller<BN::move_s_segment__insert_at_h0_back, filler...>
	{
		template<instr_type Cont = MN::pass>
		static constexpr instr_type result = instruction<MN::move_s_block__insert_at_h0_back, Cont>;
	};

	template<key_type... filler>
	struct block_controller<BN::move_s_segment__insert_at_h1_back, filler...>
	{
		template<instr_type Cont = MN::pass>
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
	};

	using locus_type = index_type const*;

		// pack length is stored as the initial value.

	template<index_type... Vs>
	static constexpr locus_type locus = array<index_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/

// inventory:

	template<key_type, key_type...> struct variadic_controller;

	//

	//	template<key_type... filler>
	//	struct machine<MN::stop, _zero, filler...>
	//	{
	//		using nn			= BD;
	//		static constexpr auto nc	= controller_module::template
	//						  drop_s_block__contr<MN::first>;

	//		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
	//		static constexpr auto result(Heaps... Hs)
	//		{
	//			constexpr auto pos	= n::pos(c, i, j);
	//			constexpr index_type nj	= block_max_index2(pos);
	//			constexpr index_type ni	= pos + nj;

	//			return NIK_MACHINE(nn, nc, d, ni, nj)(Hs...);
	//		}
	//	};

	// template<key_type... filler>
	// struct variadic_controller<VN::stop, filler...>
	// {
	// 	template<instr_type Cont = pass<>>
	// 	static constexpr auto result = linear_controller<drop_s_block<>, Cont>;
	// };
															
	// drop stack position:

	//	template<key_type Cont = MN::pass>
	//	static constexpr auto drop_s_pos__contr = variadic_controller
	//	<
	//		MN::move_s_segment__insert_at_h0_back,
	//		MN::drop_s_block,
	//		MN::move_h0_all__insert_at_s_front,

	//		Cont
	//	>;

	//	template<index_type Pos>
	//	static constexpr auto drop_s_pos__locus = v_locus
	//	<
	//		Pos, _zero, _zero, _zero
	//	>;

	// move stack position, insert at stack back:

	//	template<key_type Cont = MN::pass>
	//	static constexpr auto move_s_pos__insert_at_s_back__contr = variadic_controller
	//	<
	//		MN::move_s_segment__insert_at_h0_back,
	//		MN::move_s_block__insert_at_s_back,
	//		MN::move_h0_all__insert_at_s_front,

	//		Cont
	//	>;

	//	template<index_type Pos>
	//	static constexpr auto move_s_pos__insert_at_s_back__locus = v_locus
	//	<
	//		Pos, _zero, _zero, _zero
	//	>;

	// move stack position, insert at heap zero front:

	//	template<key_type Cont = MN::pass>
	//	static constexpr auto move_s_pos__insert_at_h0_front__contr = variadic_controller
	//	<
	//		MN::move_s_segment__insert_at_h1_back,
	//		MN::move_s_block__insert_at_h0_front,
	//		MN::move_h1_all__insert_at_s_front,

	//		Cont
	//	>;

	//	template<index_type Obj>
	//	static constexpr auto move_s_pos__insert_at_h0_front__locus = v_locus
	//	<
	//		Obj, _zero, _zero, _zero
	//	>;

	// copy stack position, insert at heap zero front:

	//	template<key_type Cont = MN::pass>
	//	static constexpr auto copy_s_pos__insert_at_h0_front__contr = variadic_controller
	//	<
	//		MN::move_s_segment__insert_at_h1_back,
	//		MN::copy_s_block__insert_at_h0_front,
	//		MN::move_h1_all__insert_at_s_front,

	//		Cont
	//	>;

	//	template<index_type Obj>
	//	static constexpr auto copy_s_pos__insert_at_h0_front__locus = v_locus
	//	<
	//		Obj, _zero, _zero, _zero
	//	>;

	// move heap zero all, insert at stack position:

	//	template<key_type Cont = MN::pass>
	//	static constexpr auto move_h0_all__insert_at_s_pos__contr = variadic_controller
	//	<
	//		MN::move_s_segment__insert_at_h1_back,
	//		MN::move_h0_all__insert_at_s_front,
	//		MN::move_h1_all__insert_at_s_front,

	//		Cont
	//	>;

	//	template<index_type Pos>
	//	static constexpr auto move_h0_all__insert_at_s_pos__locus = v_locus
	//	<
	//		Pos, _zero, _zero, _zero
	//	>;

	// move heap zero all, replace at stack position:

	//	template<key_type Cont = MN::pass>
	//	static constexpr auto move_h0_all__replace_at_s_pos__contr = variadic_controller
	//	<
	//		MN::move_s_segment__insert_at_h1_back,
	//		MN::drop_s_block,
	//		MN::move_h0_all__insert_at_s_front,
	//		MN::move_h1_all__insert_at_s_front,

	//		Cont
	//	>;

	//	template<index_type Pos>
	//	static constexpr auto move_h0_all__replace_at_s_pos__locus = v_locus
	//	<
	//		Pos, _zero, _zero, _zero, _zero
	//	>;

	// apply heap zero all, move, replace at stack position:

	//	template<key_type Cont = MN::pass>
	//	static constexpr auto apply_h0_all__move__replace_at_s_pos__contr = variadic_controller
	//	<
	//		MN::move_s_segment__insert_at_h1_back,
	//		MN::drop_s_block,
	//		MN::apply_h0_all__move__insert_at_s_front,
	//		MN::move_h1_all__insert_at_s_front,

	//		Cont
	//	>;

	//	template<index_type Pos>
	//	static constexpr auto apply_h0_all__move__replace_at_s_pos__locus = v_locus
	//	<
	//		Pos, _zero, _zero, _zero, _zero
	//	>;

	// compel heap zero all, move, replace at stack position:

	//	template<key_type Cont = MN::pass>
	//	static constexpr auto compel_h0_all__move__replace_at_s_pos__contr = variadic_controller
	//	<
	//		MN::move_s_segment__insert_at_h1_back,
	//		MN::drop_s_block,
	//		MN::compel_h0_all__move__insert_at_s_front,
	//		MN::move_h1_all__insert_at_s_front,

	//		Cont
	//	>;

	//	template<index_type Pos>
	//	static constexpr auto compel_h0_all__move__replace_at_s_pos__locus = v_locus
	//	<
	//		Pos, _zero, _zero, _zero, _zero
	//	>;

/***********************************************************************************************************************/

// syntactic sugar:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// permutatic controller:

/***********************************************************************************************************************/

// names:

	struct PN
	{
		// passers:

			// stack -> stack:

			static constexpr key_type drop_s_pos					= 34;
			static constexpr key_type move_s_pos__insert_at_s_back			= 35;

			// stack -> heap:

			static constexpr key_type move_s_pos__insert_at_h0_front		= 36;
			static constexpr key_type copy_s_pos__insert_at_h0_front		= 37;

			// heap -> stack:

			static constexpr key_type move_h0_all__insert_at_s_pos			= 38;
			static constexpr key_type move_h0_all__replace_at_s_pos			= 39;

			static constexpr key_type apply_h0_all__move__replace_at_s_pos		= 40;
			static constexpr key_type compel_h0_all__move__replace_at_s_pos		= 41;
	};

/***********************************************************************************************************************/

// instructions:

	// passers:

			// stack -> stack:

	//	template<index_type Pos>
	//	static constexpr instr_type drop_s_pos = instruction
	//	<
	//		MN::drop_s_pos, MA::patch(Pos), Pos
	//	>;

	//	template<index_type Pos, key_type Note = _zero>
	//	static constexpr instr_type move_s_pos__insert_at_s_back = instruction
	//	<
	//		MN::move_s_pos__insert_at_s_back, Note, Pos
	//	>;

			// stack -> heap:

	//	template<index_type Pos>
	//	static constexpr instr_type move_s_pos__insert_at_h0_front = instruction
	//	<
	//		MN::move_s_pos__insert_at_h0_front, MA::patch(Pos), Pos
	//	>;

	//	template<index_type Pos>
	//	static constexpr instr_type copy_s_pos__insert_at_h0_front = instruction
	//	<
	//		MN::copy_s_pos__insert_at_h0_front, MA::patch(Pos), Pos
	//	>;

			// heap -> stack:

	//	template<index_type Pos>
	//	static constexpr instr_type move_h0_all__insert_at_s_pos = instruction
	//	<
	//		MN::move_h0_all__insert_at_s_pos, MA::patch(Pos), Pos
	//	>;

	//	template<index_type Pos>
	//	static constexpr instr_type move_h0_all__replace_at_s_pos = instruction
	//	<
	//		MN::move_h0_all__replace_at_s_pos, MA::patch(Pos), Pos
	//	>;

	//	template<index_type Pos>
	//	static constexpr instr_type apply_h0_all__move__replace_at_s_pos = instruction
	//	<
	//		MN::apply_h0_all__move__replace_at_s_pos, MA::patch(Pos), Pos
	//	>;

	//	template<index_type Pos>
	//	static constexpr instr_type compel_h0_all__move__replace_at_s_pos = instruction
	//	<
	//		MN::compel_h0_all__move__replace_at_s_pos, MA::patch(Pos), Pos
	//	>;

/***********************************************************************************************************************/

// inventory:

	template<key_type, key_type...> struct permutatic_controller;

	//

	// template<key_type... filler>
	// struct permutatic_controller<PN::drop_s_block, filler...>
	// {
	// 	template<instr_type Cont = pass<>>
	// 	static constexpr auto result = linear_controller<drop_s_block<>, Cont>;
	// };

	// erase:

	//	template<index_type Pos, pa_type Cont = pass<>>
	//	static constexpr auto erase_contr = permutatic_controller
	//	<
	//		drop_s_pos<Pos>,

	//		Cont
	//	>;

	// insert:

	//	template<index_type Pos, index_type Obj, pa_type Cont = pass<>>
	//	static constexpr auto insert_contr = permutatic_controller
	//	<
	//		copy_s_pos__insert_at_h0_front<Obj>,
	//		move_h0_all__insert_at_s_pos<Pos>,	// includes undefined behaviour.

	//		Cont
	//	>;

	// replace:

	//	template<index_type Pos, index_type Obj, pa_type Cont = pass<>>
	//	static constexpr auto replace_contr = permutatic_controller
	//	<
	//		copy_s_pos__insert_at_h0_front<Obj>,
	//		move_h0_all__replace_at_s_pos<Pos>,	// includes undefined behaviour.

	//		Cont
	//	>;

	// unary apply replace:

	//	template<index_type Pos, index_type Op, index_type Arg, pa_type Cont = pass<>>
	//	static constexpr auto apply1_replace_contr = permutatic_controller
	//	<
	//		copy_s_pos__insert_at_h0_front<Arg>,
	//		copy_s_pos__insert_at_h0_front<Op>,
	//		apply_h0_all__move__replace_at_s_pos<Pos>,	// includes undefined behaviour.

	//		Cont
	//	>;

	// binary apply replace:

	//	template<index_type Pos, index_type Op, index_type Arg1, index_type Arg2, pa_type Cont = pass<>>
	//	static constexpr auto apply2_replace_contr = permutatic_controller
	//	<
	//		copy_s_pos__insert_at_h0_front<Arg2>,
	//		copy_s_pos__insert_at_h0_front<Arg1>,
	//		copy_s_pos__insert_at_h0_front<Op>,
	//		apply_h0_all__move__replace_at_s_pos<Pos>,	// includes undefined behaviour.

	//		Cont
	//	>;

	// unary compel replace:

	//	template<index_type Pos, index_type Op, index_type Arg, pa_type Cont = pass<>>
	//	static constexpr auto compel1_replace_contr = permutatic_controller
	//	<
	//		copy_s_pos__insert_at_h0_front<Arg>,
	//		copy_s_pos__insert_at_h0_front<Op>,
	//		compel_h0_all__move__replace_at_s_pos<Pos>,	// includes undefined behaviour.

	//		Cont
	//	>;

	// binary compel replace:

	//	template<index_type Pos, index_type Op, index_type Arg1, index_type Arg2, pa_type Cont = pass<>>
	//	static constexpr auto compel2_replace_contr = permutatic_controller
	//	<
	//		copy_s_pos__insert_at_h0_front<Arg2>,
	//		copy_s_pos__insert_at_h0_front<Arg1>,
	//		copy_s_pos__insert_at_h0_front<Op>,
	//		compel_h0_all__move__replace_at_s_pos<Pos>,	// includes undefined behaviour.

	//		Cont
	//	>;

	// unary test replace:

	//	template<index_type Op, index_type Arg, pa_type Cont = pass<>>
	//	static constexpr auto test1_replace_contr = permutatic_controller
	//	<
	//		copy_s_pos__insert_at_h0_front<Arg>,
	//		copy_s_pos__insert_at_h0_front<Op>,
	//		apply_h0_all__replace_h0_all<>,			// includes undefined behaviour.

	//		Cont
	//	>;

	// binary test replace:

	//	template<index_type Op, index_type Arg1, index_type Arg2, pa_type Cont = pass<>>
	//	static constexpr auto test2_replace_contr = permutatic_controller
	//	<
	//		copy_s_pos__insert_at_h0_front<Arg2>,
	//		copy_s_pos__insert_at_h0_front<Arg1>,
	//		copy_s_pos__insert_at_h0_front<Op>,
	//		apply_h0_all__replace_h0_all<>,			// includes undefined behaviour.

	//		Cont
	//	>;

	// unary check replace:

	//	template<index_type Op, index_type Arg, pa_type Cont = pass<>>
	//	static constexpr auto check1_replace_contr = permutatic_controller
	//	<
	//		copy_s_pos__insert_at_h0_front<Arg>,
	//		copy_s_pos__insert_at_h0_front<Op>,
	//		compel_h0_all__replace_h0_all<>,		// includes undefined behaviour.

	//		Cont
	//	>;

	// binary check replace:

	//	template<index_type Op, index_type Arg1, index_type Arg2, pa_type Cont = pass<>>
	//	static constexpr auto check2_replace_contr = permutatic_controller
	//	<
	//		copy_s_pos__insert_at_h0_front<Arg2>,
	//		copy_s_pos__insert_at_h0_front<Arg1>,
	//		copy_s_pos__insert_at_h0_front<Op>,
	//		compel_h0_all__replace_h0_all<>,		// includes undefined behaviour.

	//		Cont
	//	>;

	// left:

	//	template<index_type Pos, pa_type Cont = pass<>>
	//	static constexpr auto left_contr = permutatic_controller
	//	<
	//		move_s_segment__insert_at_h1_back<Pos>,
	//		clear<>,
	//		move_h1_all__insert_at_s_front<>,

	//		Cont
	//	>;

	// roll:

	//	template<pa_type Cont = pass<>>
	//	static constexpr auto roll__contr = permutatic_controller
	//	<
	//		roll_s_segment__pos_at_h0_first<>,

	//		Cont
	//	>;

/***********************************************************************************************************************/

// syntactic sugar:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// distributic controller:

/***********************************************************************************************************************/

// names:

	struct DN
	{
		// passers:

			static constexpr key_type erase					= 42;
			static constexpr key_type insert				= 43;
			static constexpr key_type replace				= 44;

			static constexpr key_type fold					= 45;
			static constexpr key_type roll					= 46;

			static constexpr key_type apply					= 47;
			static constexpr key_type compel				= 48;

			static constexpr key_type test					= 49;
			static constexpr key_type check					= 50;

			static constexpr key_type skip					= 51;
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
	//		MN::apply, MA::arity(sizeof...(Args)), Pos, Op, Args...
	//	>;

	//	template<index_type Pos, index_type Op, index_type... Args>
	//	static constexpr instr_type compel = instruction
	//	<
	//		MN::compel, MA::arity(sizeof...(Args)), Pos, Op, Args...
	//	>;

	//	template<index_type Op, index_type... Args>
	//	static constexpr instr_type test = instruction
	//	<
	//		MN::test, MA::arity(sizeof...(Args)), Op, Args...
	//	>;

	//	template<index_type Op, index_type... Args>
	//	static constexpr instr_type check = instruction
	//	<
	//		MN::check, MA::arity(sizeof...(Args)), Op, Args...
	//	>;

	//	template<key_type Note = MA::unary>
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
	//	static constexpr auto skip_contr = distributic_controller<Test, skip<MA::binary>, Ante, Cont, Conse, Cont>;

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
		// halters:

			static constexpr key_type halt			= 52;

		// passers:

			static constexpr key_type size_of		= 53;
			static constexpr key_type clear			= 54;
			static constexpr key_type map			= 55;
			static constexpr key_type plot			= 56;
			static constexpr key_type align			= 57;

			static constexpr key_type lift			= 58;
			static constexpr key_type stem			= 59;
			static constexpr key_type costem		= 60;
			static constexpr key_type cycle			= 61;

		// members:

			static constexpr key_type size			= 0;
			static constexpr key_type name			= 1;

			static constexpr key_type appl			= 2;

			static constexpr key_type cond			= 2;
			static constexpr key_type appl1			= 3;
			static constexpr key_type appl2			= 4;

		// constants:

			static constexpr instr_type lift_instr		= instruction<lift, _zero>;
			static constexpr instr_type stem_instr		= instruction<stem, _zero>;
			static constexpr instr_type halt_instr		= instruction<halt, _zero>;
			static constexpr instr_type cycle_instr		= instruction<cycle, _zero>;
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
		// passers:

			static constexpr key_type assign				= 62;

			static constexpr key_type branch				= 63;
			static constexpr key_type go_to__next_at_h0_front		= 64;
			static constexpr key_type go_to					= 65;

			static constexpr key_type save					= 66;
			static constexpr key_type restore				= 67;

	// reflection:

		// sizes:

			static constexpr key_type reg_size				= 68;
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

