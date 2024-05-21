//
// A progam that uses two overloaded functions to calculate
// a patient's total hospital charges
//

/*
 Chapter 06 Programming Challenge 19 Using Files - Hospital Report

 Modify Programming Challenge 15 (Overloaded Hospital) to write the report it creates
 to a file.

 */


#include <iostream> // for cout, cin
#include <iomanip>  // for setprecision(), fixed
#include <fstream>  // for ofstream

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
	cout << "\nEnter the following - \n";

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

		// Call totalCharges(), passing into the function the inpatient's data,
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

	// Prepare for file output
	ofstream outputFile;                     // Create ofstream object
	outputFile.open("Hospital_Report.txt");  // Open file for output


	// if statement is used to determine inpatient or outpatient output
	if (choice == 1) {  // inpatient
		// Print to console
		cout << "Inpatient Charges\n\n";
		cout << "Number of Days ... " << days << endl;
		cout << "Daily Rate ....... $" << fixed << setprecision(2) << dailyRate << endl;
		cout << "Medications ...... $" << fixed << setprecision(2) << medication << endl;
		cout << "Services ......... $" << fixed << setprecision(2) << services << endl;
		cout << "Total ............ $" << fixed << setprecision(2) << patientCharges << endl;

		// Write to file
		outputFile << "- Hospital Report -\n";
		outputFile << "Inpatient Charges\n\n";
		outputFile << "Number of Days ... " << days << endl;
		outputFile << "Daily Rate ....... $" << fixed << setprecision(2) <<dailyRate << endl;
		outputFile << "Medication ....... $" << fixed << setprecision(2) << medication << endl;
		outputFile << "Service .......... $" << fixed << setprecision(2) << services << endl;
		outputFile << "Total ............ $" << fixed << setprecision(2) << patientCharges << endl;
	}

	if (choice == 2) {  // outpatient
		// Print to console
		cout << "Outpatient Charges\n\n";
		cout << "Medications ... $" << fixed << setprecision(2) << medication << endl;
		cout << "Services ...... $" << fixed << setprecision(2) << services << endl;
		cout << "Total ......... $" << fixed << setprecision(2) << patientCharges << endl;

		// Write to file
		outputFile << "- Hospital Report -\n";
		outputFile << "Outpatient Charges\n\n";
		outputFile << "Medications ... $" << fixed << setprecision(2) << medication << endl;
		outputFile << "Services ...... $" << fixed << setprecision(2) << services << endl;
		outputFile << "Total ......... $" << fixed << setprecision(2) << patientCharges << endl;
	}
	
	cout << "\n\nWriting to file Hospital_Report.txt ..." << endl;

	// Close the file
	outputFile.close();
	cout << "Done.\n\n";

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

//***************************************************************
// Defintion of overloaded function totalCharges.               *
// This function uses two parameters to calculate and return    *
// the total charges due for an outpatient.                     *
//***************************************************************
double totalCharges(double medication, double services) {
	return medication + services;
}

