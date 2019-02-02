/*
Filename: tree.h
Written By: Connor Bettermann
Project 3
5.20.16

This file holds all of the function prototypes for the t_node and tree classes.
The t_node class is derived from the Info class.
*/
#include "info.h"

#ifndef TREE_H
#define TREE_H

using namespace std;


class t_node : public Info
{
	public:
		t_node();
		t_node(char in_statement[], int in_importance, bool in_complete);
		~t_node();
		int set_right(t_node * in_right);
		int set_left(t_node * in_left);
		t_node * get_right();
		t_node * get_left();
		int get_importance();
		char * get_statement();	

		bool operator < (const int & in_importance);
		bool operator > (const int & in_importance);
	private:
		class t_node * right; //children in the tree
		class t_node * left;

};


class Tree
{
	public:
		Tree();
		Tree(t_node * new_root);
		~Tree();
		int set_root(t_node * new_root);
		t_node * get_root();
		int insert(char in_statement[], int in_importance, bool in_complete);
		int insert(t_node * root, char in_statement[], int in_importance, bool in_complete);
		int insert_as_first(char in_statement[], int in_importance, bool in_complete);
		int print_all();
		int print_all(t_node * root);
		t_node * search(char in_statement[]);
		t_node * search(char in_statement[], t_node * root);
		

	protected:
		t_node * root; //root of the tree
};




#endif
