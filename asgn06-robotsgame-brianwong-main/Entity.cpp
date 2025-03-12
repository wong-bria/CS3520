#include "Entity.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;



//Player::Player(const Cell & cell, const EntityCounter & counter): m_counter(nullptr) // TODO
Player::Player(const Cell & cell, const EntityCounter & counter)
    : m_cell(cell), m_counter(counter)
{
  // TODO
  m_counter.increment();
}

//Player::Player(const Player & other): m_counter(nullptr) // TODO
Player::Player(const Player & other)
    : m_cell(other.m_cell), m_counter(other.m_counter)
{
  // TODO
  m_counter.increment();
}

Player::~Player()
{
  // TODO
  m_counter.decrement();
}

void
Player::update(Direction input_direction, size_t worldRows, size_t worldCols)
{
  // TODO
  switch (input_direction) {
        case Direction::north:
            if (m_cell.row > 0) --m_cell.row;
            break;
        case Direction::south:
            if (m_cell.row < worldRows - 1) ++m_cell.row;
            break;
        case Direction::west:
            if (m_cell.col > 0) --m_cell.col;
            break;
        case Direction::east:
            if (m_cell.col < worldCols - 1) ++m_cell.col;
            break;
        case Direction::none:
            // Do nothing
            break;
    }
}

const Cell &
Player::get_cell() const
{
  return m_cell;
}



//RobotOrDebris::RobotOrDebris(const Cell & cell, bool isDebris, const EntityCounter & counter): m_counter(nullptr) // TODO
RobotOrDebris::RobotOrDebris(const Cell & cell, bool isDebris, const EntityCounter & counter)
    : m_cell(cell), m_isDebris(isDebris), m_counter(counter)
{
  // TODO
  m_counter.increment();
}

//RobotOrDebris::RobotOrDebris(const RobotOrDebris & other): m_counter(nullptr) // TODO
RobotOrDebris::RobotOrDebris(const RobotOrDebris & other)
    : m_cell(other.m_cell), m_isDebris(other.m_isDebris), m_counter(other.m_counter)
{
  // TODO
  m_counter.increment();
}

RobotOrDebris::~RobotOrDebris()
{
  // TODO
  m_counter.decrement();
}

void
RobotOrDebris::update(const Player & player)
{
  // TODO
  if (m_isDebris) return; // Debris does not move

    const Cell & playerCell = player.get_cell();

    // Check if the robot is in the same cell as the player
    if (m_cell == playerCell) return;

    // Movement preference based on the sum of row and column
    bool preferRow = ((m_cell.row + m_cell.col) % 2 == 0);

    // If the robot is in the same row or column, move accordingly
    if (m_cell.row == playerCell.row) {
        m_cell.col += (m_cell.col < playerCell.col) ? 1 : -1;
    } else if (m_cell.col == playerCell.col) {
        m_cell.row += (m_cell.row < playerCell.row) ? 1 : -1;
    } else {
        // Move based on preference
        if (preferRow) {
            m_cell.row += (m_cell.row < playerCell.row) ? 1 : -1;
        } else {
            m_cell.col += (m_cell.col < playerCell.col) ? 1 : -1;
        }
    }
}

const Cell &
RobotOrDebris::get_cell() const
{
  return m_cell;
}

void
RobotOrDebris::make_debris()
{
  m_isDebris = true;
}

bool
RobotOrDebris::is_debris() const
{
  return m_isDebris;
}
