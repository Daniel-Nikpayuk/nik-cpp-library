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

// machine alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controllers:

/***********************************************************************************************************************/

	template<auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, instruction)	= NIK_MODULE::template instruction<Vs...>;

	template<auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, label)		= NIK_MODULE::template label<Vs...>;

	template<auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, controller)	= NIK_MODULE::template controller<Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatchers:

/***********************************************************************************************************************/

	using nik_name(NIK_PREFIX, block_machine)		= typename NIK_MODULE::BD;
	using nik_name(NIK_PREFIX, linear_machine)		= typename NIK_MODULE::LD;
	using nik_name(NIK_PREFIX, control_machine)		= typename NIK_MODULE::CD;
	using nik_name(NIK_PREFIX, register_machine)		= typename NIK_MODULE::CD; // convenience

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// trampolining:

/***********************************************************************************************************************/

// start:

	template<typename n, auto c, auto d, auto... Vs>
	inline NIK_POLICY auto start()
	{
		return NIK_MODULE::template start<n, c, d, Vs...>();
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// instructions:

/***********************************************************************************************************************/

// atomic:

	// halters:

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, pause)	= NIK_MODULE::template pause<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, first)	= NIK_MODULE::template first<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, rest)	= NIK_MODULE::template rest<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, pack)	= NIK_MODULE::template pack<Note...>;

	// debuggers:

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, depth)	= NIK_MODULE::template depth<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, dump)	= NIK_MODULE::template dump<Note...>;

	// passers:

		// stack -> stack:

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, sizeof_s_all__insert_at_s_front)		=
			NIK_MODULE::template sizeof_s_all__insert_at_s_front<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, align_s_all__insert_at_s_front)		=
			NIK_MODULE::template align_s_all__insert_at_s_front<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, shift_r_block__insert_at_s_back)		=
			NIK_MODULE::template shift_r_block__insert_at_s_back<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, map_s_all__op_at_h0_first)			=
			NIK_MODULE::template map_s_all__op_at_h0_first<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, map_s_all__act_at_h0_first)		=
			NIK_MODULE::template map_s_all__act_at_h0_first<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, map_s_all__arr_at_h0_first)		=
			NIK_MODULE::template map_s_all__arr_at_h0_first<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, drop_s_block)				=
			NIK_MODULE::template drop_s_block<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, drop_s_pos_opt)				=
			NIK_MODULE::template drop_s_pos_opt<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, drop_s_all)				=
			NIK_MODULE::template drop_s_all<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_s_block__insert_at_s_back)		=
			NIK_MODULE::template move_s_block__insert_at_s_back<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_s_pos__insert_at_s_back_opt)		=
			NIK_MODULE::template move_s_pos__insert_at_s_back_opt<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, fold_s_block__op_at_h0_first)		=
			NIK_MODULE::template fold_s_block__op_at_h0_first<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, roll_s_block__act_at_h0_first)		=
			NIK_MODULE::template roll_s_block__act_at_h0_first<Note...>;

		// stack -> heap:

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_s_block__insert_at_h0_front)		=
			NIK_MODULE::template move_s_block__insert_at_h0_front<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_s_block__insert_at_h1_back)		=
			NIK_MODULE::template move_s_block__insert_at_h1_back<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_s_first__replace_at_h1_value)		=
			NIK_MODULE::template move_s_first__replace_at_h1_value<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, copy_s_block__insert_at_h0_front)		=
			NIK_MODULE::template copy_s_block__insert_at_h0_front<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, copy_s_block__insert_at_h0_back)		=
			NIK_MODULE::template copy_s_block__insert_at_h0_back<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, copy_s_pos__insert_at_h0_front_opt)	=
			NIK_MODULE::template copy_s_pos__insert_at_h0_front_opt<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, copy_s_pos__insert_at_h0_back_opt)		=
			NIK_MODULE::template copy_s_pos__insert_at_h0_back_opt<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, copy_s_block__insert_at_h2_front)		=
			NIK_MODULE::template copy_s_block__insert_at_h2_front<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, copy_s_pos__insert_at_h2_front_opt)	=
			NIK_MODULE::template copy_s_pos__insert_at_h2_front_opt<Note...>;

		// heap -> stack:

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_h0_first__insert_at_s_front)		=
			NIK_MODULE::template move_h0_first__insert_at_s_front<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_h0_first__insert_at_s_pos_opt)	=
			NIK_MODULE::template move_h0_first__insert_at_s_pos_opt<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_h0_first__replace_at_s_pos_opt)	=
			NIK_MODULE::template move_h0_first__replace_at_s_pos_opt<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_h1_all__insert_at_s_front)		=
			NIK_MODULE::template move_h1_all__insert_at_s_front<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_h1_all__value_at_s_front)		=
			NIK_MODULE::template move_h1_all__value_at_s_front<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_h2_first__insert_at_s_front)		=
			NIK_MODULE::template move_h2_first__insert_at_s_front<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_h2_first__replace_at_s_pos_opt)	=
			NIK_MODULE::template move_h2_first__replace_at_s_pos_opt<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, apply_h0_all__move__insert_at_s_front)	=
			NIK_MODULE::template apply_h0_all__move__insert_at_s_front<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, apply_h0_all__move__replace_at_s_pos_opt)	=
			NIK_MODULE::template apply_h0_all__move__replace_at_s_pos_opt<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, compel_h0_all__move__insert_at_s_front)	=
			NIK_MODULE::template compel_h0_all__move__insert_at_s_front<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, compel_h0_all__move__replace_at_s_pos_opt)	=
			NIK_MODULE::template compel_h0_all__move__replace_at_s_pos_opt<Note...>;

		// heap -> heap:

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, apply_h0_all__move__replace_at_h0_front)	=
			NIK_MODULE::template apply_h0_all__move__replace_at_h0_front<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, compel_h0_all__move__replace_at_h0_front)	=
			NIK_MODULE::template compel_h0_all__move__replace_at_h0_front<Note...>;

	// interposers:

		template<auto Obj, auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, copy_i_pos__insert_at_h0_front)		=
			NIK_MODULE::template copy_i_pos__insert_at_h0_front<Obj, Note...>;

		template<auto Pos, auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, branch)					=
			NIK_MODULE::template branch<Pos, Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, pass)					=
			NIK_MODULE::template pass<Note...>;

		template<auto Name, auto... Vs>
		NIK_POLICY auto nik_name(NIK_PREFIX, block)					=
			NIK_MODULE::template block<Name, Vs...>;

		template<auto SubName, auto SubNote, auto... Vs>
		NIK_POLICY auto nik_name(NIK_PREFIX, linear)					=
			NIK_MODULE::template linear<SubName, SubNote, Vs...>;

		template<auto SubName, auto SubNote, auto... Vs>
		NIK_POLICY auto nik_name(NIK_PREFIX, control)					=
			NIK_MODULE::template control<SubName, SubNote, Vs...>;

		template<auto SubName, auto SubNote, auto... Vs>
		NIK_POLICY auto nik_name(NIK_PREFIX, user)					=
			NIK_MODULE::template user<SubName, SubNote, Vs...>;

	// recursors:

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, recurse__insert_at_h0_front)		=
			NIK_MODULE::template recurse__insert_at_h0_front<Note...>;

		template<auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, trampoline__insert_at_h0_front)		=
			NIK_MODULE::template trampoline__insert_at_h0_front<Note...>;

	// reflection:

		template<auto Length, auto... Note>
		NIK_POLICY auto nik_name(NIK_PREFIX, reg_size)					=
			NIK_MODULE::template reg_size<Length, Note...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compounds:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block:

