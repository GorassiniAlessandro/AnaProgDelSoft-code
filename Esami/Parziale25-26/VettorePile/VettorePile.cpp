#include <iostream>
#include <stdexcept>
#include <vector>
#include "Pila.hpp"
using namespace std;

Pila UnisciPile(const vector<Pila>& v);

int main() 
{ 
  vector<Pila> v;
  Pila p;
  p.Push(3);
  p.Push(-5);
  v.push_back(p);  // push (3, -5)
  p.Push(2);     
  v.push_back(p);  // push (3, -5, 2)
  p.Push(-32);
  v.push_back(p);  // push (3, -5, 2, -32)
  p.Push(21);
  v.push_back(p); // push (3, -5, 2, -32, 21)
  
  cout << UnisciPile(v) << endl;
  return 0;
}

Pila UnisciPile(const vector<Pila>& v)
{
    Pila ris, p;
    int e;
    for (unsigned i = 0; i < v.size(); i++)
    {
      p = v[i];
      while (!p.IsEmpty())
        {
          e = p.Top();
          if (e > 0)
            ris.Push(e);
          p.Pop();
        }
    }
    return ris;
}