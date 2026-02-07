# Esercizio 2 — Implementazione di uno Stack (Pila)

## Descrizione

Implementazione di una struttura dati **Stack** (pila) in C++ con template generico `T`.

### Requisiti implementati

- ✅ `push(value)` - Inserisce un elemento in cima alla pila
- ✅ `pop()` - Rimuove e restituisce l'elemento in cima
- ✅ `top()` - Restituisce l'elemento in cima senza rimuoverlo
- ✅ `empty()` - Verifica se la pila è vuota
- ✅ `size()` - Restituisce il numero di elementi
- ✅ Driver interattivo che legge n numeri e li stampa in ordine inverso

## Struttura del progetto

- **Stack.hpp**: Template della classe Stack (header-only)
- **Main.cpp**: Programma driver che testa lo Stack
- **Makefile**: Per compilare il progetto

## Caratteristiche

- **Template generico**: Funziona con qualsiasi tipo T (int, double, string, ecc.)
- **Dinamico**: Usa `std::vector` per crescita automatica
- **Gestione errori**: Eccezioni per operazioni su pila vuota
- **LIFO**: Last In, First Out - gli ultimi inseriti sono i primi a uscire

## Compilazione ed esecuzione

```bash
make          # Compila
make run      # Compila ed esegue
make clean    # Pulisce i file compilati
```

## Esempio di utilizzo

**Input:**
```
Inserisci il numero di elementi: 5
Inserisci 5 numeri:
Elemento 1: 10
Elemento 2: 20
Elemento 3: 30
Elemento 4: 40
Elemento 5: 50
```

**Output:**
```
Elementi della pila in ordine inverso (LIFO):
1. 50
2. 40
3. 30
4. 20
5. 10

Pila vuota. Dimensione: 0
```

## Come funziona

1. Crea una pila vuota
2. Legge n numeri da tastiera
3. Inserisce ogni numero con `push()`
4. Estrae gli elementi con `pop()` (stampa in ordine inverso)
5. Verifica che la pila sia vuota

## Metodi disponibili

| Metodo | Descrizione | Complessità |
|--------|-------------|-------------|
| `push(T)` | Inserisce elemento | O(1) ammortizzato |
| `pop()` | Rimuove e restituisce top | O(1) |
| `top()` | Restituisce top | O(1) |
| `empty()` | Verifica se vuota | O(1) |
| `size()` | Conta elementi | O(1) |

