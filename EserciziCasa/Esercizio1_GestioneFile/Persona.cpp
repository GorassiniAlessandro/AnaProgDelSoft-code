#include "Persona.hpp"

Persona::Persona(std::string n, std::string c, int e)
    : nome(n), cognome(c), eta(e) {}

std::string Persona::getNome() const {
    return nome;
}

std::string Persona::getCognome() const {
    return cognome;
}

int Persona::getEta() const {
    return eta;
}

std::istream& operator>>(std::istream& in, Persona& p) {
    in >> p.nome >> p.cognome >> p.eta;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Persona& p) {
    out << p.nome << " " << p.cognome << " " << p.eta;
    return out;
}
