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

// controllers source:

	// Linear calling works because each of its controllers take register positions as input.
	// The whole purpose after all is to mutate the registers in ways eventually meaningful
	// to Turing complete register machines. Any instructions that interpret parameters
	// differently has a hardcoded machine.

	// e1e: starts with heap one empty, ends with heap one empty.
	// e2e: starts with heaps zero and one empty, ends with heaps zero and one empty.

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// instructions:

public:

/***********************************************************************************************************************/

// interposers:

	template<key_type Note = _zero>
	static constexpr instr_type pause = instruction
	<
		MN::pause, Note
	>;

	template<key_type Note, key_type Subname, key_type Subnote, key_type... Args>
	static constexpr instr_type load = instruction
	<
		MN::load, Note, Subname, Subnote, Args...
	>;

		template<key_type Subname, key_type... Args>
		static constexpr instr_type load_block = instruction
		<
			MN::load, MT::block, Subname, _zero, Args...
		>;

		template<key_type Subname, key_type Subnote, key_type... Args>
		static constexpr instr_type load_linear = instruction
		<
			MN::load, MT::linear, Subname, Subnote, Args...
		>;

		template<key_type Subname, key_type Subnote, key_type... Args>
		static constexpr instr_type load_turing = instruction
		<
			MN::load, MT::turing, Subname, Subnote, Args...
		>;

		template<key_type Subname, key_type Subnote, key_type... Args>
		static constexpr instr_type load_user = instruction
		<
			MN::load, MT::user, Subname, Subnote, Args...
		>;

	template<key_type Note = _zero>
	static constexpr instr_type restack = instruction
	<
		MN::restack, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type compel = instruction
	<
		MN::compel, Note
	>;

// halters:

	template<key_type Note = _zero>
	static constexpr instr_type result = instruction
	<
		MN::result, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type first = instruction
	<
		MN::first, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type rest = instruction
	<
		MN::rest, Note
	>;

// debuggers:

	template<key_type Note = _zero>
	static constexpr instr_type depth = instruction
	<
		MN::depth, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type dump = instruction
	<
		MN::dump, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type stack = instruction
	<
		MN::stack, Note
	>;

	template<key_type Note = _zero>
	static constexpr instr_type heaps = instruction
	<
		MN::heaps, Note
	>;

// passers:

	// stack -> stack:

	template<key_type Note = _zero>
	static constexpr instr_type drop_s_block = instruction
	<
		MN::drop_s_block, Note
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block:

private:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template<key_type...>
	struct block_program
	{
		// Block programs are intended *only* to be called by linear, turing, or user programs. 
		// Their register indices coincide with their controller indices, and as such they are
		// required to accept no additional register index values when resolving their respective
		// controllers. This also means that there are no default controller indices provided here.

		static constexpr auto dispatcher	= U_BD;

		static constexpr depth_type depth	= 500;

		// loading:

		static constexpr auto subname(label_type l, index_type, index_type j)
			{ return l[j][MI::subname]; }

		static constexpr index_type subpos(label_type l, index_type, index_type j)
			{ return l[j][MI::offset]; }
	};

/***********************************************************************************************************************/

// stop:

	template<key_type... filler>
	struct block_program<BN::stop, filler...> : public block_program<filler...>
	{
		static constexpr instr_type controller	= instruction<MN::drop_s_block, MN::first>;
	};

public:

	template<index_type Pos>
	static constexpr instr_type stop = instruction
	<
		MN::load, MT::block, BN::stop, _zero, Pos // is the subnote really needed ?
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear:

// private:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template<key_type...>
	struct linear_program
	{
		static constexpr auto dispatcher	= U_LD;

		static constexpr depth_type depth	= 500;

		static constexpr index_type initial_i	= _one;
		static constexpr index_type initial_j	= _zero;
	};

/***********************************************************************************************************************/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// user:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template<key_type...>
	struct user_program
	{
		static constexpr auto dispatcher	= U_TD;

		static constexpr depth_type depth	= 500;

		static constexpr index_type initial_i	= _one;
		static constexpr index_type initial_j	= _zero;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

