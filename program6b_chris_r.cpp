/* Program 6B CRUMBLE 4/1/2025
Program #6B: Quadratic FIO with Functions
Calculate the roots of a quadratic equation from a file, Data.txt.
Output the roots to a file, Stat.txt.
*/
#include <iostream> // cin and cout
#include <cmath>    // sqrt
#include <iomanip>  // setprecision
#include <fstream>  // file handling
using namespace std;

// Function prototypes, declarations, & definitions
bool Check_Value(int x);
void Calculate_Stat(ifstream &In, int &max, int &min, float &average);
void GetInputs(ifstream &In, double &a, double &b, double &c);
int QuadRoots(double a, double b, double c, double &r1, double &r2);
void Print(ofstream &Out, double a, double b, double c, double r1, double r2, int EquationKind);

int main() // Main func.
{
    // Initialize numeric variables.
    double a = 0, b = 0, c = 0, r1 = 0, r2 = 0;
    int EquationKind = 0; // Initialize the equation kind.

    // Open input and output files
    {
        ifstream In("Data.txt");
        ofstream Out("Stat.txt");

        if (!In) // File does not exist or not in the same directory.
        {
            cout << "Error opening input file." << endl;
            return 1;
        }

        if (!Out) // File does not exist or not in the same directory.
        {
            cout << "Error opening output file." << endl;
            return 1;
        }
        // Continue to read score from input file until end of file.
        while (In >> a >> b >> c)
        {
            GetInputs(In, a, b, c);                    // Read a, b, c from input file.
            EquationKind = QuadRoots(a, b, c, r1, r2); // Calculate roots.
            Print(Out, a, b, c, r1, r2, EquationKind); // Print results to output file.
        }

        In.close();  // Close input file.
        Out.close(); // Close output file.

        return 0;
    }
    // End of main function.
}

// Read a, b, c from input file.
void GetInputs(ifstream &In, double &a, double &b, double &c)
{
    In >> a >> b >> c;
}

// Calculate roots of quadratic equation.
int QuadRoots(double a, double b, double c, double &r1, double &r2)
{
    if (a == 0)
    {
        return -1; // Not a quadratic equation.
    }
    double discriminant = b * b - 4 * a * c; // Calculate discriminant.
    if (discriminant < 0)
    {
        return -2; // No real roots
    }
    r1 = (-b + sqrt(discriminant)) / (2 * a); // Calculate first root.
    r2 = (-b - sqrt(discriminant)) / (2 * a); // Calculate second root.
    return 0;                                 // Success
}

// Print results to output file.
void Print(ofstream &Out, double a, double b, double c, double r1, double r2, int EquationKind)
{
    Out << "Equation: " << a << "x^2 + " << b << "x + " << c << endl;
    if (EquationKind == -1)
    {
        Out << "This is a linear equation, no roots." << endl;
    }
    else if (EquationKind == -2)
    {
        Out << "No real roots." << endl;
    }
    else
    {
        Out << "Roots: r1 = " << r1 << ", r2 = " << r2 << endl;
    }
}
