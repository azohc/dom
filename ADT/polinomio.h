#ifndef _POLINOMIO_H_
#define _POLINOMIO_H_
#include <cmath>
using namespace std;

template <class T>
class Polinomio {
public:

	Polinomio() {
		_v = new Monomio[TAM_INICIAL];
	}

	void addMonomio(const T &coef, int exp) {
		if (full())
			throw "Polinomio de grado maximo"
		_v[_elems] = Monomio<T>(coef, exp);
		_elems++;
	}

	bool full() {
		return _elems == TAM_INICIAL - 1;
	}

	T evaluate(T val) const {
		T o;

		for (int i = 0; i < _elems; i++) 
			o += _v[i]._coef*pow(val, _v[i]._exp);

		return o;
	}
		
private:

	template <class T>
	class Momomio {
	public:
		Monomio(T c, int e) {
			_coef = c;
			_exp = e;
		}
		T _coef;
		int _exp;
	};

	const static int TAM_INICIAL = 10;
	int _elems;
	Monomio<T> * _v;
};
#endif