//
// This program prompts a user for information needed
// for a paint job, and outputs the job's details. The 
// program makes use of several functions, global 
// variables, global constants, a and static variable.
//

/*
 Chapter 06 Programming Challenge 18 Paint Job Estimator

 A painting company has determined that for every 110 square feet of wall space,
 1 gallon of paint and 8 hours of labor will be required. The company charges $25.00
 per hour for labor. Write a modular program that allows the user to enter the number
 of rooms that are to be painted and the price of the paint per gallon. It should ask
 for the square feet of wall space in each room. It should then display the following data:
 
 * The number of gallons of paint required
 * The hours of labor required
 * The cost of the paint the labor charges
 * The total cost of the paint
 
 Input Validation: Do not accept a value less than 1 for the number of rooms. Do not
 accept a value less than $10.00 for the price of paint. Do not accept a negative value
 for square footage of wall space.
*/

#include <iostream>  // for cout, cin
#include <iomanip>   // for fixed, setprecision
using namespace std;  

// Global Variables
double gallonCost;                    // holds the cost of a paint gallon
int totalSqft;                        // holds the total square footage to be painted

// Global Constants
const int SQFT_PER_GALLON = 110;      // 100 sqft per gallon of paint
const int LABOR_PER_GALLON = 8;       // 8 hours of labor per gallon of paint
const double LABOR_UNIT_COST = 25.0;  // $25.00 for labor per hour

// Function Prototypes
void setPaintData();
int setSqft(int);
int calcPaintGallons();
int calcLaborHours(int);
double calcPaintCost(int);
double calcLaborCost(int);
double calcJobCost(double, double);
void getPaintData(int, int, double, double, double);


int main() {

	// Variables
	int paintGallons;  // holds the return value of calcPaintGallons
	int laborHours;    // holds the return value of calcLaborHours
	double paintCost;  // holds the return value of calcPaintCost
	double laborCost;  // holds the return value of calcLaborCost
	double jobCost;    // holds the return value of calcPaintJob


	// Prompt user for input data
	setPaintData();

	// Calculate gallons of paint needed
	paintGallons = calcPaintGallons();

	// paintGallons can now be used to calculate
	// laborHours, paintCost, laborCost
	laborHours = calcLaborHours(paintGallons);
	paintCost = calcPaintCost(paintGallons);
	laborCost = calcLaborCost(paintGallons);

	// Calculate the total cost of the paint job
	jobCost = calcJobCost(paintCost, laborCost);

	// Pass all the calculated data to getPaintData
	// and output results
	getPaintData(paintGallons, laborHours, paintCost, laborCost, jobCost);
	cout << endl;

	return 0;
}


// Function Definitions
//***************************************************************
// Defintion of setPaintData.                                   *
// This function prompts the user for data. The price of the    *
// paint is stored in the global variable gallonCost, where it  *
// is accessed later by getPaintData(). This function uses a    *
// for loop to call setSqft() for each room that needs to be    *
// painted. while loops are used for validating user input.     *
//***************************************************************

void setPaintData() {
	int rooms = 0;  // holds the number of rooms that need paint

	// User Prompt
	while (rooms < 1) {
		cout << "Enter number of rooms to be painted: ";
		cin >> rooms;
		// Input Validation
		if (rooms < 1) {
			// Error Message
			cout << "\nInvalid Input" << "\n* Rooms cannot be less than 1" << endl << endl;
		}
	}

	while (gallonCost < 10) {
		cout << "Enter price of paint per gallon: $";
		cin >> gallonCost;
		// Input Validation
		if (gallonCost < 10) {
			// Error Message
			cout << "\nInvalid Input" << "\n* Paint per gallon cannot be less than $10.00" << endl << endl;
		}
	}

	// Call setSqft() for each room
	for (int i = 0; i < rooms; i++) {
		totalSqft = setSqft(i);
	}
}


