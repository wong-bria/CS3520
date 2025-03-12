#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int
main()
{
  // TODO
  vector<string> lines;
  string str;
  size_t max_length = 0;

  // read lines of text from input
  while (getline(cin, str)) {
    lines.push_back(str);
    if (str.length() > max_length) {
      max_length = str.length();
    }
  }

  // create top border
  cout << string(max_length + 4, '*') << endl;

  for (const string& text : lines) {
    cout << "* " << text;
    cout << string(max_length - text.length(), ' ') << " *" << endl;
  }

  cout << string(max_length + 4, '*') << endl;

  return 0;
}
