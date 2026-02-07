#include <iostream>
#include <fstream>
#include <vector>
#include "Rettangolo.hpp"

int main() {
    // Nome del file di input contenente i dati dei rettangoli
    std::string inputFile = "rettangoli.txt";
    
    std::cout << "=== GESTIONE RETTANGOLI ===" << std::endl << std::endl;
    
    // Apertura del file di input in modalità lettura
    std::ifstream infile(inputFile);
    
    // Controllo se il file è stato aperto correttamente
    if (!infile.is_open()) {
        std::cerr << "Errore: impossibile aprire il file " << inputFile << std::endl;
        return 1;  // Termina il programma con codice di errore
    }
    
    // Lettura del primo valore: il numero di rettangoli nel file
    int n;
    infile >> n;
    
    // Validazione: il numero deve essere positivo
    if (n <= 0) {
        std::cerr << "Errore: il numero di rettangoli deve essere positivo" << std::endl;
        infile.close();
        return 1;
    }
    
    std::cout << "Lettura di " << n << " rettangoli da file..." << std::endl << std::endl;
    
    // Creazione di un vettore dinamico per memorizzare tutti i rettangoli
    // Il vettore crescerà automaticamente secondo necessità
    std::vector<Rettangolo> rettangoli;
    
    // Ciclo per leggere n rettangoli dal file
    for (int i = 0; i < n; i++) {
        // Creazione di un oggetto Rettangolo temporaneo
        Rettangolo r;
        
        // Lettura dei dati usando l'operatore >> sovraccaricato
        if (infile >> r) {
            // Se la lettura ha successo, aggiungi il rettangolo al vettore
            rettangoli.push_back(r);
        } else {
            // Gestione errore di lettura
            std::cerr << "Errore nella lettura del rettangolo " << (i + 1) << std::endl;
        }
    }
    
    // Chiusura del file dopo aver terminato la lettura
    infile.close();
    
    // Verifica che il numero di rettangoli letti corrisponda a quello atteso
    if (rettangoli.size() != n) {
        std::cerr << "Attenzione: letti " << rettangoli.size() << " rettangoli su " << n << std::endl;
    }
    
    // Stampa di tutti i rettangoli letti usando l'operatore << sovraccaricato
    std::cout << "=== RETTANGOLI LETTI ===" << std::endl;
    for (int i = 0; i < rettangoli.size(); i++) {
        // L'operatore << stampa automaticamente base, altezza, area e perimetro
        std::cout << (i + 1) << ". " << rettangoli[i] << std::endl;
    }
    std::cout << std::endl;
    
    // Calcolo delle statistiche sui rettangoli
    if (!rettangoli.empty()) {
        // Variabili per accumulare i totali
        double area_totale = 0;
        double perimetro_totale = 0;
        
        // Variabili per tracciare il massimo e minimo
        // Inizializzate con i valori del primo rettangolo
        double area_max = rettangoli[0].area();
        double area_min = rettangoli[0].area();
        int indice_max = 0;  // Posizione del rettangolo con area massima
        int indice_min = 0;  // Posizione del rettangolo con area minima
        
        // Ciclo per calcolare tutte le statistiche in un solo passaggio
        for (int i = 0; i < rettangoli.size(); i++) {
            // Calcolo area e perimetro del rettangolo corrente
            double a = rettangoli[i].area();
            double p = rettangoli[i].perimetro();
            
            // Accumulo dei totali
            area_totale += a;
            perimetro_totale += p;
            
            // Controllo se l'area corrente è la massima finora
            if (a > area_max) {
                area_max = a;
                indice_max = i;
            }
            
            // Controllo se l'area corrente è la minima finora
            if (a < area_min) {
                area_min = a;
                indice_min = i;
            }
        }
        
        // Stampa delle statistiche generali
        std::cout << "=== STATISTICHE ===" << std::endl;
        std::cout << "Numero di rettangoli: " << rettangoli.size() << std::endl;
        std::cout << "Area totale: " << area_totale << std::endl;
        std::cout << "Perimetro totale: " << perimetro_totale << std::endl;
        
        // Calcolo e stampa della media delle aree
        std::cout << "Area media: " << (area_totale / rettangoli.size()) << std::endl;
        std::cout << std::endl;
        
        // Stampa del rettangolo con area massima
        std::cout << "Rettangolo con area massima (" << area_max << "):" << std::endl;
        std::cout << "  " << rettangoli[indice_max] << std::endl;
        std::cout << std::endl;
        
        // Stampa del rettangolo con area minima
        std::cout << "Rettangolo con area minima (" << area_min << "):" << std::endl;
        std::cout << "  " << rettangoli[indice_min] << std::endl;
    }
    
    // Messaggio finale
    std::cout << std::endl << "Programma completato!" << std::endl;
    
    return 0;  // Termina con successo
}
