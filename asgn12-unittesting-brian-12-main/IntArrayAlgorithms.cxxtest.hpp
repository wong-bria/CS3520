#ifndef INT_ARRAY_ALGORITHMS_CXXTEST_HPP
#define INT_ARRAY_ALGORITHMS_CXXTEST_HPP

#include <cxxtest/TestSuite.h>
#include <iostream>
#include "IntArray.hpp"
#include "IntArrayAlgorithms.hpp"

class IntArrayAlgorithmsTestSuite : public CxxTest::TestSuite
{
public:

  void test_swap() {
    IntArray a = {1, 2, 3};
    IntArray b = {4, 5};
    IntArrayAlgorithms::swap(a, b);
    TS_ASSERT_EQUALS(a, IntArray({4, 5}));
    TS_ASSERT_EQUALS(b, IntArray({1, 2, 3}));

    IntArray c = {2};
    IntArray d = {-2};
    IntArrayAlgorithms::swap(c, d);
    TS_ASSERT_EQUALS(c, IntArray({-2}));
    TS_ASSERT_EQUALS(d, IntArray({2}));
  }

  void test_contains() {
    IntArray a = {1, 2, 3};
    TS_ASSERT_EQUALS(IntArrayAlgorithms::contains(a, 1), true);
    TS_ASSERT_EQUALS(IntArrayAlgorithms::contains(a, 2), true);
    TS_ASSERT_EQUALS(IntArrayAlgorithms::contains(a, 3), true);
    TS_ASSERT_EQUALS(IntArrayAlgorithms::contains(a, 0), false);
    TS_ASSERT_EQUALS(IntArrayAlgorithms::contains(a, 9), false);

    IntArray b = {-2, 0, 0, 0};
    TS_ASSERT_EQUALS(IntArrayAlgorithms::contains(b, -2), true);
    TS_ASSERT_EQUALS(IntArrayAlgorithms::contains(b, 0), true);
    TS_ASSERT_EQUALS(IntArrayAlgorithms::contains(b, 2), false);
  }

  void test_sort() {
    IntArray a = {4, 7, 3, 1, 8};
    IntArrayAlgorithms::sort(a);
    TS_ASSERT_EQUALS(a, IntArray({1, 3, 4, 7, 8}));

    IntArray b = {1, 2, 3, 4};
    IntArrayAlgorithms::sort(b);
    TS_ASSERT_EQUALS(b, IntArray({1, 2, 3, 4}));

    IntArray c = {0, 2, -2, 0};
    IntArrayAlgorithms::sort(c);
    TS_ASSERT_EQUALS(c, IntArray({-2, 0, 0, 2}));
  }

  void test_sum() {
    TS_ASSERT_EQUALS(IntArrayAlgorithms::sum(IntArray({})), 0);
    TS_ASSERT_EQUALS(IntArrayAlgorithms::sum(IntArray({1})), 1);
    TS_ASSERT_EQUALS(IntArrayAlgorithms::sum(IntArray({1, -1})), 0);
    TS_ASSERT_EQUALS(IntArrayAlgorithms::sum(IntArray({1, 2, 3})), 6);
  }

  void test_product() {
    TS_ASSERT_EQUALS(IntArrayAlgorithms::product(IntArray({})), 1);
    TS_ASSERT_EQUALS(IntArrayAlgorithms::product(IntArray({1})), 1);
    TS_ASSERT_EQUALS(IntArrayAlgorithms::product(IntArray({1, -1})), -1);
    TS_ASSERT_EQUALS(IntArrayAlgorithms::product(IntArray({1, 2, 3})), 6);
  }

};

#endif
