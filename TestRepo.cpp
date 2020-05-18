#include "RepoException.h"
#include "ReadFromFileException.h"
#include <assert.h>
#include "TestRepo.h"
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include "Avion.h"
#include "Autobuz.h"

TestRepoFile::TestRepoFile()
{
	Avion* av = new Avion("121", "Cluj", "Paris", "12.09.2020", 100, 80, "nu");
	Autobuz* au = new Autobuz("115", "Dej", "Gherla", "12.08.2020", 50, 30, 1);
	this->calatoriiIn.push_back(av);
	this->calatoriiIn.push_back(au);
}

TestRepoFile::~TestRepoFile()
{
}

void TestRepoFile::testAll()
{
	this->testGetSize();
	this->testGetAll();
	this->testGetCalatorie();
	this->testAddCalatorie();
	//this->testUpdateProdus();
	this->testDelete();
	/*this->testLoadFromFileTXT();
	this->testLoadFromFileCSV();
	this->testSavetoFileTXT();
	this->testSaveToFileCSV();*/
}

void TestRepoFile::testGetSize()
{
	RepoFile* repoFile = new RepoFileTXT();
	assert(repoFile->getSize() == 0);
	repoFile->addCalatorie(new Avion("121", "Cluj", "Paris", "12.09.2020", 100, 80, "nu"));
	assert(repoFile->getSize() == 1);
}

void TestRepoFile::testGetAll()
{
	RepoFile* repoFile = new RepoFileTXT();
	Avion* av = new Avion("121", "Cluj", "Paris", "12.09.2020", 100, 80, "nu");
	Autobuz* au = new Autobuz("115", "Dej", "Gherla", "12.08.2020", 50, 30, 1);
	repoFile->addCalatorie(av);
	repoFile->addCalatorie(au);
	vector<Calatorie*> calatorii = repoFile->getAll();
	assert(*calatorii[0] == *av);
	assert(*calatorii[1] == *au);
}

void TestRepoFile::testGetCalatorie()
{
	RepoFile* repoFile = new RepoFileTXT();
	Avion* av = new Avion("121", "Cluj", "Paris", "12.09.2020", 100, 80, "nu");
	repoFile->addCalatorie(av);
	try {
		assert(*repoFile->getCalatorie(0) == *av);
	}
	catch (...) {
		assert(false);
	}
	try {
		*(repoFile)->getCalatorie(-1);
	}
	catch (RepoException& e) {
	}
	catch (...) {
		assert(false);
	}
	try {
		*(repoFile)->getCalatorie(1);
	}
	catch (RepoException& e) {
	}
	catch (...) {
		assert(false);
	}
}

void TestRepoFile::testAddCalatorie()
{
	RepoFile* repoFile = new RepoFileTXT();
	Avion* av = new Avion("121", "Cluj", "Paris", "12.09.2020", 100, 80, "nu");
	try {
		repoFile->addCalatorie(av);
	}
	catch (...) {
		assert(false);
	}
	assert(repoFile->getSize() == 1);
	assert(*repoFile->getCalatorie(0) == *av);
	Autobuz* au = new Autobuz("121", "Dej", "Gherla", "12.08.2020", 50, 30, 1);
	try {
		repoFile->addCalatorie(au);
		assert(false);
	}
	catch (RepoException& e) {
	}
	catch (...) {
		assert(false);
	}
	assert(repoFile->getSize() == 1);
	assert(*repoFile->getCalatorie(0) == *av);
}

void TestRepoFile::testDelete()
{
	RepoFile* repoFile = new RepoFileTXT();
	Avion* av = new Avion("121", "Cluj", "Paris", "12.09.2020", 100, 80, "nu");
	repoFile->addCalatorie(av);
	Avion* av1 = new Avion("131", "Cluj", "Viena", "12.09.2020", 100, 80, "nu");
	try {
		repoFile->deleteCalatorie(av1);
		assert(false);
	}
	catch (RepoException& e) {
	}
	catch (...) {
		assert(false);
	}
	assert(repoFile->getSize() == 1);
	assert(*repoFile->getCalatorie(0) == *av);
	try {
		repoFile->deleteCalatorie(av);
	}
	catch (...) {
		assert(false);
	}
	assert(repoFile->getSize() == 0);
}