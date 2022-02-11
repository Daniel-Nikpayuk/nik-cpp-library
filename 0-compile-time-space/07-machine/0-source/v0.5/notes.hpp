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

// narrative:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// preamble:

	// The narrative design is for policies to be nested:

	// We dispatch <detour, call> by policy, but the policy embedded in the call instruction is intended
	// only for the final value returned from the call. In order to dispatch correctly within generalized
	// detour chains, we would need a way of specifying subpolicies. This would be done using machinations.

	// With that said, in this specific context, such nesting can be optimized away using careful designs.

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// programs:

/***********************************************************************************************************************/

// nesting depth policy:

	// It is assumed each function nesting depth is chosen to be less than the compiler's nesting depth.
	// This is to say that in practice there should be small buffer of nesting depths/calls available.

	// Consequences: If d == 0 during a given machine call,

	// A) It is able to call the next machine. In turn the iterators will
	//    dispatch it to MN::pause which does not require any further depths.

	// B) It is able to call single depth functions within its scope.

/***********************************************************************************************************************/

// names:

	// I would prefer to implement these as enums, but I don't know how
	// to get gcc/clang to pattern match the register machine when I do.

	// block machines break the nomenclature design by catenating their
	// name x note indices. This is done to allow for reuse of their notes.

/***********************************************************************************************************************/

// space:

	// Programs are base level or derived.

	// Base level: Block, Linear, Recursive.

	// Generic programs are either base level or derived.

	// User programs are generic programs that
	// are specifically stored in Heap four.

/***********************************************************************************************************************/

// block:

	// Block programs are intended *only* to be called by linear/recursive programs. 

	// Block programs consist of two block instructions. Minimally, in order to call
	// these programs only "unpack i segment, insert at h1 back" is required to bootstrap
	// the calling/loading process for the others. As the minimum number of required
	// programs all have the same form they are optimized into a single-call loader.

	// As an optimization the two co-instructions are encoded as a single one instead.

/***********************************************************************************************************************/

// linear:

	// Optimized to use a single label as the controller.

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// routines:

/***********************************************************************************************************************/

// block:

	// Block programs consist of two block instructions and some machine
	// modifiers: As such they can be optimized into a single instruction.

/***********************************************************************************************************************/

// machination:

	// Do not refactor using other templated structs. Although these definitions are potentially redundant,
	// trampolining/detouring require a distinct keyword so there's no confusion with other returned values.

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machines:

/***********************************************************************************************************************/

// Heap anatomy:

	// Heap zero:

		// Staging area to store objects
		// for calls and applications.

	// Heap one:

		// Stores pack segments, used for
		// register or argument access.

	// Heap two:

		// Stores stack1 info,
		// used for program calls.

	// Heap three:

		// Stores stack2 info,
		// used for program calls.

	// Heap four:

		// Stores constant info,
		// used for values, operators, programs.

	// Heap five:

		// Saves and restores stack1,
		// used for functional programs.

/***********************************************************************************************************************/

// constexpr monad:

	//	template<key_type... filler>
	//	struct machine<MN::(((name))), (((note))), filler...>
	//	{
	//		template
	//		<
	//			// stack1:

	//				auto d, auto m, auto n, auto c, auto i, auto j, auto... Vs,

	//			// stack2:

	//				typename... Heaps
	//		>
	//		static constexpr auto result(Heaps... Hs)
	//		{
	//			return machine
	//			<
	//				next_name<T_type_U<n>>(d, m, c, i, j),
	//				next_note<T_type_U<n>>(d, m, c, i, j)

	//			>::template result
	//			<
	//				next_depth(d),
	//				m, n, c,
	//				next_index1<T_type_U<n>>(d, m, c, i, j),
	//				next_index2<T_type_U<n>>(d, m, c, i, j)

	//				Vs...	// The behaviour of each
	//					// machine is such that it
	//			>(Hs...);	// mutates these packs.
	//		}
	//	};

/***********************************************************************************************************************/

// fold register block (2^N):

	// clang: bracket nesting level defaults to a maximum of 256

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

