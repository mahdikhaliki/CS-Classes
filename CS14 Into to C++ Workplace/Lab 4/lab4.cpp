//
// lab4.cpp
//
// Mahdi Khaliki and JiaJie Yin
// 9/12/16
// Lab 4
// Converts seconds to minutes and hours.
//

#include <iostream>
using namespace std;

int main()
{
	int seconds, minutes, newSeconds, hours, modHours, newMinutes;
	
	cout << "Enter time in seconds: " << flush;
	cin >> seconds;
	cout << "That is " << seconds << " seconds" << endl;
	
	if (seconds >= 60)
	{
		minutes = seconds / 60;
		newSeconds = seconds % 60;

		cout << "That is " << minutes << " minutes and " 
		<< newSeconds << " seconds " << endl;
	}
	
	if (seconds >=3600)
	{
		hours = seconds / 3600;
		modHours = seconds % 3600;
		newMinutes = modHours / 60;
		
		cout << "That is " << hours << " hours " << newMinutes 
		<< " minutes and " << newSeconds << " seconds " << endl;
	}
}