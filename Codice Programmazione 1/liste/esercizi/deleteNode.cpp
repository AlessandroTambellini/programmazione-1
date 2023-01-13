#include <iostream>
#include <time.h>

using namespace std;

struct node
{
    int value;
    node *next;
};

void generateList(node *firstNode, int len)
{
    node *x = firstNode;
    for (int i = 0; i < len; i++)
    {
        x->value = rand() % 10;
        if (i == len - 1)
        {
            x->next = nullptr;
        }
        else
        {
            node *t = new node;
            x->next = t;
            x = t;
        }
    }
}

void printList(node *x)
{
    for (; x != nullptr; x = x->next)
    {
        cout << '{' << endl
             << '\t' << "value: " << x->value << ';' << endl
             << '\t' << "next: " << x->next << ';' << endl
             << '}' << endl;
    }
}

void removeNode(node *x, int num)
{
    if (x->value == num)
    {
        node *q = x;
        if (x->next != nullptr)
        {
            x = x->next;
        }
        delete q;
    }
    for (; x->next != nullptr; x = x->next)
    {
        if (x->next->value == num)
        {
            node *q = x->next;
            x->next = q->next;
            delete q;
        }
    }
}

int main()
{
    srand(time(NULL));
    node *firstNode = new node;
    int listLen = rand() % 10;

    generateList(firstNode, listLen);
    printList(firstNode);

    cout << endl;

    int guess = rand() % 10;
    cout << "guess: " << guess << endl;
    removeNode(firstNode, guess);
    printList(firstNode);
}