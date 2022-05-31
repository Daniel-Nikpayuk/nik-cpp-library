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

namespace nik { nik_begin_module(interpret, reference, architect, NIK_VERSION, NIK_VENDOR)

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

	struct ReferenceKey
	{
		nik_ces key_type id			=  0;

		nik_ces key_type to_reference		=  1;
		nik_ces key_type from_reference		=  2;

		nik_ces key_type is_reference		=  3;

		nik_ces key_type dimension		=  4;
	};

/***********************************************************************************************************************/

// apply:

private:

	template<key_type Key>
	nik_ces void apply_assert()
	{
		constexpr bool is_key = (Key < ReferenceKey::dimension); // assumes key_type is unsigned.

		static_assert(is_key, "This store key has not been implemented.");
	}

public:

	struct ReferenceApply
	{
		template<key_type Key, auto... Vs>
		nik_ces auto result = apply_assert<Key>();
	};

	nik_ces auto U_ReferenceApply = store_module::template U_store_T<ReferenceApply>;

	template<auto... Vs>
	nik_ces auto reference_apply = generic_module::template apply<U_ReferenceApply, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

nik_end_module(interpret, reference, architect, NIK_VERSION, NIK_VENDOR)

// variable template specializations:

// apply:

	#define NIK_REFERENCE_APPLY NIK_MODULE::ReferenceApply::result
	#define NIK_REFERENCE_KEY NIK_MODULE::ReferenceKey

	// to reference:

		template<typename T, nik_vp(p)(T*)>
		nik_ce auto NIK_REFERENCE_APPLY<NIK_REFERENCE_KEY::to_reference, p> = NIK_STORE_MODULE::template U_store_T<T&>;

		template<typename T, nik_vp(p)(T&)>
		nik_ce auto NIK_REFERENCE_APPLY<NIK_REFERENCE_KEY::to_reference, p> = p;

	// from reference:

		template<typename T, nik_vp(p)(T*)>
		nik_ce auto NIK_REFERENCE_APPLY<NIK_REFERENCE_KEY::from_reference, p> = p;

		template<typename T, nik_vp(p)(T&)>
		nik_ce auto NIK_REFERENCE_APPLY<NIK_REFERENCE_KEY::from_reference, p> = NIK_STORE_MODULE::template U_store_T<T*>;

	// is reference:

		template<auto V>
		nik_ce auto NIK_REFERENCE_APPLY<NIK_REFERENCE_KEY::is_reference, V> = false;

		template<typename T, nik_vp(p)(T&const)>
		nik_ce auto NIK_REFERENCE_APPLY<NIK_REFERENCE_KEY::is_reference, p> = true;

	#undef NIK_REFERENCE_KEY
	#undef NIK_REFERENCE_APPLY
}

