#include <iostream>
#include <string>
#include "RepoFile.h"
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include"TestService.h"
#include "UI.h"
#include "TestRepo.h"
//#include "TestCalatorie.h"
//#include "TestAvion.h"
//#include "TestAutobuz.h"
//#include "TestRepoFile.h"
//#include "TesteLive.h"

using namespace std;

int main()
{
    TestService testService;
    testService.testAll();
    TestRepoFile testRepo;
    testRepo.testAll();
    cout << "Start!" << endl;
    cout << "Gata!" << endl;

    

    RepoUser repoUser("id.txt");
    ServUser servUser(repoUser);
    UI ui(servUser);
    ui.runUI();
}