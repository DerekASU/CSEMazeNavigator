// Name of Author(s): Derek Janzen 
// Course Number and Name: CSE 220, Programming for Computer Engineering 
// Semester: Fall 2014 // Source Code Lab Project Number: 5 
// Time Spent: 18 hours 20 minutes
// Resources used: c++ library and stack overflow
#include<cstring>
#include"Node.h"

Node::Node(char name) : name(name)
{

}

Node::Node()
{
	name = '\0';
	attachedNodes[0] = NULL;
	attachedNodes[1] = NULL;
	attachedNodes[2] = NULL;
	attachedNodes[3] = NULL;
}

void Node::setNodeName(char newname) {
	name = newname;
	attachedNodes[0] = NULL;
	attachedNodes[1] = NULL;
	attachedNodes[2] = NULL;
	attachedNodes[3] = NULL;
}

void Node::attachNewNode(Node* newNode, int dir) {
	attachedNodes[dir] = newNode;

}

Node* Node::getAttachedNode(int dir) {
	return attachedNodes[dir];
}


