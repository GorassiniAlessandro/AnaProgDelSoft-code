#include <iostream>
#include "StazioneSciistica.hpp"

int main() {
    try {
        StazioneSciistica stazione("MonteBianco");

        Impianto imp1("Alfa", TipoImpianto::Seggiovia, Orario(8, 0, 0), Orario(16, 0, 0), 1200);
        Impianto imp2("Beta", TipoImpianto::Funivia, Orario(8, 30, 0), Orario(17, 0, 0), 900);
        Impianto imp3("Gamma", TipoImpianto::Seggiovia, Orario(9, 0, 0), Orario(15, 30, 0), 800);

        stazione.aggiungiImpianto(imp1);
        stazione.aggiungiImpianto(imp2);
        stazione.aggiungiImpianto(imp3);

        Persona p1("A123");
        Persona p2("B456");

        stazione.registraPersona(p1, Orario(8, 0, 0), Orario(15, 0, 0));
        stazione.registraPersona(p2, Orario(9, 0, 0), Orario(16, 0, 0));

        stazione.inserisciIngresso("A123", "Alfa", Orario(9, 10, 0));
        stazione.inserisciIngresso("A123", "Beta", Orario(10, 0, 0));
        stazione.inserisciIngresso("A123", "Gamma", Orario(11, 5, 0));
        stazione.inserisciIngresso("A123", "Alfa", Orario(12, 30, 0));

        int risaliteAlfa = stazione.numeroRisalite("A123", "Alfa");
        std::cout << "Risalite su Alfa: " << risaliteAlfa << std::endl;

        std::string impPiuUsato = stazione.impiantoPiuUsato("A123");
        std::cout << "Impianto piu usato: " << impPiuUsato << std::endl;

        int minTempo = tempoMinimoTraSeggiovie(stazione, "A123");
        std::cout << "Tempo minimo tra seggiovie: " << minTempo << " secondi" << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Errore: " << e.what() << std::endl;
    }

    return 0;
}
