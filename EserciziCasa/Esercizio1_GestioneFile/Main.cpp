#include <iostream>
#include <fstream>
#include <vector>
#include "Persona.hpp"

int main() {
    std::vector<Persona> persone;
    std::string inputFile = "input.txt";
    std::string outputFile = "output.txt";
    
    // Leggi il file di input
    std::ifstream infile(inputFile);
    if (!infile.is_open()) {
        std::cerr << "Errore: non riesco ad aprire il file " << inputFile << std::endl;
        return 1;
    }
    
    Persona p;
    while (infile >> p) {
        persone.push_back(p);
    }
    infile.close();
    
    // Conta i maggiorenni e scrivi su file
    std::ofstream outfile(outputFile);
    if (!outfile.is_open()) {
        std::cerr << "Errore: non riesco ad aprire il file " << outputFile << std::endl;
        return 1;
    }
    
    int conteggio_maggiorenni = 0;
    for (const auto& persona : persone) {
        if (persona.getEta() >= 18) {
            outfile << persona << std::endl;
            conteggio_maggiorenni++;
        }
    }
    outfile.close();
    
    // Stampa il risultato
    std::cout << "Numero di persone maggiorenni: " << conteggio_maggiorenni << std::endl;
    std::cout << "Dati scritti nel file: " << outputFile << std::endl;
    
    return 0;
}
