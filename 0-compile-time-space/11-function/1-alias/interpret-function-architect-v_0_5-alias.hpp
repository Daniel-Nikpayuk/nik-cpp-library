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

// function alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// reflection:

/***********************************************************************************************************************/

// match:

	using nik_name(NIK_PREFIX, S_is_function)			= typename NIK_MODULE::S_is_function;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_function)		= NIK_MODULE::U_is_function;

	template<auto f>
	NIK_POLICY auto nik_name(NIK_PREFIX, is_function)		= NIK_MODULE::template is_function<f>;

// arity:

	using nik_name(NIK_PREFIX, S_arity)				= typename NIK_MODULE::S_arity;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_arity)			= NIK_MODULE::U_arity;

	template<auto f>
	NIK_POLICY auto nik_name(NIK_PREFIX, arity)			= NIK_MODULE::template arity<f>;

// is n-ary:

	using nik_name(NIK_PREFIX, S_is_n_ary)				= typename NIK_MODULE::S_is_n_ary;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_n_ary)		= NIK_MODULE::U_is_n_ary;

	template<auto f, auto n>
	NIK_POLICY auto nik_name(NIK_PREFIX, is_n_ary)			= NIK_MODULE::template is_n_ary<f, n>;

// out type:

	using nik_name(NIK_PREFIX, S_out_type)				= typename NIK_MODULE::S_out_type;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_out_type)		= NIK_MODULE::U_out_type;

	template<auto f>
	using nik_name(NIK_PREFIX, out_type)				= typename NIK_MODULE::template out_type<f>;

// in type:

	using nik_name(NIK_PREFIX, S_in_type)				= typename NIK_MODULE::S_in_type;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_in_type)			= NIK_MODULE::U_in_type;

	template<auto f, auto pos = 0, auto depth = 500>
	using nik_name(NIK_PREFIX, in_type)				= typename NIK_MODULE::template
										in_type<f, pos, depth>;

// in types:

	using nik_name(NIK_PREFIX, S_in_types)				= typename NIK_MODULE::S_in_types;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_in_types)		= NIK_MODULE::U_in_types;

	template<auto f>
	using nik_name(NIK_PREFIX, in_types)				= typename NIK_MODULE::template in_types<f>;

// in types left:

	using nik_name(NIK_PREFIX, S_in_types_left)			= typename NIK_MODULE::S_in_types_left;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_in_types_left)		= NIK_MODULE::U_in_types_left;

	template<auto f, auto pos, auto depth = 500>
	using nik_name(NIK_PREFIX, in_types_left)			= typename NIK_MODULE::template
										in_types_left<f, pos, depth>;

// in types right:

	using nik_name(NIK_PREFIX, S_in_types_right)			= typename NIK_MODULE::S_in_types_right;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_in_types_right)		= NIK_MODULE::U_in_types_right;

	template<auto f, auto pos, auto depth = 500>
	using nik_name(NIK_PREFIX, in_types_right)			= typename NIK_MODULE::template
										in_types_right<f, pos, depth>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

