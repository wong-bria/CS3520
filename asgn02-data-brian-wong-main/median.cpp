#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int
main()
{
  const string error_message = "Invalid input.";
  
  vector<double> numbers;
  double num;

  // TODO

  // read numbers from input
  while (cin >> num) {
    numbers.push_back(num);
  }

  // Check if no valid numbers were read
  if (numbers.empty()) {
      cout << error_message << endl;
      return 0;
  }

  // Calculate the median
  double median;
  auto n = numbers.size();
  if (n % 2 == 1) {
      // Odd number of elements
      median = numbers[n / 2];
  } else {
      // Even number of elements
      median = (numbers[n / 2] + numbers[n / 2 - 1]) / 2.0;
  }

  cout << fixed << setprecision(2) << median << endl;

  return 0;
}
