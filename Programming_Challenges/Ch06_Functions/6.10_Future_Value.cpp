//
// This program uses a function to determine an account's future 
// value, based on the account's present value, monthly interest  
// rate, and amount of months, the money is left in the account.
// This is determined by a single function call to futureValue().
//

/*
 Chapter 06 Programming Challenge 10 Future Value 

 Suppose you have a certain amount of money in a savings account that earns com-
 pound monthly interest, and you want to calculate the amount that you will have 
 after a specific number of months. The formula, which is known as the future value
 formula, is 

 F = P * (1+i)^t

 The terms in the formula are as follows:

 * F is the future value of the account after the specified time period.
 * P is the present value of the account.
 * i is the monthly interest rate.
 * t is the number of months.

 Write a program that prompts the user to enter the account's present value, monthly
 interest rate, and the number of months that the money will be left in the account. The
 program should pass these values to a function named futureValue that returns the
 future value of the account, after the specified number of months. The program should
 display the account's future value.

*/

#include <iostream>  // for cout
#include <iomanip>   // for setprecision(), fixed
#include <cmath>     // for pow()

using namespace std;

// Function Prototypes


double futureValue(double, double, int);


int main() {
	// Variables
	double presentValue,  // holds the user's present account value
		        monthlyIR,  // holds the accounts monthly interest rate as a percentage
		           months;  // holds the amount of months to pass


	// User Prompt
	cout << "Enter the account's present value: $";
	cin >> presentValue;
	cout << "Enter the Monthly Interest Rate Percent: ";
	cin >> monthlyIR;
	cout << "Enter the number of months the money\n";
	cout << "will be left in the account: $";
	cin >> months;


	// Call function and output results
	cout << "\nAccount Future Value: $" << setprecision(2) << fixed << futureValue(presentValue, monthlyIR, months) << endl;

	cout << endl;
	return 0;
}


// Function Defintion
double futureValue(double presentValue, double monthlyIR, int months) {
	// Formula: F = P * (1+i)^t
	double product;  // holds the product of the power function

	// Convert from percentage to decimal
	monthlyIR = monthlyIR / 100;

	// Find the product of the exponent
	product = pow(1 + monthlyIR, months);

	// Return the future value
	return presentValue * product;
}

