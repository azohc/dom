#include <iostream>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::list;


void solveCase(int n, int k) {

	//n = numero de sobres, k = # de sobres que necesita coger
	list <int> pasta;
	int aux;
	for (int i = 0; i < n; i++)
	{
		cin >> aux;
		pasta.push_back(aux);
	}

	//el numero i-esimo indica la cantidad que se llevara el presidente si coge los k sobres desde el sobre i hasta el sobre i + k - 1

	int N = n - k + 1;	//cantidad de veces que se devuelve la pasta q se lleva el presi
	int i = 0, j = 0, max = 0;
	list <int>::const_iterator iter = pasta.cbegin();

	while (i < N) 
	{
		while (j < k) {
			if (*iter > max)
				max = *iter;
			
			iter++;
			j++;
		}
		cout << max << " ";
		i++;
		if (k == 1)
			max = 0;
	}

	cout << endl;
}


int main() {

	int n, k;
	cin >> n >> k;

	while (n != 0 || k != 0) {
		solveCase(n, k);
		cin >> n >> k;
	}

	return 0;
}