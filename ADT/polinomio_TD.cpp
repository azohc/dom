//#include <iostream>
//#include "polinomio_TD.h"
//using namespace std;
//
//bool solveCase() {
//	int a, b;
//
//	if (!(cin >> a >> b))
//		return false;
//
//	Polinomio<int> p;
//	p.addMonomio(0, 0);
//
//	while (a != 0 || b != 0) {
//		p.addMonomio(a, b);
//		cin >> a >> b;
//	}
//
//	cin >> a;	//numero de valores para evaluar
//	int*v = new int[a];
//	for (int i = 0; i < a; i++)
//		cin >> v[i];
//	
//	for (int i = 0; i < a; i++)
//		cout << p.evaluate(v[i]) << " ";
//
//	cout << endl;
//	return true;
//}
//
//int main() {
//
//	while (solveCase());
//
//	return 0;
//}