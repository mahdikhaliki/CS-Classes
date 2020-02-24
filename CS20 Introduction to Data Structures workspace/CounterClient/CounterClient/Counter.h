#ifndef Counter_h
#define Counter_h

#include <iostream>
using namespace std;

class Counter {
    friend ostream &operator <<(ostream &out, const Counter &obj);
    friend istream &operator >>(istream &in, Counter &obj);
    
private:
    static const int MAXDIGITS = 40000;
    char digits[MAXDIGITS];
    int numDigits;
    
    void incrementHelper(int position);
    void decrementHelper(int position);
    void subHelper(int position);
    void moveNumDigits();
    Counter multiply(char digit) const;
    Counter & times10();
public:
    Counter(int n = 0);
    Counter(const string &value);
    void set(int n);
    void set(const string &value);
    int getNumDigits();
    bool operator<(const Counter &other) const;
    bool operator==(const Counter &other) const;
    bool operator<=(const Counter &other) const;
    bool operator>(const Counter &other) const;
    bool operator!=(const Counter &other) const;
    bool operator>=(const Counter &other) const;
    Counter operator+(const Counter &other) const;
    Counter& operator+=(const Counter &other);
    Counter& operator++();
    Counter operator++(int dummy);
    Counter operator-(const Counter &other) const;
    Counter& operator-=(const Counter &other);
    Counter& operator--();
    Counter operator--(int dummy);
    Counter& operator*=(const Counter &other);
    Counter operator*(const Counter &other) const;
};

#endif /* Counter_h */
