#include <iostream>
#include "Autobuz.h"

using namespace std;

// comenzi compilare + rulare
// g++ init.cpp Autobuz.cpp - o init
// ./ init

int main()
{
    try
    {
        // creez 3 autobuze puternice
        Autobuz a1(50, 30, "Mercedes");
        Autobuz a2(40, 20, "Volvo");
        Autobuz a3;

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

        // test >
        if (a1 > a2)
        {
            cout << "Autobuzul 1 are capacitate mai mare decat Autobuzul 2.\n";
        }
        else
        {
            cout << "Autobuzul 2 are capacitate mai mare sau egala cu Autobuzul 1.\n";
        }

        // testare metoda
        cout << "Locuri libere in Autobuz 1: " << a1.getNumarLocuriLibere() << endl;
    }
    catch (const exception &ex)
    {
        cerr << "Eroare: " << ex.what() << endl;
    }

    return 0;
}
