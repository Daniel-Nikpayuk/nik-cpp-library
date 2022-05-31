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

// source:

namespace nik { nik_begin_module(interpret, constant, architect, NIK_VERSION, NIK_VENDOR)

public:

	using generic_module	= typename NIK_STORE_MODULE::generic_module;
	using store_module	= NIK_STORE_MODULE;
	using key_type		= typename NIK_STORE_MODULE::key_type;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// constant types:

/***********************************************************************************************************************/

// builtin:

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

// pack:

	nik_ces auto U_null_Ts			= store_module::template U_pack_Ts<>;
	nik_ces auto U_null_Vs			= store_module::template U_pack_Vs<>;
	nik_ces auto U_null_As			= store_module::template U_pack_As<>;
	nik_ces auto U_null_Bs			= store_module::template U_pack_Bs<>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// generic:

/***********************************************************************************************************************/

// keys:

	struct ConstantKey
	{
		nik_ces key_type id					=  0;

		nik_ces key_type to_const				=  1;
		nik_ces key_type from_const				=  2;

		nik_ces key_type is_const				=  3;

		nik_ces key_type dimension				=  4;
	};

/***********************************************************************************************************************/

// apply:

private:

	template<key_type Key>
	nik_ces void apply_assert()
	{
		constexpr bool is_key = (Key < ConstantKey::dimension); // assumes key_type is unsigned.

		static_assert(is_key, "This store key has not been implemented.");
	}

public:

	struct ConstantApply
	{
		template<key_type Key, auto... Vs>
		nik_ces auto result = apply_assert<Key>();
	};

	nik_ces auto U_ConstantApply = store_module::template U_store_T<ConstantApply>;

	template<auto... Vs>
	nik_ces auto constant_apply = generic_module::template apply<U_ConstantApply, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

nik_end_module(interpret, constant, architect, NIK_VERSION, NIK_VENDOR)

// variable template specializations:

// apply:

	#define NIK_CONSTANT_APPLY NIK_MODULE::ConstantApply::result
	#define NIK_CONSTANT_KEY NIK_MODULE::ConstantKey

	// to const:

		template<typename T, nik_vp(p)(T*)>
		nik_ce auto NIK_CONSTANT_APPLY<NIK_CONSTANT_KEY::to_const, p> = NIK_STORE_MODULE::template U_store_T<T const>;

		template<typename T, nik_vp(p)(T const*)>
		nik_ce auto NIK_CONSTANT_APPLY<NIK_CONSTANT_KEY::to_const, p> = p;

	// from const:

		template<typename T, nik_vp(p)(T*)>
		nik_ce auto NIK_CONSTANT_APPLY<NIK_CONSTANT_KEY::from_const, p> = p;

		template<typename T, nik_vp(p)(T const*)>
		nik_ce auto NIK_CONSTANT_APPLY<NIK_CONSTANT_KEY::from_const, p> = NIK_STORE_MODULE::template U_store_T<T>;

	// is const:

		template<auto V>
		nik_ce auto NIK_CONSTANT_APPLY<NIK_CONSTANT_KEY::is_const, V> = false;

		template<typename T, nik_vp(p)(T const*)>
		nik_ce auto NIK_CONSTANT_APPLY<NIK_CONSTANT_KEY::is_const, p> = true;

	#undef NIK_CONSTANT_KEY
	#undef NIK_CONSTANT_APPLY
}

