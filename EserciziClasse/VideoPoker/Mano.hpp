// File Mano.hpp
#ifndef MANO_HPP
#define MANO_HPP
#include <iostream>
#include <vector>
#include "Mazzo.hpp"

enum class Punto {niente, coppia, doppia, tris, scala, colore,
            full, poker, scala_reale};

class Mano
{ 
  friend ostream& operator <<(ostream&, const Mano&);
 public:
  Mano(Mazzo*);
  void Distribuisci();
  void CambiaCarta(unsigned i);
  Punto Valuta() const;
  string NomePunto(Punto p) const;
 private:
  vector<Carta> carte;
  Mazzo* mazzo_utilizzato;
  
  
  void Conta(vector<unsigned>& semi, vector<unsigned>& valori) const;
  pair<unsigned,unsigned> CercaMassimi(const vector<unsigned>& valori) const;
  bool Scala(vector<unsigned>& valori) const;
  bool Colore(vector<unsigned>& semi) const;
};
#endif
