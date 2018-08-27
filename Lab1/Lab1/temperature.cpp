#include <iostream> 
using namespace std; 

double convert(double value); 
string errorMsg = "The value you entered is not a proper Celcius temperature.";

int main() { 
	double celciusTemp; 
	cout << "Please enter a Celcius value: "; 
	cin >> celciusTemp; 
	
	if (convert(celciusTemp)) {
		cout << celciusTemp << " degress Celcius is " << convert(celciusTemp) << " degrees Farenheit.";
	}
	else {
		cout << "The value you entered is too low.";
	}
	return 0;
}

//method converts temperature in Celcius into Farenheit 
double convert(double temp) { 
	if (temp < -273.15 ) {
		return 0.0;
	}
	return 1.8 * temp + 32.0; 
}