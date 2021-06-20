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

// abstract:

//	filters (accessors):

//		i(...) - identity
//		d(...) - dereference

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// objects:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// attribute specifications:

/***********************************************************************************************************************/

	template<auto...> struct _object_attributes;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// object specifications:

	template<typename Type = void, typename Attr = void> struct _object	{ };

	//

	template<auto U = U_void, auto A = U_void> using obj_UxU		= _object<T_type_U<U>, T_type_U<A>>;

/***********************************************************************************************************************/

	template<typename ObjSpec>
	using obj_type = typename pattern_match_abstract_object<ObjSpec>::template induct
	<
		ab_obj_type
	>;

	template<typename ObjSpec>
	using obj_attr = typename pattern_match_abstract_object<ObjSpec>::template induct
	<
		ab_obj_attr
	>;

	template<typename ObjSpec> constexpr auto U_obj_type_T			= U_type_T<obj_type<ObjSpec>>;
	template<typename ObjSpec> constexpr auto U_obj_attr_T			= U_type_T<obj_attr<ObjSpec>>;

/***********************************************************************************************************************/

//	template<typename ObjSpec>
//	using obj_to_void_type = typename pattern_match_abstract_object<ObjSpec>::template induct
//	<
//		ab_obj_to_void_type
//	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// signature arguments:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

/***********************************************************************************************************************/

	enum struct Mutability
	{
		immutable,
		variable,

		dimension // filler
	};

	enum struct Denotation
	{
		direct,
		indirect,

		dimension // filler
	};

/***********************************************************************************************************************/

	template<Mutability m> constexpr bool V_is_immutable			= (m == Mutability::immutable);
	template<Mutability m> constexpr bool V_is_variable			= (m == Mutability::variable);

	template<Mutability m, auto> using S_is_immutable			= S_boolean<V_is_immutable<m>>;
	template<Mutability m, auto> using S_is_variable			= S_boolean<V_is_variable<m>>;

	//

	template<Denotation d> constexpr bool V_is_direct			= (d == Denotation::direct);
	template<Denotation d> constexpr bool V_is_indirect			= (d == Denotation::indirect);

	template<Denotation d, auto> using S_is_direct				= S_boolean<V_is_direct<d>>;
	template<Denotation d, auto> using S_is_indirect			= S_boolean<V_is_indirect<d>>;

/***********************************************************************************************************************/

	template<Mutability m, Denotation d>
	constexpr bool V_is_immutable_direct					= (V_is_immutable<m> && V_is_direct<d>);

	template<Mutability m, Denotation d>
	constexpr bool V_is_immutable_indirect					= (V_is_immutable<m> && V_is_indirect<d>);

	template<Mutability m, Denotation d>
	constexpr bool V_is_variable_direct					= (V_is_variable<m> && V_is_direct<d>);

	template<Mutability m, Denotation d>
	constexpr bool V_is_variable_indirect					= (V_is_variable<m> && V_is_indirect<d>);

	template<Mutability m, Denotation d> using S_is_immutable_direct	= S_boolean<V_is_immutable_direct<m, d>>;
	template<Mutability m, Denotation d> using S_is_immutable_indirect	= S_boolean<V_is_immutable_indirect<m, d>>;
	template<Mutability m, Denotation d> using S_is_variable_direct		= S_boolean<V_is_variable_direct<m, d>>;
	template<Mutability m, Denotation d> using S_is_variable_indirect	= S_boolean<V_is_variable_indirect<m, d>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// attribute specifications:

/***********************************************************************************************************************/

	template
	<
		Mutability Mutate,
		Denotation Denote,
		auto...
	>
	struct _argument_attributes
	{
		static constexpr Mutability mutate				= Mutate;
		static constexpr Denotation denote				= Denote;
	};

	//

	using cd_arg_attr	= _argument_attributes < Mutability::immutable , Denotation::direct   >;
	using ci_arg_attr	= _argument_attributes < Mutability::immutable , Denotation::indirect >;
	using d_arg_attr	= _argument_attributes < Mutability::variable  , Denotation::direct   >;
	using i_arg_attr	= _argument_attributes < Mutability::variable  , Denotation::indirect >;

/***********************************************************************************************************************/

	template<typename ArgAttrSpec> constexpr Mutability arg_attr_mutate	= ArgAttrSpec::mutate;
	template<typename ArgAttrSpec> constexpr Denotation arg_attr_denote	= ArgAttrSpec::denote;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// argument specifications:

/***********************************************************************************************************************/

	template<typename = void, typename = void> struct _argument		{ };

	//

	template<typename Type = void> using cd_arg				= _argument < Type , cd_arg_attr >;
	template<typename Type = void> using ci_arg				= _argument < Type , ci_arg_attr >;
	template<typename Type = void> using d_arg				= _argument < Type , d_arg_attr  >;
	template<typename Type = void> using i_arg				= _argument < Type , i_arg_attr  >;

/***********************************************************************************************************************/

	template<typename ArgSpec>
	using arg_type = typename pattern_match_abstract_object<ArgSpec>::template induct
	<
		ab_obj_type
	>;

	template<typename ArgSpec>
	using arg_attr = typename pattern_match_abstract_object<ArgSpec>::template induct
	<
		ab_obj_attr
	>;

	template<typename ArgSpec> constexpr auto U_arg_type_T			= U_type_T<arg_type<ArgSpec>>;
	template<typename ArgSpec> constexpr auto U_arg_attr_T			= U_type_T<arg_attr<ArgSpec>>;

	template<typename ArgSpec> constexpr Mutability arg_mutate		= arg_attr_mutate<arg_attr<ArgSpec>>;
	template<typename ArgSpec> constexpr Denotation arg_denote		= arg_attr_denote<arg_attr<ArgSpec>>;

/***********************************************************************************************************************/

	template<typename ArgSpec>
	using arg_to_void_type = typename pattern_match_abstract_object<ArgSpec>::template induct
	<
		ab_obj_to_void_type
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

