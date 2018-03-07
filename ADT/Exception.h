#pragma once
#include <string>
using namespace std;

class Exception {
public:
	Exception(const string &msg) : _msg(msg) {}

	string getMsg() const {
		return _msg;
	}

private:
	string _msg;
};

class BadHour : Exception {
public:
	BadHour(const string &msg) : Exception(msg) {}

};