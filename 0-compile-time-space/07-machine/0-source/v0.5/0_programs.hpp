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
			static constexpr key_type id					=  0;
			static constexpr key_type identity				= id; // convenience for
											      // default params.

		// halters:

			static constexpr key_type value					=  1;

		// interoperators:

			static constexpr key_type call					=  2;
			static constexpr key_type detour				=  3;
			static constexpr key_type machinate				=  4;

		// passers:

			// block:

			static constexpr key_type index_block				=  5;

			static constexpr key_type move_r_block				=  6;
			static constexpr key_type fold_r_block				=  7;

			static constexpr key_type move_a_block				=  8;
			static constexpr key_type catenate_a_block			=  9;
			static constexpr key_type map_a_block				= 10;
			static constexpr key_type zip_a_block				= 11;

			// (near) linear:

			static constexpr key_type copy_r_pos				= 12; // opt
			static constexpr key_type copy_a_pos				= 13; // opt
			static constexpr key_type copy_h4_pos				= 14; // opt

			static constexpr key_type move_r_all				= 15;
			static constexpr key_type move_h0_all				= 16;
			static constexpr key_type move_h1_all				= 17;

			static constexpr key_type move_a0_all				= 18;

			static constexpr key_type save					= 19;
			static constexpr key_type restore				= 20;

			// recursive:

			static constexpr key_type go_to					= 21;
			static constexpr key_type call_h0_all				= 22;
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

			static constexpr key_type optimal				=  9; // opt
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

		static constexpr index_type length     (type i)			{ return i[size]; }
		static constexpr bool       is_optimal (cindex_type n)		{ return (n < _eight); }
	};

	using MI								= MachineInstr;
	using instr_type							= typename MI::type;

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

	template<label_type... Vs>
	static constexpr contr_type controller = array
		<label_type, array<instr_type, array<index_type, sizeof...(Vs)>>, Vs...>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// programs:

	template<key_type, key_type...> struct program;

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
		static constexpr key_type index_segment				=  1;
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

			static constexpr auto instr(ctr_type c, cindex_type, cindex_type)
				{ return c; }

			static constexpr index_type max_note(cindex_type n)
			{
				return	(n >= _2_3) ? 3 :
					(n >= _2_2) ? 2 :
					(n >= _2_1) ? 1 : 0 ;
			}

			static constexpr index_type max_index2(cindex_type n)
			{
				return	(n >= _2_3) ? _2_3 :
					(n >= _2_2) ? _2_2 :
					(n >= _2_1) ? _2_1 :
					(n >= _2_0) ? _2_0 : 0 ;
			}

		// navigators:

			static constexpr key_type next_name(ctr_type c, cindex_type i, cindex_type j)
			{
				if (i > j)		return c[BI::name];	// assumes i >= j, next i := i - j
				else 			return c[BI::coname];	// implies next i > 0
			}

			static constexpr key_type next_note(ctr_type c, cindex_type i, cindex_type j)
			{
				if (i > j)		return max_note(i - j);	// assumes i >= j, next i := i - j
				else			return c[BI::conote];
			}

			static constexpr index_type next_index1(ctr_type c, cindex_type i, cindex_type j)
			{
				return i - j;
			}

			static constexpr index_type next_index2(ctr_type c, cindex_type i, cindex_type j)
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
			static constexpr key_type id				=  0;
			static constexpr key_type identity			= id; // convenience for
										      // default params.
		// user:

			static constexpr key_type test				=  1;
			static constexpr key_type apply				=  2;
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

			static constexpr auto instr(ctr_type c, cindex_type, cindex_type j)
				{ return c[j]; }

		// navigators:

			static constexpr key_type next_name(ctr_type c, cindex_type, cindex_type j)
			{
				return c[j+1][MI::name];
			}

			static constexpr key_type next_note(ctr_type c, cindex_type, cindex_type j)
			{
				return c[j+1][MI::note];
			}

			static constexpr index_type next_index1(ctr_type, cindex_type i, cindex_type)
			{
				return i;
			}

			static constexpr index_type next_index2(ctr_type, cindex_type, cindex_type j)
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

			static constexpr auto instr(ctr_type c, cindex_type i, cindex_type j)
				{ return c[i][j]; }

		// navigators:

			static constexpr key_type next_name(ctr_type c, cindex_type i, cindex_type j)
			{
				const index_type ni = next_index1(c, i, j);
				const index_type nj = next_index2(c, i, j);

				return c[ni][nj][MI::name];
			}

			static constexpr key_type next_note(ctr_type c, cindex_type i, cindex_type j)
			{
				const index_type ni = next_index1(c, i, j);
				const index_type nj = next_index2(c, i, j);

				return c[ni][nj][MI::note];
			}

			static constexpr index_type next_index1(ctr_type c, cindex_type i, cindex_type j)
			{
				return i + bool{j == ML::length(c[i])};	// j == last : return i+1.
									// j != last : return i.
			}

			static constexpr index_type next_index2(ctr_type c, cindex_type i, cindex_type j)
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
	static constexpr key_type next_name(cdepth_type d, ckey_type m, typename tn::ctr_type c, cindex_type i, cindex_type j)
	{
		if (d == 0)		return MN::machinate;
		else if (m != MT::id)	return MN::detour;
		else			return tn::next_name(c, i, j);
	}

	template<typename tn>
	static constexpr key_type next_note(cdepth_type d, ckey_type m, typename tn::ctr_type c, cindex_type i, cindex_type j)
	{
		if (d == 0)		return MT::pause;
		else if (m != MT::id)	return m;
		else			return tn::next_note(c, i, j);
	}

	template<typename tn>
	static constexpr index_type next_index1(cdepth_type d, ckey_type m, typename tn::ctr_type c, cindex_type i, cindex_type j)
	{
		if (d == 0)		return i;
		else if (m != MT::id)	return i;
		else 			return tn::next_index1(c, i, j);
	}

	template<typename tn>
	static constexpr index_type next_index2(cdepth_type d, ckey_type m, typename tn::ctr_type c, cindex_type i, cindex_type j)
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

		static constexpr key_type pack_loc	=  8;
		static constexpr key_type pack_pos	=  9;
		static constexpr key_type pack_size	= 10;

		static constexpr key_type param_trait	= 11;

		static constexpr key_type loc_offset	= 12;
		static constexpr key_type pos_offset	= 13;
	};

	using CI = CallInstr<>;

