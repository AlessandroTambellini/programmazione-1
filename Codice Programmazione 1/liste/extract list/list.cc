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
        cout << x->value << " ---> ";
    }
}

void deleteList(node *x)
{
    node *nextNode = x;
    while (nextNode != nullptr)
    {
        nextNode = x->next;
        delete x;
        x = nextNode;
    }
}

void generateList(node *x, int len)
{
    node *currNode = x;
    for (int i = 0; i < len; i++)
    {
        node *t = new node;
        t->value = rand() % 100;
        t->next = nullptr;
        currNode->next = t;
        currNode = t;
    }
}