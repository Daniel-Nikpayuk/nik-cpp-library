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
	static constexpr auto f_list_at(void(*)(ListName<Vs...>*))
	{
		return pack_module::template pack_at<d, pos, Vs...>;
	}

public:

	template<typename List, depth_type pos, depth_type depth = 500>
	static constexpr auto list_at = f_list_at<depth, pos>(functor_module::template U_type_T<List>);

/***********************************************************************************************************************/

// left:

private:

	template<auto d, auto pos, template<auto...> class ListName, auto... Vs>
	static constexpr auto f_list_left(void(*)(ListName<Vs...>*))
	{
		return pack_module::template pack_left<d, pos, Vs...>;
	}

public:

	template<typename List, depth_type pos, depth_type depth = 500>
	static constexpr auto list_left = f_list_left<depth, pos>(functor_module::template U_type_T<List>);

/***********************************************************************************************************************/

// right:

private:

	template<auto d, auto pos, template<auto...> class ListName, auto... Vs>
	static constexpr auto f_list_right(void(*)(ListName<Vs...>*))
	{
		return pack_module::template pack_right<d, pos, Vs...>;
	}

public:

	template<typename List, depth_type pos, depth_type depth = 500>
	static constexpr auto list_right = f_list_right<depth, pos>(functor_module::template U_type_T<List>);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

