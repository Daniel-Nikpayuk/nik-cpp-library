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

public:

	template<typename... Ts>
	static constexpr auto U_pre_pack_Ts = U_opt_pack_Vs<U_type_T<T_pretype_T<Ts>>...>;

/***********************************************************************************************************************/

// machination:

		// Do not refactor using other templated structs. Although this definition is potentially redundant,
		// trampolining requires a distinct keyword so that there's no confusion with any other returned value.

	template<typename StackCache, typename HeapCache>
	struct machination
	{
		StackCache sc;
		HeapCache hc;

		constexpr machination(const StackCache & _sc, const HeapCache & _hc) : sc(_sc), hc(_hc) { }
	};

	//

	template<typename T>
	static constexpr bool is_machination(T) { return false; }

	template<typename StackCache, typename HeapCache>
	static constexpr bool is_machination(machination<StackCache, HeapCache>) { return true; }

/***********************************************************************************************************************/

// loadable:

		// Do not refactor using other templated structs. Although this definition is potentially redundant,
		// loadability requires a distinct keyword so that there's no confusion with any other returned value.

	template<typename StackCache, typename HeapCache>
	struct loadable
	{
		StackCache sc;
		HeapCache hc;

		constexpr loadable(const StackCache & _sc, const HeapCache & _hc) : sc(_sc), hc(_hc) { }
	};

	//

	template<typename T>
	static constexpr bool is_loadable(T) { return false; }

	template<typename MachineCache, typename StackCache, typename HeapCache>
	static constexpr bool is_loadable(loadable<StackCache, HeapCache>) { return true; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machine names:

/***********************************************************************************************************************/

	// I would prefer to implement these as enums, but I don't know how
	// to get gcc/clang to pattern match the register machine when I do.

	struct MachineName
	{
		// interposers:

			static constexpr key_type pause						=  0;
			static constexpr key_type sleep						=  1;

			static constexpr key_type branch					=  2; // <machine>
			static constexpr key_type go_to						=  3; // <machine>

			static constexpr key_type shift_r_block__insert_at_s_back		=  4; // <machine>
			static constexpr key_type load						=  5;
			static constexpr key_type restack					=  6;
			static constexpr key_type call						=  7;

		// halters:

			static constexpr key_type result					=  8;
			static constexpr key_type first						=  9;
			static constexpr key_type rest						= 10;

		// debuggers:

			static constexpr key_type depth						= 11;
			static constexpr key_type dump						= 12;

			static constexpr key_type stack						= 13;
			static constexpr key_type heaps						= 14;

		// passers:

			// stack -> stack:

			static constexpr key_type drop_s_block					= 15; // <halters>
			static constexpr key_type drop_s_pos					= 16; // opt, <mutators>

			static constexpr key_type fold_s_block__op_at_h0_first			= 17; // <near linear>
			static constexpr key_type roll_s_block__act_at_h0_first			= 18; // <near linear>

			// stack -> heap:

			static constexpr key_type move_s_block__insert_at_h0_front		= 19; // <mutators>
			static constexpr key_type move_s_block__insert_at_h1_back		= 20; // <mutators>

			static constexpr key_type copy_s_block__insert_at_h0_front		= 21; // <mutators>
			static constexpr key_type copy_s_block__insert_at_h0_back		= 22; // <mutators>
			static constexpr key_type copy_s_pos__insert_at_h0_front		= 23; // opt, <mutators>
			static constexpr key_type copy_s_pos__insert_at_h0_back			= 24; // opt, <mutators>

			// heap -> stack:

			static constexpr key_type move_h0_first__insert_at_s_front		= 25; // <mutators>
			static constexpr key_type move_h0_first__insert_at_s_pos		= 26; // opt, <mutators>
			static constexpr key_type move_h0_first__replace_at_s_pos		= 27; // opt, <mutators>

			static constexpr key_type move_h1_all__insert_at_s_front		= 28; // <mutators>
	};

	using MN = MachineName;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// routine names:

/***********************************************************************************************************************/

// names:

	struct BlockName
	{
		// halters:

			static constexpr key_type stop			= 0;

		// passers:

			// stack -> stack:

			static constexpr key_type make_r_segment__insert_at_s_back		= 1; // <machine>

			static constexpr key_type drop_s_segment				= 2; // <list>

			static constexpr key_type fold_s_segment__replace_at_s_front		= 3; // <machine>
			static constexpr key_type roll_s_segment__replace_at_s_front		= 4; // <machine>

			// stack -> heap:

			static constexpr key_type move_s_segment__insert_at_h0_front		= 5; // <mutators>
			static constexpr key_type move_s_segment__insert_at_h1_back		= 6; // <mutators>
	};

	using BN = BlockName;

/***********************************************************************************************************************/

// linear:

	struct LinearName
	{
	// (level 1)

		// passers:

			// stack -> stack:

			static constexpr index_type drop_s_pos					=  0; // <mutators>, opt
			static constexpr index_type move_s_pos__insert_at_s_back		=  1; // <near linear>, opt

			// stack -> heap:

			static constexpr index_type copy_s_pos__insert_at_h0_front		=  2; // <mutators>, opt
			static constexpr index_type copy_s_pos__insert_at_h0_back		=  3; // <mutators>, opt

			static constexpr index_type copy_s_pos__insert_at_h2_front		=  4; // <mutators>, opt

			// heap -> stack:

			static constexpr index_type move_h0_first__insert_at_s_pos		=  5; // <mutators>, opt
			static constexpr index_type move_h0_first__replace_at_s_pos		=  6; // <mutators>, opt

			static constexpr index_type move_h2_first__replace_at_s_pos		=  7; // <mutators>, opt

			static constexpr index_type apply_h0_all__move__replace_at_s_pos	=  8; // <machine>, opt

			static constexpr index_type compel_h0_all__move__replace_at_s_pos	=  9; // <machine>, opt

	// (level 2)

		// mutators:

			static constexpr index_type erase					= 10;
			static constexpr index_type insert					= 11;
			static constexpr index_type replace					= 12;

		// control:

			static constexpr index_type go_to					= 13;
			static constexpr index_type go_to_label					= 14;

			static constexpr index_type assign_label				= 15;

			static constexpr index_type save					= 16;
			static constexpr index_type restore					= 17;

			static constexpr index_type test					= 18;
			static constexpr index_type check					= 19;

			static constexpr index_type apply					= 20;
			static constexpr index_type compel					= 21;
	};

	using LN = LinearName;

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

// instructions:

/***********************************************************************************************************************/

	struct MachineInstr
	{
		using type						= index_type const*;

		static constexpr index_type size			= 0;
		static constexpr index_type name			= 1;
		static constexpr index_type note			= 2;
		static constexpr index_type pos				= 3;

		static constexpr index_type length (type i)		{ return i[size]; }
		static constexpr index_type last   (type i)		{ return i[length(i)]; }
		static constexpr bool       is_opt (index_type n)	{ return (n < _eight); }

		// The subnote value tells us how many of the leftside parameters
		// are direct values rather than register locations.

		static constexpr index_type subname			= 3;
		static constexpr index_type subnote			= 4;
		static constexpr index_type offset			= 5;

		static constexpr index_type subsize  (type i)		{ return i[size] - subnote; }
		static constexpr index_type subright (type i)		{ return offset; }

	//	static constexpr key_type patchname(key_type m, index_type n)	{ return is_opt(n) ? m : MN::call; }
	//	static constexpr key_type patchnote(key_type m, index_type n)	{ return is_opt(n) ? CT::fast : m; }
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
		static constexpr index_type first			= 1;

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
		static constexpr index_type first			= 1;

		static constexpr index_type length   (type c)		{ return c[size][ML::size][MI::size]; }
		static constexpr label_type last     (type c)		{ return c[length(c)]; }
		static constexpr index_type reg_size (type c)		{ return ML::last(last(c))[MI::pos]; }
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
	// Their register indices coincide with their controller indices, and as such they are
	// required to accept no additional register index values when resolving their respective
	// controllers. This also means that there are no default controller indices provided here.

/***********************************************************************************************************************/

	template<key_type...>
	struct block_program
	{
		static constexpr depth_type depth	= 500;

		// loaders:

		static constexpr auto subname(label_type l, index_type, index_type j)
			{ return l[j][MI::subname]; }

		static constexpr index_type subpos(label_type l, index_type, index_type j)
			{ return l[j][MI::offset]; }

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

		// dispatchers:

		static constexpr key_type next_name(instr_type c, depth_type d, index_type i, index_type j)
		{
			if (d == 0)	return MN::pause;	// assumes i >= j, next i := i - j
			else if (i > j)	return c[MI::name];	// implies next i > 0
			else 		return MI::last(c);	// otherwise next i == 0
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

	static constexpr auto U_block_program = U_type_T<block_program<>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// (linear) programs:

	// Optimized to use a single label as the controller.

/***********************************************************************************************************************/

	template<key_type...>
	struct linear_program
	{
		static constexpr depth_type depth	= 500;

		static constexpr index_type initial_i	= _one;
		static constexpr index_type initial_j	= _zero;

		// loaders:

		static constexpr auto subname(label_type l, index_type, index_type j)
			{ return l[j][MI::subname]; }

		static constexpr index_type subpos(label_type l, index_type, index_type j)
			{ return l[j][MI::offset]; }

		static constexpr index_type subnote(label_type l, index_type, index_type j)
			{ return l[j][MI::subnote]; }

		static constexpr instr_type subinstr(label_type l, index_type, index_type j)
			{ return l[j]; }

		static constexpr index_type val(label_type l, index_type, index_type j)
			{ return l[j][MI::pos]; }

		// dispatchers:

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

	static constexpr auto U_linear_program = U_type_T<linear_program<>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// turing:

/***********************************************************************************************************************/

	template<key_type...>
	struct turing_program
	{
		static constexpr depth_type depth	= 500;

		static constexpr index_type initial_i	= _one;
		static constexpr index_type initial_j	= _zero;

		// loaders:

		static constexpr auto subname(contr_type c, index_type i, index_type j)
			{ return c[i][j][MI::subname]; }

		static constexpr index_type subpos(contr_type c, index_type i, index_type j)
			{ return c[i][j][MI::offset]; }

		static constexpr index_type subnote(contr_type c, index_type i, index_type j)
			{ return c[i][j][MI::subnote]; }

		static constexpr instr_type subinstr(contr_type c, index_type i, index_type j)
			{ return c[i][j]; }

		static constexpr index_type val(contr_type c, index_type i, index_type j)
			{ return c[i][j][MI::pos]; }

		// basic indices:

		static constexpr index_type basic_next_index1(contr_type c, index_type i, index_type j)
		{
			return i + bool{j == ML::length(c[i])};	// j == last : return i+1.
								// j != last : return i.
		}

		static constexpr index_type basic_next_index2(contr_type c, index_type i, index_type j)
		{
			return (j == ML::length(c[i])) ? _one : j+1;	// j == last : return one.
									// j != last : return j+1.
		}

		// dispatchers:

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

			index_type ni = basic_next_index1(c, i, j);
			index_type nj = basic_next_index2(c, i, j);
			key_type note = c[ni][nj][MI::note];

			if (note == MT::linear)
			{
				key_type subname = c[ni][nj][MI::subname];

				if (subname == LN::go_to_label) return c[ni][nj][MI::offset];
			}

			return ni;
		}

		static constexpr index_type next_index2(contr_type c, depth_type d, index_type i, index_type j)
		{
			if (d == 0) return j;

			index_type ni = basic_next_index1(c, i, j);
			index_type nj = basic_next_index2(c, i, j);
			key_type note = c[ni][nj][MI::note];

			if (note == MT::linear)
			{
				key_type subname = c[ni][nj][MI::subname];

				if (subname == LN::go_to_label) return _one;
			}

			return nj;
		}
	};

	static constexpr auto U_turing_program = U_type_T<turing_program<>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

