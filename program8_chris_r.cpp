/* PROGRAM #8 CRUMBLE 5/4/2025
Write a program continuing to accept test scores from a file (a maximum of 50 valid scores and 50 invalid scores) until end of file (one score in each line).
All outputs are written to another file.
(1) Declare two arrays, size 50 (one to store valid scores and the other to store invalid scores; i.e. Any score in the range of 0 – 100 is a valid score).
            int validScores[50];
            int invalidScores[50];
(2) Write a function to get inputs. This function contains open file, check file, read and store into arrays, and close file. Instead of hard coded the input filename into the program, ask the user to enter the filename during execution of the program (run time).
    Make sure you check end of file (file can contain less than 50 scores), cannot read beyond EOF.
    Make sure you check array boundary; you cannot read more than 50 scores into any of the two arrays (remember array size is 50). Ignore any scores (valid or invalid) after storing 50 each.
      This function will be passed by reference on how many valid and how many invalid scores.
void GetInput(int valid[], int invalid[], int& validcount, int& invalidcount)
(3) Write a function to print scores in a table with rows of 5 scores. (See output example). This function will be called 3 times, first call is to print invalid scores, second call is to print valid scores.
    void Print (ofstream& out, int array[], int size)
(4) Call a function to access the valid score array and find out the highest valid score, lowest valid score, and average valid score.
    void stat (int array[], int size, int& high, int& low, double& average)
(5) Have a function to sort the valid scores in ascendant order (small to large). You will find sample sorting codes in Canvas. You may use any sort of your choice.
    void SortArray (int array[], int size)
(6) Call the function in #3 again for the third time to print the table of the sorted valid scores.
You must cope reasonably with a possibility of an empty file. You may make NO assumptions about the number of scores in the input file.
If there are no score in the file (empty file), stop the program and don’t output anything.
if all scores were invalid scores (i.e. the number of valid scores is zero), do not calculate or output any of the statistics (high score, low score, average score). Just say no valid scores and print the table of the invalid scores.
Test your program with several sequences of scores, including none, a few of only valid scores, a few of only invalid scores, a mixture of valid and invalid scores, and a file contains more than 50 valid or 50 invalid scores.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const int SIZE = 50; // size of the arrays
// function prototypes
void GetInput(int valid[], int invalid[], int &validcount, int &invalidcount);
void Print(ofstream &out, int array[], int size);
void Stat(int array[], int size, int &high, int &low, double &average);
void SortArray(int array[], int size);
// main function

int main()
{
    int validScores[SIZE];   // array to store valid scores
    int invalidScores[SIZE]; // array to store invalid scores
    int validCount = 0;      // count of valid scores
    int invalidCount = 0;    // count of invalid scores
    string filename;         // input file name

    cout << "Enter the input file name: ";
    cin >> filename;

    GetInput(validScores, invalidScores, validCount, invalidCount); // get inputs from file

    ofstream out("outputcr.txt"); // output file
    if (!out)
    {
        cout << "Error opening output file." << endl;
        return 1;
    }

    if (validCount == 0 && invalidCount == 0)
    {
        cout << "No scores in the file." << endl;
        return 0;
    }

    if (invalidCount > 0)
    {
        out << "Invalid Scores:" << endl;
        Print(out, invalidScores, invalidCount); // print invalid scores
    }

    if (validCount > 0)
    {
        out << "Valid Scores:" << endl;
        Print(out, validScores, validCount); // print valid scores

        int high, low;
        double average;
        Stat(validScores, validCount, high, low, average); // calculate statistics

        out << "Highest Valid Score: " << high << endl;
        out << "Lowest Valid Score: " << low << endl;
        out << "Average Valid Score: " << fixed << setprecision(2) << average << endl;

        SortArray(validScores, validCount); // sort valid scores
        out << "Sorted Valid Scores:" << endl;
        Print(out, validScores, validCount); // print sorted valid scores
    }

    out.close(); // close output file
    return 0;
}
// function to get inputs from file
void GetInput(int valid[], int invalid[], int &validcount, int &invalidcount)
{
    ifstream in("inputcr.txt"); // input file
    if (!in)
    {
        cout << "Error opening input file." << endl;
        return;
    }

    int score;
    while (in >> score)
    {
        if (score >= 0 && score <= 100)
        {
            if (validcount < SIZE)
            {
                valid[validcount++] = score; // store valid score
            }
        }
        else
        {
            if (invalidcount < SIZE)
            {
                invalid[invalidcount++] = score; // store invalid score
            }
        }
    }

    in.close(); // close input file
}
// function to print scores in a table with rows of 5 scores
void Print(ofstream &out, int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        out << setw(5) << array[i];
        if ((i + 1) % 5 == 0)
        {
            out << endl; // new line after every 5 scores
        }
    }
    out << endl;
}
// function to calculate statistics (highest, lowest, average)
void Stat(int array[], int size, int &high, int &low, double &average)
{
    high = array[0];
    low = array[0];
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] > high)
        {
            high = array[i]; // find highest score
        }
        if (array[i] < low)
        {
            low = array[i]; // find lowest score
        }
        sum += array[i]; // calculate sum of scores
    }

    average = static_cast<double>(sum) / size; // calculate average
}
// function to sort the array in ascending order
void SortArray(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]); // swap if the element is greater than the next element
            }
        }
    }
}
