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
		constexpr auto c = controller_module::template drop_s_block__contr<machine_name::first>;
		constexpr auto j = machine_module::block_max_index2(n);
		constexpr auto i = n + j;

		return machine_module::template start<block_machine, c, d, i, j, Vs...>();
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
		constexpr auto c = controller_module::template drop_s_block__contr<machine_name::pack>;
		constexpr auto j = machine_module::block_max_index2(n);
		constexpr auto i = n + j;

		return machine_module::template start<block_machine, c, d, i, j, Vs...>();
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
		constexpr auto c	= controller_module::template erase_contr
					<
						pos, controller_module::template pack<>
					>;
		constexpr auto i	= _zero;
		constexpr auto j	= _zero;

		return machine_module::template start<permutatic_machine, c, d, i, j, Vs...>();
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
		constexpr auto c	= controller_module::template insert_contr
					<
						pos, obj, controller_module::template pack<>
					>;
		constexpr auto i	= _zero;
		constexpr auto j	= _zero;

		return machine_module::template start<permutatic_machine, c, d, i, j, Vs...>();
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
		constexpr auto c	= controller_module::template replace_contr
					<
						pos, obj, controller_module::template pack<>
					>;
		constexpr auto i	= _zero;
		constexpr auto j	= _zero;

		return machine_module::template start<permutatic_machine, c, d, i, j, Vs...>();
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
		constexpr auto c	= controller_module::template left_contr
					<
						n, controller_module::template pack<>
					>;
		constexpr auto j	= _zero;
		constexpr auto i	= _zero;

		return machine_module::template start<permutatic_machine, c, d, i, j, Vs...>();
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
		else
		{
			constexpr auto c	= controller_module::template roll__contr
						<
							controller_module::template stop<_zero>
						>;
			constexpr auto i	= _zero;
			constexpr auto j	= _zero;

			return machine_module::template
				start<permutatic_machine, c, d, i, j, V0, Vs...>
					(machine_module::template U_opt_pack_Vs<length, uact>);
		}
	}

public:

	template<auto d, auto uact, auto V0, auto... Vs>
	static constexpr auto roll = f_roll<d, uact, V0, Vs...>();

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

