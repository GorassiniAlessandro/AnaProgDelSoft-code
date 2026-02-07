#include "Rettangolo.hpp"

// Costruttore parametrico
Rettangolo::Rettangolo(double b, double h) : base(b), altezza(h) {
    if (base < 0) base = 0;
    if (altezza < 0) altezza = 0;
}

// Costruttore di default
Rettangolo::Rettangolo() : base(0), altezza(0) {}

// Getter
double Rettangolo::getBase() const {
    return base;
}

double Rettangolo::getAltezza() const {
    return altezza;
}

// Setter
void Rettangolo::setBase(double b) {
    if (b >= 0) {
        base = b;
    }
}

void Rettangolo::setAltezza(double h) {
    if (h >= 0) {
        altezza = h;
    }
}

// Metodo area
double Rettangolo::area() const {
    return base * altezza;
}

// Metodo perimetro
double Rettangolo::perimetro() const {
    return 2 * (base + altezza);
}

// Operatore <<
std::ostream& operator<<(std::ostream& out, const Rettangolo& r) {
    out << "Rettangolo [Base: " << r.base << ", Altezza: " << r.altezza 
        << "] -> Area: " << r.area() << ", Perimetro: " << r.perimetro();
    return out;
}

// Operatore >>
std::istream& operator>>(std::istream& in, Rettangolo& r) {
    in >> r.base >> r.altezza;
    if (r.base < 0) r.base = 0;
    if (r.altezza < 0) r.altezza = 0;
    return in;
}
