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

// machines source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machines:

	template<key_type, key_type, key_type...> struct machine;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// halters (value):

/***********************************************************************************************************************/

// first:

	template<key_type... filler>
	struct machine<MN::value, MT::first, filler...>
	{
		template<NIK_CONTR_PARAMS, auto V0, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps...)
		{
			return V0;
		}
	};

/***********************************************************************************************************************/

// heap zero:

	template<key_type... filler>
	struct machine<MN::value, MT::h0, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename Heap0, typename... Heaps>
		static constexpr auto result(Heap0 H0, Heaps...)
		{
			return H0;
		}
	};

/***********************************************************************************************************************/

// heap one:

	template<key_type... filler>
	struct machine<MN::value, MT::h1, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename Heap0, typename Heap1, typename... Heaps>
		static constexpr auto result(Heap0, Heap1 H1, Heaps...)
		{
			return H1;
		}
	};

/***********************************************************************************************************************/

// argument zero:

	template<key_type... filler>
	struct machine<MN::value, MT::a0, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_HEAP_TYPENAMES, typename Arg0, typename... Args
		>
		static constexpr auto result(NIK_HEAP_VARS, Arg0 A0, Args...)
		{
			return A0;
		}
	};

/***********************************************************************************************************************/

// registers:

	template<key_type... filler>
	struct machine<MN::value, MT::registers, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps...)
		{
			return U_opt_pack_Vs<Vs...>;
		}
	};

/***********************************************************************************************************************/

// arguments:

	template<key_type... filler>
	struct machine<MN::value, MT::arguments, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			NIK_HEAP_TYPENAMES, typename... Args
		>
		static constexpr auto result(NIK_HEAP_VARS, Args...)
		{
			return U_prepack_Ts<Args...>;
		}
	};

/***********************************************************************************************************************/

// depth (debugger):

	template<key_type... filler>
	struct machine<MN::value, MT::depth, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps...)
		{
			return d;
		}
	};

/***********************************************************************************************************************/

// dump (debugger):

	template<key_type... filler>
	struct machine<MN::value, MT::dump, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps...)
		{
			constexpr auto s1 = U_opt_pack_Vs<d, m, n, c, i, j, Vs...>;
			constexpr auto s2 = U_prepack_Ts<Heaps...>;

			return U_opt_pack_Vs<s1, s2>;
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block passers:

/***********************************************************************************************************************/

// index block (2^N):

	NIK_DEFINE__INDEX_BLOCK(0);
	NIK_DEFINE__INDEX_BLOCK(1);
	NIK_DEFINE__INDEX_BLOCK(2);
	NIK_DEFINE__INDEX_BLOCK(3);

/***********************************************************************************************************************/

// move register block (2^N):

	NIK_DEFINE__MOVE_R_BLOCK(0);
	NIK_DEFINE__MOVE_R_BLOCK(1);
	NIK_DEFINE__MOVE_R_BLOCK(2);
	NIK_DEFINE__MOVE_R_BLOCK(3);
	NIK_DEFINE__MOVE_R_BLOCK(4);
	NIK_DEFINE__MOVE_R_BLOCK(5);
	NIK_DEFINE__MOVE_R_BLOCK(6);
	NIK_DEFINE__MOVE_R_BLOCK(7);
	NIK_DEFINE__MOVE_R_BLOCK(8);
	NIK_DEFINE__MOVE_R_BLOCK(9);

/***********************************************************************************************************************/

// fold register block (2^N):

	NIK_DEFINE__FOLD_R_BLOCK(0);
	NIK_DEFINE__FOLD_R_BLOCK(1);
	NIK_DEFINE__FOLD_R_BLOCK(2);
	NIK_DEFINE__FOLD_R_BLOCK(3);
	NIK_DEFINE__FOLD_R_BLOCK(4);
	NIK_DEFINE__FOLD_R_BLOCK(5);
	NIK_DEFINE__FOLD_R_BLOCK(6);
	NIK_DEFINE__FOLD_R_BLOCK(7);
	NIK_DEFINE__FOLD_R_BLOCK(8);

#ifdef GCC_IMPLEMENTATION

//	NIK_DEFINE__FOLD_R_BLOCK(9);

#endif // GCC_IMPLEMENTATION

	template<key_type... filler>
	struct machine<MN::fold_r_block, _nine, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto V, NIK_2_N_AUTO_VARS(9, V), auto... Vs,
			auto W0, auto... Ws, typename... Heaps
		>
		static constexpr auto result(nik_vpcr(H0)(auto_pack<W0, Ws...>*), Heaps... Hs)
		{
			using tn		= T_type_U<n>;
			constexpr auto ins	= tn::instr(c, i, j);

			if constexpr (ins[BI::policy] == CP::al_at_h0_front)
			{
				using alias = T_type_U<W0>;

				return NIK_BEGIN_MACHINE(d, n, c, i, j),

					NIK_2_N_AL_FOLDS(9, alias, V), Vs...

				NIK_END_MACHINE(H0, Hs...);
			}
			else
			{
				constexpr auto val = NIK_2_N_OP_FOLDS(8, W0, V);

				return NIK_BEGIN_MACHINE(d, n, c, i, j),

					NIK_2_N_OP_FOLDS(8, val, V), Vs...

				NIK_END_MACHINE(H0, Hs...);
			}
		}
	};

