//
// lab6Part2.cpp
//
// Mahdi Khaliki
// 9/26/16
// Lab 6 Part 2
// Prints the numbers between 2 user entered numbers
//

#include <iostream>
using namespace std;

int main()
{
	// Declare varibles
	int entry, entry2;
	
	// Get input from user
	cout << "Enter a number: " << flush;
	cin >> entry;
	cout << "Enter another number: " << flush;
	cin >> entry2;
	
	// Test for output
	if (entry > entry2)
	{
		while (entry >= entry2)
		{
			cout << entry << " " << flush;
			entry--;
		}
	}
	else
	{
		while (entry <= entry2)
		{
			cout << entry << " " << flush;
			entry++;
		}
	}
	return 0;
}