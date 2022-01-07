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

// machines source:

	// The narrative design is for policies to be nested:

	// We dispatch <detour, call> by policy, but the policy embedded in the call instruction is intended
	// only for the final value returned from the call. In order to dispatch correctly within generalized
	// detour chains, we would need a way of specifying subpolicies. This would be done using machinations.

	// With that said, in this specific context, such nesting can be optimized away using careful designs.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// Heap policy:

		// Heap zero:

			// Stores and moves single objects.
			// Privileges front mutations.

		// Heap one:

			// Stores and moves entire packs.
			// Privileges back mutations.

		// Heap two:

			// Stores and moves entire stacks.
			// Privileges function calls.

		// Heap three:

			// Stores and moves entire heaps.
			// Privileges function calls.

/***********************************************************************************************************************/

	// Replacing the existing controller with an "inlined" equivalent is the preferred
	// implementation, but the gcc/clang compilers issue too many type misalignments.
	// As such, any convenience machines such as call rely on tail function calls.

/***********************************************************************************************************************/

	// constexpr monad (design):

//		template<key_type... filler>
//		struct machine<MN::(((name))), (((note))), filler...>
//		{
//			template
//			<
//				// stack1:

//					auto n, auto c, auto d, auto i, auto j, auto... Vs,

//				// stack2:

//					typename... Heaps
//			>
//			static constexpr auto result(Heaps... Hs)
//			{
//				return machine
//				<
//					T_type_U<n>::next_name(c, d, i, j),
//					T_type_U<n>::next_note(c, d, i, j)

//				>::template result
//				<
//					n, c,

//					T_type_U<n>::next_depth(d),
//					T_type_U<n>::next_index1(c, d, i, j),
//					T_type_U<n>::next_index2(c, d, i, j),

//					Vs...	// The behaviour of each
//						// machine is such that it
//				>(Hs...);	// mutates these packs.
//			}
//		};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

public:

// null:

	using null_type			= decltype(U_opt_pack_Vs<>);
	static constexpr null_type null	= U_opt_pack_Vs<>;

/***********************************************************************************************************************/

// machination:

	// Do not refactor using other templated structs. Although these definitions are potentially redundant,
	// trampolining/detouring require a distinct keyword so there's no confusion with other returned values.

private:

	template<typename Stack1Cache, typename Stack2Cache>
	struct machination
	{
		key_type m;

		Stack1Cache s1;
		Stack2Cache s2;

		constexpr machination(key_type _m, const Stack1Cache & _s1, const Stack2Cache & _s2) :
					m{_m}, s1{_s1}, s2{_s2} { }
	};

	//

	template<typename T>
	static constexpr bool is_machination(T) { return false; }

	template<typename Stack1Cache, typename Stack2Cache>
	static constexpr bool is_machination(const machination<Stack1Cache, Stack2Cache> &) { return true; }

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

