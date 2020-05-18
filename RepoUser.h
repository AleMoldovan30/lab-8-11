#pragma once
#include "Calatorie.h"
#include<iostream>
#include<fstream>
#include "User.h"

using namespace std;

class RepoUser
{
	private:
		string fileName;
	public:
		RepoUser() {}
		RepoUser(string fileName) :fileName(fileName) {}
		~RepoUser() {}

		bool isInFile(User user) {
			ifstream f(this->fileName);
			if (f.is_open())
			{
				while (!f.eof())
				{
					User currentUser;
					f >> currentUser;
					if (currentUser == user)
					{
						return 1;
					}
				}
			}
			return 0;
		}
};

