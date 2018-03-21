//
// Created by chosa on 3/19/18.
//

#ifndef DOM_COMPLEX_H
#define DOM_COMPLEX_H
#include <cmath>

template <class T>
class Complex{

public:
    Complex(T r, T i){
        _realNumber = r;
        _imagNumber = i;
    }

    Complex<T> operator+(const Complex<T> &o) const{

        return Complex<T>(this->_realNumber + o._realNumber, this->_imagNumber + o._imagNumber);
    }


    Complex<T> operator*(const Complex<T> &o) const{
        return Complex<T>(this->_realNumber*o._realNumber - this->_imagNumber*o._imagNumber,
                          this->_realNumber*o._imagNumber + this->_imagNumber*o._realNumber);
    }

    T modulus() const{
        return sqrt(pow(_imagNumber, 2) + pow(_realNumber, 2));
    }



private:
    T _realNumber;
    T _imagNumber;

};
#endif //DOM_COMPLEX_H
