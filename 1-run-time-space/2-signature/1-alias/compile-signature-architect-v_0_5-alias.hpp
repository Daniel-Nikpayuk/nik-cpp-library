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

// dispatch:

/***********************************************************************************************************************/

	using nik_name(NIK_PREFIX, SignMember)				= typename NIK_MODULE::SignMember;

	template<auto m>
	NIK_POLICY bool nik_name(NIK_PREFIX, is_sign_member_0)		= NIK_MODULE::template is_sign_member_0<m>;

	template<auto m>
	NIK_POLICY bool nik_name(NIK_PREFIX, is_sign_member_1)		= NIK_MODULE::template is_sign_member_1<m>;

	template<auto m>
	NIK_POLICY bool nik_name(NIK_PREFIX, is_sign_member_2)		= NIK_MODULE::template is_sign_member_2<m>;

	template<auto m>
	NIK_POLICY bool nik_name(NIK_PREFIX, is_sign_member_3)		= NIK_MODULE::template is_sign_member_3<m>;

	template<auto m>
	NIK_POLICY bool nik_name(NIK_PREFIX, is_sign_member_4)		= NIK_MODULE::template is_sign_member_4<m>;

	template<auto m>
	NIK_POLICY bool nik_name(NIK_PREFIX, is_sign_member_5)		= NIK_MODULE::template is_sign_member_5<m>;

	//

	using nik_name(NIK_PREFIX, SignMutability)			= typename NIK_MODULE::SignMutability;

	using nik_name(NIK_PREFIX, SignDenotation)			= typename NIK_MODULE::SignDenotation;

	template<auto m>
	NIK_POLICY bool nik_name(NIK_PREFIX, sign_is_immutable)		= NIK_MODULE::template sign_is_immutable<m>;

	template<auto m>
	NIK_POLICY bool nik_name(NIK_PREFIX, sign_is_variable)		= NIK_MODULE::template sign_is_variable<m>;

	template<auto d>
	NIK_POLICY bool nik_name(NIK_PREFIX, sign_member_is_reference)	= NIK_MODULE::template sign_member_is_reference<d>;

	template<auto d>
	NIK_POLICY bool nik_name(NIK_PREFIX, sign_member_is_dereference) = NIK_MODULE::template sign_member_is_dereference<d>;

	//

	template<auto m, auto d>
	using nik_name(NIK_PREFIX, _sign_attributes)		= typename NIK_MODULE::template _sign_attributes<m, d>;

	using nik_name(NIK_PREFIX, sign_attr_ref)		= typename NIK_MODULE::sign_attr_ref;
	using nik_name(NIK_PREFIX, sign_attr_deref)		= typename NIK_MODULE::sign_attr_deref;
	using nik_name(NIK_PREFIX, sign_attr_cref)		= typename NIK_MODULE::sign_attr_cref;
	using nik_name(NIK_PREFIX, sign_attr_cderef)		= typename NIK_MODULE::sign_attr_cderef;

	//

	template<typename S, typename A>
	using nik_name(NIK_PREFIX, _sign_argument)		= typename NIK_MODULE::template _sign_argument<S, A>;

	template<typename S>
	using nik_name(NIK_PREFIX, sign_arg_by_ref)		= typename NIK_MODULE::template sign_arg_by_ref<S>;

	template<typename S>
	using nik_name(NIK_PREFIX, sign_arg_by_deref)		= typename NIK_MODULE::template sign_arg_by_deref<S>;

	template<typename S>
	using nik_name(NIK_PREFIX, sign_arg_by_cref)		= typename NIK_MODULE::template sign_arg_by_cref<S>;

	template<typename S>
	using nik_name(NIK_PREFIX, sign_arg_by_cderef)		= typename NIK_MODULE::template sign_arg_by_cderef<S>;

	// member 0:

	template<typename S, typename A>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve_member_0)	= NIK_MODULE::template resolve_member_0<S, A>;

	// member 1:

	template<typename S, typename A>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve_member_1)	= NIK_MODULE::template resolve_member_1<S, A>;

	// member 2:

	template<typename S, typename A>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve_member_2)	= NIK_MODULE::template resolve_member_2<S, A>;

	// member 3:

	template<typename S, typename A>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve_member_3)	= NIK_MODULE::template resolve_member_3<S, A>;

	// member 4:

	template<typename S, typename A>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve_member_4)	= NIK_MODULE::template resolve_member_4<S, A>;

	// member 5:

	template<typename S, typename A>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve_member_5)	= NIK_MODULE::template resolve_member_5<S, A>;

	//

	template<auto m, typename A>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve_member)	= NIK_MODULE::template resolve_member<m, A>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

