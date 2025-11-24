// File ordina.cpp
#include <iostream>
#include "Ordina.hpp"

void OrdinaPerSelezione(int v[], int n)
{ 
  for (int i = 0; i < n - 1; i++)
    { 
      int min = i;
      for (int j = i + 1; j < n; j++)
        if (v[j] < v[min])
          min = j;
      Scambia(v[min], v[i]);
    }
}

void Scambia(int& a, int& b)
{
  int temp = a;
  a = b;
  b = temp;
}