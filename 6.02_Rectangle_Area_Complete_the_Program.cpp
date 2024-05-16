//
// This program calculates the area of a rectangle, using user 
// entered width and length values, and then displays the 
// rectangle's data back to the user.
//

/*
 Chapter 6 Programming Challenge - Rectangle Area-Complete the Program
 If you have downloaded this book's source code, you will find a partially written pro-
 gram named AreaRectangle.cpp in the Chapter 06 folder. Your job is to complete the
 program. When it is complete, the program will ask the user to enter the width and 
 length of a rectangle, then display the rectangle's area. The program calls the following
 functions, which have not been written:

 * getLength-This function should ask the user to enter the rectangle's length then
   return that value as a double.
 * getWidth-This function should ask the user to enter the rectange's width then
   return that value as a double.
 * getArea-This function should accept the rectangle's length and width as argu-
   ments and return the rectangle's area. The area is calculated by multiplying the
   length by the width.
 * displayData-This function should accept the rectangle's length, width, and area
   as arguments and display them in an appropriate message on the screen.


 Link to book's source code:
   https://media.pearsoncmg.com/ph/esm/ecs_gaddis_sow_cpp_cso_9/cw/
*/


#include <iostream>
using namespace std;

// Write the prototypes for the getLength,
// getWidth, getArea, and displayData
// functions here.

// Function Prototypes
double getLength();
double getWidth();
double getArea(double, double);
void displayData(double, double, double);

int main()
{
   double length,    // The rectangle's length
          width,     // The rectangle's width
          area;      // The rectangle's area
          
   // Get the rectangle's length.
   length = getLength();
   
   // Get the rectangle's width.
   width = getWidth();
   
   // Get the rectangle's area.
   area = getArea(length, width);
   
   // Display the rectangle's data.
   displayData(length, width, area);
          
   return 0;
}

//***************************************************
// You must write the getLength, getWidth, getArea, *
// and displayData functions.                       *
//***************************************************

double getLength() {
    double length;
    cout << "Enter the rectangle's length: ";
    cin >> length;
    return length;
}

double getWidth() {
    double width;
    cout << "Enter the rectanlge's width: ";
    cin >> width;
    return width;
}

double getArea(double length, double width) {
    return length * width;
}

void displayData(double length, double width, double area) {
    cout << "\nRectangle Data" << endl;
    cout << "Length...." << length << endl;
    cout << "Width....." << width << endl;
    cout << "Area......" << area << endl;
}
