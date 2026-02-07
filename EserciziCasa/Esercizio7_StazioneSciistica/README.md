# Esercizio 7 — Gestione Stazione Sciistica

## Esercizi richiesti

1. **UML delle classi**
2. **Definizioni delle classi C++**
3. **Definizioni delle funzioni e operatori**
4. **Funzione esterna per tempo minimo tra ingressi a seggiovie**

---

## 1) UML (testuale)

```
┌─────────────────────────────────────┐
│      StazioneSciistica              │
├─────────────────────────────────────┤
│ - nome: string                      │
│ - impianti: vector<Impianto>        │
│ - persone: vector<RegistroPersona>  │
│ - haUltimoIngresso: bool            │
│ - ultimoIngresso: Orario            │
├─────────────────────────────────────┤
│ + aggiungiImpianto()                │
│ + registraPersona()                 │
│ + inserisciIngresso()               │
│ + numeroRisalite()                  │
│ + impiantoPiuUsato()                │
│ + cancellaRegistrazioniScadute()    │
│ + operator<<                        │
└─────────────────────────────────────┘
           │ *                    │ *
           │                      │
    ha composizione          ha composizione
           │                      │
           ▼                      ▼
  ┌──────────────────┐   ┌──────────────────────┐
  │    Impianto      │   │  RegistroPersona     │
  ├──────────────────┤   ├──────────────────────┤
  │ - nome: string   │   │ - persona: Persona   │
  │ - tipo: TipoImp. │   │ - inizioAccesso: Or. │
  │ - apertura: Or.  │   │ - fineAccesso: Or.   │
  │ - chiusura: Or.  │   │ - ingressi: vector   │
  │ - capacita: int  │   │    <Ingresso>        │
  ├──────────────────┤   ├──────────────────────┤
  │ + getters        │   │ + accessi agli attr. │
  │ + operator<<     │   └──────────────────────┘
  └──────────────────┘            │ *
                                  │
                           ha composizione
                                  │
                                  ▼
                        ┌──────────────────────┐
                        │    Ingresso          │
                        ├──────────────────────┤
                        │ - nomeImpianto: str. │
                        │ - orario: Orario     │
                        └──────────────────────┘

┌─────────────────┐
│  Orario         │
│  (disponibile)  │
├─────────────────┤
│ + operator<     │
│ + operator==    │
│ + operator-     │
│ + operator<<    │
└─────────────────┘
     ▲        ▲
     │        │  usa
     │        │
 usato da StazioneSciistica e suoi componenti

┌─────────────────┐
│  Persona        │
│  (disponibile)  │
├─────────────────┤
│ + Codice(): str │
│ + operator<<    │
└─────────────────┘
     ▲
     │
     │ contiene
     │
  RegistroPersona

┌─────────────────────────┐
│ enum TipoImpianto       │
├─────────────────────────┤
│ - Seggiovia             │
│ - Funivia               │
│ - Bidonvia              │
│ - Sciovia               │
└─────────────────────────┘
     ▲
     │
     │ usa
     │
   Impianto
```

### Legenda relazioni:

- **Composizione (*: ha)**: StazioneSciistica contiene 0 o più Impianti
- **Composizione (*: ha)**: StazioneSciistica contiene 0 o più RegistroPersona
- **Composizione (*: ha)**: RegistroPersona contiene 0 o più Ingressi
- **Associazione**: RegistroPersona referenzia Persona
- **Associazione**: Ingresso contiene Orario
- **Enumerazione**: Impianto usa TipoImpianto
- **Classe esterna**: Orario e Persona sono disponibili

---

## 2) Classi C++

Le definizioni sono in:
- [Esercizio7_StazioneSciistica/StazioneSciistica.hpp](EserciziCasa/Esercizio7_StazioneSciistica/StazioneSciistica.hpp)

Classi principali:
- `Impianto`
- `StazioneSciistica`
- `Ingresso` (struct)
- `RegistroPersona` (struct interna)

Tipo enum:
- `TipoImpianto` con: Seggiovia, Funivia, Bidonvia, Sciovia

---

## 3) Funzioni e operatori

Le implementazioni sono in:
- [Esercizio7_StazioneSciistica/StazioneSciistica.cpp](EserciziCasa/Esercizio7_StazioneSciistica/StazioneSciistica.cpp)

Funzioni chiave:
- `aggiungiImpianto()`
- `registraPersona()`
- `inserisciIngresso()`
- `numeroRisalite()`
- `impiantoPiuUsato()`
- `cancellaRegistrazioniScadute()`
- `operator<<` per `Impianto` e `StazioneSciistica`

Precondizioni gestite con `std::invalid_argument`:
- nome impianto/stazione vuoto
- capacita <= 0
- orari non validi (chiusura < apertura)
- duplicazione impianti o persone
- accesso fuori fascia oraria
- ingressi non in ordine strettamente cronologico

---

## 4) Funzione esterna richiesta

```
int tempoMinimoTraSeggiovie(const StazioneSciistica& s, const std::string& codicePersona)
```

Restituisce il tempo minimo (in secondi) tra due ingressi a seggiovie qualsiasi della stessa persona.

**Assunzione**: l’operatore `-` della classe `Orario` restituisce la differenza in secondi.

---

## Note

- Le classi `Orario` e `Persona` sono assunte già disponibili.
- `Persona` fornisce: `Codice()` e operator<<.
- Non viene memorizzata la data (dati giornalieri).

---

## Suggerimenti per test

Per testare, crea un piccolo driver che:
1. Crea una stazione
2. Aggiunge alcuni impianti
3. Registra persone
4. Inserisce ingressi in ordine cronologico
5. Chiama `numeroRisalite()` e `tempoMinimoTraSeggiovie()`
