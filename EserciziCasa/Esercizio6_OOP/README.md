# Esercizio 6 — Programmazione Orientata agli Oggetti (OOP)

## Descrizione

Implementazione di una classe `Rettangolo` con calcolo di area e perimetro, lettura da file e statistiche.

### Requisiti implementati

- ✅ Classe `Rettangolo` con attributi `base` e `altezza`
- ✅ Costruttore parametrico
- ✅ Metodi `area()` e `perimetro()`
- ✅ Sovraccarico `operator<<` per stampa formattata
- ✅ Lettura da file di multipli rettangoli
- ✅ Calcolo statistiche (area totale, media, min, max)
- ✅ Validazione input (no valori negativi)

## Struttura del progetto

- **Rettangolo.hpp**: Dichiarazione della classe Rettangolo
- **Rettangolo.cpp**: Implementazione della classe
- **Main.cpp**: Programma che legge da file e calcola statistiche
- **rettangoli.txt**: File di input con dati (5 rettangoli)
- **Makefile**: Per compilare il progetto

## Caratteristiche

### Classe Rettangolo

**Attributi privati:**
- `double base`
- `double altezza`

**Metodi pubblici:**
- `Rettangolo(double b, double h)` - Costruttore parametrico
- `Rettangolo()` - Costruttore di default
- `double getBase() const` - Restituisce la base
- `double getAltezza() const` - Restituisce l'altezza
- `void setBase(double)` - Imposta la base
- `void setAltezza(double)` - Imposta l'altezza
- `double area() const` - Calcola area (base × altezza)
- `double perimetro() const` - Calcola perimetro (2 × (base + altezza))

**Operatori:**
- `operator<<` - Stampa formattata del rettangolo
- `operator>>` - Lettura da stream

### Validazione

I valori negativi vengono automaticamente convertiti a 0.

## Compilazione ed esecuzione

```bash
make          # Compila
make run      # Compila ed esegue
make clean    # Pulisce i file compilati
```

## Formato file input (rettangoli.txt)

```
5
10.5 5.0
8.0 12.0
15.0 7.5
6.0 6.0
20.0 3.5
```

Prima riga: numero di rettangoli  
Righe successive: base altezza (per ogni rettangolo)

## Esempio di output

```
=== GESTIONE RETTANGOLI ===

Lettura di 5 rettangoli da file...

=== RETTANGOLI LETTI ===
1. Rettangolo [Base: 10.5, Altezza: 5] -> Area: 52.5, Perimetro: 31
2. Rettangolo [Base: 8, Altezza: 12] -> Area: 96, Perimetro: 40
3. Rettangolo [Base: 15, Altezza: 7.5] -> Area: 112.5, Perimetro: 45
4. Rettangolo [Base: 6, Altezza: 6] -> Area: 36, Perimetro: 24
5. Rettangolo [Base: 20, Altezza: 3.5] -> Area: 70, Perimetro: 47

=== STATISTICHE ===
Numero di rettangoli: 5
Area totale: 367
Perimetro totale: 187
Area media: 73.4

Rettangolo con area massima (112.5):
  Rettangolo [Base: 15, Altezza: 7.5] -> Area: 112.5, Perimetro: 45

Rettangolo con area minima (36):
  Rettangolo [Base: 6, Altezza: 6] -> Area: 36, Perimetro: 24

Programma completato!
```

## Concetti OOP implementati

### 1. Incapsulamento
```cpp
private:
    double base;
    double altezza;
public:
    double getBase() const;
    void setBase(double b);
```
Gli attributi sono privati, accessibili solo tramite getter/setter.

### 2. Costruttori
```cpp
Rettangolo(double b, double h);  // Parametrico
Rettangolo();                     // Default
```

### 3. Metodi const
```cpp
double area() const;
double getBase() const;
```
Non modificano lo stato dell'oggetto.

### 4. Sovraccarico operatori
```cpp
friend std::ostream& operator<<(std::ostream& out, const Rettangolo& r);
```
Permette stampa diretta con `cout << rettangolo`.

### 5. Validazione
```cpp
if (base < 0) base = 0;
if (altezza < 0) altezza = 0;
```

## Formule matematiche

**Area:** $A = b \times h$

**Perimetro:** $P = 2 \times (b + h)$

## Estensioni possibili

1. **Confronto rettangoli**: Sovraccarico `operator<` per ordinare per area
2. **Quadrato**: Classe derivata con `base == altezza`
3. **Diagonale**: Metodo `diagonale()` usando Pitagora
4. **Scala**: Metodo `scala(double fattore)` per ridimensionare
5. **Isoperimetro**: Metodo per verificare perimetri uguali

## Complessità

| Operazione | Complessità |
|-----------|-------------|
| Lettura file | O(n) |
| Calcolo area/perimetro | O(1) |
| Statistiche | O(n) |
| **Totale** | **O(n)** |

