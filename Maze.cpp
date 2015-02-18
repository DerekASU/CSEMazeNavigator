// Name of Author(s): Derek Janzen 
// Course Number and Name: CSE 220, Programming for Computer Engineering 
// Semester: Fall 2014 // Source Code Lab Project Number: 5 
// Time Spent: 18 hours 20 minutes
// Resources used: c++ library and stack overflow
#include<fstream>
#include<iostream>
#include<string>
#include<stdlib.h>
#include "Maze.h"
#include"Menu.h"

using namespace std;

int main() {
	Maze m;
	m.begin();

}


void Maze::begin()
{
	
	Menu menu;
	int ret = -1;
	string s;
	while( ret == -1 )
	{
		s = menu.getFile();
		ret = readFile(s);
	}
	int dir[4] = {0};
	Node* neighbor;
	vector<char> visited;
	char curr = start;
	int i=0;
	char option;
	int op;
	bool valid;
	int numSteps = 0;
	while(1) {
		Node* n = findNode(curr);
		if(n == NULL) {
			cout << "Error: Node " << curr << " not found" << endl;
			break;
		}
		while(i < 4) {
			neighbor = n->getAttachedNode(i);
			if(neighbor != NULL)
				dir[i] = 1;
			i++;
		}
		option = menu.display(curr,dir);
		valid = false;
		if(option == 'N' || option == 'n' )
		{
			if(dir[0] == 1) {
				valid = true;
				op = 0;
			}
		
		}	
		else if(option == 'E' || option == 'e' )
		{
			if(dir[1] == 1) {
				valid = true;
				op = 1;
			}
		
		}	
		else if(option == 'S' || option == 's' )
		{
			if(dir[2] == 1) {
				valid = true;
				op = 2;
			}
		
		}	
		else if(option == 'W' || option == 'w' )
		{
			if(dir[3] == 1) {
				valid = true;
				op = 3;
			}
		
		}	

		if(valid) {
			visited.push_back(curr);
			curr = (n->getAttachedNode(op))->getName();
			if(curr == end) {
				visited.push_back(end);
				break;
			}
			i=0;
			numSteps++;
			dir[0]=0;dir[1]=0;dir[2]=0;dir[3]=0;	
		}
		else {
			cout << "Please input a correct direction" << endl;
		}
	}
	menu.displayResult(numSteps,visited);
	char in;
	while(1) {
		in = menu.playAgain();
		if(in == 'N' || in == 'n' || in == 'y' || in == 'Y')
			break;

		cout << "Error: Please input correct value" << endl;
	}
	if(in == 'y' || in == 'Y')
		begin();
			
}



Node* Maze::findNode(char c)
{
	for (unsigned int i = 0; i < nodes.size(); i++)
       	{
		if(nodes[i]->getName() == c)
			return nodes[i];
	}
	return NULL;
}

Node* Maze::addNode( char c)  {

	Node *n = new Node(c);
	nodes.push_back(n);
	return n;
}

int Maze::readFile(string infile)
{

	ifstream ifile;
	ifile.open(infile.c_str());
	char one,two,three,four,five;
	int count = 0;

	if(ifile.fail())
	{
		cout << "Error in file opening, please input correct file" << endl;
		return -1;
	}

	while(ifile >> one >> two >> three >> four >> five) {
		if(count == 0)
			start = one;
		end = one;
		Node* temp1 = findNode(one);
		if(temp1 == NULL)
			temp1 = addNode(one);

		Node* temp2;
		
		if( two != '*' )
		{
			temp2 = findNode(two);
			if(temp2 == NULL)
				temp2 = addNode(two);
		
			temp1->attachNewNode(temp2,0);	
		}
		else	
			temp1->attachNewNode(NULL,0);	
		if( three != '*' )
		{
			temp2 = findNode(three);
		
			if(temp2 == NULL)
				temp2 = addNode(three);
		
			temp1->attachNewNode(temp2,1);	
		}
		else	
			temp1->attachNewNode(NULL,1);	
		if( four != '*' )
		{
			temp2 = findNode(four);
			if(temp2 == NULL)
				temp2 = addNode(four);
		
			temp1->attachNewNode(temp2,2);	
		}
		else	
			temp1->attachNewNode(NULL,2);	
		if( five != '*' )
		{
			temp2 = findNode(five);
			if(temp2 == NULL)
				temp2 = addNode(five);
		
			temp1->attachNewNode(temp2,3);	
		}
		else	
			temp1->attachNewNode(NULL,3);	
		count++;
	}
	return 0;
}
