// Chris Rumble 5/16/2025
// Chapter 11B Lab

#include <iostream>
using namespace std;

struct Clock // Define a structure to represent a clock.
{
    int hour;
    int minute;
    int second;
    bool AM;
};

void printTime(const Clock &); // Print the time.
char getChoice();              // Get user choice of actions.

// Advance the clock by one second.
void tick(Clock &);

// Reset clock to midnight.
void reset(Clock &);

// Set the hour of the clock.
void setHour(Clock &, int);

int main()
{
    Clock myClock = {12, 0, 0, true}; // hour, minute, second and AM are initialized to midnight.
    bool quit = false;
    do
    {
        char response = getChoice(); // Get user choice of actions.
        switch (response)
        {
        case 'r': // Reset the clock to midnight.
            reset(myClock);
            break;
        case 'h': // Set the hour of the clock.
            int newHour;
            cout << "Enter the hour: ";
            cin >> newHour;
            setHour(myClock, newHour);
            break;
        case 't': // Advance the clock by a number of ticks.
            int numTicks;
            cout << "Enter the number of ticks: ";
            cin >> numTicks;
            for (int i = 0; i < numTicks; i++)
                tick(myClock);
            break;
        case 'q': // Quit the program.
            quit = true;
            break;

        default: // Invalid choice.
            cout << "Invalid choice." << endl;
        }

        if (response == 'r' || response == 'h' || response == 't')
            printTime(myClock);
    } while (!quit); // Loop until the user chooses to quit.

    cout << "Bye!" << endl; // Print goodbye message.
    return 0;
}

// Advance the clock by one second.
void tick(Clock &c)
{
    c.second++;
    if (c.second == 60)
    {
        c.second = 0;
        c.minute++;
        if (c.minute == 60)
        {
            c.minute = 0;
            c.hour++;
            if (c.hour == 12)
            {
                c.AM = !c.AM;
            }
            if (c.hour == 13)
            {
                c.hour = 1;
            }
        }
    }
}

// Reset clock to midnight.
void reset(Clock &c)
{
    c.hour = 12;
    c.minute = 0;
    c.second = 0;
    c.AM = true;
}

// Set the hour of the clock.
void setHour(Clock &c, int newHour)
{
    if (newHour <= 0)
    {
        reset(c);
    }
    else if (newHour > 12)
    {
        c.hour = newHour - 12;
        c.AM = !c.AM;
    }
    else
    {
        c.hour = newHour;
    }
}

// Get user choice of actions
char getChoice()
{
    cout << "Please enter a letter..." << endl; // Prompt user for input.
    cout << "r: reset the clock " << endl;
    cout << "h: set the hour " << endl;
    cout << "t: tick the clock " << endl;
    cout << "q: to quit" << endl
         << endl;
    char ch;
    cin >> ch;
    return ch;
}

// Print the time.
// Format minutes and seconds with leading zeros.
void printTime(const Clock &c)
{
    cout << "Time is " << c.hour
         << ":";
    if (c.minute < 10)
        cout << "0";
    cout << c.minute
         << ":";
    if (c.second < 10)
        cout << "0";
    cout << c.second
         << " ";
    if (c.AM)
        cout << " AM";
    else
        cout << " PM";
    cout << endl
         << endl;
}
