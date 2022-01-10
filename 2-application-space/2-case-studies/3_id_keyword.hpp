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

// id keyword:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// optimized composition:

/***********************************************************************************************************************/

// opt compose:

	template
	<
		// labels:

			index_type none_are_id_word	= 1,
			index_type f_in_is_id_word	= 2,
			index_type f_out_is_id_word	= 3,

		// registers:

			index_type f_in			= 0,
			index_type f_out		= 1,

			index_type is_id_word		= 2,
			index_type comp			= 3
	>
	constexpr auto opt_compose_contr = r_controller
	<
		r_label // none_are_id_word:
		<
			check    < is_id_word       , f_in                 >,
			branch   < f_in_is_id_word                         >,
			check    < is_id_word       , f_out                >,
			branch   < f_out_is_id_word                        >,
			compel   < f_out            , comp  , f_out , f_in >,
			stop     < f_out                                   >
		>,

		r_label // f_in_is_id_word:
		<
			stop     < f_out                                   >
		>,

		r_label // f_out_is_id_word:
		<
			stop     < f_in                                    >
		>
	>;

	template<depth_type d, auto f, auto g>
	constexpr auto f_opt_compose()
	{
		constexpr auto is_id_word	= U_is_id_keyword;
		constexpr auto comp		= U_compose;

		constexpr index_type i		= _one;
		constexpr index_type j		= _zero;

		return machine_start
		<
			RD, opt_compose_contr<>, d, i, j,
			f, g, is_id_word, comp
		>();
	};

	struct S_opt_compose
	{
		template<auto f, auto g>
		static constexpr auto result = f_opt_compose<500, f, g>();
	};

	constexpr auto U_opt_compose = U_type_T<S_opt_compose>;

/***********************************************************************************************************************/

// opt do compose:

	struct S_opt_do_compose
	{
		template<auto f, auto g>
		static constexpr auto result = f_opt_compose<500, g, f>();
	};

	constexpr auto U_opt_do_compose = U_type_T<S_opt_do_compose>;

/***********************************************************************************************************************/

// opt do chain compose:

	template<auto f0, auto... fs>
	constexpr auto opt_do_chain_compose = machine_space::f_pack_roll<500, U_opt_do_compose, f0, fs...>();

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// :

/***********************************************************************************************************************/

	// clang complains if this controller is declared inside S_lift.

		template
		<
			// labels:

				index_type none_are_id_word	= 1,
				index_type f_out_is_id_word	= 2,

			// registers:

				index_type f_in			= 0,
				index_type f_out		= 1,

				index_type is_id_word		= 2,
				index_type comp			= 3
		>
		constexpr auto lift_contr = r_controller
		<
			r_label // none_are_id_word:
			<
				check    < is_id_word       , f_out                >,
				branch   < f_out_is_id_word                        >,
				compel   < f_out            , comp  , f_out , f_in >,
				stop     < f_out                                   >
			>,

			r_label // f_out_is_id_word:
			<
				stop     < f_in                                    >,
				reg_size < _four                                   >
			>
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

