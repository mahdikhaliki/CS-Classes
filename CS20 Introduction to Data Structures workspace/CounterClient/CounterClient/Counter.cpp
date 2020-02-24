#include "Counter.h"

Counter::Counter(int n) {
    set(n);
}

Counter::Counter(const string &value) {
    set(value);
}

ostream &operator <<(ostream &out, const Counter &obj) { 
    for (int i = obj.numDigits - 1; i >= 0; i--) {
        out << static_cast<char>(obj.digits[i] + 48) << flush;
    }
    return out;
}

istream &operator >>(istream &in, Counter &obj){ 
    string s;
    in >> s;
    obj.set(s);
    return in;
}

void Counter::set(int n) { 
    int i = 0;
    
    for (i = 0; i < MAXDIGITS; i++) {
        digits[i] = 0;
    }
    i = 0;
    if (n == 0) {
        numDigits = 1;
        return;
    }
    while (n > 0) {
        digits[i++] = n % 10;
        n /= 10;
    }
    numDigits = i;
}

int Counter::getNumDigits() {
    return numDigits;
}

void Counter::set(const string &value) { 
    int i = 0, j = 0;
    numDigits = 0;
    for (i = 0; i < MAXDIGITS; i++) {
        digits[i] = 0;
    }
    for (i = (int) value.length() - 1, j = 0; i >= 0; i--, j++) {
        char temp = value[i] - 48;
        digits[j] = temp;
        numDigits++;
    }
}

bool Counter::operator<(const Counter &other) const { 
    if (numDigits != other.numDigits) {
        return numDigits < other.numDigits;
    }
    else {
        for (int i = numDigits; i >= 0; i--) {
            if (digits[i] < other.digits[i]) {
                return true;
            }
        }
    }
    return false;
}

bool Counter::operator==(const Counter &other) const { 
    if (numDigits != other.numDigits) {
        return false;
    }
    else {
        for (int i = 0; i < numDigits; i++) {
            if (digits[i] != other.digits[i]) {
                return false;
            }
        }
    }
    return true;
}

bool Counter::operator<=(const Counter &other) const { 
    return *this < other || *this == other;
}

bool Counter::operator>(const Counter &other) const { 
    return !(*this <= other);
}

bool Counter::operator!=(const Counter &other) const { 
    return !(*this == other);
}

bool Counter::operator>=(const Counter &other) const { 
    return !(*this < other);
}

Counter Counter::operator+(const Counter &other) const { 
    return Counter(*this) += other;
}

Counter& Counter::operator+=(const Counter &other) { 
    int carry = 0;
    
    if (other.numDigits > numDigits) {
        numDigits = other.numDigits;
    }
    for (int i = 0; i < numDigits; i++) {
        digits[i] = digits[i] + other.digits[i] + carry;
        if (digits[i] > 9) {
            carry = 1;
            digits[i] %= 10;
        }
        else {
            carry = 0;
        }
        if (carry == 1 && i == numDigits - 1) {
            numDigits++;
        }
    }
    return *this;
}

Counter& Counter::operator++() { 
    if (digits[0] == 9) {
        incrementHelper(0);
    }
    else {
        digits[0]++;
    }
    return *this;
}

Counter Counter::operator++(int dummy) { 
    Counter temp = *this;
    this->operator++();
    return temp;
}

void Counter::incrementHelper(int position) { 
    if (position + 1 >= numDigits) {
        numDigits++;
    }
    digits[position] = 0;
    
    if (digits[position + 1] + 1 > 9) {
        incrementHelper(position + 1);
    }
    else {
        digits[position + 1]++;
    }
}

Counter Counter::operator-(const Counter &other) const { 
    return Counter(*this) -= other;
}

Counter& Counter::operator-=(const Counter &other) { 
    int carry = 0;
    
    if (other.numDigits > numDigits || *this < other) {
        this->set(0);
        return *this;
    }
    
    for (int i = 0; i < other.numDigits; i++) {
         digits[i] -= other.digits[i] - carry;

        if (digits[i] < 0) {
            carry = 1;
            digits[i] += 10;
        }
        else {
            carry = 0;
        }
        if (carry == 1 && i == other.numDigits - 1) {
            subHelper(i + 1);
        }
    }
    moveNumDigits();
    return *this;
}

void Counter::subHelper(int position) {
    digits[position]--;
    if (digits[position] < 0) {
        subHelper(position + 1);
    }
}

void Counter::moveNumDigits() { 
    int i = numDigits - 1;
    while (digits[i] == 0) {
        numDigits--;
        i--;
    }
}

Counter& Counter::operator--() { 
    if (digits[0] == 0) {
        if (numDigits == 1 && digits[0] == 0) {
            return *this;
        }
        decrementHelper(0);
    }
    else {
        digits[0]--;
    }
    return *this;
}

Counter Counter::operator--(int dummy) { 
    Counter temp = *this;
    this->operator--();
    return temp;
}

void Counter::decrementHelper(int position) { 
    digits[position] = 9;
    
    if (digits[position + 1] - 1 < 0) {
        decrementHelper(position + 1);
    }
    else {
        digits[position + 1]--;
    }
    if (digits[numDigits - 1] == 0) {
        numDigits--;
    }
}

Counter& Counter::operator*=(const Counter &other) { 
    return *this = *this * other;
}

Counter Counter::operator*(const Counter &other) const { 
    Counter result = 0;
    for (int i = other.numDigits - 1; i >= 0; i--)
        result.times10() += multiply(other.digits[i]);
    return result;
}

Counter Counter::multiply(char digit) const{ 
    Counter temp;
    int carry = 0;
    temp.numDigits = numDigits;
    
    for (int i = 0; i < temp.numDigits; i++) {
        temp.digits[i] = digits[i] * digit + carry;
        if (temp.digits[i] > 9) {
            carry = temp.digits[i] / 10;
            temp.digits[i] %= 10;
        }
        else {
            carry = 0;
        }
        if (carry > 0 && i >= numDigits - 1) {
            temp.numDigits++;
        }
    }
    return temp;
}

Counter& Counter::times10() { 
    if (*this != 0) {
        for (int i = numDigits; i >= 0; i--) {
            digits[i + 1] = digits[i];
        }
        digits[0] = 0;
        numDigits++;
    }
    return *this;
}
