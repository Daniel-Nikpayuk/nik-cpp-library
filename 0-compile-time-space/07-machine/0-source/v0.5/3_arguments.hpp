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

// arguments source:

private:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicate argument:

/***********************************************************************************************************************/

// argument zero:

	template<key_type... filler>
	struct machine<MN::predicate, MT::using_a0, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, typename Heap1, typename Heap2, typename Heap3,
			auto... Ps, typename... Args
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<Ws...>*), Heap1 H1, Heap2 H2, Heap3 H3,
			void(*A0)(auto_pack<Ps...>*), Args... As
		)
		{
			constexpr bool is_null	= (sizeof...(Ps) == 0);
			constexpr auto nH0	= U_opt_pack_Vs<is_null, Ws...>;

			return NIK_MACHINE(d, n, c, i, j, Vs)(nH0, H1, H2, H3, A0, As...);
		}
	};

/***********************************************************************************************************************/

// argument one:

	template<key_type... filler>
	struct machine<MN::predicate, MT::using_a1, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, typename Heap1, typename Heap2, typename Heap3,
			typename Arg0, auto... Qs, typename... Args
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<Ws...>*), Heap1 H1, Heap2 H2, Heap3 H3,
			Arg0 A0, void(*A1)(auto_pack<Qs...>*), Args... As
		)
		{
			constexpr bool is_null	= (sizeof...(Qs) == 0);
			constexpr auto nH0	= U_opt_pack_Vs<is_null, Ws...>;

			return NIK_MACHINE(d, n, c, i, j, Vs)(nH0, H1, H2, H3, A0, A1, As...);
		}
	};

/***********************************************************************************************************************/

// argument two:

	template<key_type... filler>
	struct machine<MN::predicate, MT::using_a2, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, typename Heap1, typename Heap2, typename Heap3,
			typename Arg0, typename Arg1, auto... Rs, typename... Args
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<Ws...>*), Heap1 H1, Heap2 H2, Heap3 H3,
			Arg0 A0, Arg1 A1, void(*A2)(auto_pack<Rs...>*), Args... As
		)
		{
			constexpr bool is_null	= (sizeof...(Rs) == 0);
			constexpr auto nH0	= U_opt_pack_Vs<is_null, Ws...>;

			return NIK_MACHINE(d, n, c, i, j, Vs)(nH0, H1, H2, H3, A0, A1, A2, As...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// construct argument:

/***********************************************************************************************************************/

// argument zero:

	template<key_type... filler>
	struct machine<MN::construct, MT::using_a0, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto W0, auto... Ws, typename Heap1, typename Heap2, typename Heap3,
			auto... Ps, typename... Args
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<W0, Ws...>*), Heap1 H1, Heap2 H2, Heap3 H3,
			void(*A0)(auto_pack<Ps...>*), Args... As
		)
		{
			using tn			= T_type_U<n>;
			constexpr auto ins		= tn::instr(c, i, j);
			constexpr key_type action	= ins[FI::action];
			constexpr key_type option	= ins[FI::option];
			constexpr auto nH0		= U_opt_pack_Vs<Ws...>;

			if constexpr (action == MT::cons)
			{
				constexpr auto val	= U_opt_pack_Vs<W0, Ps...>;

				if constexpr (option == MT::insert_at_r_front)

					return NIK_BEGIN_MACHINE(d, n, c, i, j),

					       val, Vs...

					NIK_END_MACHINE(nH0, H1, H2, H3, A0, As...);
				else
					return NIK_MACHINE(d, n, c, i, j, Vs)(nH0, H1, H2, H3, val, As...);
			}
			else // MT::push
			{
				constexpr auto val	= U_opt_pack_Vs<Ps..., W0>;

				if constexpr (option == MT::insert_at_r_front)

					return NIK_BEGIN_MACHINE(d, n, c, i, j),

					       val, Vs...

					NIK_END_MACHINE(nH0, H1, H2, H3, A0, As...);
				else
					return NIK_MACHINE(d, n, c, i, j, Vs)(nH0, H1, H2, H3, val, As...);
			}
		}
	};

