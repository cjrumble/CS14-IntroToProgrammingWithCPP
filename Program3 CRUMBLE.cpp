/* CRUMBLE Program #3: Do Math
Accept two integers (declare your input variables as int) from the user
Calculate their Sum, Difference, Product, Quotient, Remainder and Division Results,
Raise the second integer as a power to the first integer. Disregard divide by ZERO */

#include <iostream> // input and ouput library
#include <cmath>    // needed for all math functions
#include <iomanip>  // needed for setprecision function
using namespace std;

int main()
{
    int num1, num2;
    cout << "Enter two integers: ";
    // Have the user input two integers.
    cin >> num1 >> num2;
    // Output the results matcing the Professor's WORD document.
    cout << "The sum of " << num1 << " + " << num2 << " is " << num1 + num2 << endl;
    cout << "The difference of " << num1 << " - " << num2 << " is " << num1 - num2 << endl;
    cout << "The product of " << num1 << " * " << num2 << " is " << num1 * num2 << endl;
    cout << "The quotient of " << num1 << " / " << num2 << " is " << num1 / num2 << endl;
    cout << "The remainder of " << num1 << " / " << num2 << " is " << num1 % num2 << endl;
    // The division results are casted to double to get the decimal value w/ set decimal precision 2.
    cout << "The division results of " << num1 << " / " << num2 << " is " << fixed << setprecision(2) << static_cast<double>(num1) / static_cast<double>(num2) << endl;
    // Return set decimal precision to 0 for the power function.
    cout << num1 << " to the power of " << num2 << " is " << fixed << setprecision(0) << pow(num1, num2) << endl;
    return 0;
}
