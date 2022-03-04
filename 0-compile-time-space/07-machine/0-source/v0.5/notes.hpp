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

// controller:

	// instruction, label, controller arrays store their respective lengths as their own initial values.

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

// call specification:

	// param:

		// is cache level 1:

			// at least one of the following is false if is_opt is false:

				//  param_size <  eight
				//       Trait == all
				// *parameters == instr

			// if is optimal and Trait == all then *parameters != instr

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// routines:

/***********************************************************************************************************************/

// is cache level 0:

	// locations: id, instr, regs, h0, h4, args

	// it's cache level 0 if:

		// HandleLoc     != id       (error)
		// HandleLoc     == instr
		// HandleLoc     == regs  && HandlePos  < eight
		// HandleLoc     == h0    && HandlePos  < eight
		// HandleLoc     == h4    && HandlePos  < eight
		// HandleLoc     == args  && HandlePos  < eight

		// NameLoc       == id       (embedded in Handle)
		// NameLoc       == instr
		// NameLoc       == regs  && NamePos    < eight
		// NameLoc       == h0    && NamePos    < eight
		// NameLoc       == h4    && NamePos    < eight
		// NameLoc       == args  && NamePos    < eight

		// PackLoc       == id
		// PackLoc       != instr    (error)
		// PackLoc       == regs  && PackPos    < eight
		// PackLoc       == h0    && PackPos    < eight
		// PackLoc       == h4    && PackPos    < eight
		// PackLoc       == args  && PackPos    < eight

		// ParamTrait    == id
		// ParamTrait    == all

		// ParamSize     <  eight

		// ParamLoc[0-7] != id       (error)
		// ParamLoc[0-7] == instr
		// ParamLoc[0-7] == regs  && ParamPos[] < eight
		// ParamLoc[0-7] == h0    && ParamPos[] < eight
		// ParamLoc[0-7] == h4    && ParamPos[] < eight
		// ParamLoc[0-7] == args  && ParamPos[] < eight

	// it's cache level 0 if (refactored):

		// HandleLoc     != id       (error)
		// HandleLoc     == instr
		// HandlePos     <  eight

		// NameLoc       == id       (embedded in Handle)
		// NameLoc       == instr
		// NamePos       <  eight

		// PackLoc       == id
		// PackLoc       != instr    (error)
		// PackPos       <  eight

		// ParamSize     <  eight

		// ParamTrait    == id
		// ParamTrait    == all

		// ParamLoc[0-7] != id       (error)
		// ParamLoc[0-7] == instr
		// ParamPos[0-7] <  eight

/***********************************************************************************************************************/

// is cache level 1:

	// locations: id, instr, regs, h0, h4, args

	// it's cache level 1 if:

		// HandleLoc     != id       (error)
		// HandleLoc     == instr
		// HandleLoc     == regs  && HandlePos  < eight
		// HandleLoc     == h0    && HandlePos  < eight
		// HandleLoc     == h4    && HandlePos  < eight
		// HandleLoc     == args  && HandlePos  < eight

		// NameLoc       == id       (embedded in Handle)
		// NameLoc       == instr
		// NameLoc       == regs  && NamePos    < eight
		// NameLoc       == h0    && NamePos    < eight
		// NameLoc       == h4    && NamePos    < eight
		// NameLoc       == args  && NamePos    < eight

		// PackLoc       == id
		// PackLoc       != instr    (error)
		// PackLoc       == regs  && PackPos    < eight
		// PackLoc       == h0    && PackPos    < eight
		// PackLoc       == h4    && PackPos    < eight
		// PackLoc       == args  && PackPos    < eight

		// ParamTrait    == id
		// ParamTrait    == all

		// ParamSize     <  eight

		// ParamLoc[0-7] != id       (error)
		// ParamLoc[0-7] == instr
		// ParamLoc[0-7] == regs  && ParamPos[] < eight
		// ParamLoc[0-7] == h0    && ParamPos[] < eight
		// ParamLoc[0-7] == h4    && ParamPos[] < eight
		// ParamLoc[0-7] == args  && ParamPos[] < eight

	// it's cache level 1 if (refactored):

		// HandleLoc     != id       (error)
		// HandleLoc     == instr
		// HandlePos     <  eight

		// NameLoc       == id       (embedded in Handle)
		// NameLoc       == instr
		// NamePos       <  eight

		// PackLoc       == id
		// PackLoc       != instr    (error)
		// PackPos       <  eight

		// ParamSize     <  eight

		// ParamTrait    == id
		// ParamTrait    == all

		// ParamLoc[0-7] != id       (error)
		// ParamLoc[0-7] == instr
		// ParamPos[0-7] <  eight

/***********************************************************************************************************************/

// is id params optimal:

	// clang complains about the following:

		//	for (cindex_type *j = params, *k = j+1; result && j < end; j += 2, k += 2)
		//		result = (*j == CL::instr) || MI::is_optimal(*k);

	// the concern is UB indexing, but otherwise allows this:

		//	for (cindex_type *k = params; result && k < end; k += 2)
		//		result = (*k == CL::instr) || MI::is_optimal(*(k+1));

	// or even this:

		//	cindex_type *k	= params;
		//	bool result	= true;

		//	for (index_type j = 0; result && j < size; ++j, ++k)
		//		result = (*k == CL::instr) || MI::is_optimal(*++k);

/***********************************************************************************************************************/

// block:

	// Block programs consist of two block instructions and some machine
	// modifiers: As such they can be optimized into a single instruction.

/***********************************************************************************************************************/

// call:

	// closed:

		// The instruction length is the same as with open.
		// This is to allow for the refactoring of algorithms.

/***********************************************************************************************************************/

// machination:

	// Do not refactor using other templated structs. Although these definitions are potentially redundant,
	// trampolining/detouring require a distinct keyword so there's no confusion with other returned values.

/***********************************************************************************************************************/

// needed any more?

		//	template<typename... Ts>
		//	static constexpr bool all(Ts... vs) { return (... && vs); }

		//	template<typename T, typename... Ts>
		//	static constexpr bool all_equal(T v, Ts... vs) { return all((v == vs)...); }

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

