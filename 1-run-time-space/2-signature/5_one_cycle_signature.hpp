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

// one cycle signature:

/*
	filters (accessors):

		i(...) - identity
		d(...) - dereference
*/

/***********************************************************************************************************************/

namespace nlfs_5
{
	using namespace nlfs_4;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// objects:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// members:

/***********************************************************************************************************************/

	enum struct OneCycleMember
	{
		out,
		in,
		car_in,
		cdr_in,
		end,
		aux,
		msg,

		dimension // filler
	};

	template<OneCycleMember m> constexpr bool V_is_out		= (m == OneCycleMember::out);
	template<OneCycleMember m> constexpr bool V_is_in		= (m == OneCycleMember::in);
	template<OneCycleMember m> constexpr bool V_is_car_in		= (m == OneCycleMember::car_in);
	template<OneCycleMember m> constexpr bool V_is_cdr_in		= (m == OneCycleMember::cdr_in);
	template<OneCycleMember m> constexpr bool V_is_end		= (m == OneCycleMember::end);
	template<OneCycleMember m> constexpr bool V_is_aux		= (m == OneCycleMember::aux);
	template<OneCycleMember m> constexpr bool V_is_msg		= (m == OneCycleMember::msg);

	template<OneCycleMember m, auto> using S_is_out			= S_boolean<V_is_out<m>>;
	template<OneCycleMember m, auto> using S_is_in			= S_boolean<V_is_in<m>>;
	template<OneCycleMember m, auto> using S_is_car_in		= S_boolean<V_is_car_in<m>>;
	template<OneCycleMember m, auto> using S_is_cdr_in		= S_boolean<V_is_cdr_in<m>>;
	template<OneCycleMember m, auto> using S_is_end			= S_boolean<V_is_end<m>>;
	template<OneCycleMember m, auto> using S_is_aux			= S_boolean<V_is_aux<m>>;
	template<OneCycleMember m, auto> using S_is_msg			= S_boolean<V_is_msg<m>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// attribute specifications:

/***********************************************************************************************************************/

	template
	<
		OneCycleMember Member,
		Interval Ival
	>
	struct _one_cycle_object_attributes
	{
		static constexpr OneCycleMember member			= Member;
		static constexpr Interval interval			= Ival;
	};

	//

	using _out_obj_attr				= _one_cycle_object_attributes < OneCycleMember::out    >;
	using _in_obj_attr				= _one_cycle_object_attributes < OneCycleMember::in     >;
	using _car_in_obj_attr				= _one_cycle_object_attributes < OneCycleMember::car_in >;
	using _cdr_in_obj_attr				= _one_cycle_object_attributes < OneCycleMember::cdr_in >;
	using _end_obj_attr				= _one_cycle_object_attributes < OneCycleMember::end    >;
	using _aux_obj_attr				= _one_cycle_object_attributes < OneCycleMember::aux    >;
	using _msg_obj_attr				= _one_cycle_object_attributes < OneCycleMember::msg    >;

/***********************************************************************************************************************/

	template<typename OneCycleAttrSpec>
		constexpr OneCycleMember one_cycle_attr_member		= OneCycleAttrSpec::member;

	template<typename OneCycleAttrSpec>
		constexpr Interval one_cycle_attr_ival			= OneCycleAttrSpec::interval;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// object specifications:

/***********************************************************************************************************************/

	template<typename Type> using _out_object			= _object < Type , _out_obj_attr    >;
	template<typename Type> using _in_object			= _object < Type , _in_obj_attr     >;
	template<typename Type> using _car_in_object			= _object < Type , _car_in_obj_attr >;
	template<typename Type> using _cdr_in_object			= _object < Type , _cdr_in_obj_attr >;
	template<typename Type> using _end_object			= _object < Type , _end_obj_attr    >;
	template<typename Type> using _aux_object			= _object < Type , _aux_obj_attr    >;
	template<typename Type> using _msg_object			= _object < Type , _msg_obj_attr    >;

