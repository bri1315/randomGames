//plays tic tac toe with either the computer and a human or
//two different humans
# include <iostream>
#include <ctime>
#include <random>

using namespace std;

//array of character
char board[9] = {' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' '};
int winningCountForComp = 0;
int winningCountForOne = 0 ;
int winningCountForTwo = 0;
//initiates a game with the computer and a human player
void computerAndPlayer();
//Initiates a game with a player and another playes
void playerAndPlayer();
//shows the board
void showBoard();
//creates the computer choice
void computerChoice();
//takes in player one choice
void playerOneChoice();
//takes in player two choice
void playerTwoChoice();
//takes a view if there is a winner and if the game should continue or not continue
int countingBoard(char);
//Checks to see if there is a winner to be crowned
char checkingWinner();

int main(){
  int option;

    cout << "1. Play against computer" << endl;
    cout << "2. Play against a friend" << endl;
    cout << "3. Quit" << endl;
    cin >> option;
    switch(option){
      case 1:
        computerAndPlayer();
        break;
      case 2:
        playerAndPlayer();
        break;
      case 3:
        cout << "Goodbye Tic Tac Tow friends" << endl;
      default:
        cout << "invalid option" << endl;

  //resetting the count after finishing a game
  //compWin = 0;
  //playerOneWin = 0;
  //playerTwoWin = 0;

  return 0;
}

void showBoard(){
  cout << "   " << "    |   " << "    |   " << endl;
  cout << "   " << board[0] << "   |   " << board[1] << "   |   " << board[2] << endl;
  cout << "   " << "    |   " << "    |   " << endl;
  cout << "-----------------------" << endl;

  cout << "   " << "    |   " << "    |   " << endl;
  cout << "   " << board[3] << "   |   " << board[4] << "   |   " << board[5] << endl;
  cout << "   " << "    |   " << "    |   " << endl;
  cout << "-----------------------" << endl;

  cout << "   " << "    |   " << "    |   " << endl;
  cout << "   " << board[6] << "   |   " << board[7] << "   |   " << board[8 ] << endl;
  cout << "   " << "    |   " << "    |   " << endl;
  cout << "-----------------------" << endl;
}

void computerAndPlayer(){
  string playerName;
  cout << "Enter your user name to play: ";
  cin >> playerName;
  while(true){
    system("clear");
    showBoard();
    if(countingBoard('X') == countingBoard('O')){
      cout << playerName << " Turn" << endl;
      playerOneChoice();
    }
    else{
       cout << "Computers turn" << endl;
       computerChoice();
    }
    char winner = checkingWinner();
    if(winner == 'X'){
      system("clear");
      showBoard();
      cout << playerName << " you have won the game" << endl;
      winningCountForOne+=1;
      cout << playerName << "Has won: " << winningCountForOne << endl;
      cout << "Computer has won: " << winningCountForComp << endl;
      break;
    }
    else if(winner == 'O'){
      system("clear");
      showBoard();
      cout << "Computer has won the game" << endl;
      winningCountForComp+=1;
      cout << playerName << " Has won: " << winningCountForOne << endl;
      cout << "Computer has won: " << winningCountForComp << endl;
      break;
    }
    else if(winner == 'D'){
      cout << "Its a draw" << endl;
      cout << playerName << " Has won: " << winningCountForOne << endl;
      cout << "Computer has won: " << winningCountForComp << endl;
      break;
    }
  }
}
void playerAndPlayer(){
  string playerNameOne, playerNameTwo;
  cout << "Enter your user name to play as player one: ";
  cin >> playerNameOne;

  cout << "Enter your user name to play as player one: ";
  cin >> playerNameTwo;

  while(true){
    system("clear");
    showBoard();
    if(countingBoard('X') == countingBoard('O')){
      cout << playerNameOne << " Turn" << endl;
      playerOneChoice();
    }
    else{
       cout << playerNameTwo << " Turn" << endl;
       playerTwoChoice();
    }
    char winner = checkingWinner();
    if(winner == 'X'){
      system("clear");
      showBoard();
      cout << playerNameOne << " you have won the game" << endl;
      winningCountForOne=+1;
      cout << playerNameOne << " has won: " << winningCountForOne;
      cout << playerNameTwo << " has won: " << winningCountForTwo;
      break;
    }
    else if(winner == 'O'){
      system("clear");
      showBoard();
      cout << playerNameTwo <<" has won the game" << endl;
      winningCountForTwo=+1;
      cout << playerNameOne << " has won: " << winningCountForOne;
      cout << playerNameTwo << " has won: " << winningCountForTwo;
      break;
    }
    else if(winner == 'D'){
      cout << "Its a draw" << endl;
      cout << playerNameOne << " has won: " << winningCountForOne;
      cout << playerNameTwo << " has won: " << winningCountForTwo;
      break;
    }
  }
}

void computerChoice(){
  srand(time(0));
  int compChoice;
  //validating the choice to make sure the position isnt taken
  do{
    compChoice = rand()%10;
  }while(board[compChoice] != ' ');
  board[compChoice] = 'O';
}

void playerOneChoice(){
  while(true){
    cout << "Select your position 1 - 9: ";
    int userChoice;
    cin >> userChoice;
    userChoice--;
    //validation for user choice
    if(userChoice < 0 || userChoice > 8){
      cout << "Invalid choice\nEnter a number between 1-9:";
    }
    else if(board[userChoice] != ' '){
      cout << "Spot is alreadt taken\nPlease pick an empty spot" << endl;
    }
    else{
      board[userChoice] = 'X';
      break;
    }
  }
}

void playerTwoChoice(){
  while(true){
    cout << "Select your position 1 - 9: ";
    int userChoice;
    cin >> userChoice;
    userChoice--;
    //validation for user choice
    if(userChoice < 0 || userChoice > 8){
      cout << "Invalid choice\nEnter a number between 1-9:";
    }
    else if(board[userChoice] != ' '){
      cout << "Spot is alreadt taken\nPlease pick an empty spot" << endl;
    }
    else{
      board[userChoice] = 'O';
      break;
    }
  }
}

int countingBoard(char choice){
  int total = 0;
  for (int i =0; i < 9; i++){
    if (board[i] == choice)
      total += 1 ;
  }
  return total;
}

char checkingWinner(){
  //check for vertical wins
  if(board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
    return board[0];
  if(board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
    return board[1];
  if(board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
      return board[2];
  //checks for horizontal wins
  if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
    return board[0];
  if(board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
    return board[3];
  if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
      return board[6];
  //checks diognoals wins
  if(board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
    return board[0];
  if(board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
    return board[2];
  if(countingBoard('X') + countingBoard('O') < 9)
    return 'C';
  else
    //d meaning draw
    return 'D';
}
