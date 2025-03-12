#include "GameLogic.hpp"

#include "Board.hpp"
#include "Util.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;



const string PROMPT_BOARD_SIZE = "Input board size (2-5):";
const string PROMPT_MOVE_X = "Enter row and column for X:";
const string PROMPT_MOVE_O = "Enter row and column for O:";
const string PROMPT_TIE = "Tie game!";
const string PROMPT_WIN_X = "X wins!";
const string PROMPT_WIN_O = "O wins!";
const string MESSAGE_ERROR = "Invalid input.";



// exit with success.
void success_exit() {
  exit(0);
}

// print an error message and exit with error.
void error_exit() {
  cout << MESSAGE_ERROR << endl;
  exit(-1);
}



void game_input_board_size(Board & board) {
  unsigned int size;
  cout << PROMPT_BOARD_SIZE << endl;
  cin >> size;

  if (cin.fail() || size < 2 || size > 5) {
    error_exit();
    }

  board_reset_size(board, size);
  }



void game_display_board_and_input_next_move(Board & board) {
  board_print(board);

  GameStatus status = board_get_status(board);


  if (status == GameStatus::OVER_TIE) {
    cout << PROMPT_TIE << endl;
    success_exit();
  } else if (status == GameStatus::OVER_X_WON) {
    cout << PROMPT_WIN_X << endl;
    success_exit();
  } else if (status == GameStatus::OVER_O_WON) {
    cout << PROMPT_WIN_O << endl;
    success_exit();
  }

  
  if (board.next_move == Space::X) {
    cout << PROMPT_MOVE_X << endl;
  } else {
    cout << PROMPT_MOVE_O << endl;
  }

  unsigned int row, col;
 
  cin >> row >> col;

  if (cin.fail() || row >= board.size || col >= board.size || !board_make_move(board, row, col)) {
    error_exit();
  }

  status = board_get_status(board);

    board.next_move = (board.next_move == Space::X) ? Space::O : Space::X;

}
