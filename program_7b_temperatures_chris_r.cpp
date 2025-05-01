// Author: Chris Rumble
// Temperatures.cpp: This file contains the 'main' function. Program execution begins and ends there.
// Version 1.2
/* Program #7B: Complete the Temperatures program (Temperatures.cpp template provided) to include four user defined functions (which you will write!) and the main function. */
#include <iostream> // For input and output.
#include <string>   // For string manipulation.
#include <fstream>  // For file input and output.
#include <iomanip>  // For input and output manipulation.
using namespace std;

// Maximum size of the array.
const int MAXSIZE = 1000;
// Fill array with data from file, return number of values read in.
int getData(string, double[]);
// Return the average of array values between index1 and index2, inclusive.
double getAverage(double[], int, int);
// Get the index of the maximum array value between index1 and index2, inclusive.
int getIndexOfMax(double[], int, int);
// Print the temperature values from startDay to endDay inclusive.
void printValues(double[], int, int);

int main()
{
    // Array to hold temperature values.
    double temperatures[MAXSIZE] = {0};
    // File name to read in.
    string fileName;
    // Prompt user for file name.
    cout << "Enter the input file name: ";
    // Read in file name.
    cin >> fileName;
    // Read in data from file.
    int numTemps = getData(fileName, temperatures);
    // Check for error opening file.
    if (numTemps == -1)
    {
        cout << "Error opening file." << endl;
    }
    // Check for no data read.
    else if (numTemps == 0)
    {
        cout << "File contains no data." << endl;
    }
    // Check for too many values read.
    else
    {
        int day1, day2;
        // Display number of temperatures read in.
        cout << numTemps << " temperatures were read in." << endl;
        char response;
        do
        {
            // Prompt user for start and end days.
            cout << "Enter the start day (1 to " << numTemps << "): ";
            cin >> day1;
            cout << "Enter the end day (1 to " << numTemps << "): ";
            cin >> day2;
            // Adjust for 0-based index.
            int index1 = day1 - 1;
            int index2 = day2 - 1;
            // Check for invalid range.
            if (index1 < 0 || index2 >= numTemps || index1 > index2)
            {
                cout << "Invalid range. Please try again." << endl;
            }
            else
            {
                // Print the values.
                printValues(temperatures, index1, index2);
                // Get the average.
                double average = getAverage(temperatures, index1, index2);
                // Print the average.
                cout << fixed << setprecision(2) << "Average temperature: " << average << endl;
                // Get the index of the maximum value.
                int maxIndex = getIndexOfMax(temperatures, index1, index2);
                // Print the day with the highest temperature.
                cout << "Day with highest temperature: Day " << maxIndex + 1 << endl;
            }
            // Ask user if they want to process another range.
            cout << "Do you want to process another range? (y/n): ";
            // Read in response.
            cin >> response;
        } while (response != 'n'); // end of loop.
        // Print a message when the user is done.
    }
    cout << "Bye!" << endl;

    return 0;
}

// Fill array with data from file, return number of values read in.
// Open file, check file, and read all values in with one call to this function.
int getData(string fileName, double values[])
{
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile) // Error opening file.
    {
        return -1;
    }

    int count = 0;
    // Read values from file.
    while (count < MAXSIZE && inFile >> values[count])
    {
        count++;
    }
    inFile.close(); // Close the file.

    if (count == 0) // No data read
    {
        return 0;
    }
    return count; // Number of values read.
}

// Return the average of array values between index1 and index2, inclusive
// index1 and index2 are day1 and day2 given by user
double getAverage(double values[], int index1, int index2)
{
    double sum = 0.0;
    int count = 0;
    // Loop from index1 to index2.
    for (int i = index1; i <= index2; i++)
    {
        sum += values[i]; // Sum up the values.
        count++;
    }
    return sum / count; // Average of values between index1 and index2.
}

// Get the index of the maximum array value between index1 and index2, inclusive.
int getIndexOfMax(double values[], int index1, int index2)
{
    int maxIndex = index1;
    // Loop from index1 to index2.
    for (int i = index1 + 1; i <= index2; i++)
    {
        // Check if current value is greater than the current max.
        if (values[i] > values[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex; // Index of maximum value between index1 and index2.
}

// Print the temperature values from startDay to endDay inclusive.
// startDay and endDay are day1 and day2 given by user.
void printValues(double temps[], int startDay, int endDay)
{
    cout << "Temperatures from day " << startDay << " to day " << endDay << ":" << endl;
    // Loop from startDay to endDay.
    for (int i = startDay; i <= endDay; i++)
    {
        cout << "Day " << i + 1 << ": " << temps[i] << endl;
    }
}