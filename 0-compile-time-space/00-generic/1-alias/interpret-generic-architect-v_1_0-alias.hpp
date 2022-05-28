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

// alias:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

	using nik_name(NIK_PREFIX, _nt_)				= typename NIK_MODULE::_nt_;

	NIK_POLICY auto nik_name(NIK_PREFIX, _na_)			= NIK_MODULE::_na_;

	template<typename... Ts>
	using nik_name(NIK_PREFIX, _NA_)				= typename NIK_MODULE::template _NA_<Ts...>;

	template<auto... Vs>
	using nik_name(NIK_PREFIX, _NB_)				= typename NIK_MODULE::template _NB_<Vs...>;

/***********************************************************************************************************************/

// numeric:

	using key_type							= typename NIK_MODULE::key_type;
	using ckey_type							= typename NIK_MODULE::ckey_type;

	NIK_POLICY auto nik_name(NIK_PREFIX, _zero)			= NIK_MODULE::_zero;
	NIK_POLICY auto nik_name(NIK_PREFIX, _one)			= NIK_MODULE::_one;
	NIK_POLICY auto nik_name(NIK_PREFIX, _two)			= NIK_MODULE::_two;
	NIK_POLICY auto nik_name(NIK_PREFIX, _three)			= NIK_MODULE::_three;
	NIK_POLICY auto nik_name(NIK_PREFIX, _four)			= NIK_MODULE::_four;
	NIK_POLICY auto nik_name(NIK_PREFIX, _five)			= NIK_MODULE::_five;
	NIK_POLICY auto nik_name(NIK_PREFIX, _six)			= NIK_MODULE::_six;
	NIK_POLICY auto nik_name(NIK_PREFIX, _seven)			= NIK_MODULE::_seven;
	NIK_POLICY auto nik_name(NIK_PREFIX, _eight)			= NIK_MODULE::_eight;
	NIK_POLICY auto nik_name(NIK_PREFIX, _nine)			= NIK_MODULE::_nine;
	NIK_POLICY auto nik_name(NIK_PREFIX, _ten)			= NIK_MODULE::_ten;

	using index_type						= typename NIK_MODULE::index_type;
	using cindex_type						= typename NIK_MODULE::cindex_type;

	NIK_POLICY auto nik_name(NIK_PREFIX,_2_0)			= NIK_MODULE::_2_0;
	NIK_POLICY auto nik_name(NIK_PREFIX,_2_1)			= NIK_MODULE::_2_1;
	NIK_POLICY auto nik_name(NIK_PREFIX,_2_2)			= NIK_MODULE::_2_2;
	NIK_POLICY auto nik_name(NIK_PREFIX,_2_3)			= NIK_MODULE::_2_3;
	NIK_POLICY auto nik_name(NIK_PREFIX,_2_4)			= NIK_MODULE::_2_4;
	NIK_POLICY auto nik_name(NIK_PREFIX,_2_5)			= NIK_MODULE::_2_5;
	NIK_POLICY auto nik_name(NIK_PREFIX,_2_6)			= NIK_MODULE::_2_6;
	NIK_POLICY auto nik_name(NIK_PREFIX,_2_7)			= NIK_MODULE::_2_7;
	NIK_POLICY auto nik_name(NIK_PREFIX,_2_8)			= NIK_MODULE::_2_8;
	NIK_POLICY auto nik_name(NIK_PREFIX,_2_9)			= NIK_MODULE::_2_9;

	using depth_type						= typename NIK_MODULE::depth_type;
	using cdepth_type						= typename NIK_MODULE::cdepth_type;

/***********************************************************************************************************************/

// apply:

	template<auto Op, auto... Vs>
	NIK_POLICY auto nik_name(NIK_PREFIX, apply)			= NIK_MODULE::template apply<Op, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

