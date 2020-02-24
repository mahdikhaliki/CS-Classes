//
// WorkerClient.cpp
//
// Mahdi Khaliki and Brian Deitchman
// 4/10/17
// Lab 6
// Extracts employee information and changes information
//
#include "ProductionWorker.h"
#include <iostream>
#include <iomanip>

ProductionWorker::ProductionWorker() : Employee()
{ // if shift and hourly pay are not supplied set them to a default value
    _shift = -1;
    _HourlyPay = -1;
}

ProductionWorker::ProductionWorker(string f, string l, int eN, int m, int d,
                                   int y, string s, double h) : Employee(f, l, eN, m, d, y)
{
    _shift = s; // sets shift and pay to value supplied
    _HourlyPay = h;
}

void ProductionWorker::setAll(string f, string l, int eN, int m, int d, int y,
                              string s, double h) {
    Employee::setAll(f, l, eN, m, d, y); // lets you change every field
    _shift = s;
    _HourlyPay = h;
}

void ProductionWorker::setFirst(string first) {
    Employee::setFirst(first);
}

void ProductionWorker::setLast(string last) {
    Employee::setLast(last);
}

void ProductionWorker::setENum(int num) {
    Employee::setENum(num);
}

void ProductionWorker::setDate(int month, int day, int year) {
    Employee::setDate(month, day, year);
}

void ProductionWorker::setShift(string shift) {
    _shift = shift;
}

void ProductionWorker::setHourlyPay(double pay) {
    _HourlyPay = pay;
}
// prints the persons info in the correct format
ostream &operator <<(ostream &out, ProductionWorker &p) {
    out  << left << setw(10) <<  p._first << setw(15) << p._last << setw(12)
    << p._EmployeeNumber << right << setw(2) << setfill('0')
    << p._month << '/'  << setw(2) << p._day << '/' << left << setfill(' ')
    << setw(14) << p._year << setw(10) << p._shift << '$' << fixed
    << setprecision(2) << p._HourlyPay << flush;
    return out;
}
// extracts info from input file
istream &operator >>(istream &in, ProductionWorker &p) {
    char t;
    int s;
    in >> t >> p._first >> p._last >> t >> p._EmployeeNumber >> t >> p._month
    >> t >> p._day >> t >> p._year >> t >> s >> t >> p._HourlyPay >> t;
    p._shift = s == 0 ? "Day" : p._shift;
    p._shift = s == 1 ? "Evening" : p._shift;
    p._shift = s == 2 ? "Night" : p._shift;
    return in;
}
