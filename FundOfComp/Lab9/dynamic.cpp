// This program demonstrates the use of dynamic variables
// Ryan Lockman: 101430670

// Headers
#include <iostream>
using namespace std;

// Global Constants
const int MAXNAME = 10;

int main() {
   int  pos    = 0;
   char *name  = NULL;
   int  *one   = NULL;
   int  *two   = NULL;
   int  *three = NULL;
   int  result = 0;

   one   = new int;
   two   = new int;
   three = new int;
   name  = new char;

   cout << "\nEnter your last name with exactly 10 characters.\n"
        << "If your name has < 10 characters, repeat last letter.\n"
		<< "Blanks at the end do not count.\n";
   
   for(pos = 0; pos < MAXNAME; ++pos)
	  cin  >> *(name+pos);    // name[pos] works also

   cout << "\nHi ";
   for(pos = 0;  pos < MAXNAME; ++pos)
      cout << *(name+pos);    // name[pos] works also
  
   cout << "\nEnter three integer numbers separated by blanks: ";
   cin  >> *one;
   cin  >> *two;
   cin  >> *three;

   //echo print
   cout << "\nThe three numbers are: " << *one << " " << *two << " " << *three;

   result = *one + *two + *three;
   cout << "\nThe sum of the three values is " << result << endl;

   delete one;
   delete two;
   delete three;

  return 0;
}

// A bracket(subscript) is unnecessary because you can move the position by
//  *(name+pos), using the dereference operator, because it is an array.
// Yes if you do name[pos], not using the dereference operator, you can use
//  cin and cout to input and output, because a pointer points to the first element
//  of an array and the [pos] then steps through.
