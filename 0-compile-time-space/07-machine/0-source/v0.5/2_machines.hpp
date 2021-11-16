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
/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// constexpr monad (design):

//		template<key_type... filler>
//		struct machine<MN::(((name))), (((note))), filler...>
//		{
//			template
//			<
//				// stack:

//					auto n, auto c, auto d, auto i, auto j, auto... Vs,

//				// heaps:

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

// machines:

private:

	template<key_type, key_type, key_type...> struct machine;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// interposers:

/***********************************************************************************************************************/

// pause:

	template<key_type... filler>
	struct machine<MN::pause, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			constexpr auto sc = U_opt_pack_Vs<n, c, i, j, Vs...>;
			constexpr auto hc = U_pre_pack_Ts<Heaps...>;

			return machination(sc, hc);
		}
	};

/***********************************************************************************************************************/

// sleep:

	template<key_type... filler>
	struct machine<MN::sleep, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			constexpr auto sc = U_opt_pack_Vs<n, c, i, j, Vs...>;
			constexpr auto hc = U_pre_pack_Ts<Heaps...>;

			return loadable(sc, hc);
		}
	};

/***********************************************************************************************************************/

// branch:

	template<key_type... filler>
	struct machine<MN::branch, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			bool is_br, auto... Ws, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<is_br, Ws...>*), Heaps... Hs)
		{
			using p			= T_type_U<n>;

			constexpr auto ni	= is_br ? p::val(c, i, j) : i;
			constexpr auto nj	= is_br ? _zero : j;

			return NIK_MACHINE(n, c, d, ni, nj, Vs)(U_opt_pack_Vs<Ws...>, Hs...);
		}
	};

/***********************************************************************************************************************/

// shift range block, insert at stack back (2^N):

	NIK_DEFINE__SHIFT_R_BLOCK__INSERT_AT_S_BACK(0);
	NIK_DEFINE__SHIFT_R_BLOCK__INSERT_AT_S_BACK(1);
	NIK_DEFINE__SHIFT_R_BLOCK__INSERT_AT_S_BACK(2);
	NIK_DEFINE__SHIFT_R_BLOCK__INSERT_AT_S_BACK(3);
	NIK_DEFINE__SHIFT_R_BLOCK__INSERT_AT_S_BACK(4);
	NIK_DEFINE__SHIFT_R_BLOCK__INSERT_AT_S_BACK(5);
	NIK_DEFINE__SHIFT_R_BLOCK__INSERT_AT_S_BACK(6);
	NIK_DEFINE__SHIFT_R_BLOCK__INSERT_AT_S_BACK(7);
	NIK_DEFINE__SHIFT_R_BLOCK__INSERT_AT_S_BACK(8);
	NIK_DEFINE__SHIFT_R_BLOCK__INSERT_AT_S_BACK(9);

/***********************************************************************************************************************/

// load (block):

	template<key_type... filler>
	struct machine<MN::load, MT::block, filler...>
	{
		using bp = block_program<>;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename Heap3, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heap2 H2, Heap3 H3, Heaps... Hs)
		{
			constexpr auto nc	= block_program<bp::subname(c, i, j)>::controller;
			constexpr auto pos	= bp::subpos(c, i, j);
			constexpr auto nj	= bp::max_index2(pos);
			constexpr auto ni	= pos + nj;

			constexpr auto nH2	= U_opt_pack_Vs<U_block_program, nc, ni, nj, Vs...>;
			constexpr auto nH3	= U_pre_pack_Ts<Heap0, Heap1, Heap2, Heap3, Heaps...>;

			return NIK_MACHINE(n, c, d, i, j, Vs)(H0, H1, nH2, nH3, Hs...);
		}
	};

/***********************************************************************************************************************/

