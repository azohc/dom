#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>
#include <string>
#include "Set.cpp"
#include "Stack.cpp"
using namespace std;

//Exercise 2:
//Code a function that receives a stack and writes its elements from the bottom to the
//top, separated by blank spaces.Code both a recursive and an iterative version of
//this function.
//Write a third version as part of the Stack class.
template <class E>
void writeFifo(Stack<E> s) 
{
	string out = "";	
	while(s.numElements() > 1)
	{
		out = " " + s.top() + out;
		s.pop();
	}
	out = s.top() + out;
	cout << out << endl;
}

int main() 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Stack<string> s;
	int n;
	string x;
	cout << "Enter a the number of elements to write to the stack, then enter the elements" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s.push(x);
	}

	writeFifo(s);
	
	system("pause");
	return 0;
}



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