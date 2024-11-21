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

// Destructor
Autobuz::~Autobuz()
{
    // delete la producator sa eliberam memoria
    delete[] producator;
}

//overlaod operator=
Autobuz &Autobuz::operator=(const Autobuz &other)
{
    if (this != &other)
    {                        
        delete[] producator; // eliberez memoria veche

        // copiez valorilor din celalalt obiect
        capacitate = other.capacitate;
        nrPersoaneImbarcate = other.nrPersoaneImbarcate;

        // aloc memoria si copiez producatorul
        producator = new char[strlen(other.producator) + 1];
        strcpy(producator, other.producator);
    }
    return *this;
}

//cast la int operator
Autobuz::operator int() const
{
    return nrPersoaneImbarcate;
}

// <<operator overload
ostream &operator<<(ostream &out, const Autobuz &autobuz)
{
    out << "ID: " << autobuz.idAutobuz << "; Capacitate: " << autobuz.capacitate
        << "; Imbarcati: " << autobuz.nrPersoaneImbarcate
        << "; Producator: " << autobuz.producator << ";\n";
    return out;
}

//>operator overlaod
bool Autobuz::operator>(const Autobuz &other) const
{
    return this->capacitate > other.capacitate;
}


//getteri si setteri cu validari
int Autobuz::getCapacitate() const
{
    return capacitate;
}

void Autobuz::setCapacitate(int capacitate)
{
    if (capacitate < 0)
    {
        throw invalid_argument("Capacitatea nu poate fi negativa.");
    }
    this->capacitate = capacitate;
}

const char *Autobuz::getProducator() const
{
    return producator;
}

void Autobuz::setProducator(const char *prod)
{
    delete[] producator;
    producator = new char[strlen(prod) + 1];
    strcpy(producator, prod);
}


int Autobuz::getNumarLocuriLibere() const
{
    return capacitate - nrPersoaneImbarcate;
}