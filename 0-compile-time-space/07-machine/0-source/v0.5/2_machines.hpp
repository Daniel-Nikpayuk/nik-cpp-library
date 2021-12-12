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

//					auto n, auto c, auto d, auto m, auto i, auto j, auto... Vs,

//				// stack2:

//					typename... Heaps
//			>
//			static constexpr auto result(Heaps... Hs)
//			{
//				return machine
//				<
//					T_type_U<n>::next_name(c, d, m, i, j),
//					T_type_U<n>::next_note(c, d, m, i, j)

//				>::template result
//				<
//					n, c,

//					T_type_U<n>::next_depth(d),
//					m,
//					T_type_U<n>::next_index1(c, d, m, i, j),
//					T_type_U<n>::next_index2(c, d, m, i, j),

//					Vs...	// The behaviour of each
//						// machine is such that it
//				>(Hs...);	// mutates these packs.
//			}
//		};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// interposition:

public:

	using null_type			= decltype(U_opt_pack_Vs<>);
	static constexpr null_type null	= U_opt_pack_Vs<>;

/***********************************************************************************************************************/

// machination:

private:

		// Do not refactor using other templated structs. Although this definition is potentially redundant,
		// trampolining requires a distinct keyword so that there's no confusion with any other returned value.

	template<typename StackCache, typename HeapCache>
	struct machination
	{
		StackCache sc;
		HeapCache hc;

		constexpr machination(const StackCache & _sc, const HeapCache & _hc) :
			sc(_sc), hc(_hc) { }
	};

	//

	template<typename T>
	static constexpr bool is_machination(T) { return false; }

	template<typename StackCache, typename HeapCache>
	static constexpr bool is_machination(const machination<StackCache, HeapCache> &) { return true; }

/***********************************************************************************************************************/

// loadable:

		// Do not refactor using other templated structs. Although this definition is potentially redundant,
		// loadability requires a distinct keyword so that there's no confusion with any other returned value.

	template<typename StackCache, typename HeapCache>
	struct loadable
	{
		StackCache sc;
		HeapCache hc;

		constexpr loadable(const StackCache & _sc, const HeapCache & _hc) :
			sc(_sc), hc(_hc) { }
	};

	//

	template<typename T>
	static constexpr bool is_loadable(T) { return false; }

	template<typename StackCache, typename HeapCache>
	static constexpr bool is_loadable(const loadable<StackCache, HeapCache> &) { return true; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machines:

	template<key_type, key_type, key_type...> struct machine;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// interposers:

/***********************************************************************************************************************/

// pause:

	template<key_type... filler>
	struct machine<MN::pause, MT::id, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps...)
		{
			constexpr auto sc = U_opt_pack_Vs<n, c, m, i, j, Vs...>;
			constexpr auto hc = U_prepack_Ts<Heaps...>;

			return machination(sc, hc);
		}
	};

/***********************************************************************************************************************/

