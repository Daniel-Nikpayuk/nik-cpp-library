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

// dependencies:

	#include nik_source(../../.., interpret, store, architect, v_0_5, gcc)

// constant source:

namespace nik { nik_begin_module(interpret, constant, architect, NIK_VERSION, NIK_VENDOR)

	using store_module = nik_module(interpret, store, architect, v_0_5, gcc);

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

private:

	template<typename T>				// This works because as a variable template it has
	nik_ces bool is_constant = false;	// a partial specialize defined outside of this module.

public:

	template<typename T>
	nik_ces bool V_is_constant_T = is_constant<T>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specifiers:

public:

	enum struct Constant
	{
		to_const,
		from_const,

		dimension // filler
	};

	//

	template<Constant c> nik_ces bool is_to_const		= (c == Constant::to_const);
	template<Constant c> nik_ces bool is_from_const	= (c == Constant::from_const);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// modify:

private:

	template<typename, Constant> struct modify;

	template<typename T>
	struct modify<T, Constant::to_const>
	{
		using type	= T const;
	};

	template<typename T>
	struct modify<T const, Constant::to_const>
	{
		using type	= T const;
	};

	template<typename T>
	struct modify<T, Constant::from_const>
	{
		using type	= T;
	};

	template<typename T>
	struct modify<T const, Constant::from_const>
	{
		using type	= T;
	};

public:

	template<typename T, Constant c>
	using T_const_modify_TxV = typename modify<T, c>::type;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// builtin types:

	nik_ces auto U_void			= store_module::template U_store_T<void>;
	nik_ces auto U_char			= store_module::template U_store_T<char>;
	nik_ces auto U_char_ptr			= store_module::template U_store_T<char*>;

	nik_ces auto U_unsigned_char		= store_module::template U_store_T<unsigned char>;
	nik_ces auto U_signed_char		= store_module::template U_store_T<signed char>;

	nik_ces auto U_unsigned_short		= store_module::template U_store_T<unsigned short>;
	nik_ces auto U_signed_short		= store_module::template U_store_T<signed short>;

	nik_ces auto U_unsigned_int		= store_module::template U_store_T<unsigned int>;
	nik_ces auto U_signed_int		= store_module::template U_store_T<signed int>;

	nik_ces auto U_unsigned_long		= store_module::template U_store_T<unsigned long>;
	nik_ces auto U_signed_long		= store_module::template U_store_T<signed long>;

	nik_ces auto U_unsigned_long_long	= store_module::template U_store_T<unsigned long long>;
	nik_ces auto U_signed_long_long		= store_module::template U_store_T<signed long long>;

/***********************************************************************************************************************/

// pack types:

	nik_ces auto U_null_Ts			= store_module::template U_pack_Ts<>;
	nik_ces auto U_null_Vs			= store_module::template U_pack_Vs<>;
	nik_ces auto U_null_As			= store_module::template U_pack_As<>;
	nik_ces auto U_null_Bs			= store_module::template U_pack_Bs<>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

nik_end_module(interpret, generic, architect, NIK_VERSION, NIK_VENDOR)

// variable template specializations:

	// is constant:

		template<typename T>
		constexpr bool nik_module(interpret, constant, architect, v_0_5, gcc)::is_constant<T const> = true;

	template<typename Op, nik_vp(*pack)(Op*), auto... Vs>
	constexpr auto NIK_MODULE::apply<pack, Vs...> = Op::template result<Vs...>;
}

