#ifndef CORRIERE_ESPRESSO_HPP
#define CORRIERE_ESPRESSO_HPP

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "Orario.hpp"

// ===== Struttura per coordinate geografiche =====
struct Coordinate {
    double latitudine;
    double longitudine;

    Coordinate(double lat = 0.0, double lon = 0.0);
};

// ===== Classe Consegna =====
class Consegna {
private:
    Coordinate luogoConsegna;
    double quantitaMerce;

public:
    Consegna(const Coordinate& luogo, double quantita);

    Coordinate getLuogo() const;
    double getQuantita() const;

    bool operator==(const Consegna& other) const;
};

// ===== Classe Automezzo =====
class Automezzo {
private:
    std::string targa;
    double capacita;

public:
    Automezzo(const std::string& t, double cap);

    std::string getTarga() const;
    double getCapacita() const;

    bool operator==(const Automezzo& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Automezzo& a);
};

// ===== Classe Viaggio =====
class Viaggio {
private:
    Automezzo automezzo;
    Orario oraPartenza;
    std::vector<Consegna> consegne;

public:
    Viaggio(const Automezzo& a, const Orario& ora, const Consegna& c);

    Automezzo getAutomezzo() const;
    Orario getOraPartenza() const;
    const std::vector<Consegna>& getConsegne() const;

    void aggiungiConsegna(const Consegna& c, int posizione);

    double getCaricototaleTonellate() const;
    int getNumeroConsegne() const;

    friend std::ostream& operator<<(std::ostream& out, const Viaggio& v);
};

// ===== Classe Corriere =====
class Corriere {
private:
    std::string nome;
    Coordinate depositoCoordinate;
    Orario oraApertura;
    std::vector<Automezzo> automezzi;
    std::vector<Consegna> consegne;
    std::vector<Viaggio> viaggi;

    // Metodi privati di supporto
    int trovaIndiceAutomezzo(const Automezzo& a) const;
    int trovaIndiceConsegna(const Consegna& c) const;
    int trovaIndiceViaggio(const Automezzo& a, const Orario& o) const;
    bool consegnaGiaInViaggio(const Consegna& c) const;

public:
    Corriere(const std::string& n, const Coordinate& dep, const Orario& apertura);

    std::string getNome() const;
    Coordinate getDeposito() const;
    Orario getOraApertura() const;
    int getNumeroAutomezzi() const;
    int getNumeroConsegne() const;
    int getNumeroViaggi() const;

    // Operazioni fondamentali
    void inserisciConsegna(const Consegna& c);
    void inserisciAutomezzo(const Automezzo& a);
    void creaViaggio(const Automezzo& a, const Orario& o, const Consegna& c);
    void inserisciInViaggio(const Automezzo& a, const Orario& o, const Consegna& c, int posizione);

    Orario orarioConsegna(const Consegna& c) const;

    // Selettori aggiuntivi
    const std::vector<Viaggio>& getViaggi() const;

    friend std::ostream& operator<<(std::ostream& out, const Corriere& cor);
};

// ===== Funzione esterna =====
// Restituisce la frazione (0.0 - 1.0) di consegne effettuate da un automezzo entro un orario
double frazioneconsegneEntroOrario(const Corriere& cor, const Automezzo& a, const Orario& orario);

// ===== Funzione esterna per calcolare tempo di percorso =====
// Riceve due coppie di coordinate e restituisce i minuti necessari per andare da un punto all'altro
int tempoPercorsoMinuti(const Coordinate& da, const Coordinate& a);

#endif
