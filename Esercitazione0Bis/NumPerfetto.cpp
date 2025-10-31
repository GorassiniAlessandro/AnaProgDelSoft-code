/*----------------------------------
file: NumPerfetto.cpp
autore: Alessandro Gorassini 168518
date: 10/10/2025
descr: Programma che verifica se un numero è perfetto e stampa i numeri perfetti tra 1 e 10000.
------------------------------------*/
#include <iostream>

using namespace std;

bool isPerfect(int n) {
    if (n <= 0) return false;
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

void printPerfectNumbers(int start, int end) {
    cout << "Numeri perfetti tra " << start << " e " << end << ":" << endl;
    for (int i = start; i <= end; i++) {
        if (isPerfect(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    printPerfectNumbers(1, 10000);
    return 0;
}
