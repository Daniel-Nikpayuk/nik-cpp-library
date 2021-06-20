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

// signature models:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// (run-time) primitives:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// aliases:

/***********************************************************************************************************************/

	template<typename Spec> using return_type			= typename Spec::return_type;
	template<typename Spec> using arg_type				= typename Spec::arg_type;

	template<typename Spec> constexpr auto return_cons		= Spec::return_cons;
	template<typename Spec> constexpr auto lval			= Spec::lval;
	template<typename Spec> constexpr auto rval			= Spec::rval;
	template<typename Spec> constexpr auto car_rval			= Spec::car_rval;
	template<typename Spec> constexpr auto cdr_rval			= Spec::cdr_rval;

	//

	template<typename Spec> using sign_type				= typename Spec::sign_type;

	template<typename Spec> constexpr auto sign_return		= Spec::sign_return;
	template<typename Spec> constexpr auto sign_facade		= Spec::sign_facade;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pair:

/***********************************************************************************************************************/

	// Function as Text version:

		template<typename Spec>
		struct car__cdr
		{
			using return_type			= typename Spec::sign_type &;
			using arg_type				= typename Spec::sign_type &;

			static constexpr auto lval		= Spec::car;
			static constexpr auto rval		= Spec::cdr;

			static constexpr auto return_cons	= id<return_type>;
		};

		template<typename Spec>
		struct car__car_x_cdr
		{
			using return_type			= typename Spec::sign_type &;
			using arg_type				= typename Spec::sign_type &;

			static constexpr auto lval		= Spec::car;
			static constexpr auto car_rval		= Spec::car;
			static constexpr auto cdr_rval		= Spec::cdr;

			static constexpr auto return_cons	= id<return_type>;
		};

		template<typename Spec>
		constexpr auto sign_square = V_do_compose_opt
		<
			sign_assign	< car__cdr       <Spec> >,
			sign_multiply	< car__car_x_cdr <Spec> >
		>;

		template<typename Type>
		Type square(Type x)
		{
			using pair		= pair_signature	< Type, Type                           >;
			using spec		= pair_specification	< pair, pair_car<pair>, pair_cdr<pair> >;

			sign_type<spec> s	= sign_facade<spec>(x);

			return sign_return<spec>(sign_square<spec>(s));
		}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// abstract signature:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// abstract objects:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specifications:

/***********************************************************************************************************************/

	template<typename> struct pattern_match_abstract_object;

	template
	<
		template<typename, typename> class ObjectName,
		typename Type, typename Attr
	>
	struct pattern_match_abstract_object
	<
		ObjectName<Type, Attr>
	>
	{
		template
		<
			template
			<
				template<typename, typename> class,
				typename, typename

			> class Function
		>
		using induct = Function<ObjectName, Type, Attr>;
	};

/***********************************************************************************************************************/

	template<template<typename, typename> class ObjectName, typename Type, typename Attr>
	using ab_obj_type = Type;

	template<template<typename, typename> class ObjectName, typename Type, typename Attr>
	using ab_obj_attr = Attr;

	template<template<typename, typename> class ObjectName, typename Type, typename Attr>
	using ab_obj_to_void_type = ObjectName<void, Attr>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// signature procedures:

/***********************************************************************************************************************/

// void:

//	struct dispatch_sign_f_void
//	{
//		template<auto f, typename> using result			 	= S_value_V<f>;
//	};

/***********************************************************************************************************************/

