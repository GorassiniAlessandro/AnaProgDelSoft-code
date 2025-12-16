// File Mano.cpp
#include "Mano.hpp"
#include <cassert>

Mano::Mano(Mazzo* mazzo)
  : carte(5)
{ 
  mazzo_utilizzato = mazzo;
}

void Mano::Distribuisci()
{ 
  for (unsigned i = 0; i < 5; i++)
    carte[i] = mazzo_utilizzato->PescaCarta();
}

void Mano::CambiaCarta(unsigned i)
{ 
  carte[i] = mazzo_utilizzato->PescaCarta();
}

Punto Mano::Valuta() const
{ 
  vector<unsigned> conta_valori(mazzo_utilizzato->NUM_VALORI,0), 
    conta_semi(mazzo_utilizzato->NUM_SEMI,0);
  pair<unsigned,unsigned> max;
  Conta(conta_semi,conta_valori);
  max = CercaMassimi(conta_valori);
  switch (max.first)
    {
    case 4:
      return Punto::poker;
    case 3:
      if (max.second == 2)
        return Punto::full;
      else 
        return Punto::tris;
    case 2:  
      if (max.second == 2)
        return Punto::doppia;
      else 
        return Punto::coppia;
    default:
      if (Scala(conta_valori))
        if (Colore(conta_semi))
          return Punto::scala_reale;
        else 
          return Punto::scala;
      else
        if (Colore(conta_semi))
          return Punto::colore;
        else 
          return Punto::niente;
    }
}

void Mano::Conta(vector<unsigned>& semi, vector<unsigned>& valori) const
{ 
  for (unsigned i = 0; i < 5; i++)
    { 
      semi[static_cast<unsigned>(carte[i].SemeCarta())]++;
      valori[static_cast<unsigned>(carte[i].ValoreCarta())]++;
    }
}

pair<unsigned,unsigned> Mano::CercaMassimi(const vector<unsigned> & valori) const
{ 
  pair<unsigned,unsigned> max = make_pair(0,0);
  for (unsigned i = 0; i < mazzo_utilizzato->NUM_VALORI; i++)
    if (valori[i] > max.first)
      { 
        max.second = max.first;
        max.first = valori[i];
      }
    else if (valori[i] > max.second)
      max.second = valori[i];
  return max;
}

bool Mano::Scala(vector<unsigned>& valori) const
{ 
  unsigned v;
  for (v = mazzo_utilizzato->NUM_VALORI-1; valori[v] == 0; v--) 
    ; // cerca il valore piu' alto della mano      
  if (valori[v] > 1 || v < 4)
    return false; // se ci sono carte uguali (valori[v] > 1) oppure 
  // se v e' uno degli ultimi 4 valori (v  < 4) allora non c'e' scala
  int carte_da_trovare = 4;
  while (carte_da_trovare > 0)
    { v--;
      if (valori[v] != 1)
        return false;
      else 
        carte_da_trovare--;
    }
  return true;
}

bool Mano::Colore(vector<unsigned>& semi) const
{ for (unsigned s = 0; s < mazzo_utilizzato->NUM_SEMI; s++)
    if (semi[s] == 5)
      return true;
  return false;
}

string Mano::NomePunto(Punto p) const
{ 
  switch (p) 
    {
    case Punto::niente: return "niente";
    case Punto::coppia: return "coppia";
    case Punto::doppia: return "doppia";
    case Punto::tris: return "tris";
    case Punto::scala: return "scala";
    case Punto::full: return "full";
    case Punto::colore: return "colore";
    case Punto::poker: return "poker";
    case Punto::scala_reale: return "scala reale";
    }
  return NULL; // caso impossibile (serve per prevenire il warning)
}

ostream& operator<<(ostream& os, const Mano& m)
{ 
  os << endl;
  for (unsigned i = 1; i <= 5; i++)
    os << i << ": " << m.carte[i-1] << endl;
  os << "Punto: " << m.NomePunto(m.Valuta()) << endl;
  return os;
}
