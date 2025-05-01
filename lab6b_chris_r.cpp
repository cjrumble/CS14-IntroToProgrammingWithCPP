/* Lab 6B CRUMBLE 4/1/2025
The program is to read integers from an input file called "Data.txt" and output the highest value, the lowest values, and their average to an output file called "Stat.txt"
Create two user-defined functions: Check_Value(), and Calculate_Stat() and deeclare them beefore main().
>> bool Check_Value (int x) is the function take in an integer and return true if the integer is valid, or return false if not.
>> void Calculate_Stat (ifstream& In, int x, int& max, int& min, float& average) is the function that will call Check_Value(), do the calculations, and send back to main all 3 values of high, low and average by reference.
The statistics (high, low, average) are only for valid numbers; don't include any of the invalid numbers. Open your input file in main, but read data inside the Calculate_Stat() function. */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

bool Check_Value(int x);
void Calculate_Stat(ifstream &In, int &max, int &min, float &average);

int main()
{
    int high = 0, low = 100;
    float average = 0;
    ifstream In;
    ofstream Out;

    In.open("Data.txt");
    Out.open("Stat.txt");

    if (!In)
    {
        cout << "Input file not found, program ends" << endl;
        return -1;
    }
    else
    {
        Calculate_Stat(In, high, low, average);
    }

    if (!Out)
    {
        cout << "Output file not found, program ends" << endl;
        return -1;
    }
    else
    {
        Out << fixed << setprecision(2);
    }

    Out << "The high value is: " << high << endl;
    Out << "The low value is: " << low << endl;
    Out << "There average is: " << average << endl;

    In.close();
    Out.close();
    return 0;
}

bool Check_Value(int x)
{
    return x >= 0 && x <= 100;
}

void Calculate_Stat(ifstream &In, int &max, int &min, float &average)
{
    int sum = 0;
    int count = 0;
    int num; // Declare num to store input values
    max = 0;
    min = 100;

    while (In >> num)
    {
        if (Check_Value(num))
        {
            sum += num;
            count++;
            if (num > max)
            {
                max = num;
            }
            if (num < min)
            {
                min = num;
            }
        }
    }

    if (count > 0)
    {
        average = static_cast<float>(sum) / count;
    }
    else
    {
        average = 0;
        max = 0;
        min = 0;
    }
}