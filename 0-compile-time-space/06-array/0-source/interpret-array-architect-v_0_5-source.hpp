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

// array source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

// is array::

private:

	template<typename T>				// This works because as a variable template it has
	static constexpr bool is_array = false;		// a partial specialize defined outside of this module.

public:

	template<typename T>
	static constexpr bool V_is_array_T = is_array<T>;

/***********************************************************************************************************************/

// size:

private:

//	template<typename T>				// This works because as a variable template it has
//	static constexpr bool array_size = 0;		// a partial specialize defined outside of this module.

public:

//	template<typename T>
//	static constexpr bool V_array_size_T = array_size<T>;

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

//	template<Array r> static constexpr bool is_to_array		= (r == Array::to_array);
//	template<Array r> static constexpr bool is_from_array		= (r == Array::from_array);

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

// array:

/***********************************************************************************************************************/

public:

// variable:

	template<typename Type, Type... Vs>
	static constexpr Type array[] = { Vs... };

// struct:

	template<typename Type, auto N>
	struct Array { Type value[N]; };

// apply:

	template<typename F, const auto *arr, auto... Is>
	static constexpr auto apply(nik_avpcr(auto_pack<Is...>*))
	{
		constexpr auto size	= sizeof...(Is);
		constexpr auto nttp	= F::template result<size>(arr);
		using ConstType		= T_pointer_modify_TxV<decltype(arr), Pointer::from_pointer>;
		using Type		= T_const_modify_TxV<ConstType, Constant::from_const>;

		return array<Type, nttp.value[Is]...>;
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