// block:

	template<key_type... filler>
	struct CallInstr<MP::block, filler...> : public CallInstr<filler...>
	{
		static constexpr key_type pos		= 12;
		static constexpr key_type policy	= 13;

		static constexpr key_type coname	= 14;
		static constexpr key_type conote	= 15;
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
		static constexpr key_type pos		= 12;
		static constexpr key_type adj		= 13;
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
		static constexpr key_type id			=  0;
		static constexpr key_type identity		= id;	// convenience for
									// default params.

		static constexpr key_type instr			=  1;
		static constexpr key_type regs			=  2;
		static constexpr key_type h0			=  3;
		static constexpr key_type h4			=  4;
		static constexpr key_type args			=  5;
	};

	using CL = CallLocation;

/***********************************************************************************************************************/

// traits:

	struct CallTrait
	{
		static constexpr key_type id		=  0;
		static constexpr key_type identity	= id;	// convenience for
								// default params.
		static constexpr key_type closed	=  1;
		static constexpr key_type open		=  2;

		static constexpr key_type all		=  3;

		static constexpr key_type dispatch	=  4;
	};

	using CT = CallTrait;

/***********************************************************************************************************************/

// dispatch:

	struct CallDispatch
	{
		template<auto V, typename T> static constexpr bool is_value  (T v) { return (v == V); }
		template<auto V, typename T> static constexpr bool not_value (T v) { return (v != V); }

		template<typename T, typename... Ts>
		static constexpr bool all_equal(T v, Ts... vs) { return (... && (v == vs)); }

		// locations:

			template<auto test, ckey_type trait, bool safe_return>
			static constexpr bool all_param_locs_test(cindex_type size, cindex_type *params)
			{
				if (size == 0) return safe_return;
				else
				{
					if constexpr (trait == CT::all) return test(*params);
					else
					{
						const index_type *end	= params + (size << 1);
						bool result		= true;

						for (cindex_type *k = params; result && k < end; k += 2)
							result = test(*k);

						return result;
					}
				}
			}

		// id:

			template<ckey_type trait>
			static constexpr bool assert_no_param_locs_equal_id(cindex_type size, cindex_type *params)
			{
				return all_param_locs_test<not_value<CL::id>, trait, true>(size, params);
			}

		// h0:

			static constexpr bool all_nonparam_locs_equal_h0(ckey_type cloc, ckey_type nloc, ckey_type ploc)
			{
				return all_equal(CL::h0, cloc, nloc, ploc);
			}

			template<ckey_type trait>
			static constexpr bool all_param_locs_equal_h0(cindex_type size, cindex_type *params)
			{
				return all_param_locs_test<is_value<CL::h0>, trait, true>(size, params);
			}

		// optimal:

			// caller, name:

			static constexpr bool is_generic_optimal(ckey_type loc, cindex_type pos)
			{
				return (loc == CL::instr) || MI::is_optimal(pos);
			}

			// pack:

			static constexpr bool is_pack_optimal(ckey_type loc, cindex_type pos, cindex_type size)
			{
				if (loc == CL::id) return MI::is_optimal(size);
				else               return MI::is_optimal(pos);
			}

			static constexpr index_type pack_size(ckey_type trait, cindex_type param_size)
			{
				if      (param_size == 0)  return 0;
				else if (trait == CT::all) return param_size - 1;
				else                       return param_size >> 1;
			}

			// params:

			static constexpr bool is_all_params_optimal(cindex_type size, cindex_type *params)
			{
				if (*params == CL::instr) return true;
				else
				{
					bool result = true;

					for (cindex_type *k = params + 1; result && k < params + size; ++k)
						result = MI::is_optimal(*k);

					return result;
				}
			}

			static constexpr bool is_id_params_optimal(cindex_type size, cindex_type *params)
			{
				const index_type *end	= params + (size << 1);
				bool result		= true;

				for (cindex_type *j = params, *k = j+1; result && j < end; j += 2, k += 2)
					result = (*j == CL::instr) || MI::is_optimal(*k);

				return result;
			}

			template<ckey_type trait>
			static constexpr bool is_params_optimal(cindex_type size, cindex_type *params)
			{
				if (!MI::is_optimal(size)) return false;
				else if (size == 0) return true;
				else
				{
					if constexpr (trait == CT::all) return is_all_params_optimal(size, params);
					else                            return is_id_params_optimal(size, params);
				}
			}
	};

	using CD = CallDispatch;

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

		//

		template<auto V, auto... Vs>
		static constexpr auto append(nik_avpcr(auto_pack<Vs...>*))
			{ return U_opt_pack_Vs<Vs..., V>; }

		template<auto... Vs, auto... Ws>
		static constexpr auto catenate(nik_avpcr(auto_pack<Vs...>*), nik_avpcr(auto_pack<Ws...>*))
			{ return U_opt_pack_Vs<Vs..., Ws...>; }

		//

		template<auto pos, auto... Vs>
		static constexpr auto at(nik_avpcr(auto_pack<Vs...>*))
			{ return Fast<pos>::template at<Vs...>; }

		template<auto value, auto... Is>
		static constexpr auto to_constant(nik_avpcr(auto_pack<Is...>*))
			{ return U_opt_pack_Vs<((Is-Is)+value)...>; }

		template<auto arr, auto offset, auto... Is>
		static constexpr auto map_array(nik_avpcr(auto_pack<Is...>*))
			{ return U_opt_pack_Vs<arr[offset+Is]...>; }

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
		static constexpr auto h2(nik_avpcr(T_specific*), nik_avpcr(auto_pack<pos, Is...>*))
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
		static constexpr auto h2(nik_avpcr(T_specific*), nik_avpcr(auto_pack<Is...>*))
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
		static constexpr auto h2(nik_avpcr(T_specific*), nik_avpcr(auto_pack<Is...>*))
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
		template<instr_type ins>
		static constexpr auto U_program = U_type_T<program<ins[CI::caller_pos], ins[CI::name_pos]>>;
	};

	using RG = Resolve<MP::generic>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

