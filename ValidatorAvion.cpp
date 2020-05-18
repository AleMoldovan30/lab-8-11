#include "ValidatorAvion.h"
#include "Avion.h"
#include "ValidationException.h"

void ValidatorAvion::validate(Calatorie* ca)
{
	ValidatorCalatorie::validate(ca);
	Avion* av = (Avion*)ca;
	if (av->getEscala().empty())
	{
		throw ValidationException("Escala calatoriei nu a fost completata!");
	}
	
}
