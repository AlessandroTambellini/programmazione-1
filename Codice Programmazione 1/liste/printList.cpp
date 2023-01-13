#include <iostream>

using namespace std;

struct node
{
    int value;
    node *next;
};

void printList(node *x)
{
    for (; x != nullptr; x = x->next)
    {
        cout << '{' << endl
             << '\t' << x->value << ';' << endl
             << '\t' << x->next << ';' << endl
             << '}' << endl;
    }
}