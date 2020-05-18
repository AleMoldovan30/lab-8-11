#include "Calatorie.h"
#include <cstring>
#include<iostream>
Calatorie::Calatorie()
{
	this->nr_locuri_totale = 0;
	this->nr_locuri_rezervate = 0;
}

Calatorie::Calatorie(string cod_calatorie, string localitate_de_plecare, string destinatie, string data_plecarii, int nr_locuri_totale, int nr_locuri_rezervate)
{
	this->cod_calatorie = cod_calatorie;
	this->localitate_de_plecare = localitate_de_plecare;
	this->destinatie = destinatie;
	this->data_plecarii = data_plecarii;
	this->nr_locuri_totale = nr_locuri_totale;
	this->nr_locuri_rezervate = nr_locuri_rezervate;
}

Calatorie::Calatorie(const Calatorie& c)
{
	this->cod_calatorie = c.cod_calatorie;
	this->localitate_de_plecare = c.localitate_de_plecare;
	this->destinatie = c.destinatie;
	this->data_plecarii = c.data_plecarii;
	this->nr_locuri_totale = c.nr_locuri_totale;
	this->nr_locuri_rezervate = c.nr_locuri_rezervate;
}

Calatorie::~Calatorie()
{
}

Calatorie* Calatorie::clone()
{
	return new Calatorie(this->cod_calatorie, this->localitate_de_plecare, this->destinatie, this->data_plecarii, this->nr_locuri_totale, this->nr_locuri_rezervate);

}

string Calatorie::getCodCalatorie()
{
	return this->cod_calatorie;
}

string Calatorie::getLocalitateDePlecare()
{
	return this->localitate_de_plecare;
}

string Calatorie::getDestinatie()
{
	return this->destinatie;
}

string Calatorie::getDataPlecarii()
{
	return this->data_plecarii;
}

int Calatorie::getNrLocuriTotale()
{
	return this->nr_locuri_totale;
}

int Calatorie::getNrLocuriRezervate()
{
	return this->nr_locuri_rezervate;
}

void Calatorie::setCodCalatorie(string cod_calatorie)
{
	this->cod_calatorie = cod_calatorie;
}

void Calatorie::setLocalitateDePlecare(string localitate_de_plecare)
{
	this->localitate_de_plecare = localitate_de_plecare;
}

void Calatorie::setDestinatie(string destinatie)
{
	this->destinatie = destinatie;
}

void Calatorie::setDataPlecarii(string data_plecarii)
{
	this->data_plecarii = data_plecarii;
}

void Calatorie::setNrLocuriTotale(int nr_locuri_totale)
{
	this->nr_locuri_totale = nr_locuri_totale;
}

void Calatorie::setNrLocuriRezervate(int nr_locuri_rezervate)
{
	this->nr_locuri_rezervate = nr_locuri_rezervate;
}

Calatorie& Calatorie::operator=(const Calatorie& c)
{
	this->cod_calatorie = c.cod_calatorie;
	this->localitate_de_plecare = c.localitate_de_plecare;
	this->destinatie = c.destinatie;
	this->data_plecarii = c.data_plecarii;
	this->nr_locuri_totale = c.nr_locuri_totale;
	this->nr_locuri_rezervate = c.nr_locuri_rezervate;
	return *this;
}

bool Calatorie::operator==(const Calatorie& c)
{
	return this->cod_calatorie == c.cod_calatorie &&
		this->localitate_de_plecare == c.localitate_de_plecare &&
		this->destinatie == c.destinatie &&
		this->data_plecarii == c.data_plecarii &&
		this->nr_locuri_totale == c.nr_locuri_totale &&
		this->nr_locuri_rezervate == c.nr_locuri_rezervate;
}

string Calatorie::toString(string delim)
{
	return this->cod_calatorie + delim + this->localitate_de_plecare + delim + this->destinatie + delim + this->data_plecarii +
		delim + to_string(nr_locuri_totale) + delim + to_string(nr_locuri_rezervate);
}