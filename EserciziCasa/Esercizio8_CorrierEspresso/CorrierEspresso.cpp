#include "CorrierEspresso.hpp"
#include <cmath>

// ===== Coordinate =====

Coordinate::Coordinate(double lat, double lon) : latitudine(lat), longitudine(lon) {}

// ===== Consegna =====

Consegna::Consegna(const Coordinate& luogo, double quantita)
    : luogoConsegna(luogo), quantitaMerce(quantita) {
    if (quantita <= 0) {
        throw std::invalid_argument("Quantita merce deve essere positiva");
    }
}

Coordinate Consegna::getLuogo() const { return luogoConsegna; }
double Consegna::getQuantita() const { return quantitaMerce; }

bool Consegna::operator==(const Consegna& other) const {
    return (luogoConsegna.latitudine == other.luogoConsegna.latitudine &&
            luogoConsegna.longitudine == other.luogoConsegna.longitudine &&
            quantitaMerce == other.quantitaMerce);
}

// ===== Automezzo =====

Automezzo::Automezzo(const std::string& t, double cap) : targa(t), capacita(cap) {
    if (t.empty()) {
        throw std::invalid_argument("Targa automezzo vuota");
    }
    if (cap <= 0) {
        throw std::invalid_argument("Capacita automezzo non valida");
    }
}

std::string Automezzo::getTarga() const { return targa; }
double Automezzo::getCapacita() const { return capacita; }

bool Automezzo::operator==(const Automezzo& other) const {
    return targa == other.targa;
}

std::ostream& operator<<(std::ostream& out, const Automezzo& a) {
    out << "Automezzo [Targa: " << a.targa << ", Capacita: " << a.capacita << " kg]";
    return out;
}

// ===== Viaggio =====

Viaggio::Viaggio(const Automezzo& a, const Orario& ora, const Consegna& c)
    : automezzo(a), oraPartenza(ora) {
    consegne.push_back(c);
}

Automezzo Viaggio::getAutomezzo() const { return automezzo; }
Orario Viaggio::getOraPartenza() const { return oraPartenza; }
const std::vector<Consegna>& Viaggio::getConsegne() const { return consegne; }

void Viaggio::aggiungiConsegna(const Consegna& c, int posizione) {
    if (posizione < 0 || posizione > consegne.size()) {
        throw std::invalid_argument("Posizione non valida");
    }
    consegne.insert(consegne.begin() + posizione, c);
}

double Viaggio::getCaricototaleTonellate() const {
    double totale = 0.0;
    for (int i = 0; i < consegne.size(); i++) {
        totale += consegne[i].getQuantita();
    }
    return totale;
}

int Viaggio::getNumeroConsegne() const { return consegne.size(); }

std::ostream& operator<<(std::ostream& out, const Viaggio& v) {
    out << "Viaggio [Automezzo: " << v.automezzo.getTarga()
        << ", Partenza: " << v.oraPartenza
        << ", Consegne: " << v.consegne.size()
        << ", Carico totale: " << v.getCaricototaleTonellate() << " kg]";
    return out;
}

// ===== Corriere =====

Corriere::Corriere(const std::string& n, const Coordinate& dep, const Orario& apertura)
    : nome(n), depositoCoordinate(dep), oraApertura(apertura) {
    if (n.empty()) {
        throw std::invalid_argument("Nome corriere vuoto");
    }
}

std::string Corriere::getNome() const { return nome; }
Coordinate Corriere::getDeposito() const { return depositoCoordinate; }
Orario Corriere::getOraApertura() const { return oraApertura; }
int Corriere::getNumeroAutomezzi() const { return automezzi.size(); }
int Corriere::getNumeroConsegne() const { return consegne.size(); }
int Corriere::getNumeroViaggi() const { return viaggi.size(); }

int Corriere::trovaIndiceAutomezzo(const Automezzo& a) const {
    for (int i = 0; i < automezzi.size(); i++) {
        if (automezzi[i] == a) {
            return i;
        }
    }
    return -1;
}

int Corriere::trovaIndiceConsegna(const Consegna& c) const {
    for (int i = 0; i < consegne.size(); i++) {
        if (consegne[i] == c) {
            return i;
        }
    }
    return -1;
}

int Corriere::trovaIndiceViaggio(const Automezzo& a, const Orario& o) const {
    for (int i = 0; i < viaggi.size(); i++) {
        if (viaggi[i].getAutomezzo() == a && viaggi[i].getOraPartenza() == o) {
            return i;
        }
    }
    return -1;
}

bool Corriere::consegnaGiaInViaggio(const Consegna& c) const {
    for (int i = 0; i < viaggi.size(); i++) {
        const std::vector<Consegna>& cons = viaggi[i].getConsegne();
        for (int j = 0; j < cons.size(); j++) {
            if (cons[j] == c) {
                return true;
            }
        }
    }
    return false;
}

void Corriere::inserisciConsegna(const Consegna& c) {
    // Se la consegna esiste gia, non ha effetto
    if (trovaIndiceConsegna(c) == -1) {
        consegne.push_back(c);
    }
}

