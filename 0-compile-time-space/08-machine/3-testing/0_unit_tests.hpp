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

// unit tests:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

	#include nik_import(../../.., interpret, functor, architect, v_0_5, gcc, dynamic, name)

	using machine_module = nik_module(interpret, machine, architect, v_0_5, gcc);

/***********************************************************************************************************************/

	template<auto n, auto d, auto... Vs>
	constexpr auto f_list_drop_s_pos(nik_avpcr(auto_pack<Vs...>*))
	{
		using LD = typename machine_module::LD;

		constexpr auto c = machine_module::template label
		<
			machine_module::template drop_s_pos<n>,
			machine_module::template pack<>
		>;

		return machine_module::template start<LD, c, d, Vs...>();
	}

	template<typename List, auto n, auto d = 500>
	constexpr auto list_drop_s_pos = f_list_drop_s_pos<n, d>(U_store_T<List>);

/***********************************************************************************************************************/

	template<auto n, auto d, auto... Vs>
	constexpr auto f_list_at(nik_avpcr(auto_pack<Vs...>*))
	{
		using LD = typename machine_module::LD;

		constexpr auto c = machine_module::template label
		<
			machine_module::template stop<n>
		>;

		return machine_module::template start<LD, c, d, Vs...>();
	}

	template<typename List, auto n, auto d = 500>
	constexpr auto list_at = f_list_at<n, d>(U_store_T<List>);

/***********************************************************************************************************************/

	template<auto n, auto d>
	constexpr auto f_index_sequence()
	{
		using LD = typename machine_module::LD;

		constexpr auto c = machine_module::template label
		<
			machine_module::template make_i_segment__insert_at_s_back<n>,
			machine_module::template pack<>
		>;

		return machine_module::template start<LD, c, d>();
	}

	template<auto n, auto d = 500>
	constexpr auto index_sequence = f_index_sequence<n, d>();

/***********************************************************************************************************************/

	template<auto n, auto d, auto... Vs>
	constexpr auto f_list_erase(nik_avpcr(auto_pack<Vs...>*))
	{
		using LD = typename machine_module::LD;

		constexpr auto c = machine_module::template label
		<
			machine_module::template erase<n>,
			machine_module::template pack<>
		>;

		return machine_module::template start<LD, c, d, Vs...>();
	}

	template<typename List, auto n, auto d = 500>
	constexpr auto list_erase = f_list_erase<n, d>(U_store_T<List>);

/***********************************************************************************************************************/

	template<auto n, auto m, auto d, auto... Vs>
	constexpr auto f_list_insert(nik_avpcr(auto_pack<Vs...>*))
	{
		using LD = typename machine_module::LD;

		constexpr auto c = machine_module::template label
		<
			machine_module::template insert<n, m>,
			machine_module::template pack<>
		>;

		return machine_module::template start<LD, c, d, Vs...>();
	}

	template<typename List, auto n, auto m, auto d = 500>
	constexpr auto list_insert = f_list_insert<n, m, d>(U_store_T<List>);

/***********************************************************************************************************************/

	template<auto n, auto m, auto d, auto... Vs>
	constexpr auto f_list_replace(nik_avpcr(auto_pack<Vs...>*))
	{
		using LD = typename machine_module::LD;

		constexpr auto c = machine_module::template label
		<
			machine_module::template replace<n, m>,
			machine_module::template pack<>
		>;

		return machine_module::template start<LD, c, d, Vs...>();
	}

	template<typename List, auto n, auto m, auto d = 500>
	constexpr auto list_replace = f_list_replace<n, m, d>(U_store_T<List>);

/***********************************************************************************************************************/

	constexpr int square(int x) { return x*x; }

	template<auto op, auto arg, auto d>
	constexpr auto f_unary_apply()
	{
		using LD = typename machine_module::LD;

		constexpr auto c = machine_module::template label
		<
			machine_module::template apply<0, 1, 2>,
			machine_module::template stop<0>
		>;

		return machine_module::template start<LD, c, d, 0, op, arg>();
	}

	template<auto op, auto arg, auto d = 500>
	constexpr auto unary_apply = f_unary_apply<op, arg, d>();

/***********************************************************************************************************************/

	constexpr int times(int x, int y) { return x*y; }

	template<auto op, auto arg1, auto arg2, auto d>
	constexpr auto f_binary_apply()
	{
		using LD = typename machine_module::LD;

		constexpr auto c = machine_module::template label
		<
			machine_module::template apply<0, 1, 2, 3>,
			machine_module::template stop<0>
		>;

		return machine_module::template start<LD, c, d, 0, op, arg1, arg2>();
	}

	template<auto op, auto arg1, auto arg2, auto d = 500>
	constexpr auto binary_apply = f_binary_apply<op, arg1, arg2, d>();

/***********************************************************************************************************************/

//	using list_5		= auto_pack<5, -12, 7, 9, 0>;
//	constexpr auto ulist_5  = U_store_T<list_5>;