// restack:

	template<key_type... filler>
	struct machine<MN::restack, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1,
			auto nn, auto nc, auto ni, auto nj, auto... nVs,
			auto nH0, auto nH1, auto nH2, auto nH3, auto... nHs, typename... Heaps
		>
		static constexpr auto result
		(
			Heap0 H0, Heap1 H1,
			void(*H2)(auto_pack<nn, nc, ni, nj, nVs...>*),
			void(*H3)(auto_pack<nH0, nH1, nH2, nH3, nHs...>*), Heaps... Hs
		)
		{
			return NIK_MACHINE(n, c, d, i, j, nVs)
			(
				nH0, nH1,
				U_opt_pack_Vs<nn, nc, ni, nj, Vs...>,
				U_opt_pack_Vs
				<
					U_type_T<T_pretype_T<Heap0>>,
					U_type_T<T_pretype_T<Heap1>>,
					nH2, nH3,
					U_type_T<T_pretype_T<Heaps>>...
				>,

				nHs...
			);
		}
	};

/***********************************************************************************************************************/

// call (trampoline apply):

	template<key_type... filler>
	struct machine<MN::call, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, typename Heap1,
			auto nn, auto nc, auto ni, auto nj, auto... nVs,
			auto... nHs, typename... Heaps
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<Ws...>*), Heap1 H1,
			void(*H2)(auto_pack<nn, nc, ni, nj, nVs...>*),
			void(*H3)(auto_pack<nHs...>*), Heaps... Hs
		)
		{
			constexpr auto val	= NIK_MACHINE(nn, nc, d, ni, nj, nVs)(nHs...);
			constexpr auto nd	= T_type_U<n>::next_depth(d);

			if constexpr (nd == d)

				return NIK_MACHINE(n, c, d, i, j, Vs)(H0, H1, H2, Hs...);

			else if constexpr (is_machination(val))

				return machine::template result<n, c, nd, i, j, Vs...>(H0, H1, val.sc, val.hc, Hs...);

			else if constexpr (is_loadable(val))

				return NIK_MACHINE(n, c, d, i, j, Vs)(H0, H1, val.sc, val.hc, Hs...);

			else
				return NIK_MACHINE(n, c, d, i, j, Vs)
					(U_opt_pack_Vs<val, Ws...>, H1, U_opt_pack_Vs<>, U_opt_pack_Vs<>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// halters:

/***********************************************************************************************************************/

// result:

	template<key_type... filler>
	struct machine<MN::result, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, auto W0, auto... Ws, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<W0, Ws...>*), Heaps... Hs)
		{
			return W0;
		}
	};

/***********************************************************************************************************************/

// first:

	template<key_type... filler>
	struct machine<MN::first, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto V0, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			return V0;
		}
	};

/***********************************************************************************************************************/

// rest:

	template<key_type... filler>
	struct machine<MN::rest, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto V0, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			return U_opt_pack_Vs<Vs...>;
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// debuggers:

/***********************************************************************************************************************/

// depth:

	template<key_type... filler>
	struct machine<MN::depth, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			return d;
		}
	};

/***********************************************************************************************************************/

// dump:

	template<key_type... filler>
	struct machine<MN::dump, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			constexpr auto sc = U_opt_pack_Vs<n, c, i, j, Vs...>;
			constexpr auto hc = U_pre_pack_Ts<Heaps...>;

			return U_opt_pack_Vs<sc, hc>;
		}
	};

/***********************************************************************************************************************/

// stack:

	template<key_type... filler>
	struct machine<MN::stack, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			return U_opt_pack_Vs<Vs...>;
		}
	};

/***********************************************************************************************************************/

// heaps:

	template<key_type... filler>
	struct machine<MN::heaps, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			return U_pre_pack_Ts<Heaps...>;
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (stack -> stack):

/***********************************************************************************************************************/

// drop stack block (2^N):

	NIK_DEFINE__DROP_S_BLOCK(0);
	NIK_DEFINE__DROP_S_BLOCK(1);
	NIK_DEFINE__DROP_S_BLOCK(2);
	NIK_DEFINE__DROP_S_BLOCK(3);
	NIK_DEFINE__DROP_S_BLOCK(4);
	NIK_DEFINE__DROP_S_BLOCK(5);
	NIK_DEFINE__DROP_S_BLOCK(6);
	NIK_DEFINE__DROP_S_BLOCK(7);
	NIK_DEFINE__DROP_S_BLOCK(8);
	NIK_DEFINE__DROP_S_BLOCK(9);

