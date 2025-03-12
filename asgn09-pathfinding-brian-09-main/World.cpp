#include "World.hpp"
#include <algorithm>
#include <iostream>
#include <random>
using namespace std;


void World::initialize(int worldId) {
  mt19937 mt_rand(worldId);

  size = 10 + int(mt_rand() % 10);

  start = { int(mt_rand() % size), int(mt_rand() % size) };
  do {
    goal = { int(mt_rand() % size), int(mt_rand() % size) };
  } while(start == goal);

  int nblocks = size * size / 3;
  for (int ii = 0; ii < nblocks; ++ ii) {
    Point block = { int(mt_rand() % size), int(mt_rand() % size) };
    if (block != start && block != goal) {
      blocks.insert(block);
    }
  }
}

void World::display(const list<Point> & path) const {
  // TODO: display world
  // Create a set from the path for quick lookup
    set<Point> path_set(path.begin(), path.end());

    // Iterate over each row in the world
    for (int row = 0; row < size; ++row) {
        // Iterate over each column in the current row
        for (int col = 0; col < size; ++col) {
            Point current_point = {row, col};

            // Check if the current point is the start, goal, a block, or part of the path
            if (current_point == start) {
                if (path_set.find(current_point) != path_set.end()) {
                    cout << "s";  // Start in the path
                } else {
                    cout << "S";  // Start not in the path
                }
            } else if (current_point == goal) {
                if (path_set.find(current_point) != path_set.end()) {
                    cout << "g";  // Goal in the path
                } else {
                    cout << "G";  // Goal not in the path
                }
            } else if (blocks.find(current_point) != blocks.end()) {
                if (path_set.find(current_point) != path_set.end()) {
                    cout << "x";  // Block in the path
                } else {
                    cout << "X";  // Block not in the path
                }
            } else {
                if (path_set.find(current_point) != path_set.end()) {
                    cout << ".";  // Point in the path
                } else {
                    cout << " ";  // Empty space not in the path
                }
            }

            // Only print space if it's not the last column in the row
            if (col < size - 1) {
                cout << " ";
            }
        }
        // Move to the next line after each row
        cout << endl;
    }
}

void World::get_neighbors(const Point & p, set<Point> & neighbors) const {
  neighbors.clear();

  // TODO: fill in neighbors
  vector<Point> directions = {
    {p.row - 1, p.col}, // Up
    {p.row + 1, p.col}, // Down
    {p.row, p.col - 1}, // Left
    {p.row, p.col + 1}  // Right
  };

  // Iterate through each potential direction
  for (const Point& neighbor : directions) {
    // Check if the neighbor is within the bounds of the world
    if ((neighbor.row >= 0) && (neighbor.row < size)
        && (neighbor.col >= 0) && neighbor.col < size) {   
        // Ensure row is within bounds
        // Ensure col is within bounds

      // Check if it's not a block and it's not the point itself
      if (blocks.find(neighbor) == blocks.end()) {

        if (!(p.row < 0 || p.row >= size || p.col < 0 || p.col >= size) && blocks.find(p) == blocks.end()) {
           neighbors.insert(neighbor);  
        }
      }
    }
  }
}
