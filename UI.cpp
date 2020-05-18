
#include "UI.h"
#include <iostream>
#include <fstream>
#include "RepoFileTXT.h"
#include "ReadFromFileException.h"
#include "ValidationException.h"
#include "RepoException.h"
#include "RepoFileCSV.h"
#include "Util.h"
#include "Autobuz.h"
#include "Avion.h"
#include <sstream>
#include <windows.h>
#include <conio.h> 

using namespace std;

void UI::menu()
{
	cout << "1. Citire din fisier" << endl;
	cout << "2. Afisare calatorii" << endl;
	cout << "3. Adaugare calatorie avion" << endl;
	cout << "4. Adaugare calatorie autobuz" << endl;
	cout << "5. Stergere calatorie" << endl;
	cout << "6. Modificare calatorie avion" << endl;
	cout << "7. Modificare calatorie autobuz" << endl;
	cout << "8. Gasire calatorie dupa data" << endl;
	cout << "9. Rezervare calatorie" << endl;
	cout << "-----------------------------"<< endl;
	cout << "0. Exit" << endl;
	cout << endl << endl << "Alegeti optiunea: ";
}

void UI::chooseFileType()
{
	int option = 0;
	cout << "Alegeti ce tip de fisier doriti."<<endl<<"Scrieti 1 pentru TXT si 2 pentru CSV: ";
	cin >> option;
	while (option < 1 || option > 2)
	{
		cout << "Ati trecut un identificator gresit! Scrieti 1 pt. TXT si 2 pt. CSV: ";
		cin >> option;
	}
	if (option == 1)
	{
		this->s.setRepo(new RepoFileTXT("fisier.txt"));
	}
	else
	{
		this->s.setRepo(new RepoFileCSV("fisier.csv"));
	}
}

void UI::UILoadFromFile()
{
	try {
		this->s.loadFromFile();
	}
	catch (ReadFromFileException& e) {
		cout << e.what() << endl;
		cout << "Dati un alt nume de fisier: ";
		string fileName;
		getline(cin, fileName);
		this->s.setFileName(fileName);
	}
	catch (ValidationException& e) {
		cout << e.what() << endl;
	}
}

void UI::UIAddAv()
{
	
	cout << "Dati cod calatorie: ";
	string codul;
	cin>>codul;

	string loc_plec;
	cout << "Dati localitatea de plecare: ";
	cin>> loc_plec;

	string destinatie;	
	cout << "Dati destinatia: ";
	cin>> destinatie;

	string data_plec;	
	cout << "Dati data plecarii: ";
	cin>>data_plec;

	int loc_totale;
	cout << "Dati numarul de locuri totale: ";
	cin >> loc_totale;
	cin.ignore();

	int loc_rez;	
	cout << "Dati numarul locurilor rezervate: ";
	cin >> loc_rez;
	cin.ignore();

	string escala;	
	cout << "Dati propr de a avea escala (da/nu): ";
	cin>>escala;
	try
	{
		this->s.addAv(codul, loc_plec, destinatie, data_plec, loc_totale, loc_rez, escala);
	}
	catch (ValidationException& e) {
		cout << e.what() << endl;
	}
	catch (RepoException& e) {
		cout << e.what() << endl;
	}
}

void UI::UIAddAu()
{
	cout << "Dati cod calatorie: ";
	string cod;
	cin>>cod;

	cout << "Dati localitatea de plecare: ";
	string loc_plec;
	cin>>loc_plec;

	cout << "Dati destinatia: ";
	string destinatie;
	cin>>destinatie;

	cout << "Dati data plecarii: ";
	string data_plec;
	cin>>data_plec;

	cout << "Dati numarul de locuri totale: ";
	int loc_totale;
	cin >> loc_totale;
	cin.ignore();
	
	cout << "Dati numarul locurilor rezervate: ";
	int loc_rez;
	cin >> loc_rez;
	cin.ignore();
	
	cout << "Dati nr zile calatorie: ";
	int nr_zile;
	cin >> nr_zile;
	cin.ignore();
	
	try
	{
		this->s.addAu(cod, loc_plec, destinatie, data_plec, loc_totale, loc_rez, nr_zile);
	}
	catch (ValidationException& e) {
		cout << e.what() << endl;
	}
	catch (RepoException& e) {
		cout << e.what() << endl;
	}
}

