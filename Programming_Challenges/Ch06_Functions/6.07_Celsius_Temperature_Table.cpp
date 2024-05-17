//
// This program uses a function to convert temperatures
// 0 - 20 Fahrenheit to Celsius, and then displays the 
// data in a table
//

/*
 Chapter 06 Programming Challenge 07 Celsius Temperature Table 

 The formula for converting a temperature from Fahrenheit to Celsius is

 C = (5/9)*(F - 32)

 where F is the Fahrenheit temperature and C is the Celsius temperature. Write a func-
 tion named celsius that accepts a Fahrenheit temperature as an argument. The func-
 tion should return the temperature, converted to Celsius. Demonstrate the function by
 calling it in a loop that displays a table of the Fahrenheit temperatures 0 through 20
 and their Celsius equivalents.
 */

#include <iostream>  // for cout
#include <iomanip>   // for setw(), setprecision(), fixed()

using namespace std;

// Function Prototype
double celsius(double);

int main() {

	// Table header
	cout << setw(8) << "Celsius" << setw(14) << "Fahrenheit" << endl;

	// A for loop is called for the first 20 
	for (int i = 0; i <= 20; i++) {
		cout << setw(5) << i << setw(15) << setprecision(1) << fixed << celsius(i) << endl;
	}

	return 0;
}

// Function Defition
double celsius(double fahrenheit) {
	// Formulat: C = (5/9)*(F - 32)
	return 0.556 * (fahrenheit - 32);
}
