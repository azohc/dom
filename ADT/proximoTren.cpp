////#define _CRTDBG_MAP_ALLOC
////#include <stdlib.h>
////#include <crtdbg.h>
//
//#include <iostream>
//#include <string>
//#include "Hora.h"
//using namespace std;
//
//void solveCase(int n, int m) {
//
//
//	Hora*trenes = new Hora[n];
//	Hora*consultas = new Hora[m];
//	
//	for (int i = 0; i < n; i++) {
//		try {
//			cin >> trenes[i];
//		}
//		catch (BadHour) {}
//	}
//
//	for (int i = 0; i < m; i++) {
//		try {
//			cin >> consultas[i];
//		}
//		catch (BadHour) {}
//	}
//	
//	for (int i = 0; i < m; i++)
//	{
//		int j = 0;
//		try {
//
//			while (trenes[j] < consultas[i] && j < n) {
//				j++;
//			}
//
//			j < n ? cout << trenes[j] << endl : cout << "NO" << endl;
//
//		}
//		catch (BadHour) {
//			cout << "ERROR" << endl;
//			j = n;
//		}
//	}
//
//	cout << "---" << endl;
//	
//	delete consultas;
//	delete trenes;
//	consultas = trenes = NULL;
//}
//
//int main() {
//
//	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//
//	int n, m;
//
//	cin >> n >> m;		//n = numero de trenes, m = numero de consultas
//
//	while (n != 0 || m != 0) {
//		solveCase(n, m);
//		cin >> n >> m;
//	}
//
//	return 0;
//}