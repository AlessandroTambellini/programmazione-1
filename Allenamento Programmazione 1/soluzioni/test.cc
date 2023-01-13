#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Wrong number of arguments." << endl;
        exit(EXIT_FAILURE);
    }

    fstream in, out;

    in.open(argv[1], ios::in);
    if (in.fail())
    {
        cout << "Errore in apertura file " << argv[1] << endl;
        exit(1);
    }

    out.open(argv[2], ios::out);
    if (out.fail())
    {
        cout << "Errore chiusura file " << argv[2] << endl;
        in.close();
        exit(1);
    }

    
}