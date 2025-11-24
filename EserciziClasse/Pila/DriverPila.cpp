#include "Pila.hpp"

void F(Pila p)
{
  p.Pop();	
}


int main()
{
  Pila p1;
  
  p1.Push(25);
  p1.Push(-8);
   
  Pila p2 = p1;  // Costruttore di copia
   
  F(p1);
  
  cout << p1 << "  " << p2 << endl;
  
  p2.Pop();
  cout << p1 << "  " << p2 << endl;

  p2.Push(12);  // interferenza
    
  cout << p1 << "  " << p2 << endl;  
  
  return 0;
}

// int main()
// {
  // Pila p1, p2;
  
  // p1.Push(25);
  // p1.Push(-8);
  // p2 = p1;  // condivisione di memoria
  // cout << p1 << "  " << p2 << endl;
  
  // p2.Pop();
  // cout << p1 << "  " << p2 << endl;

  // p2.Push(12);  // interferenza
  
  // (p1 = p2).Push(23);
  
  // cout << p1 << "  " << p2 << endl;
  // return 0;
// }