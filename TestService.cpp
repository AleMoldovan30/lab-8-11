#include "TestService.h"
#include <assert.h>
#include "Service.h"
#include "RepoFileTXT.h"
#include "Avion.h"
#include "Autobuz.h"
#include "RepoException.h"
#include <vector>

TestService::TestService() {}

TestService::~TestService() {}

void TestService::testAll()
{
	this->testGetAll();
	//this->testGetPos();
	this->testAddAv();
	//this->testAddAu();
	//this->testUpdAv();
	//this->testUpdAu();
	this->testDel();
	this->testLive();

	this->testFindDate();
	/*this->testRezervare();*/
}

void TestService::testGetAll()
{
	Service s;
	RepoFile* repoFile = new RepoFileTXT();
	s.setRepo(repoFile);
	Avion* av = new Avion("121", "Cluj", "Paris", "12.09.2020", 100, 80, "nu");
	Autobuz* au = new Autobuz("115", "Dej", "Gherla", "12.08.2020", 50, 30, 1);
	s.addAv(av->getCodCalatorie(), av->getLocalitateDePlecare(), av->getDestinatie(), av->getDataPlecarii(), av->getNrLocuriTotale(), av->getNrLocuriRezervate(), av->getEscala());
	s.addAu(au->getCodCalatorie(), au->getLocalitateDePlecare(), au->getDestinatie(), au->getDataPlecarii(), au->getNrLocuriTotale(), au->getNrLocuriRezervate(), au->getNrZileCalatorie());
	vector<Calatorie*> calatorii = s.getAll();
	assert(*calatorii[0] == *av);
	assert(*calatorii[1] == *au);
}

void TestService::testAddAv()
{
	Service s;
	RepoFile* repoFile = new RepoFileTXT();
	s.setRepo(repoFile);
	Avion* av = new Avion("121", "Cluj", "Paris", "12.09.2020", 100, 80, "nu");
	try {
		s.addAv(av->getCodCalatorie(), av->getLocalitateDePlecare(), av->getDestinatie(), av->getDataPlecarii(), av->getNrLocuriTotale(), av->getNrLocuriRezervate(), av->getEscala());
	}
	catch (...) {
		assert(false);
	}
	assert(*s.getPoz(0) == *av);
	Avion* av1 = new Avion("121", "Cluj", "Moscova", "12.09.2020", 210, 200, "da");
	try {
		s.addAv(av1->getCodCalatorie(), av1->getLocalitateDePlecare(), av1->getDestinatie(), av1->getDataPlecarii(), av1->getNrLocuriTotale(), av1->getNrLocuriRezervate(), av1->getEscala());
		assert(false);
	}
	catch (RepoException& e) {
	}
	catch (...) {
		assert(false);
	}
	assert(*s.getPoz(0) == *av);
}

void TestService::testDel()
{
	Service s;
	RepoFile* repoFile = new RepoFileTXT();
	s.setRepo(repoFile);
	Avion* av = new Avion("121", "Cluj", "Paris", "12.09.2020", 100, 80, "nu");
	s.addAv(av->getCodCalatorie(), av->getLocalitateDePlecare(), av->getDestinatie(), av->getDataPlecarii(), av->getNrLocuriTotale(), av->getNrLocuriRezervate(), av->getEscala());
	try {
		s.delAvAu("100");
		assert(false);
	}
	catch (RepoException& e) {
	}
	catch (...) {
		assert(false);
	}
	assert(*s.getPoz(0) == *av);
	try {
		s.delAvAu(av->getCodCalatorie());
	}
	catch (...) {
		assert(false);
	}
}

void TestService::testFindDate()
{
	Service s;
	RepoFile* repoFile = new RepoFileTXT();
	s.setRepo(repoFile);
	Avion* av = new Avion("121", "Cluj", "Paris", "12.09.2020", 100, 80, "nu");
	Autobuz* au = new Autobuz("115", "Dej", "Gherla", "12.08.2020", 50, 30, 1);
	s.addAv(av->getCodCalatorie(), av->getLocalitateDePlecare(), av->getDestinatie(), av->getDataPlecarii(), av->getNrLocuriTotale(), av->getNrLocuriRezervate(), av->getEscala());
	s.addAu(au->getCodCalatorie(), au->getLocalitateDePlecare(), au->getDestinatie(), au->getDataPlecarii(), au->getNrLocuriTotale(), au->getNrLocuriRezervate(), au->getNrZileCalatorie());
	
	vector<Calatorie*> rez = s.findDate("12.08.2021");
	assert(rez.size() == 0);
	
	rez = s.findDate("12.09.2020");
	assert(rez.size() == 1);
	assert(*rez[0] == *av);

	rez = s.findDate("12.08.2020");
	assert(rez.size() == 1);
	assert(*rez[0] == *au);

}

void TestService::testLive()
{
	
	Avion* c1 = new Avion("156", "Cluj-Napoca", "Dubai", "14.06.2020", 100, 80, "nu");
	Autobuz* c2 = new Autobuz("873", "Constanta", "Cluj-Napoca", "15.07.2020", 40, 20, 1);
	Autobuz* c3 = new Autobuz("118", "Vienna", "Bucuresti", "14.06.2020", 3, 80, 50);
	Avion* c4 = new Avion("122", "Bucuresti", "Cluj-Napoca", "14.06.2020", 100, 80, "nu");
	Avion* c5 = new Avion("122", "Cluj-Napoca", "Bucuresti", "14.06.2020", 100, 80, "nu");

	Service s;
	vector<Calatorie*> defaultTrips;
	/*Service service;
	vector<Calatorie> defaultTrips;*/
	defaultTrips.push_back(c1);
	defaultTrips.push_back(c2);
	defaultTrips.push_back(c3);
	defaultTrips.push_back(c4);
	defaultTrips.push_back(c5);
	
	s.resetElements(s, defaultTrips);

	s.deletee(c1);
	assert(s.getSize() == 3);
	assert(*s.getPoz(0) == *c2);
	assert(*s.getPoz(1) == *c3);
	assert(*s.getPoz(2) == *c5);

	s.resetElements(s, defaultTrips);

	s.deletee(c2);
	assert(s.getSize() == 4);
	assert(*(s.getPoz(0)) == *c1);
	assert(*(s.getPoz(1)) == *c3);
	assert(*(s.getPoz(2)) == *c4);
	assert(*(s.getPoz(3)) == *c5);

	s.resetElements(s, defaultTrips);

	s.deletee(c3);
	assert(s.getSize() == 3);
	assert(*(s.getPoz(0)) == *c1);
	assert(*(s.getPoz(1)) == *c2);
	assert(*(s.getPoz(2)) == *c5);

	s.resetElements(s, defaultTrips);
	s.deletee(c4);
	assert(s.getSize() == 1);
	assert(*(s.getPoz(0)) == *c2);


	s.resetElements(s, defaultTrips);
	s.deletee(c5);
	assert(s.getSize() == 3);
	assert(*(s.getPoz(0)) == *c1);
	assert(*(s.getPoz(1)) == *c2);
	assert(*(s.getPoz(2)) == *c3);



}