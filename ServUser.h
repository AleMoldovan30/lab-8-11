#pragma once
#include "RepoUser.h"

class ServUser
{
private:
	RepoUser repoUser;
public:
	ServUser() {}
	~ServUser() {}
	ServUser(RepoUser& repoUser) :repoUser(repoUser) {}

	bool login(string id, string pass)
	{
		User user(id, pass);
		return repoUser.isInFile(user);
	}
};