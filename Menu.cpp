// Name of Author(s): Derek Janzen 
// Course Number and Name: CSE 220, Programming for Computer Engineering 
// Semester: Fall 2014 // Source Code Lab Project Number: 5 
// Time Spent: 18 hours 20 minutes
// Resources used: c++ library and stack overflow
#include<iostream>
#include<vector>
#include"Menu.h"



char Menu::display(char room , int dir[]){

	char c;
	cout << "You are current in room " << room << "  of the Pointer-Based Maze." << endl;
	cout << "Select a direction from the available choices below. "	 << endl;
	if(dir[0] == 1)
	cout << "(N) North   ";
	if(dir[1] == 1)
	cout << "(E) East   ";
	if(dir[2] == 1)
	cout << "(S) South   ";
	if(dir[3] == 1)
	cout << "(W) West  ";

	cout << endl;
	cout << "Please enter your choice from the menu above: ";
	cin >> c;	
	cout << endl;
	return c;
	
}

string Menu::getFile() {
	string s;
	cout << "Enter the name of the maze file: " ;
        getline(cin, s);
	cout << endl;
	return s;

}


void Menu::displayResult(int numSteps , vector<char> visited) 
{
	unsigned int i =0 ;
	cout << " Congratulations! you have reached the finish point." << endl;
        cout << "You took " << numSteps+2 << " steps." << endl;
        cout << "The nodes you visited are: ";
        for(i=0;i<visited.size();i++)
                cout << visited[i] << " ";
	cout << endl;
}


char Menu::playAgain() {
	
	cout << endl << "Play again ?" << endl << "(n) No     (y) Yes" << endl;
        cout << "please enter your choice from the menu above: ";
        char in;
        cin >> in;
	cout << endl;
	return in;
}
