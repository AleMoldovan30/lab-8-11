#pragma once
#include<string>
#include "Calatorie.h"
#include "ValidationException.h"
using namespace std;

class ValidatorCalatorie 
{
	public:
		ValidatorCalatorie() {}
		~ValidatorCalatorie() {}
		virtual void validate(Calatorie* ca);
};