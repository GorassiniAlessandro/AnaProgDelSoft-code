/*----------------------------------
file: CalcoloNewton.cpp
autore: Alessandro Gorassini 168518
date: 10/10/2025
descr:Funzione che calcola la radice quadrata di un numero reale positivo utilizzando il metodo iterativo di Newton.
      La sequenza viene interrotta quando la differenza tra x(k+1) e x(k) è minore di epsilon.
------------------------------------*/
#include <iostream>
#include <cmath>

using namespace std;

// descr: Funzione che calcola la radice quadrata di un numero reale positivo utilizzando il metodo iterativo di Newton.
// La sequenza viene interrotta quando la differenza tra x(k+1) e x(k) è minore di epsilon.
double sqrt_newton(double a, double eps) {
    if (a < 0) {
        cout << "Errore: numero negativo" << endl;
        return -1.0;
    }
    double x = a / 2.0; // stima iniziale
    double next_x;
    do {
        next_x = (x + a / x) / 2.0;
        if (fabs(next_x - x) < eps) break;
        x = next_x;
    } while (true);
    return next_x;
}

int main() {
    double num, eps;
    cout << "Inserisci il numero positivo: ";
    cin >> num;
    cout << "Inserisci epsilon: ";
    cin >> eps;

    double my_sqrt = sqrt_newton(num, eps);
    double lib_sqrt = sqrt(num);

    cout << "Radice quadrata calcolata: " << my_sqrt << endl;
    cout << "Radice quadrata libreria: " << lib_sqrt << endl;
    cout << "Differenza: " << fabs(my_sqrt - lib_sqrt) << endl;

    return 0;
}