/***********************************************************************************************************************/

// move argument block (2^N):

	NIK_DEFINE__MOVE_A_BLOCK(0);
	NIK_DEFINE__MOVE_A_BLOCK(1);
	NIK_DEFINE__MOVE_A_BLOCK(2);
	NIK_DEFINE__MOVE_A_BLOCK(3);
	NIK_DEFINE__MOVE_A_BLOCK(4);
	NIK_DEFINE__MOVE_A_BLOCK(5);
	NIK_DEFINE__MOVE_A_BLOCK(6);
	NIK_DEFINE__MOVE_A_BLOCK(7);
	NIK_DEFINE__MOVE_A_BLOCK(8);
	NIK_DEFINE__MOVE_A_BLOCK(9);

/***********************************************************************************************************************/

// copy register position (optimization):

	template<key_type Note, key_type... filler>
	struct machine<MN::copy_r_pos, Note, filler...>
	{
		static constexpr index_type pos = 3;

		template<NIK_CONTR_PARAMS, auto... Vs, typename Heap0, typename Heap1, typename... Heaps>
		static constexpr auto result(Heap0, Heap1, Heaps... Hs)
		{
			using tn		= T_type_U<n>;
			constexpr auto ins	= tn::instr(c, i, j);
			constexpr auto val	= Fast<ins[pos]>::template at<Vs...>;

			constexpr auto cH0	= U_pretype_T<Heap0>;
			constexpr auto cH1	= U_pretype_T<Heap1>;

			constexpr auto index	= (Note == MT::insert_at_h0_back) ? _zero : _one;
			constexpr auto cHn	= Fast<index>::template at<cH0, cH1>;

			constexpr auto nH0	= PE::template append<val>(cHn);

			return NIK_MACHINE(d, n, c, i, j, Vs)(nH0, Hs...);
		}
	};

/***********************************************************************************************************************/

