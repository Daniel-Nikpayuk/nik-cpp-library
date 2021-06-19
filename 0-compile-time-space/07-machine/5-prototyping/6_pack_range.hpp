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

// pack range:

/***********************************************************************************************************************/

	template<typename T, auto N, auto P, auto... Vs>
	constexpr auto pack_range_f()
	{
		if constexpr (N == 0)	return U_pack_Vs<Vs...>;
		else			return range<T, N-1, P+1, Vs..., add_by<T, (1 << P)>(Vs)...>();
	}

	template<u_type N, u_type P = 0, typename T = unsigned long long>
	constexpr auto pack_range = pack_range_f<T, N, P, 1>();

/***********************************************************************************************************************/

// code bloat:

/*
	template<typename... Ts>
	constexpr stype helper(Ts... Vs) { return (1 * ... * Vs); }

	template<utype N, utype P, stype... Vs>
	constexpr stype polynomial(stype x)
	{
		if constexpr (N == 0)	return helper(plus_N<Vs>(x)...);
		else			return polynomial<N-1, P+1, Vs..., plus_N<(1 << P)>(Vs)...>(x);
	}
*/

/***********************************************************************************************************************/

	int main(int argc, char *argv[])
	{
	//	stype x;

	//	std::cin >> x;

	//	printf("%lld\n", polynomial<13, 0, 1>(x));

		printf(range<3, 0, 1>());

		return 0;
	}

