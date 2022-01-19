/************************************************************************************************************************
**
** Copyright 2021-2022 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

// halters:

	// value:

	template<auto...> NIK_POLICY auto nik_name(NIK_PREFIX, first)		= NIK_MODULE::template first<>;
	template<auto...> NIK_POLICY auto nik_name(NIK_PREFIX, rest)		= NIK_MODULE::template rest<>;

	// (debuggers):

	template<auto...> NIK_POLICY auto nik_name(NIK_PREFIX, depth)		= NIK_MODULE::template depth<>;
	template<auto...> NIK_POLICY auto nik_name(NIK_PREFIX, dump)		= NIK_MODULE::template dump<>;
	template<auto...> NIK_POLICY auto nik_name(NIK_PREFIX, registers)	= NIK_MODULE::template registers<>;
	template<auto...> NIK_POLICY auto nik_name(NIK_PREFIX, arguments)	= NIK_MODULE::template arguments<>;

	//

	template<auto Arg> NIK_POLICY auto nik_name(NIK_PREFIX, argument)	= NIK_MODULE::template argument<Arg>;

// interoperators:

	template<auto Pos, auto Prog, auto... Args>
	NIK_POLICY auto nik_name(NIK_PREFIX, call)		= NIK_MODULE::template call<Pos, Prog, Args...>;

	template<auto Pos, auto Prog, auto Adj, auto... Args>
	NIK_POLICY auto nik_name(NIK_PREFIX, adj_call)		= NIK_MODULE::template adj_call<Pos, Prog, Adj, Args...>;

// passers:

	template<auto...>
	NIK_POLICY auto nik_name(NIK_PREFIX, cycle)		= NIK_MODULE::template cycle<>;

	template<auto Pos>
	NIK_POLICY auto nik_name(NIK_PREFIX, branch)		= NIK_MODULE::template branch<Pos>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compounds:

/***********************************************************************************************************************/

// block:

	template<auto Pos>
	NIK_POLICY auto nik_name(NIK_PREFIX, value)		= NIK_MODULE::template value<Pos>;

//	template<auto Pos>
//	NIK_POLICY auto nik_name(NIK_PREFIX, left)		= NIK_MODULE::template left<Pos>;

//	template<auto Pos>
//	NIK_POLICY auto nik_name(NIK_PREFIX, right)		= NIK_MODULE::template right<Pos>;

/***********************************************************************************************************************/

// linear:

	template<auto Pos>
	NIK_POLICY auto nik_name(NIK_PREFIX, erase)		= NIK_MODULE::template erase<Pos>;

	template<auto Pos, auto Obj>
	NIK_POLICY auto nik_name(NIK_PREFIX, insert)		= NIK_MODULE::template insert<Pos, Obj>;

	template<auto Pos, auto Obj>
	NIK_POLICY auto nik_name(NIK_PREFIX, replace)		= NIK_MODULE::template replace<Pos, Obj>;

/***********************************************************************************************************************/

// near linear:

	template<auto Arg>
	NIK_POLICY auto nik_name(NIK_PREFIX, is_null)		= NIK_MODULE::template is_null<Arg>;

	template<auto Arg, auto Obj>
	NIK_POLICY auto nik_name(NIK_PREFIX, cons_assign)	= NIK_MODULE::template cons_assign<Arg, Obj>;

	template<auto Arg, auto Obj>
	NIK_POLICY auto nik_name(NIK_PREFIX, push_assign)	= NIK_MODULE::template push_assign<Arg, Obj>;

	template<auto Pos, auto Arg>
	NIK_POLICY auto nik_name(NIK_PREFIX, car)		= NIK_MODULE::template car<Pos, Arg>;

	template<auto Arg>
	NIK_POLICY auto nik_name(NIK_PREFIX, cdr_assign)	= NIK_MODULE::template cdr_assign<Arg>;

//	template<auto Arg>
//	NIK_POLICY auto nik_name(NIK_PREFIX, map_assign)	= NIK_MODULE::template map_assign<Arg>;

//	template<auto Pos, auto Arg>
//	NIK_POLICY auto nik_name(NIK_PREFIX, cat_assign)	= NIK_MODULE::template cat_assign<Pos, Arg>;

//	template<auto Pos, auto Arg>
//	NIK_POLICY auto nik_name(NIK_PREFIX, zip_assign)	= NIK_MODULE::template zip_assign<Pos, Arg>;

/***********************************************************************************************************************/

// user:

	template<auto Op, auto... Args>
	NIK_POLICY auto nik_name(NIK_PREFIX, test)		= NIK_MODULE::template test<Op, Args...>;

	template<auto Act, auto... Args>
	NIK_POLICY auto nik_name(NIK_PREFIX, check)		= NIK_MODULE::template check<Act, Args...>;

	template<auto Pos, auto Op, auto... Args>
	NIK_POLICY auto nik_name(NIK_PREFIX, apply)		= NIK_MODULE::template apply<Pos, Op, Args...>;

	template<auto Pos, auto Act, auto... Args>
	NIK_POLICY auto nik_name(NIK_PREFIX, compel)		= NIK_MODULE::template compel<Pos, Act, Args...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

