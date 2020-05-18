#include "Autobuz.h"

Autobuz::Autobuz() : Calatorie()
{
	this->nr_zile_calatorie = 0;
}

Autobuz::Autobuz(string cod_calatorie, string localitate_de_plecare, string destinatie, string data_plecarii, int nr_locuri_totale, int nr_locuri_rezervate, int nr_zile_calatorie) : Calatorie(cod_calatorie, localitate_de_plecare, destinatie, data_plecarii, nr_locuri_totale, nr_locuri_rezervate)
{
	this->nr_zile_calatorie = nr_zile_calatorie;

}

Autobuz::Autobuz(const Autobuz& c) : Calatorie(c)
{
	this->nr_zile_calatorie = c.nr_zile_calatorie;
}

Autobuz::~Autobuz()
{
}

Calatorie* Autobuz::clone()
{
	return new Autobuz(this->cod_calatorie, this->localitate_de_plecare, this->destinatie, this->data_plecarii, this->nr_locuri_totale, this->nr_locuri_rezervate, this->nr_zile_calatorie);
}

int Autobuz::getNrZileCalatorie()
{
	return this->nr_zile_calatorie;
}

void Autobuz::setNrZileCalatorie(int nr_zile_calatorie)
{
	this->nr_zile_calatorie = nr_zile_calatorie;
}

Autobuz& Autobuz::operator=(const Autobuz& c)
{
	Calatorie::operator=(c);
	this->nr_zile_calatorie = c.nr_zile_calatorie;
	return *this;
}

bool Autobuz::operator==(const Autobuz& c)
{
	return Calatorie::operator==(c) && this->nr_zile_calatorie == c.nr_zile_calatorie;
}

string Autobuz::toString(string delim)
{
	return "AU" + delim + Calatorie::toString(delim) + delim + to_string(nr_zile_calatorie);
}