// call (between):

		// { Vs... , Hs... } passing policy: copy/lift.

	template<key_type... filler>
	struct machine<MN::call, MT::between, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, auto... Xs,
			auto nn, auto nc, auto nm, auto ni, auto nj, auto... nVs,
			auto nH0, auto nH1, auto nH2, auto nH3, auto... nHs, typename... Args
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<Ws...>*),
			void(*H1)(auto_pack<Xs...>*),
			void(*H2)(auto_pack<nn, nc, nm, ni, nj, nVs...>*),
			void(*H3)(auto_pack<nH0, nH1, nH2, nH3, nHs...>*), Args... As
		)
		{
			using tn			= T_type_U<n>;

			constexpr auto val		= NIK_AUTOMATA(nn, nc, d, nm, ni, nj, nVs)
								(nH0, nH1, nH2, nH3, nHs...);
			constexpr auto call_ins		= tn::instr(c, i, j);
			constexpr key_type memonic	= call_ins[CI::memonic];
			constexpr key_type location	= call_ins[CI::location];

			if constexpr (is_machination(val))

				return NIK_AUTOMATA(n, c, d, MN::call, i, j, Vs)(H0, H1, val.sc, val.hc, As...);

			else if constexpr (memonic == PM::id && location == PL::id)

				return val;

			else if constexpr (memonic == PM::stage2 && location == PL::id)

				return NIK_AUTOMATA(n, c, d, MN::overwrite, i, j, Vs)(H0, H1, val.sc, val.hc, As...);

			else if constexpr (memonic == PM::heap_zero)
			{
				if constexpr (location == PL::front)

					return NIK_MACHINE(n, c, d, i, j, Vs)
						(U_opt_pack_Vs<val, Ws...>, H1, nH2, nH3, As...);
				else
					return NIK_MACHINE(n, c, d, i, j, Vs)
						(U_opt_pack_Vs<Ws..., val>, H1, nH2, nH3, As...);
			}
			else if constexpr (memonic == PM::heap_one)
			{
				if constexpr (location == PL::front)

					return NIK_MACHINE(n, c, d, i, j, Vs)
						(H0, U_opt_pack_Vs<val, Xs...>, nH2, nH3, As...);
				else
					return NIK_MACHINE(n, c, d, i, j, Vs)
						(H0, U_opt_pack_Vs<Xs..., val>, nH2, nH3, As...);
			}
			else if constexpr (memonic == PM::registers)
			{
				if constexpr (location == PL::front)

					return NIK_BEGIN_MACHINE(n, c, d, i, j),

						val, Vs...

					NIK_END_MACHINE(H0, H1, nH2, nH3, As...);
				else
					return NIK_BEGIN_MACHINE(n, c, d, i, j),

						Vs..., val

					NIK_END_MACHINE(H0, H1, null, null, As...);
			}
			else if constexpr (memonic == PM::arguments)
			{
				if constexpr (location == PL::front)

					return NIK_MACHINE(n, c, d, i, j, Vs)(H0, H1, nH2, nH3, val, As...);
				else
					return NIK_MACHINE(n, c, d, i, j, Vs)(H0, H1, nH2, nH3, As..., val);
			}
		}
	};

/***********************************************************************************************************************/

// call (block):

		// { Vs... , Hs... } passing policy: copy.

	template<key_type... filler>
	struct machine<MN::call, MT::block, filler...>
	{
		static constexpr auto nn		= U_block_program;
		static constexpr auto nm		= MN::id;
		static constexpr auto nnm		= MN::call;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename Heap3, typename... Args
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heap2 H2, Heap3 H3, Args... As)
		{
			using tn		= T_type_U<n>;

			constexpr auto call_ins	= tn::instr(c, i, j);
			constexpr auto nc	= T_block_program::template make<call_ins>;
			constexpr auto pos	= call_ins[BCI::pos];
			constexpr auto nj	= T_block_program::max_index2(pos);
			constexpr auto ni	= pos + nj;

			constexpr auto nH2	= U_opt_pack_Vs<nn, nc, nm, ni, nj, Vs...>;
			constexpr auto nH3	= U_prepack_Ts<Heap0, Heap1, Heap2, Heap3, Args...>;

			return NIK_AUTOMATA(n, c, d, nnm, i, j, Vs)(H0, H1, nH2, nH3, As...);
		}
	};

/***********************************************************************************************************************/

