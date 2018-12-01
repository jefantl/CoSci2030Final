// CompSciFinal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "CompleteBinaryTree.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Starting program" << endl;

	CompleteBinaryTree CBT = CompleteBinaryTree();
	CBT.add("Test entry 0");
	CBT.add("Test entry 1");
	CBT.add("Test entry 1"); //testing repeated inputs


		CBT.print();


	bool quit = false;
	while (!quit) {
		string userInput;
		cout << endl << endl << "to quit: Q, Quit" << endl;
		cout << "to add record: A ID, Add ID  Exe: A this is event 1" << endl;
		cout << "to print records: P, Print" << endl;
		cout << "to print a specific record: P ID, Print ID  Exe: P 12345678" << endl;

		getline(cin, userInput);

		if (userInput.compare("Q") == 0 || userInput.compare("Quit") == 0)
		{
			quit = true;
		}
		else if (userInput.substr(0, 2).compare("A ") == 0) {
			CBT.add(userInput.substr(2, userInput.length()));
		}
		else if (userInput.substr(0, 4).compare("Add ") == 0) {
			CBT.add(userInput.substr(4, userInput.length()));
		}
		else if (userInput.substr(0, 2).compare("P ") == 0 && userInput.length() == 10) {
			CBT.print(userInput.substr(2, 10));
		}
		else if (userInput.substr(0, 6).compare("Print ") == 0 && userInput.length() == 14)
		{
			CBT.print(userInput.substr(6, 14));
		}
		else if (userInput.compare("P") == 0 || userInput.compare("Print") == 0)
		{
			CBT.print();
			CBT.printArray();
		}
		else {
			cout << "Command not recognized. Maybe capitalize?" << endl;
		}
	}
}