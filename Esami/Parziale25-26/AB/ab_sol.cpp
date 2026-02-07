#include <iostream>
#include <stdexcept>
using namespace std;

class B 
{
  public:
    B(int k = 0) { x = k; }
    void Set(int k) { x = k; }
    int Get() const { return x; }
  private:
    int x;
};

class A 
{
  public:
    A(unsigned n, int init = 0);
    A(const A& a);
    A& operator=(const A& a); 
    ~A();
    int operator[](unsigned i) const;
    int operator()(unsigned i) const;
    void Set(unsigned i, int v);
  private:
    B* v1;
    int* v2;
    unsigned n;
};

A::A(unsigned k, int e) 
{
  n = k;
  if (n == 0) 
  {
    v1 = nullptr;
    v2 = nullptr;
  }
  else
  {
    v1 = new B[n];
    v2 = new int[n];
    for (unsigned i = 0; i < n; i++) 
	  {
      v1[i] = B(e);
      v2[i] = e * 2;
    }
  }
}

A::A(const A& a) 
{
	n = a.n;
  if (n == 0) 
	{
      v1 = nullptr; 
      v2 = nullptr; 
    }
	else
	{
       v1 = new B[n];
       v2 = new int[n];
       for (unsigned i = 0; i < n; i++) 
	     {
          v1[i] = a.v1[i];
          v2[i] = a.v2[i];
       }
	}
}

A& A::operator=(const A& a) 
{ 
  if (a.n == 0)
  { 
    if (n != 0)
    {
      delete[] v1;
      delete[] v2;
      v1 = nullptr;
      v2 = nullptr;
      n = 0;
    }
  }
  else 
  {
    if (n == 0)
    {
      v1 = new B[a.n];
      v2 = new int[a.n];
      n = a.n;
    }
    else if (n != a.n)
    {
      delete[] v1;
      delete[] v2;
      v1 = new B[a.n];
      v2 = new int[a.n];
      n = a.n;
    }
    for (unsigned i = 0; i < n; i++) 
    {
      v1[i] = a.v1[i];
      v2[i] = a.v2[i];
    }
  }
  return *this;
}

A::~A() 
{
  delete[] v1;
  delete[] v2;
}

int A::operator[](unsigned i) const 
{  return v1[i].Get() + v2[i]; }

int A::operator()(unsigned i) const 
{ return v1[i].Get() * v2[i]; }

void A::Set(unsigned i, int val) 
{  v1[i].Set(val); v2[i] = val * 3; }

int main() 
{   A a1(4, 2), a2(2); //, a3;
    a2.Set(1, 4);
    //a1[0] = 10;   
    cout << a1[0] << " " << a1(1) << " " << a2(1) << endl;
    A a4 = a1; 
    a4.Set(0, 3);
    cout << a1[0] << " " << a1(0) << endl;
    return 0;
}