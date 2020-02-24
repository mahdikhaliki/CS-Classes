//
// lab6Part1.cpp
//
// Mahdi Khaliki
// 9/26/16
// Lab 6 Part 1
// Gets entries from a user and gives a count and sum of entries.
//

#include <iostream>
using namespace std;

int main()
{
	//Decare variables
	int entry, sum, count;
	float average;
	sum = count = 0;
	
	// Get initial entry
	cout << "Enter a number: " << flush;
	cin >> entry;
	
	// Get additional entries
	while (entry > 0)
	{
		++count;
		sum = sum + entry;
		cout << "Enter another number: " << flush;
		cin >> entry;
	}
	
	// Calculate average
	average = static_cast<float>(sum) / static_cast<float>(count);
	
	// Output sum and count
	cout << "sum: " << sum << endl;
	cout << "count: " << count << endl;
	cout << "average: " << average << endl;
	return 0;
}