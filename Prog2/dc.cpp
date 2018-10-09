#include <iostream>
#include "stack.h"
#include "dsexceptions.h"
#include <typeinfo>
#include <cstdlib>

using namespace std;

int main(){
  string input;
  Stack<int> s(10);

  do
  {
    string temp;
    getline(cin, input);
    
    if(input.length() ==0)
      break;
    
    int i = 0;
    while(i <input.length())
    {
      //if statement handles numeric values in input
      //else statement handles all other values
      if(isdigit(input[i]) || input[i]=='_')
      {
        // do-while loop extracts positive and negative numbers
	// of any length from input
	do
	{
	  temp+=input[i];
	  i++;
	}
	while(isdigit(input[i]));

	//change underscore to - for int conversion
	temp[0] == '_' ? temp[0] = '-' :temp[0];
	try
	{
	  s.push(atoi(temp.c_str()));
	}
	catch(Overflow e)
	{
	  cout << "Exception -- The Stack Is Full!" << endl;
	}
	temp = "";
      }//end of if starement to handle numbers
      else
      {
	//switch statement executes statement
	//based on character or operation entered
	switch(input[i])
	{
	  case 'p':
	    try
	    {
	      cout << s.top() <<endl;
	    }
	    catch(Underflow e)
	    {
	      cout << "Exception -- You Cannot Pop an Empty Stack!" << endl;
	    }
	    break; //end of p case

	  case 'n':
	    try
	    {
	      cout << s.topAndPop() << " ";
	    }
	    //catch handles Underflow exception	    
	    catch(Underflow e)
	    {
	      cout << "Exception -- You Cannot Pop an Empty Stack!" << endl;
	    }	    
	    break; //end of n case

	  case 'f':
	  { 
	    Stack<int> tempStack  = s;
	    while(!tempStack.isEmpty())
	      cout << tempStack.topAndPop() <<endl;
            break;
	  } //end of f case

	  case 'c':
	    s.makeEmpty();
	    break; //end of c case

	  case 'd':
	    try
	    {
	      s.push(s.top());
	    }
            //catch handles Overflow exception
	    catch(Overflow e)
	    {
	      cout <<"Expception -- The Stack Is Full!" << endl;
	    }
	    //catch handles Underflow exception	    
	    catch(Underflow e)
	    {
	      cout << "Exception -- You Cannot Pop an Empty Stack!" << endl;
	    }	    
	    break; //End of d case

	  case 'r':
	    try
	    {
	      int temp1 = s.topAndPop();
	      int temp2 = s.topAndPop();
	      s.push(temp1);
	      s.push(temp2);
	    }
	    //catch handles Underflow exception	    
	    catch(Underflow e)
	    {
	      cout << "Exception -- You Cannot Pop an Empty Stack!" << endl;
	    }
	    break; //end of r case
	    
	  case '+':
	    try
	    {
	      s.push(s.topAndPop() + s.topAndPop());
	    }
	    //catch handles Underflow exception	    
	    catch(Underflow e)
	    {
	      cout << "Exception -- You Cannot Pop an Empty Stack!" << endl;
	    }	    
	    break; //end of + case

	  case '-':
	    try
	    {
	      int temp1 = s.topAndPop();
	      int temp2 = s.topAndPop();
	      s.push(temp2-temp1);
	    } 
            //catch handles Underflow exception	    
	    catch(Underflow e)
	    {
	      cout << "Exception -- You Cannot Pop an Empty Stack!" << endl;
	    }
	    break; //end of - case
	    
	  case '*':
	    try
	    {
	      s.push(s.topAndPop() * s.topAndPop());
	    }
	    //catch handles Underflow exception	    
	    catch(Underflow e)
	    {
	      cout << "Exception -- You Cannot Pop an Empty Stack!" << endl;
	    }	    
	    break; //end of * case
		
	  case '/':
	    try
	    {
	      int temp1 = s.topAndPop();
	      int temp2 = s.topAndPop();
  	      if(temp1 == 0)
		throw DivisionByZero();
	      s.push(temp2/temp1);
	    }
	    //catch handles Underflow exception	    
	    catch(Underflow e)
	    {
	      cout << "Exception -- You Cannot Pop an Empty Stack!" << endl;
	    }
	    //catch handles DivisionByZero exception	    
	    catch(DivisionByZero e)
	    {
	      cout << "Exception -- You Cannot Divide by 0!" << endl;
	    }	
	    break; //end of / case
	    
	  case '%':
	  {
	    try
	    {
	      int temp1 = s.topAndPop();
	      int temp2 = s.topAndPop();
	      if(temp1 == 0)
		throw DivisionByZero();
	      while(temp2>temp1)
	        temp2-=temp1;
	      s.push(temp2);
	    }
	    //catch handles Underflow exception	    
	    catch(Underflow e)
	    {
	      cout << "Exception -- You Cannot Pop an Empty Stack!" << endl;
	    }	    
	    //catch handles DivisionByZero exception	    
	    catch(DivisionByZero e)
	    {
	      cout << "Exception -- You Cannot Divide by 0!" << endl;
	    }
	    break; //end of % case
	  }

	  //below case handles space in input if user enters any
	  //does nothing if space is found
	  //case is needed so default case does not run for spaces
	  case ' ':
	    break; //end of space case

	  default:
	    cout << input[i] << " is not a valid operation. Please try again!" << endl; 
	}//end of switch case 
	i++;
      }//end of else statement
    }
  }
  //if cin reaches end of file
  //exit do-while and end program
  while (!cin.eof());
  return 0;
}
	
