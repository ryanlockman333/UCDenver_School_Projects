// This program finds the average time spent programming by a student
// each day over a three day period.
// Ryan Lockman: 101430670

// Headers
#include <iostream>
using namespace std;

int main() {
	int   numStudents = 0, nDays     = 0;
	float programming = 0, biology   = 0;
	float totalBio    = 0, totalProg = 0, averageBio = 0, averageProg = 0;
    int   student     = 0, day       = 0;              // these are the counters for the loops

	cout << "This program will find the average number of hours a day" 
         << "\n that a student spent in programming and in biology over a long weekend\n\n";
    cout << "How many students are there?" << endl << endl;
    cin  >> numStudents;
	cout << "How many days a week did you work?" << endl;
	cin  >> nDays;
       
    for(student = 1; student <= numStudents; student++) {
		for(day = 1; day <= nDays; day++) {
			cout << "Please enter the number of programming hours worked by student " 
				 << student <<" on day " << day << "." << endl;
            cin  >> programming;
			cout << "Please enter the number of biology hours worked by student " 
				 << student <<" on day " << day << "." << endl;
            cin  >> biology;
			
			totalProg = totalProg + programming;
            totalBio  = totalBio + biology;
		}
		
		averageProg = totalProg / nDays;
        averageBio  = totalBio / nDays;

		cout << endl;
		cout << "The average number of hours per day spent on programming by "
		     << "student " << student << " is " << averageProg
			 << endl << endl << endl;
		cout << "The average number of hours per day spent on biology by "
		     << "student " << student << " is " << averageBio
			 << endl << endl << endl;
			 
		if(averageProg > averageBio)
			cout << "Student " << student << " spent most of their hours studying "
				 << "programming";
		else if(averageProg < averageBio)
			cout << "Student " << student << " spent most of their hours studying "
				 << "biology";
		else if(averageProg == averageBio)
			cout << "Student " << student << " spent the same amount of their hours"
				 << " studying programming and biology";
		cout << endl << endl;
	}

    return 0;	
}