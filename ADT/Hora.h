#ifndef __HORA_
#define __HORA_
#include <iostream>	
#include "Exception.h"
using namespace std;

class Hora{

public:
	Hora() {
		_hr = 0;
		_min = 0;
		_seg = 0;
	}

	Hora(int hr, int min, int seg) {
		_hr = hr;
		_min = min;
		_seg = seg;
	}

	friend ostream &operator<<(ostream &o, const Hora &h)
	{
		o << (h._hr >= 10 ? "" : "0") << h._hr <<
			(h._min >= 10 ? ":" : ":0") << h._min <<
			(h._seg >= 10 ? ":" : ":0") << h._seg;

		return o;
	}
	friend istream &operator>>(istream &i, Hora &h)
	{
		i >> h._hr;
		i.ignore();
		i >> h._min;
		i.ignore();
		i >> h._seg;

		if (h._hr < 0 || h._hr > 23 ||
			h._min < 0 || h._min > 59 ||
			h._seg < 0 || h._seg > 59)
			throw BadHour("Invalid hour input");

		return i;
	}


	bool operator<(const Hora &h) const
	{

		if (h._hr < 0 || h._hr > 23 ||
			h._min < 0 || h._min > 59 ||
			h._seg < 0 || h._seg > 59)
			throw BadHour("Invalid hour input");


		if (_hr < h._hr)
			return true;
		else if (_hr == h._hr) {
			if (_min < h._min)
				return true;
			else if (_min == h._min) {
				if (_seg < h._seg)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}

	bool operator==(const Hora&h) const
	{
		return _hr == h._hr && _min == h._min && _seg == h._seg;
	}

	Hora operator+(const Hora&h) const
	{
		Hora hSum = Hora();

		hSum._seg = _seg + h._seg;
		if (hSum._seg > 59) {
			hSum._seg -= 60;
			hSum._min += 1;
		}

		hSum._min += _min + h._min;
		if (hSum._min > 59) {
			hSum._min -= 60;
			hSum._hr += 1;
		}

		hSum._hr += _hr + h._hr;

		if (hSum._hr > 23 && (hSum._min > 0 || hSum._seg > 0))
			throw BadHour("Sum of hours exceeds midnight");

		return hSum;
	}


private:
	int _hr;
	int _min;
	int _seg;
};
#endif