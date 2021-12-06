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

//					auto n, auto c, auto d, auto m, auto i, auto j, auto... Vs,

//				// heaps:

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

private:

	static constexpr auto null	= U_opt_pack_Vs<>;
	using null_type			= decltype(null);

/***********************************************************************************************************************/

// machination:

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
		static constexpr auto result(Heaps... Hs)
		{
			constexpr auto sc = U_opt_pack_Vs<n, c, m, i, j, Vs...>;
			constexpr auto hc = U_pre_pack_Ts<Heaps...>;

			return machination(sc, hc);
		}
	};

/***********************************************************************************************************************/

// save:

	template<key_type... filler>
	struct machine<MN::save, MT::id, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename Heap3, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heap2 H2, Heap3 H3, Heaps... Hs)
		{
			constexpr auto nH2 = U_opt_pack_Vs<Vs...>;
			constexpr auto nH3 = U_pre_pack_Ts<Heaps...>;

			return NIK_MACHINE(n, c, d, i, j, Vs)(H0, H1, nH2, nH3, Hs...);
		}
	};

/***********************************************************************************************************************/

// call (stage2):

		// { Vs... , Hs... } passing policy: copy.

	template<key_type... filler>
	struct machine<MN::call, MT::stage2, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, auto... Xs,
			auto nn, auto nc, auto nm, auto ni, auto nj, auto... nVs,
			auto... nHs, typename... Heaps
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<Ws...>*),
			void(*H1)(auto_pack<Xs...>*),
			void(*H2)(auto_pack<nn, nc, nm, ni, nj, nVs...>*),
			void(*H3)(auto_pack<nHs...>*), Heaps... Hs
		)
		{
			using tn			= T_type_U<n>;

			constexpr auto val		= NIK_AUTOMATA(nn, nc, d, nm, ni, nj, nVs)(nHs...);
			constexpr auto call_ins		= tn::instr(c, i, j);
			constexpr key_type memonic	= call_ins[CI::memonic];
			constexpr key_type location	= call_ins[CI::location];

			if constexpr (is_machination(val))

				return NIK_AUTOMATA(n, c, d, MN::call, i, j, Vs)(H0, H1, val.sc, val.hc, Hs...);

			else if constexpr (memonic == PM::id && location == PL::id)

				return val;

			else if constexpr (memonic == PM::stage2 && location == PL::id)

				return NIK_AUTOMATA(n, c, d, MN::pass, i, j, Vs)(H0, H1, val.sc, val.hc, Hs...);

			else if constexpr (memonic == PM::heap_zero)
			{
				if constexpr (location == PL::front)

					return NIK_MACHINE(n, c, d, i, j, Vs)
						(U_opt_pack_Vs<val, Ws...>, H1, null, null, Hs...);
				else
					return NIK_MACHINE(n, c, d, i, j, Vs)
						(U_opt_pack_Vs<Ws..., val>, H1, null, null, Hs...);
			}
			else if constexpr (memonic == PM::heap_one)
			{
				if constexpr (location == PL::front)

					return NIK_MACHINE(n, c, d, i, j, Vs)
						(H0, U_opt_pack_Vs<val, Xs...>, null, null, Hs...);
				else
					return NIK_MACHINE(n, c, d, i, j, Vs)
						(H0, U_opt_pack_Vs<Xs..., val>, null, null, Hs...);
			}
			else if constexpr (memonic == PM::stack)
			{
				if constexpr (location == PL::front)

					return NIK_BEGIN_MACHINE(n, c, d, i, j),

						val, Vs...

					NIK_END_MACHINE(H0, H1, null, null, Hs...);
				else
					return NIK_BEGIN_MACHINE(n, c, d, i, j),

						Vs..., val

					NIK_END_MACHINE(H0, H1, null, null, Hs...);
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
			typename Heap0, typename Heap1, typename Heap2, typename Heap3, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heap2 H2, Heap3 H3, Heaps... Hs)
		{
			using tn		= T_type_U<n>;

			constexpr auto call_ins	= tn::instr(c, i, j);
			constexpr auto nc	= T_BP::template make_controller<call_ins>;
			constexpr auto pos	= call_ins[BCI::pos];
			constexpr auto nj	= T_BP::max_index2(pos);
			constexpr auto ni	= pos + nj;

			constexpr auto cH0	= U_pretype_T<Heap0>;
			constexpr auto cH1	= U_pretype_T<Heap1>;
			constexpr auto nH2	= U_opt_pack_Vs<nn, nc, nm, ni, nj, Vs...>;
			constexpr auto nH3	= U_opt_pack_Vs<cH0, cH1, null, null, U_pretype_T<Heaps>...>;

			return NIK_AUTOMATA(n, c, d, nnm, i, j, Vs)(H0, H1, nH2, nH3, Hs...);
		}
	};

/***********************************************************************************************************************/

