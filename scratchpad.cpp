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
}


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


*/
/*
int age, minors, adults, seniors;
age = minors = adults = seniors = 0;
cout << "Enter age: ";
cin >> age;
*/
/*
int modelYear;
string modelName;
cout << "Enter model year: ";
cin >> modelYear;
cout << "Enter model name: ";
cin >> modelName;

if (((modelYear >= 1999 && modelYear <= 2002) && (modelName == "Extravagant")) || ((modelYear >= 2004 && modelYear <= 2007) && (modelName == "Guzzler")))
{
    cout << "RECALL";
}
else
{
    cout << "NO RECALL";
}
return 0;
} */
/*
    if (age < 18)
    {
        minors += 1;
        cout << "Minors: " << minors << endl;
    }
    if ((age >= 18) && (age <= 64))
    {
        adults += 1;
        cout << "Adults: " << adults << endl;
    }
    else if (age >= 65)
    {
        seniors += 1;
        cout << "Seniors: " << seniors << endl;
    }
    return 0;
} */
/*
int main()
{
    bool isPremiumCustomer;
    int nbooksPurchased, freeBooks;
    cout << "Are you a premium customer? (1 for yes, 0 for no)" << endl;
    cin >> isPremiumCustomer;
    cout << "How many books have you purchased?" << endl;
    cin >> nbooksPurchased;

    if ((isPremiumCustomer == true) && ((nbooksPurchased >= 5) && (nbooksPurchased < 8)))
    {
        freeBooks = 1;
        cout << "You get " << freeBooks << " free books." << endl;
    }
    else if ((isPremiumCustomer == true) && (nbooksPurchased >= 8))
    {
        freeBooks = 2;
        cout << "You get " << freeBooks << " free books." << endl;
    }
    else
    {
        freeBooks = 0;
        cout << "You get " << freeBooks << " free books." << endl;
    }
    return 0;
}
*/
/*
#include <exception>
#include <iostream>
#include <stack>
#include <set>
#include <string>
#include <stdexcept>
#include <cstring>
#include <list>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include <queue>

using namespace std;

int main()
{
    bool isPremiumCustomer;
    int nbooksPurchased;
    int freeBooks;

    cout << isPremiumCustomer;

    int freeBooks = isPremiumCustomer ? (nbooksPurchased >= 5 ? 1 : 0) : (nbooksPurchased >= 7 ? 1 : 0);
    freeBooks = (isPremiumCustomer && nbooksPurchased >= 8) ? 2 : (isPremiumCustomer && nbooksPurchased >= 5) ? 1
                                                              : (nbooksPurchased >= 12)                       ? 2
                                                              : (nbooksPurchased >= 7)                        ? 1
                                                                                                              : 0;

    if ((isPremiumCustomer = 1) && ((nbooksPurchased >= 5) && (nbooksPurchased < 8)))
    {
        freeBooks = 1;
    }
    else if ((isPremiumCustomer = 1) && (nbooksPurchased >= 8))
    {
        freeBooks = 2;
    }
    else if ((isPremiumCustomer = 0) && ((nbooksPurchased >= 7) && (nbooksPurchased < 12)))
    {
        freeBooks = 1;
    }
    else ((isPremiumCustomer == 0) && (nbooksPurchased > 12) {
            freeBooks = 2;
    }


    return 0;
}

for (int i = 2; i <= 10; i += 2)
{
    cout << i << " ";
}

Write a nested loop (using while or for loop),
to print a hallow rectangle.
Hint: You might also consider to use if/else inside your loop.

Ask user for width and height.

For example:
if user inputs 6 for width and 4 for height, then your program should output the following:

******
*    *
*    *
******

int width, height;
cout << "Enter width: ";
cin >> width;
cout << "Enter height: ";
cin >> height;

for (int i = 1; i <= height; i++)
{
    for (int j = 1; j <= width; j++)
    {
        if (i == 1 || i == height || j == 1 || j == width)
        {
            cout << "*";
        }
        else
        {
            cout << " ";
        }
    }
    cout << endl;
}
    */
/*
Write if statements to print different messages depending on the letter grade.

 Grade is a
 character(char datatype)
     .Write if /
 else if / else

 When Grade is A,
 print “Excellent Work”

 When Grade is B,
 print “Good Job”

 When Grade is C,
 print “Work Harder”

 Anything else,
 print “Need Improvement”

#include <iostream>
 using namespace std;

int main()
{
 char grade;
 cout << "Enter grade: ";
 cin >> grade;

 if (grade == 'A')
 {
     cout << "Excellent Work" << endl;
 }
 else if (grade == 'B')
 {
     cout << "Good Job" << endl;
 }
 else if (grade == 'C')
 {
     cout << "Work Harder" << endl;
 }
 else
 {
     cout << "Need Improvement" << endl;
 }
 return 0;
}
*/
/*
    Write switch statements to print different messages depending on the letter grade.

    Grade is a
    character(char datatype)
        .Write switch

    When Grade is A,
    print “Excellent Work”

    When Grade is B,
    print “Good Job”

    When Grade is C,
    print “Work Harder”

    Anything else,
    print “Need Improvement”

#include <iostream>
    using namespace std;

int main()
{
    char grade;
    cout << "Enter grade: ";
    cin >> grade;

    switch (grade)
    {
    case 'A':
        cout << "Excellent Work" << endl;
        break;
    case 'B':
        cout << "Good Job" << endl;
        break;
    case 'C':
        cout << "Work Harder" << endl;
        break;
    default:
        cout << "Need Improvement" << endl;
    }
    return 0;
}
*/
/*
#include <exception>
#include <iostream>
#include <stack>
#include <set>
#include <string>
#include <stdexcept>
#include <cstring>
#include <list>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include <queue>


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, n = 0, s = 0;
    double average;
    ifstream;
    ofstream;
    In.open("data.txt");
    Out.open("average.txt");
    if (!In)
    {
        cout << "Input file not found, program ends" << endl;
        return -1;
    }
    In >> a;
    while (!In.eof())
    {
        s += a;
        n++;
    }
    if ()
    {
        average = (double)s / a;
        Out << "The average is: " << average << endl;
    }
    else
        cout << Input file is empty, no output to output file << endl;
    In.close();
    return 0;
    */
// This program has an uninitialized global variable.
/*
#include <iostream>
using namespace std;

int globalNum; // Global variable, automatically set to zero 6
int main()
{
    cout << "globalNum is " << globalNum << endl;
    return 0;
}

*/
