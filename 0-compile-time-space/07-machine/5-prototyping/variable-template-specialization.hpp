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

	constexpr int id     (int x) { return   x; }
	constexpr int square (int x) { return x*x; }

	template<auto V>
	constexpr int add_by (int x) { return x+V; }

	struct function
	{
		template<auto index, auto...>
		static constexpr auto result			= id;
	};

	template<auto... filler>
	constexpr auto function::result<0, filler...>		= square;

	template<auto V, auto... filler>
	constexpr auto function::result<1, V, filler...>	= add_by<V>;

