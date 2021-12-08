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

// structures:

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

// programs:

/***********************************************************************************************************************/

	using nik_name(NIK_PREFIX, T_block_program)		= typename NIK_MODULE::T_block_program;
	NIK_POLICY auto nik_name(NIK_PREFIX, U_block_program)	= NIK_MODULE::U_block_program;

	using nik_name(NIK_PREFIX, T_linear_program)		= typename NIK_MODULE::T_linear_program;
	NIK_POLICY auto nik_name(NIK_PREFIX, U_linear_program)	= NIK_MODULE::U_linear_program;

	using nik_name(NIK_PREFIX, T_user_program)		= typename NIK_MODULE::T_user_program;
	NIK_POLICY auto nik_name(NIK_PREFIX, U_user_program)	= NIK_MODULE::U_user_program;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// instructions:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// atomic:

/***********************************************************************************************************************/

// interposers:

	template<auto... Note>
	NIK_POLICY auto nik_name(NIK_PREFIX, pause)	= NIK_MODULE::template pause<Note...>;

	template<auto... Note>
	NIK_POLICY auto nik_name(NIK_PREFIX, save)	= NIK_MODULE::template save<Note...>;

	template<auto... Note>
	NIK_POLICY auto nik_name(NIK_PREFIX, branch)	= NIK_MODULE::template branch<Note...>;

// halters:

	template<auto... Note>
	NIK_POLICY auto nik_name(NIK_PREFIX, first)	= NIK_MODULE::template first<Note...>;

	template<auto... Note>
	NIK_POLICY auto nik_name(NIK_PREFIX, rest)	= NIK_MODULE::template rest<Note...>;

// debuggers:

	template<auto... Note>
	NIK_POLICY auto nik_name(NIK_PREFIX, depth)	= NIK_MODULE::template depth<Note...>;

	template<auto... Note>
	NIK_POLICY auto nik_name(NIK_PREFIX, dump)	= NIK_MODULE::template dump<Note...>;

	template<auto... Note>
	NIK_POLICY auto nik_name(NIK_PREFIX, registers)	= NIK_MODULE::template registers<Note...>;

	template<auto... Note>
	NIK_POLICY auto nik_name(NIK_PREFIX, arguments)	= NIK_MODULE::template arguments<Note...>;

// passers:

	template<auto... Note>
	NIK_POLICY auto nik_name(NIK_PREFIX, copy_i_value__insert_at_h0_front)		=
		NIK_MODULE::template copy_i_value__insert_at_h0_front<Note...>;

	template<auto... Note>
	NIK_POLICY auto nik_name(NIK_PREFIX, drop_r_block)				=
		NIK_MODULE::template drop_r_block<Note...>;

	template<auto... Note>
	NIK_POLICY auto nik_name(NIK_PREFIX, move_h0_first__insert_at_r_front)		=
		NIK_MODULE::template move_h0_first__insert_at_r_front<Note...>;

	template<auto... Note>
	NIK_POLICY auto nik_name(NIK_PREFIX, move_h1_all__insert_at_r_front)		=
		NIK_MODULE::template move_h1_all__insert_at_r_front<Note...>;

	template<auto... Note>
	NIK_POLICY auto nik_name(NIK_PREFIX, apply_h0_all__return_value)		=
		NIK_MODULE::template apply_h0_all__return_value<Note...>;

	template<auto... Note>
	NIK_POLICY auto nik_name(NIK_PREFIX, apply_h0_all__move__insert_at_r_front)	=
		NIK_MODULE::template apply_h0_all__move__insert_at_r_front<Note...>;

	template<auto... Note>
	NIK_POLICY auto nik_name(NIK_PREFIX, compel_h0_all__return_value)		=
		NIK_MODULE::template compel_h0_all__return_value<Note...>;

	template<auto... Note>
	NIK_POLICY auto nik_name(NIK_PREFIX, compel_h0_all__move__insert_at_r_front)	=
		NIK_MODULE::template compel_h0_all__move__insert_at_r_front<Note...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compounds:

/***********************************************************************************************************************/

// block:

	// passers:

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, at)					=
			NIK_MODULE::template at<Pos>;

/***********************************************************************************************************************/

// linear:

	// interoperators:

		template<auto Pos, auto Program, auto... Args>
		NIK_POLICY auto nik_name(NIK_PREFIX, call)					=
			NIK_MODULE::template call<Pos, Program, Args...>;

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, instr_goto)				=
			NIK_MODULE::template instr_goto<Pos>;

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, regstr_goto)				=
			NIK_MODULE::template regstr_goto<Pos>;

	// mutators:

		template<auto Pos>
		NIK_POLICY auto nik_name(NIK_PREFIX, erase)					=
			NIK_MODULE::template erase<Pos>;

		template<auto Pos, auto Obj>
		NIK_POLICY auto nik_name(NIK_PREFIX, insert)					=
			NIK_MODULE::template insert<Pos, Obj>;

		template<auto Pos, auto Obj>
		NIK_POLICY auto nik_name(NIK_PREFIX, replace)					=
			NIK_MODULE::template replace<Pos, Obj>;

		template<auto Pos, auto Obj>
		NIK_POLICY auto nik_name(NIK_PREFIX, regstr_assign)				=
			NIK_MODULE::template regstr_assign<Pos, Obj>;

		template<auto Pos, auto Obj>
		NIK_POLICY auto nik_name(NIK_PREFIX, instr_assign)				=
			NIK_MODULE::template instr_assign<Pos, Obj>;

	// passers:

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
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// evaluation:

/***********************************************************************************************************************/

// start:

	template<typename program, auto... Vs, typename T>
	inline NIK_POLICY auto start(T v = nik_module(interpret, cache, architect, v_0_5, gcc)::template U_pack_Vs<>)
	{
		return NIK_MODULE::template start<program, Vs...>(v);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

