#include "Game.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <set>
#include <map>
using namespace std;

const char *msg_filename = "Please enter a world file:";
const char *msg_direction = "Please enter a direction to move (wasd or space):";

const char *errmsg_world_file = "Error reading world file.";
const char *errmsg_world_shape = "Invalid world shape.";
const char *errmsg_world_char = "Invalid world character.";
const char *errmsg_world_player_missing = "World missing player.";
const char *errmsg_world_player_multiple = "World has multiple players.";

const char *errmsg_direction = "Invalid direction input.";

void Game::input_and_read_world_from_file(const EntityCounter &counter)
{
    // TODO: prompt user for filename
    cout << msg_filename << endl;
    string worldname;
    getline(cin, worldname);
    string file_path = "world/" + worldname + ".txt";

    ifstream world_file(file_path);
    if (!world_file)
    {
        // if there is an error opening the file, throws an exception.
        throw runtime_error(errmsg_world_file);
    }

    // TOOD: read and validate world from file
    vector<string> world_lines;
    string line;
    size_t expected_length = 0;

    while (getline(world_file, line))
    {
        // if there is an unrecognized character, throws an exception.
        if (line.empty() || line.find_first_not_of("prx.") != string::npos)
        {
            throw runtime_error(errmsg_world_char);
        }

        // If it's the first line, set the expected length
        if (world_lines.empty())
        {
            expected_length = line.length();
        }
        else
        {
            if (line.length() != expected_length)
            {
                // if the world is not a rectangle, throws an exception.
                throw runtime_error(errmsg_world_shape);
            }
        }

        // Store the valid line
        world_lines.push_back(line);
    }

    // if the world is is empty, throws an exception.
    if (world_lines.empty())
    {
        throw runtime_error(errmsg_world_shape);
    }

    size_t player_count = 0;
    size_t player_row = 0;
    size_t player_col = 0;

    // Find player position and count players
    for (size_t r = 0; r < world_lines.size(); ++r)
    {
        size_t found_pos = world_lines[r].find('p');
        if (found_pos != string::npos)
        {
            player_row = r;
            player_col = found_pos;
            player_count++;
            // Check if more than one player is found
            if (player_count > 1)
            {
                throw runtime_error(errmsg_world_player_multiple);
            }
        }
    }

    // If there are no players, throw an exception
    if (player_count == 0)
    {
        throw runtime_error(errmsg_world_player_missing);
    }

    // Create player entity here
    m_player.push_back(Player(Cell{player_row, player_col}, counter));

    // Fill in m_robotsAndDebris based on the world_lines
    for (size_t r = 0; r < world_lines.size(); ++r)
    {
        for (size_t c = 0; c < world_lines[r].length(); ++c)
        {
            char cell = world_lines[r][c];
            if (cell == 'r')
            {
                // Create a RobotOrDebris object for a robot
                m_robotsAndDebris.emplace_back(RobotOrDebris(Cell{r, c}, false, counter)); // false indicates it's a robot
            }
            else if (cell == 'x')
            {
                // Create a RobotOrDebris object for debris
                m_robotsAndDebris.emplace_back(RobotOrDebris(Cell{r, c}, true, counter)); // true indicates it's debris
            }
        }
    }

    m_worldRows = world_lines.size();
    m_worldCols = expected_length;
}

void Game::display_world() const
{
    // Create a grid filled with empty cells ('.') of size m_worldRows x m_worldCols
    vector<string> grid(m_worldRows, string(m_worldCols, '.'));

    // Place the player on the grid if present
    if (!m_player.empty())
    {
        const Cell &player_cell = m_player[0].get_cell();
        size_t player_row = player_cell.row;
        size_t player_col = player_cell.col;

        if (player_row < m_worldRows && player_col < m_worldCols)
        {
            grid[player_row][player_col] = 'p';
        }
    }

    // Place robots and debris on the grid
    for (const auto &entity : m_robotsAndDebris)
    {
        const Cell &entity_cell = entity.get_cell();
        size_t entity_row = entity_cell.row;
        size_t entity_col = entity_cell.col;

        if (entity_row < m_worldRows && entity_col < m_worldCols)
        {
            if (entity.is_debris())
            {
                grid[entity_row][entity_col] = 'x';
            }
            else
            {
                grid[entity_row][entity_col] = 'r';
            }
        }
    }

    // Output the grid to display the world
    for (const auto &row : grid)
    {
        cout << row << endl;
    }
}

