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

// define macros source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// member typenames:

	#define NIK_MEMBER_TYPENAMES_1											\
															\
		typename Member0Type

	#define NIK_MEMBER_TYPENAMES_2											\
															\
		NIK_MEMBER_TYPENAMES_1, typename Member1Type

	#define NIK_MEMBER_TYPENAMES_3											\
															\
		NIK_MEMBER_TYPENAMES_2, typename Member2Type

	#define NIK_MEMBER_TYPENAMES_4											\
															\
		NIK_MEMBER_TYPENAMES_3, typename Member3Type

	#define NIK_MEMBER_TYPENAMES_5											\
															\
		NIK_MEMBER_TYPENAMES_4, typename Member4Type

	#define NIK_MEMBER_TYPENAMES_6											\
															\
		NIK_MEMBER_TYPENAMES_5, typename Member5Type

/***********************************************************************************************************************/

// member types:

	#define NIK_MEMBER_TYPES_1											\
															\
		Member0Type

	#define NIK_MEMBER_TYPES_2											\
															\
		NIK_MEMBER_TYPES_1, Member1Type

	#define NIK_MEMBER_TYPES_3											\
															\
		NIK_MEMBER_TYPES_2, Member2Type

	#define NIK_MEMBER_TYPES_4											\
															\
		NIK_MEMBER_TYPES_3, Member3Type

	#define NIK_MEMBER_TYPES_5											\
															\
		NIK_MEMBER_TYPES_4, Member4Type

	#define NIK_MEMBER_TYPES_6											\
															\
		NIK_MEMBER_TYPES_5, Member5Type

/***********************************************************************************************************************/

// member declarations:

	#define NIK_MEMBER_DECLARATIONS_1										\
															\
		Member0Type member_0;

	#define NIK_MEMBER_DECLARATIONS_2										\
															\
		NIK_MEMBER_DECLARATIONS_1										\
		Member1Type member_1;

	#define NIK_MEMBER_DECLARATIONS_3										\
															\
		NIK_MEMBER_DECLARATIONS_2										\
		Member2Type member_2;

	#define NIK_MEMBER_DECLARATIONS_4										\
															\
		NIK_MEMBER_DECLARATIONS_3										\
		Member3Type member_3;

	#define NIK_MEMBER_DECLARATIONS_5										\
															\
		NIK_MEMBER_DECLARATIONS_4										\
		Member4Type member_4;

	#define NIK_MEMBER_DECLARATIONS_6										\
															\
		NIK_MEMBER_DECLARATIONS_5										\
		Member5Type member_5;

/***********************************************************************************************************************/

// member arguments:

	#define NIK_MEMBER_ARGUMENTS_1											\
															\
		const Member0Type & m0

	#define NIK_MEMBER_ARGUMENTS_2											\
															\
		NIK_MEMBER_ARGUMENTS_1,											\
		const Member1Type & m1

	#define NIK_MEMBER_ARGUMENTS_3											\
															\
		NIK_MEMBER_ARGUMENTS_2,											\
		const Member2Type & m2

	#define NIK_MEMBER_ARGUMENTS_4											\
															\
		NIK_MEMBER_ARGUMENTS_3,											\
		const Member3Type & m3

	#define NIK_MEMBER_ARGUMENTS_5											\
															\
		NIK_MEMBER_ARGUMENTS_4,											\
		const Member4Type & m4

	#define NIK_MEMBER_ARGUMENTS_6											\
															\
		NIK_MEMBER_ARGUMENTS_5,											\
		const Member5Type & m5

/***********************************************************************************************************************/

// member instantiations:

	#define NIK_MEMBER_INSTANTIATIONS_1										\
															\
		member_0(m0)

	#define NIK_MEMBER_INSTANTIATIONS_2										\
															\
		NIK_MEMBER_INSTANTIATIONS_1,										\
		member_1(m1)

	#define NIK_MEMBER_INSTANTIATIONS_3										\
															\
		NIK_MEMBER_INSTANTIATIONS_2,										\
		member_2(m2)

	#define NIK_MEMBER_INSTANTIATIONS_4										\
															\
		NIK_MEMBER_INSTANTIATIONS_3,										\
		member_3(m3)

	#define NIK_MEMBER_INSTANTIATIONS_5										\
															\
		NIK_MEMBER_INSTANTIATIONS_4,										\
		member_4(m4)

	#define NIK_MEMBER_INSTANTIATIONS_6										\
															\
		NIK_MEMBER_INSTANTIATIONS_5,										\
		member_5(m5)

/***********************************************************************************************************************/

// notes:

	#define NIK_VARIABLE()												\
															\

	#define NIK_IMMUTABLE()												\
															\
		const

	#define NIK_MEMBER_VARIABLE(_num_)										\
															\
		member_ ## _num_ ## _ref

	#define NIK_MEMBER_IMMUTABLE(_num_)										\
															\
		member_ ## _num_ ## _cref

/***********************************************************************************************************************/

