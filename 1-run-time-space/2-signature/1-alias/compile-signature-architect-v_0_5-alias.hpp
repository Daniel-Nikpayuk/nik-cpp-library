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

// signature:

	template<typename... Ts>
	using nik_name(NIK_PREFIX, signature) = typename NIK_MODULE::template signature<Ts...>;

// accessors:

	// member 0:

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, member_0_ref)(Signature & s)
		{ return NIK_MODULE::member_0_ref(s); }

	template<typename Signature>
	inline NIK_POLICY const auto & nik_name(NIK_PREFIX, member_0_cref)(const Signature & s)
		{ return NIK_MODULE::member_0_cref(s); }

	// member 1:

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, member_1_ref)(Signature & s)
		{ return NIK_MODULE::member_1_ref(s); }

	template<typename Signature>
	inline NIK_POLICY const auto & nik_name(NIK_PREFIX, member_1_cref)(const Signature & s)
		{ return NIK_MODULE::member_1_cref(s); }

	// member 2:

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, member_2_ref)(Signature & s)
		{ return NIK_MODULE::member_2_ref(s); }

	template<typename Signature>
	inline NIK_POLICY const auto & nik_name(NIK_PREFIX, member_2_cref)(const Signature & s)
		{ return NIK_MODULE::member_2_cref(s); }

	// member 3:

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, member_3_ref)(Signature & s)
		{ return NIK_MODULE::member_3_ref(s); }

	template<typename Signature>
	inline NIK_POLICY const auto & nik_name(NIK_PREFIX, member_3_cref)(const Signature & s)
		{ return NIK_MODULE::member_3_cref(s); }

	// member 4:

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, member_4_ref)(Signature & s)
		{ return NIK_MODULE::member_4_ref(s); }

	template<typename Signature>
	inline NIK_POLICY const auto & nik_name(NIK_PREFIX, member_4_cref)(const Signature & s)
		{ return NIK_MODULE::member_4_cref(s); }

	// member 5:

	template<typename Signature>
	inline NIK_POLICY auto & nik_name(NIK_PREFIX, member_5_ref)(Signature & s)
		{ return NIK_MODULE::member_5_ref(s); }

	template<typename Signature>
	inline NIK_POLICY const auto & nik_name(NIK_PREFIX, member_5_cref)(const Signature & s)
		{ return NIK_MODULE::member_5_cref(s); }

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

