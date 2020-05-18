#pragma once
#include "Calatorie.h"

class Autobuz : public Calatorie
{
private:
	int nr_zile_calatorie;
public:
	Autobuz();
	Autobuz(string cod_calatorie, string localitate_de_plecare, string destinatie, string data_plecarii, int nr_locuri_totale, int nr_locuri_rezervate, int nr_zile_calatorie);
	Autobuz(const Autobuz& c);
	~Autobuz();

	Calatorie* clone();

	int getNrZileCalatorie();
	void setNrZileCalatorie(int nr_zile_calatorie);
	Autobuz& operator=(const Autobuz& c);
	bool operator==(const Autobuz& c);
	string toString(string delim);
};