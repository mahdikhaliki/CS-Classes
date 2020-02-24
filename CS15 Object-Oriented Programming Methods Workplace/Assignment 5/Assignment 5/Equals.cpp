#include "Equals.hpp"
#include <cmath>

bool Equals(double x, double y) { // Returns true if 2 values are close enough
    return fabs(x - y) < pow(10, -10) ? true : false;
}

bool LoE(double x, double y) { // Compares 2 values less than or equal to
    return x < y || Equals(x, y) ? true : false;
}

bool GoE(double x, double y) { // Compares 2 values greater than or equal to
    return x > y || Equals(x, y) ? true : false;
}
