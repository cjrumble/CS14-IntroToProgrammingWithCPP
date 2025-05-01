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

const int MAXSCORES = 25;       // maximum number of scores per student
float findScoreAvg(int[], int); // finds and return average by taking array of
                                // scores and number of scores as parameters
char findLetterGrade(float);    // finds letter grade from average given
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

        cout << "Please input the last name of the student" << endl;
        cin >> lastname;
        cout << endl
             << "Please input score #" << 1 << ": ";
        cin >> Scores[0];
        for (int count = 1; count < numOfScores; count++)
        {
            cout << endl
                 << "Please input score #" << count + 1 << ": ";
            cin >> Scores[count];
        }
        cout << firstname << " " << lastname << " has an average of ";
        average = findScoreAvg(Scores, numOfScores);
        cout << average;
        cout << " " << firstname << " " << lastname << "'s letter grade is ";

        cout << findLetterGrade(average);
        cout << endl
             << endl
             << endl;
        cout << "Please input a y if you want to input more students"
             << " any other character will stop the input" << endl;
        cin >> moreInput;
    }
    cout << "Thank you for using the program. Goodbye!" << endl;
    return 0;
}
