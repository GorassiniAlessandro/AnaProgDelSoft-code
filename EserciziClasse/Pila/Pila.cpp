#include "Pila.hpp"

Pila::Pila()
{
  top = -1;
  dim = 100;
  vet = new int[dim];  
}

Pila::Pila(const Pila& p)
{
  top = p.top;
  dim = p.dim;
  vet = new int[dim];
  for (int i = 0; i <= top; i++)
    vet[i] = p.vet[i];	  
}

Pila::~Pila()
{
  cerr << "distruttore" << endl;
  delete[] vet;	
}

Pila& Pila::operator=(const Pila& p)
{
  if (dim <= p.top)
  {
	 delete[] vet;
     dim = p.dim;
     vet = new int[dim];	 
  }	  
  for (int i = 0; i <= p.top; i++)
    vet[i] = p.vet[i];	  
  top = p.top;
  return *this;
}

void Pila::Push(int e)
{
  if (top == dim-1)
  {
	int* aux_vet;
    aux_vet = new int[2*dim];
    for (int i = 0; i <= top; i++)
      aux_vet[i] = vet[i];
    delete[] vet;
    vet = aux_vet;
    dim *= 2;	
  }	  
  top++;
  vet[top] = e;  
}

void Pila::Pop()
{// TODO: inserire la precondizione
  top--;	
}

int Pila::Top() const
{
  return vet[top];	
}

bool Pila::IsEmpty() const
{
  return top == -1;	
}



ostream& operator<<(ostream& os, const Pila& p)
{
  os << "(";
  for (int i = 0; i < p.top; i++)
	os << p.vet[i] << ", ";
  if (p.top != -1)
	os << p.vet[p.top];
  os << ")";
  return os;
}

istream& operator>>(istream& is, Pila& p)
{
  char ch;
  int e;

  p.top = -1;
  is >> ch;  
  ch = is.peek();
  
  if (ch != ')')
  {
	do
	{
		is >> e >> ch;
		p.Push(e);
	}	
	while (ch != ')');
  }
  else
	is >> ch;
  return is;
}
