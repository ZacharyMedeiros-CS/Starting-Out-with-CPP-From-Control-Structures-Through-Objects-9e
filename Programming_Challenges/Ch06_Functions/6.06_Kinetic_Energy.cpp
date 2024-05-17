//
// A program that prompts the user for an object's mass and 
// velocity and passes these values to a function that returns
// the object's kinetic energy
//

/*
 Chapter 06 Programming Challenge 06 Kinetic Energy 

 In physics, an object that is in motion is said to have kinetic energy. The following
 formula can be used to determine a moving object's kinetic energy:

 KE = (1/2)mv^2

 The variables in the formula are as follows: KE is the kinetic energy, m is the object's
 mass in kilograms, and v is the object's velocity, in meters per second.
 Write a function named kineticEnergy that accepts an object's mass (in kilograms)
 and velocity (in meters per second) as arguments. The function should return the
 amount of kinetic energy that the object has. Demonstrate the function by calling it in
 a program that asks the user to enter values for mass and velocity.
*/


#include <iostream>  // for cout, cin

using namespace std;

// Function Prototypes
double kineticEnergy(double, double);

int main() {

	double mass,  // holds the object's mass
		 velocity;  // holds the object's velocity


	// User prompt
	cout << "Mass: ";
	cin >> mass;
	cout << "Velocity: ";
	cin >> velocity;

	// Call function and output results
	cout << "\nKinetic Energy: " << kineticEnergy(mass, velocity) << endl;


	return 0;
}


// Function Definition
double kineticEnergy(double mass, double velocity) {
	// Formula: Kinetic Energy = (1/2) * mass * velocity^2
	return 0.5 * mass * velocity * velocity;
}
