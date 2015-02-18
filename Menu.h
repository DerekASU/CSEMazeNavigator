// Name of Author(s): Derek Janzen 
// Course Number and Name: CSE 220, Programming for Computer Engineering 
// Semester: Fall 2014 // Source Code Lab Project Number: 5 
// Time Spent: 18 hours 20 minutes
// Resources used: c++ library and stack overflow
#include<string>
#include<vector>

using namespace std;
using std::vector;

class Menu
{
	public:
		char display(char m, int dir[]);
		string getFile();
		void displayResult(int numSteps , vector<char> visited);
		char playAgain();
};
