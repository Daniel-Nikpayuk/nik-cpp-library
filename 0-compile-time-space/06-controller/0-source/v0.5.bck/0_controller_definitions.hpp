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

// controller declarations:

public:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// names:

	// I would prefer to implement these as enums, but I don't know how
	// to get gcc/clang to pattern match the register machine when I do.

	struct MN
	{
	// abstract:

		// passers:

			static constexpr index_type id						=  0;

	// block:

		// halters:

			static constexpr index_type pause					=  1;

			static constexpr index_type first					=  2;
			static constexpr index_type rest					=  3;
			static constexpr index_type pack					=  4;

		// debuggers:

			static constexpr index_type depth					=  5;
			static constexpr index_type dump					=  6;

		// interoperability:

			static constexpr index_type pass					=  7;

		// passers:

			// stack -> stack:

			static constexpr index_type drop_s_block				=  8;
			static constexpr index_type move_s_block__insert_at_s_back		=  9;

			static constexpr index_type fold_s_block__op_at_h0_first		= 10;
			static constexpr index_type roll_s_block__act_at_h0_first		= 11;

			// stack -> heap:

			static constexpr index_type move_s_block__insert_at_h0_front		= 12;
			static constexpr index_type move_s_block__insert_at_h0_back		= 13;
			static constexpr index_type move_s_block__insert_at_h1_back		= 14;

			static constexpr index_type copy_s_block__insert_at_h0_front		= 15;

	// variadic:

		// halters:

			static constexpr index_type stop					= 16;

		// passers:

			// stack -> stack:

			static constexpr index_type drop_s_segment				= 17;
			static constexpr index_type move_s_segment__insert_at_s_back		= 18;

			static constexpr index_type fold_s_segment__pos_at_h0_first		= 19;
			static constexpr index_type roll_s_segment__pos_at_h0_first		= 20;

			// stack -> heap:

			static constexpr index_type move_s_segment__insert_at_h0_back		= 21;
			static constexpr index_type move_s_segment__insert_at_h1_back		= 22;

			// heap -> stack:

			static constexpr index_type move_h0_all__insert_at_s_front		= 23;
			static constexpr index_type move_h1_all__insert_at_s_front		= 24;

			static constexpr index_type copy_h0_all__insert_at_s_front		= 25;
			static constexpr index_type copy_h1_all__insert_at_s_front		= 26;

			static constexpr index_type apply_h0_all__move__insert_at_s_front	= 27;
			static constexpr index_type apply_h0_all__replace_h0_all		= 28;

			static constexpr index_type compel_h0_all__move__insert_at_s_front	= 29;
			static constexpr index_type compel_h0_all__replace_h0_all		= 30;

	// permutatic:

		// passers:

			// stack -> stack:

			static constexpr index_type drop_s_pos					= 31;
			static constexpr index_type move_s_pos__insert_at_s_back		= 32;

			// stack -> heap:

			static constexpr index_type move_s_pos__insert_at_h0_front		= 33;
			static constexpr index_type copy_s_pos__insert_at_h0_front		= 34;

			// heap -> stack:

			static constexpr index_type move_h0_all__insert_at_s_pos		= 35;
			static constexpr index_type move_h0_all__replace_at_s_pos		= 36;

			static constexpr index_type apply_h0_all__move__replace_at_s_pos	= 37;
			static constexpr index_type compel_h0_all__move__replace_at_s_pos	= 38;

	// distributic:

		// passers:

			static constexpr index_type erase					= 39;
			static constexpr index_type insert					= 40;
			static constexpr index_type replace					= 41;

			static constexpr index_type fold					= 42;
			static constexpr index_type roll					= 43;

			static constexpr index_type apply					= 44;
			static constexpr index_type compel					= 45;

			static constexpr index_type test					= 46;
			static constexpr index_type check					= 47;

			static constexpr index_type skip					= 48;

	// near linear:

		// halters:

			static constexpr index_type halt					= 49;

		// passers:

			static constexpr index_type size_of					= 50;
			static constexpr index_type clear					= 51;
			static constexpr index_type map						= 52;
			static constexpr index_type plot					= 53;
			static constexpr index_type align					= 54;

			static constexpr index_type lift					= 55;
			static constexpr index_type stem					= 56;
			static constexpr index_type costem					= 57;
			static constexpr index_type cycle					= 58;

	// register:

		// passers:

			static constexpr index_type assign					= 59;

			static constexpr index_type branch					= 60;
			static constexpr index_type go_to__next_at_h0_front			= 61;
			static constexpr index_type go_to					= 62;

			static constexpr index_type save					= 63;
			static constexpr index_type restore					= 64;

	// reflection:

		// sizes:

			static constexpr index_type reg_size					= 65;
	};

	using machine_name = MN;

