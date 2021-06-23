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

// signature alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// one cycle:

/***********************************************************************************************************************/

// signature:

	template<typename... Ts>
	using nik_name(NIK_PREFIX, one_cycle)			= typename NIK_MODULE::template one_cycle<Ts...>;

// accessors:

	// out:

	template<typename... Ts>
	NIK_POLICY auto nik_name(NIK_PREFIX, dout)		= NIK_MODULE::template dout<Ts...>;

	template<typename... Ts>
	NIK_POLICY auto nik_name(NIK_PREFIX, iout)		= NIK_MODULE::template iout<Ts...>;

	// in:

	template<typename... Ts>
	NIK_POLICY auto nik_name(NIK_PREFIX, din)		= NIK_MODULE::template din<Ts...>;

	template<typename... Ts>
	NIK_POLICY auto nik_name(NIK_PREFIX, iin)		= NIK_MODULE::template iin<Ts...>;

	// car in:

	template<typename... Ts>
	NIK_POLICY auto nik_name(NIK_PREFIX, dcar_in)		= NIK_MODULE::template dcar_in<Ts...>;

	template<typename... Ts>
	NIK_POLICY auto nik_name(NIK_PREFIX, icar_in)		= NIK_MODULE::template icar_in<Ts...>;

	// cdr in:

	template<typename... Ts>
	NIK_POLICY auto nik_name(NIK_PREFIX, dcdr_in)		= NIK_MODULE::template dcdr_in<Ts...>;

	template<typename... Ts>
	NIK_POLICY auto nik_name(NIK_PREFIX, icdr_in)		= NIK_MODULE::template icdr_in<Ts...>;

	// end:

	template<typename... Ts>
	NIK_POLICY auto nik_name(NIK_PREFIX, dend)		= NIK_MODULE::template dend<Ts...>;

	template<typename... Ts>
	NIK_POLICY auto nik_name(NIK_PREFIX, iend)		= NIK_MODULE::template iend<Ts...>;

	// aux:

	template<typename... Ts>
	NIK_POLICY auto nik_name(NIK_PREFIX, daux)		= NIK_MODULE::template daux<Ts...>;

	template<typename... Ts>
	NIK_POLICY auto nik_name(NIK_PREFIX, iaux)		= NIK_MODULE::template iaux<Ts...>;

	// msg:

	template<typename... Ts>
	NIK_POLICY auto nik_name(NIK_PREFIX, dmsg)		= NIK_MODULE::template dmsg<Ts...>;

	template<typename... Ts>
	NIK_POLICY auto nik_name(NIK_PREFIX, imsg)		= NIK_MODULE::template imsg<Ts...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

