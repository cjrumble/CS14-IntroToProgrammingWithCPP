// Lab 2A CRUMBLE
/* Program to find sum and product
  by adding and multiplying two integer inputs  */

#include <iostream>
using namespace std;

int main()
{

  // Declare variables to hold inputs and calculations
  int number1, number2, sum, product;

  // Ask for two integer inputs
  cout << "Enter first number: ";
  cin >> number1;

  cout << "Enter second number: ";
  cin >> number2;

  // Do the math to add and multiply
  sum = number1 + number2;
  product = number1 * number2;

  // Output the result of Sum and Product
  cout << "The sum of " << number1 << " + " << number2 << " is " << sum << endl;
  cout << "The product of " << number1 << " x " << number2 << " is " << product;
}
