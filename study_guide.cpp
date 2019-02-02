/*
Filename: study_guide.cpp
Written By: Connor Bettermann
Project 3
5.20.16

This file holds all of function definitions for the study_guide class.
The study guide class represents what the user will be accessing. This
class inherits the List class that deals with all of the data structures.
Ideally, this class will be filled out more with functions used directly by the user,
but for the most part, all we are doing is accessing the data which is done
by the data structur itself.
*/
#include "study_guide.h"


//Default Constructor for study_guide class
study_guide::study_guide()
{


}


//Default Destructor for study_guide class
study_guide::~study_guide()
{



}


//Operator overload to display the entire study guide
ostream& operator << (ostream& out, study_guide * guide)
{
	return cout << guide->print_all();
}

