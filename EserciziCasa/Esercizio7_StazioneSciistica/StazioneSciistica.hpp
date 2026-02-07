#ifndef STAZIONE_SCIISTICA_HPP
#define STAZIONE_SCIISTICA_HPP

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

#include "Orario.hpp"
#include "Persona.hpp"

enum class TipoImpianto {
    Seggiovia,
    Funivia,
    Bidonvia,
    Sciovia
};

class Impianto {
private:
    std::string nome;
    TipoImpianto tipo;
    Orario apertura;
    Orario chiusura;
    int capacitaPersoneOra;

public:
    Impianto(const std::string& n, TipoImpianto t, const Orario& a, const Orario& c, int cap);

    std::string getNome() const;
    TipoImpianto getTipo() const;
    Orario getApertura() const;
    Orario getChiusura() const;
    int getCapacitaPersoneOra() const;

    friend std::ostream& operator<<(std::ostream& out, const Impianto& i);
};

struct Ingresso {
    std::string nomeImpianto;
    Orario orario;
};

class StazioneSciistica {
private:
    struct RegistroPersona {
        Persona persona;
        Orario inizioAccesso;
        Orario fineAccesso;
        std::vector<Ingresso> ingressi;
    };

    std::string nome;
    std::vector<Impianto> impianti;
    std::vector<RegistroPersona> persone;

    bool haUltimoIngresso;
    Orario ultimoIngresso;

    int trovaIndiceImpianto(const std::string& nomeImpianto) const;
    int trovaIndicePersona(const std::string& codice) const;

public:
    StazioneSciistica(const std::string& n);

    std::string getNome() const;
    int getNumeroImpianti() const;
    int getNumeroPersone() const;

    void aggiungiImpianto(const Impianto& i);
    void registraPersona(const Persona& p, const Orario& inizio, const Orario& fine);
    void inserisciIngresso(const std::string& codicePersona, const std::string& nomeImpianto, const Orario& orario);

    int numeroRisalite(const std::string& codicePersona, const std::string& nomeImpianto) const;
    std::string impiantoPiuUsato(const std::string& codicePersona) const;

    void cancellaRegistrazioniScadute(const Orario& orario);

    const std::vector<Impianto>& getImpianti() const;
    const std::vector<RegistroPersona>& getPersone() const;

    friend std::ostream& operator<<(std::ostream& out, const StazioneSciistica& s);
};

int tempoMinimoTraSeggiovie(const StazioneSciistica& s, const std::string& codicePersona);

#endif
