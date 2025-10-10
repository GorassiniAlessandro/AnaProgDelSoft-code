/*----------------------------------
file: DataPrec.cpp
autore: Alessandro Gorassini 168518
date: 10/10/2025
descr:Funzione che riceve una data e calcola la data precedente
------------------------------------*/

#include <iostream>

using namespace std;

int GiornoDelMese(int m, int a);

void ChiediData(int* g, int* m, int* a);

void Ieri(int* g, int* m, int* a);

bool IsDataCorrect(int g, int m, int a);

void Stampa(int g, int m, int a);

int main ()
{
    int giorno, mese, anno;
    ChiediData(&giorno, &mese, &anno);

    Ieri(&giorno, &mese, &anno);

    Stampa(giorno, mese, anno);

    return 0;

}

void ChiediData(int* g, int* m, int* a)
{
    cout << "inserire una data valida gg mm aaaa :";
    do
    {
        cin >> *g >> *m >> *a;
    } while (!IsDataCorrect(*g, *m, *a));

}

void Ieri(int* g, int* m, int* a)
{
    if (*g > 1)
    {
        (*g)--;
    }
    else
    {
        if (*m > 1)
        {
            (*m)--;
            *g = GiornoDelMese(*m, *a);
        }
        else
        {
            (*a)--;
            *m = 12;
            *g = GiornoDelMese(12, *a);
        }

    }
}

bool IsDataCorrect(int g, int m, int a)
{
    if (m < 1 || m > 12) return false;
    if (g < 1 || g > GiornoDelMese(m, a)) return false;
    return true;
}

int GiornoDelMese(int m, int a)
{
    if (m == 2)
    {
        if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) return 29;
        else return 28;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

void Stampa(int g, int m, int a)
{
    cout << g << "/" << m << "/" << a << endl;
}
