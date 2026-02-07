# Esercizio 8 — Gestione Corriere Espresso

## Esercizi richiesti

1. **UML delle classi con responsabilità delle associazioni**
2. **Definizioni delle classi C++**
3. **Definizioni dei metodi**
4. **Funzione esterna per frazione consegne entro orario**

---

## 1) UML (testuale)

```
┌─────────────────────────────────────────┐
│                Corriere                 │
├─────────────────────────────────────────┤
│ - nome: string                          │
│ - deposito: Coordinate                  │
│ - oraApertura: Orario                   │
│ - automezzi: vector<Automezzo>          │
│ - consegne: vector<Consegna>            │
│ - viaggi: vector<Viaggio>               │
├─────────────────────────────────────────┤
│ + inserisciConsegna(c: Consegna)        │
│ + inserisciAutomezzo(a: Automezzo)      │
│ + creaViaggio(a, o, c)                  │
│ + inserisciInViaggio(a, o, c, p)        │
│ + orarioConsegna(c): Orario             │
│ + getters, operator<<                   │
└─────────────────────────────────────────┘
   1 *-- 0..* Automezzo   (possiede)
   1 *-- 0..* Consegna    (gestisce)
   1 *-- 0..* Viaggio     (organizza)
   1 *-- 1    Coordinate  (deposito)

┌──────────────────┐        ┌──────────────────┐        ┌──────────────────┐
│   Automezzo      │        │    Consegna      │        │     Viaggio      │
├──────────────────┤        ├──────────────────┤        ├──────────────────┤
│ - targa: string  │        │ - luogo: Coord.  │        │ - automezzo: Aut.│
│ - capacita: dbl  │        │ - quantita: dbl  │        │ - oraPartenza: Or│
├──────────────────┤        ├──────────────────┤        │ - consegne: vect │
│ + getters        │        │ + getters        │        ├──────────────────┤
│ + operator==     │        │ + operator==     │        │ + aggiungi       │
│ + operator<<     │        │                  │        │ + getters        │
└──────────────────┘        └──────────────────┘        │ + operator<<     │
                                                        └──────────────────┘
Viaggio 1 --> 1 Automezzo   (assegna)
Viaggio 1 *-- 1..* Consegna (sequenza ordinata)

┌──────────────────┐
│   Coordinate     │
├──────────────────┤
│ - latitudine: dbl│
│ - longitudine:dbl│
└──────────────────┘
Consegna 1 *-- 1 Coordinate (luogo)

┌─────────────────┐
│  Orario         │
│  (disponibile)  │
├─────────────────┤
│ + operator<     │
│ + operator==    │
│ + operator+     │
│ + operator<<    │
└─────────────────┘
Corriere 1 --> 1 Orario (apertura)
Viaggio  1 --> 1 Orario (partenza)
```

### Responsabilità delle associazioni:

- **Corriere *-- Automezzo (1..0\*)**: il corriere possiede i propri automezzi
- **Corriere *-- Consegna (1..0\*)**: il corriere gestisce le consegne disponibili
- **Corriere *-- Viaggio (1..0\*)**: il corriere organizza i viaggi della giornata
- **Corriere *-- Coordinate (1..1)**: coordinate del deposito
- **Viaggio --> Automezzo (1..1)**: un viaggio usa un automezzo specifico
- **Viaggio *-- Consegna (1..1..*)**: sequenza ordinata di consegne
- **Consegna *-- Coordinate (1..1)**: coordinate del luogo di consegna
- **Corriere/Viaggio --> Orario (1..1)**: orari di apertura e partenza

---

## 2) Classi C++ definite

Le definizioni sono in [CorrierEspresso.hpp](EserciziCasa/Esercizio8_CorrierEspresso/CorrierEspresso.hpp):

- `Coordinate` - struct con latitudine e longitudine
- `Consegna` - classe con luogo e quantità merce
- `Automezzo` - classe con targa e capacità
- `Viaggio` - classe che raggruppa un automezzo e le sue consegne
- `Corriere` - classe principale che gestisce l'intero sistema

---

## 3) Metodi delle classi

Le implementazioni sono in [CorrierEspresso.cpp](EserciziCasa/Esercizio8_CorrierEspresso/CorrierEspresso.cpp):

### Corriere - Operazioni fondamentali:

- `inserisciConsegna(c: Consegna)` - Aggiunge consegna (no duplicati)
- `inserisciAutomezzo(a: Automezzo)` - Aggiunge automezzo (verifica unicità targa)
- `creaViaggio(a, o, c)` - Crea nuovo viaggio con una consegna
  - Precondizioni: automezzo e consegna presenti, orario >= apertura deposito, 
    nessun viaggio con stesso orario, capacità sufficiente
- `inserisciInViaggio(a, o, c, p)` - Inserisce consegna in posizione p di un viaggio
  - Precondizioni: viaggio esiste, consegna non ancora in un viaggio, 
    carico totale non supera capacità
- `orarioConsegna(c: Consegna)` - Calcola orario esatto della consegna basato su percorsi

### Tutti i getter e operator<<

---

## 4) Funzione esterna richiesta

```cpp
double frazioneconsegneEntroOrario(const Corriere& cor, 
                                   const Automezzo& a, 
                                   const Orario& orario)
```

Restituisce la frazione (0.0 - 1.0) di consegne effettuate da un automezzo che 
verranno completate entro un orario specificato, rispetto a tutte le sue consegne.

---

## Gestione precondizioni

Tutte le precondizioni sono gestite lanciando `std::invalid_argument`:
- Nome corriere/automezzo vuoto
- Capacità non valida
- Viaggio non trovato
- Consegna non trovata
- Carico insufficiente
- Orario non valido

---

## Funzione di supporto

`int tempoPercorsoMinuti(const Coordinate& da, const Coordinate& a)`

Calcola il tempo in minuti necessario per andare da un punto a un altro 
usando distanza geodetica approssimata.

---

## Compilazione ed esecuzione

```bash
make          # Compila
make run      # Compila ed esegue
make clean    # Pulisce i file compilati
```

---

## Note

- Le coordinate usano latitudine/longitudine (sistema WGS84)
- La distanza è calcolata in modo approssimato per semplicità
- In un'applicazione reale, si userebbe un servizio di mappe (Google Maps, etc.)
- Non è usata nessuna libreria esterna (chrono, iomanip, etc.)

