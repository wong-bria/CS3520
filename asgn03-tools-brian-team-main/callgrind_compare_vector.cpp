#include <iostream>
#include <vector>
using namespace std;

const int iterations = 10000000;

void run_vector_at() {
  // TODO
  vector<int> vec(iterations);
  for (int i = 0; i < iterations; ++i) {
    vec[i] = i;
  }

  for (int i = 0; i < iterations; ++i) {
    int value = vec.at(i);
  }
}

void run_vector_brackets() {
  // TODO
  vector<int> vec(iterations);
  for (int i = 0; i < iterations; ++i) {
    vec[i] = i;
  }

  for (int i = 0; i < iterations; ++i) {
    int value = vec[i];
  }
}

int main() {
  run_vector_at();
  run_vector_brackets();
}
