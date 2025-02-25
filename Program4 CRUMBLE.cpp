/* CRUMBLE Program #4: Do Math - Perform a math operation of the user’s choice on two numbers.
 */

#include <iostream> // input and ouput library.
#include <cmath>    // needed for all math functions.
#include <iomanip>  // needed for setprecision function.
using namespace std;

int main()
{
    char operation;
    double num1, num2;
    // Prompt the user to enter an operation.
    cout << "Enter an operation (+, -, *, /, Q, R): ";
    cin >> operation;
    // Prompt the user to enter two real numbers.
    cout << "Enter two real numbers: ";
    cin >> num1 >> num2;
    // If the operation is addition.
    if (operation == '+')
    {
        cout << "The sum of " << num1 << " + " << num2 << " is " << num1 + num2 << endl;
    }
    // If the operation is subtraction.
    else if (operation == '-')
    {
        cout << "The difference of " << num1 << " - " << num2 << " is " << num1 - num2 << endl;
    }
    // If the operation is multiplication.
    else if (operation == '*')
    {
        cout << "The product of " << num1 << " * " << num2 << " is " << num1 * num2 << endl;
    }
    // If the operation is division.
    else if (operation == '/')
    {
        // Check if the denominator is zero.
        if (num2 == 0)
        {
            // Display an error message.
            cout << "Error: Division by zero is not allowed." << endl;
        }
        else
        {
            cout << "The quotient of " << num1 << " / " << num2 << " is " << num1 / num2 << endl;
        }
    }
    // If the operation is quotient.
    else if (operation == 'Q')
    {

        if (num2 == 0)

        {
            // Display an error message.
            cout << "Error: Division by zero is not allowed." << endl;
        }
        else
        {
            cout << "The quotient of " << num1 << " / " << num2 << " is " << num1 / num2 << endl;
        }
    }
    // If the operation is remainder.
    else if (operation == 'R')
    {
        // Check if the denominator is zero.
        if (num2 == 0)
        {
            // Display an error message.
            cout << "Error: Division by zero is not allowed." << endl;
        }
        else
        {
            cout << "The remainder of " << num1 << " / " << num2 << " is " << (int)num1 % (int)num2 << endl;
        }
    }
    // If the operation is invalid.
    else
    {
        // Display an error message.
        cout << "Error: Invalid operation." << endl;
    }
    return 0;
}