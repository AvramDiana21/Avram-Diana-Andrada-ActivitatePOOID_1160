#include <iostream>
#include <string>
using namespace std;

// Clasa Aliment
class Aliment {
public:
    string nume;
    int caloriiPerPortie;
    char* origine;
    static int numarTotalAlimente;
    const int gramajPortie;

    // Constructor implicit
    Aliment() : gramajPortie(100) {
        this->nume = "Mere";
        this->caloriiPerPortie = 52;
        this->origine = new char[strlen("Romania") + 1];
        strcpy_s(this->origine, strlen("Romania") + 1, "Romania");
        numarTotalAlimente++;
    }

    // Constructor cu parametri
    Aliment(string nume, int calorii, const char* origine) : gramajPortie(100) {
        this->nume = nume;
        this->caloriiPerPortie = calorii;
        this->origine = new char[strlen(origine) + 1];
        strcpy_s(this->origine, strlen(origine) + 1, origine);
        numarTotalAlimente++;
    }

    // Constructor cu un singur parametru
    Aliment(string nume) : gramajPortie(100) { 
        this->nume = nume;
        this->caloriiPerPortie = 0;
        this->origine = new char[strlen("Necunoscut") + 1];
        strcpy_s(this->origine, strlen("Necunoscut") + 1, "Necunoscut");
        numarTotalAlimente++;
    }

    // Destructor
    ~Aliment() {
        if (this->origine != NULL) {
            delete[] this->origine;
        }
    }

    // Funcție statică pentru procesare
    static void afiseazaNumarTotalAlimente() {
        cout << "Numar total alimente: " << numarTotalAlimente << endl;
    }

    void afisare() {
        cout << "Nume: " << this->nume << endl;
        cout << "Calorii per portie: " << this->caloriiPerPortie << " kcal" << endl;
        cout << "Origine: " << this->origine << endl;
        cout << "Gramaj portie: " << this->gramajPortie << " g" << endl;
        afiseazaNumarTotalAlimente();
    }
};
int Aliment::numarTotalAlimente = 0;


// Clasa Dieta
class Dieta {
public:
    string tipDieta;
    float durataZile;
    char* scop;
    static int numarTotalDiete;
    const float cantitateProteineZilnic;

    //Constructor implicit
    Dieta() :cantitateProteineZilnic(50.0f) {
        this->tipDieta = "Vegetariana";
        this->durataZile = 30;
        this->scop = new char[strlen("Detoxifiere") + 1];
        strcpy_s(this->scop, strlen("Detoxifiere") + 1, "Detoxifiere");
        numarTotalDiete++;
    }

    // Destructor
    ~Dieta() {
        if (this->scop != NULL) {
            delete[] this->scop;
        }
    }

    // Funcție statică pentru procesare
    static void afiseazaNumarTotalDiete() {
        cout << "Numar total diete: " << numarTotalDiete << endl;
    }

    void afisare() {
        cout << "Tip dieta: " << this->tipDieta << endl;
        cout << "Durata in zile: " << this->durataZile << " zile" << endl;
        cout << "Scop: " << this->scop << endl;
        cout << "Cantitate proteine zilnic: " << this->cantitateProteineZilnic << " g" << endl;
        afiseazaNumarTotalDiete();
    }
};
int Dieta::numarTotalDiete = 0;


// Functia main
void main() {
    // Obiecte Aliment
    Aliment aliment1;
    aliment1.afisare();

    Aliment aliment2("Portocale", 47, "Spania");
    aliment2.afisare();

    Aliment aliment3("Banane");
    aliment3.afisare();

    cout << "\n\n";

    // Obiecte Dieta
    Dieta dieta1;
    dieta1.afisare();
}
