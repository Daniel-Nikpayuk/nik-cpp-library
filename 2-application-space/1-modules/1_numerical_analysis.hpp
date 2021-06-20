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

// numerical analysis:

/***********************************************************************************************************************/

namespace numerical_analysis
{
	using namespace list_operators;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// numerical operators:

/***********************************************************************************************************************/

	template<typename Type>
	constexpr Type twice(Type x)		{ return 2*x; }

	template<typename Type>
	constexpr Type square(Type x)		{ return x*x; }

	template<typename Type>
	constexpr Type inverse(Type x)		{ return 1.0/x; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// summation:

	template<auto map_function, typename Type>
	Type sum(Type i, Type e)
	{
		using spec = range_fold_spec
		<
			Type,
			add<Type>,
			map_function,
			Interval::closed
		>;

		return fold<spec>(0, i, e);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// production:

	template<auto map_function, typename Type>
	Type prod(Type i, Type e)
	{
		using spec = range_fold_spec
		<
			Type,
			multiply<Type>,
			map_function,
			Interval::closed
		>;

		return fold<spec>(1, i, e);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// kahan summation:

/***********************************************************************************************************************/

	template<auto f, typename AuxType, typename InType>
	constexpr void kahan_assign(AuxType & aux, InType in)
	{
		aux.car = f(in);
	}

	template<typename OutType, typename AuxType>
	constexpr OutType kahan_add(OutType out, AuxType & aux)
	{
		aux.cdr	= aux.car - aux.cdr;
		aux.car	= out + aux.cdr;
		aux.cdr	= (aux.car - out) - aux.cdr;

		return aux.car;
	}

/***********************************************************************************************************************/

/*
	template<auto map_function, Interval ival, Direction dir, typename InType>
	f_out_type<map_function> kahan_sum(InType i, InType e)
	{
	// signature:

		using OutType			= f_out_type		< map_function				>;
		using AuxType			= pair			< OutType	, OutType		>;
		using signature_spec		= one_cycle_signature
						<
							out_object	< OutType	, Object::constant	>,
							in_object 	< InType	, Object::range		>,
							end_object	< InType	, Object::range		>,
							aux_object	< AuxType	, Object::constant	>,
							msg_object	<			 		>
						>;
		using signature			= ocs_memory		< 		  signature_spec	>;

	// atomic filters:

		constexpr auto loop_end_f	= in_equals_end		< _id_		, signature_spec	>;
		constexpr auto set_f		= kahan_assign		< map_function	, AuxType, InType	>;
		constexpr auto add_f		= kahan_add		< OutType	, AuxType		>;
		constexpr auto next_f		= in_iterate		< to_next<dir>	, signature_spec	>;

	// composite filters:

		constexpr auto act_f		= aux_in_void_assign	< set_f		, signature_spec	>;
		constexpr auto combine_f	= out_aux_reassign	< add_f		, signature_spec	>;

	// resolution:

		constexpr auto sum_f		= nik_cpp_library
		<
			precycle
			<
				signature,

				interval_before_loop	< ival		, next_f	>

			>, cycle
			<
				signature,

				stem_before_value	< loop_end_f	, _id_		>,
				before_act		< act_f				>,
				before_combine		< combine_f			>,
				before_next		< next_f			>

			>, postcycle
			<
				signature,

				interval_after_loop	< ival		, act_f		>,
				interval_after_loop	< ival		, combine_f	>
			>
		>;

		signature s			= signature(0.0, i, e, AuxType(0.0, 0.0));

		return sum_f(s).out;
	}
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

