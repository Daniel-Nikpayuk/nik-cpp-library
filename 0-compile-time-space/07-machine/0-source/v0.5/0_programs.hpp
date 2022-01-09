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
	static constexpr auto U_prepack_Ts = U_opt_pack_Vs<U_pretype_T<Ts>...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machine names:

public:

/***********************************************************************************************************************/

	// I would prefer to implement these as enums, but I don't know how
	// to get gcc/clang to pattern match the register machine when I do.

	// block machines break the nomenclature design by catenating their
	// name x note indices. This is done to allow for reuse of their notes.

	struct MachineName
	{
			static constexpr key_type id						=  0;
			static constexpr key_type identity					= id; // convenience for
												      // default params.

		// halters:

			static constexpr key_type value						=  1;

		// interoperators:

			static constexpr key_type call						=  2;
			static constexpr key_type detour					=  3;
			static constexpr key_type machinate					=  4;

		// passers:

			// block:

			static constexpr key_type unpack_i_block__insert_at_h1_back		=  5; // <machine>
			static constexpr key_type drop_r_block					=  6; // <halters>
			static constexpr key_type move_r_block__insert_at_h1_back		=  7; // <mutators>

			static constexpr key_type fold_r_block					=  8; // <halters>
			static constexpr key_type roll_r_block					=  9; // <halters>

			// linear:

			static constexpr key_type move_h0_first					= 10; // <mutators>
			static constexpr key_type move_h1_all					= 11; // <mutators>

			// user:

			static constexpr key_type go_to						= 12; // <machine>
			static constexpr key_type apply_h0_all					= 13; // <machine>
			static constexpr key_type compel_h0_all					= 14; // <machine>
	};

	using MN = MachineName;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// notes:

/***********************************************************************************************************************/

	struct MachineNote
	{
			static constexpr key_type id					=  0;
			static constexpr key_type identity				= id;	// convenience for
												// default params.

		// halters:

			// value:

			static constexpr key_type first					=  1;
			static constexpr key_type rest					=  2;

			static constexpr key_type depth					=  3;
			static constexpr key_type dump					=  4;

			static constexpr key_type registers				=  5;
			static constexpr key_type arguments				=  6;

		// interoperators:

			// call (policy):

			static constexpr key_type insert_at_r_front			=  7;
			static constexpr key_type insert_at_h0_front			=  8;
			static constexpr key_type insert_at_h0_back			=  9;
			static constexpr key_type insert_at_h1_back			= 10;

			// call/detour:

			static constexpr key_type block					= 11;
			static constexpr key_type linear				= 12;
			static constexpr key_type user					= 14;
			static constexpr key_type user1					= 15;
			static constexpr key_type user2					= 16;

			// detour:

			static constexpr key_type call					= 17;
			static constexpr key_type load					= 18;

			// machinate:

			static constexpr key_type pause					= 19;
			static constexpr key_type unwind				= 20;

		// passers:

			// user:

			static constexpr key_type conditional				= 21;
			static constexpr key_type replace_at_h0_front			= 22;
	};

	using MT = MachineNote;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// instructions:

/***********************************************************************************************************************/

	struct MachineInstr
	{
		using type							= index_type const*;

		static constexpr index_type size				= 0;
		static constexpr index_type name				= 1;
		static constexpr index_type note				= 2;

		static constexpr index_type length (type i)			{ return i[size]; }
		static constexpr index_type last   (type i)			{ return i[length(i)]; }
	};

	using MI								= MachineInstr;
	using instr_type							= typename MI::type;

	struct CallInstr : public MachineInstr
	{
		static constexpr index_type call_name				= 1;
		static constexpr index_type call_note				= 2;
		static constexpr index_type name				= 3;

		static constexpr index_type call_policy				= 4;
	};

	using CI = CallInstr;

		// pack length is stored as the initial value.

	template<index_type... Vs>
	static constexpr instr_type instruction = array<index_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// labels:

/***********************************************************************************************************************/

	struct MachineLabel
	{
		using type							= instr_type const*;

		static constexpr index_type size				= 0;

		static constexpr index_type length (type l)			{ return l[size][MI::size]; }
		static constexpr instr_type last   (type l)			{ return l[length(l)]; }
	};

	using ML								= MachineLabel;
	using label_type							= typename ML::type;

		// pack length is stored as the initial value.

	template<instr_type... Vs>
	static constexpr label_type label = array<instr_type, array<index_type, sizeof...(Vs)>, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// controllers:

/***********************************************************************************************************************/

	struct MachineContr
	{
		using type							= label_type const*;

		static constexpr index_type size				= 0;

		static constexpr index_type length (type c)			{ return c[size][ML::size][MI::size]; }
		static constexpr label_type last   (type c)			{ return c[length(c)]; }
	};

	using MC								= MachineContr;
	using contr_type							= typename MC::type;

		// pack length is stored as the initial value.

	template<label_type... Vs>
	static constexpr contr_type controller = array
		<label_type, array<instr_type, array<index_type, sizeof...(Vs)>>, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// (block) programs:

	// Block programs are intended *only* to be called by linear/user programs. 

	// Block programs consist of two block instructions. Minimally, in order to call
	// these programs only "unpack i segment, insert at h1 back" is required to bootstrap
	// the calling/loading process for the others. As the minimum number of required
	// programs all have the same form they are optimized into a single-call loader.

	// As an optimization the two co-instructions are encoded as a single one instead.

/***********************************************************************************************************************/

// names:

	struct BlockName
	{
		static constexpr key_type id						=  0;
		static constexpr key_type identity					= id; // convenience for
											      // default params.
		static constexpr key_type unpack_i_segment__insert_at_h1_back		=  1; // <machine>
		static constexpr key_type drop_r_segment				=  2; // <list>
		static constexpr key_type move_r_segment__insert_at_h1_back		=  3; // <mutators>
		static constexpr key_type fold_r_segment				=  4; // <list>
		static constexpr key_type roll_r_segment				=  5; // <list>
	};

	using BN = BlockName;

/***********************************************************************************************************************/

// instructions:

	struct BlockInstr : public MachineInstr
	{
		static constexpr index_type coname				=  2;
		static constexpr index_type conote				=  3;
	};

	using BI = BlockInstr;

	struct BlockCallInstr : public CallInstr
	{
		static constexpr index_type pos					=  5;

		static constexpr index_type coname				=  6;
		static constexpr index_type conote				=  7;
	};

	using BCI = BlockCallInstr;

/***********************************************************************************************************************/

	template<key_type...>
	struct block_program
	{
			using ctr_type					= instr_type;

		// defaults:

			static constexpr depth_type depth		= 500;

		// accessors:

			static constexpr auto instr(ctr_type c, index_type, index_type)
				{ return c; }

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

			static constexpr key_type next_name(ctr_type c, index_type i, index_type j)
			{
				if (i > j)		return c[BI::name];	// assumes i >= j, next i := i - j
				else 			return c[BI::coname];	// implies next i > 0
			}

			static constexpr key_type next_note(ctr_type c, index_type i, index_type j)
			{
				if (i > j)		return max_note(i - j);	// assumes i >= j, next i := i - j
				else			return c[BI::conote];
			}

			static constexpr index_type next_index1(ctr_type c, index_type i, index_type j)
			{
				return i - j;
			}

			static constexpr index_type next_index2(ctr_type c, index_type i, index_type j)
			{
				return max_index2(i - j);
			}

		// programs:

			template<auto call_ins>
			static constexpr ctr_type make = block_program
			<
				call_ins[BCI::name]

			>::template lines
			<
				call_ins[BCI::coname],
				call_ins[BCI::conote]
			>;
	};

	using T_block_program				= block_program<>;
	static constexpr auto U_block_program		= U_type_T<block_program<>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// (linear) programs:

	// Optimized to use a single label as the controller.

/***********************************************************************************************************************/

// names:

	struct LinearName
	{
			static constexpr key_type id					=  0;
			static constexpr key_type identity				= id; // convenience for
											      // default params.

		// mutators:

			static constexpr key_type erase					=  1;
			static constexpr key_type insert				=  2;
			static constexpr key_type replace				=  3;

		// interoperators:

			static constexpr key_type make					=  4;
			static constexpr key_type run					=  5;

			static constexpr key_type instr_goto				=  6;
			static constexpr key_type regstr_goto				=  7;

			static constexpr key_type instr_assign				=  8;

			static constexpr key_type test					=  9;
			static constexpr key_type check					= 10;

			static constexpr key_type apply					= 11;
			static constexpr key_type compel				= 12;
	};

	using LN = LinearName;

/***********************************************************************************************************************/

// instructions:

	struct LinearInstr : public MachineInstr
	{
		// none.
	};

	using LI = LinearInstr;

	struct LinearCallInstr : public CallInstr
	{
		static constexpr index_type offset			= 5;
	};

	using LCI = LinearCallInstr;

