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

// nomenclature source:

/*
	This library is intended to be a TMP/constexpr library, and as such offers grammatical tools resembling functions
	which manipulate the type system.

	As C++17 has no clear mechanism to annotate meta grammatical tools, any such meta types are thus described within
	the names of the grammatical tools themselves. The following provides a reference for these meta types along with
	a theory based narrative toward their particular conceptualization.

	We start with template parameters as they constrain and represent the possible input of the above mentioned
	meta functions. Notably we have:

		T - type						[typename]
		V - value						[auto]
		E - variable template (indirect)			[template<auto...> auto]
		F - function template (indirect)			[template<auto...> auto(*)(auto)]
		A - type(s) template template				[template<typename...> class]
		B - value(s) template template				[template<auto...> class]

	As for meta function output: Since only types or values can be returned from meta grammatical operators
	(regardless of template parameter input), if we then require any of the other template parameter categories
	to be returned we must embed or *cache* them within types or values (such that they may also be recovered
	or pattern matched afterward). As such they are encoded as subcategories of typenames or autos, but given
	their relevance throughout the library, they are given names with meanings as follows:

	Type subcategories:

		R - has a type(s) cache
		S - has a value(s) cache
		E - has a variable template member (indirect cache)
		F - has a function template member (indirect cache)
		C - has a type(s) template template(s) cache
		D - has a value(s) template template(s) cache

	Value subcategories:

		U - has a type cache
		W - has a type cache with its own type(s) cache
		X - has a type cache with its own value(s) cache
		I - has a type cache with its own variable template member (indirect cache)
		J - has a type cache with its own function template member (indirect cache)
		G - has a type cache with its own type(s) template template(s) cache
		H - has a type cache with its own value(s) template template(s) cache

	To summarize, there are seventeen distinct categories. As for "categories",
	the theoretcal narrative comes from category theory, and is as follows:

	a) We start with the discrete category of C++17s type system, with C++17s types as objects, and the only morphisms
	being the identities. We'll call this category C++T.

	b) From there we use C++T to generate its category of elements, called C++V. From a type theory lens, the objects in
	this category are C++17 judgments (type value pairs). Moreover, the definition of the category of elements means
	the only morphisms in this category are also trivial (identities).

	c) We also make use of template template categories, with C++B consisting of *template<typename...> class* patterns,
	and C++C of *template<auto...> class* patterns.

	d) From here we can create a new category by uniting and filtering the objects of these categories C++T, C++V,
	C++B, and C++C, where in particular we filter out all objects which aren't acceptable as template parameters
	by the standard. This category we will call C++TP.

	e) The category we're finally interested in takes the subcategories of C++TP as its objects, and as its morphisms
	we finally have the above mentioned grammatical tools that act on such classes of objects. We call this category
	C++Nik.

	The above nomenclature then represents particular objects within C++Nik, so for example we can now describe
	a given grammatical tool (which is actually a functor) as:

		U_type_T

	This functor in particular maps types to type caches (objects of C++V), and can further be used
	to define the subcategory U.

	Beyond this, we can also describe constants by providing a prefix while omitting a suffix:

		T_add

	This tells us our *add* constant is a predefined typename. The convention here is that by omitting the suffix
	we are saying this is a meta function that takes no input (or takes a trivial input), and so can be considered
	a constant.

	Finally, for the purpose of user friendly design---given that there are seventeen distinct categories---if
	the output of a given grammatical tool is a value subcategory which can be deduced from the U subcategory alone,
	the codomain will simply be given less precisely as U itself.
*/

