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

// machine declarations source:

	// nesting depth policy:

		// It is assumed each function nesting depth is chosen to be less than the compiler's nesting depth.
		// This is to say that in practice there should be small buffer of nesting depths/calls available.

		// Consequences: If d == 0 during a given machine call,

		// A) It is able to call the next machine. In turn the iterators will
		//    dispatch it to MN::pause which does not require any further depths.

		// B) It is able to call single depth functions within its scope.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// constexpr monad (design):

//		template<>
//		struct machine<MN::(((name))), (((note)))>
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

// keywords:

private:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machine:

	template<index_type, index_type, index_type...> struct machine;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// aliases:

	template<auto... Vs>				// optimized because we know auto_pack<Vs...>
	static constexpr auto U_opt_pack_Vs =		// is not void nor a reference.
		nik_module(interpret, functor, architect, v_0_5, gcc)::template type_map<auto_pack<Vs...>*>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatch:

/***********************************************************************************************************************/

// machine:

	using MN	= typename controller_module::MN;
	using MA	= typename controller_module::MA;
	using MD	= typename controller_module::MD;

/***********************************************************************************************************************/

// block:

	using bc_type	= typename controller_module::bc_type;
	using BC	= typename controller_module::BC;

/***********************************************************************************************************************/

// variadic:

	using vl_type	= typename controller_module::vl_type;
	using vc_type	= typename controller_module::vc_type;

/***********************************************************************************************************************/

// permutatic:

	using pa_type	= typename controller_module::pa_type;
	using pc_type	= typename controller_module::pc_type;
	using PA	= typename controller_module::PA;

/***********************************************************************************************************************/

// distributic:

	using dc_type	= typename controller_module::dc_type;
	using DA	= typename controller_module::DA;

/***********************************************************************************************************************/

// near linear:

	using nc_type	= typename controller_module::nc_type;
	using NA	= typename controller_module::NA;
	using NP	= typename controller_module::NP;

/***********************************************************************************************************************/

// register:

	using rc_type	= typename controller_module::rc_type;
	using RA	= typename controller_module::RA;
	using RL	= typename controller_module::RL;
	using RC	= typename controller_module::RC;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// trampolining:

/***********************************************************************************************************************/

// pair:

	template<typename StackCache, typename HeapCache>
	struct trampoline_pair
	{
		StackCache sc;
		HeapCache hc;

		constexpr trampoline_pair(const StackCache & _sc, const HeapCache & _hc) : sc(_sc), hc(_hc) { }
	};

	template<typename T>
	static constexpr bool is_trampoline_pair(T) { return false; }

	template<typename StackCache, typename HeapCache>
	static constexpr bool is_trampoline_pair(trampoline_pair<StackCache, HeapCache>) { return true; }

/***********************************************************************************************************************/

// trampoline:

	template<auto d, auto un, auto c, auto i, auto j, auto... Vs, auto... Hs>
	static constexpr auto machine_trampoline(void(*)(auto_pack<un, c, i, j, Vs...>*), void(*)(auto_pack<Hs...>*))
	{
		static_assert(bool(d), "machine trampolining nesting depth exceeded.");

		using n = T_type_U<un>;

		constexpr auto result = NIK_MACHINE(n, c, d, i, j)(Hs...);

		if constexpr (is_trampoline_pair(result))	return machine_trampoline<d-1>(result.sc, result.hc);
		else						return result;
	}

/***********************************************************************************************************************/

// start:

public:

	template<NIK_CONTR_PARAMS, auto... Vs, auto... Ws, auto... Xs>
	static constexpr auto start
	(
		void(*H0)(auto_pack<Ws...>*) = U_opt_pack_Vs<>,
		void(*H1)(auto_pack<Xs...>*) = U_opt_pack_Vs<>
	)
	{
		constexpr auto result = NIK_MACHINE(n, c, d, i, j)(U_opt_pack_Vs<Ws...>, U_opt_pack_Vs<Xs...>);

		if constexpr (is_trampoline_pair(result))	return machine_trampoline<d>(result.sc, result.hc);
		else						return result;
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

