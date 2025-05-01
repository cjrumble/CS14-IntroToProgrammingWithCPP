/* Midterm Exam Part C - Chris Rumble 3/21/2025
If file not empty, determine how many valid scores (0 to 100), and how many invalid scores (less than 0 or greater than 100). Take only the valid scores and determine what letter grade and keep track of how many As, Bs, Cs, Ds, and Fs.
*/

#include <iostream> // Include the library for input and output.
#include <iomanip>  // Include the library for input and output manipulation.
#include <fstream>  // Include the library for file input and output.
using namespace std;

int main() // Main func.
{
    // Initialize the score and average variables.
    double validScores = 0, invalidScores = 0, sum = 0, average = 0, score = 0;
    // Initialize the grade count variables.
    int numAs = 0, numBs = 0, numCs = 0, numDs = 0, numFs = 0;
    // Initialize high and low scores.
    double highScore = 0, lowScore = 0;
    // Initialize the input file.
    ifstream In;
    // Initialize the grade variable.
    string grade;

    // Open input file
    In.open("Scores.txt");

    // Did we locate the Scores.txt file?? Check to make sure before continuing.
    if (!In) // File does not exist or not in the same directory.
    {
        cout << "Input file not found, program stopped." << endl;
        return -1;
    }
    // Continue to read score from input file until end of file, and add them to Sum
    while (!In.eof())
    {
        // Read score from input file.
        In >> score;
        // Check if score is valid.
        if (score >= 0 && score <= 100)
        {
            // Add score to Sum.
            sum += score;
            // Increment number of scores.
            validScores++;
            // Check for high score.
            if (score > highScore)
            {
                highScore = score;
            }
            // Check for low score.
            if (score < lowScore)
            {
                lowScore = score;
            }
            // Determine letter grade.
            if (score >= 90)
            {
                grade = "A";
            }
            else if (score >= 80)
            {
                grade = "B";
            }
            else if (score >= 70)
            {
                grade = "C";
            }
            else if (score >= 60)
            {
                grade = "D";
            }
            else
            {
                grade = "F";
            }
            // Increment letter grade count.
            if (grade == "A")
            {
                numAs++;
            }
            else if (grade == "B")
            {
                numBs++;
            }
            else if (grade == "C")
            {
                numCs++;
            }
            else if (grade == "D")
            {
                numDs++;
            }
            else if (grade == "F")
            {
                numFs++;
            }
        }
        else
            invalidScores++;
    }

    // Make sure the input file is NOT empty. DO NOT divide by zero!
    if (validScores != 0)
    {
        // Calculate the average.
        average = sum / validScores;
        cout << "The number of valid scores: " << validScores << endl;
        cout << "The number of invalid scores: " << invalidScores << endl;
        cout << "The highest valid score: " << highScore << endl;
        cout << "The lowest valid score: " << lowScore << endl;
        cout << "The average of the valid scores: " << average << endl;
        cout << "Number of As: " << numAs << endl;
        cout << "Number of Bs: " << numBs << endl;
        cout << "Number of Cs: " << numCs << endl;
        cout << "Number of Ds: " << numDs << endl;
        cout << "Number of Fs: " << numFs << endl;
    }
    else
        cout << "Input file is empty, no average" << endl;

    In.close();

    return 0;
}