// call (linear):

		// { Vs... , Hs... } passing policy: copy.

	template<key_type... filler>
	struct machine<MN::call, MT::linear, filler...>
	{
		static constexpr auto nn	= U_block_program;
		static constexpr auto nm	= MN::id;
		static constexpr auto nnm	= MN::call;

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
			constexpr auto nc		= make_unpack_i_segment__insert_at_h0_back<MT::linear>;
			constexpr auto nj		= T_block_program::max_index2(size);
			constexpr auto ni		= size + nj;

			constexpr auto nH0		= U_opt_pack_Vs<call_ins, length>;
			constexpr auto cVs		= U_opt_pack_Vs<Vs...>;
			constexpr auto cHs		= U_prepack_Ts<Heap0, Heap1, Heap2, Heap3, Args...>;
			constexpr auto nH2		= U_opt_pack_Vs<nn, nc, nm, ni, nj>;
			constexpr auto nH3		= U_opt_pack_Vs<nH0, null, cVs, cHs>;

			return NIK_AUTOMATA(n, c, d, nnm, i, j, Vs)(H0, H1, nH2, nH3, As...);
		}
	};

/***********************************************************************************************************************/

// call (user):

		// { Vs... , Hs... } passing policy: embed.

	template<key_type... filler>
	struct machine<MN::call, MT::user, filler...>
	{
		static constexpr auto nn	= U_linear_program;
		static constexpr auto nm	= MN::id;
		static constexpr auto nnm	= MN::call;
		static constexpr auto ni	= T_linear_program::initial_i;
		static constexpr auto nj	= T_linear_program::initial_j;

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
			constexpr auto nc		= make_user_program
							<
								call_ins[UCI::prog], call_ins[UCI::pos], size
							>;

			constexpr auto nnH0		= U_opt_pack_Vs<call_ins, length>;
			constexpr auto nnH2		= U_opt_pack_Vs<Vs...>;
			constexpr auto nnH3		= U_prepack_Ts<Heap0, Heap1, Heap2, Heap3, Args...>; // restore: H2, H3.

			constexpr auto nH2		= U_opt_pack_Vs<nn, nc, nm, ni, nj, Vs...>;
			constexpr auto nH3		= U_opt_pack_Vs<nnH0, null, nnH2, nnH3, U_pretype_T<Args>...>;

			return NIK_BEGIN_AUTOMATA(n, c, d, nnm, i, j) // Vs... are ignored

			NIK_END_AUTOMATA(H0, H1, nH2, nH3); // As... are ignored
		}
	};

/***********************************************************************************************************************/

// make (linear):

	template<key_type... filler>
	struct machine<MN::make, MT::linear, filler...>
	{
		static constexpr auto nn = U_linear_program;
		static constexpr auto nm = MN::id;
		static constexpr auto ni = T_linear_program::initial_i;
		static constexpr auto nj = T_linear_program::initial_j;

		template
		<
			NIK_CONTR_PARAMS,
			auto call_ins, auto length, auto... Ws,
			typename Heap1, auto... Vs,
			auto cH0, auto cH1, auto cH2, auto cH3, auto... cAs
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<call_ins, length, Ws...>*),
			Heap1 H1,
			void(*H2)(auto_pack<Vs...>*),
			void(*H3)(auto_pack<cH0, cH1, cH2, cH3, cAs...>*)
		)
		{
			constexpr auto nc	= T_linear_program::template make<call_ins, Ws...>;
			constexpr auto sc	= U_opt_pack_Vs<nn, nc, nm, ni, nj, Vs...>;
			constexpr auto hc	= U_pretype_T<decltype(H3)>;

			return machination(sc, hc);
		}
	};

/***********************************************************************************************************************/

