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

// at:

private:

	template<auto d, auto pos, template<auto...> class ListName, auto... Vs>
	static constexpr auto f_at(void(*)(ListName<Vs...>*))
	{
		return pack_module::template at<d, pos, Vs...>;
	}

public:

	template<typename List, depth_type pos, depth_type depth = 500>
	static constexpr auto at = f_at<depth, pos>(functor_module::template U_type_T<List>);

/***********************************************************************************************************************/

// left:

private:

	template<auto d, auto pos, template<auto...> class ListName, auto... Vs>
	static constexpr auto f_left(void(*)(ListName<Vs...>*))
	{
		return pack_module::template left<d, pos, Vs...>;
	}

public:

	template<typename List, depth_type pos, depth_type depth = 500>
	static constexpr auto left = f_left<depth, pos>(functor_module::template U_type_T<List>);

/***********************************************************************************************************************/

// right:

private:

	template<auto d, auto pos, template<auto...> class ListName, auto... Vs>
	static constexpr auto f_right(void(*)(ListName<Vs...>*))
	{
		return pack_module::template right<d, pos, Vs...>;
	}

public:

	template<typename List, depth_type pos, depth_type depth = 500>
	static constexpr auto right = f_right<depth, pos>(functor_module::template U_type_T<List>);

/***********************************************************************************************************************/

// name:

private:

	template<template<auto...> class ListName, auto... Vs>
	static constexpr auto f_name(void(*)(ListName<Vs...>*))
	{
		return template_pack<ListName>;
	}

public:

	template<typename List>
	static constexpr auto name = f_name(functor_module::template U_type_T<List>);

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
		void(*)(template_pack<OutList>*),
		void(*)(InList1<Vs...>*),
		void(*)(InList2<Ws...>*)
	)
	{
		return functor_module::template U_type_T<OutList<Vs..., Ws...>>;
	}

public:

	template<typename InList1, typename InList2, typename OutList = InList1>
	static constexpr auto catenate	= f_right
					(
						name<OutList>,
						functor_module::template U_type_T<InList1>,
						functor_module::template U_type_T<InList2>
					);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

