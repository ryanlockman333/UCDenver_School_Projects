// This program tests a password for the American Equities
// web page to see if the format is correct
// Ryan Lockman: 101430670

// Headers
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std; 

// Function Prototypes
bool testPassWord(char[]);  
int countLetters(char*);
int countDigits(char*);

int main() {
	char passWord[20];  
	
	cout << "Enter a password consisting of exactly 4 "
		 << "letters, 6 digits, and only lower case:\n";
	cin.getline(passWord,20);

	if(testPassWord(passWord))
		cout << "\nPlease wait - your password is being verified\n";
	else
		cout << "\nInvalid password. Please enter a password"
		     << "\nwith exactly 4 letters, 6 digits, and only lower case."
			 << "\nFor example, my375619by is valid.";
	
	cout << "\n\nThe number of letters in the password is: " << countLetters(passWord)
	     << "\nThe number of digits in the password is:  "   << countDigits(passWord);

	return 0;
}

//**************************************************************
//                       testPassWord
//
// task:			determines if the word contained in the
//				    character array passed to it, contains
//					exactly 4 letters and 6 digits.
// data in:			a word contained in a character array
// data returned:   true if the word contains 4 letters & 6
//					digits, false otherwise
//
//**************************************************************
bool testPassWord(char custPass[]) {
	bool is;
	
	int length     = strlen(custPass);
    int numLetters = countLetters(custPass);
	int numDigits  = countDigits(custPass);
	
	for(int i = 0; i < length; ++i)
		if(isupper(custPass[i])) {
			is = false;
			break;
		}
		else
			is = true;
	
	if(numLetters == 4 && numDigits == 6 && length == 10 && is == true)
		return true;
	else
		return false;
}

// the next 2 functions are from Sample Program 10.5
//**************************************************************
//                       countLetters
//
// task:			counts the number of letters (both
//                  capital and lower case in the string
// data in:			a string 
// data returned:   the number of letters in the string
//
//**************************************************************
int countLetters(char *strPtr) {
	int occurs = 0;

	while(*strPtr != '\0') {
		if(isalpha(*strPtr))  
			occurs++;
		strPtr++;
	}

	return occurs;
}

//**************************************************************
//                       countDigits
//
// task:			counts the number of digits in the string
// data in:			a string 
// data returned:   the number of digits in the string
//
//**************************************************************
int countDigits(char *strPtr) {  
	int occurs = 0;

	while(*strPtr != '\0') {
		if(isdigit(*strPtr))  // isdigit determines if the character is a digit
			occurs++;
		strPtr++;
	}

	return occurs;
}
