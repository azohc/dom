#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>
#include <string>
#include <algorithm>
#include "Set.cpp"
#include "Stack.cpp"
#include "Peli.cpp"
using namespace std;



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	system("pause");
	return 0;
}




////JUEZ

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
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//
//	int n = -1;
//	while (n != 0)
//	{
//		cin >> n;
//		solveCase(n);
//	}
//
//	system("pause");
//	return 0;
//}
//

////Trenes y horarios
//int n, m;
//
//cin >> n >> m;		//n = numConsultas, m = numTrenes
//Hora*consultas = new Hora[n];
//Hora*trenes = new Hora[m];
//for (int i = 0; i < m; i++)
//	cin >> trenes[i];
//for (int i = 0; i < n; i++)
//	cin >> consultas[i];
//sort(consultas, consultas + n);
//int j = 1;
//for (int i = 0; i < n; i++)
//{
//	while (trenes[j - 1] < consultas[i] && j <= m)
//		j++;
//	if (j <= m)
//		cout << trenes[j - 1];
//	else
//		cout << "NO" << endl;
//}


////EJS CLASE
/*
//Exercise 1: 
//Use a stack to implement a non-recursive procedure that receives a integer number
//n >= 0 and writes its digits in order and their sum

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Stack<int> s;
	int n, sum = 0;

	cout << "Enter a number: ";
	cin >> n;

	while (n > 0)
	{
		s.push(n % 10);
		n /= 10;
	}

	while(s.numElements() > 1)
	{
		cout << s.top() << " + ";		//print top number and +
		sum += s.top();					//add top number to sum
		s.pop();						//pop top number
	}

	sum += s.top();
	cout << s.top() << " = " << sum << endl;

	system("pause");
	return 0;
}
*/

////Exercise 2:
////Code a function that receives a stack and writes its elements from the bottom to the
////top, separated by blank spaces.Code both a recursive and an iterative version of
////this function.
////Write a third version as part of the Stack class.
//template <class E>
//void writeFifo(Stack<E> s) 
//{
//	string out = "";	
//	while(s.numElements() > 1)
//	{
//		out = " " + s.top() + out;
//		s.pop();
//	}
//	out = s.top() + out;
//	cout << out << endl;
//}
//
//int main() 
//{
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//
//	Stack<string> s;
//	int n;
//	string x;
//	cout << "Enter a the number of elements to write to the stack, then enter the elements" << endl;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x;
//		s.push(x);
//	}
//
//	writeFifo(s);
//	
//	system("pause");
//	return 0;
//}

