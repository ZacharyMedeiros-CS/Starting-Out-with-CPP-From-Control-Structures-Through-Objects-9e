//
// A program that makes use of reference parameter variables, 
// and a default argument, in the program's functions.
//

/*
 Chapter 06 Programming Challenge 14 Order Status 

 The Middletown Wholesale Copper Wire Company sells spools of copper wiring for
 $100 each. Write a program that displays the status of an order. The program should
 have a function that asks for the following data:

 * The number of spools ordered
 * The number of spools in stock
 * Whether there are special shipping and handling charges

 (Shipping and handling is normally $10 per spool.) If there are special charges, the
 program should ask for the special charges per spool.

 The gathered data should be passed as arguments to another function that displays:

 * The number of spools ready to ship from current stock
 * The number of spools on backorder (if the number ordered is greater than what is
	 in stock)
 * Subtotal of the portion ready to ship (the number of spools ready to ship times
	 $100)
 * Total shipping and handling charges on the portion ready to ship
 * Total of the order ready to ship

 The shipping and handling parameter in the second function should have the default
 argument 10.00.

 Input Validation: Do not accept numbers less than 1 for spools ordered. Do not accept
 a number less than 0 for spools in stock or shipping and handling charges.
*/


#include <iostream>  // for cout, cin
#include <iomanip>   // for setprecision(), setw(), fixed

using namespace std;

// Function Prototypes
void setSpoolOrderData(double&, double&, char&);
void getSpoolOrderData(double&, double&, double = 10.0);


int main() {
	// Variables
	double ordered = 0,  // holds the number of spools ordered
				 inStock = 0,  // holds the number of spools in stock
						 rate_SH;  // holds the shipping and handling charge

	char specialHandling;  // holds y/n for special shipping and handling charges


	// Call setSpoolOrderData() to gather the data for the order
	setSpoolOrderData(ordered, inStock, specialHandling);

	// If the order has special shipping and handling charges,
	// gather more data, and then call getSpoolOrderData() to 
	// display the order results
	if (specialHandling == 'y' || specialHandling == 'Y') {
		cout << setw(45) << "Shipping and Handling charges per spool: $";
		cin >> rate_SH;
		// Shipping and Handling input validation
		while (rate_SH < 0) {
			// Error messasge
			cout << "\nInvalid Input\n* Shipping and Handling cannot be less than 0" << endl;
			cout << setw(45) << "\nShipping and Handling charges per spool: $";
			cin >> rate_SH;
		}

		getSpoolOrderData(ordered, inStock, rate_SH);
	}
	else {
		// Call getSpoolOrderData() to display the order results
		getSpoolOrderData(ordered, inStock);
	}

	cout << endl;
	return 0;
}


// Function Definitions
//********************************************************** 
// Definition of setSpoolOrderData.                        *
// This function uses three reference variables, ordered,  *
// instock, and specialHandling. Their data is set by the  *
// user and then validated through a while loop.           *
//**********************************************************

void setSpoolOrderData(double& ordered, double& inStock, char& specialHandling) {
	// User prompt
	cout << "Enter the number of spools ordered: ";
	cin >> ordered;
	// Order input validation
	while (ordered < 1) {
		// Error messasge
		cout << "\nInvalid Input\n* Spools ordered cannot be less than 1" << endl;
		cout << "\nEnter the number of spools ordered: ";
		cin >> ordered;
	}

	cout << "Enter the number of spools in stock: ";
	cin >> inStock;
	// Stock input validation
	while (inStock < 0) {
		// Error messasge
		cout << "\nInvalid Input\n* Spools in stock cannot be less than 0" << endl;
		cout << "\nEnter the number of spools in stock: ";
		cin >> inStock;
	}

	// Prompt user for special shipping and handling rate
	cout << "Special Shipping and Handling Charges? (y/n) ";
	cin >> specialHandling;
}


//********************************************************** 
// Definition of getSpoolOrderData.                        *
// This function uses two reference variables, ordered,    *
// and instock, which holds data set by setSpoolOrderData. *
// This function is also passed the shipping and handling  *
// rate. The details of the purchase order are calculated, *
// and printed.                                            *
//**********************************************************

void getSpoolOrderData(double& ordered, double& inStock, double rate_SH) {
	double    total,  // holds the order total
				 total_SH,  // holds the shipping and handling total
				 subtotal,  // holds the order's subtotal
						ready;  // holds the amount of spools ready to ship


	// If the number ordered is greater than what is in stock, set ready to 0
	((inStock - ordered) <= 0) ? ready = 0 : ready = (inStock - ordered);

	// Output order data
	cout << endl;
	cout << "\nMiddletown Wholesale Copper Wire Company Purchase Order" << endl;

	// If ready is 0, display amount on back order
	if (ready == 0) {
		cout << "\nSpools ready to ship: " << inStock << endl;
		if (inStock - ordered < 0) cout << "Spools on back order: " << ordered - inStock << endl;
		ready = inStock;
	}
	else {
		cout << "\nSpools ready to ship: " << ordered << endl;
		ready = ordered;
	}

	// Calculate subtotal
	subtotal = ready * 100;

	// Calculate shipping and handling
	total_SH = ready * rate_SH;

	// Calculate total
	total = subtotal + total_SH;

	// Output results
	cout << setw(12) << "Subtotal ............... $" << setprecision(2) << fixed << subtotal << endl;
	cout << setw(25) << "Shipping and Handling .. $" << setprecision(2) << fixed << total_SH << endl;
	cout << setw(9) << "Total .................. $" << setprecision(2) << fixed << total << endl;
}
