# Assignment: Shape Library



## Overview

In this assignment you will implement a small library of shapes that
use a 2D vector class.  The shapes use an inheritance hierarchy, and
the 2D vector uses operator overloading.

Starting from the provided repository, which includes starter code,
reference implementations, and test cases, fill in the function
implementations to complete the shape library game in C++.

Remember to to fill out the ABOUT.txt (and LLM.txt if needed).

Implementation notes:
* This assignment has a larger number of executables for the tests.  Most of the tests are mainly based on the code compiling.
* It's possible to return a reference to a member variable from a member function.
* It's possible to have both const and non-const versions of member functions at the same time (overloading).
* operator[] can be overloaded in the same way as operator().
* If a destructor is decalred, it has to be defined, even if it is pure virtual.
* `ostream` shouldn't be passed to or returned from functions by value, but can be passed and returned by reference.
* You'll need to use the `std::` namespace prefix in header files.

Requirements:
* **The Shape class must be abstract.**
* **Shape must have no member variables.**
* **All Shape member functions, other than constructors and destructors, must not have implementations.  Any Shape constructors or destructors must have empty implementations.**
* **All function implementations (definitions) must be in source (.cpp) files.**
* **Modifiable files:** You can edit `Vector2D.hpp`, `Vector2D.cpp`, `Shapes.hpp` and `Shapes.cpp`.