// rest:

	template<key_type... filler>
	struct machine<MN::value, MT::rest, filler...>
	{
		template<NIK_CONTR_PARAMS, auto V0, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps...)
		{
			return U_opt_pack_Vs<Vs...>;
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

// registers (debugger):

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

// arguments (debugger):

	template<key_type... filler>
	struct machine<MN::value, MT::arguments, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename Heap3, typename... Args
		>
		static constexpr auto result(Heap0, Heap1, Heap2, Heap3, Args...)
		{
			return U_prepack_Ts<Args...>;
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// interoperators (call):

/***********************************************************************************************************************/

// block:

	template<key_type... filler>
	struct machine<MN::call, MT::block, filler...>
	{
		static constexpr auto _m = MT::id;
		static constexpr auto _n = U_block_program;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename Heap3, typename... Args
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heap2 H2, Heap3 H3, Args... As)
		{
			using tn		= T_type_U<n>;

			constexpr auto call_ins	= tn::instr(c, i, j);
			constexpr auto _c	= T_block_program::template make<call_ins>;
			constexpr auto pos	= call_ins[BCI::pos];
			constexpr auto _j	= T_block_program::max_index2(pos);
			constexpr auto _i	= pos + _j;

			constexpr auto nH2	= U_opt_pack_Vs<_m, _n, _c, _i, _j, Vs...>;
			constexpr auto nH3	= U_prepack_Ts<Heap0, Heap1, Heap2, Heap3, Args...>;

			return NIK_INTERNAL(d, n, c, i, j, Vs)(H0, H1, nH2, nH3, As...);
		}
	};

/***********************************************************************************************************************/

// linear:

	template<key_type... filler>
	struct machine<MN::call, MT::linear, filler...>
	{
		static constexpr auto _m = MT::id;
		static constexpr auto _n = U_block_program;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename Heap3, typename... Args
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heap2 H2, Heap3 H3, Args... As)
		{
			using tn			= T_type_U<n>;

			constexpr auto call_ins		= tn::instr(c, i, j);
			constexpr index_type length	= MI::length(call_ins) + 1;
			constexpr index_type size	= length - LCI::offset;
			constexpr auto _c		= make_linear_program<>;
			constexpr auto _j		= T_block_program::max_index2(size);
			constexpr auto _i		= size + _j;

			constexpr auto _H0		= U_opt_pack_Vs<call_ins, length>;
			constexpr auto _H2		= U_opt_pack_Vs<Vs...>;
			constexpr auto _H3		= U_prepack_Ts<Heap0, Heap1, Heap2, Heap3, Args...>;
			constexpr auto nH2		= U_opt_pack_Vs<_m, _n, _c, _i, _j>;
			constexpr auto nH3		= U_opt_pack_Vs<_H0, null, _H2, _H3>;

			return NIK_INTERNAL(d, n, c, i, j, Vs)(H0, H1, nH2, nH3, As...);
		}
	};

/***********************************************************************************************************************/

// user:

	template<key_type... filler>
	struct machine<MN::call, MT::user, filler...>
	{
		static constexpr auto _m = MT::id;
		static constexpr auto _n = U_linear_program;
		static constexpr auto _i = T_linear_program::initial_i;
		static constexpr auto _j = T_linear_program::initial_j;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename Heap3, typename... Args
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heap2 H2, Heap3 H3, Args... As)
		{
			using tn			= T_type_U<n>;

			constexpr auto call_ins		= tn::instr(c, i, j);
			constexpr index_type length	= MI::length(call_ins) + 1;
			constexpr index_type size	= length - UCI::offset;
			constexpr auto _c		= run_user_program
							<
								call_ins[UCI::prog], call_ins[UCI::pos], size
							>;

			constexpr auto _H0		= U_opt_pack_Vs<call_ins, length>;
			constexpr auto _H2		= U_opt_pack_Vs<Vs...>;
			constexpr auto _H3		= U_prepack_Ts<Heap0, Heap1, Heap2, Heap3, Args...>;

			constexpr auto nH2		= U_opt_pack_Vs<_m, _n, _c, _i, _j, Vs...>;
			constexpr auto nH3		= U_opt_pack_Vs<_H0, null, _H2, _H3>;

			return NIK_INTERNAL(d, n, c, i, j, Vs)(H0, H1, nH2, nH3, As...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// interoperators (detour):

/***********************************************************************************************************************/

// (internal) call:

	template<key_type... filler>
	struct machine<MN::detour, MT::call, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, typename Heap1,
			auto _m, auto _n, auto _c, auto _i, auto _j, auto... _Vs,
			auto _H0, auto _H1, auto _H2, auto _H3, auto... _As, typename... Args
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<Ws...>*), Heap1 H1,
			void(*H2)(auto_pack<_m, _n, _c, _i, _j, _Vs...>*),
			void(*H3)(auto_pack<_H0, _H1, _H2, _H3, _As...>*), Args... As
		)
		{
			using tn			= T_type_U<n>;
			constexpr auto val		= NIK_AUTOMATA(d, _m, _n, _c, _i, _j, _Vs)
								(_H0, _H1, _H2, _H3, _As...);
			constexpr auto call_ins		= tn::instr(c, i, j);
			constexpr key_type policy	= call_ins[CI::call_policy];

			if constexpr (is_machination(val))

					// optimization: Assumes _H2, _H3 are stored in val.

				return NIK_AUTOMATA(d, val.m, n, c, i, j, Vs)(H0, H1, val.s1, val.s2, As...);

			else if constexpr (policy == MT::insert_at_h0_back)

				return NIK_MACHINE(d, n, c, i, j, Vs)(U_opt_pack_Vs<Ws..., val>, H1, _H2, _H3, As...);

			else if constexpr (policy == MT::insert_at_h0_front)

				return NIK_MACHINE(d, n, c, i, j, Vs)(U_opt_pack_Vs<val, Ws...>, H1, _H2, _H3, As...);

			else // policy == id:

				return val;
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
			auto... nVs, auto... nHs, typename... Args
		>
		static constexpr auto result
		(
			Heap0 H0, Heap1 H1,
			void(*H2)(auto_pack<nVs...>*),
			void(*H3)(auto_pack<nHs...>*), Args... As
		)
		{
			return NIK_MACHINE(d, n, c, i, j, nVs)(nHs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// interoperators (machinate):

/***********************************************************************************************************************/

// pause:

	template<key_type... filler>
	struct machine<MN::machinate, MT::pause, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps...)
		{
			constexpr auto s1 = U_opt_pack_Vs<m, n, c, i, j, Vs...>;
			constexpr auto s2 = U_prepack_Ts<Heaps...>;

			return machination(MT::call, s1, s2);
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
			constexpr auto s1 = U_opt_pack_Vs<Vs...>;
			constexpr auto s2 = U_prepack_Ts<Heaps...>;

			return machination(MT::load, s1, s2);
		}
	};

/***********************************************************************************************************************/

// reindex:

	// doesn't quite work (just yet).

	template<key_type... filler>
	struct machine<MN::machinate, MT::reindex, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, auto ni, auto... Ws, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<ni, Ws...>*), Heaps...)
		{
			using tn		= T_type_U<n>;
			constexpr auto nj	= tn::initial_j;
			constexpr auto nH0	= U_opt_pack_Vs<Ws...>;
			constexpr auto s1	= U_opt_pack_Vs<m, n, c, ni, nj, Vs...>;
			constexpr auto s2	= U_opt_pack_Vs<nH0, U_pretype_T<Heaps>...>;

			return machination(MT::load, s1, s2);
		}
	};

