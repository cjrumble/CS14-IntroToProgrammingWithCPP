/* CRUMBLE 4/21/2025
Program #7A : Write a C++ program that uses an array to store numbers, manipulate them, then output from the array. */

#include <iostream>
using namespace std;
// Function to get input from user
void GetInput(int arr[], int size)
{
    cout << "Enter " << size << " numbers:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
// Function to get integer from user.
void GetInteger(int arr[], int size)
{
    int inputNumber, index_num;
    string position;
    do
    {
        cout << "Enter a number to see (0 to end): ";
        cin >> inputNumber;
        if (inputNumber >= 0 && inputNumber <= size)
        {
            index_num = inputNumber - 1; // Adjust for 0-based index.
            if (index_num == 1)
            {
                position = "st";
            }
            else if (index_num == 2)
            {
                position = "nd";
            }
            else if (index_num == 3)
            {
                position = "rd";
            }
            else
            {
                position = "th";
            }
            cout << "The " << inputNumber << position << " input you entered is " << arr[index_num] << endl;
        }
        else
        {
            cout << "Number not found in the array." << endl;
        }
    } while (inputNumber != 0);
}

// Function to print the first and last number, and all numbers in reverse order
void PrintNumbers(int arr[], int size)
{
    cout << "First number: " << arr[0] << endl;
    cout << "Last number: " << arr[size - 1] << endl;

    cout << "Numbers in reverse order: ";
    for (int i = size - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    const int SIZE = 15; // Size of the array
    int arr[SIZE];       // Declare an array of integers

    GetInput(arr, SIZE);     // Get input from user
    GetInteger(arr, SIZE);   // Get integer from user
    PrintNumbers(arr, SIZE); // Print numbers

    return 0;
}
// End of main function
// End of program
// End of program7a_chris_ru.cpp