/***********************************************************************************************************************/

// syntactic sugar (level 0):

	// halters:

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, stop)					=
			NIK_MODULE::template stop<Pos>;

	// passers:

		// stack -> stack:

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, make_r_segment__insert_at_s_back)		=
			NIK_MODULE::template make_r_segment__insert_at_s_back<Pos>;

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, drop_s_segment)				=
			NIK_MODULE::template drop_s_segment<Pos>;

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, fold_s_segment__replace_at_s_front)	=
			NIK_MODULE::template fold_s_segment__replace_at_s_front<Pos>;

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, roll_s_segment__replace_at_s_front)	=
			NIK_MODULE::template roll_s_segment__replace_at_s_front<Pos>;

		// stack -> heap:

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_s_segment__insert_at_h0_front)	=
			NIK_MODULE::template move_s_segment__insert_at_h0_front<Pos>;

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_s_segment__insert_at_h1_back)		=
			NIK_MODULE::template move_s_segment__insert_at_h1_back<Pos>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear:

/***********************************************************************************************************************/

// syntactic sugar (level 1):

	// passers:

		// stack -> stack:

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, drop_s_pos)				=
			NIK_MODULE::template drop_s_pos<Pos>;

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_s_pos__insert_at_s_back)		=
			NIK_MODULE::template move_s_pos__insert_at_s_back<Pos>;

		// stack -> heap:

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, copy_s_pos__insert_at_h0_front)		=
			NIK_MODULE::template copy_s_pos__insert_at_h0_front<Pos>;

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, copy_s_pos__insert_at_h0_back)		=
			NIK_MODULE::template copy_s_pos__insert_at_h0_back<Pos>;

		// heap -> stack:

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_h0_first__insert_at_s_pos)		=
			NIK_MODULE::template move_h0_first__insert_at_s_pos<Pos>;

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, move_h0_first__replace_at_s_pos)		=
			NIK_MODULE::template move_h0_first__replace_at_s_pos<Pos>;

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, apply_h0_all__move__replace_at_s_pos)	=
			NIK_MODULE::template apply_h0_all__move__replace_at_s_pos<Pos>;

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, compel_h0_all__move__replace_at_s_pos)	=
			NIK_MODULE::template compel_h0_all__move__replace_at_s_pos<Pos>;