/***********************************************************************************************************************/

// linear:

		// This is an optimization: The narrative design would be to return the unpacked
		// params where a *detour linear* (analogous to *call linear*) would then create
		// the linear program of interest and request it to be run.

	template<key_type... filler>
	struct machine<MN::machinate, MT::linear, filler...>
	{
		static constexpr auto _m = MT::id;
		static constexpr auto _n = U_linear_program;
		static constexpr auto _i = T_linear_program::initial_i;
		static constexpr auto _j = T_linear_program::initial_j;

		template
		<
			NIK_CONTR_PARAMS,
			auto call_ins, auto length, auto... Ws,
			typename Heap1, auto... _Vs,
			auto _H0, auto _H1, auto _H2, auto _H3, auto... _As
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<call_ins, length, Ws...>*),
			Heap1 H1,
			void(*H2)(auto_pack<_Vs...>*),
			void(*H3)(auto_pack<_H0, _H1, _H2, _H3, _As...>*)
		)
		{
			constexpr auto _c = T_linear_program::template make<call_ins, Ws...>;
			constexpr auto s1 = U_opt_pack_Vs<_m, _n, _c, _i, _j, _Vs...>;
		//	constexpr auto s2 = U_pretype_T<decltype(_H3)>;

			return machination(MT::call, s1, H3);
		//	return machination(MT::call, s1, s2);
		}
	};

/***********************************************************************************************************************/

// preuser:

