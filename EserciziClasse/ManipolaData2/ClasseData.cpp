// File ClasseData.cpp
#include <iostream>
#include "ClasseData.hpp"

Data::Data(unsigned g, unsigned m, unsigned a)
{
  giorno = g;
  mese = m;
  anno = a;
  if (!Valida())
    {
      giorno = GIORNO_ZERO;
      mese = MESE_ZERO;
      anno = ANNO_ZERO;
    }
}

Data::Data()
{
  giorno = GIORNO_ZERO;
  mese = MESE_ZERO;
  anno = ANNO_ZERO;
}


bool Data::Valida() const
{
  return anno >= 1 && mese >= 1 && mese <= 12 
      && giorno >= 1 && giorno <=GiorniDelMese();
}

unsigned Data::GiorniDelMese() const
{
  if (mese == 4 || mese == 6 || mese == 9 || mese == 11)
    return 30;
  else if (mese == 2)
    if (Bisestile())
      return 29;
    else
      return 28;
  else 
    return 31;
}         

bool Data::Bisestile() const
{
  if (anno % 4 != 0)
    return false;
  else if (anno % 100 != 0)
    return true;
  else if (anno % 400 != 0)
    return false;
  else 
    return true;
}

void Data::Stampa() const
{
  cout << giorno << '/' << mese << '/' << anno << endl;
}

void Data::DataPrecedente()
{ 
  if (giorno != 1)
    giorno--;
  else 
    if (mese != 1)  
      { 
        mese--;
        giorno = GiorniDelMese();
      }
    else
      { 
        anno--;
        mese = 12;
        giorno = 31;
      }
}

void Data::DataSuccessiva()
{ 
  if (giorno != GiorniDelMese())
    giorno++;
  else 
    if (mese != 12)  
      { 
        giorno = 1;
        mese++;
      }
    else
      { 
        giorno = 1;
        mese = 1;
        anno++;
      }
}

void Data::SommaGiorni(int n)
{
  int i;
  if (n > 0)
    for (i = 0; i < n; i++)
      DataSuccessiva();
  else
    for (i = 0; i < -n; i++)
      DataPrecedente();
}