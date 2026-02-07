#include "StazioneSciistica.hpp"

// ===== Impianto =====

Impianto::Impianto(const std::string& n, TipoImpianto t, const Orario& a, const Orario& c, int cap)
    : nome(n), tipo(t), apertura(a), chiusura(c), capacitaPersoneOra(cap) {
    if (n.empty()) {
        throw std::invalid_argument("Nome impianto vuoto");
    }
    if (cap <= 0) {
        throw std::invalid_argument("Capacita impianto non valida");
    }
    if (c < a) {
        throw std::invalid_argument("Orari impianto non validi");
    }
}

std::string Impianto::getNome() const { return nome; }
TipoImpianto Impianto::getTipo() const { return tipo; }
Orario Impianto::getApertura() const { return apertura; }
Orario Impianto::getChiusura() const { return chiusura; }
int Impianto::getCapacitaPersoneOra() const { return capacitaPersoneOra; }

std::ostream& operator<<(std::ostream& out, const Impianto& i) {
    out << "Impianto: " << i.nome << " | Tipo: ";
    switch (i.tipo) {
        case TipoImpianto::Seggiovia: out << "Seggiovia"; break;
        case TipoImpianto::Funivia: out << "Funivia"; break;
        case TipoImpianto::Bidonvia: out << "Bidonvia"; break;
        case TipoImpianto::Sciovia: out << "Sciovia"; break;
    }
    out << " | Apertura: " << i.apertura
        << " | Chiusura: " << i.chiusura
        << " | Capacita: " << i.capacitaPersoneOra << " p/h";
    return out;
}

// ===== StazioneSciistica =====

StazioneSciistica::StazioneSciistica(const std::string& n)
    : nome(n), haUltimoIngresso(false) {
    if (n.empty()) {
        throw std::invalid_argument("Nome stazione vuoto");
    }
}

std::string StazioneSciistica::getNome() const { return nome; }
int StazioneSciistica::getNumeroImpianti() const { return impianti.size(); }
int StazioneSciistica::getNumeroPersone() const { return persone.size(); }

int StazioneSciistica::trovaIndiceImpianto(const std::string& nomeImpianto) const {
    for (int i = 0; i < impianti.size(); i++) {
        if (impianti[i].getNome() == nomeImpianto) {
            return i;
        }
    }
    return -1;
}

int StazioneSciistica::trovaIndicePersona(const std::string& codice) const {
    for (int i = 0; i < persone.size(); i++) {
        if (persone[i].persona.Codice() == codice) {
            return i;
        }
    }
    return -1;
}

void StazioneSciistica::aggiungiImpianto(const Impianto& i) {
    if (trovaIndiceImpianto(i.getNome()) != -1) {
        throw std::invalid_argument("Impianto gia presente");
    }
    impianti.push_back(i);
}

void StazioneSciistica::registraPersona(const Persona& p, const Orario& inizio, const Orario& fine) {
    if (trovaIndicePersona(p.Codice()) != -1) {
        throw std::invalid_argument("Persona gia registrata");
    }
    if (fine < inizio) {
        throw std::invalid_argument("Intervallo accesso non valido");
    }

    RegistroPersona rp;
    rp.persona = p;
    rp.inizioAccesso = inizio;
    rp.fineAccesso = fine;
    persone.push_back(rp);
}

void StazioneSciistica::inserisciIngresso(const std::string& codicePersona, const std::string& nomeImpianto, const Orario& orario) {
    int idxPersona = trovaIndicePersona(codicePersona);
    if (idxPersona == -1) {
        throw std::invalid_argument("Persona non registrata");
    }

    int idxImpianto = trovaIndiceImpianto(nomeImpianto);
    if (idxImpianto == -1) {
        throw std::invalid_argument("Impianto non esistente");
    }

    const Impianto& imp = impianti[idxImpianto];

    if (orario < imp.getApertura() || imp.getChiusura() < orario) {
        throw std::invalid_argument("Orario fuori fascia di apertura");
    }

    if (orario < persone[idxPersona].inizioAccesso || persone[idxPersona].fineAccesso < orario) {
        throw std::invalid_argument("Accesso non valido per la persona");
    }

    if (haUltimoIngresso && !(ultimoIngresso < orario)) {
        throw std::invalid_argument("Gli ingressi devono essere in ordine strettamente cronologico");
    }

    Ingresso ing;
    ing.nomeImpianto = nomeImpianto;
    ing.orario = orario;
    persone[idxPersona].ingressi.push_back(ing);

    ultimoIngresso = orario;
    haUltimoIngresso = true;
}