// make (user):

	template<key_type... filler>
	struct machine<MN::make, MT::user, filler...>
	{
		static constexpr auto nn = U_linear_program;
		static constexpr auto nm = MN::id;
		static constexpr auto ni = T_linear_program::initial_i;
		static constexpr auto nj = T_linear_program::initial_j;

		static constexpr auto on = U_user_program;
		static constexpr auto om = MN::id;
		static constexpr auto oi = T_user_program::initial_i;
		static constexpr auto oj = T_user_program::initial_j;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto call_ins, auto length, auto U_UP, auto... Ws,
			typename Heap1, auto... cVs,
			auto cH0, auto cH1, auto cH2, auto cH3, auto... cAs,
			typename... Args
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<call_ins, length, U_UP, Ws...>*),
			Heap1 H1,
			void(*H2)(auto_pack<cVs...>*),
			void(*H3)(auto_pack<cH0, cH1, cH2, cH3, cAs...>*),
			Args...
		)
		{
			using T_UP		= T_type_U<U_UP>;

			constexpr auto nc	= call_user_program<>;
			constexpr auto sc	= U_opt_pack_Vs<nn, nc, nm, ni, nj, Vs...>;

			constexpr auto nH0	= U_pretype_T<decltype(H3)>;
			constexpr auto nH1	= U_pretype_T<decltype(H1)>;

			constexpr auto oc	= T_UP::template lines<Ws...>;
			constexpr auto nH2	= U_opt_pack_Vs<on, oc, om, oi, oj, cVs...>;

			constexpr auto hc	= U_opt_pack_Vs<nH0, nH1, nH2, nH0>; // nH3 == nH0

			return machination(sc, hc);
		}
	};

/***********************************************************************************************************************/

// unwind (id):

	template<key_type... filler>
	struct machine<MN::unwind, MT::id, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps...)
		{
			constexpr auto sc = U_opt_pack_Vs<Vs...>;
			constexpr auto hc = U_prepack_Ts<Heaps...>;

			return loadable(sc, hc);
		}
	};

/***********************************************************************************************************************/

// unwind (reindex):

	// doesn't quite work (just yet).

	template<key_type... filler>
	struct machine<MN::unwind, MT::reindex, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, auto ni, auto... Ws, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<ni, Ws...>*), Heaps...)
		{
			using tn		= T_type_U<n>;
			constexpr auto nj	= tn::initial_j;
			constexpr auto nH0	= U_opt_pack_Vs<Ws...>;
			constexpr auto sc	= U_opt_pack_Vs<n, c, m, ni, nj, Vs...>;
			constexpr auto hc	= U_opt_pack_Vs<nH0, U_pretype_T<Heaps>...>;

			return loadable(sc, hc);
		}
	};

/***********************************************************************************************************************/

// unwind (user):

	template<key_type... filler>
	struct machine<MN::unwind, MT::user, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename Heap0, typename... Heaps>
		static constexpr auto result(Heap0 H0, Heaps...)
		{
			constexpr auto sc = U_opt_pack_Vs<Vs...>;
			constexpr auto hc = U_pretype_T<decltype(H0)>;

			return loadable(sc, hc);
		}
	};

/***********************************************************************************************************************/

// overwrite (between):

	template<key_type... filler>
	struct machine<MN::overwrite, MT::between, filler...>
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
			return NIK_MACHINE(n, c, d, i, j, nVs)(nHs...);
		}
	};

/***********************************************************************************************************************/

// copy instruction value, insert at heap zero front:

	template<key_type... filler>
	struct machine<MN::copy_i_value__insert_at_h0_front, MT::id, filler...>
	{
		static constexpr index_type value = 3;

		template<NIK_CONTR_PARAMS, auto... Vs, auto... Ws, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)
		{
			using tn		= T_type_U<n>;
			constexpr auto ins	= tn::instr(c, i, j);

			return NIK_MACHINE(n, c, d, i, j, Vs)(U_opt_pack_Vs<ins[value], Ws...>, Hs...);
		}
	};

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

// branch:

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

			return NIK_MACHINE(n, c, d, ni, nj, Vs)(U_opt_pack_Vs<Ws...>, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// halters:

/***********************************************************************************************************************/

// first:

	template<key_type... filler>
	struct machine<MN::first, MT::id, filler...>
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
	struct machine<MN::rest, MT::id, filler...>
	{
		template<NIK_CONTR_PARAMS, auto V0, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps...)
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
	struct machine<MN::depth, MT::id, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps...)
		{
			return d;
		}
	};

/***********************************************************************************************************************/

