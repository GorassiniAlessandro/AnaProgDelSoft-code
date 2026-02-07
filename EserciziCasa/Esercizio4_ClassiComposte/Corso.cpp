#include "Corso.hpp"
#include <fstream>
#include <iomanip>

Corso::Corso(std::string n) : nome(n) {}

std::string Corso::getNome() const {
    return nome;
}

std::vector<Studente> Corso::getStudenti() const {
    return studenti;
}

int Corso::getNumeroStudenti() const {
    return studenti.size();
}

void Corso::aggiungiStudente(const Studente& s) {
    studenti.push_back(s);
}

void Corso::scriviSuFile(const std::string& filename) const {
    std::ofstream outfile(filename);
    
    if (!outfile.is_open()) {
        std::cerr << "Errore: impossibile aprire il file " << filename << std::endl;
        return;
    }
    
    // Intestazione
    outfile << "============================================" << std::endl;
    outfile << "CORSO: " << nome << std::endl;
    outfile << "============================================" << std::endl;
    outfile << "Numero di studenti iscritti: " << studenti.size() << std::endl;
    outfile << std::endl;
    
    if (studenti.empty()) {
        outfile << "Nessuno studente iscritto." << std::endl;
    } else {
        // Intestazione tabella
        outfile << std::setw(20) << std::left << "NOME"
                << std::setw(20) << std::left << "COGNOME"
                << std::setw(15) << std::right << "NUM. VOTI"
                << std::setw(15) << std::right << "MEDIA"
                << std::endl;
        outfile << "---------------------------------------------------------------------------" << std::endl;
        
        // Dati studenti
        for (const auto& studente : studenti) {
            outfile << std::setw(20) << std::left << studente.getNome()
                    << std::setw(20) << std::left << studente.getCognome()
                    << std::setw(15) << std::right << studente.getNumeroVoti()
                    << std::setw(15) << std::right << std::fixed << std::setprecision(2) 
                    << studente.calcolaMedia() << std::endl;
            
            // Dettagli voti
            outfile << "   Voti: ";
            for (int voto : studente.getVoti()) {
                outfile << voto << " ";
            }
            outfile << std::endl;
        }
    }
    
    // Statistiche finali
    outfile << std::endl;
    outfile << "============================================" << std::endl;
    outfile << "STATISTICHE CORSO" << std::endl;
    outfile << "============================================" << std::endl;
    outfile << "Media del corso: " << std::fixed << std::setprecision(2) 
            << calcolaMediaCorso() << std::endl;
    
    outfile.close();
    std::cout << "Dati scritti con successo nel file: " << filename << std::endl;
}

void Corso::leggiDaFile(const std::string& filename) {
    std::ifstream infile(filename);
    
    if (!infile.is_open()) {
        std::cerr << "Errore: impossibile aprire il file " << filename << std::endl;
        return;
    }
    
    // Semplice lettura (nota: questo è un esempio base)
    // In un'applicazione reale, si userebbe un formato strutturato
    
    infile.close();
}

void Corso::stampaStudenti() const {
    std::cout << "\n=== CORSO: " << nome << " ===" << std::endl;
    std::cout << "Numero studenti: " << studenti.size() << std::endl << std::endl;
    
    if (studenti.empty()) {
        std::cout << "Nessuno studente iscritto." << std::endl;
    } else {
        for (size_t i = 0; i < studenti.size(); i++) {
            std::cout << (i + 1) << ". " << studenti[i] << std::endl;
        }
    }
    std::cout << std::endl;
}

double Corso::calcolaMediaCorso() const {
    if (studenti.empty()) {
        return 0.0;
    }
    
    double somma_medie = 0.0;
    for (const auto& studente : studenti) {
        somma_medie += studente.calcolaMedia();
    }
    
    return somma_medie / studenti.size();
}

std::ostream& operator<<(std::ostream& out, const Corso& c) {
    out << "Corso: " << c.nome << " | Studenti: " << c.studenti.size();
    return out;
}
