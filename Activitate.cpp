    #include <iostream>
#include <string>
using namespace std;

class Avion {
private:
    int anFabricatie;
    float lungime;
    string model;
    int* codSerie;
    static int numarAvioane;
public:
    Avion() {
        this->anFabricatie = 0;
        this->lungime = 0.0;
        this->model = "";
        this->codSerie = new int(0);
        numarAvioane++;
    }
    Avion(int an, float lung, string mdl, int cod) {
        this->anFabricatie = an;
        this->lungime = lung;
        this->model = mdl;
        this->codSerie = new int(cod);
        numarAvioane++;
    }

    ~Avion() {
        delete codSerie;
        numarAvioane--;
    }

    Avion(const Avion& a) {
        this->anFabricatie = a.anFabricatie;
        this->lungime = a.lungime;
        this->model = a.model;
        this->codSerie = new int(*a.codSerie);
        numarAvioane++;
    }

    Avion& operator=(const Avion& a) {
        if (this != &a) {
            this->anFabricatie = a.anFabricatie;
            this->lungime = a.lungime;
            this->model = a.model;
            delete codSerie;
            this->codSerie = new int(*a.codSerie);
        }
        return *this;
    }

    bool operator==(const Avion& a) const {
        return (this->anFabricatie == a.anFabricatie &&
            this->lungime == a.lungime &&
            this->model == a.model &&
            *this->codSerie == *a.codSerie);
    }

    int getAnFabricatie() { return this->anFabricatie; }
    float getLungime() { return this->lungime; }
    string getModel() { return this->model; }
    int getCodSerie() { return *this->codSerie; }

    static int getNumarAvioane() { return numarAvioane; }
    void setAnFabricatie(int an) { this->anFabricatie = an; }
    void setLungime(float lung) { this->lungime = lung; }
    void setModel(string mdl) { this->model = mdl; }
    void setCodSerie(int cod) { *this->codSerie = cod; }
};

int Avion::numarAvioane = 0;

class Aeroport {
private:
    int capacitate;
    float suprafata;
    string denumire;
    Avion avionInAeroport;
    int numarZboruri;
public:
    Aeroport() {
        this->capacitate = 0;
        this->suprafata = 0.0;
        this->denumire = "";
        this->avionInAeroport = Avion();
        this->numarZboruri = 0;

    }
    Aeroport(int cap, float sup, string nume, Avion avion, int nrZboruri) {
        this->capacitate = cap;
        this->suprafata = sup;
        this->denumire = nume;
        this->avionInAeroport = avion;
        this->numarZboruri = nrZboruri;

    }

    Aeroport(int cap, float sup, string nume, int nrZboruri)
    {
        this->capacitate = cap;
        this->suprafata = sup;
        this->denumire = nume;
        this->numarZboruri = nrZboruri;
    }

    Aeroport& operator=(const Aeroport& b) {
        if (this != &b) {
            this->capacitate = b.capacitate;
            this->suprafata = b.suprafata;
            this->denumire = b.denumire;
            this->avionInAeroport = b.avionInAeroport;
            this->numarZboruri = b.numarZboruri;
        } // FIX: am scos 'p'
        return *this;
    }

    bool operator==(const Aeroport& b) const {
        return (this->capacitate == b.capacitate &&
            this->suprafata == b.suprafata &&
            this->denumire == b.denumire && // FIX: am scos 'p'
            this->avionInAeroport == b.avionInAeroport &&
            this->numarZboruri == b.numarZboruri);
    }

    ~Aeroport() {}

    int getCapacitate() { return capacitate; }
    float getSuprafata() { return suprafata; }
    string getDenumire() { return denumire; }
    Avion getAvionInAeroport() { return avionInAeroport; }
    int getNumarZboruri() { return numarZboruri; }

    void setCapacitate(int cap) { capacitate = cap; }
    void setSuprafata(float sup) { suprafata = sup; }
    void setDenumire(string nume) { denumire = nume; }
    void setNumarZboruri(int nrZboruri) { numarZboruri = nrZboruri; }
};

int main() {
    string model1 = "AN 124";
    Avion avion1(2001, 30.5, model1, 123);
    string model2 = "Airbus A320";
    Avion avion2(2010, 40.2, model2, 456);

    cout << "An fabricatie avion1: " << avion1.getAnFabricatie() << endl;
    cout << "Model avion1: " << avion1.getModel() << endl;
    cout << "CodSerie avion1: " << avion1.getCodSerie() << endl;
    cout << "Lungime avion2: " << avion2.getLungime() << endl;

    avion1.setAnFabricatie(2007);
    avion1.setCodSerie(789);
    avion2.setModel("Boeing 777");
    cout << "Numar total avioane: " << Avion::getNumarAvioane() << endl;

    Aeroport aeroport1(20, 1000.0, "Otopeni", avion1, 5);

    cout << "\nInformatii despre Aeroport:\n";
    cout << "Capacitate: " << aeroport1.getCapacitate() << endl;
    cout << "Suprafata: " << aeroport1.getSuprafata() << endl;
    cout << "Denumire: " << aeroport1.getDenumire() << endl;
    cout << "Numar zboruri: " << aeroport1.getNumarZboruri() << endl;
    cout << "\nInformatii despre Avion in Aeroport:\n";
    cout << "An fabricatie: " << aeroport1.getAvionInAeroport().getAnFabricatie() << endl;
    cout << "Lungime: " << aeroport1.getAvionInAeroport().getLungime() << endl;
    cout << "Model: " << aeroport1.getAvionInAeroport().getModel() << endl;
    cout << "CodSerie: " << aeroport1.getAvionInAeroport().getCodSerie() << endl;

    return 0;
}
