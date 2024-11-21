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
    Autobuz();                                                 // Constructor fara
    Autobuz(int capacitate, int nrPersoane, const char *prod); // Constructor cu parametri
    Autobuz(const Autobuz &other);                             // Constructor de copiere
    ~Autobuz();                                                // Destructor

    Autobuz &operator=(const Autobuz &other);                                   // Operator= supraincarcat
    friend std::ostream &operator<<(std::ostream &out, const Autobuz &autobuz); // Operator<<

    operator int() const;                       // Operator cast la int
    bool operator>(const Autobuz &other) const; // Operator>

    int getNumarLocuriLibere() const; // Metoda care calculeaza locurile libere

    // Getters si Setters pt fieldurile private
    int getCapacitate() const;
    void setCapacitate(int capacitate);
    const char *getProducator() const;
    void setProducator(const char *prod);
};