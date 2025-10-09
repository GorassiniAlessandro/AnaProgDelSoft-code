/*----------------------------------
file: PrimoCeck.cpp
autore: Alessandro Gorassini 168518
date: 09/10/2025
descr: Programma che chiede un numero intero e verifica se è primo o no.
------------------------------------*/

#include <iostream> 

using namespace std;

void StampaPiramide(int n);

int main ()
{
    int numero;
    cout << "Inserisci un numero intero: ";
    
    cin >> numero;
    
    
    StampaPiramide(numero);
    cout << endl;
    return 0;
    
}

void StampaPiramide(int n)
{
    //cout << "a";
    int layer_tot = n; // altezza della piramide
    int mattoni_tot = ((n*2)-1);      //grandezza della base della piramide 
    int vertice = n;    //centro della piramide 
    int i;
    int j;
    for (i = 0; i < layer_tot; i ++)      //utilizzo i per la riga corrente 
    {
        int max_num_riga = i+1;
        //cout << "  i :" << i << " --- max_num_riga :" << max_num_riga << endl;
        
        for (j = 1 ; j <= mattoni_tot;j++)      //utilizza j per il numero corrente 
        {   
            int num_contrario = (vertice - j) + max_num_riga;   //scaletta con offsett pari al numero più grande della riga 
            int num_riga = j + (max_num_riga - vertice );       // scaletta al contratio con offset par al numero più grande 
            if(j < vertice)
            {
                
                if( num_riga < 1)
                {
                    cout << "*"; 
                }else{
                    cout << num_riga ; 
                }

            }else 
            if(j == vertice)
            {
                cout << max_num_riga; 
            }else{
                
                if( num_contrario < 1)
                {
                    cout << "*"; 
                }else{
                    cout << num_contrario ; 
                }
            }
        }
        cout << endl;
    }
}
