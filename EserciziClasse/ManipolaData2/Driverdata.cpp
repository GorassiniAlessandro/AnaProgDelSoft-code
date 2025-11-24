// File main.cpp
#include <iostream>
#include "ClasseData.hpp"

int main()
{
  unsigned g, m, a;
  cout << "Data iniziale (giorno mese anno): ";
  cin >> g >> m >> a;
  Data d(g,m,a);
  int n;
  do
    {
      d.Stampa();
      cout << "Quanti giorni vuoi aggiungere (0 per uscire)? ";
      cin >> n;
      d.SommaGiorni(n);
    }
  while (n != 0);
  return 0;
}