// copy argument position (optimization):

	template<key_type Note, key_type... filler>
	struct machine<MN::copy_a_pos, Note, filler...>
	{
		static constexpr index_type pos = 3;

		template<NIK_CONTR_PARAMS, auto... Vs, NIK_HEAP_TYPENAMES, typename... Args>
		static constexpr auto result(NIK_HEAP_VARS, Args... As)
		{
			using tn		= T_type_U<n>;
			constexpr auto ins	= tn::instr(c, i, j);
			constexpr auto val	= Fast<ins[pos]>::template at<U_pretype_T<Args>...>;

			constexpr auto cH0	= U_pretype_T<Heap0>;
			constexpr auto cH1	= U_pretype_T<Heap1>;

			constexpr auto index	= (Note == MT::insert_at_h0_back) ? _zero : _one;
			constexpr auto cHn	= Fast<index>::template at<cH0, cH1>;

			constexpr auto algo	= PE::translate(Note);
			constexpr auto nH0	= Pack<algo>::template result<cHn, val>;

			return NIK_MACHINE(d, n, c, i, j, Vs)(nH0, H1, H2, H3, H4, H5, As...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear passers:

/***********************************************************************************************************************/

// move heap zero first, insert at registers front:

/*
	template<key_type... filler>
	struct machine<MN::move_h0_first, MT::insert_at_r_front, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto W0, auto... Ws, typename... Heaps
		>
		static constexpr auto result(nik_vpcr(H0)(auto_pack<W0, Ws...>*), Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(d, n, c, i, j),

				W0, Vs...

			NIK_END_MACHINE(U_opt_pack_Vs<Ws...>, Hs...);
		}
	};
*/

/***********************************************************************************************************************/

// move heap one all, insert at registers front:

	template<key_type... filler>
	struct machine<MN::move_h1_all, MT::insert_at_r_front, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, auto... Xs, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, nik_vpcr(H1)(auto_pack<Xs...>*), Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(d, n, c, i, j),

				Xs..., Vs...

			NIK_END_MACHINE(H0, U_null_Vs, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// recursive passers:

/***********************************************************************************************************************/

// cycle:

	template<key_type... filler>
	struct machine<MN::go_to, MT::first, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			using tn		= T_type_U<n>;
			constexpr auto ni	= tn::initial_i;
			constexpr auto nj	= tn::initial_j;

			return NIK_MACHINE(d, n, c, ni, nj, Vs)(Hs...);
		}
	};

/***********************************************************************************************************************/

// apply heap zero all, insert at registers front (V_apply_VxVs):

/*
	template<key_type... filler>
	struct machine<MN::call_h0_all, MT::insert_at_r_front, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, auto W0, auto... Ws, typename... Heaps>
		static constexpr auto result(nik_vpcr(H0)(auto_pack<W0, Ws...>*), Heaps... Hs)
		{
			if constexpr (policy == )

				return NIK_BEGIN_MACHINE(d, n, c, i, j),

					W0(Ws...), Vs...

				NIK_END_MACHINE(U_null_Vs, Hs...);
			else
				return NIK_BEGIN_MACHINE(d, n, c, i, j),

					T_type_U<W0>::template result<Ws...>, Vs...
			
				NIK_END_MACHINE(U_null_Vs, Hs...);
		}
	};
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// call:

/***********************************************************************************************************************/

// id:

	template<key_type... filler>
	struct machine<MN::call, MT::id, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, NIK_HEAP_TYPENAMES, typename... Args>
		static constexpr auto result(NIK_HEAP_VARS, Args... As)
		{
			using tn		= T_type_U<n>;
			constexpr auto ins	= tn::instr(c, i, j);
			constexpr auto shape	= CT::open; // CT::shape(ins);

			constexpr auto cH0	= U_null_Vs;
			constexpr auto cH1	= U_pretype_T<Heap1>;
			constexpr auto cH2	= U_pretype_T<Heap2>;
			constexpr auto cH3	= U_pretype_T<Heap3>;
			constexpr auto cH4	= U_pretype_T<Heap4>;
			constexpr auto cH5	= U_pretype_T<Heap5>;

			constexpr auto nH2	= Make<shape>::template h2<ins, Vs...>(U_pretype_T<Heap0>);
			constexpr auto nH3	= U_opt_pack_Vs<NIK_HEAP_CARGS, U_pretype_T<Args>...>;

			return NIK_INTERNAL(d, n, c, i, j, Vs)(H0, H1, nH2, nH3, H4, H5, As...);
		}
	};

/***********************************************************************************************************************/

// optimal:

	template<key_type... filler>
	struct machine<MN::call, MT::optimal, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, NIK_HEAP_TYPENAMES, typename... Args>
		static constexpr auto result(NIK_HEAP_VARS, Args... As)
		{
			using tn		= T_type_U<n>;
			constexpr auto ins	= tn::instr(c, i, j);

			constexpr auto caller	= ins[CI::caller_pos];
			constexpr auto prog	= RG::template U_program<ins>;
			constexpr auto params	= QF::template U_params<ins>();

			constexpr auto nH2	= Resolve<caller>::template h2<ins, Vs...>(prog, params);
			constexpr auto nH3	= U_prepack_Ts<NIK_HEAP_TYPES, Args...>;

			return NIK_INTERNAL(d, n, c, i, j, Vs)(H0, H1, nH2, nH3, H4, H5, As...);
		}
	};

/***********************************************************************************************************************/

