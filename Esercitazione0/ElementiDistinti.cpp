/*----------------------------------
file: ElementiDistinti.cpp
autore: Alessandro Gorassini 168518
date: 10/10/2025
descr: Programma che calcola il numero di elementi distinti in un vettore e in una matrice utilizzando std::set.
------------------------------------*/
#include <iostream>
#include <set>

using namespace std;

const int DIM_VET = 6;
const int NUM_RIGHE = 2;
const int NUM_COL = 3;

int NumeroDistintiVettore(int v[], int n);
int NumeroDistintiMatrice(int m[][NUM_COL], int righe, int col);

int main()
{
  int vett[DIM_VET];
  int mat[NUM_RIGHE][NUM_COL];
  int i, j;

  cout << "Inserisci un vettore di " << DIM_VET << " valori interi : ";
  for (i = 0; i < DIM_VET; i++)
    cin >> vett[i];
  cout << "Il numero di elementi distinti del vettore e' " 
       << NumeroDistintiVettore(vett,DIM_VET) << endl; 

  cout << "Inserisci una matrice di " << NUM_RIGHE 
       << " righe e " << NUM_COL << " colonne" << endl;
  for (i = 0; i < NUM_RIGHE; i++)
    for (j = 0; j < NUM_COL; j++)
      cin >> mat[i][j];

  cout << "Il numero di elementi distinti della matrice e' " 
       << NumeroDistintiMatrice(mat,NUM_RIGHE,NUM_COL) << endl; 
}

int NumeroDistintiVettore(int v[], int n)
{
  set<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(v[i]);
  }
  return s.size();
}

int NumeroDistintiMatrice(int m[][NUM_COL], int righe, int col)
{
  set<int> s;
  for (int i = 0; i < righe; i++) {
    for (int j = 0; j < col; j++) {
      s.insert(m[i][j]);
    }
  }
  return s.size();
}
