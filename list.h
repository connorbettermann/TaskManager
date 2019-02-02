/*
Filename: list.h
Written By; Connor Bettermann
Project 3
5.20.16

This file holds all of the function prototypes for the list and l_node classes.
*/
#include <cstring>
#include <iostream>
#include "tree.h"

#ifndef LIST_H
#define LIST_H

class l_node : public Tree
{
	public:
		l_node();
		l_node(char in_topic[]);
		l_node(const l_node *& to_copy);
		~l_node();
		l_node * get_next();
		int set_next(l_node * new_next);
		char * get_topic();
		int set_topic(char in_topic[]);
		int print_topic();
		bool operator == (const l_node * in_node);
		l_node& operator = (const l_node *& to_copy);
	private:
		char * topic; //char array holding the name of the topic
		class l_node * next;	//pointer pointing to the next topic

};


class List
{
	public:
		List();
		~List();
		bool is_empty();
		int insert(char in_topic[], char in_statement[], int in_importance);
		int insert_as_first(char in_topic[], char in_statement[], int in_importance);
		int print_all();
		int print_all(l_node * head);
		l_node * get_head();
		l_node * search(char in_search[]);
		l_node * search(char in_search[], l_node * head);
		friend ostream& operator << (ostream& out, List * list);

	protected:
		l_node * head; //beginning of the list
		l_node * tail; //end of the list

};



#endif
