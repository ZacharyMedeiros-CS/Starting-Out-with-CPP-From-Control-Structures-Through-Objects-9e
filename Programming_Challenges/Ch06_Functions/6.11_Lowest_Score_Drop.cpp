//
// This program uses three functions to calculate a test score's
// average, after dropping the lowest test score
//

/*
 Chapter 06 Programming Challenge 11 Lowest Score Drop 

 Write a program that calculates the average of a group of test scores, where the lowest
 score in the group is dropped. It should use the following functions:
 * void getScore() should ask the user for a test score, store it in a reference param-
	 eter variable, and validate it. This function should be called by main once for each
	 of the five scores to be entered.
 * void calcAverage() should calculate and display the average of the four highest
	 scores. This function should be called just once by main and should be passed the
	 five scores.
 * int findLowest() should find and return the lowest of the five scores passed to it.
	 It should be called by calcAverage, which uses the function to determine which of
	 the five scores to drop.

 Input Validation: Do not accept test scores lower than 0 or higher than 100.
*/


#include <iostream>

using namespace std;

// Function Prototypes
void getScore(int&);
void calcAverage(int, int, int, int, int);
int findLowest(int, int, int, int, int);


int main() {
	// Variables
	int score1,  // holds the value of the test score
		  score2,
			score3,
			score4,
			score5;


	// Call getScore() to prompt the user for five test scores
	getScore(score1);
	getScore(score2);
	getScore(score3);
	getScore(score4);
	getScore(score5);

	// Calculate and display results, where findLowest is called 
	// from within calcAverage, to determine the lowest score to 
	// be dropped from the average 
	calcAverage(score1, score2, score3, score4, score5);


	return 0;
}

// Function Definitions
//**********************************************************
// Definition of getScore.                                 *
// The parameter score is a reference variable. The user   *
// enters a test's score, and is then validated inside of  *
// the while loop.                                         *
//**********************************************************

void getScore(int& score) {
	// User prompt
	cout << "Enter test score: ";
	cin >> score;

	// Input Validation
	while (score < 0 || score > 100) {
		cout << "\nInvalid Entry\nScore cannot be less than 0 or greater than 100" << endl;
		cout << "Enter test score: ";
		cin >> score;
	}
}


//**********************************************************
// Definition of calcAverage.                              *
// Five test scores are passed to the function. findlowest *
// is called to determine which of the test scores will be *
// dropped from the average. The test scores are averaged, *
// and printed.                                            *
//**********************************************************

void calcAverage(int score1, int score2, int score3, int score4, int score5) {
	// Find the lowest score by calling findLowest()
	int lowest = findLowest(score1, score2, score3, score4, score5);

	// Calculate and output the average of test the test scores
	cout << "Test Score Average: " << (score1 + score2 + score3 + score4 + score5 - lowest) / 4 << endl;
}


//**********************************************************
// Definition of findLowest.                               *
// findLowest is called inside of getAverage to determine  * 
// which test score will be dropped from the average. Five *
// test scores are passed to the function. The test with   *
// the lowest score is determined and then returned.       * 
//**********************************************************

int findLowest(int score1, int score2, int score3, int score4, int score5) {
	int lowest = score1;

	// A series of if statements determine which of the five scores is the lowest
	if (lowest > score2) lowest = score2;
	if (lowest > score3) lowest = score3;
	if (lowest > score4) lowest = score4;
	if (lowest > score5) lowest = score5;

	return lowest;
}
