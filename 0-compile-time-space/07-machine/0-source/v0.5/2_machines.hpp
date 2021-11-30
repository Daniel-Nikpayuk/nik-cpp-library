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

		constexpr machination(const StackCache & _sc, const HeapCache & _hc) : sc(_sc), hc(_hc) { }
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

		constexpr loadable(const StackCache & _sc, const HeapCache & _hc) : sc(_sc), hc(_hc) { }
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
	struct machine<MN::pause, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			constexpr auto sc = U_opt_pack_Vs<n, c, r, i, j, Vs...>;
			constexpr auto hc = U_pre_pack_Ts<Heaps...>;

			return machination(sc, hc);
		}
	};

/***********************************************************************************************************************/

// save:

	template<key_type... filler>
	struct machine<MN::save, _zero, filler...>
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

	template<key_type... filler>
	struct machine<MN::call, MT::stage2, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, auto... Xs,
			auto nn, auto nc, bool nr, auto ni, auto nj, auto... nVs,
			auto... nHs, typename... Heaps
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<Ws...>*),
			void(*H1)(auto_pack<Xs...>*),
			void(*H2)(auto_pack<nn, nc, nr, ni, nj, nVs...>*),
			void(*H3)(auto_pack<nHs...>*), Heaps... Hs
		)
		{
			using tn		= T_type_U<n>;

			constexpr auto val	= NIK_AUTOMATA(nn, nc, d, nr, ni, nj, nVs)(nHs...);
			constexpr bool nnr	= is_machination(val);
			constexpr auto ins	= tn::instr(c, i, j);

			if constexpr (nnr || is_loadable(val))

				return NIK_AUTOMATA(n, c, d, nnr, i, j, Vs)(H0, H1, val.sc, val.hc, Hs...);

			else if constexpr (ins[CI::memonic] == MM::id && ins[CI::location] == MM::id)

				return val;

			else if constexpr (ins[CI::memonic] == MM::stack)
			{
				if constexpr (ins[CI::location] == MM::front)

					return NIK_BEGIN_MACHINE(n, c, d, i, j),

						val, Vs...

					NIK_END_MACHINE(H0, H1, null, null, Hs...);
				else
					return NIK_BEGIN_MACHINE(n, c, d, i, j),

						Vs..., val

					NIK_END_MACHINE(H0, H1, null, null, Hs...);
			}
			else if constexpr (ins[CI::memonic] == MM::heap_zero)
			{
				if constexpr (ins[CI::location] == MM::front)

					return NIK_MACHINE(n, c, d, i, j, Vs)
						(U_opt_pack_Vs<val, Ws...>, H1, null, null, Hs...);
				else
					return NIK_MACHINE(n, c, d, i, j, Vs)
						(U_opt_pack_Vs<Ws..., val>, H1, null, null, Hs...);
			}
			else if constexpr (ins[CI::memonic] == MM::heap_one)
			{
				if constexpr (ins[CI::location] == MM::front)

					return NIK_MACHINE(n, c, d, i, j, Vs)
						(H0, U_opt_pack_Vs<val, Xs...>, null, null, Hs...);
				else
					return NIK_MACHINE(n, c, d, i, j, Vs)
						(H0, U_opt_pack_Vs<Xs..., val>, null, null, Hs...);
			}
		}
	};

/***********************************************************************************************************************/