// retrieve:

	template<key_type... filler>
	struct machine<MN::call, MT::retrieve, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto locs, auto poses, auto h0,
			typename Heap1, typename Heap2, typename Heap3,
			typename Heap4, typename Heap5, typename... Args
		>
		static constexpr auto result
		(
			nik_vpcr(H0)(auto_pack<locs, poses, h0>*),
			Heap1 H1, Heap2 H2, Heap3 H3,
			Heap4 H4, Heap5 H5, Args... As
		)
		{
			constexpr auto cHs	= U_prepack_Ts<Heap2, Heap3, Heap4, Args...>;
			const auto mac		= Retrieve::template program<h0, Vs...>(locs, poses, cHs);

			return NIK_INTERNAL(d, n, c, i, j, Vs)(h0, H1, mac.h2, mac.h3, H4, H5, As...);
				// here we need c's current location to be a call instruction
				// with policy to replace h0.
		}
	};

/***********************************************************************************************************************/

// fetch:

	template<key_type... filler>
	struct machine<MN::call, MT::fetch, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, NIK_HEAP_TYPENAMES, typename... Args>
		static constexpr auto result(NIK_HEAP_VARS, Args... As)
		{
			using tn		= T_type_U<n>;
			constexpr auto ins	= tn::instr(c, i, j);

			constexpr auto cVs	= U_opt_pack_Vs<Vs...>;
			constexpr auto cHs	= U_prepack_Ts<NIK_HEAP_TYPES, Args...>;
			constexpr auto mac	= Fetch::template program<ins>(cVs, cHs);

			return NIK_INTERNAL(d, n, c, i, j, Vs)(H0, H1, mac.h2, mac.h3, H4, H5, As...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// detour:

/***********************************************************************************************************************/

// internal:

	template<key_type... filler>
	struct machine<MN::detour, MT::internal, filler...>
	{
		static constexpr index_type index = 3;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, typename Heap1,
			auto _m, auto _n, auto _c, auto _i, auto _j, auto... _Vs,
			auto _H0, auto _H1, auto _H2, auto _H3, auto... _Hs, typename... Args
		>
		static constexpr auto result
		(
			nik_vpcr(H0)(auto_pack<Ws...>*), Heap1 H1,
			nik_vpcr(H2)(auto_pack<_m, _n, _c, _i, _j, _Vs...>*),
			nik_vpcr(H3)(auto_pack<_H0, _H1, _H2, _H3, _Hs...>*), Args... As
		)
		{
			using tn			= T_type_U<n>;
			constexpr auto val		= NIK_AUTOMATA(d, _m, _n, _c, _i, _j, _Vs)
								(_H0, _H1, U_null_Vs, U_null_Vs, _Hs...);
			constexpr auto call_ins		= tn::instr(c, i, j);
			constexpr key_type policy	= call_ins[CI::policy];

			if constexpr (is_machination(val))

					// optimization: Assumes _H2, _H3 are stored in val.

				return NIK_AUTOMATA(d, val.m, n, c, i, j, Vs)(H0, H1, val.h2, val.h3, As...);

			else if constexpr (policy == CP::insert_at_r_front)

				return NIK_BEGIN_MACHINE(d, n, c, i, j),

					val, Vs...

				NIK_END_MACHINE(H0, H1, _H2, _H3, As...);

			else if constexpr (policy == CP::insert_at_h0_back)

				return NIK_MACHINE(d, n, c, i, j, Vs)(U_opt_pack_Vs<Ws..., val>, H1, _H2, _H3, As...);

			else if constexpr (policy == CP::insert_at_h0_front)

				return NIK_MACHINE(d, n, c, i, j, Vs)(U_opt_pack_Vs<val, Ws...>, H1, _H2, _H3, As...);

			else // if constexpr (policy == CP::id)

				return val;

		//	else // CP::conditional:
		//	{
		//		constexpr auto ins	= tn::instr(c, i, j);
		//		constexpr auto ni	= val ? ins[index] : i;
		//		constexpr auto nj	= val ? _zero : j;

		//		return NIK_MACHINE(d, n, c, ni, nj, Vs)(U_opt_pack_Vs<Ws...>, Hs...);
		//	}
		}
	};

/***********************************************************************************************************************/

// load:

	template<key_type... filler>
	struct machine<MN::detour, MT::load, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1,
			auto... _Vs, auto... _Hs, typename... Args
		>
		static constexpr auto result
		(
			Heap0 H0, Heap1 H1,
			nik_vpcr(H2)(auto_pack<_Vs...>*),
			nik_vpcr(H3)(auto_pack<_Hs...>*), Args... As
		)
		{
			return NIK_MACHINE(d, n, c, i, j, _Vs)(_Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machinate:

/***********************************************************************************************************************/

// pause:

	template<key_type... filler>
	struct machine<MN::machinate, MT::pause, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps...)
		{
			constexpr auto h2 = U_opt_pack_Vs<m, n, c, i, j, Vs...>;
			constexpr auto h3 = U_prepack_Ts<Heaps...>;

			return machination(MT::internal, h2, h3);
		}
	};

/***********************************************************************************************************************/

// unwind:

	template<key_type... filler>
	struct machine<MN::machinate, MT::unwind, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps...)
		{
			constexpr auto h2 = U_opt_pack_Vs<Vs...>;
			constexpr auto h3 = U_prepack_Ts<Heaps...>;

			return machination(MT::load, h2, h3);
		}
	};

