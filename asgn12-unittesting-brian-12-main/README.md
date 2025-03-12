# Assignment: Unit Testing



## Overview

In this assignment you will implement unit tests for a dynamic array, and some algorithms
that work with those arrays.

You are provided with an implementation of a class IntArray, that
manages a dynamic array of integers, and IntArrayAlgorithms, that contains
placeholder functions for algorithms that operate on IntArrays. You
are also provided with placeholder CxxTest suites for IntArray and
existing suites for IntArrayAlgorithms.

Add unit tests to IntArray.cxxtest.hpp to test IntArray. Implement the placeholder functions in IntArrayAlgorithms.cpp.

**Note: This assignment has no reference implementation or tests for the test script. Use the `runner` executable created by the build.**

Your goal is:
* For the IntArray test suite to test *every* function and *every* line of code of `IntArray.cpp`. Each test should focus on testing a single function (except for explicitly testing `IntArray::~IntArray()`, `IntArray::ptr()`, and `IntArray::size()`).  This can be confirmed with gcov.
* For all the IntArrayAlgorithms tests to pass.

You will need to download CxxTest and add it to your repository.
* Visit the [CxxTest repo](https://github.com/CxxTest/cxxtest/), download, and extract revision a19f85fdf9 into a folder called `cxxtest`.
  * This can be done in a terminal using:
    * `curl -o cxxtest.zip -LO https://github.com/CxxTest/cxxtest/archive/a19f85fdf90f97e16d6e3e7e3d2d68c31cd89e3c.zip`
    * `unzip cxxtest.zip`
    * `mv cxxtest-a19f85fdf90f97e16d6e3e7e3d2d68c31cd89e3c cxxtest`
    * `rm cxxtest.zip`
* Move the `cxxtest` folder into your project folder.
* You may need to make the cxxtestgen file executable.  This can be done by entering `chmod +x cxxtest/bin/cxxtestgen` in a terminal.
* Add the `cxxtest` folder to your git repository.
  * Go to the Source Control sidebar. You should see a large number of files related to CxxTest listed.
  * Hover over Changes and click the + to stage the changes.
  * Commit and push the changes.

Remember to to fill out the ABOUT.txt (and LLM.txt if needed).

Requirements:
* **You must implement the `IntArrayAlgorithms.cpp` functions in terms of built-in types (e.g. int \*, int) and size_t. You must not call other library functions or use other library classes (e.g. std::sort or std::vector).**
* **Modifiable files:** You can edit `IntArray.cxxtest.hpp` and `IntArrayAlgorithms.cpp`.
