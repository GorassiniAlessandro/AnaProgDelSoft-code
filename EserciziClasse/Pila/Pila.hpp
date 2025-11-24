// File Pila.hpp
#ifndef PILA_HPP
#define PILA_HPP
#include <iostream>

using namespace std;

class Pila
{
  friend ostream& operator<<(ostream&, const Pila&); 
  friend istream& operator>>(istream&, Pila&); 
public:
  Pila();
  Pila(const Pila&);
  ~Pila();
  Pila& operator=(const Pila&);  
  void Push(int);
  void Pop();
  int Top() const;
  bool IsEmpty() const;
 private:
  int* vet;     // vettore di interi
  int dim;      // dimensione del vettore
  int top;      // elemento affiorante
};
#endif