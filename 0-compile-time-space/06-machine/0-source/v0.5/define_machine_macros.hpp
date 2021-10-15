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
		typename n, auto c, auto d, auto i, auto j								\

/***********************************************************************************************************************/

	#define NIK_BEGIN_MACHINE(_n_, _c_, _d_, _i_, _j_)								\
															\
		machine													\
		<													\
			_n_::next_name(_c_, _d_, _i_, _j_),								\
			_n_::next_note(_c_, _d_, _i_, _j_)								\
															\
		>::template result											\
		<													\
			_n_, _c_,											\
															\
			_n_::next_depth(_d_),										\
			_n_::next_index1(_c_, _d_, _i_, _j_),								\
			_n_::next_index2(_c_, _d_, _i_, _j_)

	#define NIK_END_MACHINE 											\
															\
		>

	#define NIK_MACHINE(_n_, _c_, _d_, _i_, _j_)									\
															\
		NIK_BEGIN_MACHINE(_n_, _c_, _d_, _i_, _j_),  Vs...  NIK_END_MACHINE

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// stack -> stack:

/***********************************************************************************************************************/

// shift range block, insert at stack back (2^N):

	#define NIK_DEFINE__SHIFT_R_BLOCK__INSERT_AT_S_BACK(_n_)							\
															\
		template<key_type... filler>										\
		struct machine<MN::shift_r_block__insert_at_s_back, _n_, filler...>					\
		{													\
			template<NIK_CONTR_PARAMS, auto... Vs, typename... Heaps>					\
			static constexpr auto result(Heaps... Hs)							\
			{												\
				constexpr index_type offset = sizeof...(Vs);						\
															\
				return NIK_BEGIN_MACHINE(n, c, d, i, j),						\
															\
					Vs..., NIK_2_ ## _n_ ## _INDICES(offset)					\
															\
				NIK_END_MACHINE(Hs...);									\
			}												\
		}

/***********************************************************************************************************************/

// drop stack block (2^N):

	#define NIK_DEFINE__DROP_S_BLOCK(_n_)										\
															\
		template<key_type... filler>										\
		struct machine<MN::drop_s_block, _n_, filler...>							\
		{													\
			template<NIK_CONTR_PARAMS, NIK_2_ ## _n_ ## _AUTO_VS, auto... Vs, typename... Heaps>		\
			static constexpr auto result(Heaps... Hs)							\
			{												\
				return NIK_MACHINE(n, c, d, i, j)(Hs...);						\
			}												\
		}

/***********************************************************************************************************************/

// drop stack position (optimization):

	#define NIK_DEFINE__DROP_S_POS(_s_, _n_, _c_)									\
															\
		template<key_type... filler>										\
		struct machine<MN::drop_s_pos, _n_, filler...>								\
		{													\
			template<NIK_CONTR_PARAMS, NIK_ ## _s_ ## _FAST_AUTO_VS, auto... Vs, typename... Heaps>		\
			static constexpr auto result(Heaps... Hs)							\
			{												\
				return NIK_BEGIN_MACHINE(n, c, d, i, j),						\
															\
					NIK_ ## _n_ ## _FAST_VS  NIK_ ## _c_ ## _COMMA  Vs...				\
															\
				NIK_END_MACHINE(Hs...);									\
			}												\
		}

/***********************************************************************************************************************/

// move stack block, insert at stack back (2^N):

	#define NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_S_BACK(_n_)								\
															\
		template<key_type... filler>										\
		struct machine<MN::move_s_block__insert_at_s_back, _n_, filler...>					\
		{													\
			template<NIK_CONTR_PARAMS, NIK_2_ ## _n_ ## _AUTO_VS, auto... Vs, typename... Heaps>		\
			static constexpr auto result(Heaps... Hs)							\
			{												\
				return NIK_BEGIN_MACHINE(n, c, d, i, j),						\
															\
					Vs..., NIK_2_ ## _n_ ## _VS							\
															\
				NIK_END_MACHINE(Hs...);									\
			}												\
		}

/***********************************************************************************************************************/

// move stack position, insert at stack back (optimization):

	#define NIK_DEFINE__MOVE_S_POS__INSERT_AT_S_BACK(_s_, _n_, _c_)							\
															\
		template<key_type... filler>										\
		struct machine<MN::move_s_pos__insert_at_s_back, _n_, filler...>					\
		{													\
			template<NIK_CONTR_PARAMS, NIK_ ## _s_ ## _FAST_AUTO_VS, auto... Vs, typename... Heaps>		\
			static constexpr auto result(Heaps... Hs)							\
			{												\
				return NIK_BEGIN_MACHINE(n, c, d, i, j),						\
															\
					NIK_ ## _n_ ## _FAST_VS  NIK_ ## _c_ ## _COMMA  Vs..., V ## _n_			\
															\
				NIK_END_MACHINE(Hs...);									\
			}												\
		}