/***********************************************************************************************************************/

// applications:

	using ma_type = index_type const*;

	struct MA
	{
		// notes:

			static constexpr index_type unary	= 0;
			static constexpr index_type binary	= 1;

		// members:

			static constexpr index_type size	= 0;
			static constexpr index_type name	= 1;
			static constexpr index_type note	= 2;
			static constexpr index_type pos		= 3;

			// assignments:

			static constexpr index_type obj		= 4;

			// applications:

			static constexpr index_type op		= 4;
			static constexpr index_type arg		= 5;
			static constexpr index_type arg1	= 5;
			static constexpr index_type arg2	= 6;

			// predications:

			static constexpr index_type pred	= 3;
			static constexpr index_type input	= 4;
			static constexpr index_type input1	= 4;
			static constexpr index_type input2	= 5;

		// procedures:

			static constexpr index_type length(ma_type a) { return a[size]; }
			static constexpr index_type arity(index_type args) { return (args == 1) ? unary : binary; }
			static constexpr index_type patch(depth_type pos) { return (pos < _eight) ? pos+1 : _zero; }
	};

		// pack length is stored as the initial value.

	template<index_type... Vs>
	static constexpr ma_type m_application = array<index_type, sizeof...(Vs), Vs...>;

/***********************************************************************************************************************/

