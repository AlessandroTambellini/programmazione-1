#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Numero di argomenti errato." << endl;
        exit(EXIT_FAILURE);
    }

    fstream input, output;
    input.open(argv[1], ios::in);
    if (input.fail())
    {
        cout << "Errore nell'apertura del file" << endl;
        exit(EXIT_FAILURE);
    }

    output.open(argv[2], ios::out);
    if (output.fail())
    {
        cout << "Errore nell'apertura del file di output" << endl;
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    while (input >> buffer)
    {
        output << buffer << ' ';
    }
    input.close();
    output.close();
    cout << endl;

    return 0;
}