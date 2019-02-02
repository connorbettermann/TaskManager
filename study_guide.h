/*
Filename: study_guide.h
Written By: Connor Bettermann
Project 3
5.20.16

This file holds all fo the function prototypes for the study_guide class.
This study_guide class is derived from the List class.
*/

#include "list.h"

#ifndef STUDY_GUIDE_H
#define STUDY_GUIDE_H

class study_guide : public List
{
	public:
		study_guide();
		~study_guide();
		friend ostream& operator << (ostream& out, study_guide * guide);
	private:
};



#endif