// dispatch:

	struct MD
	{
		// notes:

			static constexpr index_type contr = 0;
			static constexpr index_type regtr = 1;

		// iterators:

			template<typename d_type>
			static constexpr d_type default_next_depth(d_type d)
			{
				if (d > 0)	return d-1;
				else 		return d;
			}

			template<typename c_type, typename d_type, typename i_type, typename j_type>
			static constexpr index_type default_next_note(c_type, d_type d, i_type, j_type)
			{
				return _zero;
			}

			template<typename c_type, typename d_type, typename i_type, typename j_type>
			static constexpr j_type default_next_index2(c_type, d_type, i_type, j_type j)
			{
				return j;
			}
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// syntactic sugar:

/***********************************************************************************************************************/

	// generic:

		template<index_type Name, index_type Note, index_type... Args>
		static constexpr ma_type call = m_application
		<
			Name, Note, Args...
		>;

	// abstract:

		// id

	// block:

		// halters:

		template<index_type Note = _zero>
		static constexpr ma_type pause = m_application
		<
			MN::pause, Note
		>;

		template<index_type Note = _zero>
		static constexpr ma_type first = m_application
		<
			MN::first, Note
		>;

		template<index_type Note = _zero>
		static constexpr ma_type rest = m_application
		<
			MN::rest, Note
		>;

		template<index_type Note = _zero>
		static constexpr ma_type pack = m_application
		<
			MN::pack, Note
		>;

		// debuggers:

		template<index_type Note = _zero>
		static constexpr ma_type depth = m_application
		<
			MN::depth, Note
		>;

		template<index_type Note = _zero>
		static constexpr ma_type dump = m_application
		<
			MN::dump, Note
		>;

		template<index_type Note = _zero>
		static constexpr ma_type pass = m_application
		<
			MN::pass, Note
		>;

		// interoperability:

		// pass

		// passers:

			// stack -> stack:

		// drop_s_block
		// move_s_block__insert_at_s_back

		// fold_s_block__op_at_h0_first
		// roll_s_block__act_at_h0_first

			// stack -> heap:

		// move_s_block__insert_at_h0_front
		// move_s_block__insert_at_h0_back
		// move_s_block__insert_at_h1_back

		// copy_s_block__insert_at_h0_front

	// variadic:

		// halters:

		template<index_type Pos, index_type Note = _zero>
		static constexpr ma_type stop = m_application
		<
			MN::stop, Note, Pos
		>;

		// passers:

			// stack -> stack:

		template<index_type Pos, index_type Note = _zero>
		static constexpr ma_type drop_s_segment = m_application
		<
			MN::drop_s_segment, Note, Pos
		>;

		template<index_type Pos, index_type Note = _zero>
		static constexpr ma_type move_s_segment__insert_at_s_back = m_application
		<
			MN::move_s_segment__insert_at_s_back, Note, Pos
		>;

		// fold_s_segment__op_at_h0_first
		// roll_s_segment__act_at_h0_first

			// stack -> heap:

		template<index_type Pos, index_type Note = _zero>
		static constexpr ma_type move_s_segment__insert_at_h0_back = m_application
		<
			MN::move_s_segment__insert_at_h0_back, Note, Pos
		>;

		template<index_type Pos, index_type Note = _zero>
		static constexpr ma_type move_s_segment__insert_at_h1_back = m_application
		<
			MN::move_s_segment__insert_at_h1_back, Note, Pos
		>;

			// heap -> stack:

		template<index_type Note = _zero>
		static constexpr ma_type move_h0_all__insert_at_s_front = m_application
		<
			MN::move_h0_all__insert_at_s_front, Note
		>;

		template<index_type Note = _zero>
		static constexpr ma_type move_h1_all__insert_at_s_front = m_application
		<
			MN::move_h1_all__insert_at_s_front, Note
		>;

		// copy_h0_all__insert_at_s_front
		// copy_h1_all__insert_at_s_front

		// apply_h0_all__move__insert_at_s_front

		template<index_type Note = _zero>
		static constexpr ma_type apply_h0_all__replace_h0_all = m_application
		<
			MN::apply_h0_all__replace_h0_all, Note
		>;

		// compel_h0_all__move__insert_at_s_front

		template<index_type Note = _zero>
		static constexpr ma_type compel_h0_all__replace_h0_all = m_application
		<
			MN::compel_h0_all__replace_h0_all, Note
		>;

	// permutatic:

		// passers:

			// stack -> stack:

		template<depth_type Pos>
		static constexpr ma_type drop_s_pos = m_application
		<
			MN::drop_s_pos, MA::patch(Pos), Pos
		>;

		template<index_type Pos, index_type Note = _zero>
		static constexpr ma_type move_s_pos__insert_at_s_back = m_application
		<
			MN::move_s_pos__insert_at_s_back, Note, Pos
		>;

			// stack -> heap:

		template<depth_type Pos>
		static constexpr ma_type move_s_pos__insert_at_h0_front = m_application
		<
			MN::move_s_pos__insert_at_h0_front, MA::patch(Pos), Pos
		>;

		template<depth_type Pos>
		static constexpr ma_type copy_s_pos__insert_at_h0_front = m_application
		<
			MN::copy_s_pos__insert_at_h0_front, MA::patch(Pos), Pos
		>;

			// heap -> stack:

		template<depth_type Pos>
		static constexpr ma_type move_h0_all__insert_at_s_pos = m_application
		<
			MN::move_h0_all__insert_at_s_pos, MA::patch(Pos), Pos
		>;

		template<depth_type Pos>
		static constexpr ma_type move_h0_all__replace_at_s_pos = m_application
		<
			MN::move_h0_all__replace_at_s_pos, MA::patch(Pos), Pos
		>;

		template<depth_type Pos>
		static constexpr ma_type apply_h0_all__move__replace_at_s_pos = m_application
		<
			MN::apply_h0_all__move__replace_at_s_pos, MA::patch(Pos), Pos
		>;

		template<depth_type Pos>
		static constexpr ma_type compel_h0_all__move__replace_at_s_pos = m_application
		<
			MN::compel_h0_all__move__replace_at_s_pos, MA::patch(Pos), Pos
		>;

	// distributic:

		// passers:

		template<index_type Pos, index_type Note = _zero>
		static constexpr ma_type erase = m_application
		<
			MN::erase, Note, Pos
		>;

		template<index_type Pos, index_type Obj, index_type Note = _zero>
		static constexpr ma_type insert = m_application
		<
			MN::insert, Note, Pos, Obj
		>;

		template<index_type Pos, index_type Obj, index_type Note = _zero>
		static constexpr ma_type replace = m_application
		<
			MN::replace, Note, Pos, Obj
		>;

	//	template<index_type Pos, index_type Op, index_type Note = _zero>
	//	static constexpr ma_type fold = m_application
	//	<
	//		MN::fold, Note, Pos, Op
	//	>;

	//	template<index_type Pos, index_type Op, index_type Note = _zero>
	//	static constexpr ma_type roll = m_application
	//	<
	//		MN::roll, Note, Pos, Op
	//	>;

		template<index_type Pos, index_type Op, index_type... Args>
		static constexpr ma_type apply = m_application
		<
			MN::apply, MA::arity(sizeof...(Args)), Pos, Op, Args...
		>;

		template<index_type Pos, index_type Op, index_type... Args>
		static constexpr ma_type compel = m_application
		<
			MN::compel, MA::arity(sizeof...(Args)), Pos, Op, Args...
		>;

		template<index_type Op, index_type... Args>
		static constexpr ma_type test = m_application
		<
			MN::test, MA::arity(sizeof...(Args)), Op, Args...
		>;

		template<index_type Op, index_type... Args>
		static constexpr ma_type check = m_application
		<
			MN::check, MA::arity(sizeof...(Args)), Op, Args...
		>;

		template<index_type Note = MA::unary>
		static constexpr ma_type skip = m_application
		<
			MN::skip, Note
		>;

	// near linear:

		// passers:

		template<index_type Note = _zero>
		static constexpr ma_type size_of = m_application
		<
			MN::size_of, Note
		>;

		template<index_type Note = _zero>
		static constexpr ma_type clear = m_application
		<
			MN::clear, Note
		>;

		template<index_type Note = _zero>
		static constexpr ma_type map = m_application
		<
			MN::map, Note
		>;

		template<index_type Note = _zero>
		static constexpr ma_type plot = m_application
		<
			MN::plot, Note
		>;

		template<index_type Note = _zero>
		static constexpr ma_type align = m_application
		<
			MN::align, Note
		>;

	// register:

		// passers:

		template<index_type Pos, index_type Obj, index_type Note = _zero>
		static constexpr ma_type assign = m_application
		<
			MN::assign, Note, Pos, Obj
		>;

		template<index_type Pos, index_type Note = _zero>
		static constexpr ma_type branch = m_application
		<
			MN::branch, Note, Pos
		>;

		// go_to__next_at_h0_front

		template<index_type Pos>
		static constexpr ma_type goto_label = m_application
		<
			MN::go_to, MD::contr, Pos
		>;

		template<index_type Pos>
		static constexpr ma_type goto_using = m_application
		<
			MN::go_to, MD::regtr, Pos
		>;

		template<index_type Pos, index_type Note = _zero>
		static constexpr ma_type save = m_application
		<
			MN::save, Note, Pos
		>;

		template<index_type Pos, index_type Note = _zero>
		static constexpr ma_type restore = m_application
		<
			MN::restore, Note, Pos
		>;

		// reg_size

		template<index_type Length, index_type Note = _zero>
		static constexpr ma_type reg_size = m_application
		<
			MN::reg_size, Note, Length
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

