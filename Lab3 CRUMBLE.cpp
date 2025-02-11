/* Lab 3 C++ Tracing Variables - Modified Program 3-27 from the book.
This program asks for three numbers, then displays the average of the numbers.
*/

#include <iostream>
using namespace std;

int main()
{
    double num1 = 0, num2 = 0, num3 = 0, avg = 0;
    cout << "The value of num1 is " << num1 << ", num2 is " << num2 << ", num3 is " << num3 << " and avg is " << avg << endl;
    num1 = 125;
    num2 = 28;
    num3 = -25;
    avg = (num1 + num2 + num3) / 3.0;
    cout << "The average of default values " << num1 << ", " << num2 << ", and " << num3 << " is " << avg << endl;
    cout << "Enter a new first number: ";
    cin >> num1; // 100
    cout << "Enter a new second number: ";
    cin >> num2; // 150
    cout << "Enter a new third number: ";
    cin >> num3; // 300
    avg = (num1 + num2 + num3) / 3.0;
    cout << "The average of NEW values " << num1 << ", " << num2 << ", and " << num3 << " is " << avg << endl;
    return 0;
}