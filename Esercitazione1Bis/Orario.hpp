/*----------------------------------
file: Orario.hpp
autore: Alessandro Gorassini 168518
date: 28/10/2025
descr: Header file for the Orario class, defining a time class with methods for managing hours, minutes, seconds, and adding seconds.
------------------------------------*/

#ifndef ORARIO_HPP
#define ORARIO_HPP

#include <iostream>
#include <ctime>

using namespace std;

class Orario {
private:
    int ore;
    int minuti;
    int secondi;
public:
    Orario() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        ore = ltm->tm_hour;
        minuti = ltm->tm_min;
        secondi = ltm->tm_sec;
    }
    Orario(int h, int m, int s) : ore(h), minuti(m), secondi(s) {}
    int getOre() const { return ore; }
    int getMinuti() const { return minuti; }
    int getSecondi() const { return secondi; }
    void SommaSecondi(int s);
};
#endif