/***********************************************************************************************************************/

// argument one:

	template<key_type... filler>
	struct machine<MN::construct, MT::using_a1, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto W0, auto... Ws, typename Heap1, typename Heap2, typename Heap3,
			typename Arg0, auto... Qs, typename... Args
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<W0, Ws...>*), Heap1 H1, Heap2 H2, Heap3 H3,
			Arg0 A0, void(*A1)(auto_pack<Qs...>*), Args... As
		)
		{
			using tn			= T_type_U<n>;
			constexpr auto ins		= tn::instr(c, i, j);
			constexpr key_type action	= ins[FI::action];
			constexpr key_type option	= ins[FI::option];
			constexpr auto nH0		= U_opt_pack_Vs<Ws...>;

			if constexpr (action == MT::cons)
			{
				constexpr auto val	= U_opt_pack_Vs<W0, Qs...>;

				if constexpr (option == MT::insert_at_r_front)

					return NIK_BEGIN_MACHINE(d, n, c, i, j),

					       val, Vs...

					NIK_END_MACHINE(nH0, H1, H2, H3, A0, A1, As...);
				else
					return NIK_MACHINE(d, n, c, i, j, Vs)(nH0, H1, H2, H3, A0, val, As...);
			}

			else // MT::push
			{
				constexpr auto val	= U_opt_pack_Vs<Qs..., W0>;

				if constexpr (option == MT::insert_at_r_front)

					return NIK_BEGIN_MACHINE(d, n, c, i, j),

					       val, Vs...

					NIK_END_MACHINE(nH0, H1, H2, H3, A0, A1, As...);
				else
					return NIK_MACHINE(d, n, c, i, j, Vs)(nH0, H1, H2, H3, A0, val, As...);
			}
		}
	};

/***********************************************************************************************************************/

// argument two:

	template<key_type... filler>
	struct machine<MN::construct, MT::using_a2, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto W0, auto... Ws, typename Heap1, typename Heap2, typename Heap3,
			typename Arg0, typename Arg1, auto... Rs, typename... Args
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<W0, Ws...>*), Heap1 H1, Heap2 H2, Heap3 H3,
			Arg0 A0, Arg1 A1, void(*A2)(auto_pack<Rs...>*), Args... As
		)
		{
			using tn			= T_type_U<n>;
			constexpr auto ins		= tn::instr(c, i, j);
			constexpr key_type action	= ins[FI::action];
			constexpr key_type option	= ins[FI::option];
			constexpr auto nH0		= U_opt_pack_Vs<Ws...>;

			if constexpr (action == MT::cons)
			{
				constexpr auto val	= U_opt_pack_Vs<W0, Rs...>;

				if constexpr (option == MT::insert_at_r_front)

					return NIK_BEGIN_MACHINE(d, n, c, i, j),

					       val, Vs...

					NIK_END_MACHINE(nH0, H1, H2, H3, A0, A1, A2, As...);
				else
					return NIK_MACHINE(d, n, c, i, j, Vs)(nH0, H1, H2, H3, A0, A1, val, As...);
			}
			else // MT::push
			{
				constexpr auto val	= U_opt_pack_Vs<Rs..., W0>;

				if constexpr (option == MT::insert_at_r_front)

					return NIK_BEGIN_MACHINE(d, n, c, i, j),

					       val, Vs...

					NIK_END_MACHINE(nH0, H1, H2, H3, A0, A1, A2, As...);
				else
					return NIK_MACHINE(d, n, c, i, j, Vs)(nH0, H1, H2, H3, A0, A1, val, As...);
			}
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// select argument:

/***********************************************************************************************************************/

// argument zero:

	template<key_type... filler>
	struct machine<MN::select, MT::using_a0, filler...>
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
			void(*A0)(auto_pack<P0, Ps...>*), Args... As
		)
		{
			using tn				= T_type_U<n>;
			constexpr auto ins			= tn::instr(c, i, j);
			constexpr key_type action		= ins[FI::action];

			if constexpr (action == MT::car)

				return NIK_BEGIN_MACHINE(d, n, c, i, j),

				       P0, Vs...

				NIK_END_MACHINE(H0, H1, H2, H3, A0, As...);

			else // MT::cdr
			{
				constexpr auto rest		= U_opt_pack_Vs<Ps...>;
				constexpr key_type option	= ins[FI::option];

				if constexpr (option == MT::insert_at_r_front)

					return NIK_BEGIN_MACHINE(d, n, c, i, j),

					       rest, Vs...

					NIK_END_MACHINE(H0, H1, H2, H3, A0, As...);
				else
					return NIK_MACHINE(d, n, c, i, j, Vs)(H0, H1, H2, H3, rest, As...);
			}
		}
	};