// call (block):

	template<key_type... filler>
	struct machine<MN::call, MT::block, filler...>
	{
		static constexpr auto nn	= U_block_program;
		static constexpr auto nr	= false;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, auto... Xs, auto... nVs, auto... nHs, typename... Heaps
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<Ws...>*), void(*H1)(auto_pack<Xs...>*),
			void(*H2)(auto_pack<nVs...>*), void(*H3)(auto_pack<nHs...>*), Heaps... Hs
		)
		{
			using tn		= T_type_U<n>;

			constexpr auto ins	= tn::instr(c, i, j);
			constexpr auto nc	= block_program
						<
							ins[BCI::name]

						>::template controller
						<
							ins[BCI::memonic],
							ins[BCI::location],
							ins[BCI::coname],
							ins[BCI::conote]
						>;
			constexpr auto pos	= ins[BCI::pos];
			constexpr auto nj	= T_BP::max_index2(pos);
			constexpr auto ni	= pos + nj;

			constexpr auto val	= NIK_AUTOMATA(nn, nc, d, nr, ni, nj, Vs)
						(
							U_opt_pack_Vs<Ws...>,
							U_opt_pack_Vs<Xs...>,
							null, null, U_pretype_T<Heaps>...
						);
			constexpr bool nnr	= is_machination(val);

			if constexpr (nnr || is_loadable(val))

				return NIK_AUTOMATA(n, c, d, nnr, i, j, nVs)(H0, H1, val.sc, val.hc, nHs...);

			else if constexpr (ins[BCI::memonic] == MM::id && ins[BCI::location] == MM::id)

				return val;

			else if constexpr (ins[BCI::memonic] == MM::stack)
			{
				if constexpr (ins[BCI::location] == MM::front)

					return NIK_BEGIN_MACHINE(n, c, d, i, j),

						val, nVs...

					NIK_END_MACHINE(H0, H1, null, null, nHs...);
				else
					return NIK_BEGIN_MACHINE(n, c, d, i, j),

						nVs..., val

					NIK_END_MACHINE(H0, H1, null, null, nHs...);
			}
			else if constexpr (ins[BCI::memonic] == MM::heap_zero)
			{
				if constexpr (ins[BCI::location] == MM::front)

					return NIK_MACHINE(n, c, d, i, j, nVs)
						(U_opt_pack_Vs<val, Ws...>, H1, null, null, nHs...);
				else
					return NIK_MACHINE(n, c, d, i, j, nVs)
						(U_opt_pack_Vs<Ws..., val>, H1, null, null, nHs...);
			}
			else if constexpr (ins[BCI::memonic] == MM::heap_one)
			{
				if constexpr (ins[BCI::location] == MM::front)

					return NIK_MACHINE(n, c, d, i, j, nVs)
						(H0, U_opt_pack_Vs<val, Xs...>, null, null, nHs...);
				else
					return NIK_MACHINE(n, c, d, i, j, nVs)
						(H0, U_opt_pack_Vs<Xs..., val>, null, null, nHs...);
			}
		}
	};

/***********************************************************************************************************************/

// call (linear):

		// Replacing the existing controller with an "inlined" equivalent is the preferred
		// implementation, but the gcc/clang compilers issue too many type misalignments.
		// As such, any convenience machines such as call rely on tail function calls.

			// ? Needs to treat linear and user controllers differently.
			// ? Is allowed a single function call, can dispatch accordingly.

/*
	template<key_type... filler>
	struct machine<MN::call, MT::linear, filler...>
	{
		static constexpr index_type offset	= LI::offset + 2;

		static constexpr auto nn		= U_linear_program;
		static constexpr auto ni		= T_LP::initial_i;
		static constexpr auto nj		= T_LP::initial_j;

		template<key_type Subname, key_type Subnote, key_type Mem, key_type Loc, index_type Size>
		static constexpr label_type param_loader = label
		<
			load__unpack_i_segment__insert_at_h1_back<MN::pass, _zero, Size>, // redundant step?
			call<>,
			ship<>,
			pose_linear<Subname, Subnote, Mem, Loc>,
			unload_linear<>
		>;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename Heap3, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heap2 H2, Heap3 H3, Heaps... Hs)
		{
			using tn			= T_type_U<n>;

			constexpr auto ins		= tn::instr(c, i, j);
			constexpr auto subins		= LI::template subinstr<ins>;
			constexpr index_type length	= LI::length(ins);
			constexpr index_type size	= length - offset;
			constexpr auto nc		= param_loader
							<
								subins[LI::name],
								subins[LI::note],
								subins[LI::mem],
								subins[LI::loc],
								size
							>;

			constexpr auto nH0		= U_opt_pack_Vs<ins, length>;
			constexpr auto nH2		= 
			constexpr auto nH3		= 
			constexpr auto nH4		= U_opt_pack_Vs<n, c, i, j, Vs...>;
			constexpr auto nH5		= U_pre_pack_Ts<Heap0, Heap1, Heaps...>;

			return NIK_BEGIN_MACHINE(nn, nc, d, ni, nj)
				NIK_END_MACHINE(nH0, null, H2, H3, nH4, nH5);
		}
	};
*/

// linear, control:

/*
	template<key_type Note, key_type... filler>
	struct machine<MN::call, Note, filler...>
	{
		using nn = LD;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heap2 H2, Heaps... Hs)
		{
			constexpr auto instr	= n::subinstr(c, i, j);
			constexpr auto subsize	= CI::subsize(instr);
			constexpr auto nc	= label
						<
							make_r_segment__insert_at_s_back<subsize>,
							instruction<Note, CT::scalable>
						>;
			constexpr auto un	= U_type_T<n>;

			return NIK_BEGIN_MACHINE(nn, nc, d, nn::i, nn::j)

			NIK_END_MACHINE // optimized, works because nc does not use H3 onward:
			(
				H0, H1, H2, U_opt_pack_Vs<instr, Vs...>, U_opt_pack_Vs<un, c, i, j>, Hs...
			);
		}
	};
*/

