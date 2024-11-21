#include "Autobuz.h"
#include <cstring>
#include <stdexcept>

using namespace std;

Autobuz::Autobuz()
    : idAutobuz(++nrAutobuze), capacitate(0), nrPersoaneImbarcate(0), producator(nullptr)
{
    producator = new char[8];
    strcpy(producator, "Necunoscut");
}

// COcstructorul cu parametrii
Autobuz::Autobuz(int capacitate, int nrPersoane, const char *prod)
    : idAutobuz(++nrAutobuze)
{
    // valdiare pe input
    if (capacitate < 0)
    {
        throw invalid_argument("Capacitatea nu poate fi negativa");
    }
    if (nrPersoane < 0 || nrPersoane > capacitate)
    {
        throw invalid_argument("Numarul de persoane imbarcate nu este valid");
    }
    this->capacitate = capacitate;
    this->nrPersoaneImbarcate = nrPersoane;

    producator = new char[strlen(prod) + 1];
    strcpy(producator, prod);
}

// Copy construct
Autobuz::Autobuz(const Autobuz &other)
    : idAutobuz(++nrAutobuze)
{
    capacitate = other.capacitate;
    nrPersoaneImbarcate = other.nrPersoaneImbarcate;
    producator = new char[strlen(other.producator) + 1];
    strcpy(producator, other.producator);
}