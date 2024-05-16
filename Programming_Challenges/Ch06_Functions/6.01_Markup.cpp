//
// This program uses a function, to apply a markup to the
// wholesale cost of an item, for retail purchase.
//

/*
 Chapter 6 Programming Challenge - Markup
 Write a program that asks the user to enter an item's wholesale cost and its markup
 percentage. It should then display the item's retail price. For example:
 * If an item's wholesale cost is 5.00 and its markup percentage is 100 percent, then
   the item's retail price is 10.00.
 * I an item's wholesale cost is 5.00 and its markup percentage is 50 percent, then the
   item's retail price is 7.50.
 The program should have a function named calculateRetail that receives the wholesale
 cost and the markup percentage as arguments and returns the retail price of the item.

 Input Validation: Do not accept negative values for either the wholesale cost of the
 item or the markup percentage.

*/

#include <iostream>  // for cout
#include <iomanip>   // for setprecision, fixed 
using namespace std;


// Function Prototypes
double calculateRetail(double, double);

int main() {

    // Variables
    double wholesale,      // holds the item's wholesale cost
        markupPercentage,  // holds the item's markup percentage
        retailPrice;       // holds the item's retail price


    // Algorithm
    // Step 1) Prompt user for input
    // Step 2) Validate user input
    // Step 3) Call calculateRetail
    // Step 4) Output results by printing retailPrice


    // + Step 1)
    // User Prompt
    cout << "Enter the items's wholesale cost $";
    cin >> wholesale;
    cout << "Enter the item's markup percentage ";
    cin >> markupPercentage;

    // + Step 2)
    // Input Validation - If wholesale or markupPercentage is less than 0, 
    // print error message and prompt user again
    while (wholesale < 0 || markupPercentage < 0) {
        cout << "\nInvalid Input\n * Cannot accept values less than 0" << endl;
        cout << "\nEnter wholesale $";
        cin >> wholesale;
        cout << "Enter markup percentage ";
        cin >> markupPercentage;
    }

    // + Step 3)
    retailPrice = calculateRetail(wholesale, markupPercentage);

    // + Step 4)
    // Output Results
    cout << "\nRetail Price $" << setprecision(2) << fixed << retailPrice << endl;


    cout << endl;
    return 0;

}


// Function Definition
double calculateRetail(double wholesale, double markupPercentage) {
    double markupDecimal = markupPercentage / 100;
    return wholesale + (wholesale * markupDecimal);
}
