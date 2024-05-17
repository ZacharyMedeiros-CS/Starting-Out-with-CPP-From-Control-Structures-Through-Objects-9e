//
// This program uses a while loop and a function to display
// the distance an object falls, due to the acceleration
// of gravity.
//

/*
 Chapter 6 Programming Challenge 05 Falling Distance - 

 When an object is falling because of gravity, the following formula can be used to
 determine the distance the object falls in a specific time period:

 d = (1/2)gt^2

 The variables in the formula are as follows: d is the distance in meters, g is 9.8, and t
 is the amount of time, in seconds, that the object has been falling.
 Write a function named fallingDistance that accepts an object's falling time (in
 seconds) as an argument. The function should return the distance, in meters, that the
 object has fallen during that time interval. Write a program that demonstrates the
 function by calling it in a loop that passes the values 1 through 10 as arguments and
 displays the return value.

*/


#include <iostream>  // for cout
#include <iomanip>   // for setw()

using namespace std;

// Function Prototype
double fallingDistance(int);

int main() {

	double distance;  // holds the distance returned by fallingDistance()
	int seconds = 1;  // holds seconds


	// Results Heading
	cout << setw(6) << "Time" << setw(13) << "Distance" << endl;

	// A while loop is used to call fallingDistance() 10 times
	while (seconds < 11) {
		// A call to fallingDistance() returns 
		// the distance fallen for each second
		distance = fallingDistance(seconds);

		// Format the results
		cout << setw(4) << seconds << "s" << setw(12) << setprecision(1) << fixed << distance << "m" << endl;

		seconds++;
	}

	return 0;
}


// Function Definition
//****************************************************
// Definition of function fallingDistance. This      *
// function is passed time, in seconds, and returns  *
// distance, in meters, that an object has fallen.   *
//****************************************************

double fallingDistance(int seconds) {
	// Formula: distance = (1/2)gravity*time^2
	return 0.5 * 9.8 * seconds * seconds;
}

