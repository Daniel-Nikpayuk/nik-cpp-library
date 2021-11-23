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

// programs source:

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

// interposition:

/***********************************************************************************************************************/

	template<typename... Ts>
	static constexpr auto U_pre_pack_Ts = U_opt_pack_Vs<U_type_T<T_pretype_T<Ts>>...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machine names:

public:

/***********************************************************************************************************************/

	// I would prefer to implement these as enums, but I don't know how
	// to get gcc/clang to pattern match the register machine when I do.

	struct MachineName
	{
		// interposers:

			static constexpr key_type pause					=  0;

			static constexpr key_type pose					=  1;
			static constexpr key_type load					=  2;
			static constexpr key_type reload				=  3;
			static constexpr key_type call					=  4;
			static constexpr key_type pass					=  5;
			static constexpr key_type ship					=  6;

			static constexpr key_type branch				=  7; // <machine>
			static constexpr key_type go_to					=  8; // <machine>

		// halters:

			static constexpr key_type first					=  9;
			static constexpr key_type rest					= 10;

		// debuggers:

			static constexpr key_type depth					= 11;
			static constexpr key_type dump					= 12;

			static constexpr key_type stack					= 13;
			static constexpr key_type heaps					= 14;

		// passers:

			static constexpr key_type unpack_i_block__insert_at_h1_back	= 15; // <machine>
			static constexpr key_type drop_s_block				= 16; // <halters>

			static constexpr key_type move_s_block				= 17; // <mutators>
			static constexpr key_type move_s_all				= 18; // <mutators>

			static constexpr key_type move_h0_all				= 19; // <mutators>
			static constexpr key_type move_h1_all				= 20; // <mutators>

			static constexpr key_type apply_h0_all				= 21; // <machine>
			static constexpr key_type compel_h0_all				= 22; // <machine>
	};

	using MN = MachineName;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// notes:

/***********************************************************************************************************************/

	struct MachineNote
	{
		static constexpr key_type block				= 0;
		static constexpr key_type linear			= 1;
		static constexpr key_type turing			= 2;
		static constexpr key_type user				= 3;
	};

	using MT = MachineNote;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// modes:

/***********************************************************************************************************************/

	struct MachineMode
	{
			static constexpr key_type not_applicable	= 0;
			static constexpr key_type na			= not_applicable;	// convenience for
												// default params.

		// memonics:

			static constexpr key_type stack			= 1;
			static constexpr key_type heap_zero		= 2;
			static constexpr key_type heap_one		= 3;

		// locators:

			static constexpr key_type front			= 4;
			static constexpr key_type back			= 5;
	};

	using MM = MachineMode;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// instructions:

/***********************************************************************************************************************/

	struct MachineInstr
	{
		using type						= index_type const*;

		static constexpr index_type size			= 0;
		static constexpr index_type name			= 1;
		static constexpr index_type note			= 2;

		static constexpr index_type length (type i)		{ return i[size]; }
		static constexpr index_type last   (type i)		{ return i[length(i)]; }
	};

	using MI							= MachineInstr;
	using instr_type						= typename MI::type;

		// pack length is stored as the initial value.

	template<index_type... Vs>
	static constexpr instr_type instruction = array<index_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// labels:

/***********************************************************************************************************************/

	struct MachineLabel
	{
		using type						= instr_type const*;

		static constexpr index_type size			= 0;

		static constexpr index_type length (type l)		{ return l[size][MI::size]; }
		static constexpr instr_type last   (type l)		{ return l[length(l)]; }
	};

	using ML							= MachineLabel;
	using label_type						= typename ML::type;

		// pack length is stored as the initial value.

	template<instr_type... Vs>
	static constexpr label_type label = array<instr_type, array<index_type, sizeof...(Vs)>, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controllers:

/***********************************************************************************************************************/

	struct MachineContr
	{
		using type						= label_type const*;

		static constexpr index_type size			= 0;

		static constexpr index_type length   (type c)		{ return c[size][ML::size][MI::size]; }
		static constexpr label_type last     (type c)		{ return c[length(c)]; }
	};

	using MC							= MachineContr;
	using contr_type						= typename MC::type;

		// pack length is stored as the initial value.

	template<label_type... Vs>
	static constexpr contr_type controller = array
		<label_type, array<instr_type, array<index_type, sizeof...(Vs)>>, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// (block) programs:

	// Optimized to use a single instruction as the controller.

	// Block programs are intended *only* to be called by linear, turing, or user programs. 
	// Their instruction indices coincide with their machine modifiers.

/***********************************************************************************************************************/

// names:

	struct BlockName
	{
		// halters:

		// passers:

			static constexpr key_type unpack_i_segment__insert_at_h1_back		= 0; // <machine>

			static constexpr key_type drop_s_segment				= 1; // <list>

			static constexpr key_type move_s_segment				= 2; // <mutators>
	};

	using BN = BlockName;

