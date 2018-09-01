/* 
Name: Dharmesh Patel
Date 2018.08.29
Assignment: Lab 1 - Problem 1
Description: This program asks the user for a temperature in degrees Celsius 
			 and returns the value in degrees Fahrenheit
*/

#include <iostream> 
using namespace std; 


double convert(double value); 

int main() { 
	double celsiusTemp; 

	//Asks for user input
	cout << "Please enter a Celsius value: "; 
	cin >> celsiusTemp; 
	
	//checks if user input is valid Celsius temperature
	if (convert(celsiusTemp)) {
		//If user input is valid, output Fahrenheit temperature
		cout << celsiusTemp << " degrees Celsius is " << convert(celsiusTemp) << " degrees Fahrenheit." << endl;
		//below line prevents console from closing automatically after successfully executing the program
		system("PAUSE");
	}
	else {
		//If user input is not valid, tell user the error and prompt for Celsius value again
		cout << "The value you entered is too low to be a Celsius temperature value." << endl;
		cout << "Please enter a Celsius value: ";
		cin >> celsiusTemp;
	}
	return 0;
}

//method converts temperature in Celsius into Fahrenheit 
double convert(double temp) { 
	if (temp < -273.15 ) {
		return 0.0;
	}
	return 1.8 * temp + 32.0; 
}