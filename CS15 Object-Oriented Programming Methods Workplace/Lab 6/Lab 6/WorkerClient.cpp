//
// WorkerClient.cpp
//
// Mahdi Khaliki and Brian Deitchman
// 4/10/17
// Lab 6
// Extracts employee information and changes information.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Employee.h"
#include "ProductionWorker.h"
using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {// makes sure correct number of arguments were entered
        cout << "User did not enter enough arguments." << endl;
        return -1;
    }
    Employee e[10];// array of employees
    ProductionWorker p[10];// array of productions workers
    int i = 0, j = 0, s = 0, h = 0;
    ifstream in(argv[1]);
    ofstream out(argv[2]);
    if (!in || !out) {// makes sure the files open
        out << "Error opening files." << endl;
        return -1;
    }
    out << left << setw(10) <<  "First" << setw(15) << "Last" << setw(12)
    << "Employee#" << setw(20) << "Date (mm/dd/yyyy)" << setw(10) << "Shift"
    << "Hourly Pay" << endl; // sets up the format for the output file
    while (!in.eof()) {//while not at the end of file extract info
        char t;
        in >> t;
        if (in.eof()) {
            break;
        }
        if (t == 'E') {// checks if the person is an employee
            in >> e[i];// if they are add them to the array
            out << e[i] << endl;// prints their info
            i++;
        }
        else if (t == 'P') {// checks if they're a production worker
            in >> p[j]; // add them to the array
            out << p[j] << endl;// print their info
            j++;
        }
    }
    // Demonstrates that we can change a persons info
    e[0].setAll("Change", "Change", 1234, 6, 1, 1777);
    e[1].setLast("Change");
    e[2].setAll("Change", "Change", 4321, 8, 30, 1897);
    e[3].setDate(5, 6, 2007);
    p[0].setAll("Change", "Change", 987, 12, 25, 1997, "Day", 120.54);
    p[1].setLast("Change");
    p[2].setENum(9999);
    p[3].setAll("Change", "Change", 999999, 1, 1, 1970, "Evening", 15.67);
    p[4].setShift("Day");
    p[5].setAll("Change", "Change", 666, 6, 6, 1666, "Night", 19.70);
    
    out << "\nChanging fields" << endl; // prints the workers again after
    for (s = 0; s < i; s++) {           // after changes fields
        out << e[s] << endl;
    }
    for (h = 0; h < j; h++) {
        out << p[h] << endl;
    }

    in.close(); // closes files
    out.close();
    return 0;
}
