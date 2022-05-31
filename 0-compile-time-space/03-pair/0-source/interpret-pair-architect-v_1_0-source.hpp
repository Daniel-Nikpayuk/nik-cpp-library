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

namespace nik { nik_begin_module(interpret, pair, architect, NIK_VERSION, NIK_VENDOR)

public:

	using generic_module	= typename NIK_STORE_MODULE::generic_module;
	using store_module	= NIK_STORE_MODULE;
	using key_type		= typename NIK_STORE_MODULE::key_type;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

public:

	template<typename T1, typename T2>
	struct pair
	{
		T1 v1;
		T2 v2;

		constexpr pair(const T1 & _v1, const T2 & _v2) : v1(_v1), v2(_v2) { }
	};

	// C++17:

	template<auto v1, auto v2>
	nik_ces pair<decltype(v1), decltype(v2)> ce_pair() { return pair(v1, v2); }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// generic:

/***********************************************************************************************************************/

// keys:

	struct PairKey
	{
			nik_ces key_type id			=  0;

		// typename:

			nik_ces key_type cons			=  1;
			nik_ces key_type car			=  2;
			nik_ces key_type cdr			=  3;

			nik_ces key_type is_pair		=  4;

		// constexpr

			nik_ces key_type ce_cons		=  5;
			nik_ces key_type ce_car			=  6;
			nik_ces key_type ce_cdr			=  7;

			nik_ces key_type is_ce_pair		=  8;

			nik_ces key_type dimension		=  9;
	};

/***********************************************************************************************************************/

// apply:

private:

	template<key_type Key>
	nik_ces void apply_assert()
	{
		constexpr bool is_key = (Key < PairKey::dimension); // assumes key_type is unsigned.

		static_assert(is_key, "This store key has not been implemented.");
	}

public:

	struct PairApply
	{
		template<key_type Key, auto... Vs>
		nik_ces auto result = apply_assert<Key>();
	};

	nik_ces auto U_PairApply = store_module::template U_store_T<PairApply>;

	template<auto... Vs>
	nik_ces auto pair_apply = generic_module::template apply<U_PairApply, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

nik_end_module(interpret, pair, architect, NIK_VERSION, NIK_VENDOR)

// variable template specializations:

// apply:

	#define NIK_PAIR_APPLY NIK_MODULE::PairApply::result
	#define NIK_PAIR_KEY NIK_MODULE::PairKey

	// typename:

		template<typename T1, nik_vp(p1)(T1*), typename T2, nik_vp(p2)(T2*)>
		nik_ce auto NIK_PAIR_APPLY<NIK_PAIR_KEY::cons, p1, p2> = NIK_STORE_MODULE::template U_store_T
		<
			NIK_MODULE::template pair<T1, T2>
		>;

		template<typename T1, typename T2, nik_vp(p)(NIK_MODULE::pair<T1, T2>*)>
		nik_ce auto NIK_PAIR_APPLY<NIK_PAIR_KEY::car, p> = NIK_STORE_MODULE::template U_store_T<T1>;

		template<typename T1, typename T2, nik_vp(p)(NIK_MODULE::pair<T1, T2>*)>
		nik_ce auto NIK_PAIR_APPLY<NIK_PAIR_KEY::cdr, p> = NIK_STORE_MODULE::template U_store_T<T2>;

		//

		template<auto V>
		nik_ce auto NIK_PAIR_APPLY<NIK_PAIR_KEY::is_pair, V> = false;

		template<typename T1, typename T2, nik_vp(p)(NIK_MODULE::pair<T1, T2>*)>
		nik_ce auto NIK_PAIR_APPLY<NIK_PAIR_KEY::is_pair, p> = true;

	// constexpr:

		template<auto V1, auto V2>
		nik_ce auto NIK_PAIR_APPLY<NIK_PAIR_KEY::ce_cons, V1, V2> = NIK_MODULE::template ce_pair<V1, V2>;

		template<typename T1, typename T2, NIK_MODULE::pair<T1, T2>(*p)()>
		nik_ce auto NIK_PAIR_APPLY<NIK_PAIR_KEY::ce_car, p> = p().v1;

		template<typename T1, typename T2, NIK_MODULE::pair<T1, T2>(*p)()>
		nik_ce auto NIK_PAIR_APPLY<NIK_PAIR_KEY::ce_cdr, p> = p().v2;

		//

		template<auto V>
		nik_ce auto NIK_PAIR_APPLY<NIK_PAIR_KEY::is_ce_pair, V> = false;

		template<typename T1, typename T2, NIK_MODULE::pair<T1, T2>(*const p)()>
		nik_ce auto NIK_PAIR_APPLY<NIK_PAIR_KEY::is_ce_pair, p> = true;

		template<typename T1, typename T2, const NIK_MODULE::pair<T1, T2>(*const p)()>
		nik_ce auto NIK_PAIR_APPLY<NIK_PAIR_KEY::is_ce_pair, p> = true;

	#undef NIK_PAIR_KEY
	#undef NIK_PAIR_APPLY
}

