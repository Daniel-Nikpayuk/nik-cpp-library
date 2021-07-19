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

// controller declarations source:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machine specs:

	// I would prefer to implement these as enums, but I don't know how
	// to get gcc/clang to pattern match the register machine when I do.

/***********************************************************************************************************************/

// names:

	struct MachName
	{
	// block:

		// halters:

			static constexpr key_type pause						=  0; // atomic

			static constexpr key_type first						=  1; // atomic
			static constexpr key_type rest						=  2; // atomic
			static constexpr key_type pack						=  3; // atomic

		// debuggers:

			static constexpr key_type depth						=  4; // atomic
			static constexpr key_type dump						=  5; // atomic

		// passers:

			// stack -> stack:

			static constexpr key_type drop_s_block					=  6; // atomic
			static constexpr key_type move_s_block__insert_at_s_back		=  7; // atomic

			static constexpr key_type fold_s_block__op_at_h0_first			=  8; // atomic
			static constexpr key_type roll_s_block__act_at_h0_first			=  9; // atomic

			// stack -> heap:

			static constexpr key_type move_s_block__insert_at_h0_front		= 10; // atomic
			static constexpr key_type move_s_block__insert_at_h0_back		= 11; // atomic
			static constexpr key_type move_s_block__insert_at_h1_back		= 12; // atomic

			static constexpr key_type move_s_first__replace_h0_value		= 13; // *

			static constexpr key_type copy_s_block__insert_at_h0_front		= 14; // atomic

		// interposers:

			static constexpr key_type call						= 15; // atomic
			static constexpr key_type pass						= 16; // atomic

	// variadic:

		// halters:

			// none.

		// passers:

			// stack -> stack:

			static constexpr key_type fold_s_segment__pos_at_h0_first		= 17; // maybe atomic
			static constexpr key_type roll_s_segment__pos_at_h0_first		= 18; // maybe atomic

			// stack -> heap:

			// heap -> stack:

			static constexpr key_type move_h0_all__insert_at_s_front		= 19; // atomic
			static constexpr key_type move_h1_all__insert_at_s_front		= 20; // atomic

			static constexpr key_type move_h0_all__pack_at_s_front			= 21; // *

			static constexpr key_type copy_h0_all__insert_at_s_front		= 22; // atomic
			static constexpr key_type copy_h1_all__insert_at_s_front		= 23; // atomic

			static constexpr key_type apply_h0_all__move__insert_at_s_front		= 24; // atomic
			static constexpr key_type apply_h0_all__replace_h0_all			= 25; // atomic

			static constexpr key_type compel_h0_all__move__insert_at_s_front	= 26; // atomic
			static constexpr key_type compel_h0_all__replace_h0_all			= 27; // atomic

	// permutatic:

		// passers:

			// stack -> stack:

			static constexpr key_type drop_s_pos					= 28; // optimizations
			static constexpr key_type move_s_pos__insert_at_s_back			= 29; // optimizations

			// stack -> heap:

			static constexpr key_type move_s_pos__insert_at_h0_front		= 30; // optimizations
			static constexpr key_type copy_s_pos__insert_at_h0_front		= 31; // optimizations

			// heap -> stack:

			static constexpr key_type move_h0_all__insert_at_s_pos			= 32; // optimizations
			static constexpr key_type move_h0_all__replace_at_s_pos			= 33; // optimizations

			static constexpr key_type apply_h0_all__move__replace_at_s_pos		= 34; // optimizations
			static constexpr key_type compel_h0_all__move__replace_at_s_pos		= 35; // optimizations

	// distributic:

		// passers:

			static constexpr key_type skip						= 36; // atomic

	// near linear:

		// halters:

		// passers:

			static constexpr key_type size_of					= 37; // atomic
			static constexpr key_type clear						= 38; // atomic
			static constexpr key_type map						= 39; // atomic
			static constexpr key_type plot						= 40; // atomic
			static constexpr key_type align						= 41; // atomic

			static constexpr key_type cycle						= 42; // optimized

	// register:

		// passers:

			static constexpr key_type assign					= 43; // maybe atomic

			static constexpr key_type branch					= 44; // atomic
			static constexpr key_type go_to__next_at_h0_front			= 45; // maybe atomic
			static constexpr key_type go_to						= 46; // maybe atomic

	// reflection:

		// sizes:

			static constexpr key_type reg_size					= 47;
	};

	using MN = MachName;

