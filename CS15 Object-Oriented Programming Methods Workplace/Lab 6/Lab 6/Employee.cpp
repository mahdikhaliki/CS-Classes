//
// WorkerClient.cpp
//
// Mahdi Khaliki and Brian Deitchman
// 4/10/17
// Lab 6
// Extracts employee information and changes information
//

#include "Employee.h"
#include<string>
#include<iostream>
#include <iomanip>

Employee::Employee() { // Default constructor
    _first = "";
    _last = "";
    _EmployeeNumber = -1;
    _month = 1;
    _day = 1;
    _year = 1970;
}

Employee::Employee(string first, string last, int num, int mon, int d, int y) {
    setAll(first, last, num, mon, d, y);//sets all the variables
}
// lets the client set all the variables
void Employee::setAll(string first, string last, int num,int mon,int d,int y) {
    _first = first;
    _last = last;
    _EmployeeNumber = num;
    _month = mon;
    _day = d;
    _year = y;
}

void Employee::setFirst(string first) {
    _first = first;
}

void Employee::setLast(string last) {
    _last = last;
}

void Employee::setENum(int num) {
    _EmployeeNumber = num;
}

void Employee::setDate(int month, int day, int year) {
    _month = month;
    _day = day;
    _year = year;
}
// prints the info in the correct format
ostream &operator <<(ostream &out, Employee &e) {
    out << left << setw(10) <<  e._first << setw(15) << e._last << setw(12)
    << e._EmployeeNumber << right << setw(2) << setfill('0') << e._month
    << '/' << setw(2) << e._day << '/' << setw(4) << e._year << setfill(' ')
    << flush;
    return out;
}
// gets input from file
istream &operator >>(istream &in, Employee &e) {
    char t;
    in >> t >> e._first >> e._last >> t >> e._EmployeeNumber >> t >> e._month
    >> t >> e._day >> t >> e._year >> t;
    return in;
}
