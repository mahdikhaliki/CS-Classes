//
// baseBall.cpp
//
// Mahdi Khaliki
// Final Project
// Reads a player names file and stores the data into an array struct and
// prints a roster to the output file. Then reads a stats file and maps the
// stats according to the player number and then calculates each players batting
// average and on base average (only if the season has been played and the player
// has played at lease one game). Following that the stats are printed in
// alphabetical order, batting average (H-L), and on base average. Then the best
// and worst hitter and base runner are printed;
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// Function prototypes
void Exchange(struct players *a, struct players *b);
void SelectSort(struct players p[], int n, string field);
void PrintArray(struct players p[], int n, ostream &output, string order);

struct players // Struct to hold player data in
{
    string fName, lName;
    int playerNumber, hits = 0, walks = 0, outs = 0, numberOfGames = 0;
    float battingAverage = 0, onBaseAverage = 0;
};

int main()
{
    // Declaring varibles
    int i, y = 0, hits, walks, outs, hitter = 0, runner = 0, badHitter, badRunner;
    float teamOnBase = 0, teamHitting = 0;
    bool played = false;
    string playerNameFile = "playerNames1.txt", playerStatsFile = "baseballStats1.txt", outPutFile = "playerNames1Output5.txt";
    players p[20];
    
    // Prompting for input and output file names from user.
//    cout << "Enter players file: " << flush;
//    cin >> playerNameFile;
//    cout << "Enter stats file: " << flush;
//    cin >> playerStatsFile;
//    cout << "Enter output file: " << flush;
//    cin >> outPutFile;
    
    // Opening intput and output files
    ifstream players (playerNameFile), stats (playerStatsFile);
    ofstream output (outPutFile);
    if(!players || !stats || !output) // Checking if file opens failed
    {
        cout << "Error opening files." << endl;
        return -1;
    }
    
    // Printing input and output file names to output file
    output << "Input file names: " << playerNameFile << " and "
    << playerStatsFile << endl;
    output << "Output file name: " << outPutFile << endl;
    // Printing header for roster
    output << "\nTeam Roster\n" << left << setw(3) << '#' << setw(15) << "L-Name"
    << setw(15) << "F-Name"<< endl;
    // Saving player names to struct array and printing roster
    for(i = 0; i < 20; i++)
    {
        players >> p[i].lName >> p[i].fName;
        p[i].playerNumber = i + 1; // Assigning player numbers to each player
        output << left << setw(3) << p[i].playerNumber << setw(15) << p[i].lName
        << setw(15) << p[i].fName << endl;
    }
    players.close(); // Done with player file, closing file.
    stats >> y; // Priming read
    while (y != -1) // While the player number is not -1
    {
        for (i = 0; i < 20; i++) // For loop to compare y to player number
        {
            if (y == p[i].playerNumber) // If match is found
            {
                p[i].numberOfGames++; // Increment number of games played
                stats.ignore(); // Ignore the comma
                stats >> hits; // Get the integer
                p[i].hits += hits; // Add it to the array struct
                stats.ignore();
                stats >> walks;
                p[i].walks += walks;
                stats.ignore();
                stats >> outs;
                p[i].outs += outs;
            }
            if (p[i].numberOfGames != 0) // If a player has played a game
            {
                played = true;
            }
        }
        stats >> y;
    }
    stats.close(); // Done with stats file, closing file.
    
    if (played == true) // If a player has played
    {
        // Making calculations
        for (i = 0; i < 20; i++)
        {
            if (p[i].numberOfGames != 0)
            {
                p[i].battingAverage = static_cast<float>(p[i].hits)
                / (p[i].hits + p[i].outs);
                
                p[i].onBaseAverage = (static_cast<float>(p[i].hits) + p[i].walks)
                / (p[i].hits + p[i].walks + p[i].outs);
            }
            teamHitting += p[i].hits; // Adding to the team hits for average
            teamOnBase += p[i].onBaseAverage; // Adding up team on base
        }
        
        // Sorting and printing stats in alphabetical order
        SelectSort(p, 20, "name");
        PrintArray(p, 20, output, "Alphabetically");
        
        // Sorting and printing stats in batting average (H-L)
        SelectSort(p, 20, "battingAverage");
        PrintArray(p, 20, output, "Batting Average H-L");
        
        // Sorting and printing stats in on base average (H-L)
        SelectSort(p, 20, "onBaseAverage");
        PrintArray(p, 20, output, "On Base Average H-L");
        
        // Finding best hitter and on base average player
        for (i = 0; i < 20 - 1; i++)
        {
            if (p[hitter].hits < p[i + 1].hits)
            {
                hitter = i + 1;
            }
            if (p[runner].onBaseAverage < p[i].onBaseAverage)
            {
                runner = i;
            }
        }
        // Finding the worst hitter and on base average player
        badHitter = 0;
        badRunner = 0;
        for (i = 20 - 1; i > 0; i--)
        {
            // Comparing only if the player has played a game (omiting inactive)
            if (p[i].numberOfGames != 0)
            {
                if (p[badHitter].hits > p[i].hits)
                {
                    badHitter = i;
                }
                if (p[badRunner].onBaseAverage > p[i].onBaseAverage)
                {
                    badRunner = i;
                }
            }
        }
        // Printing various other stats
        output << "\nBest hitter: " << p[hitter].lName << ' ' << p[hitter].fName
        << right << setw(30)<< "Batting Average: " << p[hitter].battingAverage
        << "\nBest base runner: " << p[runner].lName << ' ' << p[runner].fName
        << setw(30)<< "On base percentage: " << p[runner].onBaseAverage
        << "\nTeam average hits: " << teamHitting/20
        << "\nTeam on base average: " << teamOnBase/20
        << "\nWorst hitter: " << p[badHitter].lName << ' ' << p[badHitter].fName
        << setw(30)<< "Batting Average: " << p[badHitter].battingAverage
        << "\nWorst base Runner: " << p[badRunner].lName << ' '
        << p[badRunner].fName << setw(30) << "On base percentage: "
        << p[badRunner].onBaseAverage << endl;
    }
    else // If no player has played
    {
        output << "\nNo Stats" << endl;
    }
    return 0;
}

