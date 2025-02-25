/* #include <iostream>
using namespace std;

// types memory sizes
int main()
{
    cout << sizeof(char) << endl;        // 1
    cout << sizeof(short) << endl;       // 2
    cout << sizeof(short int) << endl;   // 2
    cout << sizeof(int) << endl;         // 4
    cout << sizeof(float) << endl;       // 4
    cout << sizeof(long int) << endl;    // 4
    cout << sizeof(long) << endl;        // 4
    cout << sizeof(long long) << endl;   // 8
    cout << sizeof(double) << endl;      // 8
    cout << sizeof(long double) << endl; // 16
    return 0;
} */

/* Scratchpad example 1
 */

/* Pointer example 1
int main()
{
    int x = 10;
    int y = 20;
    int z = 30;
    int *ptr = &x;
    cout << *ptr << endl; // 10
    ptr = &y;
    cout << *ptr << endl; // 20
    ptr = &z;
    cout << *ptr << endl; // 30
    return 0;
}
*/
/*
Hand trace a c++ program with 4 to 6 variables that values change through the program.
Hand tracing is a debugging process where you pretend that you are the computer executing
a program. You step through each of the programs statements one by one. As you look
at a statement, you record the contents that each variable will have after the statement executes.
This process is often helpful in finding mathematical mistakes and other logic errors.
To hand trace a program, you consrruct a charr with a column for each variable. The rows
in the chart correspond ro rhe lines in rhe program. For example, Program 3-27 is shown
with a hand trace chart. The program uses the following four variables: num1, num2, num3,
and avg. */

/*
#include <iostream>
using namespace std;

int main()
{
    int num1;
    float num2;
    double num3;
    long double avg;
    cout << "The value of num1 is " << num1 << ", num2 is " << num2 << ", num3 is " << num3 << " and avg is " << avg << endl;
    return 0;
} */

/* Scratchpad example 2
#include <iostream>
using namespace std;

int main()
{
    int x;
    x = 3 / static_cast<int>(4.5 + 6.4);
    cout << x << endl;

    double average;
    average = 1.0 + 2.0 + 3.0 / 3.0;
    cout << average << endl;

    int length, width, height;
    cin.get(length >> width >> height);
    cout << length << " " << width << " " << height << endl;
} */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int modelYear;
    string modelName;
    cout << "Enter model year: ";
    cin >> modelYear;
    cout << "Enter model name: ";
    cin >> modelName;

    if ((modelYear >= 1999 && modelYear <= 2002) && (modelName == "Extravagant"))
        || ((modelYear >= 2004 && modelYear <= 2007) && (modelName == "Guzzler"))
        {
            cout << "RECALL";
        }
    else
    {
        cout << "NO RECALL";
    }
    return 0;
}
