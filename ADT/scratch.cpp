//#include <iostream>
//#include <algorithm>
//#include <string>
//#include "Arbin.h"
//
//using std::cin;
//using std::cout;
//using std::endl;
//using std::string;
//using std::getline;
//using std::max;
//using std::stoi;
//
//// prints the contents of the tree
//void printTree(const Arbin<int>& t)
//{
//	if (t.esVacio()) cout << ". ";
//	else {
//		cout << t.raiz() << " ";
//		printTree(t.hijoIz());
//		printTree(t.hijoDr());
//	}
//}
//
//
//// returns true if the tree is a leave == it has no sons
//bool isLeaf(const Arbin<int>& t)
//{
//	if (t.esVacio()) return false;
//	return t.hijoIz().esVacio() && t.hijoDr().esVacio();
//}
//
//
//// returns the number of leaves of the tree
//int numLeaves(const Arbin<int>& t)
//{
//	if (t.esVacio()) return 0;
//	if (isLeaf(t)) return 1;
//	return numLeaves(t.hijoIz()) + numLeaves(t.hijoDr());
//}
//
//
//// returns the height of the tree
//int height(const Arbin<int>& t)
//{
//	if (t.esVacio()) return 0;
//
//	int heightL, heightR;
//	heightL = height(t.hijoIz());
//	heightR = height(t.hijoDr());
//	return 1 + max(heightL, heightR);
//}
//
//
//// returns the number of nodes of the tree
//int numNodes(const Arbin<int>& t)
//{
//	if (t.esVacio()) return 0;
//	return 1 + numNodes(t.hijoIz()) + numNodes(t.hijoDr());
//}
//
//
//////////////////////////
//// Homework functions //
//////////////////////////
//
//
//// reads a tree from the standard input 
//// (using the same format used by printTree)
//Arbin<int> readTree()
//{
//	string s;
//	cin >> s;
//
//	if (s == ".")
//		return Arbin<int>();
//	else {
//		Arbin<int> izq = readTree();
//		Arbin<int> der = readTree();
//		return Arbin<int>(izq, stoi(s), der);	//adding readTree() to return line gives a tree that is reflected over the y axis
//	}
//}
//
//// Prints the frontier of the tree
//// (i.e. the leaves from left to right)
//void frontier(const Arbin<int>& t)
//{
//	if (t.esVacio()) return;
//
//	if (isLeaf(t.hijoIz()))
//		cout << t.hijoIz().raiz() << " ";
//	else
//		frontier(t.hijoIz());
//
//	if (isLeaf(t.hijoDr()))
//		cout << t.hijoDr().raiz() << " ";
//	else
//		frontier(t.hijoDr());
//}
//
//
//// returns true if the tree is balanced: 
////		if the longest branch of left tree is one node shorter or longer than the longest branch of right tree, and L/R trees also balanced
//bool isBalanced(const Arbin<int>& t, int& height)
//{
//	int hL = 0, hR = 0;
//
//	if (t.esVacio()) {
//		height = 0;
//		return true;
//	}
//	bool bL = isBalanced(t.hijoIz(), hL);
//	bool bR = isBalanced(t.hijoDr(), hR);
//
//	height = max(hL, hR) + 1;
//
//	return abs(hL - hR) < 2 && bL && bR;
//}
//
//
//// returns true if the tree is complete
//bool isComplete(const Arbin<int>& t)
//{
//	if (t.esVacio()) return true;
//	return height(t.hijoIz()) == height(t.hijoDr()) && isComplete(t.hijoIz()) && isComplete(t.hijoDr());
//}
//
//
//int main()
//{
//	//Complete:
//	//1 2 4 . . 5 . . 3 6 . . 7 . .		
//
//	//Not complete:
//	//1 2 4 . . 5 . . 3 . 6 . .						bal
//	//1 2 4 7 . . . 5 . . 3 . 6 8 9 . . . .			notBal
//	//1 2 4 7 . . . 5 . . 3 0 0 . . . 6 8 9 . . . .	bal
//	/*Arbin<int> arbin = Arbin<int>(
//					Arbin<int>(Arbin<int>(4),
//					2,
//					Arbin<int>(5)),
//				1,
//			Arbin<int>(Arbin<int>(),
//			3,
//			Arbin<int>(6)));*/
//	Arbin<int> arbin = readTree();
//
//	cout << "Tree read from input: ";
//	printTree(arbin);
//	cout << endl;
//	int h = 0;
//	isBalanced(arbin, h) ? cout << "Balanced" << endl : cout << "Not balanced" << endl;
//	isComplete(arbin) ? cout << "Complete" << endl : cout << "Not complete" << endl;
//	cout << "Nodes: " << numNodes(arbin) << endl;
//	cout << "Height: " << height(arbin) << endl;
//	cout << "Leaves: " << numLeaves(arbin) << endl;
//	cout << "Frontier: ";
//	frontier(arbin);
//	cout << endl;
//
//	system("PAUSE");
//	return 0;
//}