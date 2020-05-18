#include "ValidatorAutobuz.h"
#include "Autobuz.h"
#include "ValidationException.h"

void ValidatorAutobuz::validate(Calatorie* ca)
{
	ValidatorCalatorie::validate(ca);
	Autobuz* au = (Autobuz*)ca;
	if (au->getNrZileCalatorie() < -1)
	{
		throw ValidationException("Numarul de zile al calatoriei nu poate fi negativ!");
	}
}
