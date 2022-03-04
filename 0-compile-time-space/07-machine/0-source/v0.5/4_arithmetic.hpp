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

// arithmetic source:

private:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// near linear passers:

/***********************************************************************************************************************/

// swap registers and argument zero:

	template<key_type... filler>
	struct machine<MN::swap, MT::r_and_a0, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename Heap3,
			auto... Ps, typename... Args
		>
		static constexpr auto result
		(
			Heap0 H0, Heap1 H1, Heap2 H2, Heap3 H3,
			nik_vpcr(A0)(auto_pack<Ps...>*), Args... As
		)
		{
			constexpr auto nA0 = U_opt_pack_Vs<Vs...>;

			return NIK_MACHINE(d, n, c, i, j, Ps)(H0, H1, H2, H3, nA0, As...);
		}
	};

/***********************************************************************************************************************/

// swap arguments zero and one:

	template<key_type... filler>
	struct machine<MN::swap, MT::a0_and_a1, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename Heap3,
			typename Arg0, typename Arg1, typename... Args
		>
		static constexpr auto result
		(
			Heap0 H0, Heap1 H1, Heap2 H2, Heap3 H3,
			Arg0 A0, Arg1 A1, Args... As
		)
		{
			return NIK_MACHINE(d, n, c, i, j, Vs)(H0, H1, H2, H3, A1, A0, As...);
		}
	};

/***********************************************************************************************************************/

// swap arguments zero and two:

	template<key_type... filler>
	struct machine<MN::swap, MT::a0_and_a2, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename Heap3,
			typename Arg0, typename Arg1, typename Arg2, typename... Args
		>
		static constexpr auto result
		(
			Heap0 H0, Heap1 H1, Heap2 H2, Heap3 H3,
			Arg0 A0, Arg1 A1, Arg2 A2, Args... As
		)
		{
			return NIK_MACHINE(d, n, c, i, j, Vs)(H0, H1, H2, H3, A2, A1, A0, As...);
		}
	};

/***********************************************************************************************************************/

// swap arguments one and two:

	template<key_type... filler>
	struct machine<MN::swap, MT::a1_and_a2, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename Heap3,
			typename Arg0, typename Arg1, typename Arg2, typename... Args
		>
		static constexpr auto result
		(
			Heap0 H0, Heap1 H1, Heap2 H2, Heap3 H3,
			Arg0 A0, Arg1 A1, Arg2 A2, Args... As
		)
		{
			return NIK_MACHINE(d, n, c, i, j, Vs)(H0, H1, H2, H3, A0, A2, A1, As...);
		}
	};

/***********************************************************************************************************************/

// argument zero is null, insert at heap zero front:

	template<key_type... filler>
	struct machine<MN::a0_is_null, MT::insert_at_h0_front, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, typename Heap1, typename Heap2, typename Heap3,
			auto... Ps, typename... Args
		>
		static constexpr auto result
		(
			nik_vpcr(H0)(auto_pack<Ws...>*), Heap1 H1, Heap2 H2, Heap3 H3,
			nik_vpcr(A0)(auto_pack<Ps...>*), Args... As
		)
		{
			constexpr bool is_null	= (sizeof...(Ps) == 0);
			constexpr auto nH0	= U_opt_pack_Vs<is_null, Ws...>;

			return NIK_MACHINE(d, n, c, i, j, Vs)(nH0, H1, H2, H3, A0, As...);
		}
	};

/***********************************************************************************************************************/

