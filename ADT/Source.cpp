#include <iostream>
#include "Arbin.h"
#include <algorithm>
using namespace std;


// prints the contents of the tree
void printTree(const Arbin<int>& t)
{
	if (t.esVacio()) cout << " . ";
	else {
		cout << t.raiz() << " ";
		printTree(t.hijoIz());
		printTree(t.hijoDr());
	}
}


// returns true if the tree is just a leave
bool isLeaf(const Arbin<int>& t)
{
	if (t.esVacio()) return false;
	return t.hijoIz().esVacio() && t.hijoDr().esVacio();
}


// returns the number of leaves of the tree
int numLeaves(const Arbin<int>& t)
{
	if (t.esVacio()) return 0;
	if (isLeaf(t)) return 1;
	return numLeaves(t.hijoIz()) + numLeaves(t.hijoDr());
}


// returns the height of the tree
int height(const Arbin<int>& t)
{
	if (t.esVacio()) return 0;
	
	int heightL, heightR;
	heightL = height(t.hijoIz());
	heightR = height(t.hijoDr());
	return 1 + max(heightL,heightR);
}


// returns the number of nodes of the tree
int numNodes(const Arbin<int>& t)
{
	if (t.esVacio()) return 0;
	return 1 + numNodes(t.hijoIz()) + numNodes(t.hijoDr());
}


////////////////////////
// Homework functions //
////////////////////////


// reads a tree from the standard input 
// (using the same format used by printTree)
Arbin<int> readTree()
{
	return Arbin<int>();
}

// Prints the frontier of the tree
// (i.e. the leaves from left to right)
void frontier(const Arbin<int>& t)
{

}


// returns true if the tree is balanced
bool isBalanced(const Arbin<int>& t)
{
	return false;
}


// returns true if the tree is complete
bool isComplete(const Arbin<int>& t)
{
	return false;
}


int main()
{
	Arbin<int> myArbin = 
		Arbin<int>(Arbin<int>(Arbin<int>(4), 
							  2,
							  Arbin<int>(5)),
				   1,
				   Arbin<int>(Arbin<int>(), 
							  3, 
							  Arbin<int>(6)));

	printTree(myArbin);
	cout << endl;

	cout << "Nodes: " << numNodes(myArbin) << endl;
	cout << "Height: " << height(myArbin) << endl;
	cout << "Leaves: " << numLeaves(myArbin) << endl;
	system("PAUSE");

}