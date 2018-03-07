#pragma once;
#include <iostream>

template <class E>
class Stack {
public:
	Stack();

	~Stack();

	void push(const E &e);

	const E &top() const; //partial observer function

	void pop();			//partial mutator function 

	bool empty() const;	//observer function 

	int size() const;	//observer function 

	int numElements() const; //observer function
	
protected:
	void expand();

private:
	unsigned int _size;
	unsigned int _numberElements;
	E* _v;
};