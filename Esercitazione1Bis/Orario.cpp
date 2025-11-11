/*----------------------------------
file: Orario.cpp
autore: Alessandro Gorassini 168518
date: 28/10/2025
descr: Implementation of the Orario class methods for time management, including adding seconds with rollover.
------------------------------------*/

#include "Orario.hpp"

void Orario::SommaSecondi(int s) {
    secondi += s;
    minuti += secondi / 60;
    secondi %= 60;
    ore += minuti / 60;
    minuti %= 60;
    ore %= 24; // Assuming 24-hour format
}
