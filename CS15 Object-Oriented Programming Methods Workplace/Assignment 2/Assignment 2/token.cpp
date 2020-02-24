//
// token.cpp
//
// Mahdi Khaliki
// Assignment 2
// Reads a line of text from a file, tokenizes it, prints out each word in the
// file (once if seen more than once), prints how many times the word appears in
// the file, and prints the smallest and largest words.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

bool wordCount(char a[][16], int wordCt[], char *p1, int arrayCt);
int wordLen(char a[][16], bool shortest);
int const MAX = 100;
#define DELIMS  " ."

int main(int argc, const char * argv[]) {
    if (argc < 3) { // Checks if user has passed in both file names
        cout << "User did not enter file names." << endl;
        return -1;
    }
    
    char c[MAX], a[MAX][16], *p1 = NULL; // Declaring varibles
    int arrayCt = 0, rowCt = 0, wordCt[MAX] = {0}, i = 0, sum = 0;
    
    ifstream input(argv[1]); // Using the second arguement as input file name
    ofstream output(argv[2]); // Using the third arguement as Output file name
    if(!input || !output) {
        output << "Error opening files." << endl;
        return -2;
    }
    
    while (!input.eof()) {
        // Gets the first line and echo prints it
        input.getline(c, MAX, '\n');
        if (strcmp(c, "") == 0) {
            break;
        }
        output << c << endl;
        // Tokenizes the first word of the line.
        p1 = strtok(c, DELIMS);
        // If p1 a unique word save it in the array
        if (wordCount(a, wordCt, p1, arrayCt) == false) {
            strcpy(a[arrayCt++], p1);
        }
        // Tokenize the rest of the line while p != NULL
        while ((p1 = strtok(NULL, DELIMS)) != NULL) {
            if (wordCount(a, wordCt, p1, arrayCt) == false) {
                strcpy(a[arrayCt++], p1);
            }
        }
        rowCt++; // Number of rows count
    }

    for (i = 0; i < arrayCt; i++) { // Calcualtes number of words seen in file
        sum += wordCt[i];
    }
    if (sum > 0) { // If at least 1 word has been seen in file
        for (i = 0; i < arrayCt; i++) { // Printing each word and its count
            output << left << setw(15) << a[i] <<wordCt[i] << endl;
        }
        // Printing various other stats
        output << "Number of words = " << sum << endl;
        output << "Number of rows = " << rowCt << endl;
        output << "Shortest word = " << a[wordLen(a, true)] << endl;
        output << "Longest word = " << a[wordLen(a, false)] << endl;
    }
    else { // If there are no words in the array
        output << "No data in file." << endl;
    }
    input.close();
    output.close();
    return 0;
}
// wordCount compares the current tokenized word with the rest of the array and
// if a match is found it increments the count for that word. It returns if the
// word is unique or not, so main() knows to save the word or not.
bool wordCount(char a[][16], int wordCt[], char *p1, int arrayCt) {
    int i = 0;
    bool found = false;
    while (strcmp(a[i], "") != 0) { // While you haven't hit a blank element
        if (strcmp(a[i], p1) == 0) { // If a match is found
            wordCt[i]++; // Increment the associated word count
            found = true;
        }
        i++;
    }
    if (found == false) { // If it is a unique word increment its count
        wordCt[arrayCt]++;
    }
    return found;
}
// wordLen returns the index of either the shortest or longest word in the array.
// If there is a tie, the word that is seen first in the file is returned.
int wordLen(char a[][16], bool shortest) {
    int length = 0, i = 0;
    while (strcmp(a[++i], "") != 0) {
        if (shortest == true) {
            if (strlen(a[length]) > strlen(a[i])) { // Compares for the shortest word
                length = i;
            }
        }
        else {
            if (strlen(a[length]) < strlen(a[i])) { // Compares for the longest word
                length = i;
            }
        }
    }
    return length; // Returns the index of the shortest or longest word.
}
