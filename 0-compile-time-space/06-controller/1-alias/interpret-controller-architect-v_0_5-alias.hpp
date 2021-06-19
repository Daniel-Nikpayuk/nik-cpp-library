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

// controller alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// applications:

/***********************************************************************************************************************/

// syntactic sugar:

	// generic:

		template<auto Name, auto Note, auto... Args>
		NIK_POLICY auto nik_name(NIK_PREFIX, call) = NIK_MODULE::template call
		<
			Name, Note, Args...
		>;

	// abstract:

		// id

	// block:

		// halters:

		template<auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, pause) = NIK_MODULE::template pause
		<
			Note
		>;

		template<auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, first) = NIK_MODULE::template first
		<
			Note
		>;

		template<auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, rest) = NIK_MODULE::template rest
		<
			Note
		>;

		template<auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, pack) = NIK_MODULE::template pack
		<
			Note
		>;

		// debuggers:

		template<auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, depth) = NIK_MODULE::template depth
		<
			Note
		>;

		template<auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, dump) = NIK_MODULE::template dump
		<
			Note
		>;

		template<auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, pass) = NIK_MODULE::template pass
		<
			Note
		>;

		// interoperability:

		// pass

		// passers:

			// stack -> stack:

		// drop_s_block
		// move_s_block__insert_at_s_back

		// fold_s_block__op_at_h0_first
		// roll_s_block__act_at_h0_first

			// stack -> heap:

		// move_s_block__insert_at_h0_front
		// move_s_block__insert_at_h0_back
		// move_s_block__insert_at_h1_back

		// copy_s_block__insert_at_h0_front

	// variadic:

		// halters:

		template<auto Pos, auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, stop) = NIK_MODULE::template stop
		<
			Pos, Note
		>;

		// passers:

			// stack -> stack:

		template<auto Pos, auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, drop_s_segment) = NIK_MODULE::template drop_s_segment
		<
			Pos, Note
		>;

		template<auto Pos, auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_s_segment__insert_at_s_back) =
			NIK_MODULE::template move_s_segment__insert_at_s_back
		<
			Pos, Note
		>;

		// fold_s_segment__op_at_h0_first
		// roll_s_segment__act_at_h0_first

			// stack -> heap:

		template<auto Pos, auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_s_segment__insert_at_h0_back) =
			NIK_MODULE::template move_s_segment__insert_at_h0_back
		<
			Pos, Note
		>;

		template<auto Pos, auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_s_segment__insert_at_h1_back) =
			NIK_MODULE::template move_s_segment__insert_at_h1_back
		<
			Pos, Note
		>;

			// heap -> stack:

		template<auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_h0_all__insert_at_s_front) =
			NIK_MODULE::template move_h0_all__insert_at_s_front
		<
			Note
		>;

		template<auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_h1_all__insert_at_s_front) =
			NIK_MODULE::template move_h1_all__insert_at_s_front
		<
			Note
		>;

		// copy_h0_all__insert_at_s_front
		// copy_h1_all__insert_at_s_front

		// apply_h0_all__move__insert_at_s_front

		template<auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, apply_h0_all__replace_h0_all) =
			NIK_MODULE::template apply_h0_all__replace_h0_all
		<
			Note
		>;

		// compel_h0_all__move__insert_at_s_front

		template<auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, compel_h0_all__replace_h0_all) =
			NIK_MODULE::template compel_h0_all__replace_h0_all
		<
			Note
		>;

	// permutatic:

		// passers:

			// stack -> stack:

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, drop_s_pos) = NIK_MODULE::template drop_s_pos
		<
			Pos
		>;

		template<auto Pos, auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_s_pos__insert_at_s_back) =
			NIK_MODULE::template move_s_pos__insert_at_s_back
		<
			Pos, Note
		>;

			// stack -> heap:

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_s_pos__insert_at_h0_front) =
			NIK_MODULE::template move_s_pos__insert_at_h0_front
		<
			Pos
		>;

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, copy_s_pos__insert_at_h0_front) =
			NIK_MODULE::template copy_s_pos__insert_at_h0_front
		<
			Pos
		>;

			// heap -> stack:

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_h0_all__insert_at_s_pos) =
			NIK_MODULE::template move_h0_all__insert_at_s_pos
		<
			Pos
		>;

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_h0_all__replace_at_s_pos) =
			NIK_MODULE::template move_h0_all__replace_at_s_pos
		<
			Pos
		>;

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, apply_h0_all__move__replace_at_s_pos) =
			NIK_MODULE::template apply_h0_all__move__replace_at_s_pos
		<
			Pos
		>;

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, compel_h0_all__move__replace_at_s_pos) =
			NIK_MODULE::template compel_h0_all__move__replace_at_s_pos
		<
			Pos
		>;

	// distributic:

		// passers:

		template<auto Pos, auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, erase) = NIK_MODULE::template erase
		<
			Pos, Note
		>;

		template<auto Pos, auto Obj, auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, insert) = NIK_MODULE::template insert
		<
			Pos, Obj, Note
		>;

		template<auto Pos, auto Obj, auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, replace) = NIK_MODULE::template replace
		<
			Pos, Obj, Note
		>;

	//	template<auto Pos, auto Op, auto Note = NIK_CONSTANT::_zero>
	//	NIK_POLICY auto nik_name(NIK_PREFIX, ma_type fold) = NIK_MODULE::template fold
	//	<
	//		Pos, Op, Note
	//	>;

	//	template<auto Pos, auto Op, auto Note = NIK_CONSTANT::_zero>
	//	NIK_POLICY auto nik_name(NIK_PREFIX, ma_type roll) = NIK_MODULE::template roll
	//	<
	//		Pos, Op, Note
	//	>;

		template<auto Pos, auto Op, auto... Args>
		NIK_POLICY auto nik_name(NIK_PREFIX, apply) = NIK_MODULE::template apply
		<
			Pos, Op, Args...
		>;

		template<auto Pos, auto Op, auto... Args>
		NIK_POLICY auto nik_name(NIK_PREFIX, compel) = NIK_MODULE::template compel
		<
			Pos, Op, Args...
		>;

		template<auto Op, auto... Args>
		NIK_POLICY auto nik_name(NIK_PREFIX, test) = NIK_MODULE::template test
		<
			Op, Args...
		>;

		template<auto Op, auto... Args>
		NIK_POLICY auto nik_name(NIK_PREFIX, check) = NIK_MODULE::template check
		<
			Op, Args...
		>;

		template<auto Note = NIK_MODULE::MA::unary>
		NIK_POLICY auto nik_name(NIK_PREFIX, skip) = NIK_MODULE::template skip
		<
			Note
		>;

	// near linear:

		// passers:

		template<auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, size_of) = NIK_MODULE::template size_of
		<
			Note
		>;

		template<auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, clear) = NIK_MODULE::template clear
		<
			Note
		>;

		template<auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, map) = NIK_MODULE::template map
		<
			Note
		>;

		template<auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, plot) = NIK_MODULE::template plot
		<
			Note
		>;

		template<auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, align) = NIK_MODULE::template align
		<
			Note
		>;

	// register:

		// passers:

		template<auto Pos, auto Obj, auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, assign) = NIK_MODULE::template assign
		<
			Pos, Obj, Note
		>;

		template<auto Pos, auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, branch) = NIK_MODULE::template branch
		<
			Pos, Note
		>;

		// go_to__next_at_h0_front

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, goto_label) = NIK_MODULE::template goto_label
		<
			Pos
		>;

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, goto_using) = NIK_MODULE::template goto_using
		<
			Pos
		>;

		template<auto Pos, auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, save) = NIK_MODULE::template save
		<
			Pos, Note
		>;

		template<auto Pos, auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, restore) = NIK_MODULE::template restore
		<
			Pos, Note
		>;

		// reg_size

		template<auto Length, auto Note = NIK_CONSTANT::_zero>
		NIK_POLICY auto nik_name(NIK_PREFIX, reg_size) = NIK_MODULE::template reg_size
		<
			Length, Note
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block controller:

/***********************************************************************************************************************/

	template<auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, b_controller) = NIK_MODULE::template b_controller
	<
		Vs...
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specializations:

/***********************************************************************************************************************/

// drop stack block:

	template<auto Cont = NIK_MODULE::MN::pass>
	NIK_POLICY auto nik_name(NIK_PREFIX, drop_s_block__contr) = NIK_MODULE::template drop_s_block__contr
	<
		Cont
	>;

// move stack block, insert at stack back:

	template<auto Cont = NIK_MODULE::MN::pass>
	NIK_POLICY auto nik_name(NIK_PREFIX, move_s_block__insert_at_s_back__contr) =
		NIK_MODULE::template move_s_block__insert_at_s_back__contr
	<
		Cont
	>;

// fold stack block, op at heap zero first:

	template<auto Cont = NIK_MODULE::MN::pass>
	NIK_POLICY auto nik_name(NIK_PREFIX, fold_s_block__op_at_h0_first__contr) =
		NIK_MODULE::template fold_s_block__op_at_h0_first__contr
	<
		Cont
	>;

// roll stack block, act at heap zero first:

	template<auto Cont = NIK_MODULE::MN::pass>
	NIK_POLICY auto nik_name(NIK_PREFIX, roll_s_block__act_at_h0_first__contr) =
		NIK_MODULE::template roll_s_block__act_at_h0_first__contr
	<
		Cont
	>;