/*
	template<key_type... filler>
	struct machine<MN::machinate, MT::preuser, filler...>
	{
		static constexpr auto nm = MT::id;
		static constexpr auto nn = U_linear_program;
		static constexpr auto ni = T_linear_program::initial_i;
		static constexpr auto nj = T_linear_program::initial_j;

		static constexpr auto _m = MT::id;
		static constexpr auto _n = U_user_program;
		static constexpr auto _i = T_user_program::initial_i;
		static constexpr auto _j = T_user_program::initial_j;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto call_ins, auto length, auto U_UP, auto... Ws,
			typename Heap1, auto... _Vs,
			auto _H0, auto _H1, auto _H2, auto _H3, auto... _As,
			typename... Args
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<call_ins, length, U_UP, Ws...>*),
			Heap1 H1,
			void(*H2)(auto_pack<_Vs...>*),
			void(*H3)(auto_pack<_H0, _H1, _H2, _H3, _As...>*),
			Args...
		)
		{
			using T_UP		= T_type_U<U_UP>;

			constexpr auto nc	= call_user_program<>;
			constexpr auto s1	= U_opt_pack_Vs<nm, nn, nc, ni, nj, Vs...>;

			constexpr auto nH0	= U_pretype_T<decltype(H3)>;
			constexpr auto nH1	= U_pretype_T<decltype(H1)>;

			constexpr auto _c	= T_UP::template lines<Ws...>;
			constexpr auto nH2	= U_opt_pack_Vs<_m, _n, _c, _i, _j, _Vs...>;

			constexpr auto s2	= U_opt_pack_Vs<nH0, nH1, nH2, nH0>; // nH3 == nH0

			return machination(MT::call, s1, s2);
		}
	};
*/

/***********************************************************************************************************************/

// user:

	template<key_type... filler>
	struct machine<MN::machinate, MT::user, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename Heap0, typename... Heaps>
		static constexpr auto result(Heap0 H0, Heaps...)
		{
			constexpr auto s1 = U_opt_pack_Vs<Vs...>;
			constexpr auto s2 = U_pretype_T<decltype(H0)>;

			return machination(MT::load, s1, s2);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block passers:

/***********************************************************************************************************************/

// unpack instruction block, insert at heap zero back (2^N):

	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H0_BACK(0);
	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H0_BACK(1);
	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H0_BACK(2);
	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H0_BACK(3);
	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H0_BACK(4);
	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H0_BACK(5);
	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H0_BACK(6);
	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H0_BACK(7);
	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H0_BACK(8);
	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H0_BACK(9);

/***********************************************************************************************************************/

// drop register block (2^N):

	NIK_DEFINE__DROP_R_BLOCK(0);
	NIK_DEFINE__DROP_R_BLOCK(1);
	NIK_DEFINE__DROP_R_BLOCK(2);
	NIK_DEFINE__DROP_R_BLOCK(3);
	NIK_DEFINE__DROP_R_BLOCK(4);
	NIK_DEFINE__DROP_R_BLOCK(5);
	NIK_DEFINE__DROP_R_BLOCK(6);
	NIK_DEFINE__DROP_R_BLOCK(7);
	NIK_DEFINE__DROP_R_BLOCK(8);
	NIK_DEFINE__DROP_R_BLOCK(9);

/***********************************************************************************************************************/

// move register block, insert at heap one back (2^N):

	NIK_DEFINE__MOVE_R_BLOCK__INSERT_AT_H1_BACK(0);
	NIK_DEFINE__MOVE_R_BLOCK__INSERT_AT_H1_BACK(1);
	NIK_DEFINE__MOVE_R_BLOCK__INSERT_AT_H1_BACK(2);
	NIK_DEFINE__MOVE_R_BLOCK__INSERT_AT_H1_BACK(3);
	NIK_DEFINE__MOVE_R_BLOCK__INSERT_AT_H1_BACK(4);
	NIK_DEFINE__MOVE_R_BLOCK__INSERT_AT_H1_BACK(5);
	NIK_DEFINE__MOVE_R_BLOCK__INSERT_AT_H1_BACK(6);
	NIK_DEFINE__MOVE_R_BLOCK__INSERT_AT_H1_BACK(7);
	NIK_DEFINE__MOVE_R_BLOCK__INSERT_AT_H1_BACK(8);
	NIK_DEFINE__MOVE_R_BLOCK__INSERT_AT_H1_BACK(9);

/***********************************************************************************************************************/

// fold register block (2^N):

/***********************************************************************************************************************/

// roll register block (2^N):

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear passers:

/***********************************************************************************************************************/

// move heap zero first, insert at registers front:

	template<key_type... filler>
	struct machine<MN::move_h0_first, MT::insert_at_r_front, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto W0, auto... Ws, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<W0, Ws...>*), Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(d, n, c, i, j),

				W0, Vs...

			NIK_END_MACHINE(U_opt_pack_Vs<Ws...>, Hs...);
		}
	};

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
		static constexpr auto result(Heap0 H0, void(*H1)(auto_pack<Xs...>*), Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(d, n, c, i, j),

				Xs..., Vs...

			NIK_END_MACHINE(H0, null, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// user passers:

/***********************************************************************************************************************/

// copy instruction value, insert at heap zero front:

	template<key_type... filler>
	struct machine<MN::copy_i_value, MT::insert_at_h0_front, filler...>
	{
		static constexpr index_type value = 3;

		template<NIK_CONTR_PARAMS, auto... Vs, auto... Ws, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)
		{
			using tn		= T_type_U<n>;
			constexpr auto ins	= tn::instr(c, i, j);

			return NIK_MACHINE(d, n, c, i, j, Vs)(U_opt_pack_Vs<ins[value], Ws...>, Hs...);
		}
	};

/***********************************************************************************************************************/

// branch:

/*
	template<key_type... filler>
	struct machine<MN::branch, MT::id, filler...>
	{
		static constexpr index_type index = 3;

		template<NIK_CONTR_PARAMS, auto... Vs, bool is_br, auto... Ws, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<is_br, Ws...>*), Heaps... Hs)
		{
			using tn		= T_type_U<n>;

			constexpr auto ins	= tn::instr(c, i, j);
			constexpr auto ni	= is_br ? ins[index] : i;
			constexpr auto nj	= is_br ? _zero : j;

			return NIK_MACHINE(d, n, c, ni, nj, Vs)(U_opt_pack_Vs<Ws...>, Hs...);
		}
	};
*/

/***********************************************************************************************************************/

// apply heap zero all, insert at registers front (V_apply_VxVs):

	template<key_type... filler>
	struct machine<MN::apply_h0_all, MT::insert_at_r_front, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, auto op, auto... args, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<op, args...>*), Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(d, n, c, i, j),

				op(args...), Vs...

			NIK_END_MACHINE(null, Hs...);
		}
	};

