#ifndef INT_ARRAY_ALGORITHMS_HPP
#define INT_ARRAY_ALGORITHMS_HPP

#include "IntArray.hpp"

// a class for algorithms on IntArrays
class IntArrayAlgorithms {
public:
  static void swap(IntArray & lhs, IntArray & rhs); // swap the contents of two arrays
  static bool contains(const IntArray & arr, int val); // returns true if the array contains val, false otherwise
  static void sort(IntArray & arr); // sort the array, smallest to largest
  static int sum(const IntArray & arr); // return the sum of all the elements in the array (0 if empty)
  static int product(const IntArray & arr); // return the product of all the elements in the array (1 if empty)
};

#endif
