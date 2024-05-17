//
// A program that uses a static local variable to calculate 
// the growth of a population for a specified number of years
//

/*
 Chapter 06 Programming Challenge 16 Population

 In a population, the birth rate is the percentage increase of the population due to births,
 and the death rate is the percentage decrease of the population due to deaths. Write a
 program that displays the size of a population for any number of years. The program
 should ask for the following data:

 * The starting size of a population
 * The annual birth rate
 * The annual death rate
 * The number of years to display

 Write a function that calculates the size of the population for a year. The formula is

 N = P + BP - DP

 where N is the new population size, P is the previous population size, B is the birth rate,
 and D is the death rate.

 Input validation: Do not accept numbers less than 2 for the starting size. Do not accept
 negative numbers for birth rate or death rate. Do not accept numbers less than 1 for
 the number of years.
*/


#include <iostream>  // for cout, cin
#include <iomanip>   // fixed, setprecision(), setw()
using namespace std;

// Function Prototypes
double populationSize(double, double, double);


int main() {

	// Variables
	double birthRate = 0,  // holds the population's birth rate
		     deathRate = 0,  // holds the population's death rate
		         years = 0;  // holds the number of years to display

	static double population = 0;  // holds the population size


	// Program Title
	cout << "\t\tPopulation Growth\n";

	// Input Validation while loop
	while (population < 2 || birthRate < 0 || deathRate < 0 || years < 1) {
		// Prompt user
		cout << "\nCurrent Population: ";
		cin >> population;
		cout << "Birth Rate (percentage): ";
		cin >> birthRate;
		cout << "Death Rate (percentage): ";
		cin >> deathRate;
		cout << "Growth Period (years): ";
		cin >> years;

		// Input Validation
		if (population < 2 || birthRate < 0 || deathRate < 0 || years < 1) {
			cout << "\nInvalid Input"
				   << "\n* Current Population cannot be less than 2"
				   << "\n* Birth Rate and Death Rate cannot be a negative value"
				   << "\n* Years cannot be less than 1" << endl;
		}
	}


	// Output results
	// A for loop calculates the population for the entered amount of years
	for (int i = 1; i <= years; i++) {
		// The static local variable population maintains a running value, 
		// needed for the population growth formula
		population = populationSize(population, birthRate, deathRate);
	}
	// Format and print results
	cout << "\nPopulation: " << fixed << setprecision(1) << population << endl;

	return 0;
}


// Function Definitions
//***************************************************************
// Defintion of populationSize.                                 *
// This function uses the formula N = P + BP - DP to calculate  *
// and return population size.                                  *
//***************************************************************
double populationSize(double previousPopSize, double birthRate, double deathRate) {
	// Convert percentage to a decimal
	birthRate /= 100;
	deathRate /= 100;
	return previousPopSize + (birthRate * previousPopSize) - (deathRate * previousPopSize);
}
