#include <iostream>
#include <fstream>

using namespace std;

int strlen(const char *s)
{
    int r;
    for (r = 0; s[r] != '\0'; r++)
        ;
    return r;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
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
    char symbol = argv[3][0];
    while (input >> buffer)
    {
        int len = strlen(buffer);
        for (int i = 0; i < len; i++)
        {
            if (buffer[i] == symbol)
            {
                buffer[i] = '?';
            }
        }
        output << buffer << ' ';
    }
    input.close();
    output.close();

    return 0;
}