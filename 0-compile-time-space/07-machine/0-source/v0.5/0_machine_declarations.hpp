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

// machine declarations source:

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

	// constexpr monad (design):

//		template<>
//		struct machine<MN::(((name))), (((note)))>
//		{
//			template
//			<
//				// stack:

//					typename n, auto c, auto d, auto i, auto j, auto... Vs,

//				// heaps:

//					typename... Heaps
//			>
//			static constexpr auto result(Heaps... Hs)
//			{
//				return machine
//				<
//					n::next_name(c, d, i, j),
//					n::next_note(c, d, i, j)

//				>::template result
//				<
//					n, c,

//					n::next_depth(d),
//					n::next_index1(c, d, i, j),
//					n::next_index2(c, d, i, j),

//					Vs...	// The behaviour of each
//						// machine is such that it
//				>(Hs...);	// mutates these packs.
//			}
//		};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machine:

private:

	template<key_type, key_type, key_type...> struct machine;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// aliases:

	template<auto... Vs>				// optimized because we know auto_pack<Vs...>
	static constexpr auto U_opt_pack_Vs =		// is not void nor a reference.
		nik_module(interpret, functor, architect, v_0_5, gcc)::template type_map<auto_pack<Vs...>*>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// machine:

	using MN				= typename controller_module::MN;
	using CallNote				= typename controller_module::CallNote;

/***********************************************************************************************************************/

	using MI				= typename controller_module::MI;
	using CallInstr				= typename controller_module::CallInstr;
	using instr_type			= typename controller_module::instr_type;

	template<index_type... Vs>
	static constexpr auto instruction	= controller_module::template instruction<Vs...>;

/***********************************************************************************************************************/

	using ML				= typename controller_module::ML;
	using label_type			= typename controller_module::label_type;

/***********************************************************************************************************************/

	using MC				= typename controller_module::MC;
	using contr_type			= typename controller_module::contr_type;

	template<key_type N>
	using block_controller			= typename controller_module::template block_controller<N>;

/***********************************************************************************************************************/

	using MD				= typename controller_module::MD;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// trampolining:

/***********************************************************************************************************************/

// pair:

	template<typename StackCache, typename HeapCache>
	struct trampoline_pair
	{
		StackCache sc;
		HeapCache hc;

		constexpr trampoline_pair(const StackCache & _sc, const HeapCache & _hc) : sc(_sc), hc(_hc) { }
	};

	template<typename T>
	static constexpr bool is_trampoline_pair(T) { return false; }

	template<typename StackCache, typename HeapCache>
	static constexpr bool is_trampoline_pair(trampoline_pair<StackCache, HeapCache>) { return true; }

/***********************************************************************************************************************/

// trampoline:

	template<auto d, auto un, auto c, auto i, auto j, auto... Vs, auto... Hs>
	static constexpr auto machine_trampoline(void(*)(auto_pack<un, c, i, j, Vs...>*), void(*)(auto_pack<Hs...>*))
	{
		static_assert(bool(d), "machine trampolining nesting depth exceeded.");

		using n = T_type_U<un>;

		constexpr auto result = NIK_MACHINE(n, c, d, i, j)(Hs...);

		if constexpr (is_trampoline_pair(result))	return machine_trampoline<d-1>(result.sc, result.hc);
		else						return result;
	}

/***********************************************************************************************************************/

// start:

public:

	template<NIK_CONTR_PARAMS, auto... Vs, auto... Ws, auto... Xs>
	static constexpr auto start
	(
		void(*H0)(auto_pack<Ws...>*) = U_opt_pack_Vs<>,
		void(*H1)(auto_pack<Xs...>*) = U_opt_pack_Vs<>
	)
	{
		constexpr auto result = NIK_MACHINE(n, c, d, i, j)(U_opt_pack_Vs<Ws...>, U_opt_pack_Vs<Xs...>);

		if constexpr (is_trampoline_pair(result))	return machine_trampoline<d>(result.sc, result.hc);
		else						return result;
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// block:

/***********************************************************************************************************************/

	struct BD
	{
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

	// iterators:

			// optimized to use a single instruction as the controller.

		// name:

			static constexpr key_type next_name(instr_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0)	return MN::pause;	// assumes i >= j, next i := i - j
				else if (i > j)	return c[MI::name];	// implies next i > 0
				else 		return MI::last(c);	// otherwise next i == 0
			}

		// note:

			static constexpr key_type next_note(instr_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0)	return _zero;
				else		return max_note(i - j);
			}

		// depth:

			static constexpr depth_type (*next_depth)(depth_type) = MD::default_next_depth;

		// index1:

			static constexpr index_type next_index1(instr_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0)	return i;
				else 		return i - j;
			}

		// index2:

			static constexpr index_type next_index2(instr_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0)	return j;
				else		return max_index2(i - j);
			}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// linear:

