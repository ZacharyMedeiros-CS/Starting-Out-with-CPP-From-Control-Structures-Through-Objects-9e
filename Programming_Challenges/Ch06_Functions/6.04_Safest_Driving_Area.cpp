//
// This program uses a function, to apply a markup to the
// wholesale cost of an item, for retail purchase.
//

/*
 Chapter 6 Programming Challenge 4 Safest Driving Area
 Write a program that determines which of five geographic regions within a major city
 (north, south, east, west, central) had the fewest reported automobile accidents last
 year. It should have the following two functions, which are called by main:

 * int getNumAccidents() is passed the name of a region. It asks the user for the
   number of automobile accidents reported in that region during the last year, vali-
   dates the input, then returns it. It should be called once for each city rergion.
 
 * void findLowest() is passed the five accident totals. It determines which is the 
   smallest and prints the name of the region, along with its accident figure.

 Input Validation: Do not accept an accident number that is less than 0.

*/

#include <iostream>  // for cout, cin
using namespace std;


// Function Prototypes
int getNumAccidents(string);
void findLowest(int, int, int, int, int);


int main() {

  // Variables
  string const NORTH = "North",    // Holds the name of the region that 
               SOUTH = "South",    // is passed to getNumAccidents()
                EAST = "East", 
                WEST = "West", 
             CENTRAL = "Central";

  int nAccidents,  // Holds the number of accidents for each region, 
      sAccidents,  // and is then passed to findLowest()
      eAccidents, 
      wAccidents, 
      cAccidents;


  // Algorithm
  // Step 1) Store the number of accidents by calling 
  //         getNumAccidents() for each region
  // Step 2) Determine and print which region has the lowest
  //         amount of accidents by calling findLowest()


  // + Step 1)
  nAccidents = getNumAccidents(NORTH);
  sAccidents = getNumAccidents(SOUTH);
  eAccidents = getNumAccidents(EAST);
  wAccidents = getNumAccidents(WEST);
  cAccidents = getNumAccidents(CENTRAL);

  // + Step 2)
  findLowest(nAccidents, sAccidents,eAccidents, wAccidents, cAccidents);


  cout << endl;
  return 0;

}


// Function Definitions
//****************************************************
// Definition of function getNumAccidents. This      *
// function is passed the name of a region, asks the *
// user for the number of accidents for that region, *
// validates the input, and then returns the         *
// accident count.                                   *
// ***************************************************

int getNumAccidents(string region) {
  int accidentCount = -1;  // Holds the number of accidents in the region

  // If accidentCount is less than 0, stay in while loop to 
  // ensure valid input is returned by the function
  while (accidentCount < 0) {
    cout << "Enter the number of accidents for the " << region << " region: ";
    cin >> accidentCount;

    // Input validation error message
    if (accidentCount < 0) {
      cout << "\nInvalid Input\n * Number of accidents cannot be less than 0\n" << endl;
    }
  }
  return accidentCount;
}


//****************************************************
// Definition of function findLowest. This function  *
// is passed the number of accidents for each        *
// region. The region with the lowest number of      *
// accidents is determined, and printed with the     *
// name of it's region.                              *
// ***************************************************

void findLowest(int north, int south, int east, int west, int central) {
  int lowest = north;  // Holds the region with the lowest accident
                       // count initialized with the north region

  string region = "North";  // Holds the name of the region with the
                            // lowest accident count

  // Determine the lowest value by storing and comparing every region's
  // accident count, and assigning lowest to the smallest value along
  // with the name of the region to region.
  if (south < lowest) {
    lowest = south;
    region = "South";
  }
  if (east < lowest) {
    lowest = east;
    region = "East";
  }
  if (west < lowest) {
    lowest = west;
    region = "West";
  }
  if (central < lowest) {
    lowest = central;
    region = "Central";
  }

  // Output results
  cout << "\nLowest amount of accidents: " << lowest;
  cout << " in the " << region << " region" << endl;
}

