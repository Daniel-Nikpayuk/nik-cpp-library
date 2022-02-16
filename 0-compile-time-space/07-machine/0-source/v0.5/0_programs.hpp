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

// programs source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// interposition:

/***********************************************************************************************************************/

	template<typename... Ts>
	static constexpr auto U_prepack_Ts = U_opt_pack_Vs<U_pretype_T<Ts>...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machine:

public:

/***********************************************************************************************************************/

// names:

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

			static constexpr key_type unpack_i_block				=  5;

			static constexpr key_type move_r_block					=  6;
			static constexpr key_type fold_r_block					=  7;

			static constexpr key_type move_a_block					=  8;
			static constexpr key_type catenate_a_block				=  9;
			static constexpr key_type map_a_block					= 10;
			static constexpr key_type zip_a_block					= 11;

			// (near) linear:

			static constexpr key_type copy_r_pos					= 12; // opt
			static constexpr key_type copy_a_pos					= 13; // opt
			static constexpr key_type copy_h4_pos					= 14; // opt

			static constexpr key_type move_r_all					= 15;
			static constexpr key_type move_h0_all					= 16;
			static constexpr key_type move_h1_all					= 17;

			static constexpr key_type move_a0_all					= 18;

			static constexpr key_type save						= 19;
			static constexpr key_type restore					= 20;

			// recursive:

			static constexpr key_type go_to						= 21;
			static constexpr key_type call_h0_all					= 22;
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

			static constexpr key_type h0					=  2;
			static constexpr key_type h1					=  3;

			static constexpr key_type a0					=  4;

			static constexpr key_type registers				=  5;
			static constexpr key_type arguments				=  6;

			static constexpr key_type depth					=  7;
			static constexpr key_type dump					=  8;

		// interoperators:

			// call:

			static constexpr key_type fast					=  9; // opt
			static constexpr key_type retrieve				= 10;
			static constexpr key_type fetch					= 11;

			// detour:

			static constexpr key_type internal				= 12;
			static constexpr key_type load					= 13;

			// machinate:

			static constexpr key_type pause					= 14;
			static constexpr key_type unwind				= 15;
			static constexpr key_type rewind				= 16;

		// passers:

			static constexpr key_type insert_at_r_front			= 17;

			static constexpr key_type insert_at_h0_back			= 18;
			static constexpr key_type insert_at_h1_back			= 19;
			static constexpr key_type insert_at_h2_back			= 20;

			static constexpr key_type append_at_h0_back			= 21;

			static constexpr key_type replace_at_h0				= 22;

			// near linear:

			static constexpr key_type insert_at_a_front			= 23;

			static constexpr key_type insert_at_a0_back			= 24;
			static constexpr key_type append_at_a0_back			= 25;

			static constexpr key_type replace_at_a0				= 26;

			// recursive:

			static constexpr key_type conditional				= 27;
	};

	using MT = MachineNote;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// instructions:

/***********************************************************************************************************************/

	struct MachineInstr
	{
		using type							= index_type const * const;

		static constexpr key_type size					= 0;
		static constexpr key_type name					= 1;
		static constexpr key_type note					= 2;

		static constexpr index_type length  (type i)			{ return i[size]; }
		static constexpr bool       is_opt  (index_type n)		{ return (n < _eight); }
	};

	using MI								= MachineInstr;
	using instr_type							= typename MI::type;

		// pack length is stored as the initial value.

	template<index_type... Vs>
	static constexpr instr_type instruction = array<index_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// labels:

/***********************************************************************************************************************/

	struct MachineLabel
	{
		using type							= instr_type const * const;

		static constexpr key_type size					= 0;

		static constexpr index_type length (type l)			{ return l[size][MI::size]; }
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
		using type							= label_type const * const;

		static constexpr key_type size					= 0;

		static constexpr index_type length (type c)			{ return c[size][ML::size][MI::size]; }
	};

	using MC								= MachineContr;
	using contr_type							= typename MC::type;

		// pack length is stored as the initial value.

	template<label_type... Vs>
	static constexpr contr_type controller = array
		<label_type, array<instr_type, array<index_type, sizeof...(Vs)>>, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// programs:

/***********************************************************************************************************************/

// bases:

	struct MachineProgram
	{
		static constexpr key_type id					=  0;
		static constexpr key_type identity				= id;	// convenience for
											// default params.

		static constexpr key_type block					=  1;
		static constexpr key_type linear				=  2;
		static constexpr key_type recursive				=  3;

		static constexpr key_type generic				=  4;
	};

	using MP = MachineProgram;

	template<key_type, key_type...> struct program;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block:

/***********************************************************************************************************************/

// names:

	struct BlockName
	{
		static constexpr key_type id					=  0;
		static constexpr key_type identity				= id; // convenience for
										      // default params.
		static constexpr key_type unpack_i_right			=  1;
		static constexpr key_type move_r_segment			=  2;
		static constexpr key_type move_a_segment			=  3;
	};

	using BN = BlockName;

