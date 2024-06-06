#include <iostream>
#include <vector>

//checks if the users want to play again
char play_again()
{
  char play_again;
  std::cout << "Would you like to play again?\n\nType y for yes and n for no\n\n";
  std::cin >> play_again;
  play_again = tolower(play_again);
  return play_again;
}
//prints hello message
void hello()
{
  std::string message = "Welcome this program allows you to take turns playing tic-tac-toe with another person\n\n";
  std::cout << message;
}

//prints goodbye message
void goodbye()
{
  std::string message = "Thank you for playing!!\n\n";
  std::cout << message;
}

//intializes a game board
std::vector<char> new_board()
{
  std::vector<char> board;
  for(int i = 0; i < 9; i++)
    {
      board.push_back('_');
    }
  return board;
}

//Prints current game board
void disply_board(std::vector<char> board)
{
  std::cout << "Here is the current board:\n";
  for(int i = 0; i < 9; i++)
    {
      if(i  == 2 || i  == 5 || i  == 8)
      {
        std::cout << board[i];
        std::cout << "\n";

      }
      else
      {
        std::cout << board[i];
      }
    }
  std::cout << "\n\n";
}

int get_space(std::vector<char> board)
{
  std::cout << "Enter the space you want to go a number 1 - 9 below:\n";
    int num = 0;
    bool bad_num;
    bool filled;
  
  do
    {
      std::cin >> num;
      
      //checks if space exist
      if(num < 1 || num > 9)
      {
        std::cout << "You cant go there\n";
        std::cout << "Enter the space you want to go a number 1 - 9 below:\n";
        bad_num = true;
      }
      else
      {
        bad_num = false;
      }

      num--;
      //checks if space has been filled
      if(board[num] == 'X' || board[num] == 'O')
        {
          std::cout << "You cant go there\n";
          std::cout << "Enter the space you want to go a number 1 - 9 below:\n";
          bad_num = true;
        }
        else
        {
          bad_num = false;
        }
    }
  while (bad_num == true);
  return num;
}

//tells whether to change space to X or O
char check_turn(int turn)
{
  if(turn % 2)
  {
    return 'O';
  }
  else
  {
    return 'X';
  }
}

//fix
//checks if game should be over
bool end_game(std::vector<char> board, int turns)
{
  //horizontal wins
  if((board[0] == board[1]) && (board[0] == board[2]) && (board[0] != '_'))
  {
    std::cout << "\n" << board[0] << " Wins!!!\n\n";
    return true;
  }
  else if ((board[3] == board[4]) && (board[3] == board[5]) && (board[3] != '_'))
  {
     std::cout << "\n" << board[3] << " Wins!!!\n\n";
     return true;
  }
  else if ((board[6] == board[7] ) && (board[6] == board[8]) && (board[6] != '_'))
  {
    std::cout << "\n" << board[6] << " Wins!!!\n\n";
    return true;
  }
    
  //vertical cases
  else if((board[0] == board[3]) && (board[0] == board[6]) && (board[0] != '_'))
  {
    std::cout << "\n" << board[0] << " Wins!!!\n\n";
    return true;
  }
  else if((board[1] == board[4]) && (board[1] == board[7]) && (board[1]  != '_'))
  {
    std::cout << "\n" << board[1] << " Wins!!!\n\n";
    return true;
  }
  else if ((board[2] == board[5]) && (board[2] == board[8]) && (board[2] != '_'))
  {
    std::cout << "\n" << board[2] << " Wins!!!\n\n";
    return true;
  }
    
    //Diagonal cases
  else if ((board[0] == board[4]) && ( board[0] == board[8]) && ( board[0] != '_'))
  {
    std::cout << "\n" << board[0] << " Wins!!!\n\n";
    return true;
  }
  else if ((board[2] == board[4]) && ( board[2] == board[8]) && (board[2] != '_'))
  {
    std::cout << "\n" << board[2] << " Wins!!!\n\n";
    return true;
  }
  //tie
  else if(turns >= 11)
  {
    std::cout << "\n" << "Tie...\n\n";
    return true;
  }
  else
  {
    return false;
  }
}
