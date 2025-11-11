/*----------------------------------
file: DriverOrario.cpp
autore: Alessandro Gorassini 168518
date: 28/10/2025
descr: Driver program to test the Orario class, demonstrating initialization, getters, and adding seconds.
------------------------------------*/

#include <iostream>
#include "Orario.hpp"

using namespace std;

int main() {
    cout << "=== Test Orario ===" << endl;

    // Test 1: Orario corrente
    Orario corrente;
    cout << "Test 1: Orario corrente" << endl;
    cout << "Ora: " << corrente.getOre() << ":" << corrente.getMinuti() << ":" << corrente.getSecondi() << endl << endl;

    // Test 2: Orario personalizzato
    Orario custom(10, 30, 45);
    cout << "Test 2: Orario personalizzato (10:30:45)" << endl;
    cout << "Ora: " << custom.getOre() << ":" << custom.getMinuti() << ":" << custom.getSecondi() << endl << endl;

    // Test 3: Somma secondi
    custom.SommaSecondi(75); // Aggiunge 1 minuto e 15 secondi
    cout << "Test 3: Somma 75 secondi" << endl;
    cout << "Ora dopo somma: " << custom.getOre() << ":" << custom.getMinuti() << ":" << custom.getSecondi() << endl << endl;

    // Test 4: Somma secondi con rollover ore
    custom.SommaSecondi(3600); // Aggiunge 1 ora
    cout << "Test 4: Somma 3600 secondi (1 ora)" << endl;
    cout << "Ora dopo somma: " << custom.getOre() << ":" << custom.getMinuti() << ":" << custom.getSecondi() << endl << endl;

    cout << "=== Fine test ===" << endl;

    return 0;
}
