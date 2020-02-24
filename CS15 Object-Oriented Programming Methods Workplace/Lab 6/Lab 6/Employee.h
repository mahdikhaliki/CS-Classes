#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
    friend ostream &operator <<(ostream &out, Employee &a);
    friend istream &operator >>(istream &in, Employee &a);
protected:
    string _first, _last;
    int _EmployeeNumber;
    int _month;
    int _day;
    int _year;
public:
    Employee();
    Employee(string, string, int, int, int, int);
    void setAll(string, string, int, int, int, int);
    void setFirst(string);
    void setLast(string);
    void setENum(int);
    void setDate(int, int, int);
};

#endif // EMPLOYEE_H