/***********************************************************************************************************************/

// fold stack block, op at heap zero first (2^N):

	#define NIK_DEFINE__FOLD_S_BLOCK__OP_AT_H0_FIRST(_n_)								\
															\
		template<key_type... filler>										\
		struct machine<MN::fold_s_block__op_at_h0_first, _n_, filler...>					\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, auto V, NIK_2_ ## _n_ ## _AUTO_VS, auto... Vs,			\
				auto op, auto... Ws, typename... Heaps							\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<op, Ws...>*), Heaps... Hs)			\
			{												\
				return NIK_BEGIN_MACHINE(n, c, d, i, j),						\
															\
					NIK_2_ ## _n_ ## _OPS  V,  NIK_2_ ## _n_ ## _OP_VS, Vs...			\
															\
				NIK_END_MACHINE(H0, Hs...);								\
			}												\
		}

/***********************************************************************************************************************/

// roll stack block, act at heap zero first (2^N):

	#define NIK_DEFINE__ROLL_S_BLOCK__ACT_AT_H0_FIRST(_n_)								\
															\
		template<key_type... filler>										\
		struct machine<MN::roll_s_block__act_at_h0_first, _n_, filler...>					\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, auto V, NIK_2_ ## _n_ ## _AUTO_VS, auto... Vs,			\
				auto uact, auto... Ws, typename... Heaps						\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<uact, Ws...>*), Heaps... Hs)			\
			{												\
				using act = T_type_U<uact>;								\
															\
				return NIK_BEGIN_MACHINE(n, c, d, i, j),						\
															\
					NIK_2_ ## _n_ ## _ACTS  V,  NIK_2_ ## _n_ ## _ACT_VS, Vs...			\
															\
				NIK_END_MACHINE(H0, Hs...);								\
			}												\
		}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// stack -> heap:

/***********************************************************************************************************************/

// move stack block, insert at heap zero front (2^N):

	#define NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H0_FRONT(_n_)							\
															\
		template<key_type... filler>										\
		struct machine<MN::move_s_block__insert_at_h0_front, _n_, filler...>					\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, NIK_2_ ## _n_ ## _AUTO_VS, auto... Vs,				\
				auto... Ws, typename... Heaps								\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)				\
			{												\
				return NIK_MACHINE(n, c, d, i, j)(U_opt_pack_Vs<NIK_2_ ## _n_ ## _VS, Ws...>, Hs...);	\
			}												\
		}

/***********************************************************************************************************************/

// move stack block, insert at heap one back (2^N):

	#define NIK_DEFINE__MOVE_S_BLOCK__INSERT_AT_H1_BACK(_n_)							\
															\
		template<key_type... filler>										\
		struct machine<MN::move_s_block__insert_at_h1_back, _n_, filler...>					\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, NIK_2_ ## _n_ ## _AUTO_VS, auto... Vs,				\
				typename Heap0, auto... Ws, typename... Heaps						\
			>												\
			static constexpr auto result(Heap0 H0, void(*H1)(auto_pack<Ws...>*), Heaps... Hs)		\
			{												\
				return NIK_MACHINE(n, c, d, i, j)							\
					(H0, U_opt_pack_Vs<Ws..., NIK_2_ ## _n_ ## _VS>, Hs...);			\
			}												\
		}

/***********************************************************************************************************************/

// copy stack block, insert at heap zero front (2^N):

	#define NIK_DEFINE__COPY_S_BLOCK__INSERT_AT_H0_FRONT(_n_)							\
															\
		template<key_type... filler>										\
		struct machine<MN::copy_s_block__insert_at_h0_front, _n_, filler...>					\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, NIK_2_ ## _n_ ## _AUTO_VS, auto... Vs,				\
				auto... Ws, typename... Heaps								\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)				\
			{												\
				return NIK_BEGIN_MACHINE(n, c, d, i, j),						\
															\
					NIK_2_ ## _n_ ## _VS, Vs...							\
															\
				NIK_END_MACHINE(U_opt_pack_Vs<NIK_2_ ## _n_ ## _VS, Ws...>, Hs...);			\
			}												\
		}

/***********************************************************************************************************************/

