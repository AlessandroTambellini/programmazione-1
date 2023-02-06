#include <iostream>
#include <cstring>
#include "../coda.h"

using namespace std;

int main()
{
    init();

    cout << "Digita: " << endl
         << "* \"rimuovi\" per rimuovere la prima persona in fila" << endl
         << "* \"stampa\" per vedere la coda" << endl
         << "* \"esci\" per terminare il programma" << endl
         << "* un nome per aggiungere una persona " << endl;

    bool esci = false;
    char input[MAX_DIM];

    while (!esci)
    {
        cin >> input;

        if (strcmp(input, "rimuovi") == 0)
        {
            char *primo;
            if (first(primo))
            {
                dequeue();
            }
            else
            {
                cout << "coda vuota" << endl;
            }
        }
        else if (strcmp(input, "stampa") == 0)
        {
            cout << "Persone nella coda: " << endl;
            print();
        }
        else if (strcmp(input, "esci") == 0)
        {
            esci = true;
        }
        else
        {
            cout << input << " inserito nella coda" << endl;
            enqueue(input);
        }
    }

    deinit();

    return 0;
}
