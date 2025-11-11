#include <iostream>
#include "ContoCorrente.hpp"

using namespace std;

int main() {
    cout << "=== Test ContoCorrente ===" << endl;

    // Test 1: Inizializzazione con tasso
    ContoCorrente conto(5.0); // Tasso interesse 5%
    cout << "Test 1: Inizializzazione" << endl;
    cout << "Saldo iniziale: " << conto.SaldoEuro() << " euro e " << conto.SaldoCentesimi() << " centesimi" << endl;
    cout << "Saldo in lire: " << conto.SaldoInLire() << endl;
    cout << "Tasso interesse: " << conto.TassoInteresse() << "%" << endl << endl;

    // Test 2: Deposito
    conto.DepositaEuro(100, 50);
    cout << "Test 2: Deposito di 100.50 euro" << endl;
    cout << "Saldo dopo deposito: " << conto.SaldoEuro() << " euro e " << conto.SaldoCentesimi() << " centesimi" << endl << endl;

    // Test 3: Aggiornamento interessi
    conto.AggiornaSaldo();
    cout << "Test 3: Aggiornamento interessi (5%)" << endl;
    cout << "Saldo dopo interessi: " << conto.SaldoEuro() << " euro e " << conto.SaldoCentesimi() << " centesimi" << endl << endl;

    // Test 4: Prelievo riuscito
    if (conto.PrelevaEuro(50, 25)) {
        cout << "Test 4: Prelievo di 50.25 euro riuscito" << endl;
        cout << "Saldo attuale: " << conto.SaldoEuro() << " euro e " << conto.SaldoCentesimi() << " centesimi" << endl << endl;
    } else {
        cout << "Test 4: Prelievo fallito: saldo insufficiente" << endl << endl;
    }

    // Test 5: Prelievo fallito (saldo insufficiente)
    if (conto.PrelevaEuro(100, 0)) {
        cout << "Test 5: Prelievo di 100.00 euro riuscito" << endl;
    } else {
        cout << "Test 5: Prelievo di 100.00 euro fallito: saldo insufficiente" << endl;
    }
    cout << "Saldo attuale: " << conto.SaldoEuro() << " euro e " << conto.SaldoCentesimi() << " centesimi" << endl << endl;

    // Test 6: Deposito con rollover centesimi
    conto.DepositaEuro(0, 80); // Aggiunge 80 centesimi, dovrebbe diventare 1 euro e 7 centesimi
    cout << "Test 6: Deposito di 0.80 euro (rollover centesimi)" << endl;
    cout << "Saldo dopo deposito: " << conto.SaldoEuro() << " euro e " << conto.SaldoCentesimi() << " centesimi" << endl << endl;

    // Test 7: Cambio tasso interesse
    conto.FissaTassoInteresse(10.0);
    cout << "Test 7: Cambio tasso interesse a 10%" << endl;
    cout << "Nuovo tasso: " << conto.TassoInteresse() << "%" << endl;

    conto.AggiornaSaldo();
    cout << "Saldo dopo interessi al 10%: " << conto.SaldoEuro() << " euro e " << conto.SaldoCentesimi() << " centesimi" << endl << endl;

    // Test 8: Secondo conto senza tasso iniziale
    ContoCorrente conto2;
    cout << "Test 8: Secondo conto senza tasso iniziale" << endl;
    cout << "Saldo iniziale conto2: " << conto2.SaldoEuro() << " euro e " << conto2.SaldoCentesimi() << " centesimi" << endl;
    conto2.FissaTassoInteresse(3.0);
    conto2.DepositaEuro(50, 0);
    conto2.AggiornaSaldo();
    cout << "Dopo deposito 50.00 e interessi 3%: " << conto2.SaldoEuro() << " euro e " << conto2.SaldoCentesimi() << " centesimi" << endl << endl;

    cout << "=== Fine test ===" << endl;

    return 0;
}
