//
// lab8.cpp
//
// Mahdi Khaliki and Brian Deitchman
// Lab8
// Writing functions to get length and width, and calculating area and parimeter.
//

#include <iostream>
using namespace std;

double GetLength(void);
double GetWidth(void);
double Area(double, double);
double Perimeter(double, double);
void PrintStats(double, double);

int main()
{
    double length = GetLength();
    double width = GetWidth();
    double area = Area(length, width);
    double perimeter = Perimeter(length, width);
    PrintStats(area, perimeter);
    return 0;
}

double GetLength(void)
{
    double l;
    do
    {
        cout << "Enter length: " << flush;
        cin >> l;
    } while (l < 1);
    return l;
}

double GetWidth(void)
{
    double w;
    do
    {
        cout << "Enter width: " << flush;
        cin >> w;
    } while (w < 1);
    return w;
}

double Area(double length, double width)
{
    double a;
    a = length * width;
    return a;
}

double Perimeter(double length, double width)
{
    double p;
    p = (length * 2) + (width * 2);
    return p;
}

void PrintStats(double area, double perimeter)
{
    cout << "Area: " << area << " units squared" << endl;
    cout << "Perimeter: " << perimeter << " units" << endl;

}
