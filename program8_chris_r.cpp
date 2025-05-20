/* PROGRAM #8 CRUMBLE 5/4/2025
Write a program continuing to accept test scores from a file (a maximum of 50 valid scores and 50 invalid scores) until end of file (one score in each line).
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const int SIZE = 50; // size of the arrays.
// function prototypes.
void GetInput(int valid[], int invalid[], int &validcount, int &invalidcount);
void Print(ofstream &out, int array[], int size);
void Stat(int array[], int size, int &high, int &low, double &average);
void SortArray(int array[], int size);
// main function.

int main()
{
    int validScores[SIZE];   // array to store valid scores.
    int invalidScores[SIZE]; // array to store invalid scores.
    int validCount = 0;      // count of valid scores.
    int invalidCount = 0;    // count of invalid scores.
    string filename;         // input file name.

    cout << "Enter the input file name: ";
    cin >> filename;

    GetInput(validScores, invalidScores, validCount, invalidCount); // get inputs from file

    ofstream out("outputcr.txt"); // output file.
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
        Print(out, invalidScores, invalidCount); // print invalid scores.
    }

    if (validCount > 0)
    {
        out << "Valid Scores:" << endl;
        Print(out, validScores, validCount); // print valid scores.

        int high, low;
        double average;
        Stat(validScores, validCount, high, low, average); // calculate statistics.

        out << "Highest Valid Score: " << high << endl;
        out << "Lowest Valid Score: " << low << endl;
        out << "Average Valid Score: " << fixed << setprecision(2) << average << endl;

        SortArray(validScores, validCount); // sort valid scores.
        out << "Sorted Valid Scores:" << endl;
        Print(out, validScores, validCount); // print sorted valid scores.
    }

    out.close(); // close output file.
    return 0;
}
// function to get inputs from file
void GetInput(int valid[], int invalid[], int &validcount, int &invalidcount)
{
    ifstream in("inputcr.txt"); // input file.
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
                valid[validcount++] = score; // store valid score.
            }
        }
        else
        {
            if (invalidcount < SIZE)
            {
                invalid[invalidcount++] = score; // store invalid score.
            }
        }
    }

    in.close(); // close input file.
}
// function to print scores in a table with rows of 5 scores.
void Print(ofstream &out, int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        out << setw(5) << array[i];
        if ((i + 1) % 5 == 0)
        {
            out << endl; // new line after every 5 scores.
        }
    }
    out << endl;
}
// function to calculate statistics (highest, lowest, average).
void Stat(int array[], int size, int &high, int &low, double &average)
{
    high = array[0];
    low = array[0];
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] > high)
        {
            high = array[i]; // find highest score.
        }
        if (array[i] < low)
        {
            low = array[i]; // find lowest score.
        }
        sum += array[i]; // calculate sum of scores.
    }

    average = static_cast<double>(sum) / size; // calculate average.
}
// function to sort the array in ascending order.
void SortArray(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]); // swap if the element is greater than the next element.
            }
        }
    }
}
