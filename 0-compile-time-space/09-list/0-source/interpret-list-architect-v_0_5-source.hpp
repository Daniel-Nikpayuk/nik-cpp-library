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

// list source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

private:

	template<typename T>				// This works because as a variable template it has
	static constexpr bool is_list = false;		// a partial specialize defined outside of this module.

public:

	template<typename T>
	static constexpr bool V_is_list_T = is_list<T>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specifiers:

public:

	enum struct List
	{
		modify_list,
		rename_list,

		dimension // filler
	};

	//

	template<List l> static constexpr bool is_modify_list		= (l == List::modify_list);
	template<List l> static constexpr bool is_rename_list		= (l == List::rename_list);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// modify:

private:

	template<typename, List> struct modify;

	template
	<
		template<typename...> class TListName, typename... Ts,
		template<auto...> class VListName, auto... Vs
	>
	struct modify<TListName<Ts...>, List::modify_list, VListName<Vs...>>
	{
		template<template<typename, auto> class M>
		using type = TListName
		<
			M<Ts, Vs>...
		>;
	};

	template<template<typename...> class ListName, typename... Ts>
	struct modify<ListName<Ts...>, List::rename_list>
	{
		template<template<typename> class A>
		using type	= A<Ts...>;
	};

public:

	template<typename T, List l, template<typename...> class A>
	using T_list_modify_TxVxA = typename modify<T, l>::template type<A>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// at:

private:

	template<auto d, auto pos, template<auto...> class ListName, auto... Vs>
	static constexpr auto f_at(void(*)(ListName<Vs...>*))
	{
		return pack_module::template at<d, pos, Vs...>;
	}

public:

	template<typename List, index_type pos, depth_type depth = 500>
	static constexpr auto at = f_at<depth, pos>(cache_module::template U_type_T<List>);

/***********************************************************************************************************************/

// left:

private:

	template<auto d, auto pos, template<auto...> class ListName, auto... Vs>
	static constexpr auto f_left(void(*)(ListName<Vs...>*))
	{
		return pack_module::template left<d, pos, Vs...>;
	}

public:

	template<typename List, index_type pos, depth_type depth = 500>
	static constexpr auto left = f_left<depth, pos>(cache_module::template U_type_T<List>);

/***********************************************************************************************************************/

// right:

private:

	template<auto d, auto pos, template<auto...> class ListName, auto... Vs>
	static constexpr auto f_right(void(*)(ListName<Vs...>*))
	{
		return pack_module::template right<d, pos, Vs...>;
	}

public:

	template<typename List, index_type pos, depth_type depth = 500>
	static constexpr auto right = f_right<depth, pos>(cache_module::template U_type_T<List>);

/***********************************************************************************************************************/

// name:

private:

	template<template<auto...> class ListName, auto... Vs>
	static constexpr auto f_name(void(*)(ListName<Vs...>*))
	{
		return cache_module::template U_pack_Bs<ListName>;
	}

public:

	template<typename List>
	static constexpr auto name = f_name(cache_module::template U_type_T<List>);

/***********************************************************************************************************************/

// catenate:

private:

	template
	<
		template<auto...> class OutList,
		template<auto...> class InList1, auto... Vs,
		template<auto...> class InList2, auto... Ws
	>
	static constexpr auto f_catenate
	(
		void(*)(cache_module::template auto_template_pack<OutList>*),
		void(*)(InList1<Vs...>*),
		void(*)(InList2<Ws...>*)
	)
	{
		return cache_module::template U_type_T<OutList<Vs..., Ws...>>;
	}

public:

	template<typename InList1, typename InList2, typename OutList = InList1>
	static constexpr auto catenate	= f_catenate
					(
						name<OutList>,
						cache_module::template U_type_T<InList1>,
						cache_module::template U_type_T<InList2>
					);

/***********************************************************************************************************************/

// map:

/***********************************************************************************************************************/

// zip:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

