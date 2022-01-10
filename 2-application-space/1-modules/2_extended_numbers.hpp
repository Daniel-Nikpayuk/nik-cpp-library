/************************************************************************************************************************
**
** Copyright 2021-2022 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

// extended (big) numbers:

/***********************************************************************************************************************/

namespace extended_numbers
{
	using namespace list_operators;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// extended operators:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// ceiling log:

	template<typename Type, Type radix = 10>
	constexpr Type ceillog(Type number, Type counter = 0)
	{
		return !bool(number) ? counter : ceillog(number / radix, counter + 1);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// number to numeral:

	template<typename Type>
	constexpr char number_to_numeral(Type n)
	{
		if (n < 5)
		{
			if (n < 2)
			{
				if (n)		return '1';
				else		return '0';
			}
			else if (n < 3)		return '2';
			else if (n == 4)	return '4';
			else			return '3';
		}
		else if (n < 7)
		{
			if (n == 6)		return '6';
			else			return '5';
		}
		else if (n < 8)			return '7';
		else if (n == 9)		return '9';
		else				return '8';
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// number to string spec:

	template
	<
		typename OutIter, typename InType,
		auto car_f, auto cdr_f, auto to_numeral
	>
	using num2str_spec = map_specification
	<
		_out
		<
			_type		< OutIter		>,
			_attr		< rw_iterator		>,
			_ival		< Interval::opening	>,
			_next		< Direction::backward	>
		>,

		_in
		<
			_type		< InType		>,
			_attr		< rw_range		>,
			_ival		< Interval::closing	>,
			_axis		< Axis::unidirectional	>,
			_value		< car_f			>,
			_next		< cdr_f			>,
			_peek		< cdr_f			>
		>,

		_end
		<
			_type		< InType		>,
			_attr		< rw_range		>,
			_next		< Direction::backward	>,
			_prev		< Direction::forward	>
		>,

		_function
		<
			_act_f		< to_numeral		>
		>
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// print number:

	template<typename InType, InType radix = 10, auto to_numeral = add_by<InType, '0'>>
	void print_number(InType n)
	{
		using ArrType			= char;
		using OutIter			= ArrType*;

		using spec			= num2str_spec
		<
			OutIter, InType,
			modulo_by<InType, radix>,
			divide_by<InType, radix>,
			to_numeral
		>;

		//

		InType arr_leng			= ceillog(n) + 1;
		ArrType arr[arr_leng],
			*arr_end		= arr + (arr_leng - 1);
			*arr_end		= '\0';

		map<spec>(arr_end, n, 0);

		printf("%s\n", arr);
	}

/***********************************************************************************************************************/

/*
	template
	<
		typename InIter,
		template<typename> class pointer_type = T_pointer_type_T,
		pointer_type<InIter> radix= 10,
		auto to_numeral = add_by<pointer_type<InIter>, '0'>
	>
	void print_number(InIter begin, InIter end)
	{
		using ArrType		= char;
		using OutIter		= ArrType*;

		InType arr_leng		= ceillog(n) + 1;

		ArrType arr[arr_leng],
			*arr_end	= arr + (arr_leng - 1);
			*arr_end	= '\0';

		number_to_string
		<
			Interval::opening, Direction::backward,
			Interval::closing,
			OutIter, InType,
			radix, to_numeral

		>(arr_end, n, 0);

		printf("%s", arr);
	}
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// arithmetic operators:

/***********************************************************************************************************************/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