// copy stack block, insert at heap zero back (2^N):

	#define NIK_DEFINE__COPY_S_BLOCK__INSERT_AT_H0_BACK(_n_)							\
															\
		template<key_type... filler>										\
		struct machine<MN::copy_s_block__insert_at_h0_back, _n_, filler...>					\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, NIK_2_ ## _n_ ## _AUTO_VS, auto... Vs,				\
				auto... Ws, typename... Heaps								\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)				\
			{												\
				return NIK_BEGIN_MACHINE(n, c, d, i, j),						\
															\
					NIK_2_ ## _n_ ## _VS, Vs...							\
															\
				NIK_END_MACHINE(U_opt_pack_Vs<Ws..., NIK_2_ ## _n_ ## _VS>, Hs...);			\
			}												\
		}

/***********************************************************************************************************************/

// copy stack block, insert at heap two front (2^N):

	#define NIK_DEFINE__COPY_S_BLOCK__INSERT_AT_H2_FRONT(_n_)							\
															\
		template<key_type... filler>										\
		struct machine<MN::copy_s_block__insert_at_h2_front, _n_, filler...>					\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, NIK_2_ ## _n_ ## _AUTO_VS, auto... Vs,				\
				typename Heap0, typename Heap1, auto... Ws, typename... Heaps				\
			>												\
			static constexpr auto result(Heap0 H0, Heap1 H1, void(*H2)(auto_pack<Ws...>*), Heaps... Hs)	\
			{												\
				return NIK_BEGIN_MACHINE(n, c, d, i, j),						\
															\
					NIK_2_ ## _n_ ## _VS, Vs...							\
															\
				NIK_END_MACHINE(H0, H1, U_opt_pack_Vs<NIK_2_ ## _n_ ## _VS, Ws...>, Hs...);		\
			}												\
		}

/***********************************************************************************************************************/

// copy stack position, insert at heap zero front (optimization):

	#define NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_FRONT(_s_, _n_)							\
															\
		template<key_type... filler>										\
		struct machine<MN::copy_s_pos__insert_at_h0_front, _n_, filler...>					\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, NIK_ ## _s_ ## _FAST_AUTO_VS, auto... Vs,				\
				auto... Ws, typename... Heaps								\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)				\
			{												\
				return NIK_BEGIN_MACHINE(n, c, d, i, j),						\
															\
					NIK_ ## _s_ ## _FAST_VS, Vs...							\
															\
				NIK_END_MACHINE(U_opt_pack_Vs<V ## _n_, Ws...>, Hs...);					\
			}												\
		}

/***********************************************************************************************************************/

// copy stack position, insert at heap zero back (optimization):

	#define NIK_DEFINE__COPY_S_POS__INSERT_AT_H0_BACK(_s_, _n_)							\
															\
		template<key_type... filler>										\
		struct machine<MN::copy_s_pos__insert_at_h0_back, _n_, filler...>					\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, NIK_ ## _s_ ## _FAST_AUTO_VS, auto... Vs,				\
				auto... Ws, typename... Heaps								\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<Ws...>*), Heaps... Hs)				\
			{												\
				return NIK_BEGIN_MACHINE(n, c, d, i, j),						\
															\
					NIK_ ## _s_ ## _FAST_VS, Vs...							\
															\
				NIK_END_MACHINE(U_opt_pack_Vs<Ws..., V ## _n_>, Hs...);					\
			}												\
		}

/***********************************************************************************************************************/

// copy stack position, insert at heap two front (optimization):

	#define NIK_DEFINE__COPY_S_POS__INSERT_AT_H2_FRONT(_s_, _n_)							\
															\
		template<key_type... filler>										\
		struct machine<MN::copy_s_pos__insert_at_h2_front, _n_, filler...>					\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, NIK_ ## _s_ ## _FAST_AUTO_VS, auto... Vs,				\
				typename Heap0, typename Heap1, auto... Ws, typename... Heaps				\
			>												\
			static constexpr auto result(Heap0 H0, Heap1 H1, void(*H2)(auto_pack<Ws...>*), Heaps... Hs)	\
			{												\
				return NIK_BEGIN_MACHINE(n, c, d, i, j),						\
															\
					NIK_ ## _s_ ## _FAST_VS, Vs...							\
															\
				NIK_END_MACHINE(H0, H1, U_opt_pack_Vs<V ## _n_, Ws...>, Hs...);				\
			}												\
		}

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// heap -> stack:

/***********************************************************************************************************************/

