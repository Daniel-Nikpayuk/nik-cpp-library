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

	struct MachineName
	{
			static constexpr key_type id						=  0;
			static constexpr key_type identity					= id; // convenience for
												      // default params.
		// interposers:

			static constexpr key_type pause						=  1;

			static constexpr key_type call						=  2;
			static constexpr key_type make						=  3;
			static constexpr key_type unwind					=  4;
			static constexpr key_type overwrite					=  5;

			static constexpr key_type branch					=  6; // <machine>

		// halters:

			static constexpr key_type first						=  7;
			static constexpr key_type rest						=  8;

		// debuggers:

			static constexpr key_type depth						=  9;
			static constexpr key_type dump						= 10;

			static constexpr key_type registers					= 11;
			static constexpr key_type arguments					= 12;

		// passers:

			static constexpr key_type copy_i_value__insert_at_h0_front		= 13; // <machine>
			static constexpr key_type unpack_i_block__insert_at_h0_back		= 14; // <machine>

			static constexpr key_type drop_r_block					= 15; // <halters>
			static constexpr key_type fold_r_block					= 16; // <halters>
			static constexpr key_type roll_r_block					= 17; // <halters>

			static constexpr key_type move_r_block__insert_at_h1_back		= 18; // <mutators>
			static constexpr key_type move_h0_first__insert_at_r_front		= 19; // <mutators>
			static constexpr key_type move_h1_all__insert_at_r_front		= 20; // <mutators>

			static constexpr key_type apply_h0_all__return_value			= 21; // <machine>
			static constexpr key_type apply_h0_all__move__insert_at_r_front		= 22; // <machine>

			static constexpr key_type compel_h0_all__return_value			= 23; // <machine>
			static constexpr key_type compel_h0_all__move__insert_at_r_front	= 24; // <machine>
	};

	using MN = MachineName;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// notes:

/***********************************************************************************************************************/

	struct MachineNote
	{
		static constexpr key_type id				=  0;
		static constexpr key_type identity			= id; // convenience for
									      // default params.
		static constexpr key_type reindex			=  1;

		static constexpr key_type between			=  2;
		static constexpr key_type block				=  3;
		static constexpr key_type linear			=  4;
		static constexpr key_type user				=  5;
	};

	using MT = MachineNote;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// modes:

/***********************************************************************************************************************/

	struct PassMemonic
	{
			static constexpr key_type id			=  0;
			static constexpr key_type identity		= id; // convenience for
									      // default params.
			static constexpr key_type registers		=  1;
			static constexpr key_type heap_zero		=  2;
			static constexpr key_type heap_one		=  3;
			static constexpr key_type stage2		=  4;
			static constexpr key_type arguments		=  5;
	};

	using PM = PassMemonic;

	struct PassLocation
	{
			static constexpr key_type id			=  0;
			static constexpr key_type identity		= id; // convenience for
									      // default params.
			static constexpr key_type front			=  1;
			static constexpr key_type back			=  2;
	};

	using PL = PassLocation;

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

	struct CallInstr : public MachineInstr
	{
		static constexpr index_type call_name			= 1;
		static constexpr index_type call_note			= 2;
		static constexpr index_type name			= 3;

		static constexpr index_type memonic			= 4;
		static constexpr index_type location			= 5;
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

		static constexpr index_type length (type c)		{ return c[size][ML::size][MI::size]; }
		static constexpr label_type last   (type c)		{ return c[length(c)]; }
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

	// Block programs are intended *only* to be called by linear/user programs. 

	// Block programs consist of two block instructions. Minimally, in order to call
	// these programs only "unpack i segment, insert at h0 back" is required to bootstrap
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
		static constexpr key_type unpack_i_segment__insert_at_h0_back		=  1; // <machine>
		static constexpr key_type drop_r_segment				=  2; // <list>
		static constexpr key_type fold_r_segment				=  3; // <list>
		static constexpr key_type roll_r_segment				=  4; // <list>
		static constexpr key_type move_r_segment__insert_at_h1_back		=  5; // <mutators>
	};

	using BN = BlockName;

/***********************************************************************************************************************/

// instructions:

	struct BlockInstr : public MachineInstr
	{
		static constexpr index_type coname			=  2;
		static constexpr index_type conote			=  3;
	};

	using BI							= BlockInstr;

	struct BlockCallInstr : public CallInstr
	{
		static constexpr index_type pos				=  6;

		static constexpr index_type coname			=  7;
		static constexpr index_type conote			=  8;
	};

	using BCI							= BlockCallInstr;

/***********************************************************************************************************************/

	template<key_type...>
	struct block_program
	{
		// defaults:

			static constexpr depth_type depth = 500;

		// accessors:

			static constexpr auto instr(instr_type i, index_type, index_type)
				{ return i; }

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

			static constexpr key_type next_name(instr_type c, depth_type d, key_type m, index_type i, index_type j)
			{
				if (d == 0)		return MN::pause;	// assumes i >= j, next i := i - j
				else if (m != MN::id)	return m;		// implies next i > 0
				else if (i > j)		return c[BI::name];
				else 			return c[BI::coname];
			}

			static constexpr key_type next_note(instr_type c, depth_type d, key_type m, index_type i, index_type j)
			{
				if (d == 0)		return MT::identity;	// assumes i >= j, next i := i - j
				else if (m != MN::id)	return MT::between;
				else if (i > j)		return max_note(i - j);
				else			return c[BI::conote];
			}

			static constexpr depth_type next_depth(depth_type d)
			{
				if (d == 0)		return d;
				else 			return d-1;
			}

			static constexpr index_type next_index1(instr_type c, depth_type d, key_type m, index_type i, index_type j)
			{
				if (d == 0)		return i;
				else if (m != MN::id)	return i;
				else 			return i - j;
			}

			static constexpr index_type next_index2(instr_type c, depth_type d, key_type m, index_type i, index_type j)
			{
				if (d == 0)		return j;
				else if (m != MN::id)	return j;
				else			return max_index2(i - j);
			}

		// programs:

			template<auto call_ins>
			static constexpr instr_type make = block_program
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
		// interoperators:

			static constexpr key_type save					=  1;
			static constexpr key_type make					=  2;
			static constexpr key_type call					=  3;
			static constexpr key_type restore				=  4;

			static constexpr key_type instr_goto				=  5;
			static constexpr key_type regstr_goto				=  6;

		// mutators:

			static constexpr key_type erase					=  7;
			static constexpr key_type insert				=  8;
			static constexpr key_type replace				=  9;

			static constexpr key_type instr_assign				= 10;

			static constexpr key_type test					= 11;
			static constexpr key_type check					= 12;

			static constexpr key_type apply					= 13;
			static constexpr key_type compel				= 14;
	};

	using LN = LinearName;

