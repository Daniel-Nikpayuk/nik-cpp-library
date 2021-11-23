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
			constexpr auto sc = U_opt_pack_Vs<n, c, i, j, Vs...>;
			constexpr auto hc = U_pre_pack_Ts<Heaps...>;

			return machination(sc, hc);
		}
	};

/***********************************************************************************************************************/

// pose (block):

	template<key_type... filler>
	struct machine<MN::pose, MT::block, filler...>
	{
		// instructions:

			static constexpr index_type pose_name		= 3;
			static constexpr index_type pose_note		= 4;
			static constexpr index_type pose_mem		= 5;
			static constexpr index_type pose_loc		= 6;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, auto pos, typename Heap2, typename Heap3, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, void(*H1)(auto_pack<pos>*), Heap2 H2, Heap3 H3, Heaps... Hs)
		{
			using tn		= T_type_U<n>;

			constexpr auto nc	= block_program
						<
							tn::value(c, i, j, pose_name)

						>::template controller
						<
							tn::value(c, i, j, pose_note),
							tn::value(c, i, j, pose_mem),
							tn::value(c, i, j, pose_loc)
						>;
			constexpr auto nj	= T_BP::max_index2(pos);
			constexpr auto ni	= pos + nj;

			constexpr auto nH2	= U_opt_pack_Vs<U_block_program, nc, ni, nj, Vs...>;
			constexpr auto nH3	= U_pre_pack_Ts<Heap0, null_type, Heap2, Heap3, Heaps...>;

			return NIK_MACHINE(n, c, d, i, j, Vs)(H0, null, nH2, nH3, Hs...);
		}
	};

/***********************************************************************************************************************/

// load (block):

	template<key_type... filler>
	struct machine<MN::load, MT::block, filler...>
	{
		// instructions:

			static constexpr index_type load_name		= 3;
			static constexpr index_type load_note		= 4;
			static constexpr index_type load_mem		= 5;
			static constexpr index_type load_loc		= 6;
			static constexpr index_type load_pos		= 7;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			typename Heap0, typename Heap1, typename Heap2, typename Heap3, typename... Heaps
		>
		static constexpr auto result(Heap0 H0, Heap1 H1, Heap2 H2, Heap3 H3, Heaps... Hs)
		{
			using tn		= T_type_U<n>;

			constexpr auto nc	= block_program
						<
							tn::value(c, i, j, load_name)

						>::template controller
						<
							tn::value(c, i, j, load_note),
							tn::value(c, i, j, load_mem),
							tn::value(c, i, j, load_loc)
						>;
			constexpr auto pos	= tn::value(c, i, j, load_pos);
			constexpr auto nj	= T_BP::max_index2(pos);
			constexpr auto ni	= pos + nj;

			constexpr auto nH2	= U_opt_pack_Vs<U_block_program, nc, ni, nj, Vs...>;
			constexpr auto nH3	= U_pre_pack_Ts<Heap0, Heap1, Heap2, Heap3, Heaps...>;

			return NIK_MACHINE(n, c, d, i, j, Vs)(H0, H1, nH2, nH3, Hs...);
		}
	};

/***********************************************************************************************************************/

// reload:

	template<key_type... filler>
	struct machine<MN::reload, _zero, filler...>
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
		// instructions:

			static constexpr index_type call_mem		= 3;
			static constexpr index_type call_loc		= 4;

		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			auto... Ws, auto... Xs,
			auto nn, auto nc, auto ni, auto nj, auto... nVs,
			auto... nHs, typename... Heaps
		>
		static constexpr auto result
		(
			void(*H0)(auto_pack<Ws...>*),
			void(*H1)(auto_pack<Xs...>*),
			void(*H2)(auto_pack<nn, nc, ni, nj, nVs...>*),
			void(*H3)(auto_pack<nHs...>*), Heaps... Hs
		)
		{
			using tn		= T_type_U<n>;

			constexpr auto val	= NIK_MACHINE(nn, nc, d, ni, nj, nVs)(nHs...);
			constexpr auto nd	= tn::next_depth(d);

			if constexpr (nd == d)

				return NIK_MACHINE(n, c, d, i, j, Vs)(H0, H1, H2, Hs...);

			else if constexpr (is_machination(val))

				return machine::template result<n, c, nd, i, j, Vs...>(H0, H1, val.sc, val.hc, Hs...);

			else if constexpr (is_loadable(val))

				return NIK_MACHINE(n, c, d, i, j, Vs)(H0, H1, val.sc, val.hc, Hs...);

			else if constexpr (tn::value(c, i, j, call_mem) == MM::stack)
			{
				if constexpr (tn::value(c, i, j, call_loc) == MM::front)

					return NIK_BEGIN_MACHINE(n, c, d, i, j),

					       val, Vs...

					NIK_END_MACHINE(H0, H1, null, null, Hs...);
				else
					return NIK_BEGIN_MACHINE(n, c, d, i, j),

					       Vs..., val

					NIK_END_MACHINE(H0, H1, null, null, Hs...);
			}
			else if constexpr (tn::value(c, i, j, call_mem) == MM::heap_zero)
			{
				if constexpr (tn::value(c, i, j, call_loc) == MM::front)

					return NIK_MACHINE(n, c, d, i, j, Vs)
						(U_opt_pack_Vs<val, Ws...>, H1, null, null, Hs...);
				else
					return NIK_MACHINE(n, c, d, i, j, Vs)
						(U_opt_pack_Vs<Ws..., val>, H1, null, null, Hs...);
			}
			else if constexpr (tn::value(c, i, j, call_mem) == MM::heap_one)
			{
				if constexpr (tn::value(c, i, j, call_loc) == MM::front)

					return NIK_MACHINE(n, c, d, i, j, Vs)
						(H0, U_opt_pack_Vs<val, Xs...>, null, null, Hs...);
				else
					return NIK_MACHINE(n, c, d, i, j, Vs)
						(H0, U_opt_pack_Vs<Xs..., val>, null, null, Hs...);
			}
			else return val;
		}
	};

/***********************************************************************************************************************/

// ship:

	template<key_type... filler>
	struct machine<MN::ship, _zero, filler...>
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
			return NIK_MACHINE(n, c, d, i, j, nVs)(nH0, nH1, nH2, nH3, nHs...);
		}
	};

/***********************************************************************************************************************/

// pass:

	template<key_type... filler>
	struct machine<MN::pass, _zero, filler...>
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
		constexpr auto c	= label<call<>>;
		constexpr auto d	= program::depth;
		constexpr auto i	= T_LP::initial_i;
		constexpr auto j	= T_LP::initial_j;

		constexpr auto nn	= U_type_T<program>;
		constexpr auto nc	= program::template controller<Is...>;
		constexpr auto ni	= program::initial_i;
		constexpr auto nj	= program::initial_j;

		constexpr auto nH3	= U_opt_pack_Vs<null, null, null, null>;
		constexpr auto nH2	= U_opt_pack_Vs<nn, nc, ni, nj, Vs...>;

		return NIK_BEGIN_MACHINE(n, c, d, i, j) NIK_END_MACHINE(null, null, nH2, nH3);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