/***********************************************************************************************************************/

// notes:

	struct CallNote
	{
		static constexpr key_type block			= 0;
		static constexpr key_type linear		= 1;
		static constexpr key_type user			= 2;
	};

	struct ApplNote
	{
		static constexpr key_type unary			= 0;
		static constexpr key_type binary		= 1;

		static constexpr key_type note (key_type args) { return (args == _one) ? unary : binary; }
	};

	using PredNote = ApplNote;

	struct GotoNote
	{
		static constexpr key_type contr			= 0;
		static constexpr key_type regtr			= 1;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// instructions:

/***********************************************************************************************************************/

	struct MachInstr
	{
		using type					= index_type const*;

		static constexpr index_type size		= 0;
		static constexpr index_type name		= 1;
		static constexpr index_type note		= 2;
		static constexpr index_type pos			= 3;

		static constexpr index_type length (type i)         { return i[size]; }
		static constexpr index_type last   (type i)         { return i[length(i)]; }
		static constexpr index_type patch  (index_type pos) { return (pos < _eight) ? pos+1 : _zero; }
	};

	using MI						= MachInstr;
	using instr_type					= typename MI::type;

	struct CallInstr : public MI
	{
		static constexpr index_type arch		= 2;
		static constexpr index_type name		= 3;
		static constexpr index_type pos			= 4;
	};

	struct AsgnInstr : public MI
	{
		static constexpr index_type obj			= 4;
	};

	struct ApplInstr : public MI
	{
		static constexpr index_type op			= 4;
		static constexpr index_type arg			= 5;
		static constexpr index_type arg1		= 5;
		static constexpr index_type arg2		= 6;
	};

	struct PredInstr : public MI
	{
		static constexpr index_type pred		= 3;
		static constexpr index_type input		= 4;
		static constexpr index_type input1		= 4;
		static constexpr index_type input2		= 5;
	};

	struct NLInstr : public MI
	{
		static constexpr key_type appl			= 2;

		static constexpr key_type cond			= 2;
		static constexpr key_type appl1			= 3;
		static constexpr key_type appl2			= 4;
	};

		// pack length is stored as the initial value.

	template<index_type... Vs>
	static constexpr instr_type instruction = array<index_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// labels:

/***********************************************************************************************************************/

	struct MachLabel
	{
		using type				= instr_type const*;

		static constexpr index_type size 	= 0;
		static constexpr index_type first	= 1;
		static constexpr index_type second	= 2;

		static constexpr index_type length (type l) { return l[size][MI::size]; }
		static constexpr instr_type last   (type l) { return l[length(l)]; }
	};

	using ML					= MachLabel;
	using label_type				= typename ML::type;

		// pack length is stored as the initial value.

	template<instr_type... Vs>
	static constexpr label_type label = array<instr_type, array<index_type, sizeof...(Vs)>, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controllers:

/***********************************************************************************************************************/

	struct MachContr
	{
		using type				= label_type const*;

		static constexpr index_type size	= 0;
		static constexpr index_type first	= 1;

		static constexpr index_type length   (type c) { return c[size][ML::size][MI::size]; }
		static constexpr label_type last     (type c) { return c[length(c)]; }
		static constexpr index_type reg_size (type c) { return ML::last(last(c))[MI::pos]; }
	};

	using MC					= MachContr;
	using contr_type				= typename MC::type;

		// pack length is stored as the initial value.

	template<label_type... Vs>
	static constexpr contr_type controller = array
		<label_type, array<instr_type, array<index_type, sizeof...(Vs)>>, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

