//
// Created by chosa on 3/19/18.
//
#include <iostream>
#include "Complex.h"
using namespace std;


void solveCase(){

    float rl, im;
    int iter;

    cin >> rl >> im >> iter;

    Complex<float> c = Complex<float>(rl, im);
    Complex<float> z = Complex<float>(0, 0);

    int i = 1;

    while(i < iter && z.modulus() <= 2)
    {
        z = z*z + c;
        i++;
    }

    if(i == iter && z.modulus() <= 2)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;

}


int main(){

    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
        solveCase();

    return 0;
}