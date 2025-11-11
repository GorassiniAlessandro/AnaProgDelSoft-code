/*----------------------------------
file: Vettori3D.hpp
autore: Alessandro Gorassini 168518
date: 4/11/2025
descr: Header file for the Vettore class, defining a 3D vector class with operators for addition, cross product, dot product, and I/O.
------------------------------------*/

#ifndef VETTORI3D_HPP
#define VETTORI3D_HPP

#include <iostream>

using namespace std;

class Vettore {
    friend ostream& operator<<(ostream& os, const Vettore& v);
    friend istream& operator>>(istream& is, Vettore& v);
    friend Vettore operator+(const Vettore& v1, const Vettore& v2);
    friend Vettore operator*(const Vettore& v1, const Vettore& v2);
    friend Vettore operator&(const Vettore& v1, const Vettore& v2);
private:
    double x, y, z;
public:
    Vettore();
    Vettore(double x, double y);
    Vettore(double x, double y, double z);

    double getX() const;
    double getY() const;
    double getZ() const;
};
#endif
