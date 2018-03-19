#ifndef _COLAVIP
#define _COLAVIP

#include "Queue.h"

template <class T>
class ColaVIP{
public:

    ColaVIP<T>(int p){
        _numPriorities = p;
		_v = new Queue<T>[p];
    }


    void push(int p, const T &e){
        _v[p].push_back(e);
    }

    T const &front() const{
        if(empty())
            throw "No front of queue: it is empty";

        int i = 0;
        while(i < _numPriorities)
        {
            if(_v[i].empty())
                i++;
            else
                return _v[i].front();
        }
		
		throw "Error";
    }

    void pop(){

        int i = 0;
        while(i < _numPriorities){
            if(_v[i].empty())
                i++;
            else{
                _v[i].pop_front();
                return;
            }
        }
    }

    bool empty() const {
        bool empty = true;
        int i = 0;

        while(i < _numPriorities && empty) {
            if (!_v[i].empty())
                empty = false;
            i++;
        }

        return empty;
    }

    size_t size() const {
        int size = 0;

        for(int i = 0; i < _numPriorities; i++)
            size += _v[i].size();

        return size;
    }


private:

    Queue<T> *_v;
    int _numPriorities;	//number of priorities
};
#endif