/*
Filename: tree.cpp
Written By: Connor Bettermann
Project 3
5.20.16

This file holds all of the fucntion definitions for the tree and t_node classes.
These BSTs hold all of the statements under a specific topic. The t_node class 
is derived from the Info class.
*/
#include "tree.h"


//Defualt constructor for the t_node class
t_node::t_node()
{
	right = NULL;
	left = NULL;
}

//This constructor sets all of the Info data members to the args and intiializes the pointers
t_node::t_node(char in_statement[], int in_importance, bool in_complete)
{
	right = NULL;
	left = NULL;
		

	statement = new char[strlen(in_statement) + 1];
	strcpy(statement, in_statement);
	importance = in_importance;
	complete = in_complete;
}


//This is the default destructor for the t_node class
t_node::~t_node()
{
	delete right;
	delete left;
}

//This function sets the right member to the input arg
int t_node::set_right(t_node * in_right)
{
	right = in_right;
	return 0;
}


//This function sets the left member to the input arg
int t_node::set_left(t_node * in_left)
{
	left = in_left;
	return 0;
}


//This function returns the right member
t_node * t_node::get_right()
{
	return right;
}


//This function returns the left member
t_node * t_node::get_left()
{
	return left;
}


//This function returns the importance member in Info
int t_node::get_importance()
{
	return importance;

}

//This function returns the statement member in Info
char * t_node::get_statement()
{
	return statement;
}


//This is an operator overload to check if the importance of an object is less than the arg
bool t_node::operator < (const int & in_importance)
{
	if(this->get_importance() < in_importance)
		return true;
	else
		return false;

}


//This operator overload checks to see if the importance of an object is greater than the arg
bool t_node::operator > (const int & in_importance)
{
	if(this->get_importance() > in_importance)
		return true;
	else
		return false;

}


//Default constructor for the Tree class
Tree::Tree()
{
	root = NULL;

}


//This constructor sets the root member to the input arg
Tree::Tree(t_node * new_root)
{
	root = new_root;

}


//This is the default destructor for the Tree class
Tree::~Tree()
{
	delete root;
}


//This function sets the root of the Tree to the input arg
int Tree::set_root(t_node * new_root)
{
	root = new_root;
	return 0;
}


//This function returns the root of the Tree class object
t_node * Tree::get_root()
{
	return root;
}


//This function inserts a new Info item into the Tree
int Tree::insert(char in_statement[], int in_importance, bool in_complete)
{
	if(root == NULL)
	{
		insert_as_first(in_statement, in_importance, in_complete);
	}
	else
	{
		insert(root, in_statement, in_importance, in_complete);			
	}
	return 0;
}


//This function is called by the one above to start a recursive chain
int Tree::insert(t_node * root, char in_statement[], int in_importance, bool in_complete)
{

	if(root->get_importance() > in_importance) //if importance is greater than current node
	{
		if(root->get_left() == NULL)
		{
			t_node * temp = new t_node(in_statement, in_importance, in_complete); //inserting new node
			root->set_left(temp);
			temp->set_left(NULL);
			temp->set_right(NULL);
			return 0;
		}
		else
		{
			insert(root->get_left(), in_statement, in_importance, in_complete); //recursive call
		}
	}
	else if(root->get_importance() < in_importance) //if importance is less than current node
	{
		if(root->get_right() == NULL)
		{
			t_node * temp = new t_node(in_statement, in_importance, in_complete); //inserting new node
			root->set_right(temp);
			temp->set_right(NULL);
			temp->set_left(NULL);
			return 0;
		}	
		else
		{
			insert(root->get_right(), in_statement, in_importance, in_complete); //recursive call
		}	
	}
	return 0;
}


//This function inserts a new node as the first in the Tree
int Tree::insert_as_first(char in_statement[], int in_importance, bool in_complete)
{
	t_node * temp = new t_node(in_statement, in_importance, in_complete);
	root = temp;	
	
	return 0;
}


//This function prints all of the nodes within the tree
int Tree::print_all()
{
	if(root != NULL)
	{
		print_all(root);
	}
	else
	{
		cout << "Tree is empty!\n";
	}
	return 0;

}


//This function is called by the one above to start a recursive chain
int Tree::print_all(t_node * root)
{
	if(root != NULL)
	{
		print_all(root->get_left());
		print_all(root->get_right());
		cout << root;
	}
	return 0;

}


//This function is used to search a tree for the input arg statement and return a pointer  to it
t_node * Tree::search(char in_statement[])
{
	if(root != NULL)
	{
		return search(in_statement, root);
	}
	return NULL;

}


//This function is called by the one above to start a recursive chain
t_node * Tree::search(char in_statement[], t_node * root)
{
	if(root != NULL)
	{
		search(in_statement, root->get_left());
		search(in_statement, root->get_right());
		if(strcmp(in_statement, root->get_statement()) == 0)
		{
			return root;
		}
	}
	return NULL;

}