/***********************************************************************************************************************/

// argument one:

	template<key_type... filler>
	struct machine<MN::select, MT::using_a1, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename Heap3,
			typename Arg0, auto Q0, auto... Qs, typename... Args
		>
		static constexpr auto result
		(
			Heap0 H0, Heap1 H1, Heap2 H2, Heap3 H3,
			Arg0 A0, void(*A1)(auto_pack<Q0, Qs...>*), Args... As
		)
		{
			using tn				= T_type_U<n>;
			constexpr auto ins			= tn::instr(c, i, j);
			constexpr key_type action		= ins[FI::action];

			if constexpr (action == MT::car)

				return NIK_BEGIN_MACHINE(d, n, c, i, j),

				       Q0, Vs...

				NIK_END_MACHINE(H0, H1, H2, H3, A0, A1, As...);

			else // MT::cdr
			{
				constexpr auto rest		= U_opt_pack_Vs<Qs...>;
				constexpr key_type option	= ins[FI::option];

				if constexpr (option == MT::insert_at_r_front)

					return NIK_BEGIN_MACHINE(d, n, c, i, j),

					       rest, Vs...

					NIK_END_MACHINE(H0, H1, H2, H3, A0, A1, As...);
				else
					return NIK_MACHINE(d, n, c, i, j, Vs)(H0, H1, H2, H3, A0, rest, As...);
			}
		}
	};

/***********************************************************************************************************************/

// argument two:

	template<key_type... filler>
	struct machine<MN::select, MT::using_a2, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename Heap3,
			typename Arg0, typename Arg1, auto R0, auto... Rs, typename... Args
		>
		static constexpr auto result
		(
			Heap0 H0, Heap1 H1, Heap2 H2, Heap3 H3,
			Arg0 A0, Arg1 A1, void(*A2)(auto_pack<R0, Rs...>*), Args... As
		)
		{
			using tn				= T_type_U<n>;
			constexpr auto ins			= tn::instr(c, i, j);
			constexpr key_type action		= ins[FI::action];

			if constexpr (action == MT::car)

				return NIK_BEGIN_MACHINE(d, n, c, i, j),

				       R0, Vs...

				NIK_END_MACHINE(H0, H1, H2, H3, A0, A1, A2, As...);

			else // MT::cdr
			{
				constexpr auto rest		= U_opt_pack_Vs<Rs...>;
				constexpr key_type option	= ins[FI::option];

				if constexpr (option == MT::insert_at_r_front)

					return NIK_BEGIN_MACHINE(d, n, c, i, j),

					       rest, Vs...

					NIK_END_MACHINE(H0, H1, H2, H3, A0, A1, A2, As...);
				else
					return NIK_MACHINE(d, n, c, i, j, Vs)(H0, H1, H2, H3, A0, A1, rest, As...);
			}
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

