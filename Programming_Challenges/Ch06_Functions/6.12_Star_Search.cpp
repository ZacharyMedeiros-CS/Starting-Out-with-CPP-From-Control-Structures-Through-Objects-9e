//
// A program that calculates a competition's final score
// by averaging three scores after using functions to 
// drop the highest and lowest scores
//

/*
 Chapter 06 Programming Challenge 12 Star Search 

 A particular talent competition has five judges, each of whom awards a score between
 0 and 10 to each performer. Fractional scores, such as 8.3, are allowed. A performer's
 final score is determined by dropping the highest and lowest score recieved, then aver-
 aging the three remaining scores. Write a program that uses this method to calculate a
 contestant's score. It should include the following functions:

 * void getJudgeData() should ask the user for a judge's score, store it in a reference
	 parameter variable, and validate it. This function should be called by main once for
	 each of the five judges.
 * void calcScore() should calculate and display the average of the three scores that
	 remain after dropping the highest and lowest scores the performer received. This
	 function should be called just once by main and should be passed the five scores.

 The last two functions, described below, should be called by calcScore which uses
 the returned information to determine which of the scores to drop.
 * int findLowest() should find and return the lowest of the five scores passed to it.
 * int findHighest() should find and return the highest of the five scores passed to it.

 Input Validation: Do not accept judge scores lower than 0 or higher than 10.
*/


#include <iostream>  // for cout, cin
#include <iomanip>   // for 

using namespace std;

// Function Prototype
void getJudgeData(double&);
void calcScore(double, double, double, double, double);
double findLowest(double, double, double, double, double);
double findHighest(double, double, double, double, double);

int main() {

	double score1,  // holds the judge's score
				 score2,
			 	 score3,
				 score4,
				 score5;


	// Gather data by calling getJudgeData() for each score
	getJudgeData(score1);
	getJudgeData(score2);
	getJudgeData(score3);
	getJudgeData(score4);
	getJudgeData(score5);

	//Calculate and display the final score
	calcScore(score1, score2, score3, score4, score5);
	cout << endl;

	return 0;
}


// Function Definitions
//**********************************************************
// Definition of getJudgeData.                             *
// The parameter score is a reference variable. The user   *
// enters score data, and then the input is validated.     *
//**********************************************************

void getJudgeData(double& score) {
	// Prompt user
	cout << "Enter score: ";
	cin >> score;

	// Input validation
	while (score < 0 || score > 10) {
		cout << "\nInvalid Input\nScore cannot be less than 0 or greater than 10" << endl;
		cout << "Enter score: ";
		cin >> score;
	}
}


//**********************************************************
// Definition of calcScore.                                *
// calcScore is passed five scores. findLowest and         *
// findHighest are called from within calcScore to         *
// determine the lowest and highest judge's scores. The    *
// lowest and highest scores are then omitted from the     *
// final score.                                            *
//**********************************************************

void calcScore(double score1, double score2, double score3, double score4, double score5) {
	// Find lowest and highest scores by calling findLowest() and findHighest()
	double lowest = findLowest(score1, score2, score3, score4, score5),
		highest = findHighest(score1, score2, score3, score4, score5);

	// Calculate and display the final score
	cout << "Final Score: " << setprecision(1) << fixed
		<< (score1 + score2 + score3 + score4 + score5 - lowest - highest) / 3;
}


//**********************************************************
// Definition of findLowest.                               *
// findLowest is called by calcScore, to determine which   *
// score is the lowest, and will be left out of the final  *
// score.                                                  *
//**********************************************************

double findLowest(double score1, double score2, double score3, double score4, double score5) {
	double lowest = score1;

	// A series of if statements determine which score is the lowest
	if (score2 < lowest) lowest = score2;
	if (score3 < lowest) lowest = score3;
	if (score4 < lowest) lowest = score4;
	if (score5 < lowest) lowest = score5;

	return lowest;
}


//**********************************************************
// Definition of findHighest.                              *
// findHighest is called by calcScore, to determine which  *
// score is the highest, and will be left out of the final *
// score.                                                  *
//**********************************************************

double findHighest(double score1, double score2, double score3, double score4, double score5) {
	double highest = score1;

	// A series of if statements determine which score is the highest
	if (score2 > highest) highest = score2;
	if (score3 > highest) highest = score3;
	if (score4 > highest) highest = score4;
	if (score5 > highest) highest = score5;

	return highest;
}

