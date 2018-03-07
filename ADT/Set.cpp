#include "Set.h"

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
	_v[_counter] = NULL;
	_counter--;
}

template<class E>
bool Set<E>::contains(const E & e)
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
