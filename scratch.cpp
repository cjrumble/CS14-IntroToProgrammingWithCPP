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

#include <string>
#include <iostream>
using namespace std;

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