// construct register pos argument zero, replace at argument zero:

	template<key_type... filler>
	struct machine<MN::construct_r_a0, MT::replace_at_a0, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto W0, auto... Ws, typename Heap1, typename Heap2, typename Heap3,
			auto... Ps, typename... Args
		>
		static constexpr auto result
		(
			nik_vpcr(H0)(auto_pack<W0, Ws...>*), Heap1 H1, Heap2 H2, Heap3 H3,
			nik_vpcr(A0)(auto_pack<Ps...>*), Args... As
		)
		{
			using tn			= T_type_U<n>;
			constexpr auto ins		= tn::instr(c, i, j);
			constexpr key_type action	= ins[FI::action];
			constexpr auto nH0		= U_opt_pack_Vs<Ws...>;

			if constexpr (action == FA::cons)
			{
				constexpr auto val = U_opt_pack_Vs<W0, Ps...>;

				return NIK_MACHINE(d, n, c, i, j, Vs)(nH0, H1, H2, H3, val, As...);
			}
			else if constexpr (action == FA::push)
			{
				constexpr auto val = U_opt_pack_Vs<Ps..., W0>;

				return NIK_MACHINE(d, n, c, i, j, Vs)(nH0, H1, H2, H3, val, As...);
			}
			else if constexpr (action == FA::op_map)
			{
				constexpr auto val = U_opt_pack_Vs<W0(Ps)...>;

				return NIK_MACHINE(d, n, c, i, j, Vs)(nH0, H1, H2, H3, val, As...);
			}
			else // FA::act_map
			{
				constexpr auto val = U_opt_pack_Vs<T_type_U<W0>::template result<Ps>...>;

				return NIK_MACHINE(d, n, c, i, j, Vs)(nH0, H1, H2, H3, val, As...);
			}
		}
	};

/***********************************************************************************************************************/

// select argument zero:

	template<key_type... filler>
	struct machine<MN::select_a0, MT::id, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename Heap3,
			auto P0, auto... Ps, typename... Args
		>
		static constexpr auto result
		(
			Heap0 H0, Heap1 H1, Heap2 H2, Heap3 H3,
			nik_vpcr(A0)(auto_pack<P0, Ps...>*), Args... As
		)
		{
			using tn				= T_type_U<n>;
			constexpr auto ins			= tn::instr(c, i, j);
			constexpr key_type action		= ins[FI::action];

			if constexpr (action == FA::car)
			{
				return NIK_BEGIN_MACHINE(d, n, c, i, j),

				       P0, Vs...

				NIK_END_MACHINE(H0, H1, H2, H3, A0, As...);
			}
			else // FA::cdr
			{
				constexpr auto val = U_opt_pack_Vs<Ps...>;

				return NIK_MACHINE(d, n, c, i, j, Vs)(H0, H1, H2, H3, val, As...);
			}
		}
	};

/***********************************************************************************************************************/

// catenate arguments zero and one:

	template<key_type... filler>
	struct machine<MN::catenate_a0_a1, MT::replace_at_a0, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename Heap3,
			auto... Ps, auto... Qs, typename... Args
		>
		static constexpr auto result
		(
			Heap0 H0, Heap1 H1, Heap2 H2, Heap3 H3,
			nik_vpcr(A0)(auto_pack<Ps...>*), nik_vpcr(A1)(auto_pack<Qs...>*), Args... As
		)
		{
			constexpr auto val = U_opt_pack_Vs<Ps..., Qs...>;

			return NIK_MACHINE(d, n, c, i, j, Vs)(H0, H1, H2, H3, val, A1, As...);
		}
	};

/***********************************************************************************************************************/

// zip arguments zero and one:

	template<key_type... filler>
	struct machine<MN::zip_a0_a1, MT::replace_at_a0, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto W0, auto... Ws, typename Heap1, typename Heap2, typename Heap3,
			auto... Ps, auto... Qs, typename... Args
		>
		static constexpr auto result
		(
			nik_vpcr(H0)(auto_pack<W0, Ws...>*), Heap1 H1, Heap2 H2, Heap3 H3,
			nik_vpcr(A0)(auto_pack<Ps...>*), nik_vpcr(A1)(auto_pack<Qs...>*), Args... As
		)
		{
			using tn			= T_type_U<n>;
			constexpr auto ins		= tn::instr(c, i, j);
			constexpr key_type action	= ins[FI::action];

			if constexpr (action == FA::op_zip)
			{
				constexpr auto val = U_opt_pack_Vs<W0(Ps, Qs)...>;

				return NIK_MACHINE(d, n, c, i, j, Vs)(H0, H1, H2, H3, val, A1, As...);
			}
			else // FA::act_zip
			{
				constexpr auto val = U_opt_pack_Vs<T_type_U<W0>::template result<Ps, Qs>...>;

				return NIK_MACHINE(d, n, c, i, j, Vs)(H0, H1, H2, H3, val, A1, As...);
			}
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

