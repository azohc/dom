#include <iostream>
#include <list>

using std::pair;
using std::list;
using std::cin;
using std::cout;
using std::endl;


void solveCase(int n, int k) {

	int N = n - k + 1;

	list <pair <int, int> > sobres(k);
	sobres.clear();

	int aux, i = 0;

	while (i < k) {
		cin >> aux;
		sobres.push_back(pair <int, int>(aux, i++));
	}

	int displayed = 0;
	do {
		cin >> aux;

		if (aux > sobres.front().first)
			sobres.push_front(pair <int, int>(aux, i++));
		else
			sobres.push_back(pair <int, int>(aux, i++));

		if (sobres.size() == k - 1) {
			cout << sobres.front().first << " ";
			displayed++;
		}

		if (i == sobres.front().second)
			sobres.pop_front();

	} while (displayed != N);

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
