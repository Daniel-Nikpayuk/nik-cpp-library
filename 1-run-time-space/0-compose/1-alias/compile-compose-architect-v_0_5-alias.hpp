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

// compose alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

	NIK_POLICY auto nik_name(NIK_PREFIX, _id_)			= NIK_MODULE::_id_;

	using nik_name(NIK_PREFIX, S_is_id_keyword)			= typename NIK_MODULE::S_is_id_keyword;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_id_keyword)		= NIK_MODULE::U_is_id_keyword;

	template<auto f>
	NIK_POLICY auto nik_name(NIK_PREFIX, is_id_keyword)		= NIK_MODULE::template is_id_keyword<f>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// composition:

/***********************************************************************************************************************/

// safe compose:

	using nik_name(NIK_PREFIX, S_safe_compose)			= typename NIK_MODULE::S_safe_compose;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_safe_compose)		= NIK_MODULE::U_safe_compose;

	template<auto f, auto g>
	NIK_POLICY auto nik_name(NIK_PREFIX, safe_compose)		= NIK_MODULE::template safe_compose<f, g>;

// safe do compose:

	using nik_name(NIK_PREFIX, S_safe_do_compose)			= typename NIK_MODULE::S_safe_do_compose;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_safe_do_compose)		= NIK_MODULE::U_safe_do_compose;

	template<auto f, auto g>
	NIK_POLICY auto nik_name(NIK_PREFIX, safe_do_compose)		= NIK_MODULE::template safe_do_compose<f, g>;

// compose:

	using nik_name(NIK_PREFIX, S_compose)				= typename NIK_MODULE::S_compose;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_compose)			= NIK_MODULE::U_compose;

	template<auto f, auto g>
	NIK_POLICY auto nik_name(NIK_PREFIX, compose)			= NIK_MODULE::template compose<f, g>;

// do compose:

	using nik_name(NIK_PREFIX, S_do_compose)			= typename NIK_MODULE::S_do_compose;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_do_compose)		= NIK_MODULE::U_do_compose;

	template<auto f, auto g>
	NIK_POLICY auto nik_name(NIK_PREFIX, do_compose)		= NIK_MODULE::template do_compose<f, g>;

// do chain compose:

	template<auto f0, auto... fs>
	NIK_POLICY auto nik_name(NIK_PREFIX, do_chain_compose)		= NIK_MODULE::template do_chain_compose<f0, fs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// optimized composition:

/***********************************************************************************************************************/

// opt compose:

	using nik_name(NIK_PREFIX, S_opt_compose)			= typename NIK_MODULE::S_opt_compose;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_opt_compose)		= NIK_MODULE::U_opt_compose;

	template<auto f, auto g>
	NIK_POLICY auto nik_name(NIK_PREFIX, opt_compose)		= NIK_MODULE::template opt_compose<f, g>;

// opt do compose:

	using nik_name(NIK_PREFIX, S_opt_do_compose)			= typename NIK_MODULE::S_opt_do_compose;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_opt_do_compose)		= NIK_MODULE::U_opt_do_compose;

	template<auto f, auto g>
	NIK_POLICY auto nik_name(NIK_PREFIX, opt_do_compose)		= NIK_MODULE::template opt_do_compose<f, g>;

// opt do chain compose:

	template<auto f0, auto... fs>
	NIK_POLICY auto nik_name(NIK_PREFIX, opt_do_chain_compose)	= NIK_MODULE::template opt_do_chain_compose<f0, fs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// subcomposition:

	using nik_name(NIK_PREFIX, S_subcompose)			= typename NIK_MODULE::S_subcompose;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_subcompose)		= NIK_MODULE::U_subcompose;

	template<auto f, auto g, auto pos>
	NIK_POLICY auto nik_name(NIK_PREFIX, subcompose)		= NIK_MODULE::template subcompose<f, g, pos>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// higher orders:

/***********************************************************************************************************************/

// test:

	template<auto op, auto l0, auto... ls>
	NIK_POLICY auto nik_name(NIK_PREFIX, test)			= NIK_MODULE::template test<op, l0, ls...>;

// assign:

	template<auto r, auto op, auto... ls>
	NIK_POLICY auto nik_name(NIK_PREFIX, assign)			= NIK_MODULE::template assign<r, op, ls...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

