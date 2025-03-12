# Assignment: Document Lookup



## Overview

In this assignment you will implement a very simple document lookup
system using different standard library collections, and analyze their
performance.

Remember to to fill out the ABOUT.txt (and LLM.txt if needed).

Requirements:
* **For this assignment, the C++98 standard must be used (in that it compiles with the -std=c++98 flag; e.g. no auto, no range-based
  for loops).**
* **You must write all loops that iterate over the elements of a
  collection (even strings) as `for` loops using iterators
  (i.e. calling `begin()` and `end()`); however, you can use `while`
  loops without iterators for reading file input from streams.**
* **You must not use any
  standard library algorithms (i.e. from &lt;algorithm&gt;), but you
  can use any member functions on the collections.**
* **Modifiable files:** You can modify `Document.cpp`, `Lookup.cpp`, and `compare_main.cpp`.



### doc_main

Implement the functions marked TODO in `Document.cpp` and `Lookup.cpp` to
implement a document loading and word lookup system.  The functions in
`Document.cpp` read in and print out documents. The functions in
`Lookup.cpp` add documents to a collection and look up words in the
documents.

`doc_main.cpp` implements a simple text command input system for using
the system.  A command reference is given below.

Requirements:
* **`add_document` and `lookup_word` on a `MapCollection` must not do a linear search through the collection, but must use `map` member functions (e.g. `map::find`) that use the map's data structure.**

Implementation notes:
* In addition to the `T::iterator` types provided by collections (such as `vector<int>::iterator`), there are also `T::const_iterator` types for iterating through const collections.
* In C++98, an ifstream can't be initialized from a string object; however, you can use string's `c_str()` member function to get a type that can be used to initialize an ifstream.



### compare_main

Use callgrind to compare the relative performance of the different types
of collections.

Fill in implementations of the `use_...` functions in `compare_main.cpp`, in
the areas marked TODO, to use the collections. For each iteration of
the loop, initialize the collection from scratch from the document and
search for a word that is *not in the collection*.

You can modify the constants at the top of the file to change the
document name and number of iterations.

For both the primes_small and primes_large documents, use callgrind to
analyze the performance of the collections *two times* each: once
with the `-O0 -fno-inline` compile flags and once with the `-O2`
compile flag (no `-fno-inline`); you'll need to edit the Makefile.
Include the *percentage* of instructions your program spent in each
of the `use_...` functions and a short summary of what you observed in
terms of the relative performance of each function in compare.txt.



## Command reference

*list*  
&nbsp; List the documents.

*print [docname]*  
&nbsp; Print the document named *docname*.

*lookup-v [word]*  
&nbsp; Lookup *word* in the vector collection.

*lookup-l [word]*  
&nbsp; Lookup *word* in the list collection.

*lookup-m [word]*  
&nbsp; Lookup *word* in the map collection.
