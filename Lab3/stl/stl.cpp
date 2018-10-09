#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

void initialize(vector<int> &v);
void reverse(vector<int> &v);
void print(vector<int> v);

int main()
{
	stack<string> s1, s2;

	s1.push("Hi there");
	s2.push("Bye, there");

	if (s1 == s2)
		cout << "s1 and s2 are equal." << endl;
	else if(s1<s2)
		cout << "s1 is less than s2." << endl;
	else if (s1 > s2)
		cout << "s1 is greater than s2." << endl;

	vector<int> v;
	initialize(v);
	print(v);

	//the reverse function could have also been used here
	//the lab instructions didn't specify to use the reverse function
	//code below if reverse function was used
	//reverse(v.begin(), v.end());
	reverse(v);
	print(v);
	
	sort(v.begin(), v.end());
	print(v);

	return 0;
}

void initialize(vector<int> &v)
{
	int temp;
	for (int i = 0; i < 5; i++)
	{
		cout << "Please enter the number for position " << i << ":" << endl;
		cin >> temp;
		v.push_back(temp);
	}
		
}

void print(vector<int> v)
{
	cout << "The vector will be printed below." << endl;
	for (int i = 0; i < v.size() ; i++)
		cout << "The value at position " << i << " is " << v[i] << endl;

}

void reverse(vector<int> &v)
{
	vector<int> temp = v;
	for (int i = 0; i < v.size(); i++) 
	{
		v[i] = temp[5-i-1];
	}
	cout << "The vector has been reversed." << endl;
}