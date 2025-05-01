/* Write a program to solve quadratic equations, it should test to see if the equation has a solution or not.
The user will type in 3 numbers a, b and c representing the coefficients.
The program will test to see if the discriminant (b2 - 4ac) is negative, zero or positive.
If negative, there is no solution.
If zero, output the unique solution of –b/2a.
If positive, output the two different solutions.
If a is zero, it is not a quadratic equation.
*/

#include <iostream> // cin and cout
#include <cmath>    // sqrt
#include <iomanip>  // setprecision
using namespace std;

int main()
{
  // a, b, and c are the coefficients of the quadratic equation.
  double a, b, c, discriminant, x1, x2;

  cout << "Enter the values of a, b, and c: ";
  cin >> a >> b >> c;

  // calculate the discriminant.
  discriminant = (b * b) - (4 * a * c);
  // cout << "The discriminant is " << discriminant << endl;

  // if a is zero, it is not a quadratic equation
  if (a == 0)
  {
    cout << "This is a line; not a Quadratic Equation." << endl;
    x1 = -c / b;
    cout << a << "x^2 + " << b << "x + " << c << " has unique solution " << fixed << setprecision(3) << x1 << endl;
  }
  // if the discriminant is negative, there is no solution.
  else if (discriminant < 0)
  {
    cout << a << "x^2 + " << b << "x + " << c << " has no solution" << endl;
  }
  // if the discriminant is zero, there is one solution. set decimal precision 3
  else if (discriminant == 0)
  {
    cout << "One solution" << endl;
    x1 = -b / (2.000 * a);
    cout << a << "x^2 + " << b << "x + " << c << " has solution " << fixed << setprecision(3) << x1 << endl;
  }
  // if the discriminant is positive, there are two solutions.
  else
  {
    cout << a << "x^2 + " << b << "x + " << c << " has two solutions " << endl;
    x1 = (-b + sqrt(discriminant)) / (2 * a);
    x2 = (-b - sqrt(discriminant)) / (2 * a);
    cout << "x1 = " << fixed << setprecision(3) << x1 << endl;
    cout << "x2 = " << fixed << setprecision(3) << x2 << endl;
  }

  return 0;
}