// move heap zero first, insert at stack position (optimization):

	#define NIK_DEFINE__MOVE_H0_FIRST__INSERT_AT_S_POS(_n_, _c_)							\
															\
		template<key_type... filler>										\
		struct machine<MN::move_h0_first__insert_at_s_pos, _n_, filler...>					\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, NIK_ ## _n_ ## _FAST_AUTO_VS  NIK_ ## _c_ ## _COMMA  auto... Vs,	\
				auto W0, auto... Ws, typename... Heaps							\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<W0, Ws...>*), Heaps... Hs)			\
			{												\
				return NIK_BEGIN_MACHINE(n, c, d, i, j),						\
															\
					NIK_ ## _n_ ## _FAST_VS  NIK_ ## _c_ ## _COMMA  W0, Vs...			\
															\
				NIK_END_MACHINE(U_opt_pack_Vs<Ws...>, Hs...);						\
			}												\
		}

/***********************************************************************************************************************/

// move heap zero first, replace at stack position (optimization):

	#define NIK_DEFINE__MOVE_H0_FIRST__REPLACE_AT_S_POS(_s_, _n_, _c_)						\
															\
		template<key_type... filler>										\
		struct machine<MN::move_h0_first__replace_at_s_pos, _n_, filler...>					\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, NIK_ ## _s_ ## _FAST_AUTO_VS, auto... Vs,				\
				auto W0, auto... Ws, typename... Heaps							\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<W0, Ws...>*), Heaps... Hs)			\
			{												\
				return NIK_BEGIN_MACHINE(n, c, d, i, j),						\
															\
					NIK_ ## _n_ ## _FAST_VS  NIK_ ## _c_ ## _COMMA  W0, Vs...			\
															\
				NIK_END_MACHINE(U_opt_pack_Vs<Ws...>, Hs...);						\
			}												\
		}

/***********************************************************************************************************************/

// move heap two first, replace at stack position (optimization):

	#define NIK_DEFINE__MOVE_H2_FIRST__REPLACE_AT_S_POS(_s_, _n_, _c_)						\
															\
		template<key_type... filler>										\
		struct machine<MN::move_h2_first__replace_at_s_pos, _n_, filler...>					\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, NIK_ ## _s_ ## _FAST_AUTO_VS, auto... Vs,				\
				typename Heap0, typename Heap1, auto W0, auto... Ws, typename... Heaps			\
			>												\
			static constexpr auto result(Heap0 H0, Heap1 H1, void(*H2)(auto_pack<W0, Ws...>*), Heaps... Hs)	\
			{												\
				return NIK_BEGIN_MACHINE(n, c, d, i, j),						\
															\
					NIK_ ## _n_ ## _FAST_VS  NIK_ ## _c_ ## _COMMA  W0, Vs...			\
															\
				NIK_END_MACHINE(H0, H1, U_opt_pack_Vs<Ws...>, Hs...);					\
			}												\
		}

/***********************************************************************************************************************/

// apply heap zero all, move, replace at stack position (optimization):

	#define NIK_DEFINE__APPLY_H0_ALL__MOVE__REPLACE_AT_S_POS(_s_, _n_, _c_)						\
															\
		template<key_type... filler>										\
		struct machine<MN::apply_h0_all__move__replace_at_s_pos, _n_, filler...>				\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, NIK_ ## _s_ ## _FAST_AUTO_VS, auto... Vs,				\
				auto op, auto... args, typename... Heaps						\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<op, args...>*), Heaps... Hs)			\
			{												\
				return NIK_BEGIN_MACHINE(n, c, d, i, j),						\
															\
					NIK_ ## _n_ ## _FAST_VS  NIK_ ## _c_ ## _COMMA  op(args...), Vs...		\
															\
				NIK_END_MACHINE(U_opt_pack_Vs<>, Hs...);						\
			}												\
		}

/***********************************************************************************************************************/

// compel heap zero all, move, replace at stack position (optimization):

	#define NIK_DEFINE__COMPEL_H0_ALL__MOVE__REPLACE_AT_S_POS(_s_, _n_, _c_)					\
															\
		template<key_type... filler>										\
		struct machine<MN::compel_h0_all__move__replace_at_s_pos, _n_, filler...>				\
		{													\
			template											\
			<												\
				NIK_CONTR_PARAMS, NIK_ ## _s_ ## _FAST_AUTO_VS, auto... Vs,				\
				auto uact, auto... args, typename... Heaps						\
			>												\
			static constexpr auto result(void(*H0)(auto_pack<uact, args...>*), Heaps... Hs)			\
			{												\
				return NIK_BEGIN_MACHINE(n, c, d, i, j),						\
															\
					NIK_ ## _n_ ## _FAST_VS  NIK_ ## _c_ ## _COMMA					\
															\
					T_type_U<uact>::template result<args...>, Vs...					\
															\
				NIK_END_MACHINE(U_opt_pack_Vs<>, Hs...);						\
			}												\
		}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

