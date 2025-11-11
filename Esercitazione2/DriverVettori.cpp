/*----------------------------------
file: DriverVettori 
autore: Alessandro Gorassini 168518
date: 4/11/2025
descr: Driver program to test the Vettore class, demonstrating constructors, getters, and overloaded operators.
------------------------------------*/

#include "Vettori3D.hpp"
#include <iostream>

using namespace std;

int main() {
    cout << "=== Test Vettore ===" << endl;

    // Test costruttore di default
    Vettore v1;
    cout << "Vettore di default: " << v1 << endl;

    // Test costruttore con 2 parametri
    Vettore v2(1.0, 2.0);
    cout << "Vettore (1,2,0): " << v2 << endl;

    // Test costruttore con 3 parametri
    Vettore v3(3.0, 4.0, 5.0);
    cout << "Vettore (3,4,5): " << v3 << endl;

    // Test getters
    cout << "Componenti di v3: x=" << v3.getX() << ", y=" << v3.getY() << ", z=" << v3.getZ() << endl;

    // Test somma
    Vettore v4 = v2 + v3;
    cout << "Somma v2 + v3: " << v4 << endl;

    // Test prodotto vettoriale
    Vettore v5(1.0, 0.0, 0.0);
    Vettore v6(0.0, 1.0, 0.0);
    Vettore v7 = v5 * v6;
    cout << "Prodotto vettoriale v5 * v6: " << v7 << endl;

    // Test prodotto scalare (componente per componente)
    Vettore v8 = v2 & v3;
    cout << "Prodotto componente per componente v2 & v3: " << v8 << endl;

    // Test input da tastiera
    Vettore v9;
    cout << "Inserisci un vettore (x y z): ";
    cin >> v9;
    cout << "Vettore inserito: " << v9 << endl;

    cout << "=== Fine test ===" << endl;
    return 0;
}