void UI::UIDel()
{
	cout << "Dati codul calatoriei pe care doriti sa o stergeti: ";
	string cod;
	cin>> cod;
	
	try {
		this->s.delAvAu(cod);
	}
	catch (RepoException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::UIUpdAv()
{
	cout << "Dati codul calatoriei pe care doriti sa o modificati: ";
	string codOld;
	cin>>codOld;
	
	string cod;
	cout << "Dati cod calatorie NOU: ";
	cin>>cod;
	
	string loc_plec;
	cout << "Dati localitatea de plecare NOUA: ";
	cin>> loc_plec;
	
	string destinatie;
	cout << "Dati destinatia NOUA: ";
	cin>>destinatie;
	
	string data_plec;
	cout << "Dati data plecarii NOUA: ";
	cin>> data_plec;
	
	int loc_totale;
	cout << "Dati numarul de locuri totale NOU: ";
	cin >> loc_totale;
	
	int loc_rez;
	cout << "Dati numarul locurilor rezervate NOU: ";
	cin >> loc_rez;
	
	string escala;
	cout << "Dati propr de a avea escala (da/nu) NOUA: ";
	cin>>escala;

	try {
		this->s.updateAv(codOld, cod, loc_plec, destinatie, data_plec, loc_totale, loc_rez, escala);
	}
	catch (ValidationException& e) {
		cout << e.what() << endl;
	}
	catch (RepoException& e) {
		cout << e.what() << endl;
	}
}

void UI::UIUpdAu()
{
	cout << "Dati codul calatoriei pe care doriti sa o modificati: ";
	string codOld;
	cin >> codOld;

	string cod;
	cout << "Dati cod calatorie NOU: ";
	cin >> cod;

	string loc_plec;
	cout << "Dati localitatea de plecare NOUA: ";
	cin >> loc_plec;

	string destinatie;
	cout << "Dati destinatia NOUA: ";
	cin >> destinatie;

	string data_plec;
	cout << "Dati data plecarii NOUA: ";
	cin >> data_plec;
	cout << "Dati numarul de locuri totale NOU: ";
	int loc_totale;
	cin >> loc_totale;
	cin.ignore();
	cout << "Dati numarul locurilor rezervate NOU: ";
	int loc_rez;
	cin >> loc_rez;
	cin.ignore();
	cout << "Dati nr zile calatorie: ";
	int nr_zile;
	cin >> nr_zile;
	cin.ignore();
	try {
		this->s.updateAu(codOld, cod, loc_plec, destinatie, data_plec, loc_totale, loc_rez, nr_zile);
	}
	catch (ValidationException& e) {
		cout << e.what() << endl;
	}
	catch (RepoException& e) {
		cout << e.what() << endl;
	}
}

void UI::UIShowAll()
{
	this->print(this->s.getAll());
}
/*
void UI::print(vector<Calatorie*> calatorii)
{
	for (Calatorie* c : calatorii)
	{
		cout << c ->toString(" ").erase(0, 3) << endl;
	}
}*/

void UI::UIFindData()
{
	
	cout << "Dati data dupa care se cauta calatorii: ";
	string data;
	cin>> data;
	this->print(this->s.findDate(data));
}

void UI::UIRezervare()
{
	string cod;
	cout << "Dati codul calatoriei pe care doriti sa o rezervati: ";
	cin>>cod;
	int de_rezervat;
	cout << "Dati numarul de locuri pe care doriti sa le rezervati: ";
	cin >> de_rezervat;
	cin.ignore();
	int status = this->s.rezervare(cod, de_rezervat);
	if (status == 0)
	{
		cout << "Calatoria " + cod + " a fost rezervata cu succes! ";
		return;
	}
	if (status == -1)
	{
		cout << "Nu sunt suficiente locuri libere!";
		return;
	}
	cout << "Nu exista calatorie cu codul: " + cod + "!\n";
}

void UI::print(vector<Calatorie*> calatorii)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, 7);
	//vector<Calatorie> all = this->s.getAll();
	for (Calatorie* c : calatorii)
	{
		if (c->getNrLocuriRezervate() == c->getNrLocuriTotale())
			SetConsoleTextAttribute(console, 13);

		cout << c->toString(" ").erase(0, 3) << endl;
		SetConsoleTextAttribute(console, 7);
	}
}
