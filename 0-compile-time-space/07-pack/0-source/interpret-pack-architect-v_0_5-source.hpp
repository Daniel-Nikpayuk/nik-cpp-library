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

// pack source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block machines:

/***********************************************************************************************************************/

// at:

private:

	template<auto d, auto n, auto... Vs>
	static constexpr auto f_at()
	{
		constexpr auto c	= machine_module::template label
					<
						machine_module::template stop<n>
					>;

		return machine_module::template start<linear_machine, c, d, Vs...>();
	}

public:

	template<auto d, auto n, auto... Vs>
	static constexpr auto at = f_at<d, n, Vs...>();

/***********************************************************************************************************************/

// right:

private:

	template<auto d, auto n, auto... Vs>
	static constexpr auto f_right()
	{
		constexpr auto c	= machine_module::template label
					<
						machine_module::template drop_s_segment<n>,
						machine_module::template pack<>
					>;

		return machine_module::template start<linear_machine, c, d, Vs...>();
	}

public:

	template<auto d, auto n, auto... Vs>
	static constexpr auto right = f_right<d, n, Vs...>();

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// permutatic machines:

/***********************************************************************************************************************/

// erase:

private:

	template<auto d, auto pos, auto... Vs>
	static constexpr auto f_erase()
	{
		constexpr auto c	= machine_module::template label
					<
						machine_module::template erase<pos>,
						machine_module::template pack<>
					>;

		return machine_module::template start<linear_machine, c, d, Vs...>();
	}

public:

	template<auto d, auto pos, auto... Vs>
	static constexpr auto erase = f_erase<d, pos, Vs...>();

/***********************************************************************************************************************/

// insert:

private:

	template<auto d, auto pos, auto obj, auto... Vs>
	static constexpr auto f_insert()
	{
		constexpr auto c	= machine_module::template label
					<
						machine_module::template insert<pos, obj>,
						machine_module::template pack<>
					>;

		return machine_module::template start<linear_machine, c, d, Vs...>();
	}

public:

	template<auto d, auto pos, auto obj, auto... Vs>
	static constexpr auto insert = f_insert<d, pos, obj, Vs...>();

/***********************************************************************************************************************/

// replace:

private:

	template<auto d, auto pos, auto obj, auto... Vs>
	static constexpr auto f_replace()
	{
		constexpr auto c	= machine_module::template label
					<
						machine_module::template replace<pos, obj>,
						machine_module::template pack<>
					>;

		return machine_module::template start<linear_machine, c, d, Vs...>();
	}

public:

	template<auto d, auto pos, auto obj, auto... Vs>
	static constexpr auto replace = f_replace<d, pos, obj, Vs...>();

/***********************************************************************************************************************/

// left:

private:

	template<auto d, auto n, auto... Vs>
	static constexpr auto f_left()
	{
		constexpr auto c	= machine_module::template label
					<
						machine_module::template move_s_segment__insert_at_h1_back<n>,
						machine_module::template drop_s_all<>,
						machine_module::template move_h1_all__insert_at_s_front<>,
						machine_module::template pack<>
					>;

		return machine_module::template start<linear_machine, c, d, Vs...>();
	}

public:

	template<auto d, auto n, auto... Vs>
	static constexpr auto left = f_left<d, n, Vs...>();

/***********************************************************************************************************************/

// roll:

private:

	template<auto d, auto uact, auto V0, auto... Vs>
	static constexpr auto f_roll()
	{
		constexpr auto length = sizeof...(Vs);

		if constexpr (length == 0) return V0;

		constexpr auto c	= machine_module::template label
					<
						machine_module::template roll_s_segment__replace_at_s_front<length>,
						machine_module::template first<>
					>;

		return machine_module::template
			start<linear_machine, c, d, V0, Vs...>
				(cache_module::template U_pack_Vs<length, uact>);
	}

public:

	template<auto d, auto uact, auto V0, auto... Vs>
	static constexpr auto roll = f_roll<d, uact, V0, Vs...>();

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

