#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "converterClass.h"
#include <fstream>
#include <iostream>


int main()
{
	converterClass conv;
	ifstream inFile{ "inFix_Expressions.txt" };
	string line;

	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			conv.stackInfix(line);
			string output = conv.getPosfixExpression();
			//
			cout << output << endl;
		}
	}
	else
	{
		cout << "File error." << endl;
	}
}
