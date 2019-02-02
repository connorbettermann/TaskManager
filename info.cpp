/*
Filename: info.cpp
Written By: Connor Bettermann
Project 3
5.20.16

This file holds all of the function definitions for the info class.
This class deals with the statements to be studied and their importance.
*/
#include "info.h"


//This is the default constructor for the Info class
Info::Info()
{
	statement = NULL;
	importance = 0;
	complete = false;
}



//This constructor for the info class takes in 3 args to set all of the data memebers
Info::Info(char in_statement[], int in_importance, bool in_complete)
{
	statement = new char[strlen(in_statement) + 1];
	strcpy(statement, in_statement);
	importance = in_importance;
	complete = in_complete;

}


//This is the copy constructor for the Info class
Info::Info(const Info *& to_copy)
{
	statement = new char[strlen(to_copy->statement) + 1];
	strcpy(statement, to_copy->statement);
	importance = to_copy->importance;
	complete = to_copy->complete;

}


//This is the default destructor for the Info class
Info::~Info()
{
	delete []statement; //statement is the only dynamically allocated memeory;
}


//This is an operator overload used to change the complete member of an Info object
Info * Info::operator += (bool in_complete)
{
	complete = in_complete; //Set complete to the arg
	return this;
}


//This is an operator overload to display an Info object
ostream& operator << (ostream& out, Info * i)
{
	char * temp; 
	if(i->complete == true) //This translates the bool complete variable into Yes or No
	{
		temp = new char[4];
		strcpy(temp, "Yes");
	}
	else
	{
		temp = new char[3];
		strcpy(temp, "No");
	}

	return (cout	<< "\nStatement\n" << "---------------\n"
			<< i->statement
			<< "\nImportance: " << i->importance
			<< "\nCompleted? " << temp << endl << endl);
			

}


//This is an operator overload that invokes the copy constructor
Info& Info::operator = (const Info *& to_copy)
{
	Info * temp = new Info(to_copy);
	return *temp;

}