// sign:

	// kernel:

		template<typename Signature>
		constexpr const Signature & (*sign_cd_sign)(const Signature &) 	= id<Signature const &>;

		template<typename Signature>
		constexpr const auto & sign_ci_sign(const Signature & arg)	{ return *arg; }

		//

		template<typename Signature>
		constexpr Signature & (*sign_d_sign)(Signature &)		= id<Signature&>;

		template<typename Signature>
		constexpr auto & sign_i_sign(Signature & arg)			{ return *arg; }

		//

		template<auto f, auto M> using return_sign_f_cd_sign		= S_compose_opt<f, sign_cd_sign<T_type_U<M>>>;
		template<auto f, auto M> using return_sign_f_ci_sign		= S_compose_opt<f, sign_ci_sign<T_type_U<M>>>;
		template<auto f, auto M> using return_sign_f_d_sign		= S_compose_opt<f, sign_d_sign<T_type_U<M>>>;
		template<auto f, auto M> using return_sign_f_i_sign		= S_compose_opt<f, sign_i_sign<T_type_U<M>>>;

	// generic:

		template<auto f, typename ArgSpec, typename Signature>
		constexpr auto sign_f_sign = V_colist_Bs
		<
			arg_mutate<ArgSpec>, arg_denote<ArgSpec>,		f, U_type_T<Signature>,

			S_is_immutable_direct,					return_sign_f_cd_sign,
			S_is_immutable_indirect,				return_sign_f_ci_sign,
			S_is_variable_direct,					return_sign_f_d_sign,
			S_is_variable_indirect,					return_sign_f_i_sign
		>;

/***********************************************************************************************************************/

// cast:

	// kernel:

	//	template<auto f, typename Signature>
	//	constexpr auto sign_f_cast(Signature & arg)
	//		{ return f(arg); }

		template<auto f, typename Signature>
		constexpr auto (*sign_f_cast)(Signature &) = sign_f_sign<f, d_arg<>, Signature>;

	// generic:

		template
		<
			template<auto, typename, typename> class return_sign_f_arg,
			auto f,
			typename ArgSpec,
			typename Signature
		>
		constexpr auto sign_cast = sign_f_cast
		<
			V_value_S<return_sign_f_arg<f, ArgSpec, Signature>>,
			Signature
		>;

/***********************************************************************************************************************/

// bicast:

	//	template<auto f, typename Signature>
	//	constexpr auto sign_f_bicast(Signature & arg)
	//		{ return f(arg, arg); }

	//	template<auto f, auto l, typename Signature>
	//	constexpr auto sign_f_lv_bicast(Signature & arg)
	//		{ return f(l(), arg); }

	//	template<auto f, auto r, typename Signature>
	//	constexpr auto sign_f_rv_bicast(Signature & arg)
	//		{ return f(arg, r()); }

	// kernel:

	//	template<auto f, auto l, auto r, typename Signature>
	//	constexpr auto sign_f_bicast(Signature & arg)
	//		{ return f(l(arg), r(arg)); }

	//	template<auto f, auto l, auto r, typename Signature>
	//	constexpr auto sign_f_vl_bicast(Signature & arg)
	//		{ return f(l(), r(arg)); }

	//	template<auto f, auto l, auto r, typename Signature>
	//	constexpr auto sign_f_vr_bicast(Signature & arg)
	//		{ return f(l(arg), r()); }

		template<auto f, auto l, auto r, typename Signature>
		constexpr auto (*sign_f_bicast)(Signature &) = V_curry_compose_opt
		<
			f, l, r
		>;

		constexpr auto (*sign_f_cast)(Signature &) = sign_f_sign<f, d_arg<>, Signature>;
			{ return f(l(arg), r(arg)); }

		template<auto f, auto l, auto r, typename Signature>
		constexpr auto sign_f_vl_bicast(Signature & arg)
			{ return f(l(), r(arg)); }

		template<auto f, auto l, auto r, typename Signature>
		constexpr auto sign_f_vr_bicast(Signature & arg)
			{ return f(l(arg), r()); }

	// generic:

		template<auto f, typename Signature>
		struct dispatch_sign_bicast
		{
			template<auto l, auto r> using return_f_bicast		= S_value_V<sign_f_bicast<f, l, r, Signature>>;
			template<auto l, auto r> using return_f_vl_bicast	= S_value_V<sign_f_vl_bicast<f, l, r, Signature>>;
			template<auto l, auto r> using return_f_vr_bicast	= S_value_V<sign_f_vr_bicast<f, l, r, Signature>>;

			//

			template<typename LArgSpec, typename RArgSpec, auto l, auto r>
			static constexpr auto result = V_colist_Bs
			<
				U_arg_type_T<LArgSpec>, U_arg_type_T<RArgSpec>,		l, r,

				S_left_equals_void,					return_f_vl_bicast,
				S_right_equals_void,					return_f_vr_bicast,
				otherwise,						return_f_bicast
			>;
		};

		template
		<
			template<auto, typename, typename> class return_sign_f_arg,
			auto f,
			auto l, typename LArgSpec,
			auto r, typename RArgSpec,
			typename Signature
		>
		constexpr auto sign_bicast = dispatch_sign_bicast
		<
			f, Signature

		>::template result
		<
			LArgSpec, RArgSpec,
			V_value_S<return_sign_f_arg<l, LArgSpec, Signature>>,
			V_value_S<return_sign_f_arg<r, RArgSpec, Signature>>
		>;

