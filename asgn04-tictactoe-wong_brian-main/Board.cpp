#include "Board.hpp"

#include <iostream>
using namespace std;



void board_reset_size(Board & board, unsigned int size)
{
  // TODO
  board.size = size;
  board.spaces = vector<vector<Space>>(size, vector<Space>(size, Space::BLANK));
  board.next_move = Space::X;
}

bool board_make_move(Board & board, unsigned int row, unsigned int column)
{
  //return true; // TODO
  if (row >= board.size || column >= board.size || board.spaces[row][column] != Space::BLANK) {
    return false;
  }

  board.spaces[row][column] = board.next_move;
  return true;
}

GameStatus board_get_status(const Board & board)
{
  // Check rows for a win
  for (unsigned int i = 0; i < board.size; i++) {
    if (board.spaces[i][0] != Space::BLANK) {
      bool row_win = true;
      for (unsigned int j = 1; j < board.size; j++) {
        if (board.spaces[i][j] != board.spaces[i][0]) {
          row_win = false;
          break;
        }
      }
      if (row_win) {
        return (board.spaces[i][0] == Space::X) ? GameStatus::OVER_X_WON : GameStatus::OVER_O_WON;
      }
    }
  }

  // Check columns for a win
  for (unsigned int i = 0; i < board.size; i++) {
    if (board.spaces[0][i] != Space::BLANK) {
      bool col_win = true;
      for (unsigned int j = 1; j < board.size; j++) {
        if (board.spaces[j][i] != board.spaces[0][i]) {
          col_win = false;
          break;
        }
      }
      if (col_win) {
        return (board.spaces[0][i] == Space::X) ? GameStatus::OVER_X_WON : GameStatus::OVER_O_WON;
      }
    }
  }

  // Check first diagonal for a win (top-left to bottom-right)
  if (board.spaces[0][0] != Space::BLANK) {
    bool diag1_win = true;
    for (unsigned int i = 1; i < board.size; i++) {
      if (board.spaces[i][i] != board.spaces[0][0]) {
        diag1_win = false;
        break;
      }
    }
    if (diag1_win) {
      return (board.spaces[0][0] == Space::X) ? GameStatus::OVER_X_WON : GameStatus::OVER_O_WON;
    }
  }

  // Check second diagonal for a win (top-right to bottom-left)
  if (board.spaces[0][board.size - 1] != Space::BLANK) {
    bool diag2_win = true;
    for (unsigned int i = 1; i < board.size; i++) {
      if (board.spaces[i][board.size - 1 - i] != board.spaces[0][board.size - 1]) {
        diag2_win = false;
        break;
      }
    }
    if (diag2_win) {
      return (board.spaces[0][board.size - 1] == Space::X) ? GameStatus::OVER_X_WON : GameStatus::OVER_O_WON;
    }
  }

  // Check if the board is full (tie)
  for (unsigned int i = 0; i < board.size; i++) {
    for (unsigned int j = 0; j < board.size; j++) {
      if (board.spaces[i][j] == Space::BLANK) {
        return (board.next_move == Space::X) ? GameStatus::PLAYING_X_TURN : GameStatus::PLAYING_O_TURN;
      }
    }
  }

  // If all spaces are filled and no one has won, it's a tie
  return GameStatus::OVER_TIE;
}


void board_print(const Board & board)
{
  // TODO
  for (unsigned int i = 0; i < board.size; i++) {
    for (unsigned int j = 0; j < board.size; j++) {
      if (board.spaces[i][j] == Space::X) {
        cout << "X";
      } else if (board.spaces[i][j] == Space::O) {
        cout << "O";
      } else {
        cout << " ";
      }

      if (j < board.size - 1) {
        cout << "|";
      }
    }

    if (i < board.size - 1) {
      cout << endl;
      for (unsigned int h = 0; h < board.size * 2- 1; h++) {
        cout << "-";
        
      }
      cout << endl;
    }

  }
  cout << endl;
}
