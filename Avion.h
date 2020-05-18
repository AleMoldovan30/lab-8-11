#pragma once
#include "Calatorie.h"

class Avion : public Calatorie
{
private:
	string escala;
public:
	Avion();
	Avion(string cod_calatorie, string localitate_de_plecare, string destinatie, string data_plecarii, int nr_locuri_totale, int nr_locuri_rezervate, string escala);
	Avion(const Avion& c);
	~Avion();

	Calatorie* clone();

	string getEscala();
	void setEscala(string escala);
	Avion& operator=(const Avion& c);
	bool operator==(const Avion& c);
	string toString(string delim);
};