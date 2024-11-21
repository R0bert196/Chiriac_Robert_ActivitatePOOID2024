#include <iostream>
#include <cstring>
using namespace std;

class Autobuz
{
private:
    static int nrAutobuze;
    const int idAutobuz;
    int capacitate;
    int nrPersoaneImbarcate;
    char *producator;

public:
    Autobuz();                                                 // Constructor fără parametri
    Autobuz(int capacitate, int nrPersoane, const char *prod); // Constructor cu parametri
    Autobuz(const Autobuz &other);                             // Constructor de copiere
    ~Autobuz();                                                // Destructor
};