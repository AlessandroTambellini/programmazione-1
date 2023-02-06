#include <iostream>
#include <fstream>
#include "../pila.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Wrong number of arguments";
        exit(1);
    }

    fstream in, out;

    in.open(argv[1], ios::in);
    if (in.fail())
    {
        cout << "Failed opening the input file";
        exit(1);
    }

    out.open(argv[2], ios::out);
    if (out.fail())
    {
        cout << "Failed opening the output file";
        exit(1);
    }

    init(); // checked
    int currNum;

    while (in >> currNum)
    {
        push(currNum); // aggiunge elemento alla fine, aka non alla base
    }

    while (top(currNum))
    {
        out << currNum << endl; // rimuove elemento alla fine
        pop();
    }

    deinit();

    in.close();
    out.close();

    return 0;
}