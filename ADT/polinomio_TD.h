#ifndef _POLINOMIO_H_
#define _POLINOMIO_H_
#include <cmath>

template <class T>
class Polinomio {
public:

	Polinomio() {
		_v = new Monomio<T>[TAM_INICIAL];
	}

	void addMonomio(const T &coef, int exp) {
		if (full())
			throw "Polinomio de grado maximo";
		_v[_elems] = Monomio<T>(coef, exp);
		_elems++;
	}

	bool full() {
		return _elems == TAM_INICIAL - 1;
	}

	T evaluate(T val) const {
		T o = 0;

		for (int i = 0; i < _elems; i++) 
			o += _v[i]._coef*pow(val, _v[i]._exp);

		return o;
	}
	
private:

	template <class E>
	class Monomio {
	public:
		Monomio<E>() {
			_coef = 0;
			_exp = 0;
		}
		Monomio<E>(E c, int e) {
			_coef = c;
			_exp = e;
		}
		E _coef;
		int _exp;
	};

	const static int TAM_INICIAL = 10;
	int _elems;
	Monomio<T> *_v;
};
#endif