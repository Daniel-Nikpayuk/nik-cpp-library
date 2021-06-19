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

#include<cstdio>
#include"a-source.hpp"

/***********************************************************************************************************************/

	using namespace list_operators;
//	using namespace numerical_analysis;
//	using namespace extended_numbers;

/***********************************************************************************************************************/

	struct some_type { };

	int f(const some_type & x)	{ return 0; }
	int g(some_type & x)		{ return 0; }

	int c0(int x) { return x*x; }
	int c1(int x) { return x+7; }

	auto comp = V_do_compose_opt<id<char>, c0>;

/***********************************************************************************************************************/

	int factorial(int n)
	{
		using pair			= pair_signature
						<
							_car_object<int>,
							_cdr_object<int>
						>;

		constexpr auto is_zero		= pair_cast
						<
							is_value<int, 0>, cd_cdr<int>, pair
						>;
		constexpr auto times		= pair_bicast
						<
							multiply<int>, _id_, cd_car<int>,
								       _id_, cd_cdr<int>, pair
						>;
		constexpr auto iterate		= pair_biapply
						<
							assign<int, int>, _id_, d_car<int>,
									  times, cd_pair<int>, pair
						>;
		constexpr auto decrement	= pair_biapply
						<
							assign<int, int>, _id_, d_cdr<int>,
									  add_by<int, -1>, cd_cdr<int>, pair
						>;
		constexpr auto pair_factorial	= cycle
						<
							pair,

							cp_stem		< is_zero, _id_ , iterate >,
							cp_lift		< decrement               >
						>;
		constexpr auto pair_car		= pair_f_car
						<
							_id_, d_car<int>, pair
						>;

		pair s(1, n);

		return  pair_car(pair_factorial(s));
	};

/*
	int pair_factorial(int p, int n)
	{
		if (n == 0) return p;
		else return pair_factorial(p*n, n-1);
	}

	int factorial(int n)
	{
		return pair_factorial(1, n);
	}
*/

/***********************************************************************************************************************/

	int main(int argc, char *argv[])
	{
		int n = 10;

		printf("%d\n", factorial(n));

	//	print_number(39275);

		return 0;
	}