void Corriere::inserisciAutomezzo(const Automezzo& a) {
    if (trovaIndiceAutomezzo(a) != -1) {
        throw std::invalid_argument("Automezzo gia presente");
    }
    automezzi.push_back(a);
}

void Corriere::creaViaggio(const Automezzo& a, const Orario& o, const Consegna& c) {
    if (trovaIndiceAutomezzo(a) == -1) {
        throw std::invalid_argument("Automezzo non presente");
    }
    if (trovaIndiceConsegna(c) == -1) {
        throw std::invalid_argument("Consegna non presente");
    }
    if (o < oraApertura) {
        throw std::invalid_argument("Orario partenza prima dell'apertura deposito");
    }
    if (trovaIndiceViaggio(a, o) != -1) {
        throw std::invalid_argument("Viaggio gia presente a quell'orario");
    }
    if (a.getCapacita() < c.getQuantita()) {
        throw std::invalid_argument("Capacita automezzo insufficiente");
    }

    Viaggio v(a, o, c);
    viaggi.push_back(v);
}

void Corriere::inserisciInViaggio(const Automezzo& a, const Orario& o, const Consegna& c, int posizione) {
    int idxViaggio = trovaIndiceViaggio(a, o);
    if (idxViaggio == -1) {
        throw std::invalid_argument("Viaggio non esistente");
    }

    if (posizione < 0 || posizione > viaggi[idxViaggio].getConsegne().size()) {
        throw std::invalid_argument("Posizione non valida nel viaggio");
    }

    if (trovaIndiceConsegna(c) == -1) {
        throw std::invalid_argument("Consegna non presente");
    }

    if (consegnaGiaInViaggio(c)) {
        throw std::invalid_argument("Consegna gia inserita in un viaggio");
    }

    if (viaggi[idxViaggio].getCaricototaleTonellate() + c.getQuantita() > a.getCapacita()) {
        throw std::invalid_argument("Carico totale supererebbe capacita automezzo");
    }

    viaggi[idxViaggio].aggiungiConsegna(c, posizione);
}

Orario Corriere::orarioConsegna(const Consegna& c) const {
    // Trova il viaggio che contiene questa consegna
    for (int i = 0; i < viaggi.size(); i++) {
        const std::vector<Consegna>& cons = viaggi[i].getConsegne();
        for (int j = 0; j < cons.size(); j++) {
            if (cons[j] == c) {
                // Calcola il tempo dal deposito a questa consegna
                Orario orario = viaggi[i].getOraPartenza();

                // Somma i tempi di percorso dalle consegne precedenti
                int tempoMinuti = tempoPercorsoMinuti(depositoCoordinate, cons[0].getLuogo());
                orario = orario + tempoMinuti;

                for (int k = 1; k <= j; k++) {
                    tempoMinuti = tempoPercorsoMinuti(cons[k-1].getLuogo(), cons[k].getLuogo());
                    orario = orario + tempoMinuti;
                }

                return orario;
            }
        }
    }

    throw std::invalid_argument("Consegna non trovata in alcun viaggio");
}

const std::vector<Viaggio>& Corriere::getViaggi() const { return viaggi; }

std::ostream& operator<<(std::ostream& out, const Corriere& cor) {
    out << "Corriere: " << cor.nome
        << " | Automezzi: " << cor.automezzi.size()
        << " | Consegne: " << cor.consegne.size()
        << " | Viaggi: " << cor.viaggi.size();
    return out;
}

// ===== Funzioni esterne =====

double frazioneconsegneEntroOrario(const Corriere& cor, const Automezzo& a, const Orario& orario) {
    const std::vector<Viaggio>& viaggi = cor.getViaggi();

    int consegneEntro = 0;
    int consegneTotali = 0;

    for (int i = 0; i < viaggi.size(); i++) {
        if (viaggi[i].getAutomezzo() == a) {
            const std::vector<Consegna>& consegne = viaggi[i].getConsegne();

            for (int j = 0; j < consegne.size(); j++) {
                Orario oConsegna = cor.orarioConsegna(consegne[j]);
                consegneTotali++;

                if (oConsegna <= orario) {
                    consegneEntro++;
                }
            }
        }
    }

    if (consegneTotali == 0) {
        throw std::invalid_argument("Automezzo non ha consegne");
    }

    return (double)consegneEntro / consegneTotali;
}

int tempoPercorsoMinuti(const Coordinate& da, const Coordinate& a) {
    // Implementazione semplice: formula di distanza approssimata
    // In realta' utilizzerebbe un servizio di mappe (Google Maps, etc.)
    // Qui usiamo una stima semplificata basata sulla distanza geodetica

    double latDiff = a.latitudine - da.latitudine;
    double lonDiff = a.longitudine - da.longitudine;

    // Distanza approssimata in gradi
    double distanzaGradi = std::sqrt(latDiff * latDiff + lonDiff * lonDiff);

    // 1 grado circa 111 km
    double distanzaKm = distanzaGradi * 111.0;

    // Velocita media 60 km/h
    int minutiPercorso = (int)(distanzaKm * 60.0 / 60.0);

    // Almeno 1 minuto
    if (minutiPercorso < 1) {
        minutiPercorso = 1;
    }

    return minutiPercorso;
}
