#include "Stack.h"

template <class E>
Stack<E>::Stack() 
{
	_size = 10;
	_numberElements = 0;
	_v = new E[10];

}

template<class E>
Stack<E>::~Stack()
{
	delete[] _v;
	_v = NULL;
}

template<class E>
void Stack<E>::push(const E & e)
{
	if (_numberElements == _size)
		expand();
	_v[_numberElements] = e;
	_numberElements++;
}

template<class E>
const E & Stack<E>::top() const
{
	if (empty())
		throw "Empty stack";
	return _v[_numberElements - 1];
}

template<class E>
void Stack<E>::pop()
{
	if (empty())
		throw "Empty stack";
	_numberElements--;
}

template<class E>
bool Stack<E>::empty() const
{
	return _numberElements == 0;
}

template<class E>
int Stack<E>::size() const
{
	return _size;
}

template<class E>
int Stack<E>::numElements() const
{
	return _numberElements;
}



template<class E>
void Stack<E>::expand()
{
	int _oldSize = _size;
	_size = 2 * _size;

	E *_a = new E[_size];

	for (int i = 0; i < _oldSize; i++)
		_a[i] = _v[i];

	delete[]_v;
	_v = _a;
}