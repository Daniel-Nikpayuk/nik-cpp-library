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

// pair source:

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
/***********************************************************************************************************************/

// signature specifications:

/***********************************************************************************************************************/

	template<typename, typename> struct pair_signature;

/***********************************************************************************************************************/

	template<typename CarType, typename CdrType>
	struct pair_signature
	{
		CarType car;
		CdrType cdr;

		pair_signature() { }
	};

	//

	template<typename Pair>
	constexpr auto & pair_car(Pair & arg)		{ return arg.car; }

	template<typename Pair>
	constexpr auto & pair_cdr(Pair & arg)		{ return arg.cdr; }

	//

	template<typename Pair, auto Car, auto Cdr>
	struct pair_specification
	{
		using sign_type				= Pair;

		static constexpr auto sign_return	= Car;
		static constexpr auto sign_facade	= set<Cdr, Pair, T_reference_type_T<f_out_type<Cdr>>>;

		static constexpr auto car		= Car;
		static constexpr auto cdr		= Cdr;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

