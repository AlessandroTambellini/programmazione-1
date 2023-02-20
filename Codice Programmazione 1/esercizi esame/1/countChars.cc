#include <iostream>
#include <fstream>

using namespace std;

int takeIndex(char character)
{
    int index = -1;
    if (character >= 'a' && character <= 'z')
    {
        index = character - 'a';
    }
    else if (character >= 'A' && character <= 'Z')
    {
        index = character - 'A';
    }
    return index;
}

void printOccurences(int *alphabet)
{
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] > 0)
        {
            cout << (char)(i + 'a') << ": " << alphabet[i] << endl;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Numero di argomenti errato" << endl;
        exit(1);
    }

    fstream input;
    input.open(argv[1], ios::in);
    if (input.fail())
    {
        cout << "Errore nell'apertura del file" << endl;
        exit(1);
    }

    int alphabet[26] = {0};
    char character;
    while (input.get(character))
    {
        int index = takeIndex(character);
        if (index != -1)
        {
            alphabet[index]++;
        }
    }

    printOccurences(alphabet);

    return 0;
}