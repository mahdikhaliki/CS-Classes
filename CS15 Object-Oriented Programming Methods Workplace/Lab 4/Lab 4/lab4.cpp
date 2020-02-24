//
// lab4.cpp
//
// Mahdi Khaliki and Hao Ye
// Lab 4
// Uses a table of dimensions to fill in the top left corner of a 15X20 array in
// a clockwise fashion from 1 to (rows * columns).
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Function prototypes
const int TABLE = 14;
void makeSpiral(int *a, int rows, int columns);
void clearArray(int *a, int rows, int columns);
void printSpiral(int *a, int rows, int columns, ofstream &output);

int main(int argc, char *argv[]) {
    if (argc < 2) { // Checking if user gave an output file name
        cout << "User did not enter output file name." << endl;
        return -1;
    }
    // Declaring varibles, t[][] is used as a table of dimensions
    int i = 0;
    int t[TABLE][2] = {{1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {4,7}, {7,4}, {4,8},
        {8,4}, {15,20}, {3,10}, {8,9}, {0,10}, {1,20}};
    // Declaring arrays
    int a1[1][1], a2[2][2], a3[3][3], a4[4][4], a5[5][5], a6[4][7], a7[7][4],
        a8[4][8], a9[8][4], a10[15][20], a11[3][10], a12[8][9], a13[0][10], a14[1][20];
    // *pointer[][] holds the address of the base of each array
    int *pointer[TABLE] = {&a1[0][0], &a2[0][0], &a3[0][0], &a4[0][0], &a5[0][0],
        &a6[0][0], &a7[0][0], &a8[0][0], &a9[0][0], &a10[0][0], &a11[0][0],
        &a12[0][0], &a13[0][0], &a14[0][0]};
    
    ofstream output("lab4Output.txt"); // Opening output file
    if (!output) { // Checking if open failed
        cout << "Error opening file." << endl;
        return -2;
    }
    // Looping to fill each array based on dimensions from t[][] and pointer[][]
    while (i < TABLE) {
        clearArray(pointer[i], t[i][0], t[i][1]);
        makeSpiral(pointer[i], t[i][0], t[i][1]);
        printSpiral(pointer[i], t[i][0], t[i][1], output);
        i++;
    }
    output.close();
    return 0;
}
// makeSpiral fills the top left of *n going clockwise with integers
// from 1 to (rows * columns)
void makeSpiral(int *a, int rows, int columns) {
    int row = 0, col = 0, i, k = 1, amount, colLength = columns;
    amount = rows * columns + 1; // The last value that will be filled
    rows--; // Decrementing rowLength because of the top row
    while (k < amount) {
        i = 0;
        while ((i < columns) && (k < amount)) { // Going right
            *(a + row * colLength + col++) = k++; // Setting element to appropriate value
            i++;
        }
        col--; // Adjusting current column location
        row++; // Adjusting current row location
        columns--; // Decrementing column length
        i = 0; // Resetting to 0 for next loop
        while ((i < rows) && (k < amount)) { // Going down
            *(a + row++ * colLength + col) = k++;
            i++;
        }
        row--;
        col--;
        rows--;
        i = 0;
        while ((i < columns) && (k < amount)) { // Going left
            *(a + row * colLength + col--) = k++;
            i++;
        }
        col++;
        row--;
        columns--;
        i = 0;
        while ((i < rows) && (k < amount)) { // Going up
            *(a + row-- * colLength + col) = k++;
            i++;
        }
        row++;
        col++;
        rows--;
    }
}
// clearArray sets the value of each element in the array to 0
void clearArray(int *a, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            *(a + i * rows + j) = 0;
        }
    }
}
// printSpiral prints the array with its dimensions
void printSpiral(int *a, int rows , int columns, ofstream &output) {
    int i = 0, j = 0;
    output << '\n' << rows << 'X' << columns << endl;
    while(i < rows) {
        while(j < columns) {
            output << setw(4) << *(a + i * columns + j++) << flush;
        }
        output << endl;
        j=0;
        i++;
    }
}
