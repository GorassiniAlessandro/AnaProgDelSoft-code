# Esercizio 4 — Classi composte con allocazione dinamica

## Descrizione

Gestione di un corso universitario con studenti, voti e generazione di report su file.

### Requisiti implementati

- ✅ Classe `Studente` con nome, cognome e vettore di voti
- ✅ Classe `Corso` con nome e vector di studenti
- ✅ Metodo `aggiungiStudente()` per iscrivere studenti
- ✅ Metodo `scriviSuFile()` che genera un report formattato
- ✅ Operatori `>>` e `<<` sovraccaricati per Studente
- ✅ Allocazione dinamica via STL (vector)
- ✅ Calcolo medie e statistiche

## Struttura del progetto

- **Studente.hpp/cpp**: Classe Studente con voti
- **Corso.hpp/cpp**: Classe Corso con lista di studenti
- **Main.cpp**: Programma driver interattivo
- **Makefile**: Per compilare il progetto

## Caratteristiche

### Classe Studente
- Attributi: `nome`, `cognome`, `voti` (vector<int>)
- Metodi: `addVoto()`, `calcolaMedia()`, `getNumeroVoti()`
- Operatori: `>>` (input interattivo), `<<` (output formattato)

### Classe Corso
- Attributi: `nome`, `studenti` (vector<Studente>)
- Metodi: `aggiungiStudente()`, `scriviSuFile()`, `stampaStudenti()`, `calcolaMediaCorso()`
- Gestione dinamica: vector auto-ridimensionabile

## Compilazione ed esecuzione

```bash
make          # Compila
make run      # Compila ed esegue
make clean    # Pulisce i file generati
```

## Esempio di utilizzo

**Input interattivo:**
```
Inserisci nome: Mario
Inserisci cognome: Rossi
Inserisci il numero di voti: 3
Voto 1: 25
Voto 2: 28
Voto 3: 26

Aggiungere un altro studente? (S/N): S
...
```

## Output file (corso_output.txt)

```
============================================
CORSO: Programmazione C++
============================================
Numero di studenti iscritti: 2

NOME                COGNOME              NUM. VOTI        MEDIA
---------------------------------------------------------------------------
Mario               Rossi                        3        26.33
   Voti: 25 28 26 
Anna                Verdi                        3        27.67
   Voti: 28 27 28 

============================================
STATISTICHE CORSO
============================================
Media del corso: 27.00
```

## Concetti implementati

### 1. Composizione di classi
```cpp
class Corso {
    std::vector<Studente> studenti;  // Relazione "has-a"
};
```

### 2. Allocazione dinamica con STL
```cpp
std::vector<Studente> studenti;  // Crescita automatica
studenti.push_back(s);           // Aggiunta elemento
```

### 3. Operatori sovraccaricati
```cpp
friend std::istream& operator>>(std::istream& in, Studente& s);
friend std::ostream& operator<<(std::ostream& out, const Studente& s);
```

### 4. File I/O con fstream
```cpp
std::ofstream outfile(filename);
outfile << "Dati formattati" << std::endl;
outfile.close();
```

### 5. Validazione dati
```cpp
if (voto >= 0 && voto <= 30) {
    voti.push_back(voto);  // Solo voti validi
}
```

## Metodi disponibili

### Studente
| Metodo | Descrizione |
|--------|-------------|
| `addVoto(int)` | Aggiunge un voto (0-30) |
| `calcolaMedia()` | Calcola media aritmetica |
| `getNumeroVoti()` | Restituisce numero di voti |

### Corso
| Metodo | Descrizione |
|--------|-------------|
| `aggiungiStudente(Studente)` | Iscrive uno studente |
| `scriviSuFile(string)` | Genera report formattato |
| `stampaStudenti()` | Stampa a video |
| `calcolaMediaCorso()` | Media di tutti gli studenti |

