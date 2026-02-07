# Esercizio 5 — Ordinamento e File

## Descrizione

Programma che legge interi da un file, li ordina usando `std::sort()` e scrive il risultato su un file di output.

### Requisiti implementati

- ✅ Lettura da file di input (primo valore = n, poi n numeri)
- ✅ Archiviazione dati in `std::vector<int>`
- ✅ Ordinamento con `std::sort()` (STL algorithm)
- ✅ Scrittura su file con formato leggibile
- ✅ Gestione errori (file non trovato, dati incompleti)
- ✅ Timing del processo di ordinamento
- ✅ Statistiche (min, max, conteggio)

## Struttura del progetto

- **Main.cpp**: Programma principale
- **input.txt**: File di input di esempio (10 numeri)
- **sorted.txt**: File di output generato (numeri ordinati)
- **Makefile**: Per compilare il progetto

## Caratteristiche

### File I/O
- **Input**: `ifstream` per lettura dal file input.txt
- **Output**: `ofstream` per scrittura nel file sorted.txt
- Gestione errori per apertura file

### Ordinamento
- Utilizza `std::sort()` della STL
- Ordine crescente (predefinito)
- Complessità O(n log n)

### Performance
- Misurazione del tempo di ordinamento in microsecondi
- Calcolo e visualizzazione min/max

### Formato output
- Intestazione con informazioni
- Sequenza ordinata (10 numeri per riga)
- Allineamento numeri con `setw()`

## Compilazione ed esecuzione

```bash
make          # Compila
make run      # Compila ed esegue
make clean    # Pulisce i file generati
```

## Esempio di utilizzo

**Input file (input.txt):**
```
10
45 23 89 12 78 34 56 90 11 67
```

**Output a schermo:**
```
=== ORDINAMENTO E FILE ===

Lettura da file: input.txt
Numero di interi da ordinare: 10

Valori originali (primi 20):
45 23 89 12 78 34 56 90 11 67

Ordinamento in corso...
Ordinamento completato in 15 microsecondi

Valori ordinati (primi 20):
11 12 23 34 45 56 67 78 89 90

Dati ordinati scritti in: sorted.txt
Programma completato con successo!
```

**Output file (sorted.txt):**
```
NUMERI ORDINATI
================
Totale elementi: 10
Valore minimo: 11
Valore massimo: 90

Sequenza ordinata:
      11      12      23      34      45      56      67      78      89      90
```

## Concetti implementati

### 1. STL Vector
```cpp
std::vector<int> numeri;
numeri.reserve(n);          // Pre-allocazione memoria
numeri.push_back(valore);   // Aggiunta elemento
```

### 2. std::sort()
```cpp
std::sort(numeri.begin(), numeri.end());  // Ordina in-place
```

### 3. File I/O con stream
```cpp
std::ifstream infile(inputFile);   // Input
std::ofstream outfile(outputFile); // Output
```

### 4. Iteratori STL
```cpp
for (auto it = numeri.begin(); it != numeri.end(); ++it)
```

### 5. Range-based for loop
```cpp
for (const auto& val : numeri) { ... }
```

### 6. Timing
```cpp
auto start = std::chrono::high_resolution_clock::now();
// ... operazione ...
auto end = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
```

## Complessità

| Operazione | Complessità |
|-----------|-------------|
| Lettura file | O(n) |
| std::sort() | O(n log n) |
| Scrittura file | O(n) |
| **Totale** | **O(n log n)** |

## Varianti possibili

1. **Ordine decrescente**: `std::sort(numeri.begin(), numeri.end(), std::greater<int>());`
2. **Comparatore custom**: Passare funzione comparatrice
3. **Stable sort**: Usare `std::stable_sort()` per mantenere ordine relativo
4. **Partial sort**: Usare `std::partial_sort()` se serve solo Top-K
5. **Nth element**: Usare `std::nth_element()` per trovare mediana

## Note di performance

- Per piccoli dataset (< 100): differenza minima tra algoritmi
- Per grandi dataset (> 100.000): std::sort() è generalmente ottimale
- Lo spazio extra è O(1) se si usa la versione in-place
- Il timing include operazioni I/O, non solo l'ordinamento