// member friends:

	#define NIK_MEMBER_FRIEND(_size_, _num_, _note_)								\
															\
		friend NIK_ ## _note_() auto & module::NIK_MEMBER_ ## _note_(_num_)					\
		<													\
			NIK_MEMBER_TYPES_ ## _size_									\
		>													\
		(													\
			NIK_ ## _note_() signature<NIK_MEMBER_TYPES_ ## _size_> &					\
		);

// member instantiations:

	#define NIK_MEMBER_FRIENDS_1(_size_)										\
															\
		NIK_MEMBER_FRIEND(_size_, 0, VARIABLE)									\
		NIK_MEMBER_FRIEND(_size_, 0, IMMUTABLE)									\

	#define NIK_MEMBER_FRIENDS_2(_size_)										\
															\
		NIK_MEMBER_FRIENDS_1(_size_)										\
															\
		NIK_MEMBER_FRIEND(_size_, 1, VARIABLE)									\
		NIK_MEMBER_FRIEND(_size_, 1, IMMUTABLE)									\

	#define NIK_MEMBER_FRIENDS_3(_size_)										\
															\
		NIK_MEMBER_FRIENDS_2(_size_)										\
															\
		NIK_MEMBER_FRIEND(_size_, 2, VARIABLE)									\
		NIK_MEMBER_FRIEND(_size_, 2, IMMUTABLE)									\

	#define NIK_MEMBER_FRIENDS_4(_size_)										\
															\
		NIK_MEMBER_FRIENDS_3(_size_)										\
															\
		NIK_MEMBER_FRIEND(_size_, 3, VARIABLE)									\
		NIK_MEMBER_FRIEND(_size_, 3, IMMUTABLE)									\

	#define NIK_MEMBER_FRIENDS_5(_size_)										\
															\
		NIK_MEMBER_FRIENDS_4(_size_)										\
															\
		NIK_MEMBER_FRIEND(_size_, 4, VARIABLE)									\
		NIK_MEMBER_FRIEND(_size_, 4, IMMUTABLE)									\

	#define NIK_MEMBER_FRIENDS_6(_size_)										\
															\
		NIK_MEMBER_FRIENDS_5(_size_)										\
															\
		NIK_MEMBER_FRIEND(_size_, 5, VARIABLE)									\
		NIK_MEMBER_FRIEND(_size_, 5, IMMUTABLE)									\

/***********************************************************************************************************************/

// signatures:

	#define NIK_DEFINE_SIGNATURE(_size_)										\
															\
		template<NIK_MEMBER_TYPENAMES_ ## _size_>								\
		class signature<NIK_MEMBER_TYPES_ ## _size_>								\
		{													\
			NIK_MEMBER_DECLARATIONS_ ## _size_								\
															\
			public:												\
															\
				constexpr signature(NIK_MEMBER_ARGUMENTS_ ## _size_) :					\
					NIK_MEMBER_INSTANTIATIONS_ ## _size_ { }					\
															\
			/* friendship: */										\
															\
				NIK_MEMBER_FRIENDS_ ## _size_(_size_)							\
		};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// accessor macros:

/***********************************************************************************************************************/

// accessors:

	#define NIK_MEMBER_ACCESSOR(_num_, _note_)									\
															\
		template<typename... Ts>										\
		static constexpr NIK_ ## _note_() auto & NIK_MEMBER_ ## _note_(_num_)					\
			(NIK_ ## _note_() signature<Ts...> & s)								\
				{ return s.member_ ## _num_; }

	#define NIK_DEFINE_ACCESSORS(_num_)										\
															\
		NIK_MEMBER_ACCESSOR(_num_, VARIABLE)									\
		NIK_MEMBER_ACCESSOR(_num_, IMMUTABLE)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// resolve member macros:

/***********************************************************************************************************************/

	#define NIK_DEFINE_F_RESOLVE_MEMBER(_num_)									\
															\
		template<typename Arg, typename... Ts>									\
		static constexpr auto f_resolve_member_ ## _num_(void(*)(signature<Ts...>))				\
		{													\
			using attr		= typename Arg::attributes;						\
															\
			constexpr auto mutate	= attr::mutate;								\
			constexpr auto denote	= attr::denote;								\
															\
			if constexpr (sign_is_immutable<mutate>)							\
			{												\
				constexpr auto member = member_ ## _num_ ## _cref<Ts...>;				\
															\
				if constexpr (sign_member_is_reference<denote>) return member;				\
				else return do_compose<member, cdereference<out_type<member>>>;				\
			}												\
			else												\
			{												\
				constexpr auto member = member_ ## _num_ ## _ref<Ts...>;				\
															\
				if constexpr (sign_member_is_reference<denote>) return member;				\
				else return do_compose<member, dereference<out_type<member>>>;				\
			}												\
		}

	#define NIK_DEFINE_RESOLVE_MEMBER(_num_)									\
															\
		template<typename Sign, typename Arg>									\
		static constexpr auto resolve_member_ ## _num_ = f_resolve_member_ ## _num_<Arg>			\
			(functor_module::template U_type_T<Sign>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

