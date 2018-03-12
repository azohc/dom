////#define _CRTDBG_MAP_ALLOC
////#include <stdlib.h>
////#include <crtdbg.h>
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include "Peli.h"
//using namespace std;
//
////Una tarde de sabado: Cines y horas
//void solveCase(int n) {
//	Peli *v = new Peli[n];
//	Hora ini, dur;
//	string t;
//	char aux;
//
//	for (int i = 0; i < n; i++) {
//		cin >> ini >> dur;
//		cin.get(aux);
//		getline(cin, t);
//		v[i] = Peli(ini, dur, t);
//	}
//
//
//	sort(v, v + n);
//	
//	for (int i = 0; i < n; i++) 
//		cout << v[i]._start + v[i]._length << " " << v[i]._title << endl;
//	
//	cout << "---" << endl;
//
//	delete[]v;
//	v = NULL;
//}
//int main()
//{
//	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//
//	int n = -1;
//	while (n != 0)
//	{
//		cin >> n;
//		solveCase(n);
//	}
//
//	return 0;
//}
//
