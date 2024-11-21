#include <iostream>
#include "Autobuz.h"

using namespace std;

int main()
{
    try
    {
        Autobuz a1(50, 30, "Mercedes");
        cout << "ASDASD";
    }
    catch (const exception &ex)
    {
        cerr << "Eroare: " << ex.what() << endl;
    }
    return 0;
}
