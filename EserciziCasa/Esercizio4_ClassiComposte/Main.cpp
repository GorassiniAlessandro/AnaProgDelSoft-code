#include <iostream>
#include "Corso.hpp"

int main() {
    // Creazione del corso
    Corso corso("Programmazione C++");
    
    std::cout << "=== GESTIONE CORSO ===" << std::endl << std::endl;
    
    // Creazione e aggiunta di studenti
    std::cout << "--- Aggiunta studenti ---" << std::endl << std::endl;
    
    // Studente 1
    Studente s1;
    std::cin >> s1;
    corso.aggiungiStudente(s1);
    
    // Domanda se aggiungere altri studenti
    char continua = 'S';
    while (continua == 'S' || continua == 's') {
        Studente s_temp;
        std::cin >> s_temp;
        corso.aggiungiStudente(s_temp);
        
        std::cout << "\nAggiungere un altro studente? (S/N): ";
        std::cin >> continua;
        std::cout << std::endl;
    }
    
    // Stampa a video
    std::cout << "\n";
    corso.stampaStudenti();
    
    // Scrivi su file
    std::string filename = "corso_output.txt";
    corso.scriviSuFile(filename);
    
    std::cout << "\nProgramma terminato!" << std::endl;
    
    return 0;
}