/***********************************************************************************************************************/

// apply heap zero all, replace at heap zero front (V_apply_VxVs):

	template<key_type... filler>
	struct machine<MN::apply_h0_all, MT::replace_at_h0_front, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, auto op, auto... args, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<op, args...>*), Heaps... Hs)
		{
			constexpr auto nH0 = U_opt_pack_Vs
			<
				op(args...)
			>;

			return NIK_MACHINE(d, n, c, i, j, Vs)(nH0, Hs...);
		}
	};

/***********************************************************************************************************************/

// compel heap zero all, insert at registers front (V_apply_ExVs):

	template<key_type... filler>
	struct machine<MN::compel_h0_all, MT::insert_at_r_front, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, auto uact, auto... args, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<uact, args...>*), Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(d, n, c, i, j),

				T_type_U<uact>::template result<args...>, Vs...
			
			NIK_END_MACHINE(null, Hs...);
		}
	};

/***********************************************************************************************************************/

// compel heap zero all, replace at heap zero front (V_apply_ExVs):

	template<key_type... filler>
	struct machine<MN::compel_h0_all, MT::replace_at_h0_front, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, auto uact, auto... args, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<uact, args...>*), Heaps... Hs)
		{
			constexpr auto nH0 = U_opt_pack_Vs
			<
				T_type_U<uact>::template result<args...>
			>;

			return NIK_MACHINE(d, n, c, i, j, Vs)(nH0, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// start:

public:

	template<typename program, auto... Vs, auto... Is>
	static constexpr auto start(void(*)(auto_pack<Is...>*) = null)
	{
		constexpr auto d	= program::depth;
		constexpr auto n	= U_linear_program;
		constexpr auto c	= label<call_linear_program<LN::id, MT::id>>;
		constexpr auto i	= T_linear_program::initial_i;
		constexpr auto j	= T_linear_program::next_index2(c, i, T_linear_program::initial_j);

		constexpr auto _m	= MT::id;
		constexpr auto _n	= U_type_T<program>;
		constexpr auto _c	= program::template lines<index_type{Is}...>;
		constexpr auto _i	= program::initial_i;
		constexpr auto _j	= program::initial_j;

		constexpr auto nH2	= U_opt_pack_Vs<_m, _n, _c, _i, _j, Vs...>;
		constexpr auto nH3	= U_opt_pack_Vs<null, null, null, null>;

		return NIK_BEGIN_INTERNAL(d, n, c, i, j) NIK_END_INTERNAL(null, null, nH2, nH3);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

