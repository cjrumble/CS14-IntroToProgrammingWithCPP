/*
Program #5B: Quadratic File IO
Chris Rumble 3/17/2025
Rewrite Program4A to handle File Input and Output instead of keyboard.
 */
#include <iostream> // cin and cout
#include <cmath>    // sqrt
#include <iomanip>  // setprecision
#include <fstream>  // file handling
using namespace std;

int main()
{
    // a, b, and c are the coefficients of the quadratic equation.
    double a, b, c, discriminant, x1, x2;
    // declare file stream variables
    ifstream fin;
    ofstream fout;

    // check if the file is open
    if (!fin || !fout)
    {
        cout << "Error opening input/output files." << endl;
        return -1;
    }
    else
    {
        // open the input file
        fin.open("input.txt");
        // open the output file
        fout.open("output.txt");
    }

    // read the values of a, b, and c from the input file
    fin >> a >> b >> c;

    // calculate the discriminant.
    discriminant = (b * b) - (4 * a * c);
    // cout << "The discriminant is " << discriminant << endl;

    // if a is zero, it is not a quadratic equation
    if (a == 0)
    {
        fout << "This is a line; not a Quadratic Equation." << endl;
        x1 = -c / b;
        fout << a << "x^2 + " << b << "x + " << c << " has unique solution " << fixed << setprecision(3) << x1 << endl;
    }
    // if the discriminant is negative, there is no solution.
    else if (discriminant < 0)
    {
        fout << a << "x^2 + " << b << "x + " << c << " has no solution" << endl;
    }
    // if the discriminant is zero, there is one solution. set decimal precision 3
    else if (discriminant == 0)
    {
        fout << "One solution" << endl;
        x1 = -b / (2.000 * a);
        fout << a << "x^2 + " << b << "x + " << c << " has solution " << fixed << setprecision(3) << x1 << endl;
    }
    // if the discriminant is positive, there are two solutions.
    else
    {
        fout << a << "x^2 + " << b << "x + " << c << " has two solutions " << endl;
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        fout << "x1 = " << fixed << setprecision(3) << x1 << endl;
        fout << "x2 = " << fixed << setprecision(3) << x2 << endl;
    }

    return 0;
}
