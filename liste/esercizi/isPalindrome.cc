#include <iostream>
#include "../pila.h"
#include "../codaint.h"
#include "../../array/mystring.h"

using namespace std;

void invertiPila()
{

    int numero;

    while (top(numero))
    {
        enqueueCodaint(numero);
        pop();
    }

    while (firstCodaint(numero))
    {
        push(numero);
        dequeueCodaint();
    }
}

void comparePilaAndCoda()
{
    int pilaValue, codaValue;

    int i = 0;
    while (top(pilaValue))
    {
        firstCodaint(codaValue);
        cout << pilaValue << ' ' << codaValue << endl;
        if (pilaValue != codaValue && !i)
        {
            cout << "The word is not palindrome" << endl;
            i = 1;
        }
        pop();
        dequeueCodaint();
    }
}

int main()
{
    // pila setup

    init();
    initCodaint();
    char *word = new char[100];
    cout << "Write a word: ";
    cin >> word;

    int wordLen = myStrlen(word);
    for (int i = 0; i < wordLen; i++)
    {
        push((int)word[i]);
        enqueueCodaint((int)word[i]);
    }

    cout << "Pila: \n";
    printPila();

    cout << "Coda: \n";
    printCodaint();

    /*     invertiPila();

        for (int i = 0; i < wordLen; i++)
        {
            enqueueCodaint((int)word[i]);
        } */

    cout << "Compare pila and coda: \n";
    comparePilaAndCoda();
}