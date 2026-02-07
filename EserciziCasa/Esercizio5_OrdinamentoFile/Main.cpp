#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::string inputFile = "input.txt";
    std::string outputFile = "sorted.txt";
    
    std::cout << "=== ORDINAMENTO E FILE ===" << std::endl << std::endl;
    
    // Apertura file di input
    std::ifstream infile(inputFile);
    if (!infile.is_open()) {
        std::cerr << "Errore: impossibile aprire il file " << inputFile << std::endl;
        return 1;
    }
    
    // Lettura del numero di interi
    int n;
    infile >> n;
    
    if (n <= 0) {
        std::cerr << "Errore: il primo valore deve essere positivo" << std::endl;
        infile.close();
        return 1;
    }
    
    std::cout << "Lettura da file: " << inputFile << std::endl;
    std::cout << "Numero di interi da ordinare: " << n << std::endl << std::endl;
    
    // Creazione vector e lettura dati
    std::vector<int> numeri;
    numeri.reserve(n);
    
    for (int i = 0; i < n; i++) {
        int valore;
        if (infile >> valore) {
            numeri.push_back(valore);
        } else {
            std::cerr << "Errore: impossibile leggere il valore " << (i + 1) << std::endl;
        }
    }
    infile.close();
    
    // Verifica lettura
    if (numeri.size() != static_cast<size_t>(n)) {
        std::cerr << "Errore: attesi " << n << " valori, letti " << numeri.size() << std::endl;
        return 1;
    }
    
    // Stampa valori originali
    std::cout << "Valori originali (primi 20):" << std::endl;
    int limit = (numeri.size() < 20) ? numeri.size() : 20;
    for (int i = 0; i < limit; i++) {
        std::cout << numeri[i] << " ";
    }
    if (numeri.size() > 20) {
        std::cout << "... (" << (numeri.size() - 20) << " altri)";
    }
    std::cout << std::endl << std::endl;
    
    // Ordinamento con std::sort
    std::cout << "Ordinamento in corso..." << std::endl;
    std::sort(numeri.begin(), numeri.end());
    std::cout << "Ordinamento completato!" << std::endl << std::endl;
    
    // Stampa valori ordinati
    std::cout << "Valori ordinati (primi 20):" << std::endl;
    limit = (numeri.size() < 20) ? numeri.size() : 20;
    for (int i = 0; i < limit; i++) {
        std::cout << numeri[i] << " ";
    }
    if (numeri.size() > 20) {
        std::cout << "... (" << (numeri.size() - 20) << " altri)";
    }
    std::cout << std::endl << std::endl;
    
    // Scrittura su file
    std::ofstream outfile(outputFile);
    if (!outfile.is_open()) {
        std::cerr << "Errore: impossibile creare il file " << outputFile << std::endl;
        return 1;
    }
    
    // Intestazione
    outfile << "NUMERI ORDINATI" << std::endl;
    outfile << "================" << std::endl;
    outfile << "Totale elementi: " << numeri.size() << std::endl;
    outfile << "Valore minimo: " << numeri.front() << std::endl;
    outfile << "Valore massimo: " << numeri.back() << std::endl;
    outfile << std::endl;
    
    // Dati ordinati (10 per riga)
    outfile << "Sequenza ordinata:" << std::endl;
    for (size_t i = 0; i < numeri.size(); i++) {
        outfile << numeri[i] << " ";
        if ((i + 1) % 10 == 0) {
            outfile << std::endl;
        }
    }
    if (numeri.size() % 10 != 0) {
        outfile << std::endl;
    }
    
    outfile.close();
    
    std::cout << "Dati ordinati scritti in: " << outputFile << std::endl;
    std::cout << "Programma completato con successo!" << std::endl;
    
    return 0;
}
