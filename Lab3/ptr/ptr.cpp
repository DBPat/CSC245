#include "pch.h"
#include <iostream>
using namespace std;

struct RecType
{
	int age;
	float weight;
	char gender;
};


int main()
{
	int var = 5;
	int *intPtr = NULL;
	//intPtr = &var;
	cout << *intPtr * 10 << endl;

	RecType *recPtr = new RecType;
	recPtr->age = 25;
	recPtr->weight = 190;
	recPtr->gender = 'M';
	(*recPtr).age += 5;
	cout << (*recPtr).age << " " << (*recPtr).weight << " " << (*recPtr).gender << endl;
	delete recPtr;
	recPtr = NULL;

	char *strPtr = new char[50];
	//strcpy was not used because it is deemed unsafe and produced compile errors
	//strcpy_s is the function to use here according to c++ documentation on the microsoft website
	//note: i am using visual studio as my ide
	strcpy_s(strPtr, 18,"Operating Systems");
	cout << strPtr << endl;
	int lower = 0;
	for (int i = 0; i < strlen(strPtr); i++)
	{
		if (islower(*(strPtr + i)))
			lower++;
	}
	cout << lower << endl;
	strPtr += 10;
	cout << strPtr << endl;
	strPtr -= 10;
	delete strPtr;
	strPtr = NULL;

	return 0;
}
