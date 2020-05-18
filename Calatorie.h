#pragma once
#include <string>

using namespace std;

class Calatorie
{
protected:
	string cod_calatorie;
	string localitate_de_plecare;
	string destinatie;
	string data_plecarii;
	int nr_locuri_totale;
	int nr_locuri_rezervate;
public:
	Calatorie();
	Calatorie(string cod_calatorie, string localitate_de_plecare, string destinatie, string data_plecarii, int nr_locuri_totale, int nr_locuri_rezervate);
	Calatorie(const Calatorie& c);
	~Calatorie();

	virtual Calatorie* clone();

	string getCodCalatorie();
	string getLocalitateDePlecare();
	string getDestinatie();
	string getDataPlecarii();
	int getNrLocuriTotale();
	int getNrLocuriRezervate();

	void setCodCalatorie(string cod_calatorie);
	void setLocalitateDePlecare(string localitate_de_plecare);
	void setDestinatie(string destinatie);
	void setDataPlecarii(string data_plecarii);
	void setNrLocuriTotale(int nr_locuri_totale);
	void setNrLocuriRezervate(int nr_locuri_rezervate);

	Calatorie& operator=(const Calatorie& c);
	bool operator==(const Calatorie& c);
	virtual string toString(string delim);
};