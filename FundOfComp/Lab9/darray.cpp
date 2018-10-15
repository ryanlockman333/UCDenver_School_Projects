// This program demonstrates the use of dynamic arrays
// Ryan Lockman: 101430670

// Headers
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   float *monthSales = NULL; // a pointer used to point to an array holding monthly sales
   float total       = 0;    // total of all sales
   float average     = 0;    // average of monthly sales
   int   numOfSales  = 0;    // number of sales to be processed
   int   count       = 0;    // loop counter

   cout << fixed << showpoint << setprecision(2);
   cout << "How many monthly sales will be processed?: ";
   cin  >> numOfSales;

   monthSales = new float[numOfSales];

   if(monthSales == NULL) {
	  cout << "\nError allocating memory!\n";
	  return 1;
   }

   cout << "Enter the sales below\n";
   for(count = 0; count < numOfSales;  count++) {
       cout << "Sales for Month number " << count+1 << ": ";   
	   cin  >> monthSales[count];
	}

   for(count = 0; count < numOfSales; count++)
	   total += monthSales[count];

   average = total/numOfSales;

   cout << "Average Monthly sale is: $" << average << endl;

   delete [] monthSales;

   return 0;
}
