#include <iostream>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::list;


void solveCase(int n, int k) {

	//n = numero de sobres, k = # de sobres que necesita coger
	list <int> pasta;
	int max;
	for (int i = 0; i < n; i++)
	{
		cin >> max;
		pasta.push_back(max);
	}
	int N = n - k + 1;	//cantidad de veces que se devuelve la pasta q se lleva el presi

	int i = 0;
	max = 0;

	list <int>::const_iterator iter = pasta.cbegin();
	list <int> processList; //ML with this, TL with second while instead

	while (i < N) {
		
		if (max == 0 && !processList.empty())
			for (list <int>::const_iterator iteraux = processList.cbegin(); iteraux != processList.cend(); iteraux++)
				if (*iteraux > max)
					max = *iteraux;

		while (processList.size() < k) {
			if(*iter > max)
				max = *iter;

			processList.push_back(*iter++);
		}
		cout << max << " ";
		i++;
		
		if (processList.front() == max)
			max = 0;
		
		processList.pop_front();
	}
	/*int firstPos = 0, maxPos = 0, j = 0;
	while (i < N)
	{
		if (firstPos > maxPos) {
			advance(iter, -k + 1);
			j = 0;
			max = 0;
		}

		while (j < k) {
			if (*iter > max)
			{
				max = *iter;
				maxPos = j + i;
			}
			iter++;
			j++;
		}

		cout << max << " ";
		i++;
		j--;
		firstPos = i;
	}*/
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