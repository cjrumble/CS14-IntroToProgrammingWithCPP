/* CRUMBLE 4/15/2025 Program #7A: Numbers with Array
propt user to find theh number in the position in the array
*/

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

// Function to get integer from user
void GetInteger(int arr[], int size)
{
    int inputNumber;
    do
    {
        cout << "Enter a number to see (0 to end): ";
        cin >> inputNumber;

        if (inputNumber != 0)
        {
            bool found = false;
            for (int i = 0; i < size; i++)
            {
                if (arr[i] == inputNumber)
                {
                    cout << "You entered: " << arr[i] << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Number not found in the array." << endl;
            }
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
    const int SIZE = 15;
    int numbers[SIZE];
    // int inputNumber;

    GetInput(numbers, SIZE);
    GetInteger(numbers, SIZE);
    PrintNumbers(numbers, SIZE);

    return 0;
}
