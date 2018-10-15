// This program demonstrates the use of pointer variables
// It finds the area of a rectangle given length and width
// It prints the length and width in ascending order 
// Ryan Lockman: 101430670

// Headers
#include <iostream>
using namespace std;

int main() {
   int length = 0;		// holds length
   int width  = 0;		// holds width
   int area   = 0;		// holds area
 
   int *lengthPtr = NULL;	// int pointer which will be set to point to length
   int *widthPtr  = NULL;   // int pointer which will be set to point to width

   cout << "\nPlease input the length of the rectangle: ";
   cin  >> length;
   cout << "\nPlease input the width of the rectangle:  ";
   cin  >> width;

   lengthPtr = &length;
   widthPtr  = &width;

   area = (*lengthPtr) * (*widthPtr);
   cout << "\nThe area is " << area << endl;

   if(*lengthPtr > *widthPtr)
    	cout << "\nThe length is greater than the width\n";
   else if(*widthPtr > *lengthPtr)
    	cout << "\nThe width is greater than the length\n";
   else 
    	cout << "\nThe width and length are the same\n";

   return 0;
}

/* The output is
Please input the length of the rectangle: 10

Please input the width of the rectangle:  15

The area is 150

The width is greater than the length
*/
