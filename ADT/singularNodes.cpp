//#include "Arbin.h"
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int singular(Arbin<int> t, int &topSum, int &value) {
//	
//	int singCount = 0, leftSum = 0, rightSum = 0;
//
//	if (t.esVacio())
//		return 0;
//	
//	if (!t.hijoIz().esVacio() || !t.hijoDr().esVacio())
//		topSum += t.raiz();
//
//	singCount += singular(t.hijoIz(), topSum, leftSum);
//	
//	singCount += singular(t.hijoDr(), topSum, rightSum);
//
//	if (!t.hijoIz().esVacio() || !t.hijoDr().esVacio())
//		topSum -= t.raiz();
//	
//	if (topSum == leftSum + rightSum)
//		singCount++;
//
//	value = t.raiz() + leftSum + rightSum;
//
//	return singCount;
//}
//
//Arbin<int> readTree(istream& in) {
//	char c;
//	in >> c;
//	switch (c) {
//	case '#': return Arbin<int>();
//	case '[': {
//		int raiz;
//		in >> raiz;
//  		in >> c;
//		return Arbin<int>(raiz);
//	}
//	case '(': {
//		Arbin<int> iz = readTree(in);
//		int raiz;
//		in >> raiz;
//		Arbin<int> dr = readTree(in);
//		in >> c;
//		return Arbin<int>(iz, raiz, dr);
//	}
//	default: return Arbin<int>();
//	}
//}
//
//int main() {
//	Arbin<int> arbol;
//	while (cin.peek() != EOF)  {
//		int a = 0, b = 0, c = 0;
//		cout << singular(readTree(cin), a, b);
//		string resto_linea;
//		getline(cin, resto_linea);
//		cout << endl;
//	}
//	return 0;
//}
