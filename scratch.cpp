/* #include <string>
#include <algorithm>
#include <iostream>
using namespace std;

string extract_first_word(const string &sentence)
{
    // Find the first space character in the string
    size_t space_position = sentence.find(' ');

    // If no space is found, then the entire string is the first word
    if (space_position == string::npos)
    {
        return sentence.substr(0, sentence.size() - 1); // Remove trailing period
    }
    else
    {
        // Extract the substring from the beginning of the string up to the space
        return sentence.substr(0, space_position);
    }
}

int main()
{
    string sentence = "This is a sentence.";
    string firstWord = extract_first_word(sentence);
    sentence.substr(0, sentence.find(' ')); // Extracts "This"
    cout << firstWord << endl;              // Output: This
    return 0;
}
*/

// Given the string variable address, write an expression that returns the position of the first occurrence of the string "Avenue" in address.

/* #include <string>
#include <iostream>
using namespace std;
int main()
{
    string address = "123 Main Avenue";
    size_t position = address.find("Avenue");
    cout << "Position of 'Avenue': " << position << endl; // Output: 8
    return 0;
}
*/
// The find() method returns the position of the first occurrence of the specified substring.
// If the substring is not found, it returns string::npos.
// The find() method is case-sensitive, so "avenue" would not match "Avenue".
// The find() method can also be used to find characters, not just strings.
// The find() method can take an optional second argument, which specifies the position to start searching from.
// The find() method can be used with other string methods, such as substr(), to extract parts of the string.
// The find() method can be used in loops to find all occurrences of a substring in a string.
// The find() method can be used with string iterators to find substrings in a range of characters.
// The find() method can be used with regular expressions to find patterns in strings.
// The find() method can be used with string algorithms, such as search(), to find substrings in a string.
// The find() method can be used with string streams to find substrings in a stream of characters.
// The find() method can be used with string comparisons to find substrings in a string.
// The find() method can be used with string concatenation to find substrings in a concatenated string.
/*
#include <string>
#include <iostream>
using namespace std;
*/
/*
struct Money
{
    int dollars;
    int cents;
};

void calculateYearlySales(const Money monthlySales[12], Money &yearlySales);
// Function prototype

void f()
{
    Money monthlySales[12];
    Money yearlySales;
}

// Assume monthlySales is already declared and initialized
// Money monthlySales[12];
// Money yearlySales;

int main()
{
    Money monthlySales[12];
    // Initialize monthlySales with some values (example)
    monthlySales[0].dollars = 10;
    monthlySales[0].cents = 50;
    monthlySales[1].dollars = 15;
    monthlySales[1].cents = 25;
    // ... and so on for the other 10 elements

    Money yearlySales;
    calculateYearlySales(monthlySales, yearlySales);

    std::cout << "Yearly Sales: $" << yearlySales.dollars << "." << yearlySales.cents << std::endl;

    return 0;
}

void calculateYearlySales(const Money monthlySales[12], Money &yearlySales)
{
    // Initialize yearlySales to zero
    yearlySales.dollars = 0;
    yearlySales.cents = 0;

    // Iterate through the monthlySales array and add up the dollar and cent values
    for (int i = 0; i < 12; ++i)
    {
        yearlySales.dollars += monthlySales[i].dollars;
        yearlySales.cents += monthlySales[i].cents;
    }

    // Ensure the cents value is less than 100
    if (yearlySales.cents >= 100)
    {
        yearlySales.dollars += yearlySales.cents / 100;
        yearlySales.cents %= 100;
    }
}

*/

/* Given the function prototype void strange(int a, int b); and the declaration below, create a valid call to the function strange

     int alpha[10];

     int beta[10];
     */

