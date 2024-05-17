//
// This program uses a function to determine the present account
// value needed in order to have a specified amount in the future. 
// A loop is used to allow the user to repeat calling the function,
// to experiment with different values.
//

/*
 Chapter 06 Programming Challenge 09 Present Value 

 Suppose you want to deposit a certain amount of money into a savings account and
 then leave it alone to draw interest for the next 10 years. At the end of 10 years, you
 would like to have $10,000 in the account. How much do you need to deposit today to
 make that happen? You can use the following formula, which is known as the present
 value formula, to find out:

 P = F/(1+r)^n

 The terms in the formula are as follows:

 * P is the present value, or the amount that you need to deposit today.
 * F is the future value that you want in the account. (In this case, F is $10,000.)
 * r is the annual interest rate.
 * n is the number of years that you plan to let the money sit in the account.

 Write a program that has a function named presentValue that performs this calcula-
 tion. The function should accept the future value, annual interest rate, and number of
 years as arguments. It should return the present value, which is the amount that you
 need to deposit today. Demonstrate the function in a program that lets the user experi-
 ment with different values for the formula's terms.

*/

#include <iostream>  // for cout
#include <iomanip>   // for setprecision(), fixed
#include <cmath>     // for pow()

using namespace std;

// Function Prototypes
double presentValue(double, double, int);


int main() {
	// Variables
	double futureValue,  // holds the user's desired future value
		        annualIR,  // holds the accounts annual interest rate as a percentage
		           years;  // holds the amount of years to pass

	char choice;  // holds the users choice for repeat


	// A while loop is used to repeat calling presentValue()
	while (true) {
		// User prompt
		cout << "Enter the Future Value: $";
		cin >> futureValue;
		cout << "Enter Annual Interest Rate Percent: ";
		cin >> annualIR;
		cout << "Enter how many years: ";
		cin >> years;

		// Call presentvalue() and output results
		cout << "\nThe present value needed is $" << setprecision(2) << fixed << presentValue(futureValue, annualIR, years) << endl;

		// Prompt user for continue
		cout << "\nWould you like to try again? (y/n)" << endl;
		cin >> choice;
		cout << endl;
		// If user enters 'n' break from while loop
		if (choice == 'n') break;
	}

	return 0;
}


// Function Defintion
double presentValue(double futureValue, double annualIR, int years) {
	// Formula: P = F/(1+r)^n
	double product;  // holds the product of the power function

	// Convert from percentage to decimal
	annualIR = annualIR / 100;

	// Find the product of the exponent
	product = pow(1 + annualIR, years);

	// Return the present value
	return futureValue / product;
}

