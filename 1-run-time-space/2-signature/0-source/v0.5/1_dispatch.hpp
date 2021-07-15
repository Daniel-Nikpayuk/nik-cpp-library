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

// dispatch source:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// enumeration filters (level 0):

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// members:

/***********************************************************************************************************************/

	enum struct SignMember
	{
		member_0,
		member_1,
		member_2,
		member_3,
		member_4,
		member_5,

		dimension // filler
	};

	template<SignMember m> static constexpr bool is_sign_member_0		= (m == SignMember::member_0);
	template<SignMember m> static constexpr bool is_sign_member_1		= (m == SignMember::member_1);
	template<SignMember m> static constexpr bool is_sign_member_2		= (m == SignMember::member_2);
	template<SignMember m> static constexpr bool is_sign_member_3		= (m == SignMember::member_3);
	template<SignMember m> static constexpr bool is_sign_member_4		= (m == SignMember::member_4);
	template<SignMember m> static constexpr bool is_sign_member_5		= (m == SignMember::member_5);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// attributes:

/***********************************************************************************************************************/

	using SignMutability = typename function_module::Mutability;

	enum struct SignDenotation
	{
		reference,
		dereference,

		dimension // filler
	};

/***********************************************************************************************************************/

	template<SignMutability m>
	static constexpr bool sign_is_immutable			= function_module::template is_immutable<m>;

	template<SignMutability m>
	static constexpr bool sign_is_variable			= function_module::template is_variable<m>;

	//

	template<SignDenotation d>
	static constexpr bool sign_member_is_reference		= (d == SignDenotation::reference);

	template<SignDenotation d>
	static constexpr bool sign_member_is_dereference	= (d == SignDenotation::dereference);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// attribute filters (level 1):

/***********************************************************************************************************************/

	template<SignMutability Mutate, SignDenotation Denote>
	struct _sign_attributes
	{
		static constexpr SignMutability mutate = Mutate;
		static constexpr SignDenotation denote = Denote;
	};

	//

	using sign_attr_ref		= _sign_attributes < SignMutability::variable  , SignDenotation::reference   >;
	using sign_attr_deref		= _sign_attributes < SignMutability::variable  , SignDenotation::dereference >;
	using sign_attr_cref		= _sign_attributes < SignMutability::immutable , SignDenotation::reference   >;
	using sign_attr_cderef		= _sign_attributes < SignMutability::immutable , SignDenotation::dereference >;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// argument filters (level 2):

/***********************************************************************************************************************/

	template<SignMember Member, typename Attr>
	struct _sign_argument
	{
		static constexpr auto member	= Member;
		using attributes		= Attr;
	};

	//

	template<SignMember Member> using sign_arg_ref		= _sign_argument < Member , sign_attr_ref    >;
	template<SignMember Member> using sign_arg_deref	= _sign_argument < Member , sign_attr_deref  >;
	template<SignMember Member> using sign_arg_cref		= _sign_argument < Member , sign_attr_cref   >;
	template<SignMember Member> using sign_arg_cderef	= _sign_argument < Member , sign_attr_cderef >;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// facade filters (level 3):

/***********************************************************************************************************************/

	template<typename... Args>
	using _sign_arg_facade = typename functor_module::template typename_pack<Args...>;

	template<auto... Members>
	using _sign_member_facade = typename functor_module::template auto_pack<Members...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatchers:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// resolve member:

/***********************************************************************************************************************/

private:

	// members 0-5:

		NIK_DEFINE_F_RESOLVE_MEMBER(0)
		NIK_DEFINE_F_RESOLVE_MEMBER(1)
		NIK_DEFINE_F_RESOLVE_MEMBER(2)
		NIK_DEFINE_F_RESOLVE_MEMBER(3)
		NIK_DEFINE_F_RESOLVE_MEMBER(4)
		NIK_DEFINE_F_RESOLVE_MEMBER(5)

public:

	// members 0-5:

		NIK_DEFINE_RESOLVE_MEMBER(0)
		NIK_DEFINE_RESOLVE_MEMBER(1)
		NIK_DEFINE_RESOLVE_MEMBER(2)
		NIK_DEFINE_RESOLVE_MEMBER(3)
		NIK_DEFINE_RESOLVE_MEMBER(4)
		NIK_DEFINE_RESOLVE_MEMBER(5)

/***********************************************************************************************************************/

private:

	template<typename Signature, typename Arg>
	static constexpr auto f_resolve_member()
	{
		constexpr auto member	= Arg::member;
		using attributes	= typename Arg::attributes;

		if constexpr      (is_sign_member_0<member>) return resolve_member_0<Signature, attributes>;
		else if constexpr (is_sign_member_1<member>) return resolve_member_1<Signature, attributes>;
		else if constexpr (is_sign_member_2<member>) return resolve_member_2<Signature, attributes>;
		else if constexpr (is_sign_member_3<member>) return resolve_member_3<Signature, attributes>;
		else if constexpr (is_sign_member_4<member>) return resolve_member_4<Signature, attributes>;
		else                                         return resolve_member_5<Signature, attributes>;
	}

public:

	template<typename Signature, typename Arg>
	static constexpr auto resolve_member = f_resolve_member<Signature, Arg>();

/***********************************************************************************************************************/

private:

	template<typename Signature, typename... Args>
	static constexpr auto f_resolve_facade(void(*)(_sign_arg_facade<Args...>*))
	{
		return functor_module::template U_type_T
		<
			_sign_member_facade<resolve_member<Signature, Args>...>
		>;
	}

public:

	template<typename Signature, typename Facade>
	static constexpr auto resolve_facade = f_resolve_facade<Signature>(functor_module::template U_type_T<Facade>);

/***********************************************************************************************************************/

private:

	template<auto... Members>
	static constexpr auto f_resolve_out_types(void(*)(_sign_member_facade<Members...>*))
	{
		return functor_module::template U_pack_Vs<out_type<Members>...>;
	}

public:

	template<auto UMem>
	static constexpr auto resolve_out_types = f_resolve_out_types(functor_module::template U_type_T<UMem>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

