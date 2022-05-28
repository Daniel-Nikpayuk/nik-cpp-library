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

// dependencies:

	#include nik_source(../../.., interpret, machine, architect, v_0_5, gcc)
	#include nik_source(../../.., interpret, function, architect, v_0_5, gcc)

// colist source:

namespace nik { nik_begin_module(interpret, colist, architect, NIK_VERSION, NIK_VENDOR)

	#include nik_import(../../.., interpret, constant, architect, v_0_5, gcc, static, name)
	#include nik_import(../../.., interpret, machine, architect, v_0_5, gcc, static, name)

	using function_module = nik_module(interpret, function, architect, v_0_5, gcc);

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controller:

private:

	template
	<
		// labels:

			index_type loop		= 0,
			index_type fail		= 1,
			index_type done		= 2,

		// registers:

			index_type cond_val	= 0,
			index_type func_val	= 1,
			index_type def_val	= 2,
			index_type length	= 3,

			index_type is_zero	= 4,
			index_type dec		= 5,

			index_type cond		= 6,
			index_type func		= 7
	>
	nik_ces auto colist_contr = controller
	<
		label // loop:
		<
			test       < is_zero  , length            >,
			branch     < fail                         >,
			check      < cond     , cond_val          >,
			branch     < done                         >,
			erase      < func                         >,
			erase      < cond                         >,
			apply      < length   , dec      , length >,
			goto_label < loop                         >
		>,

		label // fail:
		<
			stop       < def_val                      >
		>,

		label // done:
		<
			compel     < func_val , func , func_val   >,
			stop       < func_val                     >,
			reg_size   < _eight                       >
		>
	>;

/***********************************************************************************************************************/

// colist:

	template<auto d, auto cond_val, auto func_val, auto def_val, auto... Vs>
	nik_ces auto f_colist()
	{
		constexpr auto length	= sizeof...(Vs);

		using F_is_zero		= typename function_module::template F_is_value_V<index_type{0}>;
		constexpr auto is_zero	= F_is_zero::template result<index_type>;

		using F_dec		= typename function_module::template F_subtract_by<index_type{1}>;
		constexpr auto dec	= F_dec::template result<index_type>;

		return start
		<
			register_machine, colist_contr<>, d,
			cond_val, func_val, def_val, length, is_zero, dec, Vs...
		>();
	}

public:

	template<auto cond_val, auto func_val, auto def_val, auto... Vs>
	nik_ces auto colist = f_colist<500, cond_val, func_val, def_val, Vs...>();

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

nik_end_module(interpret, generic, architect, NIK_VERSION, NIK_VENDOR)

// variable template specializations:

	template<typename Op, nik_vp(*pack)(Op*), auto... Vs>
	constexpr auto NIK_MODULE::apply<pack, Vs...> = Op::template result<Vs...>;
}

