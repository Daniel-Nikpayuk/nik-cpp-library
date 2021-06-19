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

// constexpr string (experimental):

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	struct apple
	{
		int x;
		char y;

		constexpr apple(int _x, char _y) : x(_x), y(_y) { }
	};

	template<int _x, char _y>
	constexpr auto f_apple() { return apple(_x, _y); }

	template<auto fa>
	constexpr auto x_plus_one = fa().x+1;

	template<auto fa>
	constexpr auto y_plus_one = fa().y+1;

		constexpr auto a = f_apple<5, 'A'>;

		printf("%d\n", x_plus_one<a>);
		printf("%c\n", y_plus_one<a>);
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template<utype N>
	struct constexpr_string
	{
		// members:

			static constexpr utype size = N - 1;

			char arr[N] = { 0 };

		// assign:

			template<typename It>
			constexpr constexpr_string(It b , const It & e)
			{
				for (char *i = arr; b < e; ++i, ++b) *i = *b;
			}

			constexpr constexpr_string(const char (&a)[N]) :
				constexpr_string(a, a+N) { }

		// catenate:

			template<typename It1, typename It2>
			constexpr constexpr_string(It1 b1, const It1 & e1, It2 b2, const It2 & e2)
			{
				char *i = arr;

				while (b1 < e1) *(i++) = *(b1++);
				while (b2 < e2) *(i++) = *(b2++);
			}

			template<utype M1, utype M2>
			constexpr constexpr_string(const char (&a1)[M1], const char (&a2)[M2]) :
				constexpr_string(a1, a1+M1, a2, a2+M2) { }

			template<utype M>
			constexpr constexpr_string<N+M> operator + (const constexpr_string<M> & s) const
			{
				return constexpr_string<N+M>(begin(), end(), s.begin(), s.end());
			}

		// accessors:

			constexpr const char* begin() const { return arr; }
			constexpr const char* end() const { return arr+size; }
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// Making C++17 literal classes ---interoperable--- with my compile time register machine:

		// We wrap the literal classes within a function
		// so they can be passed as non-type template parameters:

			constexpr auto hi_f()		{ return constexpr_string("Hi "); }
			constexpr auto there_f()	{ return constexpr_string("there!"); }

		// Their operators are also wrapped as functions:

			template<auto s1_f, auto s2_f>
			constexpr auto catenate_f() { return s1_f() + s2_f(); }

		// This way we can treat the template *call* as the operator call we're interested
		// in: For example "catenate" takes two wrapped literal classes, and because we
		// didn't use the actual function call *()* we end up returning another function,
		// which is good for us as we can continue passing it as a template parameter.

		// Finally, to access the literal class within its wrapper, we only need apply
		// the function call *()*, to which we can then interact with it directly.

			int main(int argc, char *argv[])
			{
				constexpr auto hi_there	= catenate_f<hi_f, there_f>;
			
				printf("%s\n", hi_there().begin()); // prints: "Hi there!"
			
				return 0;
			}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

