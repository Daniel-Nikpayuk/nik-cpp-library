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

namespace nik { nik_begin_module(interpret, boolean, architect, NIK_VERSION, NIK_VENDOR)

public:

	using generic_module	= typename NIK_STORE_MODULE::generic_module;
	using store_module	= NIK_STORE_MODULE;
	using key_type		= typename NIK_STORE_MODULE::key_type;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// generic:

/***********************************************************************************************************************/

// keys:

	struct BooleanKey
	{
		nik_ces key_type id			=  0;

		nik_ces key_type if_then_else		=  1;

		nik_ces key_type dimension		=  2;
	};

/***********************************************************************************************************************/

// apply:

private:

	template<key_type Key>
	nik_ces void apply_assert()
	{
		constexpr bool is_key = (Key < BooleanKey::dimension); // assumes key_type is unsigned.

		static_assert(is_key, "This store key has not been implemented.");
	}

public:

	struct BooleanApply
	{
		template<key_type Key, auto... Vs>
		nik_ces auto result = apply_assert<Key>();
	};

	nik_ces auto U_BooleanApply = store_module::template U_store_T<BooleanApply>;

	template<auto... Vs>
	nik_ces auto boolean_apply = generic_module::template apply<U_BooleanApply, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

nik_end_module(interpret, boolean, architect, NIK_VERSION, NIK_VENDOR)

// variable template specializations:

// apply:

	#define NIK_BOOLEAN_APPLY NIK_MODULE::BooleanApply::result
	#define NIK_BOOLEAN_KEY NIK_MODULE::BooleanKey

		template<auto ante, auto conse>
		nik_ce auto NIK_BOOLEAN_APPLY<NIK_BOOLEAN_KEY::if_then_else, true, ante, conse> = ante;

		template<auto ante, auto conse>
		nik_ce auto NIK_BOOLEAN_APPLY<NIK_BOOLEAN_KEY::if_then_else, false, ante, conse> = conse;

	#undef NIK_BOOLEAN_KEY
	#undef NIK_BOOLEAN_APPLY
}

