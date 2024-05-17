//
// A program that prompts the user to enter a number of coin
// flips, and then calls a function to flip the coin
//

/*
 Chapter 06 Programming Challenge 08 Coin Toss 

 Write a function named coinToss that simulates the tossing of a coin. When you call
 the function, it should generate a random number in the range of 1 through 2. If the
 random number is 1, the function should display "heads." If the random numner is 2,
 the function should display "tails." Demonstrate the function in a program that asks
 the user how many times the coin should be tossed, then simulates the tossing of the
 coin that number of times.
*/


#include <iostream>  // for cout
#include <cstdlib>   // for rand, srand
#include <ctime>     // for time()

using namespace std;


// Function Prototype
string coinToss();

int main() {

	// Variables
	int flips;

	// Get the system time
	unsigned seed = time(0);

	// Seed the random number generator
	srand(seed);


	// Prompt user
	cout << "Enter number of coin flips: ";
	cin >> flips;
	cout << endl;


	// A for loop is used to control number of coin flips
	for (int i = 1; i <= flips; i++) {
		cout << coinToss() << endl << endl;
	}

	return 0;
}

// Function Definition
string coinToss() {
	// Constants
	const int MIN_VALUE = 1;  // holds min coin value
	const int MAX_VALUE = 2;  // holds max coin value

	// Variables
	int coin;  // holds the value of the coin flip

	cout << "Flipping coin...\n";
	coin = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

	return coin == 1 ? "Heads" : "Tails";
}
