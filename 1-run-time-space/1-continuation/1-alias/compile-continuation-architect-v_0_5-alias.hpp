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

// continuation alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// lift:

	template<auto f>
	using nik_name(NIK_PREFIX, S_lift)				= typename NIK_MODULE::template S_lift<f>;

	template<auto f>
	NIK_POLICY auto nik_name(NIK_PREFIX, lift)			= NIK_MODULE::template lift<f>;

/***********************************************************************************************************************/

// keywords:

	using nik_name(NIK_PREFIX, S_is_lifted_id_keyword)		= typename NIK_MODULE::S_is_lifted_id_keyword;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_is_lifted_id_keyword)	= NIK_MODULE::U_is_lifted_id_keyword;

	template<auto uf>
	NIK_POLICY auto nik_name(NIK_PREFIX, is_lifted_id_keyword)	= NIK_MODULE::template is_lifted_id_keyword<uf>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// stem:

/***********************************************************************************************************************/

// specializations:

	template<auto pred, auto ante, auto conse>
	using nik_name(NIK_PREFIX, S_stem)		= typename NIK_MODULE::template S_stem<pred, ante, conse>;

// dispatch:

	template<auto pred, auto ante, auto conse>
	NIK_POLICY auto nik_name(NIK_PREFIX, stem)	= NIK_MODULE::template stem<pred, ante, conse>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// costem:

/***********************************************************************************************************************/

// specializations:

	template<auto pred, auto ante, auto conse>
	using nik_name(NIK_PREFIX, S_costem)		= typename NIK_MODULE::template S_costem<pred, ante, conse>;

// dispatch:

	template<auto pred, auto ante, auto conse>
	NIK_POLICY auto nik_name(NIK_PREFIX, costem)	= NIK_MODULE::template costem<pred, ante, conse>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// distem:

/***********************************************************************************************************************/

// specializations:

	template<auto pred, auto ante, auto conse>
	using nik_name(NIK_PREFIX, S_distem)		= typename NIK_MODULE::template S_distem<pred, ante, conse>;

// dispatch:

	template<auto pred, auto ante, auto conse>
	NIK_POLICY auto nik_name(NIK_PREFIX, distem)	= NIK_MODULE::template distem<pred, ante, conse>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// endoposition:

/***********************************************************************************************************************/

// endopose:

	using nik_name(NIK_PREFIX, S_endopose)				= typename NIK_MODULE::S_endopose;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_endopose)		= NIK_MODULE::U_endopose;

	template<auto uf, auto ug>
	NIK_POLICY auto nik_name(NIK_PREFIX, endopose)			= NIK_MODULE::template endopose<uf, ug>;

// chain lift:

	template<auto f0, auto... fs>
	NIK_POLICY auto nik_name(NIK_PREFIX, chain_lift)		= NIK_MODULE::template chain_lift<f0, fs...>;

// chain endopose:

	template<auto c0, auto... cs>
	NIK_POLICY auto nik_name(NIK_PREFIX, chain_endopose)		= NIK_MODULE::template chain_endopose<c0, cs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// optimized endoposition:

/***********************************************************************************************************************/

// opt endopose:

	using nik_name(NIK_PREFIX, S_opt_endopose)			= typename NIK_MODULE::S_opt_endopose;

	NIK_POLICY auto nik_name(NIK_PREFIX, U_opt_endopose)		= NIK_MODULE::U_opt_endopose;

	template<auto uf, auto ug>
	NIK_POLICY auto nik_name(NIK_PREFIX, opt_endopose)		= NIK_MODULE::template opt_endopose<uf, ug>;

// opt chain lift:

	template<auto f0, auto... fs>
	NIK_POLICY auto nik_name(NIK_PREFIX, opt_chain_lift)		= NIK_MODULE::template opt_chain_lift<f0, fs...>;

// opt chain endopose:

	template<auto c0, auto... cs>
	NIK_POLICY auto nik_name(NIK_PREFIX, opt_chain_endopose)	= NIK_MODULE::template opt_chain_endopose<c0, cs...>;

// close cycle:

	template<auto expr, typename T>
	NIK_POLICY auto nik_name(NIK_PREFIX, close_cycle)		= NIK_MODULE::template close_cycle<expr, T>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

