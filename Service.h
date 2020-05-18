#pragma once
#include "RepoFile.h"
#include "RepoFileCSV.h"
#include "RepoFileTXT.h"
#include "RepoUser.h"
#include "User.h"
#include "Autobuz.h"
#include "Avion.h"
#include <string>
#include <vector>

class Service
{
private:
	RepoFile* repo;
public:
	Service();
	Service(RepoFile* repo);
	~Service();

	vector<Calatorie*> getAll();
	vector<Calatorie*> findDate(string dataPlec);

	Calatorie* getPoz(int poz);
	int getSize();
	int rezervare(string cod_calatorie, int de_rezervat);

	void addAv(string cod_calatorie, string localitate_de_plecare, string destinatie, string data_plecarii, int nr_loc_totale, int nr_rez, string escala);
	void addAu(string cod_calatorie, string localitate_de_plecare, string destinatie, string data_plecarii, int nr_loc_totale, int nr_rez, int nr_zile_cal);
	void updateAv(string cod_calatorieOld, string cod_calatorie, string localitate_de_plecare, string destinatie, string data_plecarii, int nr_loc_totale, int nr_rez, string escala);
	void delAvAu(string cod_calatorie);
	void updateAu(string cod_calatorieOld, string cod_calatorie, string localitate_de_plecare, string destinatie, string data_plecarii, int nr_loc_totale, int nr_rez, int nr_zile_cal);

	void emptyRepo();
	void add(Calatorie* c);
	void deletee(Calatorie* c);
	void resetElements(Service s, vector<Calatorie*> calatorii);
	void loadFromFile();
	void saveToFile();
	void setFileName(string fileName);
	void setRepo(RepoFile* repo);
};