// move stack block, insert at heap zero back:

	template<auto Cont = NIK_MODULE::MN::pass>
	NIK_POLICY auto nik_name(NIK_PREFIX, move_s_block__insert_at_h0_back__contr) =
		NIK_MODULE::template move_s_block__insert_at_h0_back__contr
	<
		Cont
	>;

// move stack block, insert at heap one back:

	template<auto Cont = NIK_MODULE::MN::pass>
	NIK_POLICY auto nik_name(NIK_PREFIX, move_s_block__insert_at_h1_back__contr) =
		NIK_MODULE::template move_s_block__insert_at_h1_back__contr
	<
		Cont
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// variadic controller:

/***********************************************************************************************************************/

// locus:

	template<auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, v_locus) = NIK_MODULE::template v_locus
	<
		Vs...
	>;

/***********************************************************************************************************************/

// controller:

	template<auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, v_controller) = NIK_MODULE::template v_controller
	<
		Vs...
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specializations:

/***********************************************************************************************************************/

// drop stack position:

	template<auto Cont = NIK_MODULE::MN::pass>
	NIK_POLICY auto nik_name(NIK_PREFIX, drop_s_pos__contr) = NIK_MODULE::template drop_s_pos__contr
	<
		Cont
	>;

	template<auto Pos>
	NIK_POLICY auto nik_name(NIK_PREFIX, drop_s_pos__locus) = NIK_MODULE::template drop_s_pos__locus
	<
		Pos
	>;

// move stack position, insert at stack back:

	template<auto Cont = NIK_MODULE::MN::pass>
	NIK_POLICY auto nik_name(NIK_PREFIX, move_s_pos__insert_at_s_back__contr) =
		NIK_MODULE::template move_s_pos__insert_at_s_back__contr
	<
		Cont
	>;

	template<auto Pos>
	NIK_POLICY auto nik_name(NIK_PREFIX, move_s_pos__insert_at_s_back__locus) =
		NIK_MODULE::template move_s_pos__insert_at_s_back__locus
	<
		Pos
	>;

// move stack position, insert at heap zero front:

	template<auto Cont = NIK_MODULE::MN::pass>
	NIK_POLICY auto nik_name(NIK_PREFIX, move_s_pos__insert_at_h0_front__contr) =
		NIK_MODULE::template move_s_pos__insert_at_h0_front__contr
	<
		Cont
	>;

	template<auto Obj>
	NIK_POLICY auto nik_name(NIK_PREFIX, move_s_pos__insert_at_h0_front__locus) =
		NIK_MODULE::template move_s_pos__insert_at_h0_front__locus
	<
		Obj
	>;

// copy stack position, insert at heap zero front:

	template<auto Cont = NIK_MODULE::MN::pass>
	NIK_POLICY auto nik_name(NIK_PREFIX, copy_s_pos__insert_at_h0_front__contr) =
		NIK_MODULE::template copy_s_pos__insert_at_h0_front__contr
	<
		Cont
	>;

	template<auto Obj>
	NIK_POLICY auto nik_name(NIK_PREFIX, copy_s_pos__insert_at_h0_front__locus) =
		NIK_MODULE::template copy_s_pos__insert_at_h0_front__locus
	<
		Obj
	>;

