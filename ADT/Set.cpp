#include "Set.h"
/*      4      ------------------------------    dynamic array: resizeable      */

template<class E>
Set<E>::Set(int size)
{
	E*_v = new E[size];
	_counter = 0;
}

template<class E>
Set<E>::~Set()
{
	delete[] _v;
	_v = NULL;
}

template<class E>
void Set<E>::expand()
{
	int _NEWMAX = _MAX + (_MAX / 3) + 1;

	E*_nv = new E[_NEWMAX];

	for (int i = 0; i < _counter; i++)
		_nv[i] = _v[i];

	delete[] _v;
	_v = _nv;
	_nv = NULL;
	_MAX = _NEWMAX;
}

template<class E>
void Set<E>::insert(const E & e)
{
	if (_counter == _MAX)
		expand();
	
	if (!contains(e))		// if it is not contained in the Set
	{
		int i = 0;
			
		while (i < _counter && _v[i] < e)
			i++;
			
		for (int j = _counter; j >= i; j--)
			_v[j + 1] = _v[j];

		_v[i] = e;
	}
	else
		throw "Element already exists!";
	
}

template<class E>
void Set<E>::remove(const E & e)
{
	int i = 0;
	bool found = false;

	while(i < _counter && !found){
		if (_v[i] == e)
			found = true;
		i++;
	}
	if (found) {
		_v[i] = NULL;
		_counter--;
	}
	else
		throw "Element not found";
}

template<class E>
bool Set<E>::contains(const E & e) const
{
	int l = 0, r = _counter, mid;		// binary search
	while (l <= r)
	{
		int m = (l + r) / 2;
	
		if (_v[m] == e)
			return true;
	
		if (_v[m] < e)
			l = m + 1;
		else
			r = m - 1;
	}
	
	return false;
}

template <class E>
int Set<E>::cardinal() const {
	int card = 0;

	Set<E> aux = Set<E>();
	for (int i = 0; i < _counter; i++) {
		if (!aux.contains(_v[i])) {
			aux.insert(_v[i]);
			card++;
		}
	}
	
	return card;
}

template <class E>
Set<E> Set<E>::unyon(const Set<E> &e) const {
	Set<E> out = e.isect(e);
	
	for (int i = 0; i < _counter; i++)
		if (!out.contains(_v[i]))
			out.insert(_v[i]);
	
	return out;
}

template <class E>
Set<E> Set<E>::isect(const Set<E> &e) const {
	
	Set<E> out = Set();

	for (int i = 0; i < _counter; i++)
		if (e.contains(_v[i]) && !out.contains(_v[i]))
			out.insert(_v[i]);
	
	return out;
}

template <class E>
Set<E> Set<E>::difer(const Set<E> &e) const {

	Set<E> out = this->unyon(e);	//out = this u e
	Set<E> aux = e.isect(e);		//aux = e sin reps

	for (int i = 0; i < aux._counter; i++)
		out.remove(aux._v[i]);		//borrar elems presentes en aux

	return out;
}

template <class E>
bool Set<E>::empty() const {

	return _counter == 0;
}

template <class E>
bool Set<E>::operator==(const Set<E> &e) const {

	return this->isect(e).empty() && e.isect(this).empty();
}
