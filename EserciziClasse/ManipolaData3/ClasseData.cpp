// File data.cpp
#include <iostream>
#include "ClasseData.hpp"

Data::Data(unsigned g, unsigned m, unsigned a)
{
  giorno = g;
  mese = m;
  anno = a;
  if (!Valida())
    {
      giorno = 1;
      mese = 1;
      anno = 1970;
    }
}

Data::Data()
{
  giorno = 1;
  mese = 1;
  anno = 1970;
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

void Data::operator--()
{ 
  if (giorno != 1)
    giorno--;
  else if (mese != 1)  
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

Data& Data::operator++()
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
  return *this;
}

void Data::operator+=(int n)
{
  int i;
  if (n > 0)
    for (i = 0; i < n; i++)
      ++*this;
  else
    for (i = 0; i < -n; i++)
      --*this;
}

Data Data::operator+(int n) const
{
  int i;
  Data d = *this;
  if (n > 0)
    for (i = 0; i < n; i++)
      ++d;
  else
    for (i = 0; i < -n; i++)
      --d;
  return d;
}

bool operator==(const Data& d1, const Data& d2)
{
  return d1.giorno == d2.giorno && d1.mese == d2.mese && d1.anno == d2.anno;
}

// bool Data::operator<(const Data& d1)
// {
  // return (*this).anno < d1.anno 
      // || (anno == d1.anno && mese < d1.mese)
	  // || (anno == d1.anno && mese == d1.mese && giorno < d1.giorno);
// }

bool operator<(const Data& d1, const Data& d2)
{
  return d1.anno < d2.anno 
      || (d1.anno == d2.anno && d1.mese < d2.mese)
	  || (d1.anno == d2.anno && d1.mese == d2.mese && d1.giorno < d2.giorno);
}

int operator-(Data d1, Data d2)
{
  int conta_giorni = 0;
  if (d1 < d2)	
    while (d1 < d2)
    {
		++d1;
		conta_giorni--;
    }
  else
	 while (d2 < d1)
 	 {
		++d2;  // --d1;
		conta_giorni++;
	 }		 
  return conta_giorni;
}

ostream& operator<<(ostream& os, const Data& d)
{
  os << d.giorno << '/' << d.mese << '/' << d.anno;
  return os;
}

istream& operator>>(istream& is, Data& d)
{ // 2 11 2020    2/3/2020  2%3%2020
  char ch;  // is >> ch;
  is >> d.giorno >> ch >> d.mese >> ch >> d.anno;
  return is;
}