// move heap zero all, insert at stack position:

	template<auto Cont = NIK_MODULE::MN::pass>
	NIK_POLICY auto nik_name(NIK_PREFIX, move_h0_all__insert_at_s_pos__contr) =
		NIK_MODULE::template move_h0_all__insert_at_s_pos__contr
	<
		Cont
	>;

	template<auto Pos>
	NIK_POLICY auto nik_name(NIK_PREFIX, move_h0_all__insert_at_s_pos__locus) =
		NIK_MODULE::template move_h0_all__insert_at_s_pos__locus
	<
		Pos
	>;

// move heap zero all, replace at stack position:

	template<auto Cont = NIK_MODULE::MN::pass>
	NIK_POLICY auto nik_name(NIK_PREFIX, move_h0_all__replace_at_s_pos__contr) =
		NIK_MODULE::template move_h0_all__replace_at_s_pos__contr
	<
		Cont
	>;

	template<auto Pos>
	NIK_POLICY auto nik_name(NIK_PREFIX, move_h0_all__replace_at_s_pos__locus) =
		NIK_MODULE::template move_h0_all__replace_at_s_pos__locus
	<
		Pos
	>;

// apply heap zero all, move, replace at stack position:

	template<auto Cont = NIK_MODULE::MN::pass>
	NIK_POLICY auto nik_name(NIK_PREFIX, apply_h0_all__move__replace_at_s_pos__contr) =
		NIK_MODULE::template apply_h0_all__move__replace_at_s_pos__contr
	<
		Cont
	>;

	template<auto Pos>
	NIK_POLICY auto nik_name(NIK_PREFIX, apply_h0_all__move__replace_at_s_pos__locus) =
		NIK_MODULE::template apply_h0_all__move__replace_at_s_pos__locus
	<
		Pos
	>;

// compel heap zero all, move, replace at stack position:

	template<auto Cont = NIK_MODULE::MN::pass>
	NIK_POLICY auto nik_name(NIK_PREFIX, compel_h0_all__move__replace_at_s_pos__contr) =
		NIK_MODULE::template compel_h0_all__move__replace_at_s_pos__contr
	<
		Cont
	>;

	template<auto Pos>
	NIK_POLICY auto nik_name(NIK_PREFIX, compel_h0_all__move__replace_at_s_pos__locus) =
		NIK_MODULE::template compel_h0_all__move__replace_at_s_pos__locus
	<
		Pos
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// permutatic controller:

/***********************************************************************************************************************/

// controller:

	template<auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, p_controller) = NIK_MODULE::template p_controller
	<
		Vs...
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specializations:

/***********************************************************************************************************************/

// erase:

	template<auto Pos, auto Cont = NIK_MODULE::template pass<>>
	NIK_POLICY auto nik_name(NIK_PREFIX, erase_contr) = NIK_MODULE::template erase_contr
	<
		Pos, Cont
	>;

// insert:

	template<auto Pos, auto Obj, auto Cont = NIK_MODULE::template pass<>>
	NIK_POLICY auto nik_name(NIK_PREFIX, insert_contr) = NIK_MODULE::template insert_contr
	<
		Pos, Obj, Cont
	>;

// replace:

	template<auto Pos, auto Obj, auto Cont = NIK_MODULE::template pass<>>
	NIK_POLICY auto nik_name(NIK_PREFIX, replace_contr) = NIK_MODULE::template replace_contr
	<
		Pos, Obj, Cont
	>;

// unary apply replace:

	template<auto Pos, auto Op, auto Arg, auto Cont = NIK_MODULE::template pass<>>
	NIK_POLICY auto nik_name(NIK_PREFIX, apply1_replace_contr) = NIK_MODULE::template apply1_replace_contr
	<
		Pos, Op, Arg, Cont
	>;

// binary apply replace:

	template<auto Pos, auto Op, auto Arg1, auto Arg2, auto Cont = NIK_MODULE::template pass<>>
	NIK_POLICY auto nik_name(NIK_PREFIX, apply2_replace_contr) = NIK_MODULE::template apply2_replace_contr
	<
		Pos, Op, Arg1, Arg2, Cont
	>;

// unary compel replace:

	template<auto Pos, auto Op, auto Arg, auto Cont = NIK_MODULE::template pass<>>
	NIK_POLICY auto nik_name(NIK_PREFIX, compel1_replace_contr) = NIK_MODULE::template compel1_replace_contr
	<
		Pos, Op, Arg, Cont
	>;

