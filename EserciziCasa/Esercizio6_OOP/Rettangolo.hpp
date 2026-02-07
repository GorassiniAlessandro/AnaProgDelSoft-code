#ifndef RETTANGOLO_HPP
#define RETTANGOLO_HPP

#include <iostream>

class Rettangolo {
private:
    double base;
    double altezza;

public:
    // Costruttore parametrico
    Rettangolo(double b, double h);
    
    // Costruttore di default
    Rettangolo();
    
    // Getter
    double getBase() const;
    double getAltezza() const;
    
    // Setter
    void setBase(double b);
    void setAltezza(double h);
    
    // Metodi per calcoli
    double area() const;
    double perimetro() const;
    
    // Operatore di sovraccarico
    friend std::ostream& operator<<(std::ostream& out, const Rettangolo& r);
    friend std::istream& operator>>(std::istream& in, Rettangolo& r);
};

#endif
