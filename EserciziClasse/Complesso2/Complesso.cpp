// File complesso.cpp
#include <iostream>
#include <cmath>   // serve per la funzione acos
 
using namespace std;

class Complesso
{
  friend Complesso operator+(const Complesso& c1, const Complesso& c2);
  friend Complesso operator*(const Complesso& c1, const Complesso& c2);
 public:
  Complesso(double r = 0.0, double i = 0.0)
    { re = r; im = i; }            
  double Modulo() const     { return sqrt(re * re + im * im); }
  double Fase() const       { if (im >= 0) return acos(re/Modulo());
                         else return -acos(re/Modulo()); }
  double Reale() const { return re; }
  double Immaginaria() const { return im;}  
  void operator+=(const Complesso& c) { re += c.re;  im += c.im; }
 private:
  double re;  // parte reale
  double im;  // parte immaginaria
};

Complesso operator+(const Complesso& c1, const Complesso& c2)
{
  return Complesso(c1.re + c2.re, c1.im + c2.im);
  // Complesso r;
  // r.re = c1.re + c2.re;
  // r.im = c1.im + c2.im;
  // return r;
}

Complesso operator*(const Complesso& c1, const Complesso& c2)
{
  return Complesso(c1.re*c2.re - c1.im*c2.im, c1.re*c2.im + c2.re*c2.im);	
}



int main()
{
  Complesso a(3.3,4.1), b(1.2), c;
  
  c = a + b;
  
  a += b;
  
  c = a * b + 2.3;
  
  
  // c = 3.4 + a;   c = 3.4.operator+(a)
  
  // c = a.operator+(b);
  // c = operator+(a,b);
  
  cout << "Reale: " << c.Reale() << ", Immaginaria: "<< c.Immaginaria() << endl;
  cout << "Modulo: " << c.Modulo() << ", Fase: "<< c.Fase() << endl;
}