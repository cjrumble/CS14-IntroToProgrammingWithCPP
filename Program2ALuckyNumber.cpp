/* CRUMBLE Program 2A Lucky Number
Ask user their name and what is their lucky number.
Display the name and lucky number. */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    /* Define variables to hold name and number. */
    int lucky;
    string name;
    /* Prompt for name */
    cout << "What is your name? ";
    cin >> name;
    /* Prompt for number */
    cout << "What is your lucky number? (enter an integer)";
    cin >> lucky;
    /* Display results to screen. */
    cout << "Hi " << name << endl;
    cout << "Your luck number is " << lucky;

    return 0;
}