/*
Filename: user_func.cpp
Written By: Connor Bettermann
Project 3
5.20.16

This file represents the function definitions for a possible client program.
This is used as a way of testing the functionality of the data structures.
*/
#include "user_func.h"

int menu()
{
	char selection;
	int MAX = 50;
	study_guide * guide = new study_guide(); //creating a study guide to access

	cout << "\n---------------Welcome to THE STUDY GUIDE v1.0---------------\n";
	
	while(selection != 'q')
	{
		cout 	<< "\n\n1. Add new study material\n"
			<< "2. Display Study Guide\n"
			<< "3. Study Statement\n"
			<< "q. Quit\n"
			<< "Selection: ";
		cin >> selection;
		switch(selection)
		{
		case '1':
		{
			cin.ignore();
			cout 	<< "\n1. Enter new topic"
				<< "\n2. Add to exsisting topic"
				<< "\nSelection: ";
			cin >> selection;
			if(selection == '1') //Adding a new topic to the list as well as a new statement
			{
				add_topic(guide, MAX);
				break;	
			}
			else if(selection == '2') //adding a statement to an exsisting topic
			{
				char search[MAX];
				cout << "\nWhat topic would you like to add to?: ";
				cin.ignore();
				cin.get(search, MAX, '\n');
				l_node * temp = guide->search(search); //search list for a matching topic
				if(temp == NULL)
				{
					cout << "No topic found!\n";
					break;
				}
				else
				{
					new_statement(temp, MAX);
					break;		
				}	
				
			}
			else
			{
				cout << "\nInvalid entry\n"; cin.ignore();
				break;
			}
			//new_statement(tree, MAX);
			break;
		}
		case '2':
		{
			cout << guide; //display the entire guide
			break;
		}
		case '3':
		{
			char search_topic[MAX];
			char search_statement[MAX];
			cout << "\nWhat topic would you like to search?: ";
			cin.ignore();
			cin.get(search_topic, MAX, '\n');
			l_node * temp = guide->search(search_topic); //search for a matching topic
			if(temp == NULL)
			{
				cout << "No topic found\n";
				break;
			}	
			else
			{
				temp->print_topic();
				cout << "Enter statement to study: ";
				cin.ignore();
				cin.get(search_statement, MAX, '\n');
				t_node * match = temp->search(search_statement); //search for a matching statement
				if(match == NULL)
				{
					cout << "No statement match found!\n";
					break;
				}
				else
				{
					match += true; //set the complete value to true
					break;
				}
			}
		}
		case 'q':
		{
			break;
		}
		default:
		{
			cout << "Invalid option selected\n";
			break;
		}

		};
	}	

	return 0;
}


//This function reads in information from the user to add a statement to a tree
int new_statement(Tree * tree, int MAX)
{
	char statement[MAX];
	int importance;

	cout << "Enter the statement to be studied: " << endl;
	cin.ignore();
	cin.get(statement, MAX, '\n'); cin.ignore(MAX, '\n');
	cout << "Enter importance of information (1 - 10): ";
	cin >> importance;

	
	tree->insert(statement, importance, false);
	return 0;

}


//This function reads in from the user to add a new topic to the list
int add_topic(study_guide * guide, int MAX)
{
	char topic[MAX];
	char statement[MAX];
	int importance;
	cin.ignore();
	cout << "Enter the new topic to be added: " << endl;
	cin.get(topic, MAX, '\n'); cin.ignore(MAX, '\n');
	cout << "Enter the statement to be studied: " << endl;
	cin.get(statement, MAX, '\n'); cin.ignore();
	cout << "Enter importance of information (1 - 10): ";
	cin >> importance;
	
	guide->insert(topic, statement, importance);
	return 0;

}
