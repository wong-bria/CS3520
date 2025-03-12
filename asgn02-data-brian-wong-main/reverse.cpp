#include <iostream>
#include <string>
#include <vector>
using namespace std;

int
main()
{
  // TODO
  vector<string> lines;
  string str;

  // Reads lines of text from input
  while (getline(cin, str)) {
    lines.push_back(str);
  }

  // print lines in reverse order with characters reversed
  for (int i = lines.size() - 1; i >= 0; --i) {
    // reverse characters in current line
    for (int j = lines[i].length() - 1; j >= 0; --j) {
      cout << lines[i][j];
    }
    cout << endl;
  }

  return 0;
}
