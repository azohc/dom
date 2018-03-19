#include "ColaVIP.h"
#include <iostream>
#include <string>
using namespace std;

void solveCase() {

	int P, E, A;		//P = prioridades   E = llegadas/salidas	A = aforo

	cin >> P >> E >> A;

	ColaVIP<int> cv = ColaVIP<int>(P);

	char sign;
	int p, id, pplInside = 0;

	for (int i = 0; i < E; ++i) {
		cin >> sign;

		if (sign == '-') {
			pplInside--;

			if (pplInside != A)	//si cabe alguien
				if(!cv.empty())		// y hay gente
					cv.pop();		//entra el mas famoso de la cola
		}
		else
		{
			cin >> p >> id;

			if(pplInside == A)	//si la cantidad de gente dentro es = al alforo, a la puta cola
				cv.push(p, id);
			else
				pplInside++;

		}
	}

	if (cv.empty())
		cout << "NADIE";

	while (cv.size() > 0) {
		cout << cv.front() << " ";
		cv.pop();
	}
	cout << endl;
}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		solveCase();

	return 0;
}