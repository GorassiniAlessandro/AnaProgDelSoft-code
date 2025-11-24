// File data.hpp
#ifndef DATA_HPP
#define DATA_HPP
using namespace std;

class Data
{
 public:
  Data(unsigned g, unsigned m, unsigned a);
  Data();
  unsigned Giorno() const { return giorno; }
  unsigned Mese() const { return mese; }
  unsigned Anno() const { return anno; }
  void DataSuccessiva();
  void DataPrecedente();
  void SommaGiorni(int n);
  void Stampa() const;
  const unsigned GIORNO_ZERO = 1;
  const unsigned MESE_ZERO = 1;
  const unsigned ANNO_ZERO = 1970;
 private:
  unsigned giorno;
  unsigned mese;
  unsigned anno;
  bool Valida() const;
  bool Bisestile() const;
  unsigned GiorniDelMese() const;
};
#endif