GameStatus
Game::input_next_move_and_update()
{
    // TODO: prompt user and input direction
    cout << msg_direction << endl;
    string input;
    getline(cin, input);

    // TODO: update player and robot locations
    Direction direction;
    if (input == "w")
    {
        direction = Direction::north;
    }
    else if (input == "s")
    {
        direction = Direction::south;
    }
    else if (input == "d")
    {
        direction = Direction::east;
    }
    else if (input == "a")
    {
        direction = Direction::west;
    }
    else if (input == " ")
    {
        direction = Direction::none;
    }
    else
    {
        throw invalid_argument(errmsg_direction);
    }

    if (!m_player.empty())
    {
        m_player[0].update(direction, m_worldRows, m_worldCols);
    }

    for (auto &entity : m_robotsAndDebris)
    {
        if (!entity.is_debris())
        {
            entity.update(m_player[0]);
        }
    }

    // Custom comparator for Cell objects
    auto cellComparator = [](const Cell &lhs, const Cell &rhs)
    {
        // Define the comparison logic, for example, compare row first, then column
        if (lhs.row == rhs.row)
        {
            return lhs.col < rhs.col;
        }
        return lhs.row < rhs.row;
    };

    // Use the custom comparator for the map
    map<Cell, int, decltype(cellComparator)> cellOccupancy(cellComparator);

    // Update cell occupancy based on entities' positions
    for (const auto &entity : m_robotsAndDebris)
    {
        cellOccupancy[entity.get_cell()]++;
    }
    if (!m_player.empty())
    {
        cellOccupancy[m_player[0].get_cell()]++;
    }

    // Handle collisions for robots/debris
for (auto &entry : cellOccupancy)
{
    if (entry.second > 1) // Check if more than one entity occupies the cell
    {
        Cell collidedCell = entry.first; // Get the cell with collision
        bool firstEntity = true;         // Flag to track the first entity in the collision

        // Temporary vector to hold indices of entities to be removed
        std::vector<int> entitiesToRemove;

        for (size_t i = 0; i < m_robotsAndDebris.size(); ++i)
        {
            auto &entity = m_robotsAndDebris[i]; // Get current entity
            if (entity.get_cell() == collidedCell) // Check if the entity is in the colliding cell
            {
                if (firstEntity)
                {
                    // Check if the entity is the player
                    if (entry.second == 2 && !m_player.empty() && entity.get_cell() == m_player[0].get_cell())
                    {
                        // If it's the player, remove the player
                        m_player.clear(); // Player is removed
                    }
                    else
                    {
                        // Convert the entity into debris if it's not the player
                        entity.make_debris();
                    }

                    firstEntity = false; // Set flag to false after processing the first entity
                }
                else
                {
                    if (!m_player.empty() && entity.get_cell() == m_player[0].get_cell()) {
                        m_player.clear();
                    }
                    // If not the first entity, mark it for removal
                    entitiesToRemove.push_back(i);
                }
            }
        }

        // Remove entities marked for removal in reverse order
        for (int index = entitiesToRemove.size() - 1; index >= 0; --index)
        {
            m_robotsAndDebris.erase(m_robotsAndDebris.begin() + entitiesToRemove[index]);
        }
    }
}

    // TODO: determine game status
    // Determine game status
    if (m_player.empty())
    {
        return GameStatus::player_lost;
    }
    bool robotsLeft = any_of(m_robotsAndDebris.begin(), m_robotsAndDebris.end(),
                             [](const RobotOrDebris &entity)
                             { return !entity.is_debris(); });
    if (!robotsLeft)
    {
        return GameStatus::player_won;
    }

    return GameStatus::playing;
}