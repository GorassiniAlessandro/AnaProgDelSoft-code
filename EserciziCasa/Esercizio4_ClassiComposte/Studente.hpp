#ifndef STUDENTE_HPP
#define STUDENTE_HPP

#include <string>
#include <vector>
#include <iostream>

class Studente {
private:
    std::string nome;
    std::string cognome;
    std::vector<int> voti;

public:
    // Costruttore
    Studente(std::string n = "", std::string c = "");
    
    // Getter
    std::string getNome() const;
    std::string getCognome() const;
    std::vector<int> getVoti() const;
    
    // Setter
    void addVoto(int voto);
    void setVoti(const std::vector<int>& v);
    
    // Metodi utili
    double calcolaMedia() const;
    int getNumeroVoti() const;
    
    // Operatori sovraccaricati
    friend std::istream& operator>>(std::istream& in, Studente& s);
    friend std::ostream& operator<<(std::ostream& out, const Studente& s);
};

#endif
