#include "Pathfinding.hpp"
#include "Point.hpp"
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <vector>
using namespace std;



// utility function to compute a path from start to goal given the came_from information
void came_from_to_path(const map<Point, Point> & came_from, const Point & start, const Point & goal, list<Point> & path) {
  // TODO: reconstruct path
  if (came_from.find(goal) == came_from.end()) {
        path.clear(); // No path found
        return;
    }

    Point current = goal;
    while (current != start) {
        path.push_front(current);
        current = came_from.at(current);
    }
    path.push_front(start);
}



void pathfind_bfs(const World & w, list<Point> & path) {
  path.clear();

  deque<Point> frontier;
  map<Point, Point> came_from;

  // TODO: implement BFS using frontier and came_from

  // init the BFS by pushing starting point into frontier
    frontier.push_back(w.start);
    came_from[w.start] = w.start;  // mark start as its own predecessor

    // main BFS loop
    while (!frontier.empty()) {
        Point current = frontier.front();
        frontier.pop_front();

        if (current == w.goal) {
            break;
        }

        // get neighbors of current point
        set<Point> neighbors;
        w.get_neighbors(current, neighbors);

        for (const Point & next : neighbors) {
            // if neighbor has not been visited yet
            if (came_from.find(next) == came_from.end()) {
                frontier.push_back(next); 
                came_from[next] = current;
            }
        }
    }

  came_from_to_path(came_from, w.start, w.goal, path);
}



// point for heap
struct PriorityPoint {
  double priority;
  Point point;
};

// comparison for heap - lowest first!
bool operator<(const PriorityPoint & lhs, const PriorityPoint & rhs) {
  return lhs.priority > rhs.priority;
}

// heuristic for A*
double heuristic(const Point & a, const Point & b) {
  return abs(a.row - b.row) + abs(a.col - b.col);
}

// assume cost of moving is always 1
const double move_cost = 1.0;


void pathfind_astar(const World & w, list<Point> & path) {
  path.clear();

  vector<PriorityPoint> frontier;
  map<Point, Point> came_from;
  map<Point, double> cost_so_far;

  // TODO: implement A* using frontier, came_from and cost_so_far
  frontier.push_back({0, w.start});
  push_heap(frontier.begin(), frontier.end());

  // init starting point in the maps
  came_from[w.start] = w.start;
  cost_so_far[w.start] = 0;

  while (!frontier.empty()) {
        // pop current node with lowest priority
        pop_heap(frontier.begin(), frontier.end());
        Point current = frontier.back().point;
        frontier.pop_back();

        // exit if the goal is reached
        if (current == w.goal) {
            break;
        }

        // get neighbors of current node
        set<Point> neighbors;
        w.get_neighbors(current, neighbors);

        for (const Point & next : neighbors) {
            double new_cost = cost_so_far[current] + move_cost;

            // if neighbor is not in the cost map or the new cost is lower
            if (cost_so_far.find(next) == cost_so_far.end() || new_cost < cost_so_far[next]) {
                cost_so_far[next] = new_cost;
                double priority = new_cost + heuristic(next, w.goal);
                frontier.push_back({priority, next});
                push_heap(frontier.begin(), frontier.end());

                came_from[next] = current;
            }
        }
    }



  came_from_to_path(came_from, w.start, w.goal, path);
}
