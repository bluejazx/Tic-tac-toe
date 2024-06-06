#include <iostream>
#include <vector>

#include "game.hpp"

int main()
{
  bool game_over;
  int turn = 1;
  int space;
  char again;
  hello();
  
  do
  {
    std::vector<char> game_board = new_board();
    
    do
    {
      //creates then displays a fresh game board;
      disply_board(game_board);
  
      //gets space from player then turns that space into X or O and increase turn
      space = get_space(game_board);
      game_board[space] = check_turn(turn);
      
      //checks if game has been won startin turn 4
      turn++;
    }
    while (end_game(game_board, turn) == false);
    disply_board(game_board);
    again = play_again();
  }
    while(again == 'y');
    goodbye();
}