//
// This function uses a formula inside a function to calculate
// the profits of a stock purchase. This function is called 
// from within a for loop, to calculate the total profits from 
// multiple stock sales.
//

/*
 Chapter 06 Programming Challenge 21 Multiple Stock Sales

 Use the function that you wrote for Programming Challenge 20 (Stock Profit) in a
 program that calculates the total profit or loss from the sale of multiple stocks. The
 program should ask the user for the number of stock sales and the necessary data for
 each stock sale. It should accumulate the profit or loss for each stock sale, then display
 the total.

*/

#include <iostream>  // for cin, cout
#include <iomanip>   // for fixed, setprecision
#include <cmath>     // for abs
using namespace std;

// Function Prototype
double stockProfits(int, double, double, double, double);


int main() {

	// Variables
	int salesCount,            // holds the number of stock sales to calculate
	     numShares;            // holds the number of shares 

	double salePrice,          // holds the sale price per share
		     saleCommission,     // holds the sale commission paid
		     purchasePrice,      // holds the purchase price per share
		     purchaseCommission, // holds the purchase commission paid
		     profits,            // holds the output of stockProfits()
	       totalProfits = 0;   // holds the total amount of profits


	// User Prompt
	cout << "Enter stock sales count: ";
	cin >> salesCount;
	
	// A for loop prompts the user for the 
	// details of each stock sale
	for (int i = 0; i < salesCount; i++) {
		cout << "\n- Stock Sale " << i + 1 << " -\n";
		cout << "Enter the number of shares purchased: ";
		cin >> numShares;
		cout << "Enter the sale price per share: $";
		cin >> salePrice;
		cout << "Enter the sale commission paid: $";
		cin >> saleCommission;
		cout << "Enter the purchase price per share: $";
		cin >> purchasePrice;
		cout << "Enter the purchase commission paid:$ ";
		cin >> purchaseCommission;

		// Call stockProfits(), and store return value
		// in totalProfits, which is holding a running
		// sum of all stock sale transactions
		totalProfits += stockProfits(numShares, salePrice, saleCommission, purchasePrice,purchaseCommission);
	}

	// Output Results
	// If the value in totalProfits is less than 0, print a
	// negative dollar amount, and use the absolute value
	// function, abs(), to drop the negative from totalProfits.
	if (totalProfits < 0) {
		cout << "\n\nTotal Loss of -$" << setprecision(2) << fixed << abs(totalProfits) << endl << endl;
	}
	else {
		cout << "\n\nTotal Profit of $" << setprecision(2) << fixed << totalProfits << endl << endl;
	}

	return 0;
}


// Function Definition
//***************************************************************
// Defintion of stockProfits.                                   *
// This function uses a formula to calculate and return stock   *
// profits. The formula is                                      *
// Profit = ((NS * SP) - SC) - ((NS * PP) + PC) where NS is     *
// numShares, SP is salePrice, SC is saleCommission, PP is      *
// purchasePrice, and PC is purchaseCommision.                  *
//***************************************************************

double stockProfits(int numShares, double salePrice, double saleCommission, double purchasePrice, double purchaseCommission) {
	return ((numShares * salePrice) - saleCommission) - ((numShares * purchasePrice) + purchaseCommission);
}
