/*----------------------------------
file: Vettori3D.cpp
autore: Alessandro Gorassini 168518
date: 4/11/2025
descr: Implementation of the Vettore class, providing constructors, getters, and overloaded operators for vector operations.
------------------------------------*/

#include "Vettori3D.hpp"

Vettore::Vettore()
{
    x = 0;
    y = 0;
    z = 0;
}

Vettore::Vettore(double x, double y)
{
    this->x = x;
    this->y = y;
    this->z = 0;
}

Vettore::Vettore(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double Vettore::getX() const
{
    return x;
}
double Vettore::getY() const
{
    return y;
}
double Vettore::getZ() const
{
    return z;
}

ostream& operator<<(ostream& os, const Vettore& v)
{
    os << "(" << v.x << " " << v.y << " " << v.z << ")";
    return os;
}
istream& operator>>(istream& is, Vettore& v)
{
    is >> v.x >> v.y >> v.z;
    return is;
}
Vettore operator+(const Vettore& v1, const Vettore& v2)
{
    return Vettore(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
Vettore operator*(const Vettore& v1, const Vettore& v2)
{
    return Vettore(v1.y * v2.z - v1.z * v2.y,
                   v1.z * v2.x - v1.x * v2.z,
                   v1.x * v2.y - v1.y * v2.x);
}
Vettore operator&(const Vettore& v1, const Vettore& v2)
{
    return Vettore(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}
