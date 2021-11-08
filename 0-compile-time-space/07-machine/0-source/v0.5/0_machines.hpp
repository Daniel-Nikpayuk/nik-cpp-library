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

//					typename n, auto c, auto d, auto i, auto j, auto... Vs,

//				// heaps:

//					typename... Heaps
//			>
//			static constexpr auto result(Heaps... Hs)
//			{
//				return machine
//				<
//					n::next_name(c, d, i, j),
//					n::next_note(c, d, i, j)

//				>::template result
//				<
//					n, c,

//					n::next_depth(d),
//					n::next_index1(c, d, i, j),
//					n::next_index2(c, d, i, j),

//					Vs...	// The behaviour of each
//						// machine is such that it
//				>(Hs...);	// mutates these packs.
//			}
//		};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keys:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// interposition:

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

	template<typename MachineCache, typename StackCache, typename HeapCache>
	static constexpr bool is_loadable(loadable<StackCache, HeapCache>) { return true; }

/***********************************************************************************************************************/

// machination:

		// Do not refactor using other templated structs. Although this definition is potentially redundant,
		// trampolining requires a distinct keyword so that there's no confusion with any other returned value.

	template<typename MachineCache, typename StackCache, typename HeapCache>
	struct machination
	{
		MachineCache mc;
		StackCache sc;
		HeapCache hc;

		constexpr machination(const MachineCache & _mc, const StackCache & _sc, const HeapCache & _hc) :
				mc(_mc), sc(_sc), hc(_hc) { }
	};

	//

	template<typename T>
	static constexpr bool is_machination(T) { return false; }

	template<typename MachineCache, typename StackCache, typename HeapCache>
	static constexpr bool is_machination(machination<MachineCache, StackCache, HeapCache>) { return true; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machines:

private:

	template<key_type, key_type, key_type...> struct machine;

	using D_machine			= D_pack_Bs<machine>;
	static constexpr auto H_machine	= U_pack_Bs<machine>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// names:

/***********************************************************************************************************************/

	// I would prefer to implement these as enums, but I don't know how
	// to get gcc/clang to pattern match the register machine when I do.

	struct MachineName
	{
		// halters:

			static constexpr key_type pause						=  0;
			static constexpr key_type stack						=  1;
			static constexpr key_type heaps						=  2;

			static constexpr key_type first						=  3;
			static constexpr key_type rest						=  4;

		// debuggers:

			static constexpr key_type depth						=  5;
			static constexpr key_type dump						=  6;

		// passers:

			// callers:

			static constexpr key_type load						=  7;
			static constexpr key_type compel					=  8;

			// stack -> stack:

			static constexpr key_type drop_s_block					=  9; // <halters>
	};

	using MN = MachineName;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// halters:

/***********************************************************************************************************************/

// pause:

	template<key_type... filler>
	struct machine<MN::pause, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>
		static constexpr auto result(Heaps... Hs)
		{
			constexpr auto sc = U_opt_pack_Vs<n, c, i, j, Vs...>;
			constexpr auto hc = U_opt_pack_Vs<U_type_T<T_pretype_T<Heaps>>...>;

			return machination(H_machine, sc, hc);
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
			return U_opt_pack_Vs<U_type_T<T_pretype_T<Heaps>>...>;
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
			constexpr auto hc = U_opt_pack_Vs<U_type_T<T_pretype_T<Heaps>>...>;

			return loadable(sc, hc);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// interposition:

/***********************************************************************************************************************/

// load:

	template<key_type... filler>
	struct machine<MN::load, _zero, filler...>
	{
		template<NIK_CONTR_PARAMS, auto... Vs, auto us, auto uh, auto... Ws, typename... Heaps>
		static constexpr auto result(void(*H0)(auto_pack<us, uh, Ws...>*), Heaps... Hs)
		{
			constexpr auto sc = T_type_U<us>::template result<n, d, c, i, j, Vs...>(H0, Hs...);
			constexpr auto hc = T_type_U<uh>::template result<n, d, c, i, j, Vs...>(H0, Hs...);

			return NIK_MACHINE(n, d, c, i, j)(U_opt_pack_Vs<Ws...>, sc, hc, Hs...);
		}
	};

/***********************************************************************************************************************/

// compel (trampoline apply):

	template<key_type... filler>
	struct machine<MN::compel, _zero, filler...>
	{
		template
		<
			NIK_CONTR_PARAMS, auto... Vs,
			template<auto...> class name, template<auto...> class... Bs,
			auto nn, auto nc, auto ni, auto nj, auto... nVs,
			auto... nHs, typename... Heaps
		>
		static constexpr auto result
		(
			void(*H0)(auto_template_pack<name, Bs...>*),
			void(*H1)(auto_pack<nn, nc, ni, nj, nVs...>*),
			void(*H2)(auto_pack<nHs...>*),
			Heaps... Hs
		)
		{
			constexpr auto value = NIK_AUTOMATA(name, nn, nc, d, ni, nj, nVs)(nHs...);

			if constexpr (T_type_U<n>::next_name(c, d, i, j) == MN::pause)

				return NIK_MACHINE(n, c, d, i, j)(H0, H1, H2, Hs...);

			else if constexpr (is_machination(value))

				return machine<MN::compel, _zero>::template result
				<
					n, c, T_type_U<n>::next_depth(d), i, j, Vs...

				>(value.mc, value.sc, value.hc, Hs...);

			else if constexpr (is_loadable(value))

				return NIK_MACHINE(n, c, d, i, j)(value.sc, value.hc, Hs...);

			else
				return NIK_MACHINE(n, c, d, i, j)(U_opt_pack_Vs<value>, Hs...);
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

// start:

public:

/*
	template<typename n, auto c, auto d, auto... Vs, auto... Ws, auto... Xs, auto... Ys>
	static constexpr auto start
	(
		void(*H0)(auto_pack<Ws...>*) = U_opt_pack_Vs<>,
		void(*H1)(auto_pack<Xs...>*) = U_opt_pack_Vs<>,
		void(*H2)(auto_pack<Ys...>*) = U_opt_pack_Vs<>
	)
	{
		constexpr auto result = NIK_MACHINE(n, c, d, n::i, n::j)
					(U_opt_pack_Vs<Ws...>, U_opt_pack_Vs<Xs...>, U_opt_pack_Vs<Ys...>);

		if constexpr (is_trampoline_pair(result)) return trampoline<d>(result.sc, result.hc);
		else                                      return result;
	}
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

