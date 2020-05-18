#pragma once
#include<string>
#include "ValidatorCalatorie.h"

class ValidatorAutobuz : public ValidatorCalatorie
{
	public:
		ValidatorAutobuz() {}
		~ValidatorAutobuz() {}
		void validate(Calatorie* ca);
};
