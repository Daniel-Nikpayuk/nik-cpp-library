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

// boolean source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// conditionals:

private:

	template<bool True, bool...>
	struct T_if_then_else
	{
		template<typename Ante, typename Conse>
		using result = Ante;
	};

	template<bool... filler>
	struct T_if_then_else<false, filler...>
	{
		template<typename Ante, typename Conse>
		using result = Conse;
	};

	template<bool True, auto ante, auto conse>	// This works because as a variable template it has
	static constexpr auto V_if_then_else = ante;	// a partial specialize defined outside of this module.

public:

	// TxT -> T:

	template<bool is_br, typename Ante, typename Conse>
	using T_if_then_else_TxT = typename T_if_then_else<is_br>::template result<Ante, Conse>;

	// VxV -> V:

	template<bool is_br, auto ante, auto conse>
	static constexpr auto V_if_then_else_VxV = V_if_then_else<is_br, ante, conse>;

	// VxV -> T:

	template<bool is_br, auto ante, auto conse>
	using T_if_then_else_VxV = typename cache_module::template T_type_U
	<
		V_if_then_else<is_br, ante, conse>
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

