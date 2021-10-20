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

// machine name narratives:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// abstract:

	// passers:

		// id:

			// No corresponding machine,
			// exists for theoretical purposes.

/***********************************************************************************************************************/

// block:

	// halters:

		// pause:

			// [meta]
			// Needed for trampolining.

		// first:

			// [first]
			// Needed for at.

		// rest:

			// [rest]
			// Complement to first.

		// pack:

			// [all]
			// Needed for lists.

	// debuggers:

		// depth:

			// [meta]
			// Needed for analysis.

		// dump:

			// [meta]
			// Needed for analysis.

	// interoperability:

		// pass:

			// [meta]
			// Needed for interoperability.
			// Needed to mitigate nesting depths.

	// passers:

		// stack -> stack:

			// pop_2_n:

				// []
				// 

			// push_2_n:

				// []
				// 

			// fold_2_n:

				// []
				// Privileged as an optimization.

			// roll_2_n:

				// []
				// Privileged as an optimization.

		// stack -> heap:

			// move_2_n_s_to_h0:

				// [first]
				// Needed for move s to h0.

			// move_2_n_s_to_h1:

				// [first]
				// Needed for move s to h1.

/***********************************************************************************************************************/

// variadic:

	// halters:

		// stop:

			// [first]
			// Needed for interoperability.

	// passers:

		// stack -> stack:

			// pop:

				// []
				// 

			// push:

				// []
				// 

			// fold_s0:

				// []
				// 

			// roll_s0:

				// []
				// 

		// stack -> heap:

			// copy_s0_to_h0:

				// []
				// 

			// move_s_to_h0:

				// []
				// 

			// move_s_to_h1:

				// []
				// 

		// heap -> stack:

			// copy_h0_to_sf:

				// []
				// 

			// copy_h1_to_sf:

				// []
				// 

			// move_h0_to_sf:

				// []
				// 

			// move_h1_to_sf:

				// []
				// 

			// apply_h0_move_to_sf:

				// []
				// 

			// compel_h0_move_to_sf:

				// []
				// 

/***********************************************************************************************************************/

// permutatic:

	// passers:

		// copy_sn_to_h0:

			// []
			// 

		// move_sn_to_h0:

			// []
			// 

		// erase_sn:

			// []
			// 

		// rotate_sn:

			// []
			// 

		// insert_h0_to_sn:

			// []
			// 

		// replace_h0_to_sn:

			// []
			// 

		// apply_h0_replace_to_sn:

			// []
			// 

		// compel_h0_replace_to_sn:

			// []
			// 

/***********************************************************************************************************************/

// distributic:

	// passers:

		// erase:

			// []
			// 

		// insert:

			// []
			// 

		// replace:

			// []
			// 

		// fold:

			// []
			// 

		// roll:

			// []
			// 

		// apply:

			// []
			// Needed for general purpose register machines.

		// compel:

			// []
			// Needed for general purpose register machines.

		// test:

			// []
			// Needed for general purpose register machines.

		// check:

			// []
			// Needed for general purpose register machines.

		// jump:

			// []
			// 

/***********************************************************************************************************************/

// near linear:

	// halters:

		// halt:

			// []
			// 

	// passers:

		// size_of:

			// []
			// 

		// drop:

			// []
			// 

		// map:

			// []
			// 

		// plot:

			// []
			// 

		// align:

			// []
			// 

		// lift:

			// []
			// 

		// stem:

			// []
			// 

		// costem:

			// []
			// 

		// cycle:

			// No corresponding machine,
			// 

/***********************************************************************************************************************/

// register:

	// passers:

		// assign:

			// [object]
			// Needed for general purpose register machines.

		// branch:

			// [meta]
			// Needed for general purpose register machines.

		// go_to_s0:

			// [meta]
			// 

		// go_to:

			// [meta]
			// Needed for general purpose register machines.

		// save:

			// [object]
			// Needed for general purpose register machines.

		// restore:

			// [object]
			// Needed for general purpose register machines.

/***********************************************************************************************************************/

// reflection:

	// sizes:

		// reg_size:

			// []
			// 

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

