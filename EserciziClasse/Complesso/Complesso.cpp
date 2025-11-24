// File complesso.h
#include <iostream>
#include <cmath>   // serve per la funzione acos
 
using namespace std;

class Complesso
{
public:
  double Modulo()      { return sqrt(re * re + im * im); }
  double Fase()        { if (im >= 0) return acos(re/Modulo());
                         else return -acos(re/Modulo()); }
  double re;  // parte reale
  double im;  // parte immaginaria
};

int main()
{
  Complesso a;
  a.re = 3;
  a.im = 4;
  cout << "Il modulo e' " << a.Modulo() << endl;
}