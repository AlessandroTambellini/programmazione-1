#include <iostream>
#include <time.h>

using namespace std;

struct node
{
    int value;
    node *next;
};

void generateList(node *base, int len)
{
    node *x = base;
    for (int i = 0; i < len; i++)
    {
        node *t = new node;
        t->value = rand() % 100;
        cout << "random value: " << t->value << endl;
        t->next = nullptr;
        x->next = t;
        x = t;
    }
}