/***********************************************************************************************************************/

// instructions:

	struct LinearInstr : public MachineInstr
	{
		// none.
	};

	using LI							= LinearInstr;

	struct LinearCallInstr : public CallInstr
	{
		static constexpr index_type offset			= 6;
	};

	using LCI							= LinearCallInstr;

/***********************************************************************************************************************/

	template<key_type...>
	struct linear_program
	{
		// defaults:

			static constexpr depth_type depth		= 500;

			static constexpr index_type initial_i		= _one;
			static constexpr index_type initial_j		= _zero;

		// accessors:

			static constexpr auto instr(label_type l, index_type, index_type j)
				{ return l[j]; }

		// navigators:

			static constexpr key_type next_name(label_type l, depth_type d, key_type m, index_type, index_type j)
			{
				if (d == 0)		return MN::pause;
				else if (m != MN::id)	return m;
				else 			return l[j+1][MI::name];
			}

			static constexpr key_type next_note(label_type l, depth_type d, key_type m, index_type, index_type j)
			{
				if (d == 0)		return MT::identity;
				else if (m != MN::id)	return MT::between;
				else			return l[j+1][MI::note];
			}

			static constexpr depth_type next_depth(depth_type d)
			{
				if (d == 0)		return d;
				else 			return d-1;
			}

			static constexpr index_type next_index1(label_type, depth_type, key_type, index_type i, index_type)
			{
				return i;
			}

			static constexpr index_type next_index2(label_type, depth_type d, key_type m, index_type, index_type j)
			{
				if (d == 0)		return j;
				else if (m != MN::id)	return j;
				else 			return j+1;
			}

		// programs:

			template<auto call_ins, auto... Vs>
			static constexpr label_type make = linear_program
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

	using UI							= LinearInstr;

	struct UserCallInstr : public CallInstr
	{
		static constexpr index_type pos				= 6;
		static constexpr index_type prog			= 7;

		static constexpr index_type offset			= 8;
	};

	using UCI							= UserCallInstr;

/***********************************************************************************************************************/

	template<key_type...>
	struct user_program
	{
		// defaults:

			static constexpr depth_type depth		= 500;

			static constexpr index_type initial_i		= _one;
			static constexpr index_type initial_j		= _zero;

		// instructions:

		//	static constexpr index_type linear_name		= 3;
		//	static constexpr index_type linear_note		= 4;
		//	static constexpr index_type linear_index	= 4;

		// accessors:

			static constexpr auto instr(contr_type c, index_type i, index_type j)
				{ return c[i][j]; }

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

			static constexpr key_type next_name(contr_type c, depth_type d, key_type m, index_type i, index_type j)
			{
				if (d == 0)		return MN::pause;
				else if (m != MN::id)	return m;
				else
				{
					index_type ni = next_index1(c, d, m, i, j);
					index_type nj = next_index2(c, d, m, i, j);

					return c[ni][nj][MI::name];
				}
			}

			static constexpr key_type next_note(contr_type c, depth_type d, key_type m, index_type i, index_type j)
			{
				if (d == 0)		return MT::identity;
				else if (m != MN::id)	return MT::between;
				else
				{
					index_type ni = next_index1(c, d, m, i, j);
					index_type nj = next_index2(c, d, m, i, j);

					return c[ni][nj][MI::note];
				}
			}

			static constexpr depth_type next_depth(depth_type d)
			{
				if (d == 0)		return d;
				else 			return d-1;
			}

			static constexpr index_type next_index1(contr_type c, depth_type d, key_type m, index_type i, index_type j)
			{
				if (d == 0)		return i;
				else if (m != MN::id)	return i;
				else
				{
					index_type ni = initial_next_index1(c, i, j);
				//	index_type nj = initial_next_index2(c, i, j);
				//	key_type note = c[ni][nj][MI::note];

				//	if (note == MT::linear)
				//	{
				//		key_type l_name = c[ni][nj][linear_name];

				//		if (l_name == LN::instr_goto) return c[ni][nj][linear_index];
				//	}
				//	else
					return ni;
				}
			}

			static constexpr index_type next_index2(contr_type c, depth_type d, key_type m, index_type i, index_type j)
			{
				if (d == 0)		return j;
				else if (m != MN::id)	return j;
				else
				{
				//	index_type ni = initial_next_index1(c, i, j);
					index_type nj = initial_next_index2(c, i, j);
				//	key_type note = c[ni][nj][MI::note];

				//	if (note == MT::linear)
				//	{
				//		key_type l_name = c[ni][nj][linear_name];

				//		if (l_name == LN::instr_goto) return _one;
				//	}
				//	else
					return nj;
				}
			}
	};

	using T_user_program			= user_program<>;
	static constexpr auto U_user_program	= U_type_T<user_program<>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

