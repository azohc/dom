/*
#include <iostream>
#include <stack>
using namespace std;

bool solveCase(unsigned n) {

	stack<int> s;
	
	int*v = new int[n];
	for (unsigned i = 0; i < n; i++) cin >> v[i];

	unsigned numberToPush = 1;
	unsigned numbersPopped = 0;
	while (numbersPopped < n)
	{
		if (s.empty() || v[numbersPopped] != s.top())
		{
			if (s.size() + numbersPopped == n)
				return false;
			
			else 
			{
				cout << "Wagon " << numberToPush << " in" << endl;
				s.push(numberToPush);
				numberToPush++;
			}
		}
		else if (v[numbersPopped] == s.top())
		{
			cout << "Wagon " << s.top() << " out" << endl;
			s.pop();
			numbersPopped++;
		}



	}

	return numbersPopped == n;
}

int main()
{
	unsigned n;
	cin >> n;
	while (n != 0) {

		solveCase(n) ? cout << "POSSIBLE" : cout << "IMPOSSIBLE";
		cout << endl;
		cin >> n;

	}


	return 0;
}*/
