// File main.cpp
#include <iostream>
#include "ClasseData.hpp"

int main()
{
    unsigned g;
    unsigned m;
    unsigned a;
    cout << "Data iniziale (giorno mese anno): ";
    // cin >> g >> m >> a;
    // Data d(g,m,a);
    Data d;
    cin >> d;
  
  
    int n;
    const Data D(2,3,2020);


    do
    {
	    ++++g;
	    ++++d;	
        //      d.Stampa();
        //	  cout << d;
	    cout << d << " " << g << " " << D << endl;
        cout << "Quanti giorni vuoi aggiungere (0 per uscire)? ";
        cin >> n;
        d = d + n;  // d += n;  
	    cout << "Distanza dalla costante: " << d - D << endl;
    }
    while (n != 0);
    return 0;
}
