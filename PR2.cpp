#include <iostream>
using namespace std;

int main() {
    int marks;
    
    char grade;

    cout << "Enter marks out of 100: ";
    cin >> marks;

    grade = (marks >= 90) ? 'A' :
            (marks >= 80) ? 'B' :
            (marks >= 70) ? 'C' :
            (marks >= 60) ? 'D' : 'F';

    cout << "Your Grade: " << grade << endl;
    
    switch(grade) {
        case 'A':
            cout << "Excellent Work!" << endl;
            break;

        case 'B':
            cout << "Well done" << endl;
            break;

        case 'C':
            cout << "Good job" << endl;
            break;

        case 'D':
            cout << "You Passed, but you could do better" << endl;
            break;

        case 'F':
            cout << "Sorry, you failed" << endl;
            break;
    }
    if (grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D') {
        cout << "Congratulations! You are eligible for the next level." << endl;
    } 
    else {
        cout << "Please try again next time." << endl;
    }

    return 0;
}