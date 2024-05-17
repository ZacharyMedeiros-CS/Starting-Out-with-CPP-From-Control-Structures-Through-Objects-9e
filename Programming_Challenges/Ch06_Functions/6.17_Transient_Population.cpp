//
// This program uses a modified population growth formula,
// to include the arrivals and departures of a population,
// in a geographic location. 
//

/*
 Chapter 06 Programming Challenge 17 Transient Population

 Modify Programming Challenge 16 to also consider the effect on population caused by
 people moving into or out of a geographic area. Given as input a starting population
 size, the annual birth rate, the annual death rate, the number of individuals who typi-
 cally move into the area each year, and the number of individuals who typically leave
 the area each year, the program should project what the population will be numYears
 from now. You can either prompt the user to input a value for numYears, or you can
 set it within the program.

 Input Validation: Do not accept numbers less than 2 for starting size. Do not accept
 negative numbers for birth rate, death rate, arrivals, or departures.
*/


#include <iostream>  // for cout, cin
#include <iomanip>   // fixed, setprecision(), setw()
using namespace std;

// Function Prototypes
double populationSize(double, double, double, double, double);


int main() {

	// Variables
	double arrivals = 0,  // holds the amount of population arrivals
		   departures = 0,  // holds the amount population departures
		    birthRate = 0,  // holds the population's birth rate
		    deathRate = 0,  // holds the population's death rate
		     numYears = 0;  // holds the number of years to display

	static double population = 0;  // holds the population size


	// Program Title
	cout << "\t\tTransient Population Growth\n";

	// Input Validation while loop
	while (population < 2 || birthRate < 0 || deathRate < 0 || arrivals < 0 || departures < 0) {
		// Prompt user
		cout << "\nCurrent Population: ";
		cin >> population;
		cout << "Birth Rate (percentage): ";
		cin >> birthRate;
		cout << "Death Rate (percentage): ";
		cin >> deathRate;
		cout << "Arrivals: ";
		cin >> arrivals;
		cout << "Departures: ";
		cin >> departures;
		cout << "Growth Period (years): ";
		cin >> numYears;

		// Input Validation
		if (population < 2 || birthRate < 0 || deathRate < 0 || arrivals < 0 || departures < 0) {
			cout << "\nInvalid Input"
				   << "\n* Current Population cannot be less than 2"
			   	 << "\n* Birth Rate, Death Rate, Arrivals, and Departures"
				   << "\n  cannot be a negative value" << endl;
		}
	}

	// If the user enters a value less than one for 
	// the growth period, a default value of 20 years 
	// will be assigned to numYears
	if (numYears < 1) {
		numYears = 20;
		cout << "\nThe default growth period of 20 years will be used"
		     << "\nwhen the value entered is less than 1 year." << endl;
	}

	// Output results
	// A for loop calculates the population for the entered amount of years
	for (int i = 0; i <= numYears; i++) {
		// The static local variable population maintains a running value, 
		// needed for the population growth formula
		population = populationSize(population, birthRate, deathRate, arrivals, departures);
	}

	// Format and print results
	cout << "\nPopulation: " << fixed << setprecision(1) << population << endl;


	return 0;
}


// Function Definitions
//***************************************************************
// Defintion of populationSize.                                 *
// This function uses the formula N = P + BP - DP + a - d to    *
// calculate and return population size. Where,                 *
// * N is the new population size                               *
// * P is the previous population size                          *
// * B is the birthrate                                         *
// * D is the deathrate                                         *
// * a is the arrivals                                          *
// * d is the departures                                        *
//***************************************************************

double populationSize(double previousPopSize, double birthRate, double deathRate, double arrivals, double departures) {
	// Convert percentage to a decimal
	birthRate /= 100;
	deathRate /= 100;
	return (previousPopSize + (birthRate * previousPopSize) - (deathRate * previousPopSize)) + arrivals - departures;
}
