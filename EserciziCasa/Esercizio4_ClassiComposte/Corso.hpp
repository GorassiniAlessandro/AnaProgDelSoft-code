#ifndef CORSO_HPP
#define CORSO_HPP

#include <string>
#include <vector>
#include <iostream>
#include "Studente.hpp"

class Corso {
private:
    std::string nome;
    std::vector<Studente> studenti;

public:
    // Costruttore
    Corso(std::string n = "");
    
    // Getter
    std::string getNome() const;
    std::vector<Studente> getStudenti() const;
    int getNumeroStudenti() const;
    
    // Metodi principali
    void aggiungiStudente(const Studente& s);
    void scriviSuFile(const std::string& filename) const;
    void leggiDaFile(const std::string& filename);
    
    // Metodi utility
    void stampaStudenti() const;
    double calcolaMediaCorso() const;
    
    // Operatore sovraccaricato
    friend std::ostream& operator<<(std::ostream& out, const Corso& c);
};

#endif
