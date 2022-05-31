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

namespace nik { nik_begin_module(interpret, pointer, architect, NIK_VERSION, NIK_VENDOR)

public:

	using generic_module	= typename NIK_STORE_MODULE::generic_module;
	using store_module	= NIK_STORE_MODULE;
	using key_type		= typename NIK_STORE_MODULE::key_type;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// constexpr array:

/***********************************************************************************************************************/

	template<typename Type, Type... Vs>
	nik_ces Type ce_array[] = { Vs... };

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

// generic:

/***********************************************************************************************************************/

// keys:

	struct PointerKey
	{
		nik_ces key_type id			=  0;

		nik_ces key_type to_pointer		=  1;
		nik_ces key_type from_pointer		=  2;

		nik_ces key_type is_pointer		=  3;

		nik_ces key_type dimension		=  4;
	};

/***********************************************************************************************************************/

// apply:

private:

	template<key_type Key>
	nik_ces void apply_assert()
	{
		constexpr bool is_key = (Key < PointerKey::dimension); // assumes key_type is unsigned.

		static_assert(is_key, "This store key has not been implemented.");
	}

public:

	struct PointerApply
	{
		template<key_type Key, auto... Vs>
		nik_ces auto result = apply_assert<Key>();
	};

	nik_ces auto U_PointerApply = store_module::template U_store_T<PointerApply>;

	template<auto... Vs>
	nik_ces auto pointer_apply = generic_module::template apply<U_PointerApply, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

nik_end_module(interpret, pointer, architect, NIK_VERSION, NIK_VENDOR)

// variable template specializations:

// apply:

	#define NIK_POINTER_APPLY NIK_MODULE::PointerApply::result
	#define NIK_POINTER_KEY NIK_MODULE::PointerKey

	// to pointer:

		template<typename T, nik_vp(p)(T*)>
		nik_ce auto NIK_POINTER_APPLY<NIK_POINTER_KEY::to_pointer, p> = NIK_STORE_MODULE::template U_store_T<T*>;

		template<typename T, nik_vp(p)(T**)>
		nik_ce auto NIK_POINTER_APPLY<NIK_POINTER_KEY::to_pointer, p> = p;

	// from pointer:

		template<typename T, nik_vp(p)(T*)>
		nik_ce auto NIK_POINTER_APPLY<NIK_POINTER_KEY::from_pointer, p> = p;

		template<typename T, nik_vp(p)(T**)>
		nik_ce auto NIK_POINTER_APPLY<NIK_POINTER_KEY::from_pointer, p> = NIK_STORE_MODULE::template U_store_T<T>;

	// is pointer:

		template<auto V>
		nik_ce auto NIK_POINTER_APPLY<NIK_POINTER_KEY::is_pointer, V> = false;

		template<typename T, nik_vp(p)(T*const*)>
		nik_ce auto NIK_POINTER_APPLY<NIK_POINTER_KEY::is_pointer, p> = true;

	#undef NIK_POINTER_KEY
	#undef NIK_POINTER_APPLY
}

