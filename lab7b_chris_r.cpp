// This program will input an undetermined number of student names
// and a number of scores for each student. The number of scores is
// given by the user. The scores are stored in an array.
// Two functions are called for each student.
// One function will give the numeric average of their scores.
// The other function will give a letter grade to that average.
// Grades are assigned on a 10 point spread.
// 90-100 A	80-89 B	70-79 C	60-69 D	Below 60 F

// CRUMBLE
// 04/22/2025

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAXSCORES = 25; // maximum number of scores per student

float findScoreAvg(int[], int); // finds and return average by taking array of
                                // scores and number of scores as parameters

char findLetterGrade(float); // finds letter grade from average given
                             // to it as a parameter

int main()
{

    int Scores[MAXSCORES];      // one dimensional integer array to store scores
    string firstname, lastname; // Student's first and last name
    int numOfScores;            // holds the number of scores per student
    float average;              // holds the average of a student's grade
    char moreInput;             // determines if there is more input

    cout << fixed << setprecision(2) << showpoint;

    // Input the number of scores for each student
    cout << "Please input the number of scores each student will receive." << endl
         << "This must be a number between 1 and " << MAXSCORES << " inclusive"
         << endl;
    cin >> numOfScores;

    // Force the user to input number of scores is between 1 and MAXSCORES inclusive
    while (numOfScores > MAXSCORES || numOfScores < 1)
    {
        cout << "Please input the number of scores for each student." << endl
             << "This must be a number between 1 and " << MAXSCORES
             << " inclusive\n";
        cin >> numOfScores;
    }

    // Input names and scores for each student
    cout << "Please input a y if you want to input more students"
         << " any other character will stop the input" << endl;
    cin >> moreInput;

    while (moreInput == 'y' || moreInput == 'Y')
    {
        cout << "Please input the first name of the student" << endl;
        cin >> firstname;

        cout << endl
             << "Please input the last name of the student" << endl;
        cin >> lastname;

        cout << "Enter " << numOfScores << " scores for " << firstname << " " << lastname << endl;

        for (int count = 0; count < numOfScores; count++)
        {
            cout << endl
                 << "Please input score #" << count + 1 << ": ";

            // Fill in the input statement to place score in the array
            cin >> Scores[count];
        }
        // Output the name and average.
        cout << firstname << " " << lastname << " has an average of ";

        // Function call to get and then print average of student to screen
        average = findScoreAvg(Scores, numOfScores);
        cout << average << ". ";
        // Output the name and letter grade.
        cout << firstname << " " << lastname << "'s letter grade is ";

        // Function call to get and then print letter grade of student to screen.
        cout << findLetterGrade(average) << ". "; // call the function to get the letter grade.
        cout << endl
             << endl
             << endl; // print a blank line for spacing.
        // Ask the user if they want to input more students.
        cout << "Please input a y if you want to input more students"
             << " any other character will stop the input" << endl;
        // Get user input to see if they want to continue.
        cin >> moreInput;
    }
    return 0;
}

//***********************************************************************
//
// task:	      This function finds the average of the
//                numbers stored in an array.
//
// data in:	      an array of integer numbers
// data returned: the average of all numbers in the array
//
//***********************************************************************

float findScoreAvg(int s[], int numOfScores)
{
    // Fill in the code for this function
    // Use a for loop to find the average of the scores in the array
    float sum = 0.0;
    for (int i = 0; i < numOfScores; i++)
    {
        sum += s[i];
    }
    return sum / numOfScores;
}

//***********************************************************************
//
// task:	      This function finds the letter grade for the number
//                passed to it by the calling function
//
// data in:	      a floating point number
// data returned: the letter grade (based on a 10 point spread)
//                90-100 A	80-89 B	70-79 C	60-69 D	Below 60 F
//
//***********************************************************************

char findLetterGrade(float Average)
{
    // Fill in the code for this function
    // Use a switch statement to determine the letter grade
    switch (static_cast<int>(Average / 10))
    {
    case 10:
    case 9:
        return 'A';
    case 8:
    case 7:
        return 'B';
    case 6:
    case 5:
        return 'C';
    case 4:
    case 3:
        return 'D';
    case 2:
    case 1:
        return 'F';
    default:
        return 'F';
    }
}