	template<auto U = U_void, auto A = U_void> using out_obj_UxU	= _out_object    < T_type_U<U> , T_type_U<A> >;
	template<auto U = U_void, auto A = U_void> using in_obj_UxU	= _in_object     < T_type_U<U> , T_type_U<A> >;
	template<auto U = U_void, auto A = U_void> using car_in_obj_UxU	= _car_in_object < T_type_U<U> , T_type_U<A> >;
	template<auto U = U_void, auto A = U_void> using cdr_in_obj_UxU	= _cdr_in_object < T_type_U<U> , T_type_U<A> >;
	template<auto U = U_void, auto A = U_void> using end_obj_UxU	= _end_object    < T_type_U<U> , T_type_U<A> >;
	template<auto U = U_void, auto A = U_void> using aux_obj_UxU	= _aux_object    < T_type_U<U> , T_type_U<A> >;
	template<auto U = U_void, auto A = U_void> using msg_obj_UxU	= _msg_object    < T_type_U<U> , T_type_U<A> >;

/***********************************************************************************************************************/

	template<typename OneCycleObjSpec>
		constexpr OneCycleMember one_cycle_member		= one_cycle_attr_member<obj_attr<OneCycleObjSpec>>;

	template<typename OneCycleObjSpec>
		constexpr Interval one_cycle_ival			= one_cycle_attr_ival<obj_attr<OneCycleObjSpec>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// signature specifications:

/***********************************************************************************************************************/

	template<typename...> struct one_cycle_signature;

/***********************************************************************************************************************/

	template
	<
		typename OutType,
		typename EndType
	>
	struct one_cycle_signature
	<
		_out_object<OutType, void>,
		_end_object<EndType, void>
	>
	{
		OutType out;
		EndType end;

		one_cycle_signature(OutType o, EndType e)							:
			out(o), end(e)										{ }
	};

/***********************************************************************************************************************/

	template
	<
		typename OutType,
		typename InType,
		typename EndType
	>
	struct one_cycle_signature
	<
		_out_object<OutType, void>,
		_in_object<InType, void>,
		_end_object<EndType, void>
	>
	{
		OutType out;
		InType in;
		EndType end;

		one_cycle_signature(OutType o, InType i, EndType e)						:
			out(o), in(i), end(e)									{ }
	};

/***********************************************************************************************************************/

