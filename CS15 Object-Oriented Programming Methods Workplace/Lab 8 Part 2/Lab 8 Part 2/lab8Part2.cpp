//
// lab8Part2.cpp
//
// Mahdi Khaliki and Saoi Chan
// Lab 8 Part 2
// Asks the user for a word or sentence, until user enters "quit", and checks if
// the work is a palindrome.
//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool IsPalindrome(string &s);
bool PalHelper(string &s, int lo, int hi);

int main() {
    string s;
    // Priming read
    cout << "Enter strings, \"quit\" to quit : " << flush;
    getline(cin, s); // Get the whole string
    while (s != "quit") { // Do the following while the user does not enter "quit"
        if (IsPalindrome(s)) { // If IsPalindrome() returns true.
            cout << '|' << s << '|' << " is a palindrome." << endl;
        }
        else { // Else the word is not a palindrome.
            cout << '|' << s << '|' << " is not a palindrome." << endl;
        }
        // Ask user for another word or sentence.
        cout << "\nEnter strings, \"quit\" to quit : " << flush;
        getline(cin, s);
    }
    return 0;
}

bool IsPalindrome(string &s) {
    int lo = 0, hi = s.length() - 1; // Calculate the lo and hi
    return PalHelper(s, lo, hi); // Return whatever PalHelper returns
}

bool PalHelper(string &s, int lo, int hi) {
    if (lo >= hi) { // Base case
        return true;
    }
    // If the lo and hi index contain an alphabet.
    else if ((isalpha(s[lo]) && (isalpha(s[hi])))) {
        // Compare the lo and hi and call PalHelp() with adjusted args or return 0.
        return tolower(s[lo]) == tolower(s[hi]) ? PalHelper(s, lo + 1, hi - 1) : false;
    }
    // If the hi index is not an alphabet, skip it.
    else if ((isalpha(s[lo]) && (!isalpha(s[hi])))) {
        return PalHelper(s, lo, hi - 1);
    }
    // If the lo index is not an alphabet, skip it.
    else if ((!isalpha(s[lo]) && (isalpha(s[hi])))) {
        return PalHelper(s, lo + 1, hi);
    }
    // If both the low and hi index are not alphabets, skip them.
    else if ((!isalpha(s[lo]) && (!isalpha(s[hi])))) {
        return PalHelper(s, lo + 1, hi - 1);
    }
    return false; // Return false if none of the above conditions are met.
}
