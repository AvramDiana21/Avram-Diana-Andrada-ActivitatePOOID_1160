#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class CarteDinBiblioteca {
private:
	char* titlu;
	int numarPagini;

public:

	CarteDinBiblioteca(const char* titluP, int paginiP) {
		titlu = new char[strlen(titluP) + 1];
		strcpy(titlu, titluP);

		numarPagini = paginiP;

	}

	CarteDinBiblioteca(const CarteDinBiblioteca& c) {
		titlu = new char[strlen(c.titlu) + 1];
		strcpy(titlu, c.titlu);

		numarPagini = c.numarPagini;
	}

	CarteDinBiblioteca& operator=(const CarteDinBiblioteca& c) {
		if(this != &c){
		delete[]titlu;
		titlu = new char[strlen(c.titlu) + 1];
		strcpy(titlu, c.titlu);

		numarPagini = c.numarPagini;
		}
		return *this;
	}

	void setTitlu(const char* titluN) {
		delete[]titlu;
		titlu = new char[strlen(titluN) + 1];
		strcpy(titlu, titluN);
	}
	void setNr(int nr) {
		if (nr > 1) {
			numarPagini = nr;
		}
		else {
			cout << "NaN";
		}
	}

	const char* getTitlu()const { return titlu; }
	int getNr()const { return numarPagini; }

	~CarteDinBiblioteca() {
		delete[]titlu;
	}

	void afiseaza() const{
		cout << "Titlu: " << titlu << " , nr pagini: " << numarPagini << endl;
	}
};
ostream& operator<<(ostream& out, const CarteDinBiblioteca& c) {
	out << "Titlu: " << c.getTitlu() << " , Nr pg: " << c.getNr();
	return out;
	}


istream& operator>>(istream& in, CarteDinBiblioteca& c) {
	char buffer[100];
	int n;

	cout << "Titlu: ";
	in >> buffer;

	cout << "Nr pg: ";
	in >> n;

	c.setTitlu(buffer);
	c.setNr(n);

	return in;
}


int main() {

	CarteDinBiblioteca c1("Dracula", 395);
	c1.afiseaza();

	CarteDinBiblioteca* c = new CarteDinBiblioteca("Dracula - Ed new", 395);
	c->afiseaza();
	delete c;

	CarteDinBiblioteca c2 = c1;
	c2.afiseaza();

	CarteDinBiblioteca c3("Legende",532);
	cin >> c3;
	cout << c3 << endl;


	return 0;
}

