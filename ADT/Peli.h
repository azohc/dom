#ifndef __PELI_
#define __PELI_
#include "Hora.h"
#include <string>
using namespace std;

class Peli {
public:
	Peli()
	{
		_start = Hora();
		_length = Hora();
		_title = "";
	}
	Peli(Hora start, Hora length, string title)
	{
		_start = start;
		_length = length;
		_title = title;
	}

	//void setStart(const Hora &s);
	//void setLen(const Hora &l);
	//void setTitle(const string &t);
	
	bool operator<(const Peli &p) const {
		// A < B cuando el tiempo de finalización de A es < que B
		Hora A = _start + _length;
		Hora B = p._start + p._length;

		if (A < B)
			return true;
		else if (A == B)	//en caso de que t.d.f. de A == t.d.f. de B => ordenar segun orden alfabetico de titulo
			return _title < p._title;
		else
			return false;
	}


	Hora _start;
	Hora _length;
	string _title;
private:
};
#endif