//	constexpr auto ulist_4d = list_drop_s_pos<list_5, 2>;
//	constexpr auto ulist_4e = list_erase<list_5, 2>;
//	constexpr auto ulist_4i = list_insert<list_5, 2, 3>;
//	constexpr auto ulist_4r = list_replace<list_5, 2, 3>;

	//	printf("%d\n", ulist_5);
	//	printf("%d\n", ulist_4d);
	//	printf("%d\n", ulist_4e);
	//	printf("%d\n", ulist_4i);
	//	printf("%d\n", ulist_4r);

	//	printf("%d\n", index_sequence<11>);
	//	printf("%d\n", list_at<list_1000, 887>);

	//	printf("%d\n", unary_apply<square, 5>);
	//	printf("%d\n", binary_apply<times, 5, 7>);

	//

	//	printf("%llu\n", naive_factorial<utype(5)>);	// 1.20s (gcc) / 1.53s (clang)
	//	printf("%llu\n", naive_factorial<utype(20)>);	// 1.93s (gcc) / 3.12s (clang)

	//	printf("%llu\n", fast_factorial<utype(5)>);	// 1.01s (gcc) / 1.35s (clang)
	//	printf("%llu\n", fast_factorial<utype(20)>);	// 1.47s (gcc) / 2.00s (clang)

	//	printf("%llu\n", off_by_one_factorial<utype(5)>);
	
	//	printf("%llu\n", fixed_fib(utype(13)));
	//	printf("%llu\n", naive_fibonacci<utype(5)>);	// 1.43s (gcc) /  2.02s (clang)
	//	printf("%llu\n", naive_fibonacci<utype(13)>);	// 4.14s (gcc) / 11.68s (clang)
								// looped around: 1.82s (gcc) / 2.33s (clang)

/***********************************************************************************************************************/

// at:

	using index_type = unsigned short;

	struct linear_program_at : public machine_module::template linear_program<>
	{
		using label_type = typename machine_module::label_type;

		template<auto Pos>
		static constexpr label_type lines = machine_module::template label
		<
			machine_module::template at<Pos>
		>;
	};

	template<index_type Pos, auto... Vs>
	constexpr auto pack_at = machine_module::template start<linear_program_at, Vs...>(U_pack_Vs<Pos>);

/***********************************************************************************************************************/

// erase:

	struct linear_program_erase : public machine_module::template linear_program<>
	{
		using label_type = typename machine_module::label_type;

		template<auto Pos>
		static constexpr label_type lines = machine_module::template label
		<
			machine_module::template erase<Pos>,
			machine_module::template registers<>
		>;
	};

	template<index_type Pos, auto... Vs>
	constexpr auto pack_erase = machine_module::template start<linear_program_erase, Vs...>(U_pack_Vs<Pos>);

/***********************************************************************************************************************/

// insert:

	struct linear_program_insert : public machine_module::template linear_program<>
	{
		using label_type = typename machine_module::label_type;

		template<auto Pos, auto Obj>
		static constexpr label_type lines = machine_module::template label
		<
			machine_module::template insert<Pos, Obj>,
			machine_module::template registers<>
		>;
	};

	template<index_type Pos, index_type Obj, auto... Vs>
	constexpr auto pack_insert = machine_module::template start<linear_program_insert, Vs...>(U_pack_Vs<Pos, Obj>);

/***********************************************************************************************************************/

// replace:

	struct linear_program_replace : public machine_module::template linear_program<>
	{
		using label_type = typename machine_module::label_type;

		template<auto Pos, auto Obj>
		static constexpr label_type lines = machine_module::template label
		<
			machine_module::template replace<Pos, Obj>,
			machine_module::template registers<>
		>;
	};

	template<index_type Pos, index_type Obj, auto... Vs>
	constexpr auto pack_replace = machine_module::template start<linear_program_replace, Vs...>(U_pack_Vs<Pos, Obj>);

/***********************************************************************************************************************/

// apply:

	struct linear_program_apply : public machine_module::template linear_program<>
	{
		using label_type = typename machine_module::label_type;

		template<auto Pos, auto Op, auto... Args>
		static constexpr label_type lines = machine_module::template label
		<
			machine_module::template apply<Pos, Op, Args...>,
			machine_module::template registers<>
		>;
	};

	template<auto op, auto x, auto y>
	constexpr auto pack_apply = machine_module::template start
	<
		linear_program_apply, index_type{0}, op, x, y

	>(U_pack_Vs<index_type{0}, index_type{1}, index_type{2}, index_type{3}>);

	template<typename T> constexpr T add(T x, T y) { return x+y; }

/***********************************************************************************************************************/

	int main(int argc, char *argv[])
	{
	//	printf("%d\n", pack_at<5,  0, 1, 2, 3, 4, 7>); // prints: 7
	//	printf("%d\n", pack_erase<3,  0, 1, 2, 3, 4, 7>);
	//	printf("%d\n", pack_insert<3, 5,  0, 1, 2, 3, 4, 7>);
	//	printf("%d\n", pack_replace<3, 5,  0, 1, 2, 3, 4, 7>);

	//	printf("%d\n", pack_apply<add<index_type>, 4, 7>);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

