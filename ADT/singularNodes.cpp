#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;


int singular(Arbin<int> t, )

Arbin<int> readTree(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
  		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = readTree(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = readTree(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF)  {
		cout << YOUR_ALGORITHM_HERE(readTree(cin));
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}
