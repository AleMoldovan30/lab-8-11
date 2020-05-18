#pragma once
#include "Calatorie.h"
#include "ValidatorAutobuz.h"
#include "ValidatorAvion.h"
#include <vector>

using namespace std;

class RepoFile
{
protected:
	vector<Calatorie*> calatorii;
	string fileName;
	ValidatorAvion validatorAV;
	ValidatorAutobuz validatorAU;
public:
	RepoFile();
	RepoFile(string fileName);
	~RepoFile();
	void setFileName(string fileName);

	vector<Calatorie*> getAll();
	int getSize();
	Calatorie* getCalatorie(int pos);
	int findCalatorie(Calatorie* c);
	void addCalatorie(Calatorie* c);
	void updateCalatorie(Calatorie* cVechi, Calatorie* cNou);
	void deleteCalatorie(Calatorie* c);

	void emptyRepo();

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};