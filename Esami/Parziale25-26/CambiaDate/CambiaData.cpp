// File Driver.cpp
#include <iostream>
#include <fstream>
#include "Data.hpp"

using namespace std;

void CambiaDate(string nome_file_input, string nome_file_output, int spostamento);

int main(int argc, char* argv[])
{
  if (argc != 4)
    throw invalid_argument("Numero dei parametri sbagliato");
  CambiaDate(argv[1], argv[2], atoi(argv[3]));
  return 0;
}

void CambiaDate(string nome_file_input, string nome_file_output, int s)
{
  ifstream is(nome_file_input);
  ofstream os(nome_file_output);
  Data d;
  char ch;

  while ((ch = is.peek()) != EOF)
  {
    if (isdigit(ch))
    {
      is >> d;
      d += s;
      os << d;
    }
    else
    {
      ch = is.get();
      os << ch;
    }
  }
  is.close();
  os.close();
}