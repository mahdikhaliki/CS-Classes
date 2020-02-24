//
// finalProject.cpp
//
// Mahdi Khaliki
// Final Project
// Reads a map of a maze from an input file and using recursive backtracking
// solves the maze and prints the solution to an output file.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool solveMaze(char map[][81], int i, int j, int nRow, int nCol);
void printArray(ostream &out, char map[][81], int nRow, int nCol);

int main() {
    // Creating an array to hold the map and declaring variables
    char map[24][81], input[50], output[50];
    int nRow = 0, nCol = 0, i, s = 0, j = 0;
    // Getting input and output file names from user
    cout << "Please enter input file name: " << flush;
    cin >> input;
    cout << "Please enter output file name: " << flush;
    cin >> output;
    // Opening input and output files
    ifstream in(input);
    ofstream out(output);
    if (!in || !out) { // Checking if file opens worked correctly
        cout << "Error opening files." << endl;
        return -2;
    }
    in >> nRow >> nCol; // Extracting number of rows and columns
    in.ignore();// Ignoring the \n
    for (i = 0; i < nRow + 1; i++) { // Saving map into array
        in.getline(map[i], 81);
    }
    in.close(); // Closing input file
    printArray(out, map, nRow, nCol); // Printing original map
    solveMaze(map, s, j, nRow, nCol); // Solving maze
    out << "\nSolved Maze: " << endl; // Printing the solution map
    printArray(out, map, nRow, nCol);
    out.close(); // Closing output file
    return 0;
}

bool solveMaze(char map[][81], int i, int j, int nRow, int nCol) {
    // Mark the current position with '#'
    map[i][j] = '#';
    // Check if the position is at the end of the maze(base case)
    if (i == nRow - 1 && j == nCol - 1) {
        return true;
    }
    // Try going up
    if (i > 0 && map[i - 1][j] == ' ') {
        // Make another call to self with new position
        if (solveMaze(map, i - 1, j, nRow, nCol)) {
            return true;
        }
    }
    // Try going right
    if (j < nCol && map[i][j + 1] == ' ') {
        // Make another call to self with new position
        if (solveMaze(map, i, j + 1, nRow, nCol)) {
            return true;
        }
    }
    // Try going down
    if (i < nRow && map[i + 1][j] == ' ') {
        // Make another call to self with new position
        if (solveMaze(map, i + 1, j, nRow, nCol)) {
            return true;
        }
    }
    // Try going left
    if (j > 0 && map[i][j - 1] == ' ') {
        // Make another call to self with new position
        if (solveMaze(map, i, j - 1, nRow, nCol)) {
            return true;
        }
    }
    // If all of the above conditions are false then mark position with '@'
    map[i][j] = '@';
    return false;
}
// Print the array without the blind alleys
void printArray(ostream &out, char map[][81], int nRow, int nCol) {
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (map[i][j] != '@') {
                out << map[i][j] << flush;
            }
            else {
                out << ' ' << flush;
            }
        }
    out << endl;
    }
}
