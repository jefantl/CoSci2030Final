#pragma once

#include "Node.h" 
#include <iostream>
#include <math.h>       /* log */

using namespace std;

class CompleteBinaryTree
{
public:
	int treeSize = 1;
	int treeIndex = 0;
	Node *tree = new Node[1];
	CompleteBinaryTree();
	~CompleteBinaryTree();

	void print();
	void print(int inIndex);
	void printArray();
	void print(string inID);
	void add(string);
	void grow();
	void updateChildren(int inVal);
	bool contains(string inStr, int inIndex);
	bool contains(string inStr);
	void update();
private:

};

