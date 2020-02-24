//
// lab5methods.cpp
//
// 3/8/17
// Mahdi Khaliki, Maxwell McAllister
// CSCI 15 Lab 5
// Definitions for methods in class Date
//

#include <iostream>
#include "Lab5Date.h"
using namespace std;
// iostream is needed for the ostream type

// Parameterized macro "function"
// decides whether argument is a leap year, returns a bool
#define IS_LEAP(Y) (((Y)%4 == 0 && (Y)%100 != 0)||((Y)%400 == 0))

Date::Date(void)
{
    year = month = day = 1;
}

Date::Date(int y, int m, int d)
{
    SetAll(y, m, d);
}

void Date::SetAll(int y, int m, int d)
{
    int days[12] =  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool yValid = (y >= 1);
    bool mValid = (m >= 1) && (m <= 12);
    bool dValid = false;
    // dValid assumed false because we can only check day if month is valid
    if(mValid)
    {
        if(m == 2)
        {
            if( IS_LEAP(y) )
            {
                // It is a leap year, so 29 days in Feb
                dValid = ((d <= 29) && (d >= 1));
            }
            else
            {
                // Not a leap year, so 28 days in Feb
                dValid = ((d <= 28) && (d >= 1));
            }
        }
        else
        {
            // Not February (m != 2)
            // Subtract (1): Jan is m == 1, but it is in days[0]
            dValid = ((d <= days[m-1]) && (d >= 1));
        }
        // We still need to check whether d is non-negative
        // D is valid iff (d <= (days in month)) && (d >= 1)
        dValid = (dValid && (d >= 1)); // Dependent on result found above
    }
    
    if (yValid && mValid && dValid)
    {
        // y, m, d all legal; Assign the client's values for each field
        year = y;
        month = m;
        day = d;
    }
    else    // At least one (of y, m, d) is illegal
    {
        // Assign default date
        year = month = day = 1;
    }
    return;
}

//  Getter methods return the value of a given field
// from the Date object on which they are called
int Date::GetYear()
{
    return year;
}

int Date::GetMonth()
{
    return month;
}

int Date::GetDay()
{
    return day;
}

// Methods to print contents of Date on which they are called
// Print1() uses format "12/25/09"
void Date::Print1( ostream &out )
{
    // Calculate the value of the two lowest-value decimal places in year
    int yTemp = year % 100;
    // Print the date to the ostream ref. parameter
    // The year needs a leading zero "0" iff yTemp is one-digit
    out << month << '/' << day << '/' << ( (yTemp < 10)?("0"):("") )
    << yTemp << flush;
    return;
}

// Print2() uses format "December 25, 2009"
void Date::Print2( ostream &out )
{
    // Static 2-d array to contain month Names
    static char mN[12][10] = { {"January"}, {"February"}, {"March"},
        {"April"}, {"May"}, {"June"}, {"July"},
        {"August"}, {"September"}, {"October"},
        {"November"}, {"December"} };
    // Print the date to the ostream
    out << mN[ (month - 1) ] << ' ' << day << ", " << year << flush;
    return;
}

// Print3() uses format "25 December 2009"
void Date::Print3( ostream &out )
{
    // Same Static 2-d array as in Print2
    static char mN[12][10] = { {"January"}, {"February"}, {"March"},
        {"April"}, {"May"}, {"June"}, {"July"},
        {"August"}, {"September"}, {"October"},
        {"November"}, {"December"} };
    // Print the date to the ostream
    out << day << ' ' << mN[ (month - 1) ] << ' ' << year << flush;
    return;
}