/***********************************************************************************************************************/

// ship:

	template<key_type... filler>
	struct machine<MN::ship, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1,
			auto nn, auto nc, bool nr, auto ni, auto nj, auto... nVs,
			auto nH0, auto nH1, auto nH2, auto nH3, auto... nHs, typename... Heaps
		>
		static constexpr auto result
		(
			Heap0 H0, Heap1 H1,
			void(*H2)(auto_pack<nn, nc, nr, ni, nj, nVs...>*),
			void(*H3)(auto_pack<nH0, nH1, nH2, nH3, nHs...>*), Heaps... Hs
		)
		{
			return NIK_MACHINE(n, c, d, i, j, nVs)(nH0, nH1, nH2, nH3, nHs...);
		}
	};

/***********************************************************************************************************************/

// (all) pass:

	template<key_type... filler>
	struct machine<MN::pass, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			constexpr auto sc = U_opt_pack_Vs<n, c, r, i, j, Vs...>;
			constexpr auto hc = U_pre_pack_Ts<Heaps...>;

			return loadable(sc, hc);
		}
	};

/***********************************************************************************************************************/

// (sub) pass:

	template<key_type... filler>
	struct machine<MN::pass, _one, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename Heap3, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heap2 H2, Heap3 H3, Heaps... Hs)
		{
			return loadable(H2, H3);
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
/***********************************************************************************************************************/

// halters:

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
			constexpr auto sc = U_opt_pack_Vs<n, c, r, i, j, Vs...>;
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

// move stack block (2^N):

	NIK_DEFINE__MOVE_S_BLOCK(0);
	NIK_DEFINE__MOVE_S_BLOCK(1);
	NIK_DEFINE__MOVE_S_BLOCK(2);
	NIK_DEFINE__MOVE_S_BLOCK(3);
	NIK_DEFINE__MOVE_S_BLOCK(4);
	NIK_DEFINE__MOVE_S_BLOCK(5);
	NIK_DEFINE__MOVE_S_BLOCK(6);
	NIK_DEFINE__MOVE_S_BLOCK(7);
	NIK_DEFINE__MOVE_S_BLOCK(8);
	NIK_DEFINE__MOVE_S_BLOCK(9);

/***********************************************************************************************************************/

// move heap one all:

	template<key_type... filler>
	struct machine<MN::move_h1_all, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, auto... Xs, typename... Heaps
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<Ws...>*),
			void(*H1)(auto_pack<Xs...>*),
			Heaps... Hs
		)
		{
			using tn			= T_type_U<n>;
			constexpr key_type memonic	= tn::mem(c, i, j);
			constexpr key_type locator	= tn::loc(c, i, j);

			if constexpr (memonic == MM::stack)
			{
				if constexpr (locator == MM::front)

					return NIK_BEGIN_MACHINE(n, c, d, i, j),

						Xs..., Vs...

					NIK_END_MACHINE(H0, null, Hs...);
				else
					return NIK_BEGIN_MACHINE(n, c, d, i, j),

						Vs..., Xs...

					NIK_END_MACHINE(H0, null, Hs...);
			}
			else // if constexpr (memonic == MM::heap_zero)
			{
				if constexpr (locator == MM::front)

					return NIK_MACHINE(n, c, d, i, j, Vs)(U_opt_pack_Vs<Xs..., Ws...>, null, Hs...);
				else
					return NIK_MACHINE(n, c, d, i, j, Vs)(U_opt_pack_Vs<Ws..., Xs...>, null, Hs...);
			}
		}
	};

/***********************************************************************************************************************/

// start:

public:

	template<typename program, auto... Vs, index_type... Is>
	static constexpr auto start(void(*)(auto_pack<Is...>*) = null)
	{
		constexpr auto n	= U_linear_program;
		constexpr auto c	= label<call_linear<MN::id, MT::id, MM::id, MM::id>>;
		constexpr auto d	= program::depth;
		constexpr bool r	= true;
		constexpr auto i	= T_LP::initial_i;
		constexpr auto j	= T_LP::next_index2(c, d, false, i, T_LP::initial_j);

		constexpr auto nn	= U_type_T<program>;
		constexpr auto nc	= program::template controller<Is...>;
		constexpr bool nr	= false;
		constexpr auto ni	= program::initial_i;
		constexpr auto nj	= program::initial_j;

		constexpr auto nH2	= U_opt_pack_Vs<nn, nc, nr, ni, nj, Vs...>;
		constexpr auto nH3	= U_opt_pack_Vs<null, null, null, null>;

		return NIK_BEGIN_AUTOMATA(n, c, d, r, i, j) NIK_END_AUTOMATA(null, null, nH2, nH3);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

