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

// linked list (experimental):

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// compile time check:

	template<auto p>
	constexpr auto plus_one = p+1;

/***********************************************************************************************************************/

// linked list:

	struct ll_null { };

	template<typename T, typename NL = ll_null>
	struct ll
	{
		T v;
		NL r;

		constexpr ll(const T & _v, const NL & _r = ll_null()) : v(_v), r(_r) { }
	};

/***********************************************************************************************************************/

// operators:

	template<auto V0, auto... Vs>
	constexpr auto pack_cons()
	{
		constexpr auto value = U_pack_Vs<V0>;

		if constexpr (sizeof...(Vs) == 0)	return ll(value, ll_null());
		else					return ll(value, pack_cons<Vs...>());
	}

	template<auto... Vs>
	constexpr auto auto_pack_cons(void(*)(auto_pack<Vs...>*))
	{
		if constexpr (sizeof...(Vs) == 0)	return ll_null();
		else					return pack_cons<Vs...>();
	}

	template<auto V0, auto... Vs>
	constexpr auto auto_pack_first(void(*)(auto_pack<V0, Vs...>*))
	{
		return V0;
	}

	template<utype pos, typename LL0, typename LL>
	constexpr auto ll_at(const LL0 & l0, LL l)
	{
		if constexpr (pos == 0)			return auto_pack_first(l.v);
		else					return ll_at<pos-1>(l0, l.r);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

