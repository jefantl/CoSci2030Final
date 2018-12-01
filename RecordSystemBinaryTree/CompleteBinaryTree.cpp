#include "pch.h"
#include "CompleteBinaryTree.h"


CompleteBinaryTree::CompleteBinaryTree()
{
}


CompleteBinaryTree::~CompleteBinaryTree()
{
}


void CompleteBinaryTree::add(string inVal)
{
	if (treeIndex == treeSize) {
		grow();
	}

	int parentIndex = (treeIndex - 1) / 2;
	string parentID = "No parent";
	if (treeIndex != 0) {
		parentID = tree[parentIndex].ID;
	}
	tree[treeIndex] = Node(inVal, parentID);
	while (contains(tree[treeIndex].ID)) { //This handles any repeated hashes
		tree[treeIndex].ID = tree[treeIndex].custumHash(tree[treeIndex].ID);
	}

	
	cout << "Added ID " << tree[treeIndex].ID << " with value: " << tree[treeIndex].value << endl;
	if (treeIndex != 0) {
		updateChildren(treeIndex);
	}

	treeIndex++;
}

void CompleteBinaryTree::grow() {
	Node *newTree = new Node[treeSize * 2];
	for (int i = 0; i < treeSize; i++) {
		newTree[i] = tree[i];
	}
	tree = newTree;
	treeSize *= 2;
}

void CompleteBinaryTree::updateChildren(int inIndex) {
	int parentIndex = (inIndex - 1) / 2;
	bool isLeft = parentIndex == (inIndex / 2);
	if (isLeft) {
		tree[parentIndex].LHASH = tree[inIndex].computeHash();
		tree[parentIndex].LHIST.push_back(tree[parentIndex].LHASH);
	}
	else {
		tree[parentIndex].RHASH = tree[inIndex].computeHash();
		tree[parentIndex].RHIST.push_back(tree[parentIndex].RHASH);
	}
	if (parentIndex != 0) {
		updateChildren(parentIndex);
	}
}

bool CompleteBinaryTree::contains(string inStr) {
	for (int i = 0; i < treeIndex; i++) {
		if (tree[i].ID.compare(inStr) == 0) {
			return true;
		}
	}
	return false;
}

void CompleteBinaryTree::print()
{
	cout << endl << "Tree form of records:" << endl;
	for (int i = 0; i < treeIndex; i++) {
		if (floor(log2(i)) != floor(log2(i + 1))) { //checker for if log2(i) is a perfect value
			cout << endl;
		}
		cout << tree[i].ID << " ";
		
	}
}

void CompleteBinaryTree::printArray() {
	cout << endl << endl << "Array form of records: " << endl;

	for (int i = 0; i < treeIndex; i++) {
		cout << tree[i].ID << " ";
	}
}

void CompleteBinaryTree::print(string inID)
{
	for (int i = 0; i < treeIndex; i++) {
		if (tree[i].ID.compare(inID) == 0) {
			tree[i].print();
			return;
		}
	}
	cout << "No record with that ID" << endl;
}