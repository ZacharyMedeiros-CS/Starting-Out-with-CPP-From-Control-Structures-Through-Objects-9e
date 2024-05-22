//
// This program allows the user to enter an integer to check 
// if the value is a prime. The function isPrime() is called
// to check if the value is prime and returns a bool.
//

/*
 Chapter 06 Programming Challenge 23 Prime Number List

Use the isPrime function that you wrote in Programming Challenge 22 (isPrime func-
tion) in a program that stores a list of all the prime numbers from 1 through 100 in a file.

*/

#include <iostream>  // for cin, cout
#include <fstream>   // for ofstream
using namespace std;

// Function Prototypes
bool isPrime(int);

int main() {

	// Variables
	int integer; // holds a user entered integer to check if it is prime


	// Prepare for file output
	ofstream outputFile;            // Create ofstream object
	outputFile.open("Primes.txt");  // Open file for output

	// A for loop is used to pass the value 1 to 100
	// to the function isPrime()
	for (int i = 1; i <= 100; i++) {
		// If isPrime() is true, write the argument to
		// the output file
		if (isPrime(i)) outputFile << i << endl;
	}

	// Close the file
	outputFile.close();

	return 0;
}


// Function Definitions
//***************************************************************
// Defintion of isPrime.                                        *
// This function accepts an integer and returns false if the    *
// integer divides evenly with more values than one and itself  *
// and true otherwise.                                         *
//***************************************************************
bool isPrime(int integer) {
	int remainder,      // holds the remainder from the modulus division
		  evenCount = 0;  // holds the amount of times the integer divided evenly

	// A for loop iteratively modulus divides
	// the integer and the loop counter,
	// beginning from 1 
	for (int i = 1; i <= integer; i++) {
		remainder = integer % i;

		// If the quotient of the modulus division is 0,
		// increase evenCount by one
		if (remainder == 0) evenCount++;


		// if the remainder is 0 and evenCount is 3,
		// return false from the function
		if (remainder == 0 && evenCount == 3) return false;
	}
	// Return true from the function when completing the 
	// for loop
	return true;
}
