/*----------------------------------
file: DreverPoli.cpp
autore: Alessandro Gorassini 168518
date: 18/11/2025
descr:Test driver che mi permette di verificare il corretto funzionamento della classe Poli
------------------------------------*/


#include <iostream>
#include "Poli.hpp"
using namespace std;

void testInterferenza() {
    cout << "\n================= TEST INTERFERENZA =================\n";

    Poli p1;
    cout << "Inserisci un polinomio P1:\n";
    cin >> p1;

    // Creo una copia usando costruttore di copia
    Poli p2(p1);

    cout << "\nCopia effettuata: P2 = P1\n";
    cout << "P1 = " << p1 << endl;
    cout << "P2 = " << p2 << endl;

    cout << "\nModifico un coefficiente di P2 (interferenza test)...\n";
    p2 = p2 - Poli(10.0, 0); // modifica del termine noto

    cout << "\nDopo la modifica:\n";
    cout << "P1 = " << p1 << "  (NON deve cambiare!)\n";
    cout << "P2 = " << p2 << "  (DEVE cambiare!)\n";

    cout << "\n>>> Se P1 è rimasto invariato, NON c'è interferenza 👍\n";
}

int main() {
    cout << "================= TEST CLASSE POLINOMIO =================\n";

    // Test inserimento
    Poli p1, p2;
    cout << "Inserisci P1:\n";
    cin >> p1;
    cout << "\nInserisci P2:\n";
    cin >> p2;

    // Test stampa
    cout << "\n----- Stampa dei polinomi -----\n";
    cout << "P1 = " << p1 << endl;
    cout << "P2 = " << p2 << endl;

    // Test operatore +
    Poli somma = p1 + p2;
    cout << "\nP1 + P2 = " << somma << endl;

    // Test operatore -
    Poli diff = p1 - p2;
    cout << "P1 - P2 = " << diff << endl;

    // Test valutazione ()
    double x;
    cout << "\nInserisci un valore reale per x: ";
    cin >> x;
    cout << "P1(" << x << ") = " << p1(x) << endl;
    cout << "P2(" << x << ") = " << p2(x) << endl;

    // Test operatore assegnazione
    cout << "\n----- Test assegnazione -----\n";
    Poli p3;
    p3 = p1;  // test dell’operatore =
    cout << "Assegno P3 = P1\n";
    cout << "P3 = " << p3 << endl;

    cout << "\nModifico P3...\n";
     p3 = p3 - Poli(5.0, 0);
    cout << "P1 = " << p1 << " (NON deve cambiare!)\n";
    cout << "P3 = " << p3 << " (DEVE cambiare!)\n";

    cout << "\n>>> Se P1 non cambia, l'assegnazione non provoca interferenza 👍\n";

    // Test completo con costruttore di copia
    testInterferenza();

    cout << "\n================= FINE TEST =================\n";
    return 0;
}