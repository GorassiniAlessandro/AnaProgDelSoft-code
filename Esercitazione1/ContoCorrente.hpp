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