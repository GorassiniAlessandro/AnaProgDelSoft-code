#include <iostream>
#include "CorrierEspresso.hpp"

int main() {
    try {
        // Creazione del corriere
        Coordinate deposito(45.4642, 9.1900);  // Milano
        Orario apertura(8, 0, 0);

        Corriere corriere("FastExpress", deposito, apertura);

        // Creazione automezzi
        Automezzo auto1("AB123CD", 1000.0);
        Automezzo auto2("XY456ZW", 1500.0);

        corriere.inserisciAutomezzo(auto1);
        corriere.inserisciAutomezzo(auto2);

        // Creazione consegne
        Coordinate loc1(45.4700, 9.1900);   // Cliente 1
        Coordinate loc2(45.4750, 9.2000);   // Cliente 2
        Coordinate loc3(45.4800, 9.2100);   // Cliente 3

        Consegna cons1(loc1, 150.0);
        Consegna cons2(loc2, 200.0);
        Consegna cons3(loc3, 100.0);

        corriere.inserisciConsegna(cons1);
        corriere.inserisciConsegna(cons2);
        corriere.inserisciConsegna(cons3);

        // Creazione viaggio
        Orario partenza(9, 0, 0);
        corriere.creaViaggio(auto1, partenza, cons1);

        // Inserimento consegne nel viaggio
        corriere.inserisciInViaggio(auto1, partenza, cons2, 1);
        corriere.inserisciInViaggio(auto1, partenza, cons3, 2);

        // Test operazioni
        std::cout << corriere << std::endl;

        int numConsegneAuto1 = 0;
        const std::vector<Viaggio>& viaggi = corriere.getViaggi();
        for (int i = 0; i < viaggi.size(); i++) {
            if (viaggi[i].getAutomezzo() == auto1) {
                numConsegneAuto1 += viaggi[i].getNumeroConsegne();
            }
        }
        std::cout << "Consegne auto1: " << numConsegneAuto1 << std::endl;

        Orario orarioTest(10, 30, 0);
        double frazione = frazioneconsegneEntroOrario(corriere, auto1, orarioTest);
        std::cout << "Frazione consegne entro le 10:30: " << frazione << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Errore: " << e.what() << std::endl;
    }

    return 0;
}