// The function strange takes two integer parameters, so we can call it with two integers.
// We can use the first elements of the arrays alpha and beta as arguments to the function strange.
// Here's how we can do that:
/* #include <iostream>
using namespace std;
void strange(int a, int b)
{
    // Function implementation
    cout << "a: " << a << ", b: " << b << endl;
}
    int main()
{
    int alpha[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int beta[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // Call the function strange with the first elements of alpha and beta
    strange(alpha[0], beta[0]); // This will pass the first elements of both arrays

    return 0;
} */
/*
// create prototype for mystery function
// The function takes two parameters: one is passed by reference (one) and the other is passed by value (two).
#include <iostream>
using namespace std;
void mystery(int &one, int two); // Function prototype

int main()
{
    int x = 10;
    int y = 15;
    mystery(x, y);
    cout << "x: " << x << ", y: " << y << endl;
    return 0;
}

void mystery(int &one, int two)
{
    int temp;
    temp = one;
    one = two;
    two = temp;
}

// The function takes two parameters: one is passed by reference (one) and the other is passed by value (two).
// The function swaps the values of one and two.
// The value of one is modified in the calling function, while the value of two remains unchanged.
*/
/* Create a program that declares and initializes at compile-time the first 5 integer elements of the array named numbers, size of 10, to have the value of 69, 79, 89, 99, 109
Then, initialize during run time, the array numbers you have declared so that each element has the value of 100. */
/*
#include <iostream>
using namespace std;
int main()
{
    // Declare and initialize  at compile-time the first 5 elements of the array numbers
    int numbers[10] = {69, 79, 89, 99, 109};
    // Initialize the remaining elements of the array during run time
    for (int i = 5; i < 10; ++i)
    {
        numbers[i] = 100;
    }
    // Print the array to verify the values
    for (int i = 0; i < 10; ++i)
    {
        cout << "numbers[" << i << "] = " << numbers[i] << endl;
    }

    return 0;
}
*/
/* Assume the four structures above are defined in the correct order in the program.

Write some code involving a nested loop to give a 25 percent increase to all the testScores for all the students for all the courses in springClasses.  You may assume that all 100 elements of springClasses represent actual courses. To loop through the students on the roster of each course you should use numberOfStudents as your loop bound. To loop through the testScores for each student, you should use the member numberOfTestsGiven for the current course.

     Course springClasses[100]; */
/*
#include <iostream>
#include <string>
using namespace std;

struct Time
{
    int hour, minute;
};

struct Meetings
{
    string meetingDay1,
        meetingDay2,
        meetingDay3;
};

struct Student
{
    string firstName, lastName;
    int id;
    float testScores[];
};

struct Course
{
    int courseNumber,
        credit,
        numberofstudents,
        numberofTestsGiven;
    Meetings meetingDates;
    Time meetingTime;
    Student roster[100];
};
void increaseTestScores(Course springClasses[100])
{
    // Loop through each course in springClasses
    for (int i = 0; i < 100; ++i)
    {
        // Loop through each student in the course
        for (int j = 0; j < springClasses[i].numberofstudents; ++j)
        {
            // Loop through each test score for the student
            for (int k = 0; k < springClasses[i].numberofTestsGiven; ++k)
            {
                // Increase the test score by 25%
                springClasses[i].roster[j].testScores[k] *= 1.25;
            }
        }
    }
}
*/

/* Write a function string getRichQuick (int n) that returns a string made out of 2 to the n dollar signs, for any non-negative value of n.
For example if n is 3 to the 2nd, 3 is 2*2*2 = 8 for 8 dolar signs, then the function will return "$$$$$$$$".
Hint: Declare a local variable s of type string, initialized to "$". Then use a loop to repeatedly concatenate s with itself. If n is negative then return the empty string.
string getRichQuick(int n) */
/*
#include <iostream>
#include <string>
using namespace std;
string getRichQuick(int n)
{
    // Check if n is negative
    if (n < 0)
    {
        return ""; // Return empty string for negative n
    }

    string s = "$"; // Initialize s with one dollar sign

    // Loop to concatenate s with itself 2^n times without using (1 << n)
    for (int i = 0; i < n; ++i)
    {
        s += s; // Concatenate s with itself
    }
    return s; // Return the resulting string
    // The loop will run n times, doubling the size of s each time
    // So the final size of s will be 2^n dollar signs
}
int main()
{
    int n = 3; // Example value for n
    string result = getRichQuick(n);
    cout << "Result: " << result << endl; // Output: $$$$$$$$
    return 0;
}
*/
/* Write a void function getBounds( ) that returns the smallest and biggest values and their array index from an array via reference parameters. Use the heading supplied. Note: it's possible for the same value to be biggest and smallest.
 */
