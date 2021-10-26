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

#ifndef NIK_CPP_LIBRARY_EXCLUSIVE_HPP
#define NIK_CPP_LIBRARY_EXCLUSIVE_HPP

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// kernel macros:


#define nik_stringify(_string_)												\
															\
	#_string_


#define nik_catenate(_label1_, _label2_)										\
															\
	_label1_##_label2_


// preprocessor hack:

#define nik_name(_label1_, _label2_)											\
															\
	nik_catenate(_label1_, _label2_)


/***********************************************************************************************************************/
/***********************************************************************************************************************/

namespace nik
{
	using global_size_type	= unsigned long long;	// size_t;

/***********************************************************************************************************************/

	enum struct Translation : global_size_type
	{
		interpret,
		compile,

		dimension // filler
	};

	enum struct Module : global_size_type
	{
	// interpret:

		cache,
		constant,

		pair,
		boolean,

		pointer,
		reference,
		array,

		machine,
		pack,

		list,
		function,
		colist,

	// compile:

		procedure,
		continuation,
		signature,
		one_cycle,
		near_linear,
		typed_stack,
		typed_machine,

		dimension // filler
	};

	enum struct Permission : global_size_type
	{
		architect,
		user,

		dimension // filler
	};

	struct Version
	{
		static constexpr const char v_0_1[] = "v.0.1";
		static constexpr const char v_0_5[] = "v.0.5";
		static constexpr const char v_1_0[] = "v.1.0";
	};

	enum struct Vendor : global_size_type
	{
		gcc,
		clang,

		dimension // filler
	};

/***********************************************************************************************************************/

	template<bool V>
	constexpr bool module_assert() { return false; }

	template
	<
		Translation	translation_enum,
		Module		module_enum,
		Permission	permission_enum,
		const char*	version_str,
		Vendor		vendor_enum,

		bool		is_implemented = true
	>
	class module
	{
		// Checks to see if a given module has been implemented (specialized).

		static_assert
		(
			module_assert<is_implemented>(),
				"this module has not been implemented."
		);
	};
}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// module macros:


#define nik_begin_module(_translation_, _module_, _permission_, _version_, _vendor_)					\
															\
	template<>													\
	class module													\
	<														\
		nik::Translation::_translation_,									\
		nik::Module::_module_,											\
		nik::Permission::_permission_,										\
		nik::Version::_version_,										\
		nik::Vendor::_vendor_,											\
															\
		true													\
	>														\
	{														\
		static constexpr auto _ ## translation_	= nik::Translation::_translation_;				\
		static constexpr auto _ ## module_	= nik::Module::_module_;					\
		static constexpr auto _ ## permission_	= nik::Permission::_permission_;				\
		static constexpr auto _ ## version_	= nik::Version::_version_;					\
		static constexpr auto _ ## vendor_	= nik::Vendor::_vendor_;


#define nik_end_module(_translation_, _module_, _permission_, _version_, _vendor_)					\
															\
	};


#define nik_module(_translation_, _module_, _permission_, _version_, _vendor_)						\
															\
	nik::module													\
	<														\
		nik::Translation::_translation_,									\
		nik::Module::_module_,											\
		nik::Permission::_permission_,										\
		nik::Version::_version_,										\
		nik::Vendor::_vendor_											\
	>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_interpret()													\
															\
	0-compile-time-space


/***********************************************************************************************************************/


	#define nik_cache()												\
															\
		00-cache

	#define nik_constant()												\
															\
		01-constant

	#define nik_pair()												\
															\
		02-pair

	#define nik_boolean()												\
															\
		03-boolean

	#define nik_pointer()												\
															\
		04-pointer

	#define nik_reference()												\
															\
		05-reference

	#define nik_array()												\
															\
		06-array

	#define nik_machine()												\
															\
		07-machine

	#define nik_pack()												\
															\
		08-pack

	#define nik_list()												\
															\
		09-list

	#define nik_function()												\
															\
		10-function

	#define nik_colist()												\
															\
		11-colist


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_compile()													\
															\
	1-run-time-space


/***********************************************************************************************************************/


	#define nik_procedure()												\
															\
		0-procedure

	#define nik_continuation()											\
															\
		1-continuation

	#define nik_signature()												\
															\
		2-signature

	#define nik_one_cycle()												\
															\
		3-one-cycle

	#define nik_near_linear()											\
															\
		4-near-linear

	#define nik_typed_stack()											\
															\
		5-typed-stack

	#define nik_typed_machine()											\
															\
		6-typed-machine


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_file(_path_, _translation_, _module_, _permission_, _version_, _vendor_, _intent_)				\
															\
	nik_stringify(_path_/_translation_-_module_-_permission_-_version_-_vendor_-_intent_.hpp)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_source(_path_, _translation_, _module_, _permission_, _version_, _vendor_)					\
															\
	nik_file(_path_/nik_ ## _translation_()/nik_ ## _module_()/0-source,						\
		_translation_, _module_, _permission_, _version_, _vendor_, include)


/***********************************************************************************************************************/


#define nik_import(_path_, _translation_, _module_, _permission_, _version_, _vendor_, _policy_, _prefix_)		\
															\
	nik_file(_path_/nik_ ## _translation_()/nik_ ## _module_()/1-alias,						\
		_translation_, _module_, _permission_, _version_, _vendor_, _policy_-_prefix_-import)


/***********************************************************************************************************************/


#define nik_using(_translation_, _module_, _permission_, _version_, _vendor_, _policy_, _prefix_)			\
															\
	nik_file(_path_/nik_ ## _translation_()/nik_ ## _module_()/1-alias,						\
		_translation_, _module_, _permission_, _version_, _vendor_, _policy_-_prefix_-import)


/***********************************************************************************************************************/
/***********************************************************************************************************************/

#endif