// dump:

	template<key_type... filler>
	struct machine<MN::dump, MT::id, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps...)
		{
			constexpr auto sc = U_opt_pack_Vs<n, c, m, i, j, Vs...>;
			constexpr auto hc = U_prepack_Ts<Heaps...>;

			return U_opt_pack_Vs<sc, hc>;
		}
	};

/***********************************************************************************************************************/

// registers:

	template<key_type... filler>
	struct machine<MN::registers, MT::id, filler...>
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
	struct machine<MN::arguments, MT::id, filler...>
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

// passers:

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

// fold register block (2^N):

/***********************************************************************************************************************/

// roll register block (2^N):

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

// move heap zero first, insert at registers front:

	template<key_type... filler>
	struct machine<MN::move_h0_first__insert_at_r_front, MT::id, filler...>
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

// move heap one all, insert at registers front:

	template<key_type... filler>
	struct machine<MN::move_h1_all__insert_at_r_front, MT::id, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, auto... Xs, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, void(*H1)(auto_pack<Xs...>*), Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(n, c, d, i, j),

				Xs..., Vs...

			NIK_END_MACHINE(H0, null, Hs...);
		}
	};

/***********************************************************************************************************************/

// apply heap zero all, move, replace at heap zero front (V_apply_VxVs):

	template<key_type... filler>
	struct machine<MN::apply_h0_all__return_value, MT::id, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, auto op, auto... args, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<op, args...>*), Heaps... Hs)
		{
			return op(args...);
		}
	};

/***********************************************************************************************************************/

// apply heap zero all, move, insert at registers front (V_apply_VxVs):

	template<key_type... filler>
	struct machine<MN::apply_h0_all__move__insert_at_r_front, MT::id, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, auto op, auto... args, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<op, args...>*), Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(n, c, d, i, j),

				op(args...), Vs...

			NIK_END_MACHINE(null, Hs...);
		}
	};

/***********************************************************************************************************************/

// compel heap zero all, move, replace at heap zero front (V_apply_ExVs):

	template<key_type... filler>
	struct machine<MN::compel_h0_all__return_value, MT::id, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, auto uact, auto... args, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<uact, args...>*), Heaps... Hs)
		{
			return T_type_U<uact>::template result<args...>;
		}
	};

/***********************************************************************************************************************/

// compel heap zero all, move, insert at registers front (V_apply_ExVs):

	template<key_type... filler>
	struct machine<MN::compel_h0_all__move__insert_at_r_front, MT::id, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, auto uact, auto... args, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<uact, args...>*), Heaps... Hs)
		{
			return NIK_BEGIN_MACHINE(n, c, d, i, j),

				T_type_U<uact>::template result<args...>, Vs...
			
			NIK_END_MACHINE(null, Hs...);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// start:

public:

	template<typename program, auto... Vs, auto... Is>
	static constexpr auto start(void(*)(auto_pack<Is...>*) = null)
	{
		constexpr auto n	= U_linear_program;
		constexpr auto c	= label<call_linear_program<MN::id, PM::id, PL::id>>;
		constexpr auto d	= program::depth;
		constexpr auto m	= MN::call;
		constexpr auto i	= T_linear_program::initial_i;
		constexpr auto j	= T_linear_program::next_index2(c, d, MN::id, i, T_linear_program::initial_j);

		constexpr auto nn	= U_type_T<program>;
		constexpr auto nc	= program::template lines<index_type{Is}...>;
		constexpr auto nm	= MN::id;
		constexpr auto ni	= program::initial_i;
		constexpr auto nj	= program::initial_j;

		constexpr auto nH2	= U_opt_pack_Vs<nn, nc, nm, ni, nj, Vs...>;
		constexpr auto nH3	= U_opt_pack_Vs<null, null, null, null>;

		return NIK_BEGIN_AUTOMATA(n, c, d, m, i, j) NIK_END_AUTOMATA(null, null, nH2, nH3);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