//***************************************************************
// Defintion of setSqft.                                        *
// This function is called by setPaintData(). setSqft() is      *
// called from within a for loop, where the for loop counter is *
// passed as an argument. This counter is used to indicate      *
// which room the user is entering the square foot data for.    *
// This function makes use of the static variable totalSqft, to *
// keep a running total of the sqaure footage over all rooms.   *
// The value of totalSqft is returned by the function. Do not   *
// confuse this function's static variable totalSqft with the   *
// globally defined variable totalSqft.                         *                          *   
//***************************************************************

int setSqft(int i) {
	static int totalSqft = 0;  // holds the total square footage
	int sqft = -1;             // holds the square feet entered by
	                           // the user at each iteration of the
														 // calling function's for loop

	// User prompt
	while (sqft < 0) {
		cout << "Enter the square footage for room " << i + 1 << ": ";
		cin >> sqft;

		// Input Validation
		if (sqft < 0) {
			// Error Message
			cout << "\nInvalid Input" << "\n* Square feet cannot be less than 0" << endl << endl;
			cout << "Enter the square footage for " << i + 1 << ": ";
			cin >> sqft;
		}
	}
	totalSqft += sqft;  // add to the running total of square footage

	return totalSqft;   // return running total at given iteration
}


//***************************************************************
// Defintion of calcPaintGallons.                               *
// This function calculates whole gallons of paint needed, and  *
// returns the value. Since paint is sold in whole gallons,     *
// when modulus division results in a remainder, the quotient   *
// is rounded up to the nearst whole gallon.                    *
//***************************************************************

int calcPaintGallons() {
	int paintNeeded;  // holds the amount of gallons needed

	// Calculate whole gallons of paint
	paintNeeded = totalSqft / SQFT_PER_GALLON;
	// If there is a remainder, round 
	// up to the nearest whole gallon
	if (totalSqft % SQFT_PER_GALLON > 0) {
		paintNeeded++;
	}

	return paintNeeded;
}


//***************************************************************
// Defintion of calcLaborHours.                                 *
// This function calculates the paint job's labor hours. The    *
// function is passed the amount of paint needed, and is        *
// multiplied by the global constant LABOR_PER_GALLON, and the  *
// product is returned.                                         *
//***************************************************************

int calcLaborHours(int paintGallons) {
	return paintGallons * LABOR_PER_GALLON;
}


//***************************************************************
// Defintion of calcPaintCost.                                  *
// This function calculates the total cost of the paint. The    *
// function is passed the amount of paint needed, and is        *
// multiplied by the global variable gallonCost, and the        *
// product is returned.                                         *
//***************************************************************

double calcPaintCost(int paintGallons) {
	return paintGallons * gallonCost;
}


//***************************************************************
// Defintion of calcLaborCost.                                  *
// This function calculates the labor cost. The function is     *
// passed the amount of paint needed, and is multiplied by the  *
// global constant LABOR_UNIT_COST, and the product is          *
// returned.                                                    *
//***************************************************************

double calcLaborCost(int paintGallons) {
	return paintGallons * LABOR_UNIT_COST;
}


//***************************************************************
// Defintion of calcJobCost.                                    *
// This function calculates the total cost of the paint job.    *
// This function is passed the global variable gallonCost, and  *
// laborCost. These values are summed and returned.             *                                                    *
//***************************************************************

double calcJobCost(double gallonCost, double laborCost) {
	return gallonCost + laborCost;
}


//***************************************************************
// Defintion of getPaintData.                                   *
// This function outputs the details of the paint job. The      *
// function is passed five parameters, calculated by other      *
// functions. The results are output and formatted.             *
//***************************************************************

void getPaintData(int paintGallons, int laborHours, double paintCost, double laborCost, double jobCost) {
	cout << endl;
	cout << "Paint Required:" << setw(5) << paintGallons << setw(8) << "Gallons" << endl;
	cout << "Labor Required:" << setw(5) << laborHours << setw(8) << "Hours" << endl;
	cout << setw(17) << "Paint: $" << right << setw(7) << setprecision(2) << fixed << paintCost << endl;
	cout << setw(17) << "Labor: $" << right << setw(7) << setprecision(2) << fixed << laborCost << endl;
	cout << setw(17) << "Total: $" << right << setw(7) << setprecision(2) << fixed << jobCost << endl;
}
