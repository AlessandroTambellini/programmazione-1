#include <iostream>
#include <fstream>
#include <cstring>
#include "../list.h"
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));

    if (argc != 2)
    {
        cout << "Numero di argomenti errato" << endl;
        exit(1);
    }

    fstream in;

    in.open(argv[1], ios::in);
    if (in.fail())
    {
        cout << "Errore nell'apertura del file" << endl;
        exit(1);
    }

    node *currNode = new node;
    in >> currNode->value;
    currNode->next = nullptr;
    node *head = currNode;
    int currValue;
    while (in >> currValue)
    {
        node *newNode = new node{currValue, nullptr};
        currNode->next = newNode;
        currNode = newNode;
    }

    in.close();

    printList(head);

    deleteListV2(head);

    int len = rand() % 10;
    generateList(head, len);

    printList(head);

    return 0;
}