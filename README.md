# nik-cpp-library

A C++17 header only self-contained library. It is self-contained in the sense that it does not
use the standard namespace (*std::*). It consists of the following sections:

0) A "modules"-like dependency space, with a choice between an *inclusive* header file which
then sources the entire library, or an *exclusive* header file which then allows the user to
include specific modules manually.

1) A compile time space, notably including a register machine based off the Scheme (LISP) register
machine grammar, as discussed in *Structure and Interpretation of Computer Programs* (SICP).

Much effort has been put into privileging performance in this machine's design: There are several meta
programming styles possible when implementing---struct template, alias template, constexpr function---and
although they are equivalent to each other in potential, they can vary greatly in performance. 
It is for this reason a hybrid approach (though leaning toward *constexpr* style) was largely favored.

2) A run time space, which is currently under construction. It can be considered to have two parts:
First is a near linear function space, which provides higher order functions that allows the user to build
1-cycle list operators (loops) at compile time. Such loops are achieved through continuation passing
*monadic composition*, and require tail call optimization (-O2 compiler optimization) to be performant.

The second part is a typed assembly function space. Like the near linear space it provides higher order
functions, but this time they are intended to build typed assembly code. Notably, each such function
is equipped with its own decentralized stack.

