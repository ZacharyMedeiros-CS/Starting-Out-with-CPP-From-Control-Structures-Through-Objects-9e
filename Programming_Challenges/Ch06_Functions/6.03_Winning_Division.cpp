//
// This program uses multiple functions to determine the 
// highest grossing division for the quarter
//

/*
 Chapter 6 Programming Challenge - Winning Division
 Write a program that determines which of a company's four divisions (Northeast,
 Southeast, Northwest, and Southwest) had the greatest sales for a quarter. It should
 include the following two functions, which are called by main:

 * double getSales() is passed the name of a division. It asks the user for a divion's
   quarterly sales figure, validates the input, then returns it. It should be called once for
   each division.
 * void findHighest() is passed the four sales totals. It determines which is the larg-
   est and prints the name of the high-grossing division, along with its sales figure.

 Input Validation: Do not accept dollar amounts less than $0.00.

*/

#include <iostream>  // for cout
#include <iomanip>   // for setprecision, fixed 
using namespace std;

// Function Prototypes
double getSales(string);
void findHighest(double, double, double, double);


int main() {

    // Variables
    double sales_NE,  // holds the sales for the Northeast division
           sales_SE,  // holds the sales for the Southeast division
           sales_NW,  // holds the sales for the Northwest division
           sales_SW;  // holds the sales for the Southwest division


    // Algorithm
    // Step 1) Call getSales() for each division
    // Step 2) Call findHighest() to determine and print the highest grossing division


    // + Step 1)
    sales_NE = getSales("Northeast");
    sales_SE = getSales("Southeast");
    sales_NW = getSales("Northwest");
    sales_SW = getSales("Southwest");

    // + Step 2)
    findHighest(sales_NE, sales_SE, sales_NW, sales_SW);


    return 0;
}


// Function Definition
double getSales(string division) {
    double sales;

    // User prompt
    cout << "Enter " << division << "'s quarterly sales $";
    cin >> sales;

    // Input validation
    while (sales < 0) {
        cout << "\nInvalid Input\n * quarterly sales cannot be less than $0.00" << endl;

        cout << "\nEnter " << division << "'s quarterly sales $";
        cin >> sales;
    }

    return sales;
}

void findHighest(double sales_NE, double sales_SE, double sales_NW, double sales_SW) {
    double highest = sales_NE;
    string division = "Northeast";

    // A series of if statements are used to determine the highest grossing division
    if (sales_SE > highest) {
        highest = sales_SE;
        division = "Southeast";
    }
    if (sales_NW > highest) {
        highest = sales_NW;
        division = "Northwest";
    }
    if (sales_SW > highest) {
        highest = sales_SW;
        division = "Southwest";
    }

    // Output results
    cout << "\nHighest Grossing Division" << endl;
    cout << "- " << division << setprecision(2) << fixed << " ... $" << highest << endl;
}