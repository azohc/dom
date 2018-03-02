#pragma once

template <class E>
class Set
{
public:
	Set(int size);
	~Set();
	void expand();
	void insert(const E &e);
	void remove(const E &e);
	bool contains(const E &e);

private:
	int _MAX;
	int _counter;
	E*_v;
};