/***********************************************************************************************************************/

// syntactic sugar (level 2):

	// mutators:

			template<auto Pos>
			NIK_POLICY auto nik_name(NIK_PREFIX, erase)				=
			NIK_MODULE::template erase<Pos>;

			template<auto Pos, auto Obj>
			NIK_POLICY auto nik_name(NIK_PREFIX, insert)				=
			NIK_MODULE::template insert<Pos, Obj>;

			template<auto Pos, auto Obj>
			NIK_POLICY auto nik_name(NIK_PREFIX, replace)				=
			NIK_MODULE::template replace<Pos, Obj>;

	// control:

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, goto_using)				=
			NIK_MODULE::template goto_using<Pos>;

		template<auto Val>
		NIK_POLICY auto nik_name(NIK_PREFIX, goto_label)				=
			NIK_MODULE::template goto_label<Val>;

		template<auto Pos, auto Obj>
		NIK_POLICY auto nik_name(NIK_PREFIX, assign_using)				=
			NIK_MODULE::template assign_using<Pos, Obj>;

		template<auto Val, auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, assign_label)				=
			NIK_MODULE::template assign_label<Val, Pos>;

		template<auto... Args>
		NIK_POLICY auto nik_name(NIK_PREFIX, save)					=
			NIK_MODULE::template save<Args...>;

		template<auto... Args>
		NIK_POLICY auto nik_name(NIK_PREFIX, restore)					=
			NIK_MODULE::template restore<Args...>;

		template<auto Op, auto... Args>
		NIK_POLICY auto nik_name(NIK_PREFIX, test)					=
			NIK_MODULE::template test<Op, Args...>;

		template<auto Act, auto... Args>
		NIK_POLICY auto nik_name(NIK_PREFIX, check)					=
			NIK_MODULE::template check<Act, Args...>;

		template<auto Pos, auto Op, auto... Args>
		NIK_POLICY auto nik_name(NIK_PREFIX, apply)					=
			NIK_MODULE::template apply<Pos, Op, Args...>;

		template<auto Pos, auto Act, auto... Args>
		NIK_POLICY auto nik_name(NIK_PREFIX, compel)					=
			NIK_MODULE::template compel<Pos, Act, Args...>;

/***********************************************************************************************************************/

// syntactic sugar (level 3):

	// control:

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, recurse)					=
			NIK_MODULE::template recurse<Pos>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

