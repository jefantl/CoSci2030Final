#include "pch.h"
#include "Node.h"

Node::Node(string inVal, string inParent)
{
	value = inVal;
	parentID = inParent;
	ID = custumHash(inVal + parentID);
}

Node::Node() {

}

void Node::updateValue(string newVal)
{
	value = newVal;
}

void Node::print()
{
	cout << endl << "Node ID: " << ID << endl;
	cout << "Node value: " << value << endl;
	cout << "Parent: " << parentID << endl;
	cout << "Hashed ID: " << computeHash() << endl;
	cout << "Left child: " << LHASH << endl;
	cout << "Right child: " << RHASH << endl;
	cout << "history for left child: (oldest -> newest)" << endl;
	vector<string>::iterator it = LHIST.begin();
	for (it; it != LHIST.end(); ++it) {
		cout << "  " << *it << endl;
	}
	cout << "history for right child: (oldest -> newest)" << endl;
	it = RHIST.begin();
	for (it; it != RHIST.end(); ++it) {
		cout << "  " << *it << endl;
	}
}

Node::~Node()
{
}

string Node::custumHash(string inStr) {
	int outHash = 1;
	for (int i = 0; i < inStr.size() - 2; i ++) {
		outHash = abs((outHash * inStr[i]) % 99999999) + 10000000;
	}
	return to_string(outHash).substr(0, 8);
}


string Node::computeHash() {
	string toBeHashed = ID + parentID + LHASH + RHASH;
	return custumHash(toBeHashed);
}
