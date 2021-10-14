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

	template<typename... Ts>
	using nik_name(NIK_PREFIX, resolve_signature) = typename NIK_MODULE::template resolve_signature<Ts...>;

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
	NIK_POLICY bool nik_name(NIK_PREFIX, is_sign_immutable)		= NIK_MODULE::template is_sign_immutable<m>;

	template<auto m>                                                                               
	NIK_POLICY bool nik_name(NIK_PREFIX, is_sign_variable)		= NIK_MODULE::template is_sign_variable<m>;

	template<auto d>
	NIK_POLICY bool nik_name(NIK_PREFIX, is_sign_reference)		= NIK_MODULE::template is_sign_reference<d>;

	template<auto d>                                                                               
	NIK_POLICY bool nik_name(NIK_PREFIX, is_sign_dereference) 	= NIK_MODULE::template is_sign_dereference<d>;

	//

	template<auto m, auto d>
	using nik_name(NIK_PREFIX, _sign_attributes)		= typename NIK_MODULE::template _sign_attributes<m, d>;

	using nik_name(NIK_PREFIX, sign_attr_as_ref)		= typename NIK_MODULE::sign_attr_as_ref;
	using nik_name(NIK_PREFIX, sign_attr_as_deref)		= typename NIK_MODULE::sign_attr_as_deref;
	using nik_name(NIK_PREFIX, sign_attr_as_cref)		= typename NIK_MODULE::sign_attr_as_cref;
	using nik_name(NIK_PREFIX, sign_attr_as_cderef)		= typename NIK_MODULE::sign_attr_as_cderef;

	//

	template<auto M, typename A>
	using nik_name(NIK_PREFIX, _sign_argument)		= typename NIK_MODULE::template _sign_argument<M, A>;

	template<auto M>
	using nik_name(NIK_PREFIX, sign_arg_as_ref)		= typename NIK_MODULE::template sign_arg_as_ref<M>;

	template<auto M>
	using nik_name(NIK_PREFIX, sign_arg_as_deref)		= typename NIK_MODULE::template sign_arg_as_deref<M>;

	template<auto M>
	using nik_name(NIK_PREFIX, sign_arg_as_cref)		= typename NIK_MODULE::template sign_arg_as_cref<M>;

	template<auto M>
	using nik_name(NIK_PREFIX, sign_arg_as_cderef)		= typename NIK_MODULE::template sign_arg_as_cderef<M>;

	//

	template<typename... As>
	using nik_name(NIK_PREFIX, _sign_facade)		= typename NIK_MODULE::template _sign_facade<As...>;

	template<auto... Ms>
	using nik_name(NIK_PREFIX, _selector_facade)		= typename NIK_MODULE::template _selector_facade<Ms...>;

/***********************************************************************************************************************/

// map args to out types:

	template<auto U>
	NIK_POLICY auto nik_name(NIK_PREFIX, selectors_to_out_types)	= NIK_MODULE::template selectors_to_out_types<U>;

	// member 0:

	template<typename S, typename A>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve_selector_0)	= NIK_MODULE::template resolve_selector_0<S, A>;

	// member 1:

	template<typename S, typename A>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve_selector_1)	= NIK_MODULE::template resolve_selector_1<S, A>;

	// member 2:

	template<typename S, typename A>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve_selector_2)	= NIK_MODULE::template resolve_selector_2<S, A>;

	// member 3:

	template<typename S, typename A>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve_selector_3)	= NIK_MODULE::template resolve_selector_3<S, A>;

	// member 4:

	template<typename S, typename A>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve_selector_4)	= NIK_MODULE::template resolve_selector_4<S, A>;

	// member 5:

	template<typename S, typename A>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve_selector_5)	= NIK_MODULE::template resolve_selector_5<S, A>;

	//

	template<auto M, typename A>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve_selector)		= NIK_MODULE::template resolve_selector<M, A>;

	template<typename S, typename F>
	NIK_POLICY auto nik_name(NIK_PREFIX, args_to_selectors)		= NIK_MODULE::template args_to_selectors<S, F>;

/***********************************************************************************************************************/

// higher orders:

	template<auto UF, typename SA, typename S>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve_assign)		= NIK_MODULE::template resolve_assign<UF, SA, S>;

	template<auto UF, typename SA, typename S>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve_apply)		= NIK_MODULE::template resolve_apply<UF, SA, S>;

	template<auto UF, typename SA, typename S>
	NIK_POLICY auto nik_name(NIK_PREFIX, resolve_test)		= NIK_MODULE::template resolve_test<UF, SA, S>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

