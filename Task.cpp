#include <iostream>
#include <string>
#include <cstring>   
using namespace std;


//CLASA ALIMENT
class Aliment {
public:
    string nume;
    int caloriiPerPortie;
    char* origine;
    static int numarTotalAlimente;
    const int gramajPortie;

    // Constructori
    Aliment() : gramajPortie(100) {
        this->nume = "Mere";
        this->caloriiPerPortie = 52;
        this->origine = new char[strlen("Romania") + 1];
        strcpy_s(this->origine, strlen("Romania") + 1, "Romania");
        numarTotalAlimente++;
    }
    Aliment(string nume, int calorii, const char* origine) : gramajPortie(100) {
        this->nume = nume;
        this->caloriiPerPortie = calorii;
        this->origine = new char[strlen(origine) + 1];
        strcpy_s(this->origine, strlen(origine) + 1, origine);
        numarTotalAlimente++;
    }
    Aliment(string nume) : gramajPortie(100) {
        this->nume = nume;
        this->caloriiPerPortie = 0;
        this->origine = new char[strlen("Necunoscut") + 1];
        strcpy_s(this->origine, strlen("Necunoscut") + 1, "Necunoscut");
        numarTotalAlimente++;
    }



    ~Aliment() {
        if (this->origine != NULL) {
            delete[] this->origine;
        }
    }

    static void afiseazaNumarTotalAlimente() {
        cout << "Numar total alimente: " << numarTotalAlimente << endl;
    }

    void afisare() {
        cout << "Nume: " << this->nume << endl;
        cout << "Calorii per portie: " << this->caloriiPerPortie << " kcal" << endl;
        cout << "Origine: " << this->origine << endl;
        cout << "Gramaj portie: " << this->gramajPortie << " g" << endl;
        afiseazaNumarTotalAlimente();
        cout << endl;
    }
};

int Aliment::numarTotalAlimente = 0;


//CLASA DIETA 
class Dieta {
public:
    string tipDieta;
    float durataZile;
    char* scop;
    static int numarTotalDiete;
    const float cantitateProteineZilnic;

    Dieta() : cantitateProteineZilnic(50.0f) {
        this->tipDieta = "Vegetariana";
        this->durataZile = 30;
        this->scop = new char[strlen("Detoxifiere") + 1];
        strcpy_s(this->scop, strlen("Detoxifiere") + 1, "Detoxifiere");
        numarTotalDiete++;
    }

    ~Dieta() {
        if (this->scop != NULL) {
            delete[] this->scop;
        }
    }

    static void afiseazaNumarTotalDiete() {
        cout << "Numar total diete: " << numarTotalDiete << endl;
    }

    void afisare() {
        cout << "Tip dieta: " << this->tipDieta << endl;
        cout << "Durata in zile: " << this->durataZile << " zile" << endl;
        cout << "Scop: " << this->scop << endl;
        cout << "Cantitate proteine zilnic: " << this->cantitateProteineZilnic << " g" << endl;
        afiseazaNumarTotalDiete();
        cout << endl;
    }
};

int Dieta::numarTotalDiete = 0;


//CLASA ACTIVITATEFIZICA 
class ActivitateFizica {
public:
    string tipActivitate;
    int durataMinute;
    char* nivelDificultate;
    static int numarTotalActivitati;
    const int caloriiArseEstimativ;

    ActivitateFizica() : caloriiArseEstimativ(200) {
        tipActivitate = "Alergare";
        durataMinute = 30;
        nivelDificultate = new char[strlen("Mediu") + 1];
        strcpy_s(nivelDificultate, strlen("Mediu") + 1, "Mediu");
        numarTotalActivitati++;
    }

    ~ActivitateFizica() {
        if (nivelDificultate != NULL) {
            delete[] nivelDificultate;
        }
    }

    static void afiseazaNumarTotalActivitati() {
        cout << "Numar total activitati fizice: " << numarTotalActivitati << endl;
    }

    void afisare() {
        cout << "Tip activitate: " << tipActivitate << endl;
        cout << "Durata: " << durataMinute << " minute" << endl;
        cout << "Nivel dificultate: " << nivelDificultate << endl;
        cout << "Calorii arse estimativ: " << caloriiArseEstimativ << " kcal" << endl;
        afiseazaNumarTotalActivitati();
        cout << endl;
    }
};

int ActivitateFizica::numarTotalActivitati = 0;


//MAIN 
int main() {
    //Aliment
    Aliment aliment1;
    aliment1.afisare();

    Aliment aliment2("Portocale", 47, "Spania");
    aliment2.afisare();

    Aliment aliment3("Banane");
    aliment3.afisare();

    cout << "\n";

    //Dieta
    Dieta dieta1;
    dieta1.afisare();

    cout << "\n";

    //ActivitateFizica
    ActivitateFizica act1;
    act1.afisare();

    return 0;
}