/***********************************************************************************************************************/

	struct LD
	{
	// call:

		static constexpr index_type call_name(label_type l, index_type, index_type j)
			{ return l[j][CallInstr::name]; }

		static constexpr index_type call_pos(label_type l, index_type, index_type j)
			{ return l[j][CallInstr::pos]; }

	// applications:

	//	static constexpr index_type size   (label_type l, index_type, index_type j) { return l[j][MI::size  ]; }
	//	static constexpr key_type name     (label_type l, index_type, index_type j) { return l[j][MI::name  ]; }
	//	static constexpr key_type note     (label_type l, index_type, index_type j) { return l[j][MI::note  ]; }
	//	static constexpr index_type pos    (label_type l, index_type, index_type j) { return l[j][MI::pos   ]; }

	//	static constexpr index_type obj    (label_type l, index_type, index_type j) { return l[j][MI::obj   ]; }

	//	static constexpr index_type op     (label_type l, index_type, index_type j) { return l[j][MI::op    ]; }
	//	static constexpr index_type arg    (label_type l, index_type, index_type j) { return l[j][MI::arg   ]; }
	//	static constexpr index_type arg1   (label_type l, index_type, index_type j) { return l[j][MI::arg1  ]; }
	//	static constexpr index_type arg2   (label_type l, index_type, index_type j) { return l[j][MI::arg2  ]; }

	//	static constexpr index_type pred   (label_type l, index_type, index_type j) { return l[j][MI::pred  ]; }
	//	static constexpr index_type input  (label_type l, index_type, index_type j) { return l[j][MI::input ]; }
	//	static constexpr index_type input1 (label_type l, index_type, index_type j) { return l[j][MI::input1]; }
	//	static constexpr index_type input2 (label_type l, index_type, index_type j) { return l[j][MI::input2]; }

	// iterators:

		// name:

			static constexpr key_type next_name(label_type l, depth_type d, index_type, index_type j)
			{
				if (d == 0)	return MN::pause;
				else 		return l[j+1][MI::name];
			}

		// note:

			static constexpr key_type next_note(label_type l, depth_type d, index_type, index_type j)
			{
				if (d == 0)	 return _zero;
				else		 return l[j+1][MI::note];
			}

		// depth:

			static constexpr depth_type (*next_depth)(depth_type) = MD::default_next_depth;

		// index1:

			static constexpr index_type (*next_index1)(label_type, depth_type, index_type, index_type) =
				MD::template default_next_index1<label_type>;

		// index2:

			static constexpr index_type next_index2(label_type, depth_type d, index_type, index_type j)
			{
				if (d == 0)	return j;
				else 		return j+1;
			}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// register:

/***********************************************************************************************************************/

	// Initializers require (l = 0, m = k) -> first instruction.

	// modularizing assign, save, restore, is better design, but given
	// compile time performance constraints optimization is privileged.

/*
	struct RD
	{
	// applications:

	static constexpr index_type size   (rc_type c, index_type i, index_type j) { return c[i][j][RA::size  ]; }
	static constexpr key_type name     (rc_type c, index_type i, index_type j) { return c[i][j][RA::name  ]; }
	static constexpr key_type note     (rc_type c, index_type i, index_type j) { return c[i][j][RA::note  ]; }
	static constexpr index_type pos    (rc_type c, index_type i, index_type j) { return c[i][j][RA::pos   ]; }

	static constexpr index_type obj    (rc_type c, index_type i, index_type j) { return c[i][j][RA::obj   ]; }

	static constexpr index_type op     (rc_type c, index_type i, index_type j) { return c[i][j][RA::op    ]; }
	static constexpr index_type arg    (rc_type c, index_type i, index_type j) { return c[i][j][RA::arg   ]; }
	static constexpr index_type arg1   (rc_type c, index_type i, index_type j) { return c[i][j][RA::arg1  ]; }
	static constexpr index_type arg2   (rc_type c, index_type i, index_type j) { return c[i][j][RA::arg2  ]; }

	static constexpr index_type pred   (rc_type c, index_type i, index_type j) { return c[i][j][RA::pred  ]; }
	static constexpr index_type input  (rc_type c, index_type i, index_type j) { return c[i][j][RA::input ]; }
	static constexpr index_type input1 (rc_type c, index_type i, index_type j) { return c[i][j][RA::input1]; }
	static constexpr index_type input2 (rc_type c, index_type i, index_type j) { return c[i][j][RA::input2]; }

	static constexpr index_type reg_size (rc_type c, index_type, index_type)   { return RC::reg_size(c); }

	// iterators:

		// basics:

			static constexpr index_type basic_next_index1(rc_type c, index_type i, index_type j)
			{
				return i + bool{j == RL::length(c[i])};	// j == last : return i+1.
									// j != last : return i.
			}

			static constexpr index_type basic_next_index2(rc_type c, index_type i, index_type j)
			{
				return (j == RL::length(c[i])) ? _one : j+1;	// j == last : return one.
										// j != last : return j+1.
			}

		// index1:

			static constexpr index_type next_index1(rc_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0) return i;

				index_type ni	= basic_next_index1(c, i, j);
				index_type nj	= basic_next_index2(c, i, j);
				key_type name	= c[ni][nj][RA::name];
				key_type note	= c[ni][nj][RA::note];

				if (name == MN::go_to && note == MD::contr)	return c[ni][nj][RA::pos];
				else 						return ni;
			}

		// index2:

			static constexpr index_type next_index2(rc_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0) return j;

				index_type ni	= basic_next_index1(c, i, j);
				index_type nj	= basic_next_index2(c, i, j);
				key_type name	= c[ni][nj][RA::name];
				key_type note	= c[ni][nj][RA::note];

				if (name == MN::go_to && note == MD::contr)	return _one;
				else						return nj;
			}

		// name:

			static constexpr key_type next_name(rc_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0) return MN::pause;

				index_type ni = next_index1(c, d, i, j);
				index_type nj = next_index2(c, d, i, j);

				return c[ni][nj][RA::name];
			}

		// note:

			static constexpr key_type next_note(rc_type c, depth_type d, index_type i, index_type j)
			{
				if (d == 0) return _zero;

				index_type ni = next_index1(c, d, i, j);
				index_type nj = next_index2(c, d, i, j);

				return c[ni][nj][RA::note];
			}

		// depth:

			static constexpr depth_type (*next_depth)(depth_type) =
				MD::template default_next_depth<depth_type>;
	};
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

