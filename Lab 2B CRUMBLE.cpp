/* Lab 2B CRUMBLE
Ask user for the value of a side for a cube, then calculate and output cube's surface area and volume. */
#include <iostream>
using namespace std;

int main()
{
    int side1;                                         // Declare integer var store the side length of the cube
    float cubevol;                                     // Declare floating-point variable to store the volume of the cube
    cout << "\n\n Calculate the volume of a cube :\n"; // Output message for calculation of volume
    cout << " Input the side of a cube : ";            // Prompting the user to input the side length of the cube
    cin >> side1;                                      // Taking input for the side length from the user

    // Calculating the volume of the cube using the formula: side * side * side
    cubevol = (side1 * side1 * side1);

    cout << " The volume of a cube is : " << cubevol << endl;                   // Display the calculated volume
    cout << " The surface area of a cube is : " << 6 * (side1 * side1) << endl; // Display the surface area
    return 0;                                                                   // Successful program execution
}