/***********************************************************************************************************************/

// instructions:

	struct BlockInstr : public MachineInstr
	{
		static constexpr key_type policy				=  2;

		static constexpr key_type coname				=  3;
		static constexpr key_type conote				=  4;
	};

	using BI = BlockInstr;

/***********************************************************************************************************************/

// programs:

	template<key_type... filler>
	struct program<MP::block, filler...>
	{
			static constexpr key_type base			= MP::block;
			using ctr_type					= instr_type;

		// defaults:

			static constexpr depth_type depth		= 500;

		// accessors:

			static constexpr auto instr(ctr_type c, index_type, index_type)
				{ return c; }

			static constexpr index_type max_note(index_type n)
			{
				return	(n >= _2_3) ? 3 :
					(n >= _2_2) ? 2 :
					(n >= _2_1) ? 1 : 0 ;
			}

			static constexpr index_type max_index2(index_type n)
			{
				return	(n >= _2_3) ? _2_3 :
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
	};

	template<key_type... Is>
	using block_program				= program<MP::block, Is...>;

	using T_block_program				= block_program<>;
	static constexpr auto U_block_program		= U_type_T<T_block_program>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear:

/***********************************************************************************************************************/

// names:

	struct LinearName
	{
			static constexpr key_type id					=  0;
			static constexpr key_type identity				= id; // convenience for
											      // default params.
		// user:

			static constexpr key_type test					=  1;
			static constexpr key_type apply					=  2;
	};

	using LN = LinearName;

/***********************************************************************************************************************/

// instructions:

	struct LinearInstr : public MachineInstr
	{
		// none.
	};

	using LI = LinearInstr;

/***********************************************************************************************************************/

// programs:

	template<key_type... filler>
	struct program<MP::linear, filler...>
	{
			static constexpr key_type base			= MP::linear;
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
	};

	template<key_type... Is>
	using linear_program				= program<MP::linear, Is...>;

	using T_linear_program				= linear_program<>;
	static constexpr auto U_linear_program		= U_type_T<T_linear_program>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// recursive:

/***********************************************************************************************************************/

// instructions:

	struct RecursiveInstr : public MachineInstr
	{
		// none.
	};

	using RI = RecursiveInstr;

/***********************************************************************************************************************/

// programs:

	template<key_type... filler>
	struct program<MP::recursive, filler...>
	{
			static constexpr key_type base			= MP::recursive;
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

	template<key_type... Is>
	using recursive_program				= program<MP::recursive, Is...>;

	using T_recursive_program			= recursive_program<>;
	static constexpr auto U_recursive_program	= U_type_T<T_recursive_program>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// (meta) navigators:

private:

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

// call (function, program):

/***********************************************************************************************************************/

// instructions:

	template<key_type...>
	struct CallInstr : public MachineInstr
	{
		static constexpr key_type policy	=  3;

		static constexpr key_type caller_loc	=  4;
		static constexpr key_type caller_pos	=  5;

		static constexpr key_type name_loc	=  6;
		static constexpr key_type name_pos	=  7;

		static constexpr key_type param_loc	=  8;
		static constexpr key_type param_pos	=  9;

		static constexpr key_type loc_offset	= param_loc;
		static constexpr key_type pos_offset	= param_pos;
	};

	using CI = CallInstr<>;

// block:

	template<key_type... filler>
	struct CallInstr<MP::block, filler...> : public CallInstr<filler...>
	{
		static constexpr key_type pos		=  9;
		static constexpr key_type policy	= 10;

		static constexpr key_type coname	= 11;
		static constexpr key_type conote	= 12;
	};

	using BCI = CallInstr<MP::block>;

// linear:

	template<key_type... filler>
	struct CallInstr<MP::linear, filler...> : public CallInstr<filler...> { };

	using LCI = CallInstr<MP::linear>;

// recursive:

	template<key_type... filler>
	struct CallInstr<MP::recursive, filler...> : public CallInstr<filler...>
	{
		static constexpr key_type pos		=  9;
		static constexpr key_type adj		= 10;
	};

	using RCI = CallInstr<MP::recursive>;

/***********************************************************************************************************************/

// policies:

	struct CallPolicy
	{
		static constexpr key_type id					=  0;
		static constexpr key_type identity				= id;	// convenience for
											// default params.

		static constexpr key_type drop					=  1;
		static constexpr key_type op_at_h0_front			=  2;
		static constexpr key_type al_at_h0_front			=  3;

		static constexpr key_type insert_at_r_front			=  4;

		static constexpr key_type insert_at_h0_front			=  5;
		static constexpr key_type insert_at_h0_back			=  6;
		static constexpr key_type replace_at_h0				=  7;

		static constexpr key_type insert_at_h1_back			=  8;
		static constexpr key_type replace_at_h1				=  9;

		static constexpr key_type load					= 10;
	};

	using CP = CallPolicy;

/***********************************************************************************************************************/

// locations:

	struct CallLocation
	{
		static constexpr key_type id		=  0;
		static constexpr key_type identity	= id;	// convenience for
								// default params.

		static constexpr key_type closed	=  1;
		static constexpr key_type open		=  2;

		static constexpr key_type h0		=  3;
		static constexpr key_type instr		=  4;
		static constexpr key_type regs		=  5;
		static constexpr key_type args		=  6;
		static constexpr key_type h4		=  7;

		static constexpr key_type all_h0	=  8;
		static constexpr key_type all_instr	=  9;
		static constexpr key_type all_regs	= 10;
		static constexpr key_type all_args	= 11;
		static constexpr key_type all_h4	= 12;

		static constexpr key_type cnote(key_type cloc, key_type ploc)
		{
			const bool is_h0_all = (cloc == h0) && (ploc == all_h0);

			return is_h0_all ? MT::id : MT::fetch;
		}

		static constexpr key_type onote(key_type cloc, key_type nloc, key_type ploc, index_type psize)
		{
			const bool is_h0_all    = (cloc == h0)    && (nloc == h0)    && (ploc == all_h0);
			const bool is_instr_all = (cloc == instr) && (nloc == instr) && (ploc == all_instr);
			const bool is_param_opt	= MI::is_opt(psize);

			if      (is_h0_all)                    return MT::id;
			else if (is_instr_all && is_param_opt) return MT::fast;
			else                                   return MT::fetch;
		}

		static constexpr key_type shape(instr_type ins) { return (ins[CI::name_loc] == id) ? closed : open; }
	};

	using CL = CallLocation;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// fast (optimization):

	template<index_type, index_type...> struct Fast;

/***********************************************************************************************************************/

// (2^N):

	NIK_DEFINE__FAST_STRUCT(1, 0);
	NIK_DEFINE__FAST_STRUCT(2, 1);
	NIK_DEFINE__FAST_STRUCT(3, 2);
	NIK_DEFINE__FAST_STRUCT(4, 3);
	NIK_DEFINE__FAST_STRUCT(5, 4);
	NIK_DEFINE__FAST_STRUCT(6, 5);
	NIK_DEFINE__FAST_STRUCT(7, 6);
	NIK_DEFINE__FAST_STRUCT(8, 7);

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pack:

/***********************************************************************************************************************/

// names:

	template<key_type...>
	struct Pack
	{
		static constexpr key_type id			= 0;

		static constexpr key_type generic_append	= 1;
		static constexpr key_type generic_catenate	= 2;

		// append:

			template<auto V, auto... Vs>
			static constexpr auto append(void(*)(auto_pack<Vs...>*))
				{ return U_opt_pack_Vs<Vs..., V>; }

		// catenate:

			template<auto... Vs, auto... Ws>
			static constexpr auto catenate(void(*)(auto_pack<Vs...>*), void(*)(auto_pack<Ws...>*))
				{ return U_opt_pack_Vs<Vs..., Ws...>; }

		// map array:

			template<auto arr, auto offset, auto... Is>
			static constexpr auto map_array(void(*)(auto_pack<Is...>*))
				{ return U_opt_pack_Vs<arr[offset+Is]...>; }

		// translate:

			static constexpr key_type translate(key_type n)
			{
				if      (n == MT::insert_at_h0_back) return generic_append;
				else if (n == MT::insert_at_h1_back) return generic_append;
				else                                 return generic_catenate; // MT::append_at_h0_back
			}
	};

	using PE = Pack<>;

	// append:

		template<key_type... filler>
		struct Pack<PE::generic_append, filler...> : public PE
			{ template<auto U, auto V> static constexpr auto result = append<V>(U); };

		using PackAppend = Pack<PE::generic_append>;

	// catenate:

		template<key_type... filler>
		struct Pack<PE::generic_catenate, filler...> : public PE
			{ template<auto U1, auto U2> static constexpr auto result = catenate(U1, U2); };

		using PackCatenate = Pack<PE::generic_catenate>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// resolve:

	template<key_type...> struct Resolve;

/***********************************************************************************************************************/

// block:

	template<key_type... filler>
	struct Resolve<MP::block, filler...>
	{
		template<auto c, auto pos, auto... Vs>
		static constexpr auto U_resolve_prog_h2()
		{
			constexpr auto m = MT::id;
			constexpr auto n = U_block_program;
			constexpr auto j = T_block_program::max_index2(pos);
			constexpr auto i = pos + j;

			return U_opt_pack_Vs<m, n, c, i, j, Vs...>;
		}

		template<auto c, auto pos, auto... Vs>
		static constexpr auto U_prog_h2 = U_resolve_prog_h2<c, pos, Vs...>();

		template<auto... Vs, typename T_specific, auto pos, auto... Is>
		static constexpr auto h2(void(*)(T_specific*), void(*)(auto_pack<pos, Is...>*))
		{
			constexpr auto c = T_specific::template lines<Is...>;

			return U_resolve_prog_h2<c, pos, Vs...>();
		}
	};

	using RB = Resolve<MP::block>;

// linear:

	template<key_type... filler>
	struct Resolve<MP::linear, filler...>
	{
		template<auto c, auto... Vs>
		static constexpr auto U_prog_h2 = U_opt_pack_Vs
		<
			MT::id,
			U_linear_program,
			c,
			T_linear_program::initial_i,
			T_linear_program::initial_j,
			Vs...
		>;

		template<auto... Vs, typename T_specific, auto... Is>
		static constexpr auto h2(void(*)(T_specific*), void(*)(auto_pack<Is...>*))
		{
			constexpr auto c = T_specific::template lines<Is...>;

			return U_prog_h2<c, Vs...>;
		}
	};

	using RL = Resolve<MP::linear>;

// recursive:

	template<key_type... filler>
	struct Resolve<MP::recursive, filler...>
	{
		template<auto c, auto... Vs>
		static constexpr auto U_prog_h2 = U_opt_pack_Vs
		<
			MT::id,
			U_recursive_program,
			c,
			T_recursive_program::initial_i,
			T_recursive_program::initial_j,
			Vs...
		>;

		template<auto... Vs, typename T_specific, auto... Is>
		static constexpr auto h2(void(*)(T_specific*), void(*)(auto_pack<Is...>*))
		{
			constexpr auto c = T_specific::template lines<Is...>;

			return U_prog_h2<c, Vs...>;
		}
	};

	using RR = Resolve<MP::recursive>;

// generic:

	template<key_type... filler>
	struct Resolve<MP::generic, filler...>
	{
		template<instr_type ins> static constexpr index_type length		= MI::length(ins) + 1;
		template<instr_type ins> static constexpr index_type param_size		= length<ins> - CI::pos_offset;
		template<instr_type ins> static constexpr index_type half_param_size	= (param_size<ins> + 1) >> 1;

		template<instr_type ins>
		static constexpr auto fast_program = U_type_T
		<
			program
			<
				ins[CI::caller_pos],
				ins[CI::name_pos]
			>
		>;

		// fast params:

		template<instr_type ins>
		static constexpr auto let_fast_params()
		{
			constexpr auto s = param_size<ins>;
			constexpr auto r = Fast<s>::U_index_sequence;

			return PE::template map_array<ins, CI::pos_offset>(r);
		}

		template<instr_type ins>
		static constexpr auto fast_params = let_fast_params<ins>();

		// fast half params:

		template<instr_type ins, index_type offset>
		static constexpr auto let_fast_half_params()
		{
			constexpr auto s = half_param_size<ins>;
			constexpr auto r = Fast<s>::U_even_index_sequence;

			return PE::template map_array<ins, offset>(r);
		}

		template<instr_type ins> static constexpr auto fast_even_params = let_fast_half_params<ins, CI::loc_offset>();
		template<instr_type ins> static constexpr auto fast_odd_params  = let_fast_half_params<ins, CI::pos_offset>();
	};

	using RG = Resolve<MP::generic>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// make:

	template<key_type...> struct Make;

/***********************************************************************************************************************/

// closed:

	template<key_type... filler>
	struct Make<CL::closed, filler...>
	{
		template<auto ins, auto... Vs, auto prog, auto... Ws>
		static constexpr auto h2(void(*)(auto_pack<prog, Ws...>*))
		{
			constexpr auto params	= U_opt_pack_Vs<Ws...>;
			constexpr auto base	= T_type_U<prog>::base;

			return Resolve<base>::template h2<ins, Vs...>(prog, params);
		}
	};

/***********************************************************************************************************************/

// open:

	template<key_type... filler>
	struct Make<CL::open, filler...>
	{
		template<auto caller, auto name>
		static constexpr auto make(key_type) { return U_type_T<program<caller, name>>; }

		template<auto caller, auto name, template<auto...> class B>
		static constexpr auto make(void(*)(auto_template_pack<B>*)) { return U_type_T<B<name>>; }

		template<auto ins, auto... Vs, auto caller, auto name, auto... ps>
		static constexpr auto h2(void(*)(auto_pack<caller, name, ps...>*))
		{
			constexpr auto prog	= make<caller, name>(caller);
			constexpr auto params	= U_opt_pack_Vs<ps...>;
			constexpr auto base	= T_type_U<prog>::base;

			return Resolve<base>::template h2<ins, Vs...>(prog, params);
		}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

