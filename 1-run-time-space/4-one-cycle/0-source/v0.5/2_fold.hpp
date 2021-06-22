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

// one cycle fold:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// spec:

private:

	template<typename Spec>
	return_type_<Spec> fold(out_type_<Spec> o, in_type_<Spec> i, end_type_<Spec> e)
	{
		constexpr auto fold_f = cycle_inductor
		<
			precycle
			<
				signature_<Spec>,

				interval_before_loop	< in_ival_<Spec>	, in_next_<Spec>	>

			>, cycle
			<
				signature_<Spec>,

				stem_before_value	< loop_pred_<Spec>	, _id_			>,
				before_combine		< combine_func_<Spec>				>,
				before_next		< in_next_<Spec>				>

			>, postcycle
			<
				signature_<Spec>,

				interval_after_loop	< in_ival_<Spec>	, combine_func_<Spec>	>
			>
		>;

		signature_<Spec> s(o, i, e);

		return return_cons_<Spec>(fold_f(s));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template<typename, typename, typename, typename> struct fold_specification;

/*
	template
	<
		typename OutType, typename OutAttr,
		typename InType, typename InAttr, typename InIval, typename InCar, typename InCdr,
		typename EndType, typename EndAttr,

		typename ActFunction, typename CombineFunction
	>
	struct fold_specification
	<
		_out		< OutType , OutAttr 				>,
		_in		< InType  , InAttr  , InIval , InCar , InCdr	>,
		_end		< EndType , EndAttr				>,

		_function	< ActFunction ,	CombineFunction			>
	>
	{
	// out:

		using out_type				= typename OutType::type;
		using out_attr				= typename OutAttr::type;

		using out_obj				= out_object		< out_type , out_attr		>;
		using dout_obj				= obj_to_direct		< out_obj			>;

	// in:

		using in_type				= typename InType::type;
		using in_attr				= typename InAttr::type;

		using in_obj				= in_object		< in_type	, in_attr	>;
		using din_obj				= obj_to_direct		< in_obj			>;
		using cin_obj				= obj_to_immutable	< in_obj			>;
		using cdin_obj				= obj_to_immutable	< din_obj			>;

		static constexpr Interval in_ival	= InIval::value;
		static constexpr auto in_car		= InCar::value;
		static constexpr auto in_cdr		= iterate<InCdr::value, in_type>;

	// end:

		using end_type				= typename EndType::type;
		using end_attr				= typename EndAttr::type;

		using end_obj				= end_object		< end_type	, end_attr	>;
		using dend_obj				= obj_to_direct		< end_obj			>;
		using cdend_obj				= obj_to_immutable	< dend_obj			>;

	// signature:

		using signature				= one_cycle_signature
							<
								out_object	< obj_type<out_obj>		>,
								in_object	< obj_type<in_obj>		>,
								end_object	< obj_type<end_obj>		>
							>;

	// return:

		using return_type			= out_type;

		static constexpr auto
			return_constructor		= one_cycle_f_out<_id_, dout_obj, signature>;

	// function:

		static constexpr auto act_f		= ActFunction::value;
		static constexpr auto combine_f		= CombineFunction::value;

	// atomic filters:

		static constexpr auto value_act_f	= V_do_compose_opt<in_car, act_f>;

		static constexpr auto loop_predicate	= one_cycle_equals
							<
								_id_, cdin_obj, cdend_obj, signature
							>;
		static constexpr auto combine_function	= one_cycle_biassign
							<
								out_obj, combine_f, _id_, out_obj,
										 value_act_f, cin_obj, signature
							>;
		static constexpr auto in_next		= one_cycle_assign
							<
								din_obj, in_cdr, cdin_obj, signature
							>;
	};
*/

/***********************************************************************************************************************/

/*
	template
	<
		typename Type,
		auto fold_function,

		auto map_function	= _id_,
		auto Ival		= Interval::closing,
		auto Dir		= Direction::forward
	>
	using fold_spec			= fold_specification
	<
		_out
		<
			_type		< Type		>,
			_attr		< rw_constant	>
		>,

		_in
		<
			_type		< Type*		>,
			_attr		< rw_iterator	>,
			_ival		< Ival		>,
			_value		< _id_		>,
			_next		< Dir		>
		>,

		_end
		<
			_type		< Type*		>,
			_attr		< rw_iterator	>
		>,

		_function
		<
			_act_f		< map_function	>,
			_combine_f	< fold_function >
		>
	>;
*/

/***********************************************************************************************************************/

/*
	template
	<
		typename Type,
		auto fold_function,

		auto map_function	= _id_,
		auto Ival		= Interval::closing,
		auto Dir		= Direction::forward
	>
	using range_fold_spec		= fold_specification
	<
		_out
		<
			_type		< Type		>,
			_attr		< rw_constant	>
		>,

		_in
		<
			_type		< Type		>,
			_attr		< rw_range	>,
			_ival		< Ival		>,
			_value		< _id_		>,
			_next		< Dir		>
		>,

		_end
		<
			_type		< Type		>,
			_attr		< rw_range	>
		>,

		_function
		<
			_act_f		< map_function	>,
			_combine_f	< fold_function >
		>
	>;
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

