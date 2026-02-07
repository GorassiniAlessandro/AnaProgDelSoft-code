#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <string>
#include <iostream>

class Persona {
private:
    std::string nome;
    std::string cognome;
    int eta;

public:
    // Costruttore
    Persona(std::string n = "", std::string c = "", int e = 0);
    
    // Getter
    std::string getNome() const;
    std::string getCognome() const;
    int getEta() const;
    
    // Operatori di sovraccarico
    friend std::istream& operator>>(std::istream& in, Persona& p);
    friend std::ostream& operator<<(std::ostream& out, const Persona& p);
};

#endif
