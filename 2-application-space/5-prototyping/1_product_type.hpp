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

// product type (experimental):

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pair:

/***********************************************************************************************************************/

	template<typename T, typename U>
	struct S_pair
	{
		T x;
		U y;

		constexpr S_pair(const T & _x, const U & _y) : x(_x), y(_y) { }
	};

	constexpr void _null_() { }

	template<auto x, auto y> constexpr auto cons()			{ return S_pair(x, y); }

	template<typename PairF> constexpr auto car(const PairF & p)	{ return p().x; }
	template<typename PairF> constexpr auto car(PairF && p)		{ return p().x; }

	template<typename PairF> constexpr auto cdr(const PairF & p)	{ return p().y; }
	template<typename PairF> constexpr auto cdr(PairF && p)		{ return p().y; }

/***********************************************************************************************************************/

	template<auto V, auto... Vs>
	constexpr auto f_make_pack()
	{
		if constexpr (sizeof...(Vs) == 0)	return cons<V, _null_>;
		else					return cons<V, f_make_pack<Vs...>()>;
	}

	template<auto... Vs>
	constexpr auto f_make_list(void(*)(auto_pack<Vs...>*))
	{
		if constexpr (sizeof...(Vs) == 0)	return _null_;
		else					return f_make_pack<Vs...>();
	}

	template<typename List>
	constexpr auto make_list = f_make_list(U_type_T<List>);

/***********************************************************************************************************************/

	template<auto pos, typename List>
	constexpr auto f_at_list(const List & l)
	{
		if constexpr (pos == 0)	return car(l);
		else			return f_at_list<pos-1>(cdr(l));
	}

	template<auto pos, typename List>
	constexpr auto f_at_list(List && l)
	{
		if constexpr (pos == 0)	return car(l);
		else			return f_at_list<pos-1>(cdr(l));
	}

	template<auto l, auto pos>
	constexpr auto at_list = f_at_list<pos>(l);

/***********************************************************************************************************************/

//	constexpr auto P_list_50	= make_list<list_50>;
//	constexpr auto P_list_500	= make_list<list_500>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// version 0:

/***********************************************************************************************************************/

	template<typename... Ts> struct product { };

	template<typename T, typename... Ts>
	struct product<T, Ts...>
	{
		T v;
		product<Ts...> vs;

		product(const T & _v, const Ts &... _vs) : v(_v), vs(_vs...) { }

		template<auto pos>
		auto & member()
		{
			if constexpr (pos == 0)	return v;
			else			return vs.template member<pos-1>();
		}
	};

	template<auto pos, typename T, typename... Ts>
	auto & product_member(product<T, Ts...> & p)
	{
		return p.template member<pos>();
	}

	//	product<int, double, char> p{-3, 2.0, 'c'};

	//	p.template member<0>() = 5;

	//	printf("%d\n", p.template member<0>());
	//	printf("%f\n", p.template member<1>());
	//	printf("%c\n", p.template member<2>());

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// version 1:

/***********************************************************************************************************************/

	template<auto pos, typename... Ts>
	using T_pack_at_T = T_type_U<pack_at<500, pos, U_type_T<Ts>...>>;

	template<typename, typename...> class product;

	template<auto pos, typename T, typename... Ts>
	auto & product_member(product<T, Ts...> & p)
	{
		if constexpr (pos == 0)	return p.v;
		else			return product_member<pos-1>(p.vs);
	}

	template<typename T>
	class product<T>
	{
			T v;

		public:
			product(const T & _v) : v(_v) { }

			template<auto pos, typename U, typename... Us>
			friend auto & product_member(product<U, Us...> &);
	};

	template<typename T, typename... Ts>
	class product
	{
			T v;
			product<Ts...> vs;

		public:
			product(const T & _v, const Ts &... _vs) : v(_v), vs(_vs...) { }

			template<auto pos, typename, typename... Us>
			friend auto & product_member(product<U, Us...> &);
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