void Exchange(struct players *a, struct players *b) // Swaping the whole element
{
    players t = *a;
    *a = *b;
    *b = t;
    return;
}

void SelectSort(struct players p[], int n, string field)
{
    int i, currentValue, j;
    for (i = 0; i < n - 1; i++)
    {
        currentValue = i; // Using one value holder for all 3 sorts
        for (j = i + 1; j < n; j++)
        {
            if (field == "name")
            {
                if (p[currentValue].lName > p[j].lName)
                {
                    currentValue = j;
                }
            }
            if (field == "battingAverage")
            {
                if (p[currentValue].battingAverage < p[j].battingAverage)
                {
                    currentValue = j;
                }
            }
            if (field == "onBaseAverage")
            {
                if (p[currentValue].onBaseAverage < p[j].onBaseAverage)
                {
                    currentValue = j;
                }
            }
        }
        Exchange(&p[i], &p[currentValue]);
    }
}

// Printing the stats with a header
void PrintArray (struct players p[], int n,  ostream &output, string order)
{
    cout << endl;
    cout << order << left << setw(4) << "\n#" << setw(15) << "L-Name"
    << setw(15) << "F-Name" <<setw(6) << "Hits" << setw(7) << "Walks" << setw(8)
    << "Outs" << setw(17) << "Batting Average" << "On Base Average" << endl;
    for (int i = 0; i < n; i++)
    {
        if (p[i].numberOfGames != 0)
        {
            cout << left << setw(3) << p[i].playerNumber << setw(15)
            << p[i].lName << setw(15) << p[i].fName << setw(6) << fixed
            << setprecision(3) << p[i].hits << setw(7) << p[i].walks << setw(8)
            << p[i].outs << setw(17) << p[i].battingAverage<< setw(8)
            << p[i].onBaseAverage <<  endl;
        }
    }
}
