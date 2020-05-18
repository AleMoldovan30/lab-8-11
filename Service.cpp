#include "Service.h"
#include "RepoUser.h"
#include "User.h"
#include <string>
#include<iostream>
#include <algorithm>
#include "RepoException.h"
//#include "ValidationException.h"
//#include "ReadFromFileException.h"

using namespace std;

Service::Service()
{
	this->repo = NULL;
}

Service::Service(RepoFile* repo)
{
	this->repo = repo;
}

Service::~Service()
{
	if (this->repo != NULL)
	{
		delete this->repo;
	}
}

vector<Calatorie*> Service::getAll()
{
	return this->repo->getAll();
}

Calatorie* Service::getPoz(int poz) throw(RepoException)
{
	return this->repo->getCalatorie(poz);
}

void Service::addAv(string cod_calatorie, string localitate_de_plecare, string destinatie, string data_plecarii, int nr_loc_totale, int nr_rez, string escala)
	throw(ValidationException, RepoException)
{
	Avion* av = new Avion(cod_calatorie, localitate_de_plecare, destinatie, data_plecarii, nr_loc_totale, nr_rez, escala);
	this->repo->addCalatorie(av);
}

void Service::addAu(string cod_calatorie, string localitate_de_plecare, string destinatie, string data_plecarii, int nr_loc_totale, int nr_rez, int nr_zile_cal)
	throw(ValidationException, RepoException)
{
	Autobuz* au = new Autobuz(cod_calatorie, localitate_de_plecare, destinatie, data_plecarii, nr_loc_totale, nr_rez, nr_zile_cal);
	this->repo->addCalatorie(au);
}

void Service::delAvAu(string cod_calatorie)
	throw(RepoException)
{
	Calatorie* c = new Calatorie(cod_calatorie, "", "", "", 0, 0);
	this->repo->deleteCalatorie(c);
}

void Service::updateAv(string cod_calatorieOld, string cod_calatorie, string localitate_de_plecare, string destinatie, string data_plecarii, int nr_loc_totale, int nr_rez, string escala)
	throw(ValidationException, RepoException)
{
	Calatorie* c = new Calatorie(cod_calatorieOld, "", "", "", 0, 0);
	Avion* avNew = new Avion(cod_calatorie, localitate_de_plecare, destinatie, data_plecarii, nr_loc_totale, nr_rez, escala);
	this->repo->updateCalatorie(c, avNew);
}

void Service::updateAu(string cod_calatorieOld, string cod_calatorie, string localitate_de_plecare, string destinatie, string data_plecarii, int nr_loc_totale, int nr_rez, int nr_zile_cal)
	throw(ValidationException, RepoException)
{
	Calatorie* c = new Calatorie(cod_calatorieOld, "", "", "", 0, 0);
	Autobuz* auNew = new Autobuz(cod_calatorie, localitate_de_plecare, destinatie, data_plecarii, nr_loc_totale, nr_rez, nr_zile_cal);
	this->repo->updateCalatorie(c, auNew);
}

vector<Calatorie*> Service::findDate(string data)
{
	vector<Calatorie*> calatorii = this->repo->getAll();
	vector<Calatorie*> rez;
	for (Calatorie* c : calatorii)
	{
		if (c->getDataPlecarii().compare(data) == 0)
		{
			rez.push_back(c->clone());
		}
	}
	return rez;
}

int Service::rezervare(string cod_calatorie, int de_rezervat)
{
	vector<Calatorie*> calatorii = this->repo->getAll();
	for (Calatorie* c : calatorii)
	{
		if (c->getCodCalatorie() == cod_calatorie)
		{
			if (de_rezervat <= (c->getNrLocuriTotale() - c->getNrLocuriRezervate()))
			{
				c->setNrLocuriRezervate(c->getNrLocuriRezervate() + de_rezervat);
				this->saveToFile();
				return 0;
			}
			else
			{
				return -1;
			}
		}
	}
	return -2;
}

void Service::loadFromFile()
{
	this->repo->loadFromFile();
}

void Service::saveToFile()
{
	this->repo->saveToFile();
}

void Service::setFileName(string fileName)
{
	this->repo->setFileName(fileName);
}

void Service::setRepo(RepoFile* repo)
{
	this->repo = repo;
}

void Service::resetElements(Service s, vector<Calatorie*> calatorii) {
	s.emptyRepo();
	for (Calatorie* c : calatorii)
		s.add(c);
}

void Service::add(Calatorie* c)
{
	this->repo->addCalatorie(c);
}

void Service::deletee(Calatorie* c)
{
	this->repo->deleteCalatorie(c);
}

void Service::emptyRepo()
{
	this->repo->emptyRepo();
}

int Service::getSize()
{
	return this->repo->getSize();
}