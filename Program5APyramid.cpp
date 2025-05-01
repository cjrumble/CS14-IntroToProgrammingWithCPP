/* Chris Rumble 3/14/2025
Program #5A: Write a C++ program that draws a pyramid.
*/

#include <iostream>
using namespace std;

int main()
{
    // Declare height and width variables of the pyramid.
    int height = 0, width = 0;
    // Declare character type variables - one used to draw the pyramid shape and one to ask user if they want to play again.
    char character;
    char playAgain = 'y';

    // Main while loop to let user keep drawing pyramids until they quit.
    while (playAgain == 'y')
    {
        // Have user enter top width, height, and character to draw the pyramid.
        cout << "Enter the top width: ";
        cin >> width;
        cout << "Enter the height: ";
        cin >> height;
        cout << "Enter a character: ";
        cin >> character;

        // For loop to draw the pyramid shape.
        for (int i = 0; i < height; i++)
        {
            // Fill with the necassary spaces.
            for (int j = 0; j < height - i - 1; j++)
            {
                cout << " ";
            }
            // Draw the actual pyramid shape using the character value.
            for (int k = 0; k < 2 * i + width; k++)
            {
                cout << character;
            }
            cout << endl;
        }

        // Ask the user if they want to play again?
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    // Once we exit WHILE loop, we say goodbye to the user.
    cout << "Goodbye!" << endl;

    return 0;
}