/***********************************************************************************************************************/

// drop stack position (optimization):

	NIK_DEFINE__DROP_S_POS(1, 0, 0);
	NIK_DEFINE__DROP_S_POS(2, 1, 1);
	NIK_DEFINE__DROP_S_POS(3, 2, 1);
	NIK_DEFINE__DROP_S_POS(4, 3, 1);
	NIK_DEFINE__DROP_S_POS(5, 4, 1);
	NIK_DEFINE__DROP_S_POS(6, 5, 1);
	NIK_DEFINE__DROP_S_POS(7, 6, 1);
	NIK_DEFINE__DROP_S_POS(8, 7, 1);

/***********************************************************************************************************************/

// fold stack block, op at heap zero first (2^N):

	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(0);
	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(1);
	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(2);
	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(3);
	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(4);
	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(5);
	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(6);
	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(7);
	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(8);

#ifdef GCC_IMPLEMENTATION

//	NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(9);

#endif // GCC_IMPLEMENTATION

		// clang: bracket nesting level defaults to a maximum of 256

	template<key_type... filler>
	struct machine<MN::fold_s_block__op_at_h0_first, _nine, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto V, NIK_2_9_AUTO_VS, auto... Vs,
			auto op, auto... Ws, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<op, Ws...>*), Heaps... Hs)
		{
			constexpr auto val = NIK_2_8_OPS  V,  NIK_2_8_OP_VS;

			return NIK_BEGIN_MACHINE(n, c, d, i, j),

				NIK_2_8_OPS  val,  NIK_UPPER_512_OP_VS, Vs...

			NIK_END_MACHINE(H0, Hs...);
		}
	};

/***********************************************************************************************************************/

// roll stack block, act at heap zero first (2^N):

	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(0);
	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(1);
	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(2);
	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(3);
	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(4);
	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(5);
	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(6);
	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(7);
	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(8);
	NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(9);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (stack -> heap):

/***********************************************************************************************************************/

// move stack block, insert at heap zero front (2^N):

	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(0);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(1);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(2);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(3);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(4);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(5);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(6);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(7);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(8);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(9);

/***********************************************************************************************************************/

// move stack block, insert at heap one back (2^N):

	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(0);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(1);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(2);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(3);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(4);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(5);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(6);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(7);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(8);
	NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(9);

/***********************************************************************************************************************/

// copy stack block, insert at heap zero front (2^N):

	NIK_DEFINE__COPY_S_BLOCK__INSERT_AT_H0_FRONT(0);

/***********************************************************************************************************************/

// copy stack block, insert at heap zero back (2^N):

	NIK_DEFINE__COPY_S_BLOCK__INSERT_AT_H0_BACK(0);

/***********************************************************************************************************************/

// copy stack position, insert at heap zero front (optimization):

	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(1, 0);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(2, 1);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(3, 2);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(4, 3);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(5, 4);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(6, 5);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(7, 6);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(8, 7);

/***********************************************************************************************************************/

// copy stack position, insert at heap zero back (optimization):

	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_BACK(1, 0);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_BACK(2, 1);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_BACK(3, 2);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_BACK(4, 3);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_BACK(5, 4);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_BACK(6, 5);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_BACK(7, 6);
	NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_BACK(8, 7);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers (heap -> stack):

/***********************************************************************************************************************/

// move heap zero first, insert at stack front:

	template<key_type... filler>
	struct machine<MN::move_h0_first__insert_at_s_front, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto W0, auto... Ws, typename... Heaps
		>
		static constexpr auto result(void(*H0)(auto_pack<W0, Ws...>*), Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(n, c, d, i, j),

				W0, Vs...

			NIK_END_MACHINE(U_opt_pack_Vs<Ws...>, Hs...);
		}
	};

