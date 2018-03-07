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
	bool empty() const;
	int cardinal() const;
	Set<E> unyon(const Set<E> &e) const;//sin repet
	Set<E> isect(const Set<E> &e) const;//sin repet
	Set<E> difer(const Set<E> &e) const;
	bool operator==(const Set<E> &e) const;

private:
	int _MAX;
	int _counter;
	E*_v;
};

