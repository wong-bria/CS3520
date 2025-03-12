#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int
main()
{
  const string prompt = "Enter row and column:";

  const unsigned int grid_size = 5;
  vector<vector<bool>> grid(grid_size, vector<bool>(grid_size, false));

  // TODO
  unsigned int row;
  unsigned int col;

  while (true) {
    cout << prompt << endl;

    if (!(cin >> row >> col)) {
      break;
    }

    if (row >= grid_size || col >= grid_size) {
      break;
    }

    grid[row][col] = true;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  for (unsigned int r = 0; r < grid_size; ++r) {
    for (unsigned int c = 0; c < grid_size; ++c) {
      if (grid[r][c]) {
        cout << "X";
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }

  return 0;
}
