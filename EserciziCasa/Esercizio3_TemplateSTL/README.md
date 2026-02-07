# Esercizio 3 — Template e STL

## Descrizione

Funzione template `MaxInContainer()` che ritorna il valore massimo contenuto in qualsiasi contenitore STL standard C++.

### Requisiti implementati

- ✅ Template function `MaxInContainer<Container>()` 
- ✅ Funziona con `vector<int>` e `vector<float>`
- ✅ Funziona con altri tipi e contenitori (`vector<double>`, `list<int>`, ecc.)
- ✅ Uso di iteratori STL (`begin()`, `end()`)
- ✅ Gestione di contenitori vuoti con eccezioni
- ✅ Tre implementazioni diverse (iteratori manuali, range-based for, `std::max_element`)

## Struttura del progetto

- **MaxInContainer.hpp**: Template function (header-only)
  - `MaxInContainer()` - Versione con iteratori manuali
  - `MaxInContainer_V2()` - Versione con range-based for loop
  - `MaxInContainer_V3()` - Versione con `std::max_element`
- **Main.cpp**: Driver che testa le funzioni
- **Makefile**: Per compilare il progetto

## Caratteristiche

- **Template generico**: Accetta qualsiasi Container con iteratori
- **Type-safe**: Usa `typename Container::value_type`
- **STL-compliant**: Funziona con vector, list, deque, ecc.
- **Gestione errori**: Eccezioni per contenitori vuoti
- **Multiple implementations**: Dimostra diverse tecniche

## Compilazione ed esecuzione

```bash
make          # Compila
make run      # Compila ed esegue
make clean    # Pulisce i file compilati
```

## Esempio di output

```
=== Template e STL: MaxInContainer ===

--- Test 1: vector<int> ---
Vettore: 15 3 42 8 99 5 27 
Valore massimo (int): 99

--- Test 2: vector<float> ---
Vettore: 3.14 2.71 9.99 1.41 8.50 
Valore massimo (float): 9.99

--- Test 3: vector<double> ---
Vettore: 1.234 5.678 2.345 9.876 3.456 
Valore massimo (double) - V2: 9.876

--- Test 4: list<int> ---
Lista: 7 2 11 4 25 6 
Valore massimo (list) - V3 (std::max_element): 25

--- Test 5: Contenitore vuoto ---
Errore catturato: Il contenitore è vuoto

Test completati!
```

## Concetti chiave

### 1. Template generico
```cpp
template <typename Container>
typename Container::value_type MaxInContainer(const Container& container)
```
- `Container` è il tipo del contenitore
- `Container::value_type` è il tipo degli elementi

### 2. Iteratori STL
```cpp
for (auto it = container.begin(); it != container.end(); ++it) {
    if (*it > max_value) max_value = *it;
}
```
- `begin()` e `end()` sono disponibili su tutti i container STL
- `*it` dereferenzia l'iteratore

### 3. Range-based for loop (C++11)
```cpp
for (const auto& element : vec) {
    if (element > max_value) max_value = element;
}
```
- Più leggibile e sicuro
- Funziona con tutti i container

### 4. std::max_element
```cpp
auto it = std::max_element(container.begin(), container.end());
```
- Algoritmo STL standard
- Ritorna un iteratore al massimo

## Contenitori testati

| Contenitore | Funziona | Note |
|------------|----------|-------|
| `vector<int>` | ✅ | Accesso random |
| `vector<float>` | ✅ | Con decimali |
| `vector<double>` | ✅ | Precisione doppia |
| `list<int>` | ✅ | Accesso sequenziale |
| Contenitori vuoti | ✅ | Eccezione sollevata |