// call (linear, user):

		// { Vs... , Hs... } passing policy: restore.

		// Replacing the existing controller with an "inlined" equivalent is the preferred
		// implementation, but the gcc/clang compilers issue too many type misalignments.
		// As such, any convenience machines such as call rely on tail function calls.

	template<key_type Note, key_type... filler>
	struct machine<MN::call, Note, filler...>
	{
		static constexpr auto nn	= U_block_program;
		static constexpr auto nm	= MN::id;
		static constexpr auto nnm	= MN::call;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, auto... nVs, auto... nHs, typename... Heaps
		>
		static constexpr auto result
		(
			Heap0 H0, Heap1 H1,
			void(*H2)(auto_pack<nVs...>*),
			void(*H3)(auto_pack<nHs...>*), Heaps... Hs
		)
		{
			using tn			= T_type_U<n>;

			constexpr auto call_ins		= tn::instr(c, i, j);
			constexpr index_type length	= MI::length(call_ins) + 1;
			constexpr index_type size	= length - (MT::is_linear(Note) ? LCI::offset : UCI::offset);
			constexpr auto nc		= bp_unpack_i_segment__insert_at_h1_back::template controller
							<
								MN::pass, Note
							>;
			constexpr auto nj		= T_BP::max_index2(size);
			constexpr auto ni		= size + nj;

			constexpr auto nH0		= U_opt_pack_Vs<call_ins, length>;
			constexpr auto cH0		= U_pretype_T<Heap0>;
			constexpr auto cH1		= U_pretype_T<Heap1>;
			constexpr auto nH2		= U_opt_pack_Vs<nn, nc, nm, ni, nj, Vs...>;
			constexpr auto nH3		= U_opt_pack_Vs<nH0, null, cH0, cH1, U_pretype_T<Heaps>...>;

			return NIK_AUTOMATA(n, c, d, nnm, i, j, nVs)(H0, H1, nH2, nH3, nHs...);
		}
	};

/***********************************************************************************************************************/

// pass (id):

	template<key_type... filler>
	struct machine<MN::pass, MT::id, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			constexpr auto sc = U_opt_pack_Vs<n, c, m, i, j, Vs...>;
			constexpr auto hc = U_pre_pack_Ts<Heaps...>;

			return loadable(sc, hc);
		}
	};

/***********************************************************************************************************************/

// pass (stage2):

	template<key_type... filler>
	struct machine<MN::pass, MT::stage2, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1,
			auto nn, auto nc, auto nm, auto ni, auto nj, auto... nVs,
			auto nH0, auto nH1, auto nH2, auto nH3, auto... nHs, typename... Heaps
		>
		static constexpr auto result
		(
			Heap0 H0, Heap1 H1,
			void(*H2)(auto_pack<nn, nc, nm, ni, nj, nVs...>*),
			void(*H3)(auto_pack<nH0, nH1, nH2, nH3, nHs...>*), Heaps... Hs
		)
		{
			return NIK_MACHINE(n, c, d, i, j, nVs)(nH0, nH1, nH2, nH3, nHs...);
		}
	};

/***********************************************************************************************************************/

// pass (linear, call):

	template<key_type Note, key_type... filler>
	struct machine<MN::pass, Note, filler...>
	{
		static constexpr auto nm = MN::id;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto call_ins, auto length, auto... Ws,
			auto... Xs, typename Heap2, typename Heap3, typename... Heaps
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<call_ins, length, Ws...>*),
			void(*H1)(auto_pack<Xs...>*),
			Heap2 H2, Heap3 H3, Heaps... Hs
		)
		{
			using tn		= boolean_module::template T_if_then_else_TxT
						<
							MT::is_linear(Note), T_LP, T_UP
						>;

			constexpr auto nn	= U_type_T<tn>;
			constexpr auto ni	= tn::initial_i;
			constexpr auto nj	= tn::initial_j;

			constexpr auto cH2	= U_pretype_T<Heap2>;
			constexpr auto cH3	= U_pretype_T<Heap3>;
			constexpr auto nc	= tn::template make_controller<call_ins, Xs...>;
			constexpr auto sc	= U_opt_pack_Vs<nn, nc, nm, ni, nj, Vs...>;
			constexpr auto hc	= U_opt_pack_Vs<cH2, cH3, null, null, U_pretype_T<Heaps>...>;

			return machination(sc, hc);
		}
	};

/***********************************************************************************************************************/

// unpack instruction block (2^N):

	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H1_BACK(0);
	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H1_BACK(1);
	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H1_BACK(2);
	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H1_BACK(3);
	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H1_BACK(4);
	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H1_BACK(5);
	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H1_BACK(6);
	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H1_BACK(7);
	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H1_BACK(8);
	NIK_DEFINE__UNPACK_I_BLOCK__INSERT_AT_H1_BACK(9);

/***********************************************************************************************************************/

// branch:

	template<key_type... filler>
	struct machine<MN::branch, MT::id, filler...>
	{
		static constexpr index_type index = 3;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			bool is_br, auto... Ws, typename... Heaps
		>
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
		static constexpr auto result(Heaps... Hs)
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
	struct machine<MN::depth, MT::id, filler...>
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
	struct machine<MN::dump, MT::id, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			constexpr auto sc = U_opt_pack_Vs<n, c, m, i, j, Vs...>;
			constexpr auto hc = U_pre_pack_Ts<Heaps...>;

			return U_opt_pack_Vs<sc, hc>;
		}
	};

/***********************************************************************************************************************/

// stack:

	template<key_type... filler>
	struct machine<MN::stack, MT::id, filler...>
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
	struct machine<MN::heaps, MT::id, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			return U_pre_pack_Ts<Heaps...>;
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// passers:

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

// move heap zero first, insert at stack front:

	template<key_type... filler>
	struct machine<MN::move_h0_first__insert_at_s_front, MT::id, filler...>
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

// move heap one all, insert at stack front:

	template<key_type... filler>
	struct machine<MN::move_h1_all__insert_at_s_front, MT::id, filler...>
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

// start:

public:

	template<typename program, auto... Vs, index_type... Is>
	static constexpr auto start(void(*)(auto_pack<Is...>*) = null)
	{
		constexpr auto n	= U_linear_program;
		constexpr auto c	= label<call_linear_program<MN::id, MT::id, PM::id, PL::id>>;
		constexpr auto d	= program::depth;
		constexpr auto m	= MN::call;
		constexpr auto i	= T_LP::initial_i;
		constexpr auto j	= T_LP::next_index2(c, d, MN::id, i, T_LP::initial_j);

		constexpr auto nn	= U_type_T<program>;
		constexpr auto nc	= program::template controller<Is...>;
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

