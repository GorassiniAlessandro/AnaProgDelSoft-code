#include "ContoCorrente.hpp"

using namespace std;

double ContoCorrente::TassoInteresse() const {
    return tasso;
}

int ContoCorrente::SaldoEuro() const {
    return euro;
}

int ContoCorrente::SaldoCentesimi() const {
    return centesimi;
}

int ContoCorrente::SaldoInLire() const {
    return (euro * 1936) + (centesimi * 19);
}

void ContoCorrente::FissaTassoInteresse(double t) {
    tasso = t;
}

void ContoCorrente::DepositaEuro(int unita, int cent) {
    euro += unita;
    centesimi += cent;
    if (centesimi >= 100) {
        euro += centesimi / 100;
        centesimi %= 100;
    }
}

bool ContoCorrente::PrelevaEuro(int unita, int cent) {
    int totalCentesimi = euro * 100 + centesimi;
    int prelievoCentesimi = unita * 100 + cent;
    if (totalCentesimi >= prelievoCentesimi) {
        totalCentesimi -= prelievoCentesimi;
        euro = totalCentesimi / 100;
        centesimi = totalCentesimi % 100;
        return true;
    }
    return false;
}

void ContoCorrente::AggiornaSaldo() {
    double interesse = (euro + centesimi / 100.0) * tasso / 100.0;
    int interesseEuro = static_cast<int>(interesse);
    int interesseCentesimi = static_cast<int>((interesse - interesseEuro) * 100);
    euro += interesseEuro;
    centesimi += interesseCentesimi;
    if (centesimi >= 100) {
        euro += centesimi / 100;
        centesimi %= 100;
    }
}
