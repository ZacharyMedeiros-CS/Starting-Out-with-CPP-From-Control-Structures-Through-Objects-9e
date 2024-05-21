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
	int choice;                      // holds the user's menu choice
	int days = -1;                   // holds number of days

	double dailyRate = -1,           // holds the hospitol's daily stay rate
		    medication = -1,           // holds the medication charges
		      services = -1;           // holds the services charges

	double patientCharges = 0;       // holds the patient's total charges

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
		while (days < 0 || dailyRate < 0 || medication < 0 || services < 0) {
			cout << "* Number of days spent in the hospital: ";
			cin >> days;
			cout << "* Daily rate: $";
			cin >> dailyRate;
			cout << "* Medication charges: $";
			cin >> medication;
			cout << "* Services charges: $";
			cin >> services;

			// Input validation
			// Do not accept any negative values
			if (days < 0 || dailyRate < 0 || medication < 0 || services < 0) {
				// Error message
				cout << "\nInvalid Input\n* Negative values are not accepted\n";
				cout << "\nEnter the following - " << endl;
			}
		}

		// Call totalCharges() passing into the function the inpatient's data,
		// store the output of totalCharges() in patientCharges
		patientCharges = totalCharges(days, dailyRate, medication, services);
		break;

	case OUTPATIENT_CHOICE:
		// Outpatient user prompt
		while (medication < 0 || services < 0) {
			cout << "* Medication charges: $";
			cin >> medication;
			cout << "* Services charges: $";
			cin >> services;

			// Input validation
			// Do not accept any negative values
			if (medication < 0 || services < 0) {
				// Error message
				cout << "\nInvalid Input\n* Negative values are not accepted\n";
				cout << "\nEnter the following -\n";
			}
		}

		// Call totalCharges() passing into the function the outpatient's data,
		// store the output of totalCharges() in patientCharges
		patientCharges = totalCharges(medication, services);
		break;
	}

	// Output results
	cout << "\n\n- Hospital Report -\n";
	
	// if statement is used to determine inpatient or outpatient output
	if (choice == 1) {  // inpatient
		// Print to console
		cout << "Inpatient Charges\n\n";
		cout << "Number of Days ... " << days << endl;
		cout << "Daily Rate ....... $" << fixed << setprecision(2) << dailyRate << endl;
		cout << "Medications ...... $" << fixed << setprecision(2) << medication << endl;
		cout << "Services ......... $" << fixed << setprecision(2) << services << endl;
		cout << "Total ............ $" << fixed << setprecision(2) << patientCharges << endl;
}

	if (choice == 2) {  // outpatient
		// Print to console
		cout << "Outpatient Charges\n\n";
		cout << "Medications ... $" << fixed << setprecision(2) << medication << endl;
		cout << "Services ...... $" << fixed << setprecision(2) << services << endl;
		cout << "Total ......... $" << fixed << setprecision(2) << patientCharges << endl;
}
	cout << endl;
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