/***********************************************************************************************************************/

	template<key_type...>
	struct block_program
	{
		// defaults:

			static constexpr depth_type depth = 500;

		// accessors:

			static constexpr auto value(instr_type i, index_type, index_type, key_type p)
				{ return i[p]; }

			static constexpr index_type max_note(index_type n)
			{
				return	(n >= _2_9) ? 9 :
					(n >= _2_8) ? 8 :
					(n >= _2_7) ? 7 :
					(n >= _2_6) ? 6 :
					(n >= _2_5) ? 5 :
					(n >= _2_4) ? 4 :
					(n >= _2_3) ? 3 :
					(n >= _2_2) ? 2 :
					(n >= _2_1) ? 1 : 0 ;
			}

			static constexpr index_type max_index2(index_type n)
			{
				return	(n >= _2_9) ? _2_9 :
					(n >= _2_8) ? _2_8 :
					(n >= _2_7) ? _2_7 :
					(n >= _2_6) ? _2_6 :
					(n >= _2_5) ? _2_5 :
					(n >= _2_4) ? _2_4 :
					(n >= _2_3) ? _2_3 :
					(n >= _2_2) ? _2_2 :
					(n >= _2_1) ? _2_1 :
					(n >= _2_0) ? _2_0 : 0 ;
			}

		// navigators:

			static constexpr key_type next_name(instr_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0)	return MN::pause;	// assumes i >= j, next i := i - j
				else if (i > j)	return c[MI::name];	// implies next i > 0
				else 		return c[MI::note];	// otherwise next i == 0
			}

			static constexpr key_type next_note(instr_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0)	return _zero;
				else		return max_note(i - j);
			}

			static constexpr depth_type next_depth(depth_type d)
			{
				if (d > 0)	return d-1;
				else 		return d;
			}

			static constexpr index_type next_index1(instr_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0)	return i;
				else 		return i - j;
			}

			static constexpr index_type next_index2(instr_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0)	return j;
				else		return max_index2(i - j);
			}
	};

	using T_BP				= block_program<>;
	static constexpr auto U_block_program	= U_type_T<block_program<>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// (linear) programs:

	// Optimized to use a single label as the controller.

/***********************************************************************************************************************/

// names:

	struct LinearName
	{
	// (level 1)

		// halters:

			static constexpr index_type at			=  0;

		// passers:

	// (level 2)

		// mutators:

			static constexpr index_type erase		=  1;
			static constexpr index_type insert		=  2;
			static constexpr index_type replace		=  3;

		// control:

			static constexpr index_type go_to_label		=  4;
	};

	using LN = LinearName;

/***********************************************************************************************************************/

	template<key_type...>
	struct linear_program
	{
		// defaults:

			static constexpr depth_type depth		= 500;

			static constexpr index_type initial_i		= _one;
			static constexpr index_type initial_j		= _zero;

		// instructions:

			static constexpr index_type linear_name		= 3;
			static constexpr index_type linear_note		= 4;
			static constexpr index_type linear_index	= 4;

		// accessors:

			static constexpr auto value(label_type l, index_type, index_type j, key_type p)
				{ return l[j][p]; }

		// navigators:

			static constexpr key_type next_name(label_type l, depth_type d, index_type, index_type j)
			{
				if (d == 0)	return MN::pause;
				else 		return l[j+1][MI::name];
			}

			static constexpr key_type next_note(label_type l, depth_type d, index_type, index_type j)
			{
				if (d == 0)	 return _zero;
				else		 return l[j+1][MI::note];
			}

			static constexpr depth_type next_depth(depth_type d)
			{
				if (d > 0)	return d-1;
				else 		return d;
			}

			static constexpr index_type next_index1(label_type, depth_type, index_type i, index_type)
			{
				return i;
			}

			static constexpr index_type next_index2(label_type, depth_type d, index_type, index_type j)
			{
				if (d == 0)	return j;
				else 		return j+1;
			}
	};

	using T_LP				= linear_program<>;
	static constexpr auto U_linear_program	= U_type_T<linear_program<>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// turing:

/***********************************************************************************************************************/

	template<key_type...>
	struct turing_program
	{
		// defaults:

			static constexpr depth_type depth	= 500;

			static constexpr index_type initial_i	= _one;
			static constexpr index_type initial_j	= _zero;

		// accessors:

			static constexpr auto value(contr_type c, index_type i, index_type j, key_type p)
				{ return c[i][j][p]; }

		// initial indices:

			static constexpr index_type initial_next_index1(contr_type c, index_type i, index_type j)
			{
				return i + bool{j == ML::length(c[i])};	// j == last : return i+1.
									// j != last : return i.
			}

			static constexpr index_type initial_next_index2(contr_type c, index_type i, index_type j)
			{
				return (j == ML::length(c[i])) ? _one : j+1;	// j == last : return one.
										// j != last : return j+1.
			}

		// navigators:

			static constexpr key_type next_name(contr_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0) return MN::pause;

				index_type ni = next_index1(c, d, i, j);
				index_type nj = next_index2(c, d, i, j);

				return c[ni][nj][MI::name];
			}

			static constexpr key_type next_note(contr_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0) return _zero;

				index_type ni = next_index1(c, d, i, j);
				index_type nj = next_index2(c, d, i, j);

				return c[ni][nj][MI::note];
			}

			static constexpr depth_type next_depth(depth_type d)
			{
				if (d > 0)	return d-1;
				else 		return d;
			}

			static constexpr index_type next_index1(contr_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0) return i;

				index_type ni = initial_next_index1(c, i, j);
				index_type nj = initial_next_index2(c, i, j);
				key_type note = c[ni][nj][MI::note];

				if (note == MT::linear)
				{
					key_type linear_name = c[ni][nj][T_LP::linear_name];

					if (linear_name == LN::go_to_label) return c[ni][nj][T_LP::linear_index];
				}

				return ni;
			}

			static constexpr index_type next_index2(contr_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0) return j;

				index_type ni = initial_next_index1(c, i, j);
				index_type nj = initial_next_index2(c, i, j);
				key_type note = c[ni][nj][MI::note];

				if (note == MT::linear)
				{
					key_type linear_name = c[ni][nj][T_LP::linear_name];

					if (linear_name == LN::go_to_label) return _one;
				}

				return nj;
			}
	};

	using T_TP				= turing_program<>;
	static constexpr auto U_turing_program	= U_type_T<turing_program<>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

