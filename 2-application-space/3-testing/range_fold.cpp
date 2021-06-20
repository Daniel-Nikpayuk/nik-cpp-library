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

#include"numerical_analysis.h"

/***********************************************************************************************************************/

// fold:

namespace ocli_testing
{
	using namespace numerical_analysis;

/***********************************************************************************************************************/

	void simple_sum_test()
	{
		array<s_type> arr;

		s_type n = 20;
		s_type value = sum<_id_>(s_type(1), s_type(n));

		printf("\nsum value: %lld", value);
		printf("\nbase value: %lld\n", s_type(n*(n+1)/2));
	}

/***********************************************************************************************************************/

	void simple_prod_test()
	{
		array<u_type> arr;

		u_type n = 20;
		u_type value = prod<_id_>(s_type(1), s_type(n));

		printf("\nprod value: %lld", value);

		u_type factorial_value = 1;

		while (n > 0)
		{
			factorial_value *= n--;
		}

		printf("\nbase value: %lld\n", factorial_value);
	}

/***********************************************************************************************************************/

/*
	void kahan_sum_test()
	{
		template<typename Type>
		constexpr auto sq_inverse = V_do_compose_opt<square<Type>, inverse<Type>>;

		using k_type	= float;
		int n		= 100000;

		k_type s = sum<inverse<k_type>, Interval::closed, Direction::forward>(1, n);
		printf("%.15g\n", s);

		k_type ks = kahan_sum<inverse<k_type>, Interval::closed, Direction::forward>(1, n);
		printf("%.15g\n", ks);

		k_type ks = 6*kahan_sum<sq_inverse<k_type>, Interval::closed, Direction::forward>(1, n);
		printf("%.15g\n", ks);

		k_type pi = 3.1415926535897932384626;
		printf("%.15g\n", pi*pi);
	};
*/

/***********************************************************************************************************************/

}

