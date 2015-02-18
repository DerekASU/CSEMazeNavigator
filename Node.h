// Name of Author(s): Derek Janzen 
// Course Number and Name: CSE 220, Programming for Computer Engineering 
// Semester: Fall 2014 // Source Code Lab Project Number: 5 
// Time Spent: 18 hours 20 minutes
// Resources used: c++ library and stack overflow
#ifndef NODE_H_
#define NODE_H_

using namespace std;

class Node {

	public: 
		Node(char newname);
		Node();
		void setNodeName(char newname);
		void attachNewNode(Node *newNode, int direction);
		Node *getAttachedNode(int direction);
		inline char getName() {return name;};
	private:
		char name;
		Node* attachedNodes[4];
};

#endif
