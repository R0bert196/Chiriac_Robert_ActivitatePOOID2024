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