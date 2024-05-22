//
// This function uses a formula inside a function to calculate
// the profits of a stock purchase.
//

/*
 Chapter 06 Programming Challenge 20 Stock Profit

 The profit from the sale of a stock can be calculated as follows:

 Profit = ((NS * SP) - SC) - ((NS * PP) + PC)
 
 where NS is the number of shares, SP is the sale price per share, SC is the sale commis-
 sion paid, PP is the purchase price per share, and PC is the purchase commission paid.
 If the calculation yields a positive value, then the sale of the stock resulted in a profit.
 If the calculation yields a negative number, then the sale resulted in a loss.

 Write a function that accepts as arguments the number of shares, the purchase price per
 share, the purchase commission paid, the sale price per share, and the sale commission 
 paid. The function should return the profit (or loss) from the sale of stock.

 Demonstrate the function in a program that asks the user to enter the necessary data
 and display the amount of the profit or loss.

 */



#include <iostream>  // for cout, cin
#include <iomanip>   // for fixed, setprecision
#include <cmath>     // for abs
using namespace std;

// Function Prototype
double stockProfits(int, double, double, double, double);


int main() {
	
	// Variables
	int shares;                // holds the number of shares 
	double salePrice,          // holds the sale price per share
		     saleCommission,     // holds the sale commission paid
		     purchasePrice,      // holds the purchase price per share
		     purchaseCommission, // holds the purchase commission paid
	       profits;            // holds the output of stockProfits()


	// User Prompt
	cout << "Enter the number of shares purchase: ";
	cin >> shares;
	cout << "Enter the sale price per share: $";
	cin >> salePrice;
	cout << "Enter the sale commission paid: $";
	cin >> saleCommission;
	cout << "Enter the purchase price per share: $";
	cin >> purchasePrice;
	cout << "Enter the purchase commission paid:$ ";
	cin >> purchaseCommission;

	// Call stockProfits() and store return value
	profits = stockProfits(shares, salePrice, saleCommission, purchasePrice, purchaseCommission);

	// Output Results
	// If the result of stockProfits() is less than 0, print
	// a negative dollar amount, and use the absolute value
	// function, abs(), to drop the negative from profits.
	if (profits < 0) {
		cout << "\nLoss of -$" << setprecision(2) << fixed << abs(profits) << endl << endl;
	}
	else {
		cout << "\nProfit of $" << setprecision(2) << fixed << profits << endl << endl;
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
