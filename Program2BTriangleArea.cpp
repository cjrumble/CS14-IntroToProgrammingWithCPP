/* CRUMBLE Lab 2B - Triangle Area Calculator */
#include <iostream>
using namespace std;

int main()
{
    /* Define int variables for height & base.
       Define double variable for calculated area value. */
    int height;
    int base;
    double area;

    /* Prompt user for triangle height and base values. */
    cout << "Enter the height of the triangle: ";
    cin >> height;

    cout << "Enter the base of the triangle: ";
    cin >> base;

    /* Calculate area of triangle. */
    area = 0.5 * height * base;

    /* Display to screen the results & end line. */
    cout << "The area of the triangle is: " << area << endl;

    return 0;
}

/* Example Tests
If user enters 3 for height and 4 for base, then the area should be 6
If user enters 5 for height and 3 for base, then the area should be 7.5 */