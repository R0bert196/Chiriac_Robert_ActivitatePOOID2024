#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

// comenzi compliare + rulare
// g++ -o init un_fisier.cpp
// ./init

// Clasa Autobuz
class Autobuz
{
private:
    static int nrAutobuze;
    const int idAutobuz;
    int capacitate;
    int nrPersoaneImbarcate;
    char *producator;

public:
    Autobuz();                                                 
    Autobuz(int capacitate, int nrPersoane, const char *prod); // constructor cu parametri
    Autobuz(const Autobuz &other);                             // constructor de copiere
    ~Autobuz();                                                // destructor

    Autobuz &operator=(const Autobuz &other);                                   // operator= supraincarcat
    friend std::ostream &operator<<(std::ostream &out, const Autobuz &autobuz); // operator<<

    operator int() const;                       // operator cast la int
    bool operator>(const Autobuz &other) const; // operator>

    int getNumarLocuriLibere() const; // metoda pe obiect

    // getters si setters
    int getCapacitate() const;
    void setCapacitate(int capacitate);
    const char *getProducator() const;
    void setProducator(const char *prod);
};

// initializare variabila statica
int Autobuz::nrAutobuze = 0;

// Constructor fara parametri
Autobuz::Autobuz()
    : idAutobuz(++nrAutobuze), capacitate(0), nrPersoaneImbarcate(0), producator(nullptr)
{
    producator = new char[8];
    strcpy(producator, "Necunoscut");
}

// constructor cu parametri + validari
Autobuz::Autobuz(int capacitate, int nrPersoane, const char *prod)
    : idAutobuz(++nrAutobuze)
{
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

// copy constructor
Autobuz::Autobuz(const Autobuz &other)
    : idAutobuz(++nrAutobuze)
{
    capacitate = other.capacitate;
    nrPersoaneImbarcate = other.nrPersoaneImbarcate;
    producator = new char[strlen(other.producator) + 1];
    strcpy(producator, other.producator);
}

// destructor
Autobuz::~Autobuz()
{
    delete[] producator;
}

// operator= overload
Autobuz &Autobuz::operator=(const Autobuz &other)
{
    if (this != &other)
    {
        delete[] producator; // Eliberez memoria veche

        capacitate = other.capacitate;
        nrPersoaneImbarcate = other.nrPersoaneImbarcate;

        producator = new char[strlen(other.producator) + 1];
        strcpy(producator, other.producator);
    }
    return *this;
}

// operator cast la int
Autobuz::operator int() const
{
    return nrPersoaneImbarcate;
}

// operator<< overlaod
ostream &operator<<(ostream &out, const Autobuz &autobuz)
{
    out << "ID: " << autobuz.idAutobuz << "; Capacitate: " << autobuz.capacitate
        << "; Imbarcati: " << autobuz.nrPersoaneImbarcate
        << "; Producator: " << autobuz.producator << ";\n";
    return out;
}

// operator> overlaod
bool Autobuz::operator>(const Autobuz &other) const
{
    return this->capacitate > other.capacitate;
}

// getters si setters cu validari
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

int main()
{
    try
    {
        // creez 3 autobuze puternice
        Autobuz a1(50, 30, "Mercedes");
        Autobuz a2(40, 20, "Volvo");
        Autobuz a3;

        // afisez Autobuzul 1
        cout << "Print Autobuz 1:\n"
             << a1;
        cout << "Print Autobuz 2:\n"
             << a2;

        // test operator=
        a3 = a1;
        cout << "Print Autobuz 3 copiat din Autobuz 1:\n"
             << a3;

        // test cast la int
        cout << "Numarul de persoane imbarcate in Autobuz 1: " << int(a1) << endl;

        // test operator>
        if (a1 > a2)
        {
            cout << "Autobuzul 1 are capacitate mai mare decat Autobuzul 2.\n";
        }
        else
        {
            cout << "Autobuzul 2 are capacitate mai mare sau egala cu Autobuzul 1.\n";
        }

        // test metoda getNumarLocuriLibere
        cout << "Locuri libere in Autobuz 1: " << a1.getNumarLocuriLibere() << endl;
    }
    catch (const exception &ex)
    {
        cerr << "Eroare: " << ex.what() << endl;
    }

    return 0;
}
