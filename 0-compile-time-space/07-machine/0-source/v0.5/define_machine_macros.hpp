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

// define machine macros source:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// preamble:

/***********************************************************************************************************************/

	#define NIK_CONTR_PARAMS											\
															\
		auto d, auto m, auto n, auto c, auto i, auto j								\

/***********************************************************************************************************************/

	#define NIK_BEGIN_AUTOMATA(_d_, _m_, _n_, _c_, _i_, _j_)							\
															\
		machine													\
		<													\
			next_name<T_type_U<_n_>>(_d_, _m_, _c_, _i_, _j_),						\
			next_note<T_type_U<_n_>>(_d_, _m_, _c_, _i_, _j_)						\
															\
		>::template result											\
		<													\
			next_depth(_d_),										\
			_m_, _n_, _c_,											\
			next_index1<T_type_U<_n_>>(_d_, _m_, _c_, _i_, _j_),						\
			next_index2<T_type_U<_n_>>(_d_, _m_, _c_, _i_, _j_)

	#define NIK_END_AUTOMATA 											\
															\
		>

	#define NIK_AUTOMATA(_d_, _m_, _n_, _c_, _i_, _j_, _v_)								\
															\
		NIK_BEGIN_AUTOMATA(_d_, _m_, _n_, _c_, _i_, _j_),  _v_...  NIK_END_AUTOMATA

/***********************************************************************************************************************/

	#define NIK_BEGIN_MACHINE(_d_, _n_, _c_, _i_, _j_)								\
															\
		NIK_BEGIN_AUTOMATA(_d_, MT::id, _n_, _c_, _i_, _j_)

	#define NIK_END_MACHINE 											\
															\
		NIK_END_AUTOMATA

	#define NIK_MACHINE(_d_, _n_, _c_, _i_, _j_, _v_)								\
															\
		NIK_AUTOMATA(_d_, MT::id, _n_, _c_, _i_, _j_, _v_)

/***********************************************************************************************************************/

	#define NIK_BEGIN_INTERNAL(_d_, _n_, _c_, _i_, _j_)								\
															\
		NIK_BEGIN_AUTOMATA(_d_, MT::call, _n_, _c_, _i_, _j_)

	#define NIK_END_INTERNAL 											\
															\
		NIK_END_AUTOMATA

	#define NIK_INTERNAL(_d_, _n_, _c_, _i_, _j_, _v_)								\
															\
		NIK_AUTOMATA(_d_, MT::call, _n_, _c_, _i_, _j_, _v_)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// unpack instruction block (, insert at heap one back) (2^N):

		// This machine is not general purpose, and so is optimized accordingly.

	#define NIK_DEFINE__UNPACK_I_BLOCK(_n_)										\
															\
		template<key_type... filler>										\
		struct machine<MN::unpack_i_block, _n_, filler...>							\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, auto... Vs,								\
				auto call_ins, auto length, auto... Ws, auto... Xs, typename... Heaps			\
			>												\
			static constexpr auto result									\
			(												\
				void(*H0)(auto_pack<call_ins, length, Ws...>*),						\
				void(*H1)(auto_pack<Xs...>*), Heaps... Hs						\
			)												\
			{												\
				constexpr index_type offset = length - i;						\
															\
				return NIK_MACHINE(d, n, c, i, j, Vs)							\
				(											\
					H0,										\
															\
					U_opt_pack_Vs									\
					<										\
						Xs...,									\
						NIK_2_ ## _n_ ## _ARRAY_BLOCK(call_ins, offset)				\
					>,										\
															\
					Hs...										\
				);											\
			}												\
		}

/***********************************************************************************************************************/

// move register block (2^N):

	#define NIK_DEFINE__MOVE_R_BLOCK(_n_)										\
															\
		template<key_type... filler>										\
		struct machine<MN::move_r_block, _n_, filler...>							\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, NIK_2_ ## _n_ ## _AUTO_VS, auto... Vs,				\
				typename Heap0, auto... Xs, typename... Heaps						\
			>												\
			static constexpr auto result(Heap0 H0, void(*H1)(auto_pack<Xs...>*), Heaps... Hs)		\
			{												\
				using tn		= T_type_U<n>;							\
				constexpr auto ins	= tn::instr(c, i, j);						\
															\
				if constexpr (ins[BI::policy] == MT::drop)						\
															\
					return NIK_MACHINE(d, n, c, i, j, Vs)(H0, H1, Hs...);				\
				else											\
					return NIK_MACHINE(d, n, c, i, j, Vs)						\
						(H0, U_opt_pack_Vs<Xs..., NIK_2_ ## _n_ ## _VS>, Hs...);		\
			}												\
		}

/***********************************************************************************************************************/

// fold register block (2^N):

	#define NIK_DEFINE__FOLD_R_BLOCK(_n_)										\
															\
		template<key_type... filler>										\
		struct machine<MN::fold_r_block, _n_, filler...>							\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, auto V, NIK_2_ ## _n_ ## _AUTO_VS, auto... Vs,			\
				auto op, auto... Ws, typename... Heaps							\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<op, Ws...>*), Heaps... Hs)			\
			{												\
				using tn		= T_type_U<n>;							\
				constexpr auto ins	= tn::instr(c, i, j);						\
															\
				if constexpr (ins[BI::policy] == MT::act_at_h0_first)					\
				{											\
					using act = T_type_U<op>;							\
															\
					return NIK_BEGIN_MACHINE(d, n, c, i, j),					\
															\
						NIK_2_ ## _n_ ## _ACTS  V,  NIK_2_ ## _n_ ## _ACT_VS, Vs...		\
															\
					NIK_END_MACHINE(H0, Hs...);							\
				}											\
				else return NIK_BEGIN_MACHINE(d, n, c, i, j),						\
															\
						NIK_2_ ## _n_ ## _OPS  V,  NIK_2_ ## _n_ ## _OP_VS, Vs...		\
															\
					NIK_END_MACHINE(H0, Hs...);							\
			}												\
		}

/***********************************************************************************************************************/

// copy register position (optimization):

	#define NIK_DEFINE__COPY_R_POS(_s_, _n_)									\
															\
		template<key_type... filler>										\
		struct machine<MN::copy_r_pos, _n_, filler...>								\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, NIK_ ## _s_ ## _FAST_AUTO_VS, auto... Vs,				\
				auto... Ws, typename... Heaps								\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)				\
			{												\
				return NIK_BEGIN_MACHINE(d, n, c, i, j),						\
															\
					NIK_ ## _s_ ## _FAST_VS, Vs...							\
															\
				NIK_END_MACHINE(U_opt_pack_Vs<V ## _n_, Ws...>, Hs...);					\
			}												\
															\
			template											\
			<												\
				NIK_CONTR_PARAMS, NIK_ ## _s_ ## _FAST_AUTO_VS, auto... Vs,				\
				auto... Ws, typename... Heaps								\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)				\
			{												\
				return NIK_BEGIN_MACHINE(d, n, c, i, j),						\
															\
					NIK_ ## _s_ ## _FAST_VS, Vs...							\
															\
				NIK_END_MACHINE(U_opt_pack_Vs<Ws..., V ## _n_>, Hs...);					\
			}												\
		}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

