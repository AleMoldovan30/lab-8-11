#include "Avion.h"

Avion::Avion() :Calatorie()
{
}

Avion::Avion(string cod_calatorie, string localitate_de_plecare, string destinatie, string data_plecarii, int nr_locuri_totale, int nr_locuri_rezervate, string escala) : Calatorie(cod_calatorie, localitate_de_plecare, destinatie, data_plecarii, nr_locuri_totale, nr_locuri_rezervate)
{
	this->escala = escala;

}

Avion::Avion(const Avion& c) : Calatorie(c)
{
	this->escala = c.escala;
}

Avion::~Avion()
{
}

Calatorie* Avion::clone()
{
	return new Avion(this->cod_calatorie, this->localitate_de_plecare, this->destinatie, this->data_plecarii, this->nr_locuri_totale, this->nr_locuri_rezervate, this->escala);
}

string Avion::getEscala()
{
	return this->escala;
}

void Avion::setEscala(string escala)
{
	this->escala = escala;
}

Avion& Avion::operator=(const Avion& c)
{
	Calatorie::operator=(c);
	this->escala = c.escala;
	return *this;
}

bool Avion::operator==(const Avion& c)
{
	return Calatorie::operator==(c) && this->escala == c.escala;
}

string Avion::toString(string delim)
{
	return "AV" + delim + Calatorie::toString(delim) + delim + escala;
}