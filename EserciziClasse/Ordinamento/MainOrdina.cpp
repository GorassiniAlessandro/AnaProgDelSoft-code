#include <iostream>
#include "Ordina.hpp"

using namespace std;

int* LeggiVettore(unsigned n);

int main()
{
  int* p;
  unsigned n,i;
  
  cout << "Inserisci la lunghezza della sequenza: ";
  cin >> n;
  p = LeggiVettore(n);
  OrdinaPerSelezione(p,n);
  cout << "Il vettore ordinato e': ";
  for (i = 0; i < n; i++)
	 cout << p[i] << ' ';
  cout << endl;
  delete[] p;
  return 0; 
}

int* LeggiVettore(unsigned n)
{
  int* q;
  unsigned i;
  
  cout << "Inserisci " << n << " interi: ";
  q = new int[n];
  for (i = 0; i < n; i++)
	 cin >> q[i];
  return q;  
}