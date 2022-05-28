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

//	#include nik_source(../../.., interpret, store, architect, v_0_5, gcc)

// array source:

namespace nik { nik_begin_module(interpret, generic, architect, NIK_VERSION, NIK_VENDOR)

//	#include nik_import(../../.., interpret, store, architect, v_0_5, gcc, static, name)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

// is array:

private:

	template<typename T>				// This works because as a variable template it has
	nik_ces bool is_array = false;		// a partial specialize defined outside of this module.

public:

	template<typename T>
	nik_ces bool V_is_array_T = is_array<T>;

/***********************************************************************************************************************/

// size:

private:

//	template<typename T>				// This works because as a variable template it has
//	nik_ces bool array_size = 0;		// a partial specialize defined outside of this module.

public:

//	template<typename T>
//	nik_ces bool V_array_size_T = array_size<T>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specifiers:

public:

//	enum struct Array
//	{
//		to_array,
//		from_array,

//		dimension // filler
//	};

	//

//	template<Array r> nik_ces bool is_to_array		= (r == Array::to_array);
//	template<Array r> nik_ces bool is_from_array		= (r == Array::from_array);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// modify:

private:

//	template<typename, Array, global_size_type...> struct modify;

//	template<typename T, global_size_type N>
//	struct modify<T, Array::to_array>
//	{
//		using type	= T(*)[N];
//	};

//	template<typename T, global_size_type N>
//	struct modify<T(*)[N], Array::to_array, N>
//	{
//		using type	= T(*)[N];
//	};

//	template<typename T>
//	struct modify<T, Array::from_array>
//	{
//		using type	= T;
//	};

//	template<typename T, global_size_type N>
//	struct modify<T(*)[N], Array::from_array, N>
//	{
//		using type	= T;
//	};

public:

//	template<typename T, Array r, global_size_type... Ns>
//	using T_array_modify_TxV = typename modify<T, r, Ns...>::type;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// (variable) array:

public:

	template<typename Type, Type... Vs>
	nik_ces Type array[] = { Vs... };

	// U -> V:

		template<typename Type, auto... Vs>
		nik_ces auto V_array_U(nik_avpcr(auto_pack<Vs...>*))
			{ return array<Type, Vs...>; }

	// V -> U:

		template<auto Arr, auto... Is>
		nik_ces auto U_array_V(nik_avpcr(auto_pack<Is...>*))
			{ return U_pack_Vs<Arr[Is]...>; }

/***********************************************************************************************************************/

// copy:

	struct Copy
	{
		template<typename OutIter, typename InIter, typename EndIter>
		nik_ces void result(OutIter out, InIter in, EndIter end)
			{ while (in != end) *(out++) = *(in++); }
	};

/***********************************************************************************************************************/

// sequence:

	struct Sequence
	{
		template<auto f, typename OutIter, typename InIter, typename EndIter>
		nik_ces void result(OutIter out, InIter in, EndIter end)
			{ while (in != end) *(out++) = f(in++); }
	};

/***********************************************************************************************************************/

// map:

	struct Map
	{
		template<auto f, typename OutIter, typename InIter, typename EndIter>
		nik_ces void result(OutIter out, InIter in, EndIter end)
			{ while (in != end) *(out++) = f(*(in++)); }
	};

/***********************************************************************************************************************/

// fold:

	struct Fold
	{
		template<auto f, auto init, typename OutIter, typename InIter, typename EndIter>
		nik_ces void result(OutIter out, InIter in, EndIter end)
		{
			*out = init;

			while (in != end) *out = f(*out, *(in++));
		}
	};

/***********************************************************************************************************************/

// find:

	struct Find
	{
		template<auto Size, auto p, typename OutIter, typename InIter, typename EndIter>
		nik_ces void result(OutIter out, InIter in, EndIter end)
		{
			*out = Size;
			InIter in0 = in;

			while ((*out == Size) && (in != end)) if (p(*in)) *out = (in++) - in0;
		}
	};

/***********************************************************************************************************************/

// sift:

	struct Sift
	{
		template<auto p, typename OutIter, typename InIter, typename EndIter>
		nik_ces void result(OutIter out, InIter in, EndIter end)
		{
			OutIter out0 = out++;
			InIter   in0 = in;

			while (in != end) if (p(*in)) *(out++) = (in++) - in0;

			*out0 = out - out0;
		}
	};

/***********************************************************************************************************************/

// (deducible) sift:

/***********************************************************************************************************************/

// zip:

	struct Zip
	{
		template<auto f, typename OutIter, typename In1Iter, typename End1Iter, typename In2Iter>
		nik_ces void result(OutIter out, In1Iter in1, End1Iter end1, In2Iter in2)
			{ while (in1 != end1) *(out++) = f(*(in1++), *(in2++)); }
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// (struct) array:

public:

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

nik_end_module(interpret, generic, architect, NIK_VERSION, NIK_VENDOR)

// variable template specializations:

	// is array:

		template<typename T, global_size_type N>
		constexpr bool nik_module(interpret, array, architect, v_0_5, gcc)::is_array<T(*)[N]> = true;

	template<typename Op, nik_vp(*pack)(Op*), auto... Vs>
	constexpr auto NIK_MODULE::apply<pack, Vs...> = Op::template result<Vs...>;
}

