#pragma once

#include <string>
#include <vector> 
#include <iostream>

using namespace std;

class Node
{
public:
	string ID = "";
	string parentID = "";
	string value = ""; //user input event
	string RHASH = "";
	string LHASH = "";
	vector<string> RHIST;
	vector<string> LHIST;

	Node(string, string);
	Node();
	void updateValue(string newVal);
	~Node();
	string custumHash(string inStr);
	string computeHash();
	void print();
};

