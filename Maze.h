// Name of Author(s): Derek Janzen 
// Course Number and Name: CSE 220, Programming for Computer Engineering 
// Semester: Fall 2014 // Source Code Lab Project Number: 5 
// Time Spent: 18 hours 20 minutes
// Resources used: c++ library and stack overflow
#include<vector>
#include<string>
#include"Node.h"

using namespace std;

class Maze {

	public:
		vector<Node*> nodes;
		char start;
		char end;
		Node* findNode(char name);
		Node* addNode(char name);
		void begin();
		int readFile(string infile);
};


