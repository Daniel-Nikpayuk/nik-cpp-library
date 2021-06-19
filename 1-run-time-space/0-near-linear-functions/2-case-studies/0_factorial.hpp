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

// factorial:

	using namespace continuation_space;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pair:

	template<typename T> class pair;

	template<typename T> T & car(pair<T> & p)	{ return p.x; }
	template<typename T> T & cdr(pair<T> & p)	{ return p.y; }

	template<typename T>
	class pair
	{
		T x, y;

		public:

			constexpr pair(const T & _x, const T & _y) : x(_x), y(_y) { }

			friend T & car<T>(pair<T> &);
			friend T & cdr<T>(pair<T> &);
	};

/***********************************************************************************************************************/

// spec:

	template
	<
		typename T,

		auto p		= car<T>		,
		auto n		= cdr<T>		,

		auto is_zero	= is_value<T, 0>	,
		auto halt	= _id_ 			, // id<pair<T>&>
		auto times	= multiply<T>		,
		auto decrement	= subtract_by<T, 1>
	>
	constexpr auto U_pair_factorial = chain_endopose
	<
		stem
		<
			test   < is_zero, n      >,

			halt,
			assign < p, times, p, n  >
		>,

		lift
		<
			assign < n, decrement, n >
		>
	>;

/***********************************************************************************************************************/

// factorial:

	utype factorial(utype n)
	{
		pair<utype> s(1, n);

		return car<utype>(one_cycle<U_pair_factorial<utype>>(s));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