// Difference() returns the number of days from the Date on which it's called
// to the Date parameter (returns positive if parameter is the later date)
int Date::Difference( Date &dPr )
{
    // Table for # of days in months (0th element is for January)
    static int days[12] =  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // diff holds the difference (in days), initially assume 0
    // dInMo holds days in a particular month
    //  w "Work variables" to represent our mobile day
    // during decision-making
    int diff = 0, dInMo, wYear, wMonth, wDay;
    // Flags
    // rev being true indicates that the parameter is before "this"
    // tb is for breaking up a complicated logical expression
    bool rev = false, tb;
    // tD is a Date* to keep track of target date (the later date)
    Date *tD;
    
    // Decide which Date is earlier
    // Tiebreaker for when years are the same
    tb = (dPr.month < month) || ((dPr.month == month) && (dPr.day < day ));
    if( (dPr.year < year ) || ((dPr.year == year) && tb) )
    {
        // parameter date dPr is the earlier one
        // Start at dPr (work variables get dPr's values)
        wYear = dPr.year;
        wMonth = dPr.month;
        wDay = dPr.day;
        // Target date is "this"
        tD = this;
        // Negate result, since progress from "this" to dPr would be reverse
        rev = true;
    }
    else
    {
        // dPr date is NOT earlier ("this" is earlier or the same)
        // start at "this"
        wYear = year;
        wMonth = month;
        wDay = day;
        // Target date is dPr
        tD = &dPr;
        // Don't negate return value
        rev = false;
    }
    // Calculate the difference
    // ******
    // Always account for "moves" by adding to diff
    //  If same year and different months, or different years (and months
    // irrelevant), need to "move to" 1st of next month
    if( (wYear != tD->year) || (wMonth != tD->month) )
    {
        // Get days in current "working month", check leap year
        if( wMonth == 2 ) // February
        {
            // Decide whether working year is a leap year
            dInMo = ( IS_LEAP(wYear) )?(29):(28);
        }
        else // Not February
        {
            dInMo = days[ (wMonth - 1) ];
        }
        // Add days to move to end of month
        diff += (dInMo + 1 - wDay);
        // change wDay and wMonth to reflect this change
        wMonth++;
        // If exiting December (mo. 12), wYear becomes 13 (illegal)
        if( wMonth > 12 )
        {
            // "Wrap" to January of the next year
            wYear++;
            wMonth = 1;
        }
        wDay = 1;
    }
    cout << diff << endl;
    // If the years are not the same, need to get to end of working year
    // and then get to target year. Does nothing if years already same!
    if( wYear != tD->year )
    {
        // Not at target year yet
        // Move to Jan 1st of year after wYear (if needed)
        while( wMonth != 1 )
        {
            // Move to next month (add all days in current month)
            // First, get the num of days in current
            if( wMonth == 2 ) // February
            {
                dInMo = ( IS_LEAP(wYear) )?(29):(28);
            }
            else // Not February
            {
                dInMo = days[ (wMonth - 1) ];
            }
            // Now move to 1st of next month
            diff += dInMo;
            // Month accounting
            wMonth++;
            if( wMonth > 12 )
            {
                wYear++;
                wMonth = 1;
            }
        }
        // Now, loop through years adding all of the days in them
        // Going from Jan 1 of one year to Jan 1 of next year
        while( wYear < tD->year )
        {
            // The current year (wYear) that is being moved-over
            // determines # of days to add, from leap/normal
            diff += ( IS_LEAP(wYear) )?(366):(365);
            wYear++; // Move to next year
        }
    }
    // Loop to move to target month (Does nothing if already there!)
    while( wMonth < tD->month )
    {
        // move to 1st of next month; Days to add depends on current wMonth
        if( wMonth == 2 ) // February
        {
            dInMo = ( IS_LEAP(wYear) )?(29):(28);
        }
        else // Not February
        {
            dInMo = days[ (wMonth - 1) ];
        }
        diff += dInMo; // Add days in the origin month
        wMonth++; // Move to next month
    }
    // Add days to get to target date
    cout << diff << endl;
    diff += ((tD->day) - wDay);
    cout << diff << endl;
    // Return difference, but negate if dPr is earlier than "this"
    return (rev)?(-diff):(diff);
}
