#pragma once
#include <iostream>
using namespace std;

class Hora{

public:
	Hora();
	Hora(int hr, int min, int seg);

	friend ostream &operator<<(ostream &o, const Hora &h);
	friend istream &operator>>(istream &i, Hora &h);
	bool operator<(const Hora &h);
	bool operator==(const Hora&h);



private:
	int _hr;
	int _min;
	int _seg;
};