/* Program 6A CRUMBLE 3/30/2025
Complete the Count Vowels program by writing the function definitions for the following two functions:
bool isVowel(char c) 		// returns true if c is a vowel, else false.
int countVowels(string s)	// returns the number of vowels in the string s.
You can access each character of s by using s.at(i) where i ranges from 0 to s.length()-1.
countVowels() calls isVowel(s.at(i)) to check if character i is a vowel.
*/

#include <iostream>
#include <string>
using namespace std;
bool isVowel(char c)
{
    // Check if the character is a vowel (both uppercase and lowercase)
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}
int countVowels(string s)
{
    int count = 0;
    // Loop through each character in the string
    for (int i = 0; i < s.length(); i++)
    {
        // Check if the character is a vowel
        if (isVowel(s.at(i)))
        {
            count++; // Increment the count if it's a vowel
        }
    }
    return count; // Return the total count of vowels
}
int main()
{
    string word;
    // Loop until the user types "quit"
    while (true)
    {
        cout << "Please enter a word or type \"quit\" to exit: ";
        cin >> word; // Read the input word
        if (word == "quit")
        { // Check for exit condition
            cout << "Goodbye!" << endl;
            break; // Exit the loop
        }
        int vowelCount = countVowels(word);                          // Count the vowels in the word
        cout << word << " has " << vowelCount << " vowels." << endl; // Output the result
    }
    return 0; // Indicate successful completion
}
// End of program