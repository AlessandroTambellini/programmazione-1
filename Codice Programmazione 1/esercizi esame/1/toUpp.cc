#include <iostream>
#include <fstream>

using namespace std;

char changeChar(char currChar, char prevChar)
{
    if (prevChar == '.' || prevChar == '?' || prevChar == '!')
    {
        if (currChar >= 'a' && currChar <= 'z')
        {
            return (char)(currChar - 32);
        }
        else
        {
            return currChar;
        }
    }
    else
    {
        return currChar;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Numero di argomenti errato." << endl;
        exit(1);
    }

    fstream in, out;
    in.open(argv[1], ios::in);
    out.open(argv[2], ios::out);
    if (in.fail() || out.fail())
    {
        cout << "Errore nell'apertura di uno dei 2 files" << endl;
        exit(1);
    }

    char currChar;
    bool toUpp = true;
    in >> noskipws;
    while (in >> currChar)
    {
        if (currChar >= 'a' && currChar <= 'z' && toUpp)
        {
            out << (char)(currChar - 32);
            toUpp = false;
        }
        else
        {
            if (currChar == '!' || currChar == '?' || currChar == '.')
            {
                toUpp = true;
            }
            out << currChar;
        }
    }

    in.close();
    out.close();

    return 0;
}