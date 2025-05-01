/* Chris Rumble 3/11/2025
Chapter 5B Lab - File Input and Output
Calculate an average of all scores in the file, Scores.txt
Output the average to the screen (The average is 74.625 using the input file above)
*/

#include <iostream> // Include the library for input and output.
#include <iomanip>  // Include the library for input and output manipulation.
#include <fstream>  // Include the library for file input and output.
using namespace std;

int main() // Main func.
{
    double score = 0, numScores = 0, Sum = 0, average = 0; // Initialize numberic variables.
    ifstream In;                                           // Initialize the input file.

    // Open input file
    In.open("Scores.txt"); // contents >> (78 + 55 + 95 + 100 + 60 + 80 + 89 + 40) = 597 / 8 = 74.625

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
        // Add score to Sum.
        Sum += score;
        // Increment number of scores.
        numScores++;
    }

    // Make sure the input file is NOT empty. DO NOT divide by zero!
    if (numScores != 0)
    {
        // Calculate the average.
        average = Sum / numScores;
        cout << "The average is: " << average << endl;
    }
    else
        cout << "Input file is empty, no average" << endl;

    In.close();

    return 0;
}