	template
	<
		typename OutType,
		typename CarInType,
		typename CdrInType,
		typename EndType
	>
	struct one_cycle_signature
	<
		_out_object<OutType, void>,
		_car_in_object<CarInType, void>,
		_cdr_in_object<CdrInType, void>,
		_end_object<EndType, void>
	>
	{
		OutType out;
		CarInType car_in;
		CdrInType cdr_in;
		EndType end;

		one_cycle_signature(OutType o, CarInType i1, CdrInType i2, EndType e)				:
			out(o), car_in(i1), cdr_in(i2), end(e)							{ }
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template
	<
		typename OutType,
		typename EndType,
		typename MsgType
	>
	struct one_cycle_signature
	<
		_out_object<OutType, void>,
		_end_object<EndType, void>,
		_msg_object<MsgType, void>
	>
	{
		OutType out;
		EndType end;
		MsgType msg;

		one_cycle_signature(OutType o, EndType e)							:
			out(o), end(e)										{ }
		one_cycle_signature(OutType o, EndType e, MsgType m)						:
			out(o), end(e), msg(m)									{ }
	};

/***********************************************************************************************************************/

	template
	<
		typename OutType,
		typename InType,
		typename EndType,
		typename MsgType
	>
	struct one_cycle_signature
	<
		_out_object<OutType, void>,
		_in_object<InType, void>,
		_end_object<EndType, void>,
		_msg_object<MsgType, void>
	>
	{
		OutType out;
		InType in;
		EndType end;
		MsgType msg;

		one_cycle_signature(OutType o, InType i, EndType e)						:
			out(o), in(i), end(e)									{ }
		one_cycle_signature(OutType o, InType i, EndType e, MsgType m)					:
			out(o), in(i), end(e), msg(m)								{ }
	};

/***********************************************************************************************************************/

	template
	<
		typename OutType,
		typename CarInType,
		typename CdrInType,
		typename EndType,
		typename MsgType
	>
	struct one_cycle_signature
	<
		_out_object<OutType, void>,
		_car_in_object<CarInType, void>,
		_cdr_in_object<CdrInType, void>,
		_end_object<EndType, void>,
		_msg_object<MsgType, void>
	>
	{
		OutType out;
		CarInType car_in;
		CdrInType cdr_in;
		EndType end;
		MsgType msg;

		one_cycle_signature(OutType o, CarInType i1, CdrInType i2, EndType e)				:
			out(o), car_in(i1), cdr_in(i2), end(e)							{ }
		one_cycle_signature(OutType o, CarInType i1, CdrInType i2, EndType e, MsgType m)		:
			out(o), car_in(i1), cdr_in(i2), end(e), msg(m)						{ }
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template
	<
		typename OutType,
		typename EndType,
		typename AuxType
	>
	struct one_cycle_signature
	<
		_out_object<OutType, void>,
		_end_object<EndType, void>,
		_aux_object<AuxType, void>
	>
	{
		OutType out;
		EndType end;
		AuxType aux;

		one_cycle_signature(OutType o, EndType e)							:
			out(o), end(e)										{ }
		one_cycle_signature(OutType o, EndType e, AuxType a)						:
			out(o), end(e), aux(a)									{ }
	};

/***********************************************************************************************************************/

	template
	<
		typename OutType,
		typename InType,
		typename EndType,
		typename AuxType
	>
	struct one_cycle_signature
	<
		_out_object<OutType, void>,
		_in_object<InType, void>,
		_end_object<EndType, void>,
		_aux_object<AuxType, void>
	>
	{
		OutType out;
		InType in;
		EndType end;
		AuxType aux;

		one_cycle_signature(OutType o, InType i, EndType e)						:
			out(o), in(i), end(e)									{ }
		one_cycle_signature(OutType o, InType i, EndType e, AuxType a)					:
			out(o), in(i), end(e), aux(a)								{ }
	};

/***********************************************************************************************************************/

	template
	<
		typename OutType,
		typename CarInType,
		typename CdrInType,
		typename EndType,
		typename AuxType
	>
	struct one_cycle_signature
	<
		_out_object<OutType, void>,
		_car_in_object<CarInType, void>,
		_cdr_in_object<CdrInType, void>,
		_end_object<EndType, void>,
		_aux_object<AuxType, void>
	>
	{
		OutType out;
		CarInType car_in;
		CdrInType cdr_in;
		EndType end;
		AuxType aux;

		one_cycle_signature(OutType o, CarInType i1, CdrInType i2, EndType e)				:
			out(o), car_in(i1), cdr_in(i2), end(e)							{ }
		one_cycle_signature(OutType o, CarInType i1, CdrInType i2, EndType e, AuxType a)		:
			out(o), car_in(i1), cdr_in(i2), end(e), aux(a)						{ }
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template
	<
		typename OutType,
		typename EndType,
		typename AuxType,
		typename MsgType
	>
	struct one_cycle_signature
	<
		_out_object<OutType, void>,
		_end_object<EndType, void>,
		_aux_object<AuxType, void>,
		_msg_object<MsgType, void>
	>
	{
		OutType out;
		EndType end;
		AuxType aux;
		MsgType msg;

		one_cycle_signature(OutType o, EndType e)							:
			out(o), end(e)										{ }
		one_cycle_signature(OutType o, EndType e, MsgType m)						:
			out(o), end(e), msg(m)									{ }
		one_cycle_signature(OutType o, EndType e, AuxType a)						:
			out(o), end(e), aux(a)									{ }
		one_cycle_signature(OutType o, EndType e, AuxType a, MsgType m)					:
			out(o), end(e), aux(a), msg(m)								{ }
	};

/***********************************************************************************************************************/

	template
	<
		typename OutType,
		typename InType,
		typename EndType,
		typename AuxType,
		typename MsgType
	>
	struct one_cycle_signature
	<
		_out_object<OutType, void>,
		_in_object<InType, void>,
		_end_object<EndType, void>,
		_aux_object<AuxType, void>,
		_msg_object<MsgType, void>
	>
	{
		OutType out;
		InType in;
		EndType end;
		AuxType aux;
		MsgType msg;

		one_cycle_signature(OutType o, InType i, EndType e)						:
			out(o), in(i), end(e)									{ }
		one_cycle_signature(OutType o, InType i, EndType e, MsgType m)					:
			out(o), in(i), end(e), msg(m)								{ }
		one_cycle_signature(OutType o, InType i, EndType e, AuxType a)					:
			out(o), in(i), end(e), aux(a)								{ }
		one_cycle_signature(OutType o, InType i, EndType e, AuxType a, MsgType m)			:
			out(o), in(i), end(e), aux(a), msg(m)							{ }
	};

/***********************************************************************************************************************/

	template
	<
		typename OutType,
		typename CarInType,
		typename CdrInType,
		typename EndType,
		typename AuxType,
		typename MsgType
	>
	struct one_cycle_signature
	<
		_out_object<OutType, void>,
		_car_in_object<CarInType, void>,
		_cdr_in_object<CdrInType, void>,
		_end_object<EndType, void>,
		_aux_object<AuxType, void>,
		_msg_object<MsgType, void>
	>
	{
		OutType out;
		CarInType car_in;
		CdrInType cdr_in;
		EndType end;
		AuxType aux;
		MsgType msg;

		one_cycle_signature(OutType o, CarInType i1, CdrInType i2, EndType e)				:
			out(o), car_in(i1), cdr_in(i2), end(e)							{ }
		one_cycle_signature(OutType o, CarInType i1, CdrInType i2, EndType e, MsgType m)		:
			out(o), car_in(i1), cdr_in(i2), end(e), msg(m)						{ }
		one_cycle_signature(OutType o, CarInType i1, CdrInType i2, EndType e, AuxType a)		:
			out(o), car_in(i1), cdr_in(i2), end(e), aux(a)						{ }
		one_cycle_signature(OutType o, CarInType i1, CdrInType i2, EndType e, AuxType a, MsgType m)	:
			out(o), car_in(i1), cdr_in(i2), end(e), aux(a), msg(m)					{ }
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// procedures:

	// Must not contradict iterator traits.
	// Design to be interoperable with iterator traits.
	// Policy functions require const input (no side effects)

/***********************************************************************************************************************/

// out:

	// kernel:

		template<typename OneCycle>
		constexpr auto & one_cycle_dout(OneCycle & arg)			{ return arg.out; }

		template<typename OneCycle>
		constexpr auto & one_cycle_iout(OneCycle & arg)			{ return *arg.out; }

		// (const):

		template<typename OneCycle>
		constexpr const auto & one_cycle_cdout(const OneCycle & arg)	{ return arg.out; }

		template<typename OneCycle>
		constexpr const auto & one_cycle_ciout(const OneCycle & arg)	{ return *arg.out; }

		//

		template<auto f, auto M> using return_one_cycle_f_dout		= S_compose_opt<f, one_cycle_dout<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_iout		= S_compose_opt<f, one_cycle_iout<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_cdout		= S_compose_opt<f, one_cycle_cdout<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_ciout		= S_compose_opt<f, one_cycle_ciout<T_type_U<M>>>;

	// generic:

		template<auto f, typename ObjSpec, typename OneCycle>
		constexpr auto one_cycle_f_out = V_colist_Bs
		<
			obj_denote<ObjSpec>, obj_mutate<ObjSpec>,		f, U_type_T<OneCycle>,

			S_is_direct_variable,					return_one_cycle_f_dout,
			S_is_indirect_variable,					return_one_cycle_f_iout,
			S_is_direct_immutable,					return_one_cycle_f_cdout,
			S_is_indirect_immutable,				return_one_cycle_f_ciout
		>;

/***********************************************************************************************************************/

// in:

	// kernel:

		template<typename OneCycle>
		constexpr auto & one_cycle_din(OneCycle & arg)			{ return arg.in; }

		template<typename OneCycle>
		constexpr auto & one_cycle_iin(OneCycle & arg)			{ return *arg.in; }

		// (const):

		template<typename OneCycle>
		constexpr const auto & one_cycle_cdin(const OneCycle & arg)	{ return arg.in; }

		template<typename OneCycle>
		constexpr const auto & one_cycle_ciin(const OneCycle & arg)	{ return *arg.in; }

		//

		template<auto f, auto M> using return_one_cycle_f_din		= S_compose_opt<f, one_cycle_din<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_iin		= S_compose_opt<f, one_cycle_iin<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_cdin		= S_compose_opt<f, one_cycle_cdin<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_ciin		= S_compose_opt<f, one_cycle_ciin<T_type_U<M>>>;

	// generic:

		template<auto f, typename ObjSpec, typename OneCycle>
		constexpr auto one_cycle_f_in = V_colist_Bs
		<
			obj_denote<ObjSpec>, obj_mutate<ObjSpec>,		f, U_type_T<OneCycle>,

			S_is_direct_variable,					return_one_cycle_f_din,
			S_is_indirect_variable,					return_one_cycle_f_iin,
			S_is_direct_immutable,					return_one_cycle_f_cdin,
			S_is_indirect_immutable,				return_one_cycle_f_ciin
		>;

/***********************************************************************************************************************/

// car in:

	// kernel:

		template<typename OneCycle>
		constexpr auto & one_cycle_dcar_in(OneCycle & arg)		{ return arg.car_in; }

		template<typename OneCycle>
		constexpr auto & one_cycle_icar_in(OneCycle & arg)		{ return *arg.car_in; }

		// (const):

		template<typename OneCycle>
		constexpr const auto & one_cycle_cdcar_in(const OneCycle & arg)	{ return arg.car_in; }

		template<typename OneCycle>
		constexpr const auto & one_cycle_cicar_in(const OneCycle & arg)	{ return *arg.car_in; }

		//

		template<auto f, auto M> using return_one_cycle_f_dcar_in	= S_compose_opt<f, one_cycle_dcar_in<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_icar_in	= S_compose_opt<f, one_cycle_icar_in<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_cdcar_in	= S_compose_opt<f, one_cycle_cdcar_in<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_cicar_in	= S_compose_opt<f, one_cycle_cicar_in<T_type_U<M>>>;

	// generic:

		template<auto f, typename ObjSpec, typename OneCycle>
		constexpr auto one_cycle_f_car_in = V_colist_Bs
		<
			obj_denote<ObjSpec>, obj_mutate<ObjSpec>,		f, U_type_T<OneCycle>,

			S_is_direct_variable,					return_one_cycle_f_dcar_in,
			S_is_indirect_variable,					return_one_cycle_f_icar_in,
			S_is_direct_immutable,					return_one_cycle_f_cdcar_in,
			S_is_indirect_immutable,				return_one_cycle_f_cicar_in
		>;

/***********************************************************************************************************************/

// cdr in:

	// kernel:

		template<typename OneCycle>
		constexpr auto & one_cycle_dcdr_in(OneCycle & arg)		{ return arg.cdr_in; }

		template<typename OneCycle>
		constexpr auto & one_cycle_icdr_in(OneCycle & arg)		{ return *arg.cdr_in; }

		// (const):

		template<typename OneCycle>
		constexpr const auto & one_cycle_cdcdr_in(const OneCycle & arg)	{ return arg.cdr_in; }

		template<typename OneCycle>
		constexpr const auto & one_cycle_cicdr_in(const OneCycle & arg)	{ return *arg.cdr_in; }

		//

		template<auto f, auto M> using return_one_cycle_f_dcdr_in	= S_compose_opt<f, one_cycle_dcdr_in<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_icdr_in	= S_compose_opt<f, one_cycle_icdr_in<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_cdcdr_in	= S_compose_opt<f, one_cycle_cdcdr_in<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_cicdr_in	= S_compose_opt<f, one_cycle_cicdr_in<T_type_U<M>>>;

	// generic:

		template<auto f, typename ObjSpec, typename OneCycle>
		constexpr auto one_cycle_f_cdr_in = V_colist_Bs
		<
			obj_denote<ObjSpec>, obj_mutate<ObjSpec>,		f, U_type_T<OneCycle>,

			S_is_direct_variable,					return_one_cycle_f_dcdr_in,
			S_is_indirect_variable,					return_one_cycle_f_icdr_in,
			S_is_direct_immutable,					return_one_cycle_f_cdcdr_in,
			S_is_indirect_immutable,				return_one_cycle_f_cicdr_in
		>;

/***********************************************************************************************************************/

// end:

	// kernel:

		template<typename OneCycle>
		constexpr auto & one_cycle_dend(OneCycle & arg)			{ return arg.end; }

		template<typename OneCycle>
		constexpr auto & one_cycle_iend(OneCycle & arg)			{ return *arg.end; }

		// (const):

		template<typename OneCycle>
		constexpr const auto & one_cycle_cdend(const OneCycle & arg)	{ return arg.end; }

		template<typename OneCycle>
		constexpr const auto & one_cycle_ciend(const OneCycle & arg)	{ return *arg.end; }

		//

		template<auto f, auto M> using return_one_cycle_f_dend		= S_compose_opt<f, one_cycle_dend<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_iend		= S_compose_opt<f, one_cycle_iend<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_cdend		= S_compose_opt<f, one_cycle_cdend<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_ciend		= S_compose_opt<f, one_cycle_ciend<T_type_U<M>>>;

	// generic:

		template<auto f, typename ObjSpec, typename OneCycle>
		constexpr auto one_cycle_f_end = V_colist_Bs
		<
			obj_denote<ObjSpec>, obj_mutate<ObjSpec>,		f, U_type_T<OneCycle>,

			S_is_direct_variable,					return_one_cycle_f_dend,
			S_is_indirect_variable,					return_one_cycle_f_iend,
			S_is_direct_immutable,					return_one_cycle_f_cdend,
			S_is_indirect_immutable,				return_one_cycle_f_ciend
		>;

/***********************************************************************************************************************/

// aux:

	// kernel:

		template<typename OneCycle>
		constexpr auto & one_cycle_daux(OneCycle & arg)			{ return arg.aux; }

		template<typename OneCycle>
		constexpr auto & one_cycle_iaux(OneCycle & arg)			{ return *arg.aux; }

		// (const):

		template<typename OneCycle>
		constexpr const auto & one_cycle_cdaux(const OneCycle & arg)	{ return arg.aux; }

		template<typename OneCycle>
		constexpr const auto & one_cycle_ciaux(const OneCycle & arg)	{ return *arg.aux; }

		//

		template<auto f, auto M> using return_one_cycle_f_daux		= S_compose_opt<f, one_cycle_daux<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_iaux		= S_compose_opt<f, one_cycle_iaux<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_cdaux		= S_compose_opt<f, one_cycle_cdaux<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_ciaux		= S_compose_opt<f, one_cycle_ciaux<T_type_U<M>>>;

	// generic:

		template<auto f, typename ObjSpec, typename OneCycle>
		constexpr auto one_cycle_f_aux = V_colist_Bs
		<
			obj_denote<ObjSpec>, obj_mutate<ObjSpec>,		f, U_type_T<OneCycle>,

			S_is_direct_variable,					return_one_cycle_f_daux,
			S_is_indirect_variable,					return_one_cycle_f_iaux,
			S_is_direct_immutable,					return_one_cycle_f_cdaux,
			S_is_indirect_immutable,				return_one_cycle_f_ciaux
		>;

/***********************************************************************************************************************/

// msg:

	// kernel:

		template<typename OneCycle>
		constexpr auto & one_cycle_dmsg(OneCycle & arg)			{ return arg.msg; }

		template<typename OneCycle>
		constexpr auto & one_cycle_imsg(OneCycle & arg)			{ return *arg.msg; }

		// (const):

		template<typename OneCycle>
		constexpr const auto & one_cycle_cdmsg(const OneCycle & arg)	{ return arg.msg; }

		template<typename OneCycle>
		constexpr const auto & one_cycle_cimsg(const OneCycle & arg)	{ return *arg.msg; }

		//

		template<auto f, auto M> using return_one_cycle_f_dmsg		= S_compose_opt<f, one_cycle_dmsg<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_imsg		= S_compose_opt<f, one_cycle_imsg<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_cdmsg		= S_compose_opt<f, one_cycle_cdmsg<T_type_U<M>>>;
		template<auto f, auto M> using return_one_cycle_f_cimsg		= S_compose_opt<f, one_cycle_cimsg<T_type_U<M>>>;

	// generic:

		template<auto f, typename ObjSpec, typename OneCycle>
		constexpr auto one_cycle_f_msg = V_colist_Bs
		<
			obj_denote<ObjSpec>, obj_mutate<ObjSpec>,		f, U_type_T<OneCycle>,

			S_is_direct_variable,					return_one_cycle_f_dmsg,
			S_is_indirect_variable,					return_one_cycle_f_imsg,
			S_is_direct_immutable,					return_one_cycle_f_cdmsg,
			S_is_indirect_immutable,				return_one_cycle_f_cimsg
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// object (generic):

	template<typename OneCycle>
	struct dispatch_one_cycle_f_argument
	{
		template<auto f, auto ObjSpec> using return_f_out	= S_value_V<one_cycle_f_out<f, T_type_U<ObjSpec>, OneCycle>>;
		template<auto f, auto ObjSpec> using return_f_in	= S_value_V<one_cycle_f_in<f, T_type_U<ObjSpec>, OneCycle>>;
		template<auto f, auto ObjSpec> using return_f_car_in	= S_value_V<one_cycle_f_car_in<f, T_type_U<ObjSpec>, OneCycle>>;
		template<auto f, auto ObjSpec> using return_f_cdr_in	= S_value_V<one_cycle_f_cdr_in<f, T_type_U<ObjSpec>, OneCycle>>;
		template<auto f, auto ObjSpec> using return_f_end	= S_value_V<one_cycle_f_end<f, T_type_U<ObjSpec>, OneCycle>>;
		template<auto f, auto ObjSpec> using return_f_aux	= S_value_V<one_cycle_f_aux<f, T_type_U<ObjSpec>, OneCycle>>;
		template<auto f, auto ObjSpec> using return_f_msg	= S_value_V<one_cycle_f_msg<f, T_type_U<ObjSpec>, OneCycle>>;

		//

		template<auto f, typename ObjSpec>
		using result = T_colist_Bs
		<
			obj_member<ObjSpec>, _na_,			f, U_type_T<ObjSpec>,

			S_is_out,					return_f_out,
			S_is_in,					return_f_in,
			S_is_car_in,					return_f_car_in,
			S_is_cdr_in,					return_f_cdr_in,
			S_is_end,					return_f_end,
			S_is_aux,					return_f_aux,
			S_is_msg,					return_f_msg
		>;
	};

	template<auto f, typename ObjSpec, typename OneCycle>
	using return_one_cycle_f_argument = typename T_hold
	<
		V_equal_TxT<obj_type<ObjSpec>, void>,

		dispatch_function,
		dispatch_one_cycle_f_argument, OneCycle

	>::template result<f, ObjSpec>;

// cast:

	template
	<
		auto f,
		typename ObjSpec,
		typename OneCycle
	>
	constexpr auto one_cycle_cast = sign_cast
	<
		return_one_cycle_f_argument, f, ObjSpec, OneCycle
	>;

// bicast:

	template
	<
		auto f,
		auto l, typename LObjSpec,
		auto r, typename RObjSpec,
		typename OneCycle
	>
	constexpr auto one_cycle_bicast = sign_bicast
	<
		return_one_cycle_f_argument, f, l, LObjSpec, r, RObjSpec, OneCycle
	>;

// apply:

	template
	<
		auto f,
		typename ObjSpec,
		typename OneCycle
	>
	constexpr auto one_cycle_apply = sign_apply
	<
		return_one_cycle_f_argument, f, ObjSpec, OneCycle
	>;

// biapply:

	template
	<
		auto f,
		auto l, typename LObjSpec,
		auto r, typename RObjSpec,
		typename OneCycle
	>
	constexpr auto one_cycle_biapply = sign_biapply
	<
		return_one_cycle_f_argument, f, l, LObjSpec, r, RObjSpec, OneCycle
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

