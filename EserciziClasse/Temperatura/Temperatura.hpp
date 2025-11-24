/*----------------------------------
file: Temperatura.hpp
autore: Alessandro Gorassini 168518
date: 13/11/2025
descr:
------------------------------------*/

class B
{
private:
    int num;
public:
    B(int n) {num = n;}
    void Set(int n) {num = n;}
    char Get() const {return num;}
};

class A
{
private:
    B* p1;
    B* p2;
public:
    A(int v = 0) { p1 = new B(v); p2 = p1; };
    void Set1 (int v) { p1->Set(v); }
    void Set3 (int v) { p2->Set(v); }
    void Flip() { if( p1 == p2 ) p2 = new B(p1->Get()); else {delete p2; p2 = p1;}}
};

