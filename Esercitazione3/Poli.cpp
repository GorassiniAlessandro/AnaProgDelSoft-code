/*----------------------------------
file: Poli.cpp
autore: Alessandro Gorassini 168518
date: 18/11/2025
descr:Contenuto della classe Poli
------------------------------------*/

#include <iostream>
#include <cmath>
#include <ostream>
#include <istream>
#include "Poli.hpp"

Poli::Poli() {
    grado = 0;
    coeff = new double[1];
    coeff[0] = 0.0;
}

Poli::Poli(double cof, int esp) {
    grado = esp;
    coeff = new double[grado + 1];
    for (int i = 0; i < grado; ++i) {
        coeff[i] = 0.0;
    }
    coeff[grado] = cof;
}

Poli::Poli(const Poli& p) {
    grado = p.grado;
    coeff = new double[grado + 1];
    for (int i = 0; i <= grado; ++i) {
        coeff[i] = p.coeff[i];
    }
}

double Poli::GetCoeff(int i) const {
    if (i < 0 || i > grado) {
        return 0.0;
    }
    return coeff[i];
}

int Poli::GetGrado() const {
    return grado;
}

Poli operator+(const Poli& p1, const Poli& p2) {
    int maxGrado = std::max(p1.grado, p2.grado);
    Poli result;
    delete[] result.coeff;
    result.grado = maxGrado;
    result.coeff = new double[maxGrado + 1];
    for (int i = 0; i <= maxGrado; ++i) {
        double c1 = (i <= p1.grado) ? p1.coeff[i] : 0.0;
        double c2 = (i <= p2.grado) ? p2.coeff[i] : 0.0;
        result.coeff[i] = c1 + c2;
    }
    // riduci grado se coefficienti più alti sono nulli
    int actual = maxGrado;
    while (actual > 0 && std::fabs(result.coeff[actual]) < 1e-12) --actual;
    result.grado = actual;
    return result;
}

Poli operator-(const Poli& p1, const Poli& p2) {
    int maxGrado = std::max(p1.grado, p2.grado);
    Poli result;
    delete[] result.coeff;
    result.grado = maxGrado;
    result.coeff = new double[maxGrado + 1];
    for (int i = 0; i <= maxGrado; ++i) {
        double c1 = (i <= p1.grado) ? p1.coeff[i] : 0.0;
        double c2 = (i <= p2.grado) ? p2.coeff[i] : 0.0;
        result.coeff[i] = c1 - c2;
    }
    int actual = maxGrado;
    while (actual > 0 && std::fabs(result.coeff[actual]) < 1e-12) --actual;
    result.grado = actual;
    return result;
}

std::ostream& operator<<(std::ostream& os, const Poli& p) {
    bool primo = true;
    for (int i = p.grado; i >= 0; --i) {
        double c = p.coeff[i];
        if (std::fabs(c) < 1e-12) continue;
        if (!primo) {
            os << (c > 0 ? " + " : " - ");
        } else if (c < 0) {
            os << "-";
        }
        double absval = std::fabs(c);
        if (i == 0) {
            os << absval;
        } else {
            if (absval != 1.0) os << absval;
            os << "x";
            if (i > 1) os << "^" << i;
        }
        primo = false;
    }
    if (primo) os << "0";
    return os;
}

std::istream& operator>>(std::istream& is, Poli& p) {
    int g;
    std::cout << "Inserisci il grado del polinomio: ";
    if (!(is >> g)) return is;
    if (g < 0) g = 0;
    delete[] p.coeff;
    p.grado = g;
    p.coeff = new double[p.grado + 1];
    std::cout << "Inserisci i coefficienti da x^0 a x^" << p.grado << ":\n";
    for (int i = 0; i <= p.grado; ++i) {
        std::cout << "coeff[" << i << "]: ";
        if (!(is >> p.coeff[i])) p.coeff[i] = 0.0;
    }
    return is;
}

Poli& Poli::operator=(const Poli& p) {
    if (this == &p) return *this;
    delete[] coeff;
    grado = p.grado;
    coeff = new double[grado + 1];
    for (int i = 0; i <= grado; ++i) {
        coeff[i] = p.coeff[i];
    }
    return *this;
}

double Poli::operator()(double x) const
{
    double result = 0.0;
    for (int i = 0; i<= grado; ++i)
    {
        result += coeff[i] * std::pow(x, i);
    }
    return result;
}