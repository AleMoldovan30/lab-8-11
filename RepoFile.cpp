#include "RepoFile.h"
#include "RepoException.h"
#include "ValidationException.h"
#include <typeinfo>
#include "Autobuz.h"
#include "Avion.h"

RepoFile::RepoFile()
{
}

RepoFile::RepoFile(string fileName)
{
	this->fileName = fileName;
}

RepoFile::~RepoFile()
{
	this->emptyRepo();
}

void RepoFile::setFileName(string fileName)
{
	this->fileName = fileName;
}

vector<Calatorie*> RepoFile::getAll()
{
	return this->calatorii;
}

int RepoFile::getSize()
{
	return int(this->calatorii.size());
}

Calatorie* RepoFile::getCalatorie(int pos)
{
	if (pos >= 0 && pos < this->getSize())
	{
		return this->calatorii[pos]->clone();
	}
	return new Calatorie();
}

void RepoFile::addCalatorie(Calatorie* c)
{
	if (typeid(*c) == typeid(Avion))
	{
		this->validatorAV.validate(c);
	}
	if (typeid(*c) == typeid(Autobuz))
	{
		this->validatorAU.validate(c);
	}
	if (this->findCalatorie(c) >= 0)
	{
		throw RepoException("Exista deja o calatorie cu codul dat!");
	}
	this->calatorii.push_back(c->clone());
	this->saveToFile();
}

int RepoFile::findCalatorie(Calatorie* c)
{
	for (int i = 0; i < this->calatorii.size(); i++)
	{
		if (this->calatorii[i]->getCodCalatorie() == c->getCodCalatorie())
		{
			return i;
		}
	}
	return -1;
}

void RepoFile::updateCalatorie(Calatorie* cVeche, Calatorie* cNoua)
{
	if (typeid(*cNoua) == typeid(Avion))
	{
		this->validatorAV.validate(cNoua);
	}
	if (typeid(*cNoua) == typeid(Autobuz))
	{
		this->validatorAU.validate(cNoua);
	}
	if (this->findCalatorie(cVeche) < 0)
	{
		throw RepoException("Nu exista nicio calatorie cu codul dat!");
	}
	for (int i = 0; i < this->calatorii.size(); i++)
	{
		if (this->getCalatorie(i)->getCodCalatorie() == cVeche->getCodCalatorie())
		{
			delete this->calatorii[i];
			this->calatorii[i] = cNoua->clone();
			this->saveToFile();
			return;
		}
	}
	throw RepoException("Nu exista nicio calatorie cu codul dat!");

}

void RepoFile::deleteCalatorie(Calatorie* c)
	throw(RepoException)
{
	for (int i = 0; i < this->calatorii.size(); i++)
	{

		//if (**(this->calatorii.begin() + i) == *c)
		if (this->calatorii[i]->getCodCalatorie() == c->getCodCalatorie())
		{
			delete this->calatorii[i];
			this->calatorii.erase(this->calatorii.begin() + i);
			this->saveToFile();
			return;
		}
	}
	throw RepoException("Nu exista nicio calatorie cu un astfel de cod");
}

void RepoFile::emptyRepo()
{
	for (int i = 0; i < this->getSize(); i++)
	{
		delete this->calatorii[i];
	}
	this->calatorii.clear();
}