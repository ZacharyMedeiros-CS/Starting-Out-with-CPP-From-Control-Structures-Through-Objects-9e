//
// A progam that uses two overloaded functions to calculate
// a patient's total hospital charges
//

/*
 Chapter 06 Programming Challenge 15 Overloaded Hospital

 Write a program that computes and displays the charges for a patient's hospital
 stay. First, the program should ask if the patient was admitted as an inpatient or an
 outpatient. If the patient was an inpatient, the following data should be entered:

 * The number of days spent in the hospital
 * The daily rate
 * Hospital medication charges
 * Charges for hospital services (lab tests, etc.)

 The program should ask for the following data if the patient was an outpatient:

 * Charges for hospital services (lab tests, etc.)
 * Hospital medication charges

 The program should use two overloaded functions to calculate the total charges. One
 of the functions should accept arguments for the inpatient data, while the other func-
 tion accepts arguments for outpatient information. Both functions should return the
 total charges.

 Input Validation: Do not accept negative numbers for any data.
 */


#include <iostream> // for cout, cin
#include <iomanip>  // for setprecision(), fixed

using namespace std;

// Function Prototypes
double totalCharges(int, double, double, double);
double totalCharges(double, double);


int main() {

	// Variables
	int days,  // holds the number of day's stayed in the hospitol
		choice;  // holds the user's menu choice

	double dailyRate,  // holds the hospitol's daily stay rate
		    medication,  // holds the medication charges
		      services;  // holds the services charges

	double patientCharges = 0;  // holds the patient's total charges

	const int INPATIENT_CHOICE = 1,  // Inpatient menu option
		       OUTPATIENT_CHOICE = 2;  // Outpatient menu option


	// Display the menu and get the user's choice
	cout << "\n\t\tThe Overloaded Hospital\n\n"
		   << "1. Inpatient\n"
		   << "2. Outpatient\n"
		   << "\nEnter your choice: ";
	// Store the user's menu choice
	cin >> choice;

	// Prompt user for patient data input
	cout << "\nEnter the following - " << endl;

	// Switch statement controls which overloaded function will be  
	// called and passed the patient's data
	switch (choice) {
	case INPATIENT_CHOICE:
		// Inpatient user prompt
		cout << "Number of days spent in the hospital: ";
		cin >> days;
		cout << "Daily rate: ";
		cin >> dailyRate;
		cout << "Medication charges: ";
		cin >> medication;
		cout << "Services charges: ";
		cin >> services;

		// Input validation
		// Do not accept any negative values
		while (days < 0 || dailyRate < 0 || medication < 0 || services < 0) {
			// Error message
			cout << "\nInvalid Input\n* Negative values are not accepted\n";
			cout << "\nNumber of days spent in the hospital: ";
			cin >> days;
			cout << "Daily rate: ";
			cin >> dailyRate;
			cout << "Medication charges: ";
			cin >> medication;
			cout << "Services charges: ";
			cin >> services;
		}

		// Call totalCharges() passing into the function the inpatient's data,
		// store the output of totalCharges() in patientCharges
		patientCharges = totalCharges(days, dailyRate, medication, services);
		break;

	case OUTPATIENT_CHOICE:
		// Outpatient user prompt
		cout << "Medication charges: ";
		cin >> medication;
		cout << "Services charges: ";
		cin >> services;

		// Input validation
		// Do not accept any negative values
		while (medication < 0 || services < 0) {
			// Error message
			cout << "\nInvalid Input\n* Negative values are not accepted\n";
			cout << "\nMedication charges: ";
			cin >> medication;
			cout << "Services charges: ";
			cin >> services;
		}

		// Call totalCharges() passing into the function the outpatient's data,
		// store the output of totalCharges() in patientCharges
		patientCharges = totalCharges(medication, services);
		break;
	}

	// Output results
	cout << setprecision(2) << fixed;
	cout << "\nPatient Charges $" << patientCharges << endl;

	return 0;
}


// Function Definitions
//***************************************************************
// Defintion of overloaded function totalCharges.               *
// This function uses five parameters to calculate and return   *
// the total charges due for an inpatient.                      *
//***************************************************************
double totalCharges(int days, double dailyRate, double medication, double services) {
	return days * dailyRate + medication + services;
}

// Outpatient
//***************************************************************
// Defintion of overloaded function totalCharges.               *
// This function uses two parameters to calculate and return    *
// the total charges due for an outpatient.                     *
//***************************************************************
double totalCharges(double medication, double services) {
	return medication + services;
}

