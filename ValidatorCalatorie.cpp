#include "ValidationException.h"
#include "ValidatorCalatorie.h"

void ValidatorCalatorie::validate(Calatorie* ca)
{
	if (ca->getCodCalatorie().empty())
	{
		throw ValidationException("Codul calatoriei nu a fost completat!");
	}
	for (char c : ca->getDestinatie())
	{
		if (!isalpha(c))
		{
			throw ValidationException("Destinatia poate sa contina doar litere!");
		}
	}
	for (char x : ca->getLocalitateDePlecare())
	{
		if (!isalpha(x))
		{
			throw ValidationException("Localitatea de plecare poate sa contina doar litere!");
		}
	}
	if (ca->getNrLocuriTotale() < -1)
	{
		throw ValidationException("Numarul total al locurilor trebuie sa fie strict pozitiv!");
	}
	if (ca->getNrLocuriRezervate() < -1)
	{
		throw ValidationException("Numarul de locuri rezervate trebuie sa fie strict pozitiv!");
	}
}