#pragma once

#ifndef H_converterClass
#define H_converterClass
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

/*
* Precondition – An infix expression is provided; the infix expression is assumed to be well-formed
* Postcondition – the infix expression has been converted to a postfix expression and stored in the instance variable
*/


class converterClass
{
public:
	string pfExpression = "";  //String object to hold the postfix expression

	//converterClass(string inExpression) {}

	int precedence(char o)  //Member function to return precedence int
	{
		if ((o == '-' ) || (o == '+')) return 1;
		if ((o == '/') || (o == '*')) return 2;
		return 0;
	}

	void stackInfix(string inExpression)
	{
		stack<char> Stack;  //Local stack within the converter member function
		pfExpression = "";
		char* expression = new char[inExpression.length() + 1];
		strcpy(expression, inExpression.c_str());
		string currentToken;
		string op;
		char c;

		cout << endl << "Infix Expression: " << inExpression << ";" << endl; //Print the inFix expression

		for (int i = 0; i < inExpression.length()+1; i++)  //For each character in the input string
		{
			c = expression[i];
			if (isalpha(c))  //If the character is an alpha character
			{
				pfExpression += c;  //Append the character to the postfix string
				//cout << "Postfix expression: " << pfExpression << endl;
			}
			else if (c == '(')  //Else if the character is a ‘(‘
			{
				Stack.push(c);  //Push the character onto the stack
			}
			else if (c == ')')  //Else if the character is ‘)’
			{
				if (!Stack.empty())  // If the stack is not empty
				{
					while (Stack.top() != '(') //While the top of the stack is not a ‘(’
					{
						//Pop the operator and append it to the postfix string
						pfExpression += Stack.top();  
						Stack.pop();
					}
				}
				Stack.pop(); //Pop the ‘(‘
			}
			else if (c == ' ')  //Else if the character is a ‘ ’
			{
				continue;  //continue to the next character
			}
			else if (c == '+' || c == '-' || c == '*' || c == '/')  //Else (with some conditions)
			{
				while ((!Stack.empty()) && (precedence(c) <= precedence(Stack.top())))  //while (the stack is not empty and 
					//string operator precedence <= stack operator precedence
				{
					//Pop and append the stack operator to the postfix string
					pfExpression += Stack.top();
					Stack.pop();
				}
				Stack.push(c);  //Push the string operator onto the stack
			}
			else continue;  //Ignore any other character. Shouldn't ever get to this.
		}
		while (!Stack.empty())  //while the stack is not empty
		{
			//pop and append remaining operators to the postfix string
			pfExpression += Stack.top();
			Stack.pop();
		}
		cout << "Postfix Expression: " << pfExpression << endl; //Print the postFix expression
	}
	
	const string getPosfixExpression()
	{
		//stackInfix(inExpression);
		return pfExpression;
	};
private:
};




#endif

