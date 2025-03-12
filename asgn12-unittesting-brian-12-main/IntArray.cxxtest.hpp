#ifndef INT_ARRAY_CXXTEST_HPP
#define INT_ARRAY_CXXTEST_HPP

#include <cxxtest/TestSuite.h>
#include <iostream>
#include <utility>
#include "IntArrayAlgorithms.hpp"

class IntArrayTestSuite : public CxxTest::TestSuite
{
public:

  void test_ctor_default() {
    // TODO
    IntArray arr;
    TS_ASSERT_EQUALS(arr.size(), 0);
  }

  void test_ctor_size_t() {
    // TODO
    IntArray arr(3);
    TS_ASSERT_EQUALS(arr.size(), 3);
  }

  void test_ctor_init() {
    // TODO
    IntArray arr = {1, 2, 3};

    TS_ASSERT_EQUALS(arr.size(), 3);
    TS_ASSERT_EQUALS(arr[0], 1);
    TS_ASSERT_EQUALS(arr[1], 2);
    TS_ASSERT_EQUALS(arr[2], 3);
  }

  void test_ctor_copy() {
    // TODO
    IntArray original = {1, 2, 3};
    IntArray copiedArray(original);
    TS_ASSERT_EQUALS(copiedArray.size(), original.size());
  }

  void test_ctor_move() {
    // TODO
    IntArray src = {1, 2, 3};
    IntArray moved(std::move(src));

    TS_ASSERT_EQUALS(moved.size(), 3);
    TS_ASSERT_EQUALS(moved[0], 1);
    TS_ASSERT_EQUALS(src.size(), 0);
    TS_ASSERT_EQUALS(src.ptr(), nullptr);
    TS_ASSERT_THROWS_ANYTHING(src[0]);
  }

  void test_asgn_copy() {
    // TODO
    IntArray arr1 = {1, 2, 3};
    IntArray arr2;
    arr2 = arr1;
    TS_ASSERT_EQUALS(arr2.size(), arr1.size());
    TS_ASSERT_EQUALS(arr2[0], arr1[0]);

    IntArray arr3 = {1, 2, 3};
    arr3 = arr3;
    TS_ASSERT_EQUALS(arr3.size(), 3);
    TS_ASSERT_EQUALS(arr3[0], 1);

    IntArray a = {1, 2, 3};
    IntArray b = {4, 5, 6};
    a = b;
    TS_ASSERT_EQUALS(a.size(), 3);
    TS_ASSERT_EQUALS(a[0], 4);
  }

  void test_asgn_move() {
    // TODO
    IntArray source = {1, 2, 3, 4};
    IntArray destination;
    destination = IntArray{5, 6, 7, 8};

    TS_ASSERT_EQUALS(destination.size(), 4);
    TS_ASSERT_EQUALS(destination[0], 5);
    TS_ASSERT_EQUALS(destination[1], 6);
    TS_ASSERT_EQUALS(destination[2], 7);
    TS_ASSERT_EQUALS(destination[3], 8);

    IntArray self = {1, 2, 3};
    IntArray &ref = self;
    self = ref;

    TS_ASSERT(self.ptr() != nullptr);
    TS_ASSERT_EQUALS(self.size(), 3);
    TS_ASSERT_EQUALS(self[0], 1);
  }

  void test_elem_nonconst() {
    // TODO
    IntArray arr = {1, 2, 3};
       
    TS_ASSERT_EQUALS(arr[0], 1);
    TS_ASSERT_EQUALS(arr[1], 2);
    TS_ASSERT_EQUALS(arr[2], 3);

    TS_ASSERT_THROWS_ANYTHING(arr[5]);
  }

  void test_elem_const() {
    // TODO
    const IntArray arr = {1, 2, 3};
       
    TS_ASSERT_EQUALS(arr[0], 1);
    TS_ASSERT_EQUALS(arr[1], 2);
    TS_ASSERT_EQUALS(arr[2], 3);

    TS_ASSERT_THROWS_ANYTHING(arr[5]);
  }


  void test_oper_eq() {
    // TODO
    IntArray arr1 = {1, 2, 3, 4};
    IntArray arr2 = {1, 2, 3, 4};
    TS_ASSERT(arr1 == arr2);

    IntArray arr3 = {1, 2, 3, 4};
    IntArray arr4 = {4, 3, 2, 1};
    TS_ASSERT(!(arr3 == arr4));

    IntArray arr5 = {1, 2, 3, 4};
    IntArray arr6 = {1, 2, 3};
    TS_ASSERT(!(arr5 == arr6));

    IntArray arr7 = {};
    IntArray arr8 = {};
    TS_ASSERT(arr7 == arr8);

    IntArray arr9 = {};
    IntArray arr10 = {1, 2, 3};
    TS_ASSERT(!(arr9 == arr10));
  }


  void test_oper_ne() {
    // TODO
    IntArray arr1 = {1, 2, 3, 4};
    IntArray arr2 = {1, 2, 3, 4};
    TS_ASSERT(!(arr1 != arr2));

    IntArray arr3 = {1, 2, 3, 4};
    IntArray arr4 = {4, 3, 2, 1};
    TS_ASSERT(arr3 != arr4);

    IntArray arr5 = {1, 2, 3, 4};
    IntArray arr6 = {1, 2, 3};
    TS_ASSERT(arr5 != arr6);
  }

};

#endif