int StazioneSciistica::numeroRisalite(const std::string& codicePersona, const std::string& nomeImpianto) const {
    int idxPersona = trovaIndicePersona(codicePersona);
    if (idxPersona == -1) {
        throw std::invalid_argument("Persona non registrata");
    }

    int count = 0;
    for (int i = 0; i < persone[idxPersona].ingressi.size(); i++) {
        if (persone[idxPersona].ingressi[i].nomeImpianto == nomeImpianto) {
            count++;
        }
    }
    return count;
}

std::string StazioneSciistica::impiantoPiuUsato(const std::string& codicePersona) const {
    int idxPersona = trovaIndicePersona(codicePersona);
    if (idxPersona == -1) {
        throw std::invalid_argument("Persona non registrata");
    }

    if (persone[idxPersona].ingressi.empty()) {
        throw std::invalid_argument("Nessun ingresso registrato");
    }

    std::string impMax;
    int maxCount = -1;

    for (int i = 0; i < impianti.size(); i++) {
        int count = numeroRisalite(codicePersona, impianti[i].getNome());
        if (count > maxCount) {
            maxCount = count;
            impMax = impianti[i].getNome();
        }
    }

    return impMax;
}

void StazioneSciistica::cancellaRegistrazioniScadute(const Orario& orario) {
    std::vector<RegistroPersona> aggiornate;
    for (int i = 0; i < persone.size(); i++) {
        if (!(persone[i].fineAccesso < orario)) {
            aggiornate.push_back(persone[i]);
        }
    }
    persone = aggiornate;
}

const std::vector<Impianto>& StazioneSciistica::getImpianti() const { return impianti; }
const std::vector<StazioneSciistica::RegistroPersona>& StazioneSciistica::getPersone() const { return persone; }

std::ostream& operator<<(std::ostream& out, const StazioneSciistica& s) {
    out << "Stazione: " << s.nome << " | Impianti: " << s.impianti.size() << " | Persone: " << s.persone.size();
    return out;
}

// ===== Funzione esterna =====

int tempoMinimoTraSeggiovie(const StazioneSciistica& s, const std::string& codicePersona) {
    int idxPersona = -1;
    const std::vector<StazioneSciistica::RegistroPersona>& persone = s.getPersone();

    for (int i = 0; i < persone.size(); i++) {
        if (persone[i].persona.Codice() == codicePersona) {
            idxPersona = i;
            break;
        }
    }

    if (idxPersona == -1) {
        throw std::invalid_argument("Persona non registrata");
    }

    const std::vector<Ingresso>& ingressi = persone[idxPersona].ingressi;

    Orario precedente;
    bool haPrecedente = false;
    int minimo = -1;

    for (int i = 0; i < ingressi.size(); i++) {
        int idxImpianto = -1;
        const std::vector<Impianto>& impianti = s.getImpianti();
        for (int j = 0; j < impianti.size(); j++) {
            if (impianti[j].getNome() == ingressi[i].nomeImpianto) {
                idxImpianto = j;
                break;
            }
        }

        if (idxImpianto != -1 && impianti[idxImpianto].getTipo() == TipoImpianto::Seggiovia) {
            if (haPrecedente) {
                int diff = ingressi[i].orario - precedente;
                if (minimo == -1 || diff < minimo) {
                    minimo = diff;
                }
            }
            precedente = ingressi[i].orario;
            haPrecedente = true;
        }
    }

    if (minimo == -1) {
        throw std::invalid_argument("Meno di due ingressi a seggiovie");
    }

    return minimo;
}
