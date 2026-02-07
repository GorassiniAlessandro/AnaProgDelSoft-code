# Esercizio 1 — Gestione di file di testo

## Descrizione

Programma che legge da un file di testo un insieme di record che rappresentano persone (nome, cognome, età).

### Requisiti

- ✅ Caricare tutti i record in un `vector<Persona>`
- ✅ Scrivere su un altro file solo le persone con età ≥ 18 anni
- ✅ Stampare a video il numero di persone maggiorenni

## Struttura del progetto

- **Persona.hpp**: Dichiarazione della classe Persona
- **Persona.cpp**: Implementazione della classe Persona
- **Main.cpp**: Programma principale
- **input.txt**: File di input con i dati di esempio
- **output.txt**: File di output generato (contiene i maggiorenni)
- **Makefile**: Per compilare il progetto

## Compilazione ed esecuzione

```bash
make          # Compila il progetto
make run      # Compila ed esegue
make clean    # Pulisce i file generati
```

## Come funziona

1. Legge il file `input.txt`
2. Carica tutte le persone in un vector
3. Scrive le persone con età ≥ 18 in `output.txt`
4. Stampa il numero totale di maggiorenni

## Esempio di output

```
Numero di persone maggiorenni: 3
Dati scritti nel file: output.txt
```

Nel file output.txt troverai:
```
Mario Rossi 25
Luca Verdi 18
Francesco Ferrari 30
```
