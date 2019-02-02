/*
Filename: list.cpp
Written By: Connor Bettermann
Project 3
5.20.16

This file holds all of the function definitions for the List class.
This class deals with the Linear linked list used by the study guide class.
This list deals with l_nodes that each derive from a BST object. Each l_node
also has a topic that represents a group of material. 
*/
#include "list.h"


//Default constructor for the l_node class
l_node::l_node()
{
	next = NULL;
	topic = NULL;
}


//This constructor sets topic to the arg
l_node::l_node(char in_topic[])
{
	next = NULL;
	topic = new char[strlen(in_topic) + 1];
	strcpy(topic, in_topic);

}


//This is the copy constructor for the l_node class
l_node::l_node(const l_node *& to_copy)
{
	next = to_copy->next;
	topic = new char[strlen(to_copy->topic) + 1];
	strcpy(topic, to_copy->topic);

}


//This is the default destructor for the l_node class
l_node::~l_node()
{
	delete []topic;
}


//This function returns an l_node pointer for the next variable
l_node * l_node::get_next()
{
	return next;
}


//This function sets the next variable to the input arg
int l_node::set_next(l_node * new_next)
{
	next = new_next;
	return 0;

}


//This function returns the topic variable
char * l_node::get_topic()
{
	return topic;
}


//This function sets the topic variable to the input arg
int l_node::set_topic(char in_topic[])
{
	topic = new char[strlen(in_topic) + 1];
	strcpy(topic, in_topic);
	return 0;
}


//This function prints out the information held in a topic including the BST
int l_node::print_topic()
{
	cout << "\nTopic: " << topic << endl;
	cout << "--------Material-------\n";
	print_all();	
	
	return 0;

}



//This is an operator overload that checks to see of the topic is the same as the input
bool l_node::operator == (const l_node * in_node)
{
	if(strcmp(in_node->topic, topic) == 0)
		return true;
	else
		return false;

}


//This is an operator overload that utilizes the copy constructor for the l_node class
l_node& l_node::operator = (const l_node *& to_copy)
{
	l_node * temp = new l_node(to_copy);
	return *temp;
}


//Default constructor for the List class
List::List()
{
	head = NULL;
	tail = NULL;
}


//Default destructor for the List class
List::~List()
{
	
}


//This function checks to the see if the List is empty
bool List::is_empty()
{
	if(head == NULL)
		return true;
	else
		return false;

}


//This function inserts a new node into a the list and Info into the BST in the node
int List::insert(char in_topic[], char in_statement[], int in_importance)
{
	if(is_empty() == true)
	{
		insert_as_first(in_topic, in_statement, in_importance);
		return 0;
	}
	else
	{
		l_node * temp = new l_node(in_topic);
		tail->set_next(temp);
		tail = temp;
		temp->insert(in_statement, in_importance, false);
		return 0;
	}
	return 0;

}


//This function inserts a node as the first in a list and inserts a new Info into the BST
int List::insert_as_first(char in_topic[], char in_statement[], int in_importance)
{
	l_node * temp = new l_node(in_topic);
	head = temp;
	tail = temp;
	temp->insert(in_statement, in_importance, false);
	return 0;

}


//This functions returns the head variable in a list
l_node * List::get_head()
{
	return head;

}


//This function prints all of the elements in the list as well as their BSTs
int List::print_all()
{
	if(head == NULL)
	{
		cout << "List is empty!\n";
		return 0;
	}
	print_all(head);
	return 0;
}


//This function is called by the previous function to start a recursive chain
int List::print_all(l_node * head)
{
	if(head == NULL)
		return 0;
	else
	{
		head->print_topic();
		return print_all(head->get_next());
	}
	return 0;

}


//This is an operator overload to envoke displaying all of the information
ostream& operator << (ostream& out, List * list)
{
	if(list->get_head() == NULL)
	{
		return cout << "List is empty\n";
	}
	else
	{
		return cout << list->print_all(list->get_head());
	}

}


//This function searchs the list for a matching topic based on arg
l_node * List::search(char in_search[])
{
	if(head == NULL)
		return 0;
	else
	{
		return search(in_search, head);
	}	
	return 0;

}


//This function is called by the previous to start a recursive chain
l_node * List::search(char in_search[], l_node * head)
{
	if(head == NULL)
		return 0;
	else if(strcmp(in_search, head->get_topic()) == 0)
	{
		return head;
	}
	else
		return search(in_search, head->get_next());

}
