#include <iostream>
using namespace std;


bool areIdenticalValues(double *ptr1,double *ptr2);
bool areIdenticalAddresses(double *ptr1, double *ptr2);
int main()
{
	double one = 12.8;
	double two = 10.9;
	double *ptr1 = &one;
	double *ptr2 = &two;
	
	//both return false
	cout << areIdenticalValues(ptr1, ptr2) << endl;
	cout << areIdenticalAddresses(ptr1, ptr2) << endl;

	//identical values
	*ptr1 = 10.9;
	cout << areIdenticalValues(ptr1, ptr2) << endl;
	cout << areIdenticalAddresses(ptr1, ptr2) << endl;

	//identical addresses, which leads to identical values
	//this causes a memory leak because now 12.8 is inaccessible
	ptr1 = ptr2;
	cout << areIdenticalValues(ptr1, ptr2) << endl;
	cout << areIdenticalAddresses(ptr1, ptr2) << endl;


	return 0;
}

bool areIdenticalValues(double *ptr1 ,double *ptr2)
{
	if (*ptr1 == *ptr2)
		return true;
	return false;
}

bool areIdenticalAddresses(double * ptr1, double * ptr2)
{
	if (ptr1 == ptr2)
		return true;
	return false;
}
