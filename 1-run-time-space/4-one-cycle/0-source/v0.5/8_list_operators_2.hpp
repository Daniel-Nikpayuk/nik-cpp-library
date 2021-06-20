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

// one cycle list operators:

/*
	inventory:

		find all, zip, fasten, glide
*/

/***********************************************************************************************************************/

namespace nlfs_8
{
	using namespace nlfs_7;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// find all:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template<typename Spec>
	return_type_<Spec> find_all(out_type_<Spec> o, in_type_<Spec> i, end_type_<Spec> e)
	{
		constexpr auto find_all_f = cycle_inductor
		<
			precycle
			<
				signature_<Spec>,

				boolean_before_loop	< is_bi_last_<Spec>	, end_prev_<Spec>	>,

				interval_before_loop	< out_ival_<Spec>	, out_next_<Spec>	>,
				interval_before_loop	< in_ival_<Spec>	, in_next_<Spec>	>

			>, cycle
			<
				signature_<Spec>,

				stem_before_value	< loop_pred_<Spec>	, _id_			>,
				before_value		< value_pred_<Spec>				>,
				distem_before_act	< act_pred_<Spec>	, act_func_<Spec>	>,
				distem_before_next	< act_pred_<Spec>	, out_next_<Spec>	>,
				before_next		< in_next_<Spec>				>

			>, postcycle
			<
				signature_<Spec>,

				boolean_after_loop	< ival_meet_<Spec>	, post_func_<Spec>	>,
				boolean_after_loop	< out_ival_meet_<Spec>	, out_next_<Spec>	>,
				boolean_after_loop	< in_ival_meet_<Spec>	, in_next_<Spec>	>,

				boolean_after_loop	< is_bi_last_<Spec>	, end_next_<Spec>	>
			>
		>;

		signature_<Spec> s(o, i, e, false);

		return return_cons_<Spec>(find_all_f(s));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	template<typename, typename, typename, typename, typename> struct find_all_specification;

	template
	<
		typename OutType, typename OutAttr, typename OutIval, typename OutCdr,
		typename InType, typename InAttr, typename InIval,
			typename InAxis, typename InCar, typename InCdr, typename InPeek,
		typename EndType, typename EndAttr, typename EndCdr, typename EndRCdr,
		typename AuxType, typename AuxAttr,

		typename ValuePredicate
	>
	struct find_all_specification
	<
		_out		< OutType , OutAttr , OutIval , OutCdr					>,
		_in		< InType  , InAttr  , InIval  , InAxis  , InCar , InCdr , InPeek	>,
		_end		< EndType , EndAttr , EndCdr  , EndRCdr					>,
		_aux		< AuxType , AuxAttr							>,

		_function	< ValuePredicate							>
	>
	{
	// out:

		using out_type				= typename OutType::type;
		using out_attr				= typename OutAttr::type;

		using out_obj				= out_object		< out_type , out_attr		>;
		using dout_obj				= obj_to_direct		< out_obj			>;
		using cdout_obj				= obj_to_immutable	< dout_obj			>;

		static constexpr Interval out_ival	= OutIval::value;
		static constexpr auto out_cdr		= iterate<OutCdr::value, out_type>;

	// in:

		using in_type				= typename InType::type;
		using in_attr				= typename InAttr::type;

		using in_obj				= in_object		< in_type	, in_attr	>;
		using din_obj				= obj_to_direct		< in_obj			>;
		using cin_obj				= obj_to_immutable	< in_obj			>;
		using cdin_obj				= obj_to_immutable	< din_obj			>;

		static constexpr Interval in_ival	= InIval::value;
		static constexpr Axis in_axis		= InAxis::value;
		static constexpr auto in_car		= InCar::value;
		static constexpr auto in_cdr		= iterate<InCdr::value, in_type>;
		static constexpr auto in_peek		= iterate<InPeek::value, in_type>;

	// end:

		using end_type				= typename EndType::type;
		using end_attr				= typename EndAttr::type;

		using end_obj				= end_object		< end_type	, end_attr	>;
		using dend_obj				= obj_to_direct		< end_obj			>;
		using cdend_obj				= obj_to_immutable	< dend_obj			>;

		static constexpr auto end_cdr		= iterate<EndCdr::value, end_type>;
		static constexpr auto end_rcdr		= iterate<EndRCdr::value, end_type>;

	// aux:

		using aux_type				= typename AuxType::type;
		using aux_attr				= typename AuxAttr::type;

		using aux_obj				= aux_object		< aux_type	, aux_attr	>;
		using caux_obj				= obj_to_immutable	< aux_obj			>;

	// signature:

		using signature				= one_cycle_signature
							<
								out_object	< obj_type<out_obj>		>,
								in_object	< obj_type<in_obj>		>,
								end_object	< obj_type<end_obj>		>,
								aux_object	< obj_type<aux_obj>		>
							>;

	// return:

		using return_type			= out_type;

		static constexpr auto
			return_constructor		= one_cycle_f_out<_id_, dout_obj, signature>;

	// function:

		static constexpr auto value_p		= ValuePredicate::value;

	// atomic filters:

		static constexpr auto value_act_p	= V_do_compose_opt<in_car, value_p>;

		static constexpr auto value_predicate	= one_cycle_assign
							<
								aux_obj, value_act_p, cin_obj, signature
							>;
		static constexpr auto act_predicate	= one_cycle_match
							<
								_id_, caux_obj, signature
							>;
		static constexpr auto act_function	= one_cycle_assign
							<
								out_obj, _id_, cdin_obj, signature
							>;
		static constexpr auto out_next		= one_cycle_assign
							<
								dout_obj, out_cdr, cdout_obj, signature
							>;
		static constexpr auto in_next		= one_cycle_assign
							<
								din_obj, in_cdr, cdin_obj, signature
							>;
		static constexpr auto end_next		= one_cycle_assign
							<
								dend_obj, end_cdr, cdend_obj, signature
							>;
		static constexpr auto end_previous	= one_cycle_assign
							<
								dend_obj, end_rcdr, cdend_obj, signature
							>;

	// composite filters:

	//	1. For each left endpoint, if open, then iterate.
	//	2. Evaluate the common (closing) loop.
	//	3. If there exists any right endpoint, which is closed, then act/combine.
	//	4. If (3), then for each right endpoint, when open, iterate.

		static constexpr bool ival_meet		= or_right_closed	< out_ival	, in_ival	>;
		static constexpr bool out_ival_meet	= right_open_and	< out_ival	, ival_meet	>;
		static constexpr bool in_ival_meet	= right_open_and	< in_ival	, ival_meet	>;

		static constexpr bool is_unidir		= V_is_unidirectional	< in_axis			>;
		static constexpr bool is_uni_last	= V_boolean_and		< is_unidir	, in_ival_meet	>;

		static constexpr bool is_bidir		= V_is_bidirectional	< in_axis			>;
		static constexpr bool is_bi_last	= V_boolean_and		< is_bidir	, in_ival_meet	>;

		static constexpr auto end_f		= V_if_then_else
							  < is_uni_last		, in_peek	, _id_		>;
		static constexpr auto loop_predicate	= one_cycle_equals
							<
								end_f, cdin_obj, cdend_obj, signature
							>;

		//

		static constexpr auto post_function	= postcycle
							<
								signature,

								stem_after_loop < act_predicate , act_function >
							>;
	};
*/

/***********************************************************************************************************************/

/*
	template
	<
		typename Type,
		auto find_function,

		auto OutIval		= Interval::closing,
		auto OutDir		= Direction::forward,

		auto InIval		= Interval::closing,
		auto InDir		= Direction::forward,
		auto InRDir		= Direction::backward,
		auto InAxis		= Axis::bidirectional
	>
	using find_all_spec		= find_all_specification
	<
		_out
		<
			_type		< Type**	>,
			_attr		< rw_iterator	>,
			_ival		< OutIval	>,
			_next		< OutDir	>
		>,

		_in
		<
			_type		< Type*		>,
			_attr		< rw_iterator	>,
			_ival		< InIval	>,
			_axis		< InAxis	>,
			_value		< _id_		>,
			_next		< InDir		>,
			_peek		< InDir		>
		>,

		_end
		<
			_type		< Type*		>,
			_attr		< rw_iterator	>,
			_next		< InDir		>,
			_prev		< InRDir	>
		>,

		_aux
		<
			_type		< bool		>,
			_attr		< rw_constant	>
		>,

		_function
		<
			_value_p	< find_function	>
		>
	>;
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// zip (bimap):

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template<typename Spec>
	return_type_<Spec> zip(out_type_<Spec> o, car_in_type_<Spec> i1, cdr_in_type_<Spec> i2, end_type_<Spec> e2)
	{
		constexpr auto zip_f = cycle_inductor
		<
			precycle
			<
				signature_<Spec>,

				boolean_before_loop	< is_bi_last_<Spec>		, end_prev_<Spec>	>,
				interval_before_loop	< out_ival_<Spec>		, out_next_<Spec>	>,
				interval_before_loop	< car_in_ival_<Spec>		, car_in_next_<Spec>	>,
				interval_before_loop	< cdr_in_ival_<Spec>		, cdr_in_next_<Spec>	>

			>, cycle
			<
				signature_<Spec>,

				stem_before_value	< loop_pred_<Spec>		, _id_			>,
				before_act		< act_func_<Spec>					>,
				before_next		< out_next_<Spec>					>,
				before_next		< car_in_next_<Spec>					>,
				before_next		< cdr_in_next_<Spec>					>

			>, postcycle
			<
				signature_<Spec>,

				boolean_after_loop	< ival_meet_<Spec>		, act_func_<Spec>	>,
				boolean_after_loop	< out_ival_meet_<Spec>		, out_next_<Spec>	>,
				boolean_after_loop	< car_in_ival_meet_<Spec>	, car_in_next_<Spec>	>,
				boolean_after_loop	< cdr_in_ival_meet_<Spec>	, cdr_in_next_<Spec>	>,
				boolean_after_loop	< is_bi_last_<Spec>		, end_next_<Spec>	>
			>
		>;

		signature_<Spec> s(o, i1, i2, e2);

		return return_cons_<Spec>(zip_f(s));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	template<typename, typename, typename, typename, typename> struct zip_specification;

	template
	<
		typename OutType, typename OutAttr, typename OutIval, typename OutCdr,
		typename CarInType, typename CarInAttr, typename CarInIval,
			typename CarInCar, typename CarInCdr,
		typename CdrInType, typename CdrInAttr, typename CdrInIval,
			typename CdrInAxis, typename CdrInCar, typename CdrInCdr, typename CdrInPeek,
		typename EndType, typename EndAttr, typename EndCdr, typename EndRCdr,

		typename ActFunction
	>
	struct zip_specification
	<
		_out		< OutType   , OutAttr   , OutIval   , OutCdr						>,
		_car_in		< CarInType , CarInAttr , CarInIval , CarInCar  , CarInCdr				>,
		_cdr_in		< CdrInType , CdrInAttr , CdrInIval , CdrInAxis , CdrInCar , CdrInCdr , CdrInPeek	>,
		_end		< EndType   , EndAttr   , EndCdr    , EndRCdr						>,

		_function	< ActFunction										>
	>
	{
	// out:

		using out_type				= typename OutType::type;
		using out_attr				= typename OutAttr::type;

		using out_obj				= out_object		< out_type , out_attr		>;
		using dout_obj				= obj_to_direct		< out_obj			>;
		using cdout_obj				= obj_to_immutable	< dout_obj			>;

		static constexpr Interval out_ival	= OutIval::value;
		static constexpr auto out_cdr		= iterate<OutCdr::value, out_type>;

	// car in:

		using car_in_type			= typename CdrInType::type;
		using car_in_attr			= typename CdrInAttr::type;

		using car_in_obj			= car_in_object		< car_in_type	, car_in_attr	>;
		using dcar_in_obj			= obj_to_direct		< car_in_obj			>;
		using ccar_in_obj			= obj_to_immutable	< car_in_obj			>;
		using cdcar_in_obj			= obj_to_immutable	< dcar_in_obj			>;

		static constexpr Interval car_in_ival	= CdrInIval::value;
		static constexpr auto car_in_car	= CdrInCar::value;
		static constexpr auto car_in_cdr	= iterate<CdrInCdr::value, car_in_type>;

	// cdr in:

		using cdr_in_type			= typename CdrInType::type;
		using cdr_in_attr			= typename CdrInAttr::type;

		using cdr_in_obj			= cdr_in_object		< cdr_in_type	, cdr_in_attr	>;
		using dcdr_in_obj			= obj_to_direct		< cdr_in_obj			>;
		using ccdr_in_obj			= obj_to_immutable	< cdr_in_obj			>;
		using cdcdr_in_obj			= obj_to_immutable	< dcdr_in_obj			>;

		static constexpr Interval cdr_in_ival	= CdrInIval::value;
		static constexpr Axis cdr_in_axis	= CdrInAxis::value;
		static constexpr auto cdr_in_car	= CdrInCar::value;
		static constexpr auto cdr_in_cdr	= iterate<CdrInCdr::value, cdr_in_type>;
		static constexpr auto cdr_in_peek	= iterate<CdrInPeek::value, cdr_in_type>;

	// end:

		using end_type				= typename EndType::type;
		using end_attr				= typename EndAttr::type;

		using end_obj				= end_object		< end_type	, end_attr	>;
		using dend_obj				= obj_to_direct		< end_obj			>;
		using cdend_obj				= obj_to_immutable	< dend_obj			>;

		static constexpr auto end_cdr		= iterate<EndCdr::value, end_type>;
		static constexpr auto end_rcdr		= iterate<EndRCdr::value, end_type>;

	// signature:

		using signature				= one_cycle_signature
							<
								out_object	< obj_type<out_obj>		>,
								car_in_object	< obj_type<car_in_obj>		>,
								cdr_in_object	< obj_type<cdr_in_obj>		>,
								end_object	< obj_type<end_obj>		>
							>;

	// return:

		using return_type			= out_type;

		static constexpr auto
			return_constructor		= one_cycle_f_out<_id_, dout_obj, signature>;

	// function:

		static constexpr auto act_f		= ActFunction::value;

	// atomic filters:

		static constexpr auto act_function	= one_cycle_biassign
							<
								out_obj, act_f, car_in_car, ccar_in_obj,
										cdr_in_car, ccdr_in_obj, signature
							>;
		static constexpr auto out_next		= one_cycle_assign
							<
								dout_obj, out_cdr, cdout_obj, signature
							>;
		static constexpr auto car_in_next	= one_cycle_assign
							<
								dcar_in_obj, car_in_cdr, cdcar_in_obj, signature
							>;
		static constexpr auto cdr_in_next	= one_cycle_assign
							<
								dcdr_in_obj, cdr_in_cdr, cdcdr_in_obj, signature
							>;
		static constexpr auto end_next		= one_cycle_assign
							<
								dend_obj, end_cdr, cdend_obj, signature
							>;
		static constexpr auto end_previous	= one_cycle_assign
							<
								dend_obj, end_rcdr, cdend_obj, signature
							>;

	// composite filters:

	//	1. For each left endpoint, if open, then iterate.
	//	2. Evaluate the common (closing) loop.
	//	3. If there exists any right endpoint, which is closed, then act/combine.
	//	4. If (3), then for each right endpoint, when open, iterate.

		static constexpr bool in_ival_meet	= or_right_closed	< car_in_ival		, cdr_in_ival		>;
		static constexpr bool ival_meet		= right_closed_or	< out_ival		, in_ival_meet		>;
		static constexpr bool out_ival_meet	= right_open_and	< out_ival		, ival_meet		>;
		static constexpr bool car_in_ival_meet	= right_open_and	< car_in_ival		, ival_meet		>;
		static constexpr bool cdr_in_ival_meet	= right_open_and	< cdr_in_ival		, ival_meet		>;

		static constexpr bool is_unidir		= V_is_unidirectional	< cdr_in_axis					>;
		static constexpr bool is_uni_last	= V_boolean_and		< is_unidir		, cdr_in_ival_meet	>;

		static constexpr bool is_bidir		= V_is_bidirectional	< cdr_in_axis					>;
		static constexpr bool is_bi_last	= V_boolean_and		< is_bidir		, cdr_in_ival_meet	>;

		static constexpr auto end_f		= V_if_then_else
							< is_uni_last		, cdr_in_peek		, _id_			>;
		static constexpr auto loop_predicate	= one_cycle_equals
							<
								end_f, cdcdr_in_obj, cdend_obj, signature
							>;
	};
*/

/***********************************************************************************************************************/

/*
	template
	<
		typename Type,
		auto zip_function,

		auto OutIval		= Interval::closing,
		auto OutDir		= Direction::forward,

		auto CarInIval		= Interval::closing,
		auto CarInDir		= Direction::forward,

		auto CdrInIval		= Interval::closing,
		auto CdrInDir		= Direction::forward,
		auto CdrInRDir		= Direction::backward,
		auto CdrInAxis		= Axis::bidirectional
	>
	using zip_spec			= zip_specification
	<
		_out
		<
			_type		< Type*		>,
			_attr		< rw_iterator	>,
			_ival		< OutIval	>,
			_next		< OutDir	>
		>,

		_car_in
		<
			_type		< Type*		>,
			_attr		< rw_iterator	>,
			_ival		< CarInIval	>,
			_value		< _id_		>,
			_next		< CarInDir	>
		>,

		_cdr_in
		<
			_type		< Type*		>,
			_attr		< rw_iterator	>,
			_ival		< CdrInIval	>,
			_axis		< CdrInAxis	>,
			_value		< _id_		>,
			_next		< CdrInDir	>,
			_peek		< CdrInDir	>
		>,

		_end
		<
			_type		< Type*		>,
			_attr		< rw_iterator	>,
			_next		< CdrInDir	>,
			_prev		< CdrInRDir	>
		>,

		_function
		<
			_act_f		< zip_function	>
		>
	>;
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// fasten:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template<typename Spec>
	return_type_<Spec> fasten(out_type_<Spec> o, car_in_type_<Spec> i1, cdr_in_type_<Spec> i2, end_type_<Spec> e2)
	{
		constexpr auto fasten_f = cycle_inductor
		<
			precycle
			<
				signature_<Spec>,

				boolean_before_loop	< is_bi_last_<Spec>		, end_prev_<Spec>	>,
				interval_before_loop	< out_ival_<Spec>		, out_next_<Spec>	>,
				interval_before_loop	< car_in_ival_<Spec>		, car_in_next_<Spec>	>,
				interval_before_loop	< cdr_in_ival_<Spec>		, cdr_in_next_<Spec>	>

			>, cycle
			<
				signature_<Spec>,

				stem_before_value	< loop_pred_<Spec>		, _id_			>,
				before_act		< act_func_<Spec>					>,
				before_combine		< combine_func_<Spec>					>,
				before_next		< out_next_<Spec>					>,
				before_next		< car_in_next_<Spec>					>,
				before_next		< cdr_in_next_<Spec>					>

			>, postcycle
			<
				signature_<Spec>,

				boolean_after_loop	< ival_meet_<Spec>		, act_func_<Spec>	>,
				boolean_after_loop	< ival_meet_<Spec>		, combine_func_<Spec>	>,
				boolean_after_loop	< out_ival_meet_<Spec>		, out_next_<Spec>	>,
				boolean_after_loop	< car_in_ival_meet_<Spec>	, car_in_next_<Spec>	>,
				boolean_after_loop	< cdr_in_ival_meet_<Spec>	, cdr_in_next_<Spec>	>,
				boolean_after_loop	< is_bi_last_<Spec>		, end_next_<Spec>	>
			>
		>;

		signature_<Spec> s(o, i1, i2, e2);

		return return_cons_<Spec>(fasten_f(s));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	template<typename, typename, typename, typename, typename> struct fasten_specification;

	template
	<
		typename OutType, typename OutAttr, typename OutIval, typename OutCdr,
		typename CarInType, typename CarInAttr, typename CarInIval,
			typename CarInCar, typename CarInCdr,
		typename CdrInType, typename CdrInAttr, typename CdrInIval,
			typename CdrInAxis, typename CdrInCar, typename CdrInCdr, typename CdrInPeek,
		typename EndType, typename EndAttr, typename EndCdr, typename EndRCdr,

		typename ActFunction, typename CombineFunction
	>
	struct fasten_specification
	<
		_out		< OutType   , OutAttr   , OutIval   , OutCdr						>,
		_car_in		< CarInType , CarInAttr , CarInIval , CarInCar  , CarInCdr				>,
		_cdr_in		< CdrInType , CdrInAttr , CdrInIval , CdrInAxis , CdrInCar , CdrInCdr , CdrInPeek	>,
		_end		< EndType   , EndAttr   , EndCdr    , EndRCdr						>,

		_function	< ActFunction , CombineFunction								>
	>
	{
	// out:

		using out_type				= typename OutType::type;
		using out_attr				= typename OutAttr::type;

		using out_obj				= out_object		< out_type , out_attr		>;
		using dout_obj				= obj_to_direct		< out_obj			>;
		using cdout_obj				= obj_to_immutable	< dout_obj			>;

		static constexpr Interval out_ival	= OutIval::value;
		static constexpr auto out_cdr		= iterate<OutCdr::value, out_type>;

	// car in:

		using car_in_type			= typename CdrInType::type;
		using car_in_attr			= typename CdrInAttr::type;

		using car_in_obj			= car_in_object		< car_in_type	, car_in_attr	>;
		using dcar_in_obj			= obj_to_direct		< car_in_obj			>;
		using ccar_in_obj			= obj_to_immutable	< car_in_obj			>;
		using cdcar_in_obj			= obj_to_immutable	< dcar_in_obj			>;

		static constexpr Interval car_in_ival	= CdrInIval::value;
		static constexpr auto car_in_car	= CdrInCar::value;
		static constexpr auto car_in_cdr	= iterate<CdrInCdr::value, car_in_type>;

	// cdr in:

		using cdr_in_type			= typename CdrInType::type;
		using cdr_in_attr			= typename CdrInAttr::type;

		using cdr_in_obj			= cdr_in_object		< cdr_in_type	, cdr_in_attr	>;
		using dcdr_in_obj			= obj_to_direct		< cdr_in_obj			>;
		using ccdr_in_obj			= obj_to_immutable	< cdr_in_obj			>;
		using cdcdr_in_obj			= obj_to_immutable	< dcdr_in_obj			>;

		static constexpr Interval cdr_in_ival	= CdrInIval::value;
		static constexpr Axis cdr_in_axis	= CdrInAxis::value;
		static constexpr auto cdr_in_car	= CdrInCar::value;
		static constexpr auto cdr_in_cdr	= iterate<CdrInCdr::value, cdr_in_type>;
		static constexpr auto cdr_in_peek	= iterate<CdrInPeek::value, cdr_in_type>;

	// end:

		using end_type				= typename EndType::type;
		using end_attr				= typename EndAttr::type;

		using end_obj				= end_object		< end_type	, end_attr	>;
		using dend_obj				= obj_to_direct		< end_obj			>;
		using cdend_obj				= obj_to_immutable	< dend_obj			>;

		static constexpr auto end_cdr		= iterate<EndCdr::value, end_type>;
		static constexpr auto end_rcdr		= iterate<EndRCdr::value, end_type>;

	// aux:

		using aux_type				= f_cdr_in_type<CombineFunction::value>;
		using aux_attr				= stationary_attr<Mutability::variable>;

		using aux_obj				= aux_object		< aux_type	, aux_attr	>;

	// signature:

		using signature				= one_cycle_signature
							<
								out_object	< obj_type<out_obj>		>,
								car_in_object	< obj_type<car_in_obj>		>,
								cdr_in_object	< obj_type<cdr_in_obj>		>,
								end_object	< obj_type<end_obj>		>,
								aux_object	< obj_type<aux_obj>		>
							>;

	// return:

		using return_type			= out_type;

		static constexpr auto
			return_constructor		= one_cycle_f_out<_id_, dout_obj, signature>;

	// function:

		static constexpr auto act_f		= ActFunction::value;
		static constexpr auto combine_f		= CombineFunction::value;

	// atomic filters:

		static constexpr auto act_function	= one_cycle_biassign
							<
								out_obj, act_f, car_in_car, ccar_in_obj,
										cdr_in_car, ccdr_in_obj, signature
							>;
		static constexpr auto combine_function	= one_cycle_biassign
							<
								out_obj, combine_f, _id_, out_obj,
											_id_, aux_obj, signature
							>;
		static constexpr auto out_next		= one_cycle_assign
							<
								dout_obj, out_cdr, cdout_obj, signature
							>;
		static constexpr auto car_in_next	= one_cycle_assign
							<
								dcar_in_obj, car_in_cdr, cdcar_in_obj, signature
							>;
		static constexpr auto cdr_in_next	= one_cycle_assign
							<
								dcdr_in_obj, cdr_in_cdr, cdcdr_in_obj, signature
							>;
		static constexpr auto end_next		= one_cycle_assign
							<
								dend_obj, end_cdr, cdend_obj, signature
							>;
		static constexpr auto end_previous	= one_cycle_assign
							<
								dend_obj, end_rcdr, cdend_obj, signature
							>;

	// composite filters:

	//	1. For each left endpoint, if open, then iterate.
	//	2. Evaluate the common (closing) loop.
	//	3. If there exists any right endpoint, which is closed, then act/combine.
	//	4. If (3), then for each right endpoint, when open, iterate.

		static constexpr bool in_ival_meet	= or_right_closed	< car_in_ival		, cdr_in_ival		>;
		static constexpr bool ival_meet		= right_closed_or	< out_ival		, in_ival_meet		>;
		static constexpr bool out_ival_meet	= right_open_and	< out_ival		, ival_meet		>;
		static constexpr bool car_in_ival_meet	= right_open_and	< car_in_ival		, ival_meet		>;
		static constexpr bool cdr_in_ival_meet	= right_open_and	< cdr_in_ival		, ival_meet		>;

		static constexpr bool is_unidir		= V_is_unidirectional	< cdr_in_axis					>;
		static constexpr bool is_uni_last	= V_boolean_and		< is_unidir		, cdr_in_ival_meet	>;

		static constexpr bool is_bidir		= V_is_bidirectional	< cdr_in_axis					>;
		static constexpr bool is_bi_last	= V_boolean_and		< is_bidir		, cdr_in_ival_meet	>;

		static constexpr auto end_f		= V_if_then_else
							< is_uni_last		, cdr_in_peek		, _id_			>;
		static constexpr auto loop_predicate	= one_cycle_equals
							<
								end_f, cdcdr_in_obj, cdend_obj, signature
							>;
	};
*/

/***********************************************************************************************************************/

/*
	template
	<
		typename Type,
		auto zip_function,
		auto carry_function,

		auto OutIval		= Interval::closing,
		auto OutDir		= Direction::forward,

		auto CarInIval		= Interval::closing,
		auto CarInDir		= Direction::forward,

		auto CdrInIval		= Interval::closing,
		auto CdrInDir		= Direction::forward,
		auto CdrInRDir		= Direction::backward,
		auto CdrInAxis		= Axis::bidirectional
	>
	using fasten_spec		= zip_specification
	<
		_out
		<
			_type		< Type*			>,
			_attr		< rw_iterator		>,
			_ival		< OutIval		>,
			_next		< OutDir		>
		>,

		_car_in
		<
			_type		< Type*			>,
			_attr		< rw_iterator		>,
			_ival		< CarInIval		>,
			_value		< _id_			>,
			_next		< CarInDir		>
		>,

		_cdr_in
		<
			_type		< Type*			>,
			_attr		< rw_iterator		>,
			_ival		< CdrInIval		>,
			_axis		< CdrInAxis		>,
			_value		< _id_			>,
			_next		< CdrInDir		>,
			_peek		< CdrInDir		>
		>,

		_end
		<
			_type		< Type*			>,
			_attr		< rw_iterator		>,
			_next		< CdrInDir		>,
			_prev		< CdrInRDir		>
		>,

		_function
		<
			_act_f		< zip_function		>,
			_combine_f	< carry_function	>
		>
	>;
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// glide (bifold):

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template<typename Spec>
	return_type_<Spec> glide(out_type_<Spec> o, car_in_type_<Spec> i1, cdr_in_type_<Spec> i2, end_type_<Spec> e2)
	{
		constexpr auto glide_f = cycle_inductor
		<
			precycle
			<
				signature_<Spec>,

				boolean_before_loop	< is_bi_last_<Spec>		, end_prev_<Spec>	>,
				interval_before_loop	< car_in_ival_<Spec>		, car_in_next_<Spec>	>,
				interval_before_loop	< cdr_in_ival_<Spec>		, cdr_in_next_<Spec>	>

			>, cycle
			<
				signature_<Spec>,

				stem_before_value	< loop_pred_<Spec>		, _id_			>,
				before_act		< act_func_<Spec>					>,
				before_combine		< combine_func_<Spec>					>,
				before_next		< car_in_next_<Spec>					>,
				before_next		< cdr_in_next_<Spec>					>

			>, postcycle
			<
				signature_<Spec>,

				boolean_after_loop	< ival_meet_<Spec>		, act_func_<Spec>	>,
				boolean_after_loop	< ival_meet_<Spec>		, combine_func_<Spec>	>,
				boolean_after_loop	< car_in_ival_meet_<Spec>	, car_in_next_<Spec>	>,
				boolean_after_loop	< cdr_in_ival_meet_<Spec>	, cdr_in_next_<Spec>	>,
				boolean_after_loop	< is_bi_last_<Spec>		, end_next_<Spec>	>
			>
		>;

		signature_<Spec> s(o, i1, i2, e2);

		return return_cons_<Spec>(glide_f(s));
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	template<typename, typename, typename, typename, typename> struct glide_specification;

	template
	<
		typename OutType, typename OutAttr,
		typename CarInType, typename CarInAttr, typename CarInIval,
			typename CarInCar, typename CarInCdr,
		typename CdrInType, typename CdrInAttr, typename CdrInIval,
			typename CdrInAxis, typename CdrInCar, typename CdrInCdr, typename CdrInPeek,
		typename EndType, typename EndAttr, typename EndCdr, typename EndRCdr,

		typename ActFunction, typename CombineFunction
	>
	struct glide_specification
	<
		_out		< OutType   , OutAttr									>,
		_car_in		< CarInType , CarInAttr , CarInIval , CarInCar  , CarInCdr				>,
		_cdr_in		< CdrInType , CdrInAttr , CdrInIval , CdrInAxis , CdrInCar , CdrInCdr , CdrInPeek	>,
		_end		< EndType   , EndAttr   , EndCdr    , EndRCdr						>,

		_function	< ActFunction , CombineFunction								>
	>
	{
	// out:

		using out_type				= typename OutType::type;
		using out_attr				= typename OutAttr::type;

		using out_obj				= out_object		< out_type , out_attr		>;
		using dout_obj				= obj_to_direct		< out_obj			>;

	// car in:

		using car_in_type			= typename CdrInType::type;
		using car_in_attr			= typename CdrInAttr::type;

		using car_in_obj			= car_in_object		< car_in_type	, car_in_attr	>;
		using dcar_in_obj			= obj_to_direct		< car_in_obj			>;
		using ccar_in_obj			= obj_to_immutable	< car_in_obj			>;
		using cdcar_in_obj			= obj_to_immutable	< dcar_in_obj			>;

		static constexpr Interval car_in_ival	= CdrInIval::value;
		static constexpr auto car_in_car	= CdrInCar::value;
		static constexpr auto car_in_cdr	= iterate<CdrInCdr::value, car_in_type>;

	// cdr in:

		using cdr_in_type			= typename CdrInType::type;
		using cdr_in_attr			= typename CdrInAttr::type;

		using cdr_in_obj			= cdr_in_object		< cdr_in_type	, cdr_in_attr	>;
		using dcdr_in_obj			= obj_to_direct		< cdr_in_obj			>;
		using ccdr_in_obj			= obj_to_immutable	< cdr_in_obj			>;
		using cdcdr_in_obj			= obj_to_immutable	< dcdr_in_obj			>;

		static constexpr Interval cdr_in_ival	= CdrInIval::value;
		static constexpr Axis cdr_in_axis	= CdrInAxis::value;
		static constexpr auto cdr_in_car	= CdrInCar::value;
		static constexpr auto cdr_in_cdr	= iterate<CdrInCdr::value, cdr_in_type>;
		static constexpr auto cdr_in_peek	= iterate<CdrInPeek::value, cdr_in_type>;

	// end:

		using end_type				= typename EndType::type;
		using end_attr				= typename EndAttr::type;

		using end_obj				= end_object		< end_type	, end_attr	>;
		using dend_obj				= obj_to_direct		< end_obj			>;
		using cdend_obj				= obj_to_immutable	< dend_obj			>;

		static constexpr auto end_cdr		= iterate<EndCdr::value, end_type>;
		static constexpr auto end_rcdr		= iterate<EndRCdr::value, end_type>;

	// aux:

		using aux_type				= f_cdr_in_type<CombineFunction::value>;
		using aux_attr				= stationary_attr<Mutability::variable>;

		using aux_obj				= aux_object		< aux_type	, aux_attr	>;

	// signature:

		using signature				= one_cycle_signature
							<
								out_object	< obj_type<out_obj>		>,
								car_in_object	< obj_type<car_in_obj>		>,
								cdr_in_object	< obj_type<cdr_in_obj>		>,
								end_object	< obj_type<end_obj>		>,
								aux_object	< obj_type<aux_obj>		>
							>;

	// return:

		using return_type			= out_type;

		static constexpr auto
			return_constructor		= one_cycle_f_out<_id_, dout_obj, signature>;

	// function:

		static constexpr auto act_f		= ActFunction::value;
		static constexpr auto combine_f		= CombineFunction::value;

	// atomic filters:

		static constexpr auto act_function	= one_cycle_biassign
							<
								aux_obj, act_f, car_in_car, ccar_in_obj,
										cdr_in_car, ccdr_in_obj, signature
							>;
		static constexpr auto combine_function	= one_cycle_biassign
							<
								out_obj, combine_f, _id_, out_obj,
											_id_, aux_obj, signature
							>;
		static constexpr auto car_in_next	= one_cycle_assign
							<
								dcar_in_obj, car_in_cdr, cdcar_in_obj, signature
							>;
		static constexpr auto cdr_in_next	= one_cycle_assign
							<
								dcdr_in_obj, cdr_in_cdr, cdcdr_in_obj, signature
							>;
		static constexpr auto end_next		= one_cycle_assign
							<
								dend_obj, end_cdr, cdend_obj, signature
							>;
		static constexpr auto end_previous	= one_cycle_assign
							<
								dend_obj, end_rcdr, cdend_obj, signature
							>;

	// composite filters:

	//	1. For each left endpoint, if open, then iterate.
	//	2. Evaluate the common (closing) loop.
	//	3. If there exists any right endpoint, which is closed, then act/combine.
	//	4. If (3), then for each right endpoint, when open, iterate.

		static constexpr bool ival_meet		= or_right_closed	< car_in_ival		, cdr_in_ival		>;
		static constexpr bool car_in_ival_meet	= right_open_and	< car_in_ival		, ival_meet		>;
		static constexpr bool cdr_in_ival_meet	= right_open_and	< cdr_in_ival		, ival_meet		>;

		static constexpr bool is_unidir		= V_is_unidirectional	< cdr_in_axis					>;
		static constexpr bool is_uni_last	= V_boolean_and		< is_unidir		, cdr_in_ival_meet	>;

		static constexpr bool is_bidir		= V_is_bidirectional	< cdr_in_axis					>;
		static constexpr bool is_bi_last	= V_boolean_and		< is_bidir		, cdr_in_ival_meet	>;

		static constexpr auto end_f		= V_if_then_else
							< is_uni_last		, cdr_in_peek		, _id_			>;
		static constexpr auto loop_predicate	= one_cycle_equals
							<
								end_f, cdcdr_in_obj, cdend_obj, signature
							>;
	};
*/

/***********************************************************************************************************************/

/*
	template
	<
		typename Type,
		auto glide_function,
		auto zip_function,

		auto CarInIval		= Interval::closing,
		auto CarInDir		= Direction::forward,

		auto CdrInIval		= Interval::closing,
		auto CdrInDir		= Direction::forward,
		auto CdrInRDir		= Direction::backward,
		auto CdrInAxis		= Axis::bidirectional
	>
	using glide_spec		= glide_specification
	<
		_out
		<
			_type		< Type		>,
			_attr		< rw_constant	>
		>,

		_car_in
		<
			_type		< Type*			>,
			_attr		< rw_iterator		>,
			_ival		< CarInIval		>,
			_value		< _id_			>,
			_next		< CarInDir		>
		>,

		_cdr_in
		<
			_type		< Type*			>,
			_attr		< rw_iterator		>,
			_ival		< CdrInIval		>,
			_axis		< CdrInAxis		>,
			_value		< _id_			>,
			_next		< CdrInDir		>,
			_peek		< CdrInDir		>
		>,

		_end
		<
			_type		< Type*			>,
			_attr		< rw_iterator		>,
			_next		< CdrInDir		>,
			_prev		< CdrInRDir		>
		>,

		_function
		<
			_act_f		< zip_function		>,
			_combine_f	< glide_function 	>
		>
	>;
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

