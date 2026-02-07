#include <iostream>
#include "Stack.hpp"

int main() {
    Stack<int> pila;
    int n, valore;
    
    std::cout << "=== Stack (Pila) ===" << std::endl;
    std::cout << "Inserisci il numero di elementi: ";
    std::cin >> n;
    
    // Validazione input
    if (n <= 0) {
        std::cerr << "Errore: inserisci un numero positivo" << std::endl;
        return 1;
    }
    
    // Leggi gli elementi e inseriscili nella pila
    std::cout << "Inserisci " << n << " numeri:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Elemento " << (i + 1) << ": ";
        std::cin >> valore;
        pila.push(valore);
    }
    
    // Stampa la pila in ordine inverso (LIFO - Last In First Out)
    std::cout << "\nElementi della pila in ordine inverso (LIFO):" << std::endl;
    int posizione = 1;
    while (!pila.empty()) {
        std::cout << posizione << ". " << pila.pop() << std::endl;
        posizione++;
    }
    
    std::cout << "\nPila vuota. Dimensione: " << pila.size() << std::endl;
    
    return 0;
}