/***********************************************************************************************************************/

// rewind:

	template<key_type... filler>
	struct machine<MN::machinate, MT::rewind, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto ins, auto length, auto... Ws,
			auto... Xs, auto... Ys,
			typename Heap3, typename... Heaps
		>
		static constexpr auto result
		(
			nik_vpcr(H0)(auto_pack<ins, length, Ws...>*),
			nik_vpcr(H1)(auto_pack<Xs...>*),
			nik_vpcr(H2)(auto_pack<Ys...>*),
			Heap3 H3, Heaps...
		)
		{
			constexpr auto shape = CT::open; // CT::shape(ins);
			constexpr auto pack  = U_opt_pack_Vs<Ws..., Xs..., Ys...>;

			constexpr auto h2    = Make<shape>::template h2<ins, Vs...>(pack);

			return machination(MT::internal, h2, H3);
		}
	};

/***********************************************************************************************************************/

// fetch:

/*
	template<key_type... filler>
	struct machine<MN::machinate, MT::fetch, filler...>
	{
		static constexpr index_type pos = 3;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, auto... Ys, typename... Heaps
		>
		static constexpr auto result(Heap0, Heap1, nik_vpcr(H2)(auto_pack<Ys...>*), Heaps...)
		{
			using tn		= T_type_U<n>;
			constexpr auto ins	= tn::instr(c, i, j);
			constexpr auto loc	= ins[pos];
			constexpr auto nc	= Build::template locations<Ys...>(loc);

			constexpr auto cH0	= U_pretype_T<Heap0>;
			constexpr auto cH1	= U_pretype_T<Heap1>;

			constexpr auto h2	= RL::template U_prog_h2<nc, Vs...>;
			constexpr auto h3	= U_opt_pack_Vs<cH0, cH1, U_null_Vs, U_pretype_T<Heaps>...>;

			return machination(MT::internal, h2, h3);
		}
	};
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// start:

public:

/*
	template<typename program, auto... Vs, auto... Is, typename... Args>
	static constexpr auto start(nik_avpcr(auto_pack<Is...>*), Args...)
	{
		constexpr auto d	= program::depth;
		constexpr auto n	= U_linear_program;
		constexpr auto c	= label<detour_call<CP::id>>;
		constexpr auto i	= T_linear_program::initial_i;
		constexpr auto j	= T_linear_program::initial_j;

					= RL::U_prog_h2<c, >;

		constexpr auto _m	= MT::id;
		constexpr auto _n	= U_type_T<program>;
		constexpr auto _c	= program::template lines<index_type{Is}...>;
		constexpr auto _i	= program::initial_i;
		constexpr auto _j	= program::initial_j;

					= Resolve<base>::template h2<ins, Vs...>(prog, params);

		constexpr auto nH2	= U_opt_pack_Vs<_m, _n, _c, _i, _j, Vs...>;
		constexpr auto nH3	= U_opt_pack_Vs<U_null_Vs, U_null_Vs, U_null_Vs, U_null_Vs, U_pretype_T<Args>...>;

		return NIK_BEGIN_MACHINE(d, n, c, i, j) NIK_END_MACHINE(U_null_Vs, U_null_Vs, nH2, nH3);
	}
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

