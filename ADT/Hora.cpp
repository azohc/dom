#include "Hora.h"
#include <string>


Hora::Hora() {
	_hr = 0;
	_min = 0;
	_seg = 0;
}

Hora::Hora(int hr, int min, int seg) {
	_hr = hr;
	_min = min;
	_seg = seg;
}

bool Hora::operator<(const Hora &h) {

	return false;
}

bool Hora::operator==(const Hora&h) {

}

ostream &operator<<(ostream &o, const Hora &h) {
	o << (h._hr >= 10 ? "" : "0") << h._hr <<
		(h._min >= 10 ? ":" : "0") << h._min <<
		(h._seg >= 10 ? ":" : "0") << h._seg;

	return o;
}
istream &operator>>(istream &i, Hora &h) {
	string auxA, auxB;
	
	i >> h._hr >> auxA >> h._min >> auxB >> h._seg;
	
	if (auxA != ":" || auxB != ":" || 
		h._hr < 0 || h._hr > 99 || 
		h._min < 0 || h._min > 59 || 
		h._seg < 0 || h._seg > 59) 
		throw "Invalid hour input"
}

