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

namespace nik { nik_begin_module(interpret, array, architect, NIK_VERSION, NIK_VENDOR)

public:

	using generic_module	= typename NIK_STORE_MODULE::generic_module;
	using store_module	= NIK_STORE_MODULE;
	using key_type		= typename NIK_STORE_MODULE::key_type;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// constexpr array:

	template<typename Type, auto Size>
	struct Array { Type value[Size]; };

/***********************************************************************************************************************/

// type:

	template<typename Type, auto Size>
	nik_ces auto type(const Array<Type, Size> &) { return U_store_T<Type>; }

// size:

	template<typename Type, auto Size>
	nik_ces auto size(const Array<Type, Size> &) { return Size; }

// begin:

	template<typename Type, auto Size>
	nik_ces auto begin(Array<Type, Size> & arr) { return arr.value; }

// end:

	template<typename Type, auto Size>
	nik_ces auto end(Array<Type, Size> & arr) { return arr.value + Size; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// (near linear) apply:

	template
	<
		typename Type, auto Size,
		typename F, auto InSize, auto... Params,
		typename InType, typename... InTypes
	>
	nik_ces auto apply(InType in, InTypes... ins)
	{
		Array<Type, Size> arr{};

		F::template result<Params...>(begin(arr), in, in + InSize, ins...);

		return arr;
	}

	// -> V:

		template<typename Type, typename F, auto... As, auto... Ps, auto... Is>
		nik_ces auto V_apply(nik_avpcr(auto_pack<Ps...>*), nik_avpcr(auto_pack<Is...>*))
		{
			constexpr auto Size	= sizeof...(Is);
			constexpr auto arr	= apply<Type, Size, F, Ps...>(As...);

			return array<Type, arr.value[Is]...>;
		}

	// -> U:

		template<typename Type, typename F, auto... As, auto... Ps, auto... Is>
		nik_ces auto U_apply(nik_avpcr(auto_pack<Ps...>*), nik_avpcr(auto_pack<Is...>*))
		{
			constexpr auto Size	= sizeof...(Is);
			constexpr auto arr	= apply<Type, Size, F, Ps...>(As...);

			return U_pack_Vs<arr.value[Is]...>;
		}

/***********************************************************************************************************************/

// sequence:

	// -> V:

		template<typename Type, auto f, auto Leng, typename Indices>
		nik_ces auto V_sequence(Indices indices)
			{ return V_apply<Type, Sequence, decltype(Leng){0}>(U_pack_Vs<Leng, f>, indices); }

	// -> U:

		template<typename Type, auto f, auto Leng, typename Indices>
		nik_ces auto U_sequence(Indices indices)
			{ return U_apply<Type, Sequence, decltype(Leng){0}>(U_pack_Vs<Leng, f>, indices); }

/***********************************************************************************************************************/

// map:

	// -> V:

		template<typename Type, auto f, auto Arr, auto Leng, typename Indices>
		nik_ces auto V_map(Indices indices)
			{ return V_apply<Type, Map, Arr>(U_pack_Vs<Leng, f>, indices); }

	// -> U:

		template<typename Type, auto f, auto Arr, auto Leng, typename Indices>
		nik_ces auto U_map(Indices indices)
			{ return U_apply<Type, Map, Arr>(U_pack_Vs<Leng, f>, indices); }

/***********************************************************************************************************************/

// fold:

	// -> V:

		template<typename Type, auto f, auto init, auto Arr, auto Leng>
		nik_ces auto V_fold()
			{ return V_apply<Type, Fold, Arr>(U_pack_Vs<Leng, f, init>, U_pack_Vs<0>); }

	// -> U:

		template<typename Type, auto f, auto init, auto Arr, auto Leng>
		nik_ces auto U_fold()
			{ return U_apply<Type, Fold, Arr>(U_pack_Vs<Leng, f, init>, U_pack_Vs<0>); }

/***********************************************************************************************************************/

// find:

	// -> V:

		template<typename Type, auto p, auto Arr, auto Leng>
		nik_ces auto V_find()
			{ return V_apply<Type, Find, Arr>(U_pack_Vs<Leng, Leng, p>, U_pack_Vs<0>); }

	// -> U:

		template<typename Type, auto p, auto Arr, auto Leng>
		nik_ces auto U_find()
			{ return U_apply<Type, Find, Arr>(U_pack_Vs<Leng, Leng, p>, U_pack_Vs<0>); }

/***********************************************************************************************************************/

// sift:

		template<typename Type, auto p, auto Arr, auto Leng, auto... Is>
		nik_ces auto sift(nik_vpcr(indices)(auto_pack<Is...>*))
		{
			constexpr auto Size	= Leng + 1;
			constexpr auto arr	= apply<Type, Size, Sift, Leng, p>(Arr);
			constexpr auto leng	= arr.value[Leng];

			if constexpr (leng != sizeof...(Is)) return arr;
			else return array<Type, arr.value[Is]...>;
		}

	// -> V:

		template<typename Type, auto p, auto Arr, auto Leng, auto... Is>
		nik_ces auto V_sift(nik_vpcr(indices)(auto_pack<Is...>*))
		{
			constexpr auto Size	= Leng + 1;
			constexpr auto arr	= apply<Type, Size, Sift, Leng, p>(Arr);
			constexpr auto leng	= arr.value[Leng];

			if constexpr (leng != sizeof...(Is)) return arr;
			else return array<Type, arr.value[Is]...>;
		}

/*
		template<typename Type, auto p, auto Arr, auto Leng, auto I0, auto... Is>
		nik_ces auto V_sift(nik_vpcr(indices)(auto_pack<I0, Is...>*))
		{
			constexpr auto Size	= sizeof...(Is) + 1;
			constexpr auto arr	= apply<Type, Size, Sift, Leng, p>(Arr);

			return array<Type, arr.value[Is]...>;
		}
*/

	// -> U:

/*
		template<typename Type, auto p, auto Arr, auto Leng, auto I0, auto... Is>
		nik_ces auto U_sift(nik_vpcr(indices)(auto_pack<I0, Is...>*))
		{
			constexpr auto Size	= sizeof...(Is) + 1;
			constexpr auto arr	= apply<Type, Size, Sift, Leng, p>(Arr);

			return U_pack_Vs<arr.value[Is]...>;
		}
*/

/***********************************************************************************************************************/

// subsequence:

/*
	// -> V:

		template<typename Type, auto p, auto Arr, auto Leng, auto... Is>
		nik_ces auto V_subsequence(nik_vpcr(indices)(auto_pack<Is...>*))
			{ return V_apply<Type, Sift, Arr>(U_pack_Vs<Leng, sizeof...(Is), p>, indices); }

	// -> U:

		template<typename Type, auto p, auto Arr, auto Leng, auto... Is>
		nik_ces auto U_subsequence(nik_vpcr(indices)(auto_pack<Is...>*))
			{ return U_apply<Type, Sift, Arr>(U_pack_Vs<Leng, sizeof...(Is), p>, indices); }
*/

/***********************************************************************************************************************/

// zip:

	// -> V:

		template<typename Type, auto f, auto Arr1, auto Leng1, auto Arr2, typename Indices>
		nik_ces auto V_zip(Indices indices)
			{ return V_apply<Type, Zip, Arr1, Arr2>(U_pack_Vs<Leng1, f>, indices); }

	// -> U:

		template<typename Type, auto f, auto Arr1, auto Leng1, auto Arr2, typename Indices>
		nik_ces auto U_zip(Indices indices)
			{ return U_apply<Type, Zip, Arr1, Arr2>(U_pack_Vs<Leng1, f>, indices); }


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// generic:

/***********************************************************************************************************************/

// keys:

	struct ArrayKey
	{
			nik_ces key_type id			=  0;

		// typename:

			nik_ces key_type cons			=  1;
			nik_ces key_type type			=  2;
			nik_ces key_type size			=  3;

			nik_ces key_type is_array		=  4;

		// constexpr:

			nik_ces key_type ce_cons		=  1;

			nik_ces key_type V_ce_array_U		=  1;
			nik_ces key_type U_ce_array_V		=  1;

			nik_ces key_type dimension		=  5;
	};

/***********************************************************************************************************************/

// apply:

private:

	template<key_type Key>
	nik_ces void apply_assert()
	{
		constexpr bool is_key = (Key < ArrayKey::dimension); // assumes key_type is unsigned.

		static_assert(is_key, "This store key has not been implemented.");
	}

public:

	struct ArrayApply
	{
		template<key_type Key, auto... Vs>
		nik_ces auto result = apply_assert<Key>();
	};

	nik_ces auto U_ArrayApply = store_module::template U_store_T<ArrayApply>;

	template<auto... Vs>
	nik_ces auto array_apply = generic_module::template apply<U_ArrayApply, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

nik_end_module(interpret, array, architect, NIK_VERSION, NIK_VENDOR)

// variable template specializations:

// apply:

	#define NIK_ARRAY_APPLY NIK_MODULE::ArrayApply::result
	#define NIK_ARRAY_KEY NIK_MODULE::ArrayKey

	// to array:

		template<typename T, nik_vp(p)(T(*)[N]*)>
		nik_ce auto NIK_ARRAY_APPLY<NIK_ARRAY_KEY::to_array, p> = NIK_STORE_MODULE::template U_store_T<T&>;

		template<typename T, nik_vp(p)(T&)>
		nik_ce auto NIK_ARRAY_APPLY<NIK_ARRAY_KEY::to_array, p> = p;

	// from array:

		template<typename T, nik_vp(p)(T*)>
		nik_ce auto NIK_ARRAY_APPLY<NIK_ARRAY_KEY::from_array, p> = p;

		template<typename T, nik_vp(p)(T&)>
		nik_ce auto NIK_ARRAY_APPLY<NIK_ARRAY_KEY::from_array, p> = NIK_STORE_MODULE::template U_store_T<T*>;

	// is array:

		template<auto V>
		nik_ce auto NIK_ARRAY_APPLY<NIK_ARRAY_KEY::is_array, V> = false;

		template<typename T, nik_vp(p)(T&)>
		nik_ce auto NIK_ARRAY_APPLY<NIK_ARRAY_KEY::is_array, p> = true;

	#undef NIK_ARRAY_KEY
	#undef NIK_ARRAY_APPLY
}

