#include <iostream>
#include "linelist.h"
#include <fstream>
#include<string>
#include <cstdlib>
# include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc == 1)
		exit(1);
	else if (argc == 2) {
		//create LineList list, empty for now
		LineList list;

		// open file and build list based off strings in file
		ifstream file(argv[1]);
		string line;

		// loop through file and insert every line into LineList list
		while (file) {
			getline(file, line);
			list.insertLine(line);
			if (file.eof()) break;
		}


		//go into while loop that will exit when users enters "E"
		list.printList();
		char input = 'h';
		while (input != 'E')
		{
			cout << list.getCurrLineNum() << "> ";
			cin >> input;

			switch (input)
			{
				//if user enters I, prompt for string and insert into linelist
			case 'I':
				cout << (list.getCurrLineNum()) +1<< "> ";
				cin.ignore();
				getline(cin, line);
				list.insertLine(line);
				break;

			case 'D':
				list.deleteLine();
				break;

				//if user enters P, current line goes back 1
			case 'P':
				list.movePrevLine();
				break;

				//if user enters L, list all lines in file 
			case 'L':
				list.printList();
				break;

				//if user enters N, move to next line
			case 'N':
				list.moveNextLine();
				break;
			}
		}

		//Resets file to original 
		ofstream myfile;
		myfile.open(argv[1]);
		list.goToTop();
		for (int i = list.getCurrLineNum(); i <= list.getLength();i++) {
			list.moveNextLine();
			myfile << list.getCurrLine() << endl;
		}

		myfile.close();
	}
	
}
