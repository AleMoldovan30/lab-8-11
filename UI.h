#pragma once
#include "Service.h"
#include "ServUser.h"

class UI
{
private:
	Service s;
	ServUser ss;
	void menu();
	void chooseFileType();
	void UILoadFromFile();
	void UIAddAv();
	void UIAddAu();
	void UIDel();
	void UIUpdAv();
	void UIUpdAu();
	void UIShowAll();
	void print(vector<Calatorie*> calatorii);

	void UIFindData();
	void UIRezervare();

public:
	UI() {}
	~UI() {}
	void runApplication() {
		cout << endl << "---Autentificare cu succes! :)---" << endl << endl;
		bool done = false;
		do {
			
			int opt;
			menu();
			cin >> opt;
			switch (opt) {
			case 0: {cout << "---Delogare cu succes! :)---" << endl; done = true;break;}
			case 1: {this->UILoadFromFile(); break;}
			case 2: {this->UIShowAll(); break;}
			case 3: {this->UIAddAv(); break;}
			case 4: {this->UIAddAu(); break;}
			case 5: {this->UIDel(); break;}
			case 6: {this->UIUpdAv(); break;}
			case 7: {this->UIUpdAu(); break;}
			case 8: {this->UIFindData(); break;}
			case 9: {this->UIRezervare(); break;}
			default:
				break;
			}
		} while (!done);
	}

	UI(ServUser& serv) :ss(serv) {}
	void runUI() {
		this->chooseFileType();
		cout << "---Login---" << endl;
		cout << "ID: ";
		string id, pass;
		cin >> id;
		cout << "Parola: ";
		cin >> pass;
		if (ss.login(id, pass))
			runApplication();
		else cout << endl << "ID sau parola gresita! Incearca din nou :)" << endl << endl;
		runUI();
	}
};