#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include "Employee.h"

class ProductionWorker : public Employee
{
    friend ostream &operator <<(ostream &out, ProductionWorker &p);
    friend istream &operator >>(istream &in, ProductionWorker &p);
private:
    string _shift;
    double _HourlyPay;
public:
    ProductionWorker();
    ProductionWorker(string, string,int,int,int,int,string,double);
    void setAll(string, string, int, int, int, int, string, double);
    void setFirst(string);
    void setLast(string);
    void setENum(int);
    void setDate(int, int, int);
    void setShift(string);
    void setHourlyPay(double);
};

#endif // PRODUCTIONWORKER_H
