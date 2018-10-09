#include <iostream>
#include "linelist.h"
using namespace std;

LineList::LineList()
{
	LineNode *line = new LineNode;
	LineNode *line2 = new LineNode;

	line->info = topMessage;
	currLine = line;
	currLineNum = 0;
	length = 0;
	line2->info = bottomMessage;
	currLine->back = NULL;
	currLine->next = line2;
	line2->back = line;
	line2->next = NULL;
}

void LineList::goToTop()
{
	currLineNum = 1;
	// Post : Advances currLine to line 1
	while (currLine->back != NULL) {
		currLine = currLine->back;
	}
}

void LineList::goToBottom()
{
	// Post : Advances currLine to last line
	currLineNum = length;
	while (currLine->next != NULL)
		currLine = currLine->next;
}

void LineList::insertLine(string newLine)
{
	// post : newLine has been inserted after the current line
	LineNode *temp = new LineNode;
	temp->info = newLine;
	temp->back = currLine;
	temp->next = currLine->next;

	currLine->next->back = temp;
	currLine->next = temp;
	currLine = temp;

	currLineNum++;
	length++;;
}

void LineList::deleteLine()
{
	// post : deletes the current line leaving currentLine
	//	  pointing to line following
	if (currLine->info != bottomMessage && length >0) {
		if (currLineNum >1) {
			LineNode *temp = new LineNode;
			temp = currLine;
			currLine->next->back = temp->back;
			currLine->back->next = temp->next;
			currLine = temp->back;

			currLineNum--;
			length--;
		}
		else if (currLineNum ==1) {
			
			currLine = currLine->next;
			LineNode *temp = new LineNode;
			temp = currLine;
			currLine->next->back = temp->back;
			currLine->back->next = temp->next;
			currLine = temp->back;

			length == 1 ? currLineNum :  currLineNum--;
			length--;
		}
	}

}

void LineList::printList()
{
	int tempLine = currLineNum;
	LineNode *temp = new LineNode;
	temp = currLine;
	goToTop();
	for (currLineNum; currLineNum <=length; currLineNum++)
	{
		cout << currLineNum << "> " << currLine->next->info << endl;
		currLine = currLine->next;
	}
	currLine = temp;
	currLineNum = tempLine;
}

string LineList::getCurrLine() const
{
	return currLine->info;
}

void LineList::moveNextLine()
{
	// Post : Advances currLine (unless already at last line)
	if (currLine->next->info != bottomMessage && currLineNum !=length)
	{
		currLine = currLine->next;
		currLineNum++;
	}
	
}

void LineList::movePrevLine()
{
	// Post : Advances currLine (unless already at last line)
	if (currLine->back->info != topMessage && currLineNum >0 && length >0)
	{
		currLine = currLine->back;
		currLineNum--;
	}
}

int LineList::getCurrLineNum() const
{
	return currLineNum;
}

int LineList::getLength() const
{
	return length;
}