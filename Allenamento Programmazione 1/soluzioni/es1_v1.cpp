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

void strcpy(char *strd, const char *strs)
{
    int i;
    for (i = 0; strs[i] != '\0'; i++)
    {
        strd[i] = strs[i];
    }
    strd[i] = '\0';
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Numero di argomenti errato" << endl;
        exit(1);
    }

    fstream in, out;

    in.open(argv[1], ios::in); // chiedere questo, perché anche se non specifico ios::in funziona comunque
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

    char buffer[256] = {}; // a line of the file
    char maxBuffer[256] = {};
    int maxLength = 0;

    while (in.getline(buffer, 256))
    {
        int len = strlen(buffer);

        if (len > maxLength)
        {
            maxLength = len;
            strcpy(maxBuffer, buffer);
        }
        out << len << endl;
    }

    out << maxBuffer << ' ' << maxLength << endl;
    in.close();
    out.close();

    return 0;
}