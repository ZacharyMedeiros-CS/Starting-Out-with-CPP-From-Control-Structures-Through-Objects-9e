//
// This program simulates a round of Rock, Paper, Scissors, between 
// the user and computer. The program is modular in design, making
// use of functions to handle major tasks.
//

/*
 Chapter 06 Programming Challenge 24 Rock, Paper, Scissors Game

 Write a program that lets the user play the game Rock, Paper, Scissors against the
 computer. The program should work as follows:

 1. When the program begins, a random number in the range of 1 through 3 is gener-
    ated. If the number is 1, then the computer has chosen rock. If the number is 2, then
    the computer has chosen paper. If the number is 3, then the computer has chosen 
    scissors. (Don't display the computer's choice yet.)
 2. The user enters his or her choice of "rock", "paper", "scossors" at the keyboard.
    (You can use a menu if you prefer.)
 3. The computer's choice is displayed.
 4. A winner is selected according to the following rules:

    * If one player chooses rock and the other player chooses scissors, then rock wins.
      (The rock smashes the scissors.)
    * If one player chooses scissors and the other player chooses paper, then scissors
      wins. (Scissors cuts paper.)
    * If one player chooses paper and the other player chooses rock, then paper wins.
      (Paper wraps rock.)
    * If both players make the same choice, the game must be played again to deter-
      mine the winner.

 Be sure to divide the program into functions that perform each major task.

*/

#include <iostream>
#include <cstdlib>  // for rand and srand
#include <ctime>    // for time
#include <iomanip>  // for setw
using namespace std;

// Function Prototypes
string compPlayer();
string player();
string rpcSwitch(int);
string winner(string, string);


int main() {

  // Variables
  string compHand,    // holds the computer's hand
         playerHand;  // holds the player's hand


  // Get the system time
  unsigned seed = time(0);
  // Seed the random number generator
  srand(seed);

  // Computer makes it's decision
  compHand = compPlayer();

  // User is prompted for their choice
  playerHand = player();

  // Display hands
  cout << "\nPlayer: " << setw(6) << playerHand << endl;
  cout << "Computer: " << compHand << endl << endl;

  // Call winner and output results
  cout << winner(compHand, playerHand);

  cout << endl << endl;

  return 0;
}


// Function Definitions
//***************************************************************
// Defintion of compPlayer.                                     *
// This function generates a random number from 1 through 3.    *
// The value is passed to the rpcSwitch function, which retuns  *
// a string containing the corresponding Rock, Paper, Scissors  *
// choice, and is returned by this function.                    *
//***************************************************************

string compPlayer() {
  int maxValue = 3,  // largest possible random number
      minValue = 1,  // smallest possible random number
      compChoice;    // holds the random number

  // Generate random value from 1 to 3 and return it
  compChoice = (rand() % (maxValue - minValue + 1)) + minValue;

  // Pass random int to rpcSwitch function returning a string
  return rpcSwitch(compChoice);
}


//***************************************************************
// Defintion of player.                                         *
// This function prompts the user to choose Rock, Paper, or     *
// Scissors, represented by an int from 1 through 3. The value  *
// is passed to the rpcSwitch function, which retuns a string   *
// containing the corresponding Rock, Paper, Scissors choice,   *
// and is returned by this function.                            *
//***************************************************************

string player() {
  int playerChoice;  // holds the player's choice

  // User Prompt
  cout << "Press 1 for Rock\nPress 2 for Paper\nPress 3 for Scissors\n-> ";
  cin >> playerChoice;

  // Pass int to rpcSwitch function returning a string
  return rpcSwitch(playerChoice);
}


//***************************************************************
// Defintion of rpcSwitch.                                      *
// This function uses a switch statement to convert the         *
// numerical representation of Rock, Paper, Scissors, to a      *
// string. The string is returned by the function.              *
//***************************************************************

string rpcSwitch(int choice) {
  switch (choice) {
  case 1:
    return "Rock";
    break;

  case 2:
    return "Paper";
    break;

  case 3:
    return "Scissors";
    break;
  }
}


//***************************************************************
// Defintion of winner.                                         *
// This function decides the winner of the game. The function   *
// accepts both the computer and player choices as strings. The *
// choices are compared through if else statements. If both     *
// choices are a tie, the game is over. If not a tie, a series  *
// of if else if statements are used to determine the winner.   *
// The function returns a string indicating the winner.         *
//***************************************************************

string winner(string computer, string player) {
  // If the computer and player make the same choice, return a tie game
  if (computer == player) {
    return "Tie\n";
  }
  else {
    // If the player's choice beats the computer's, return player wins
    // else return computer wins
    if (computer == "Rock" && player == "Paper") return "Player Wins"; 
    else if (computer == "Paper" && player == "Scissors") return "Player Wins";
    else if (computer == "Scissors" && player == "Rock") return "Player Wins";
    else return "Computer Wins";
  }
}