#include "Studente.hpp"
#include <iomanip>

Studente::Studente(std::string n, std::string c)
    : nome(n), cognome(c) {}

std::string Studente::getNome() const {
    return nome;
}

std::string Studente::getCognome() const {
    return cognome;
}

std::vector<int> Studente::getVoti() const {
    return voti;
}

void Studente::addVoto(int voto) {
    if (voto >= 0 && voto <= 30) {
        voti.push_back(voto);
    } else {
        std::cerr << "Errore: voto non valido (deve essere tra 0 e 30)" << std::endl;
    }
}

void Studente::setVoti(const std::vector<int>& v) {
    voti = v;
}

double Studente::calcolaMedia() const {
    if (voti.empty()) {
        return 0.0;
    }
    
    int somma = 0;
    for (int voto : voti) {
        somma += voto;
    }
    return static_cast<double>(somma) / voti.size();
}

int Studente::getNumeroVoti() const {
    return voti.size();
}

std::istream& operator>>(std::istream& in, Studente& s) {
    std::cout << "Inserisci nome: ";
    in >> s.nome;
    std::cout << "Inserisci cognome: ";
    in >> s.cognome;
    
    std::cout << "Inserisci il numero di voti: ";
    int num_voti;
    in >> num_voti;
    
    s.voti.clear();
    for (int i = 0; i < num_voti; i++) {
        std::cout << "Voto " << (i + 1) << ": ";
        int voto;
        in >> voto;
        s.addVoto(voto);
    }
    
    return in;
}

std::ostream& operator<<(std::ostream& out, const Studente& s) {
    out << s.nome << " " << s.cognome;
    out << " | Voti: ";
    
    if (s.voti.empty()) {
        out << "Nessun voto";
    } else {
        for (int voto : s.voti) {
            out << voto << " ";
        }
        out << "| Media: " << std::fixed << std::setprecision(2) << s.calcolaMedia();
    }
    
    return out;
}