/*
#include <iostream>
using namespace std;
// Function prototype
void getBounds(int nums[], int length, int &smallest, int &biggest, int &SIndex, int &BIndex);
// Function definition
int main()
{
    // int nums[] = {5}; // Example solo array
    int nums[] = {3, 5, 1, 8, 2, 7, 4, 6, 9, 0}; // Example array
    int length = sizeof(nums) / sizeof(nums[0]);
    int smallest, biggest, SIndex, BIndex;

    // Call the function to get bounds
    getBounds(nums, length, smallest, biggest, SIndex, BIndex);

    // Output the results
    cout << "Smallest: " << smallest << " at index " << SIndex << endl;
    cout << "Biggest: " << biggest << " at index " << BIndex << endl;

    return 0;
}

void getBounds(int nums[], int length, int &smallest, int &biggest, int &SIndex, int &BIndex)
{
    // Initialize smallest and biggest to the first element of the array
    smallest = nums[0];
    biggest = nums[0];
    SIndex = 0;
    BIndex = 0;

    // Loop through the array to find the smallest and biggest values
    for (int i = 1; i < length; ++i)
    {
        if (nums[i] < smallest)
        {
            smallest = nums[i];
            SIndex = i; // Update index of smallest value
        }
        if (nums[i] > biggest)
        {
            biggest = nums[i];
            BIndex = i; // Update index of biggest value
        }
    }
}
*/
/*
Write code to read up to SIZE lines of the file “names.txt” into the names array. Check end of file and array boundary.  Use getline( ) to read each name. Record the number of lines read in variable linesRead. For example, if there are 15 lines of text, then linesRead will be 15 and only the first 15 elements of names will be initialized. On the other hand, if there are 30 lines of text, then all 25 of the elements of names will be initialized and the last five lines of the file won’t be read (since there is no more room in the array to store them). Declare any other variables needed.
string names[SIZE];
const int SIZE = 25;
int linesRead = 0; */
/*
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int SIZE = 25; // Define the maximum size of the array
int main()
{
    string names[SIZE]; // Declare an array to hold names
    int linesRead = 0;  // Variable to count the number of lines read

    // Open the file for reading
    ifstream inFile;
    inFile.open("names.txt");
    if (!inFile)
    {
        cout << "Error opening file." << endl;
        return 1; // Exit if the file cannot be opened
    }
    string line;
    while (linesRead < SIZE && getline(inFile, line))
    {
        names[linesRead] = line; // Store the line in the array
        linesRead++;             // Increment the count of lines read
    }
    inFile.close(); // Close the file after reading
    // Output the names read from the file
    for (int i = 0; i < linesRead; ++i)
    {
        cout << names[i] << endl; // Print each name
    }
}
// Summarize the programs functionality:
// The program reads up to SIZE lines from a file named "names.txt" into an array of strings.
// It uses the getline() function to read each line from the file and stores it in the names array.
// The program checks for the end of the file and ensures that it does not exceed the array boundary.
// It keeps track of the number of lines read using the variable linesRead.
*/
/*
Write a function that returns true if the two arrays have the same length and the same sequence of values. Otherwise return false.

   bool areEqual(int nums1[ ], int length1, int nums2[ ], int length2)
*/
/*
#include <iostream>
using namespace std;
bool areEqual(int nums1[], int length1, int nums2[], int length2)
{
    // Check if the lengths of the arrays are equal
    if (length1 != length2)
    {
        return false; // Return false if lengths are not equal
    }

    // Compare the elements of both arrays
    for (int i = 0; i < length1; ++i)
    {
        if (nums1[i] != nums2[i])
        {
            return false; // Return false if any element is different
        }
    }
    return true; // Return true if all elements are equal
} */
/*
Write a function bool allDifferent(int nums[ ], int length) that returns true if nums contains all different values and false if there is a value that appears more than once. You should not change the contents of the array. Do not use <unordered_set> or any other STL container. You may use a nested loop to compare each element with every other element.

bool allDifferent(int nums[ ], int length)
*/
/*
#include <iostream>
using namespace std;
bool allDifferent(int nums[], int length)
{
    // Loop through each element in the array
    for (int i = 0; i < length; ++i)
    {
        // Compare the current element with every other element
        for (int j = i + 1; j < length; ++j)
        {
            if (nums[i] == nums[j])
            {
                return false; // Return false if a duplicate is found
            }
        }
    }
    return true; // Return true if all elements are different
} */
