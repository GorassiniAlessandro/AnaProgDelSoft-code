/*----------------------------------
file: ContoCorrente.hpp
autore: Alessandro Gorassini 168518
date: 28/10/2025
descr: Header file for the ContoCorrente class, defining a bank account class with methods for managing balance, interest rate, deposits, withdrawals, and balance conversion to lire.
------------------------------------*/

#ifndef CONTOCORRENTE_HPP
#define CONTOCORRENTE_HPP

class ContoCorrente {
private:
    int euro;
    int centesimi;
    double tasso;

public:
    ContoCorrente(){
        euro = 0;
        centesimi = 0;
        tasso = 0;
    }
    ContoCorrente(double t){
        euro = 0;
        centesimi = 0;
        tasso = t;
    };
    double TassoInteresse() const;
    int SaldoEuro() const;
    int SaldoCentesimi() const;
    int SaldoInLire() const;
    void FissaTassoInteresse(double t);
    void DepositaEuro( int unita, int centesimi );
    bool PrelevaEuro(int unita, int centesimi);
    void AggiornaSaldo();
};    

#endif