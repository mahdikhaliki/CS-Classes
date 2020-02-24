//
// TwoDArrayClient.cpp
//
// Wellington Ginah
// Lab 7
// Reads the dementions of a map from an input file, creates a 2D array of
// that size, moves the mouse at random through the map and checks if the mouse
// on the island has drowned(wondered on the edge of the map), escaped(via 2
// bridges on the island) or starved to death. Finally prints out the map of how
// frequent the mouse moved to each spot on the island and prints the stats of
// fate of the mouse for 100 lives.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include "TwoDArray.hpp"
using namespace std;

struct POSITION
{
    int x = 0, y = 0;
};
struct BRIDGES
{
    POSITION _1;
    POSITION _2;
};
struct STATS
{
    int Drowned = 0, Starved = 0, Escaped = 0;
};

void moveMouse(TwoDArray &map, POSITION &currentPos);
bool checkPos(ostream& fout, TwoDArray &map, POSITION &currentPos,
              BRIDGES &bridges, STATS &s);
void readMap(istream &in, TwoDArray &map, int rows, int cols,
             BRIDGES &bridges, POSITION &initialPos);
void printMap(ostream &fout, TwoDArray &map, int rows, int cols, int largest);
void printStats(ostream& fout, STATS m_stats);
int findLargest(TwoDArray &fmap, int rows, int cols);


int main( int argc, char *argv[] )
{
    ifstream fin;
    ofstream fout;
    
    if( argc < 2 )
    {
        cout << "Usage: [Progname] input-file output-file seed-value(-1 to seed"
        << " with time)" << endl;
        return -2;
    }
    else // argc >= 3
    {
        fin.open(argv[1]); //inFile
        fout.open(argv[2]); //outFile
        if( !fin || !fout )
        {
            cout << "Error opening files" << endl;
            exit( -2 );
        }
    }
    fout << "Input file: " << argv[1] << endl;
    fout << "Input file: " << argv[2] << endl;
    if(argc >= 4) // did user supply seed for the random number generator?
    {
        if (atol(argv[3]) == -1)
        {
            fout << "Seeded with time. " << endl;
            srand( time(NULL) ); // seed random number generator from time
        }
        else
        {
            fout << "Seeded with value: " << argv[3] << endl;
            srand( atoi(argv[3]) ); // seed with set value from command line
        }
    }
    else
    {
        fout << "Did not seed." << endl;
    }
    
    int rows, cols;
    POSITION initialPos, currentPos;
    BRIDGES bridges;
    STATS m_stats;
    
    fin >> rows >> cols; // Gets number of rows and cols from file.
    TwoDArray map(rows, cols);
    TwoDArray freqMap(rows, cols);
    
    readMap(fin, map, rows, cols, bridges, initialPos);
    fout << "The map is: " << endl;
    printMap(fout, map, rows, cols, 3);
    currentPos = initialPos;

    int lives = 0;
    while (lives++ < 100)
    {
        bool starve = true;
        int moves = 0;
        while (moves++ < 100)
        {
            moveMouse(map, currentPos);
            freqMap[currentPos.x][currentPos.y] += 1; // Increase frequency of spot;
            if (!checkPos(fout, map, currentPos, bridges, m_stats))
            {
                starve = false;
                break;
            }
        }
        if (starve)
        {
            m_stats.Starved++;
            fout << "\nAfter a gruesome journey, "
            << "the mouse succumbs to starvation! (STARVED)" << endl;
        }
        currentPos = initialPos; //resets mouse to original position
    }
    int largest = findLargest(freqMap, rows, cols);
    fout << "\nFrequency Map: " << endl;
    printMap(fout, freqMap, rows, cols, largest);
    printStats(fout, m_stats);
    
    fout.close();
    fin.close();
    return 0;
}

void printStats(ostream& fout, STATS m_stats)
{
    fout << "Drowned: " << m_stats.Drowned << endl;
    fout << "Starved: " << m_stats.Starved << endl;
    fout << "Escaped: " << m_stats.Escaped << endl;
    
}

void moveMouse(TwoDArray &map, POSITION &currentPos)
{
    int r = rand() % 4; // random 0...3
    // use a table to avoid the complexity
    // static to avoid reloading the table on each function call
    //                     up, right, down, left
    static int moves[2][4] = {{ 0, 1, 0, -1 },
        { -1, 0, 1, 0 }};
    
    // Make move
    currentPos.x += moves[0][r];
    currentPos.y += moves[1][r];
}

bool checkPos(ostream& fout, TwoDArray &map, POSITION &currentPos,
              BRIDGES &bridges, STATS &s)
{
    if ((currentPos.x == bridges._1.x && currentPos.y == bridges._1.y)
        || (currentPos.x == bridges._2.x && currentPos.y == bridges._2.y))
    {
        fout << "\nMouse miraculously missed mortality!(ESCAPED)" << endl;
        s.Escaped++;
        return false;
    }
    else if (map[currentPos.x][currentPos.y] == -1)
    {
        fout << "\nDead mouse! (DROWNED)" << endl;
        s.Drowned++;
        return false;
    }
    return true;
}

void readMap(istream &in, TwoDArray &map, int rows, int cols,
             BRIDGES &bridges, POSITION &initialPos)
{
    int value; // Variable to be used to extract the input values.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            in >> value;
            // Checks the edge of the map for bridges
            if ((i == 0 || i == rows - 1) || (j == 0 || j == cols - 1))
            {
                if (value == 0)
                {
                    // Check if the first bridge is already occupied
                    if(bridges._1.x == 0 && bridges._1.y == 0)
                    {
                        bridges._1.x = i;
                        bridges._1.y = j;
                    }
                    else // else occupy the second bridge coordinates.
                    {
                        bridges._2.x = i;
                        bridges._2.y = j;
                    }
                }
            }
            if (value == 1) // Save the initial position of the mouse
            {
                initialPos.x = i;
                initialPos.y = j;
            }
            map[i][j] = value; // Save the value from input to the array
        }
    }
    
}
void printMap(ostream &fout, TwoDArray &map, int rows, int cols, int col_width)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            // Printing the array based on the supplied column width
            fout << left << setw(col_width) << map[i][j] << flush;
        }
        fout << endl;
    }
}
int findLargest(TwoDArray &fmap, int rows, int cols)
{
    // Searches the array for the largest value
    int largest = fmap[0][0];
    for(int i =0; i < rows; i++)
    {
        for(int j = 0; j < cols - 1; j++)
        {
            // Adjust largest if larger value is found
            if(largest < fmap[i][j+1])
            {
                largest = fmap[i][j+1];
            }
        }
    }
    
    int digitCount = 1;
    while (largest > 0) // Checks how many digits the largest value has.
    {
        digitCount++; // Add
        largest /= 10; // Dividing by 10 to get digitCount
    }
    return digitCount;
}
