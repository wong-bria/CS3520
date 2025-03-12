#include "IntArrayAlgorithms.hpp"
#include "IntArray.hpp"
using namespace std;

void IntArrayAlgorithms::swap(IntArray & lhs, IntArray & rhs) {
  int* tempArr = lhs.m_arr;
  lhs.m_arr = rhs.m_arr;
  rhs.m_arr = tempArr;

  size_t tempSize = lhs.m_sz;
  lhs.m_sz = rhs.m_sz;
  rhs.m_sz = tempSize;
}

bool IntArrayAlgorithms::contains(const IntArray & arr, int val) {
  for (size_t i = 0; i < arr.size(); ++i) {
    if (arr[i] == val) {
      return true;
    }
  }
  return false;
}

void IntArrayAlgorithms::sort(IntArray & arr) {
  // TODO: implement any sort algorithm of your choice (e.g. selection sort or insertion sort)
  for (size_t i = 1; i < arr.size(); ++i) {
    int key = arr[i];
    size_t j = i;

    while (j > 0 && arr[j-1] > key) {
      arr[j] = arr[j - 1];
      --j;
    }
    arr[j] = key;
  }
}

int IntArrayAlgorithms::sum(const IntArray & arr) {
  int total = 0;
  for (size_t i = 0; i < arr.size(); ++i) {
    total += arr[i];
  }
  return total;
}

int IntArrayAlgorithms::product(const IntArray & arr) {
  int total = 1;
  for (size_t i = 0; i < arr.size(); ++i) {
    total *= arr[i];
  }
  return total;
}
