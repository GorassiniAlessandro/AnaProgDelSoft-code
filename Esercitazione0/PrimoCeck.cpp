/*----------------------------------
file: PrimoCeck.cpp
autore: Alessandro Gorassini 168518
date: 09/10/2025
descr: Programma che chiede un numero intero e verifica se è primo o no.
------------------------------------*/

#include <iostream> 

using namespace std;

bool IsPrimo(int n);

int main() {
    int numero;

    cout << "Inserisci un numero intero: ";
    cin >> numero;
    if (IsPrimo(numero)) {
        cout << numero << " è un numero primo." << endl;
    }else{
        cout << numero << " non è un numero primo." << endl;
    }
    return 0;
}

bool IsPrimo(int n) 
{
    if (n <= 1) return false; // I numeri minori o uguali a 1 non sono primi
    for (int i = 2; i * i <= n; i++) { // Controlla fino alla radice quadrata di n
        if (n % i == 0) {
            return false; // n è divisibile per i, quindi non è primo
        }
    }
    return true; // n è primo
}