/***********************************************************************************************************************/

// apply:

	// kernel:

		template<auto f, typename Signature>
		constexpr Signature & sign_f_apply(Signature & arg)
			{ f(arg); return arg; }

	// generic:

		template
		<
			template<auto, typename, typename> class return_sign_f_arg,
			auto f,
			typename ArgSpec,
			typename Signature
		>
		constexpr auto sign_apply = sign_f_apply
		<
			V_value_S<return_sign_f_arg<f, ArgSpec, Signature>>,
			Signature
		>;

/***********************************************************************************************************************/

// biapply:

	// kernel:

		template<auto f, auto r1, auto r2, typename Signature>
		constexpr Signature & sign_f_biapply(Signature & arg)
			{ f(r1(arg), r2(arg)); return arg; }

		template<auto f, auto r1, auto r2, typename Signature>
		constexpr Signature & sign_f_vl_biapply(Signature & arg)
			{ f(r1(), r2(arg)); return arg; }

		template<auto f, auto r1, auto r2, typename Signature>
		constexpr Signature & sign_f_vr_biapply(Signature & arg)
			{ f(r1(arg), r2()); return arg; }

	// generic:

		template<auto f, typename Signature>
		struct dispatch_sign_biassign
		{
			template<auto l, auto r> using return_f_biapply		= S_value_V<sign_f_biapply<f, l, r, Signature>>;
			template<auto l, auto r> using return_f_vl_biapply	= S_value_V<sign_f_vl_biapply<f, l, r, Signature>>;
			template<auto l, auto r> using return_f_vr_biapply	= S_value_V<sign_f_vr_biapply<f, l, r, Signature>>;

			//

			template<typename LArgSpec, typename RArgSpec, auto l, auto r>
			static constexpr auto result = V_colist_Bs
			<
				U_arg_type_T<LArgSpec>, U_arg_type_T<RArgSpec>,		l, r,

				S_left_equals_void,					return_f_vl_biapply,
				S_right_equals_void,					return_f_vr_biapply,
				otherwise,						return_f_biapply
			>;
		};

		template
		<
			template<auto, typename, typename> class return_sign_f_arg,
			auto f,
			auto l, typename LArgSpec,
			auto r, typename RArgSpec,
			typename Signature
		>
		constexpr auto sign_biapply = dispatch_sign_biassign
		<
			f, Signature

		>::template result
		<
			LArgSpec, RArgSpec,
			V_value_S<return_sign_f_arg<l, LArgSpec, Signature>>,
			V_value_S<return_sign_f_arg<r, RArgSpec, Signature>>
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pair signature:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// objects:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// members:

/***********************************************************************************************************************/

	enum struct PairMember
	{
		car,
		cdr,
		none,

		dimension // filler
	};

	template<PairMember p> constexpr bool V_is_car			= (p == PairMember::car);
	template<PairMember p> constexpr bool V_is_cdr			= (p == PairMember::cdr);
	template<PairMember p> constexpr bool V_is_none			= (p == PairMember::none);

	template<PairMember p, auto> using S_is_car			= S_boolean<V_is_car<p>>;
	template<PairMember p, auto> using S_is_cdr			= S_boolean<V_is_cdr<p>>;
	template<PairMember p, auto> using S_is_none			= S_boolean<V_is_none<p>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// attribute specifications:

/***********************************************************************************************************************/

	template
	<
		PairMember Member
	>
	struct _object_attributes
	<
		Member
	>
	{
		static constexpr PairMember member			= Member;
	};

	//

	using _car_obj_attr						= _object_attributes < PairMember::car >;
	using _cdr_obj_attr						= _object_attributes < PairMember::cdr >;
	using _pair_obj_attr						= _object_attributes < PairMember::none >;

/***********************************************************************************************************************/

	template<typename PairObjAttrSpec>
		constexpr PairMember pair_obj_attr_member		= PairObjAttrSpec::member;

/***********************************************************************************************************************/

	template<typename PairObjAttrSpec>
	using pair_obj_attr_reduce_to_member = _object_attributes
	<
		pair_obj_attr_member<PairObjAttrSpec>
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// object specifications:

/***********************************************************************************************************************/

	template<typename Type> using _car_object			= _object < Type , _car_obj_attr >;
	template<typename Type> using _cdr_object			= _object < Type , _cdr_obj_attr >;
	template<typename Type> using _pair_object			= _object < Type , _pair_obj_attr >;

/***********************************************************************************************************************/

	template<typename PairObjSpec>
		constexpr PairMember pair_obj_member			= pair_obj_attr_member<obj_attr<PairObjSpec>>;

/***********************************************************************************************************************/

	template<typename PairObjSpec>
	using pair_obj_reduce_to_member = _object
	<
		obj_type<PairObjSpec>,
		pair_obj_attr_reduce_to_member<obj_attr<PairObjSpec>>
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// signature specifications:

/***********************************************************************************************************************/

	template<typename, typename> struct pair_signature;

	template
	<
		typename CarType,
		typename CdrType
	>
	struct pair_signature
	<
		_car_object< CarType >,
		_cdr_object< CdrType >
	>
	{
		CarType car;
		CdrType cdr;

		pair_signature(CarType a, CdrType d)								:
			car(a), cdr(d)										{ }
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// arguments:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// attribute specifications:

/***********************************************************************************************************************/

	template
	<
		Mutability Mutate,
		Denotation Denote,
		PairMember Member
	>
	struct _argument_attributes
	<
		Mutate,
		Denote,
		Member
	>
	{
		static constexpr Mutability mutate				= Mutate;
		static constexpr Denotation denote				= Denote;
		static constexpr PairMember member				= Member;
	};

	//

	using cd_car_attr	= _argument_attributes < Mutability::immutable , Denotation::direct   , PairMember::car >;
	using ci_car_attr	= _argument_attributes < Mutability::immutable , Denotation::indirect , PairMember::car >;
	using d_car_attr	= _argument_attributes < Mutability::variable  , Denotation::direct   , PairMember::car >;
	using i_car_attr	= _argument_attributes < Mutability::variable  , Denotation::indirect , PairMember::car >;

	using cd_cdr_attr	= _argument_attributes < Mutability::immutable , Denotation::direct   , PairMember::cdr >;
	using ci_cdr_attr	= _argument_attributes < Mutability::immutable , Denotation::indirect , PairMember::cdr >;
	using d_cdr_attr	= _argument_attributes < Mutability::variable  , Denotation::direct   , PairMember::cdr >;
	using i_cdr_attr	= _argument_attributes < Mutability::variable  , Denotation::indirect , PairMember::cdr >;

	using cd_pair_attr	= _argument_attributes < Mutability::immutable , Denotation::direct   , PairMember::none >;
	using ci_pair_attr	= _argument_attributes < Mutability::immutable , Denotation::indirect , PairMember::none >;
	using d_pair_attr	= _argument_attributes < Mutability::variable  , Denotation::direct   , PairMember::none >;
	using i_pair_attr	= _argument_attributes < Mutability::variable  , Denotation::indirect , PairMember::none >;

/***********************************************************************************************************************/

	template<typename PairArgAttrSpec>
		constexpr PairMember pair_arg_attr_member		= PairArgAttrSpec::member;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// argument specifications:

/***********************************************************************************************************************/

	template<typename Type = void> using cd_car			= _argument < Type , cd_car_attr >;
	template<typename Type = void> using ci_car			= _argument < Type , ci_car_attr >;
	template<typename Type = void> using d_car			= _argument < Type , d_car_attr  >;
	template<typename Type = void> using i_car			= _argument < Type , i_car_attr  >;
                                                                                                
	template<typename Type = void> using cd_cdr			= _argument < Type , cd_cdr_attr >;
	template<typename Type = void> using ci_cdr			= _argument < Type , ci_cdr_attr >;
	template<typename Type = void> using d_cdr			= _argument < Type , d_cdr_attr  >;
	template<typename Type = void> using i_cdr			= _argument < Type , i_cdr_attr  >;
                                                                                              
	template<typename Type = void> using cd_pair			= _argument < Type , cd_pair_attr >;
	template<typename Type = void> using ci_pair			= _argument < Type , ci_pair_attr >;
	template<typename Type = void> using d_pair			= _argument < Type , d_pair_attr  >;
	template<typename Type = void> using i_pair			= _argument < Type , i_pair_attr  >;

/***********************************************************************************************************************/

	template<typename PairArgSpec>
		constexpr PairMember pair_arg_member			= pair_arg_attr_member<arg_attr<PairArgSpec>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// signature procedures:

/***********************************************************************************************************************/

// car:

	// kernel:

		template<typename Pair>
		constexpr const auto & pair_cd_car(const Pair & arg)		{ return arg.car; }

		template<typename Pair>
		constexpr const auto & pair_ci_car(const Pair & arg)		{ return *arg.car; }

		//

		template<typename Pair>
		constexpr auto & pair_d_car(Pair & arg)				{ return arg.car; }

		template<typename Pair>
		constexpr auto & pair_i_car(Pair & arg)				{ return *arg.car; }

		//

		template<auto f, auto M> using return_pair_f_cd_car		= S_compose_opt<f, pair_cd_car<T_type_U<M>>>;
		template<auto f, auto M> using return_pair_f_ci_car		= S_compose_opt<f, pair_ci_car<T_type_U<M>>>;
		template<auto f, auto M> using return_pair_f_d_car		= S_compose_opt<f, pair_d_car<T_type_U<M>>>;
		template<auto f, auto M> using return_pair_f_i_car		= S_compose_opt<f, pair_i_car<T_type_U<M>>>;

	// generic:

		template<auto f, typename ArgSpec, typename Pair>
		constexpr auto pair_f_car = V_colist_Bs
		<
			arg_mutate<ArgSpec>, arg_denote<ArgSpec>,		f, U_type_T<Pair>,

			S_is_immutable_direct,					return_pair_f_cd_car,
			S_is_immutable_indirect,				return_pair_f_ci_car,
			S_is_variable_direct,					return_pair_f_d_car,
			S_is_variable_indirect,					return_pair_f_i_car
		>;

/***********************************************************************************************************************/

// cdr:

	// kernel:

		template<typename Pair>
		constexpr const auto & pair_cd_cdr(const Pair & arg)		{ return arg.cdr; }

		template<typename Pair>
		constexpr const auto & pair_ci_cdr(const Pair & arg)		{ return *arg.cdr; }

		//

		template<typename Pair>
		constexpr auto & pair_d_cdr(Pair & arg)				{ return arg.cdr; }

		template<typename Pair>
		constexpr auto & pair_i_cdr(Pair & arg)				{ return *arg.cdr; }

		//

		template<auto f, auto M> using return_pair_f_cd_cdr		= S_compose_opt<f, pair_cd_cdr<T_type_U<M>>>;
		template<auto f, auto M> using return_pair_f_ci_cdr		= S_compose_opt<f, pair_ci_cdr<T_type_U<M>>>;
		template<auto f, auto M> using return_pair_f_d_cdr		= S_compose_opt<f, pair_d_cdr<T_type_U<M>>>;
		template<auto f, auto M> using return_pair_f_i_cdr		= S_compose_opt<f, pair_i_cdr<T_type_U<M>>>;

	// generic:

		template<auto f, typename ArgSpec, typename Pair>
		constexpr auto pair_f_cdr = V_colist_Bs
		<
			arg_mutate<ArgSpec>, arg_denote<ArgSpec>,		f, U_type_T<Pair>,

			S_is_immutable_direct,					return_pair_f_cd_cdr,
			S_is_immutable_indirect,				return_pair_f_ci_cdr,
			S_is_variable_direct,					return_pair_f_d_cdr,
			S_is_variable_indirect,					return_pair_f_i_cdr
		>;

/***********************************************************************************************************************/

// pair:

	// generic:

		template<auto f, typename ArgSpec, typename Pair>
		constexpr auto pair_f_pair = sign_f_sign<f, ArgSpec, Pair>;

		//

		template
		<
			auto f,
			typename CarObj, typename CdrObj,
			template<typename, typename> class Pair = pair_signature
		>
		constexpr Pair<CarObj, CdrObj> pair_f_cons(obj_type<CarObj> a, obj_type<CdrObj> d)
		{
			using signature			= Pair
							<
								CarObj,
								CdrObj
							>;
			constexpr auto pair_f		= sign_f_sign
							<
								f, d_pair, signature
							>;

			return pair_f(signature(a, d));
		}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// filters:

/***********************************************************************************************************************/

// generic:

	template<typename Pair>
	struct dispatch_pair_f_member
	{
		template<auto f, auto ArgSpec> using return_f_car	= S_value_V<pair_f_car<f, T_type_U<ArgSpec>, Pair>>;
		template<auto f, auto ArgSpec> using return_f_cdr	= S_value_V<pair_f_cdr<f, T_type_U<ArgSpec>, Pair>>;
		template<auto f, auto ArgSpec> using return_f_arg	= S_value_V<pair_f_pair<f, T_type_U<ArgSpec>, Pair>>;

		template<auto f, typename ArgSpec>
		using result = T_colist_Bs
		<
			pair_arg_member<ArgSpec>, _na_,			f, U_type_T<ArgSpec>,

			S_is_car,					return_f_car,
			S_is_cdr,					return_f_cdr,
			otherwise,					return_f_arg
		>;
	};

	template<auto f, typename ArgSpec, typename Pair>
	using return_pair_f_member = typename T_hold
	<
		V_equal_TxT<arg_type<ArgSpec>, void>,

		dispatch_sign_f_void,
		dispatch_pair_f_member, Pair

	>::template result<f, ArgSpec>;

// cast:

	template
	<
		auto f,
		typename ArgSpec,
		typename Pair
	>
	constexpr auto pair_cast = sign_cast
	<
		return_pair_f_member, f, ArgSpec, Pair
	>;

// bicast:

	template
	<
		auto f,
		auto l, typename LArgSpec,
		auto r, typename RArgSpec,
		typename Pair
	>
	constexpr auto pair_bicast = sign_bicast
	<
		return_pair_f_member, f, l, LArgSpec, r, RArgSpec, Pair
	>;

// apply:

	template
	<
		auto f,
		typename ArgSpec,
		typename Pair
	>
	constexpr auto pair_apply = sign_apply
	<
		return_pair_f_member, f, ArgSpec, Pair
	>;

// biapply:

	template
	<
		auto f,
		auto l, typename LArgSpec,
		auto r, typename RArgSpec,
		typename Pair
	>
	constexpr auto pair_biapply = sign_biapply
	<
		return_pair_f_member, f, l, LArgSpec, r, RArgSpec, Pair
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

