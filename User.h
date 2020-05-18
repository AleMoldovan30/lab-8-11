#pragma once
#include <string>
#include<ostream>
using namespace std;

class User
{
private:
	string userName;
	string password;
public:
	User() {}
	~User() {}
	User(string u, string p) : userName(u), password(p) {}
	string getUserName() { return userName; }
	string getPassword() { return password; }
	void setUserName(string u) { userName = u; }
	void setPassword(string p) { password = p; }
	bool operator==(const User& u) 
	{return (userName == u.userName)
		and (password == u.password);
	}
	friend istream& operator >> (istream& is, User& u) {
		is >> u.userName >> u.password;
		return is;
	}
	string toString() { return userName + " " + password; }
	string toStringDelimiter(char delim) { return userName + delim + password; }
	
};