// binary compel replace:

	template<auto Pos, auto Op, auto Arg1, auto Arg2, auto Cont = NIK_MODULE::template pass<>>
	NIK_POLICY auto nik_name(NIK_PREFIX, compel2_replace_contr) = NIK_MODULE::template compel2_replace_contr
	<
		Pos, Op, Arg1, Arg2, Cont
	>;

// unary test replace:

	template<auto Op, auto Arg, auto Cont = NIK_MODULE::template pass<>>
	NIK_POLICY auto nik_name(NIK_PREFIX, test1_replace_contr) = NIK_MODULE::template test1_replace_contr
	<
		Op, Arg, Cont
	>;

// binary test replace:

	template<auto Op, auto Arg1, auto Arg2, auto Cont = NIK_MODULE::template pass<>>
	NIK_POLICY auto nik_name(NIK_PREFIX, test2_replace_contr) = NIK_MODULE::template test2_replace_contr
	<
		Op, Arg1, Arg2, Cont
	>;

// unary check replace:

	template<auto Op, auto Arg, auto Cont = NIK_MODULE::template pass<>>
	NIK_POLICY auto nik_name(NIK_PREFIX, check1_replace_contr) = NIK_MODULE::template check1_replace_contr
	<
		Op, Arg, Cont
	>;

// binary check replace:

	template<auto Op, auto Arg1, auto Arg2, auto Cont = NIK_MODULE::template pass<>>
	NIK_POLICY auto nik_name(NIK_PREFIX, check2_replace_contr) = NIK_MODULE::template check2_replace_contr
	<
		Op, Arg1, Arg2, Cont
	>;

// left:

	template<auto Pos, auto Cont = NIK_MODULE::template pass<>>
	NIK_POLICY auto nik_name(NIK_PREFIX, left_contr) = NIK_MODULE::template left_contr
	<
		Pos, Cont
	>;

// roll:

	template<auto Cont = NIK_MODULE::template pass<>>
	NIK_POLICY auto nik_name(NIK_PREFIX, roll__contr) = NIK_MODULE::template roll__contr
	<
		Cont
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// distributic controller:

/***********************************************************************************************************************/

// controller:

	template<auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, d_controller) = NIK_MODULE::template d_controller
	<
		Vs...
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specializations:

/***********************************************************************************************************************/

// call:

	template<auto Appl, auto Cont = NIK_MODULE::template pass<>>
	NIK_POLICY auto nik_name(NIK_PREFIX, call_contr) = NIK_MODULE::template call_contr
	<
		Appl, Cont
	>;

// skip:

	template<auto Test, auto Ante, auto Conse, auto Cont = NIK_MODULE::template pass<>>
	NIK_POLICY auto nik_name(NIK_PREFIX, skip_contr) = NIK_MODULE::template skip_contr
	<
		Test, Ante, Conse, Cont
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// near linear controller:

/***********************************************************************************************************************/

	template<auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, n_continuation) = NIK_MODULE::template n_continuation
	<
		Vs...
	>;

	// syntactic sugar:

		template<auto N>
		NIK_POLICY auto nik_name(NIK_PREFIX, n_lift) = NIK_MODULE::template n_lift
		<
			N
		>;

		template<auto P, auto B, auto N>
		NIK_POLICY auto nik_name(NIK_PREFIX, n_stem) = NIK_MODULE::template n_stem
		<
			P, B, N
		>;

		template<auto B>
		NIK_POLICY auto nik_name(NIK_PREFIX, n_halt) = NIK_MODULE::template n_halt
		<
			B
		>;

		NIK_POLICY auto nik_name(NIK_PREFIX, n_cycle) = NIK_MODULE::n_cycle;

/***********************************************************************************************************************/

// controller:

	template<auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, n_controller) = NIK_MODULE::template n_controller
	<
		Vs...
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register controller:

/***********************************************************************************************************************/

// labels:

	template<auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, r_label) = NIK_MODULE::template r_label
	<
		Vs...
	>;

/***********************************************************************************************************************/

// controller:

	template<auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, r_controller) = NIK_MODULE::template r_controller
	<
		Vs...
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specializations:

/***********************************************************************************************************************/

// go_to:

	// noted, but not aliased.

// restore:

	// noted, but not aliased.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

