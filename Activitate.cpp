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

