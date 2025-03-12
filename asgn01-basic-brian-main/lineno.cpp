#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int
main()
{
  // TODO
  string input;
  int line = 1;

 while(getline(cin, input)) {
    cout << setw(3) << line << ": " << input << endl;
    ++line;
  }

  return 0;
}
