#include "RepoFileTXT.h"
#include <fstream>
#include "Avion.h"
#include "Autobuz.h"

RepoFileTXT::RepoFileTXT() : RepoFile()
{

}

RepoFileTXT::RepoFileTXT(string fileName) : RepoFile(fileName)
{
}

RepoFileTXT::~RepoFileTXT()
{
}

void RepoFileTXT::loadFromFile()
{
	ifstream f(this->fileName);
	if (f.is_open())
	{
		this->emptyRepo();
		string linie;
		string delim = " ";
		while (getline(f, linie))
		{
			if (linie.substr(0, 2) == "AV")
			{
				linie = linie.erase(0, 3);

				int pos = linie.find(delim);
				string cod_calatorie = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string loc_plecare = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string loc_destinatie = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string data = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int locuri_totale = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int locuri_rezervate = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string escala = linie.substr(0, pos);

				Avion* ca = new Avion(cod_calatorie, loc_plecare, loc_destinatie, data, locuri_totale, locuri_rezervate, escala);
				this->calatorii.push_back(ca);
			}
			else if (linie.substr(0, 2) == "AU")
			{
				linie = linie.erase(0, 3);

				int pos = linie.find(delim);
				string cod_calatorie = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string loc_plecare = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string loc_destinatie = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string data = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int locuri_totale = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int locuri_rezervate = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int nr_zile = stoi(linie.substr(0, pos));

				Autobuz* ca = new Autobuz(cod_calatorie, loc_plecare, loc_destinatie, data, locuri_totale, locuri_rezervate, nr_zile);
				this->calatorii.push_back(ca);
			}
		}
		f.close();
	}
}

void RepoFileTXT::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{
		for (Calatorie* elem : this->calatorii)
		{
			f << elem->toString(" ") << endl;
		}
	}
}