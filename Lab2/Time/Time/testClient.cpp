
#include <iostream>
#include "time.h"
using namespace std;

int main() {
	// 9:30 AM
	Time myTime(9, 30, 0);
	myTime.Write();
	myTime.WriteAmPm();

	// 8:00 AM and Breakfast time
	myTime.Set(8, 0, 0);
	myTime.WriteAmPm();
	myTime.Mealtime();

	// array of 10 Time objects
	Time Schedules[10];

	// sizeof is used to determine the length of the array
	// the size of the whole array divided by the size of one 
	// object in the array gives the number of objects in the array
	for (int i = 0; i < sizeof(Schedules)/sizeof(Schedules[0]); i++) {
		Schedules[i].Set(11, 0, 0);
		Schedules[i].WriteAmPm();
	}
	//Explain number of destructor calls below

	//there are 11 destructor calls because the myTime variable is destructured
	//and the schedules array of 10 time objects will all also be destructured 
	//after main is done executing

	return 0;
}