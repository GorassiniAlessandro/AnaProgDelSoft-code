/*----------------------------------
file: Poli.hpp
autore: Alessandro Gorassini 168518
date: 18/11/2025
descr:header della classe Poli
------------------------------------*/

#ifndef POLI_HPP
#define POLI_HPP

#include <iostream>
#include <cmath>
#include <ostream>
#include <istream>

using namespace std;

class Poli
{

friend Poli operator+(const Poli& p1, const Poli& p2);
friend Poli operator-(const Poli& p1, const Poli& p2);
friend ostream& operator<<(ostream& os, const Poli& p);
friend istream& operator>>(istream& is, Poli& p);

private:
    double* coeff;
    int grado;
public:
    Poli();
    Poli(double cof, int esp);
    Poli(const Poli& p);
    ~Poli() {
        delete[] coeff;
    };
    
    double GetCoeff(int i) const ;
    int GetGrado() const ;
    
    double operator()(double x) const;
    Poli& operator=(const Poli& p);
};


#endif