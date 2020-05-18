#pragma once
#include<string>
#include "ValidatorCalatorie.h"

class ValidatorAvion : public ValidatorCalatorie
{
	public:
		ValidatorAvion() {}
		~ValidatorAvion() {}
		void validate(Calatorie* ca);
};