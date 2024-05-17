//
// This program finds the average of missed days at a company 
// using multiple funtions
//

/*
 Chapter 06 Programming Challenge 12 Days Out 

 Write a program that calculates the average number of days a company's employees are
 absent. The program should have the following functions:

 * A function called by main that asks the user for the number of employees in the
	 company. This value should be returned as an int. (The function accepts no argu-
	 ments.)
 * A function called by main that accepts one argument: the number of employees in
	 the company. The function should ask the user to enter the number of days each
	 employee missed during the past year. The total of these days should be returned as
	 an int.
 * A function called by main that takes two arguments: the number of employees in
	 the company and the total number of days absent for all employees during the year.
	 The function should return, as a double, the average number of days absent. (This
	 function does not perform screen output and does not ask the user for input.)

	 Input Validation: Do not accept a number less than 1 for the number of employees. Do
	 not accept a negative number for the days any employee missed.
*/


#include <iostream>

using namespace std;

// Function Prototypes
int numberOfEmployees();
int missedDays(int);
double avgDaysAbsent(int, int);

int main() {
	// Variables
	int employees,  // holds the number of employees at the company
					 days;  // holds the number of days absent


	// Call numberOfEmployees() and missedDays() to collect data from user
	employees = numberOfEmployees();
	days = missedDays(employees);


	// Call avgDaysAbsent() and print output
	cout << "\nThe average number of days missed per employee: " << avgDaysAbsent(employees, days) << endl;

	return 0;
}

// Function Definitions
//**********************************************************
// Definition of numberOfEmployees.                        *
// This function prompts the user for the number of        *
// employees. The input validation while loop verifies     *
// there is at least one employee. The number of employees *
// is returned by the function.                            *
//**********************************************************

int numberOfEmployees() {
	int employees;
	cout << "Enter the number of employees: ";
	cin >> employees;
	// Input Validation
	while (employees < 1) {
		cout << "\nInvalid Input\nNumber of employees cannot be less than 1" << endl;
		cout << "Enter the number of employees: ";
		cin >> employees;
	}
	return employees;
}


//**********************************************************
// Definition of missedDays.                               *
// This function prompts the user for the number of missed *
// days, for each employee, iteratively. The number of     *
// missed days cannot be less than zero, and is validated  *
// through the while loop. The days variable keeps a       *
// running total of all employee's missed days.            *
//**********************************************************

int missedDays(int employees) {
	int days = 0;  // holds a running total of all missed days
	for (int i = 1; i <= employees; i++) {
		cout << "Enter days missed for employee " << i << ": ";
		cin >> days;
		// Input validation
		while (days < 0) {
			cout << "\nInvalid Input\nDays missed cannot be less than 0" << endl;
			cout << "Enter days missed for employee " << i << ": ";
			cin >> days;
		}
		days += days;
	}
	return days;
}


//**********************************************************
// Definition of avgDaysAbsent.                            *
// This function calculates and returns, the average       * 
// number of days missed for the company.                  *
//**********************************************************

double avgDaysAbsent(int employees, int days) {
	return days / employees;
}