/***********************************************************************************************************************/

	template<key_type...>
	struct linear_program
	{
			using ctr_type					= label_type;

		// defaults:

			static constexpr depth_type depth		= 500;

			static constexpr index_type initial_i		= _one;
			static constexpr index_type initial_j		= _zero;

		// accessors:

			static constexpr auto instr(ctr_type c, index_type, index_type j)
				{ return c[j]; }

		// navigators:

			static constexpr key_type next_name(ctr_type c, index_type, index_type j)
			{
				return c[j+1][MI::name];
			}

			static constexpr key_type next_note(ctr_type c, index_type, index_type j)
			{
				return c[j+1][MI::note];
			}

			static constexpr index_type next_index1(ctr_type, index_type i, index_type)
			{
				return i;
			}

			static constexpr index_type next_index2(ctr_type, index_type, index_type j)
			{
				return j+1;
			}

		// programs:

			template<auto call_ins, auto... Vs>
			static constexpr ctr_type make = linear_program
			<
				call_ins[LCI::name]

			>::template lines<Vs...>;
	};

	using T_linear_program				= linear_program<>;
	static constexpr auto U_linear_program		= U_type_T<linear_program<>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// user:

/***********************************************************************************************************************/

// instructions:

	struct UserInstr : public MachineInstr
	{
		// none.
	};

	using UI = UserInstr;

	struct UserCallInstr : public CallInstr
	{
		static constexpr index_type pos				= 5;
		static constexpr index_type prog			= 6;
		static constexpr index_type adj				= 7;

		static constexpr index_type offset			= 8;
	};

	using UCI = UserCallInstr;

/***********************************************************************************************************************/

	template<key_type...>
	struct user_program
	{
			using ctr_type					= contr_type;

		// defaults:

			static constexpr depth_type depth		= 500;

			static constexpr index_type initial_i		= _one;
			static constexpr index_type initial_j		= _zero;

		// accessors:

			static constexpr auto instr(ctr_type c, index_type i, index_type j)
				{ return c[i][j]; }

		// navigators:

			static constexpr key_type next_name(ctr_type c, index_type i, index_type j)
			{
				index_type ni = next_index1(c, i, j);
				index_type nj = next_index2(c, i, j);

				return c[ni][nj][MI::name];
			}

			static constexpr key_type next_note(ctr_type c, index_type i, index_type j)
			{
				index_type ni = next_index1(c, i, j);
				index_type nj = next_index2(c, i, j);

				return c[ni][nj][MI::note];
			}

			static constexpr index_type next_index1(ctr_type c, index_type i, index_type j)
			{
				return i + bool{j == ML::length(c[i])};	// j == last : return i+1.
									// j != last : return i.
			}

			static constexpr index_type next_index2(ctr_type c, index_type i, index_type j)
			{
				return (j == ML::length(c[i])) ? _one : j+1;	// j == last : return one.
										// j != last : return j+1.
			}
	};

	using T_user_program			= user_program<>;
	static constexpr auto U_user_program	= U_type_T<user_program<>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// (meta) navigators:

/***********************************************************************************************************************/

	static constexpr depth_type next_depth(depth_type d)
	{
		if (d == 0)		return d;
		else 			return d-1;
	}

	template<typename tn>
	static constexpr key_type next_name(depth_type d, key_type m, typename tn::ctr_type c, index_type i, index_type j)
	{
		if (d == 0)		return MN::machinate;
		else if (m != MT::id)	return MN::detour;
		else			return tn::next_name(c, i, j);
	}

	template<typename tn>
	static constexpr key_type next_note(depth_type d, key_type m, typename tn::ctr_type c, index_type i, index_type j)
	{
		if (d == 0)		return MT::pause;
		else if (m != MT::id)	return m;
		else			return tn::next_note(c, i, j);
	}

	template<typename tn>
	static constexpr index_type next_index1(depth_type d, key_type m, typename tn::ctr_type c, index_type i, index_type j)
	{
		if (d == 0)		return i;
		else if (m != MT::id)	return i;
		else 			return tn::next_index1(c, i, j);
	}

	template<typename tn>
	static constexpr index_type next_index2(depth_type d, key_type m, typename tn::ctr_type c, index_type i, index_type j)
	{
		if (d == 0)		return j;
		else if (m != MT::id)	return j;
		else 			return tn::next_index2(c, i, j);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

