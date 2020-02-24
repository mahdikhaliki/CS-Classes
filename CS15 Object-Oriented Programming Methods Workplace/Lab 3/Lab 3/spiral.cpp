//
// spiral.cpp
//
// Mahdi Khaliki and Adam Yin
// Lab 3
// Uses a table of dimensions to fill in the top left corner of a 15X20 array in
// a clockwise fashion from 1 to (rows * columns).
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int ROW = 15, COL = 20, TABLE = 14; // Constants to be used throughout
// Function prototypes
void makeSpiral(int n[][COL], int rowLength, int colLength);
void clearArray(int n[][COL], int rows);
void printSpiral(int n[][COL], ofstream &output, int rowLength, int colLength);

int main(int argc, char *argv[]) {
    if (argc < 2) { // Checking if user gave an output file name
        cout << "User did not enter output file name." << endl;
        return -1;
    }
    // Decaring varibles
    int n[ROW][COL], i = 0;
    int t[TABLE][2] = {{1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {4,7}, {7,4}, {15,20},
        {2,8}, {12,10}, {3,10}, {8,9}, {0,10}, {1,20}};
    
    ofstream output(argv[1]); // Opening output file
    if (!output) { // Checking if open failed or not
        cout << "Error opening file." << endl;
        return -2;
    }
    
    while (i < TABLE) { // Looping to fill different dimensions from t[][]
        clearArray(n, ROW);
        makeSpiral(n, t[i][0], t[i][1]);
        printSpiral(n, output, t[i][0], t[i][1]);
        i++;
    }
    output.close();
    return 0;
}
// makeSpiral fills the top left of n[][] going clockwise with integers
// from 1 to (rows * columns)
void makeSpiral(int n[][COL], int rowLength, int colLength) {
    int row = 0, col = 0, i, k = 1, amount;
    amount = rowLength * colLength + 1; // The last value that will be filled
    rowLength--; // Decrementing rowLength because of the top row
    while (k < amount) {
        i = 0;
        while ((i < colLength)&&(k < amount)) { // Going right
            n[row][col++] = k++; // Setting element to appropriate value
            i++;
        }
        col--; // Adjusting current column location
        row++; // Adjusting current row location
        colLength--; // Decrementing column length
        i = 0; // Resetting to 0 for next loop
        while ((i < rowLength)&&(k < amount)) { // Going down
            n[row++][col] = k++;
            i++;
        }
        row--;
        col--;
        rowLength--;
        i = 0;
        while ((i < colLength)&&(k < amount)) { // Going left
            n[row][col--] = k++;
            i++;
        }
        col++;
        row--;
        colLength--;
        i = 0;
        while ((i < rowLength)&&(k < amount)) { // Going up
            n[row--][col] = k++;
            i++;
        }
        row++;
        col++;
        rowLength--;
    }
}
// clearArray sets the value of each element in the array to 0
void clearArray(int n[][COL], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COL; j++) {
            n[i][j] = 0;
        }
    }
}
// printSpiral prints the array with its dimensions
void printSpiral(int n[][COL], ofstream &output, int rowLength , int colLength) {
    int a = 0, b = 0;
    output << '\n' << rowLength << 'X' << colLength << endl;
    while(a < ROW) {
        while(b < COL) {
            output << setw(4) << n[a][b++] << flush;
        }
        output << endl;
        b=0;
        a++;
    }
}
