/*
Filename: info.h
Written By: Connor Bettermann
Project 3
5.20.16

This file contains all of the function prototypes for the Info class.
This class deals with all of the information of a statement to be studied.
*/
#include <cstring>
#include <iostream>


#ifndef INFO_H
#define INFO_H

using namespace std;


class Info
{
	public:
		Info();
		Info(char in_statement[], int in_importance, bool in_complete);
		Info(const Info *& to_copy);
		~Info();
		friend ostream& operator << (ostream& out, Info * i);
		Info * operator += (bool in_complete);
		Info& operator = (const Info *& to_copy);

	protected:
		char * statement; //char array holding the statement to be studied
		int importance; //Numerical valued importance of material
		bool complete; //Has the information been successfully studied?
};



#endif
