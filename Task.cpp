#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>   
using namespace std;

//CLASA ALIMENT
class Aliment {
private:
    string nume;
    int caloriiPerPortie;
    char* origine;
    static int numarTotalAlimente;
    const int gramajPortie;

public:
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

    Aliment(const Aliment& a) : gramajPortie(a.gramajPortie) {
        this->nume = a.nume;
        this->caloriiPerPortie = a.caloriiPerPortie;

        this->origine = new char[strlen(a.origine) + 1];
        strcpy_s(this->origine, strlen(a.origine) + 1, a.origine);

        numarTotalAlimente++;
    }



    ~Aliment() {
        if (this->origine != NULL) {
            delete[] this->origine;
        }
    }

   
    string getNume() const {
        return this->nume;
    }

    int getCaloriiPerPortie() const {
        return this->caloriiPerPortie;
    }

    const char* getOrigine() const {
        return this->origine;
    }

    int getGramajPortie() const {
        return this->gramajPortie;
    }

    static int getNumarTotalAlimente() {
        return numarTotalAlimente;
    }

   
    void setNume(const string& nume) {
        this->nume = nume;
    }

    void setCaloriiPerPortie(int calorii) {
        this->caloriiPerPortie = calorii;
    }

    void setOrigine(const char* origineNoua) {
        if (origineNoua == nullptr) return;
        if (this->origine != NULL) {
            delete[] this->origine;
        }
        this->origine = new char[strlen(origineNoua) + 1];
        strcpy_s(this->origine, strlen(origineNoua) + 1, origineNoua);
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
private:
    string tipDieta;
    float durataZile;
    char* scop;
    static int numarTotalDiete;
    const float cantitateProteineZilnic;

public:
    Dieta() : cantitateProteineZilnic(50.0f) {
        this->tipDieta = "Vegetariana";
        this->durataZile = 30;
        this->scop = new char[strlen("Detoxifiere") + 1];
        strcpy_s(this->scop, strlen("Detoxifiere") + 1, "Detoxifiere");
        numarTotalDiete++;
    }

    Dieta(string tip, float durata, const char* scop) : cantitateProteineZilnic(50.0f) {
        this->tipDieta = tip;
        this->durataZile = durata;

        this->scop = new char[strlen(scop) + 1];
        strcpy_s(this->scop, strlen(scop) + 1, scop);

        numarTotalDiete++;
    }
    Dieta(string tip, const char* scop) : cantitateProteineZilnic(50.0f) {
        this->tipDieta = tip;
        this->durataZile = 0;   

        this->scop = new char[strlen(scop) + 1];
        strcpy_s(this->scop, strlen(scop) + 1, scop);

        numarTotalDiete++;
    }

    Dieta(const Dieta& d) : cantitateProteineZilnic(d.cantitateProteineZilnic) {
        this->tipDieta = d.tipDieta;
        this->durataZile = d.durataZile;

        this->scop = new char[strlen(d.scop) + 1];
        strcpy_s(this->scop, strlen(d.scop) + 1, d.scop);

        numarTotalDiete++;
    }

    ~Dieta() {
        if (this->scop != NULL) {
            delete[] this->scop;
        }
    }

    string getTipDieta() const {
        return this->tipDieta;
    }

    float getDurataZile() const {
        return this->durataZile;
    }

    const char* getScop() const {
        return this->scop;
    }

    float getCantitateProteineZilnic() const {
        return this->cantitateProteineZilnic;
    }

    static int getNumarTotalDiete() {
        return numarTotalDiete;
    }

    void setTipDieta(const string& tip) {
        this->tipDieta = tip;
    }

    void setDurataZile(float durata) {
        this->durataZile = durata;
    }

    void setScop(const char* scopNou) {
        if (scopNou == nullptr) return;
        if (this->scop != NULL) {
            delete[] this->scop;
        }
        this->scop = new char[strlen(scopNou) + 1];
        strcpy_s(this->scop, strlen(scopNou) + 1, scopNou);
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
private:
    string tipActivitate;
    int durataMinute;
    char* nivelDificultate;
    static int numarTotalActivitati;
    const int caloriiArseEstimativ;

public:
    ActivitateFizica() : caloriiArseEstimativ(200) {
        tipActivitate = "Alergare";
        durataMinute = 30;
        nivelDificultate = new char[strlen("Mediu") + 1];
        strcpy_s(nivelDificultate, strlen("Mediu") + 1, "Mediu");
        numarTotalActivitati++;
    }
    ActivitateFizica(string tip, int durata, const char* nivel)
        : caloriiArseEstimativ(200) {
        this->tipActivitate = tip;
        this->durataMinute = durata;

        this->nivelDificultate = new char[strlen(nivel) + 1];
        strcpy_s(this->nivelDificultate, strlen(nivel) + 1, nivel);

        numarTotalActivitati++;
    }
    ActivitateFizica(string tip, int durata, const char* nivel, int calorii)
        : caloriiArseEstimativ(calorii) {
        this->tipActivitate = tip;
        this->durataMinute = durata;

        this->nivelDificultate = new char[strlen(nivel) + 1];
        strcpy_s(this->nivelDificultate, strlen(nivel) + 1, nivel);

        numarTotalActivitati++;
    }

    ActivitateFizica(const ActivitateFizica& a)
        : caloriiArseEstimativ(a.caloriiArseEstimativ) {

        this->tipActivitate = a.tipActivitate;
        this->durataMinute = a.durataMinute;

        this->nivelDificultate = new char[strlen(a.nivelDificultate) + 1];
        strcpy_s(this->nivelDificultate, strlen(a.nivelDificultate) + 1,
            a.nivelDificultate);

        numarTotalActivitati++;
    }

    ~ActivitateFizica() {
        if (nivelDificultate != NULL) {
            delete[] nivelDificultate;
        }
    }

    string getTipActivitate() const {
        return this->tipActivitate;
    }

    int getDurataMinute() const {
        return this->durataMinute;
    }

    const char* getNivelDificultate() const {
        return this->nivelDificultate;
    }

    int getCaloriiArseEstimativ() const {
        return this->caloriiArseEstimativ;
    }

    static int getNumarTotalActivitati() {
        return numarTotalActivitati;
    }

  
    void setTipActivitate(const string& tip) {
        this->tipActivitate = tip;
    }

    void setDurataMinute(int durata) {
        this->durataMinute = durata;
    }

    void setNivelDificultate(const char* nivelNou) {
        if (nivelNou == nullptr) return;
        if (this->nivelDificultate != NULL) {
            delete[] this->nivelDificultate;
        }
        this->nivelDificultate = new char[strlen(nivelNou) + 1];
        strcpy_s(this->nivelDificultate, strlen(nivelNou) + 1, nivelNou);
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


int main() {
    cout << "=============================================\n";
    cout << "  Alimentatie – Diete – Activitate fizica\n";
    cout << "=============================================\n\n";

    //==================== ALIMENT ====================
    cout << "---------- CLASA ALIMENT ----------\n";

    Aliment aliment1;                               
    cout << "\n[Aliment 1 - constructor implicit]\n";
    aliment1.afisare();

    Aliment aliment2("Portocale", 47, "Spania");  
    cout << "\n[Aliment 2 - constructor cu toti parametrii]\n";
    aliment2.afisare();

    Aliment aliment3("Banane");                    
    cout << "\n[Aliment 3 - constructor cu nume]\n";
    aliment3.afisare();

    cout << "-> Modificam originea lui aliment3 cu setter...\n";
    aliment3.setOrigine("Grecia");
    cout << "Origine noua (getOrigine): " << aliment3.getOrigine() << "\n\n";

    cout << "-> Testare constructor de copiere pentru Aliment (copieAliment din aliment2)\n";
    Aliment copieAliment = aliment2;
    copieAliment.afisare();

    cout << "Numar total obiecte Aliment (get static): "
         << Aliment::getNumarTotalAlimente() << "\n\n";


    //===================== DIETA =====================
    cout << "---------- CLASA DIETA ----------\n";

    Dieta dieta1;                                   
    cout << "\n[Dieta 1 - constructor implicit]\n";
    dieta1.afisare();

    Dieta dieta2("Keto", 21, "Slabire");           
    cout << "\n[Dieta 2 - constructor cu toti parametrii]\n";
    dieta2.afisare();

    Dieta dieta3("Low-carb", "Detox");            
    cout << "\n[Dieta 3 - constructor cu tip + scop]\n";
    dieta3.afisare();

    cout << "-> Modificam durata pentru dieta3 cu setter...\n";
    dieta3.setDurataZile(14);
    cout << "Durata noua (getDurataZile): " << dieta3.getDurataZile() << " zile\n\n";

    cout << "-> Testare constructor de copiere pentru Dieta (copieDieta din dieta2)\n";
    Dieta copieDieta = dieta2;
    copieDieta.afisare();

    cout << "Numar total obiecte Dieta (get static): "
         << Dieta::getNumarTotalDiete() << "\n\n";


    //================= ACTIVITATE FIZICA =================
    cout << "----- CLASA ACTIVITATEFIZICA -----\n";

    ActivitateFizica act1;                         
    cout << "\n[Activitate 1 - constructor implicit]\n";
    act1.afisare();

    ActivitateFizica act2("Inot", 45, "Greu");     
    cout << "\n[Activitate 2 - constructor cu tip/durata/nivel]\n";
    act2.afisare();

    ActivitateFizica act3("Cycling", 60, "Mediu", 450); 
    cout << "\n[Activitate 3 - constructor cu toti parametrii]\n";
    act3.afisare();

    cout << "-> Modificam durata pentru act2 cu setter...\n";
    act2.setDurataMinute(50);
    cout << "Durata noua (getDurataMinute): " << act2.getDurataMinute() << " minute\n\n";

    cout << "-> Testare constructor de copiere pentru ActivitateFizica (copieAct din act2)\n";
    ActivitateFizica copieAct = act2;
    copieAct.afisare();

    cout << "Numar total obiecte ActivitateFizica (get static): "
         << ActivitateFizica::getNumarTotalActivitati() << "\n\n";


    cout << "=============================================\n";
    cout << "   Sfarsit testare clase.\n";
    cout << "=============================================\n";

    return 0;
}
