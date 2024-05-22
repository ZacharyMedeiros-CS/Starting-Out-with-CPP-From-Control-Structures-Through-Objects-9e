//
// This program allows the user to enter an integer to check 
// if the value is a prime. The function isPrime() is called
// to check if the value is prime and returns a bool.
//

/*
 Chapter 06 Programming Challenge 22 isPrime Function

 A prime number is a number that is only evenly divisible by itself and 1. For example,
 the number 5 is prime because it can only be evenly divided by 1 and 5. The number 6,
 however, is not prime because it can be divided evenly by 1, 2, 3, and 6.

 Write a function name isPrime, which takes an integer as an argument and returns
 true if the argument is a prime number, or false otherwise. Demonstrate the function
 in a complete program.

 TIP: Recall that the % operator divides one number by another, and returns the remain-
 der of the division. In an expression such as num1 % num2, the % operator will return 0
 if num1 is evenly divisible by num2.

*/

#include <iostream>
using namespace std;

// Function Prototypes
bool isPrime(int);

int main() {

	// Variables
	int integer; // holds a user entered integer to check if it is prime


	// User Prompt
	cout << "Enter an intger: ";
	cin >> integer;

	// Call the function with integer and determine if
	// the value is prime
	cout << endl;
	if (isPrime(integer)) {
		cout << integer << " is a prime.\n";
	}
	else {
		cout << integer << " is not a prime.\n";
	}

	cout << endl;
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