/***********************************************************************************************************************/

// move heap zero first, insert at stack position (optimization):

	NIK_DEFINE__MOVE_H0_FIRST__INSERT_AT_S_POS(0, 0);
	NIK_DEFINE__MOVE_H0_FIRST__INSERT_AT_S_POS(1, 1);
	NIK_DEFINE__MOVE_H0_FIRST__INSERT_AT_S_POS(2, 1);
	NIK_DEFINE__MOVE_H0_FIRST__INSERT_AT_S_POS(3, 1);
	NIK_DEFINE__MOVE_H0_FIRST__INSERT_AT_S_POS(4, 1);
	NIK_DEFINE__MOVE_H0_FIRST__INSERT_AT_S_POS(5, 1);
	NIK_DEFINE__MOVE_H0_FIRST__INSERT_AT_S_POS(6, 1);
	NIK_DEFINE__MOVE_H0_FIRST__INSERT_AT_S_POS(7, 1);

/***********************************************************************************************************************/

// move heap zero first, replace at stack position (optimization):

	NIK_DEFINE__MOVE_H0_FIRST__REPLACE_AT_S_POS(1, 0, 0);
	NIK_DEFINE__MOVE_H0_FIRST__REPLACE_AT_S_POS(2, 1, 1);
	NIK_DEFINE__MOVE_H0_FIRST__REPLACE_AT_S_POS(3, 2, 1);
	NIK_DEFINE__MOVE_H0_FIRST__REPLACE_AT_S_POS(4, 3, 1);
	NIK_DEFINE__MOVE_H0_FIRST__REPLACE_AT_S_POS(5, 4, 1);
	NIK_DEFINE__MOVE_H0_FIRST__REPLACE_AT_S_POS(6, 5, 1);
	NIK_DEFINE__MOVE_H0_FIRST__REPLACE_AT_S_POS(7, 6, 1);
	NIK_DEFINE__MOVE_H0_FIRST__REPLACE_AT_S_POS(8, 7, 1);

/***********************************************************************************************************************/

// move heap one all, insert at stack front:

	template<key_type... filler>
	struct machine<MN::move_h1_all__insert_at_s_front, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, auto... Ws, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, void(*H1)(auto_pack<Ws...>*), Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(n, c, d, i, j),

				Ws..., Vs...

			NIK_END_MACHINE(H0, U_opt_pack_Vs<>, Hs...);
		}
	};

/***********************************************************************************************************************/

// start:

public:

	template<typename program, auto... Vs, auto... Ws, auto... Xs, auto... Ys, auto... Zs>
	static constexpr auto start
	(
		void(*H0)(auto_pack<Ws...>*) = U_opt_pack_Vs<>,
		void(*H1)(auto_pack<Xs...>*) = U_opt_pack_Vs<>,
		void(*H2)(auto_pack<Ys...>*) = U_opt_pack_Vs<>,
		void(*H3)(auto_pack<Zs...>*) = U_opt_pack_Vs<>
	)
	{
		using lp		= linear_program<>;

		constexpr auto oH0	= U_opt_pack_Vs<Ws...>;
		constexpr auto oH1	= U_opt_pack_Vs<Xs...>;
		constexpr auto oH2	= U_opt_pack_Vs<Ys...>;
		constexpr auto oH3	= U_opt_pack_Vs<Zs...>;

		constexpr auto nH3	= U_opt_pack_Vs<oH0, oH1, oH2, oH3>;
		constexpr auto nH2	= U_opt_pack_Vs
		<
			U_type_T<program>,
			program::controller,
			program::initial_i,
			program::initial_j,

			Vs...
		>;

		return machine<MN::call, _zero>::template result
		<
			U_linear_program,
			label<result<>>,
			program::depth,
			lp::initial_i,
			lp::initial_j

		>(oH0, oH1, nH2, nH3);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

