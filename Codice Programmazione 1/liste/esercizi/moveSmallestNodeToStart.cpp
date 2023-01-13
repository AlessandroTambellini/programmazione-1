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

int findSmallestValue(node *x)
{
    int smallestValue = x->value;
    for (; x != nullptr; x = x->next)
    {
        if (x->value < smallestValue)
        {
            smallestValue = x->value;
        }
    }

    return smallestValue;
}

node *moveSmallestValueNode(node *x, int smallestValue)
{
}

int main()
{
    srand(time(NULL));
    node *firstNode = new node;

    int listLen = rand() % 10;

    generateList(firstNode, listLen);
    printList(firstNode);

    int smallestValue = findSmallestValue(firstNode);
    cout << "Smallest value: " << smallestValue << endl;
/* 
    node *newFirstNode = moveSmallestValueNode(firstNode, smallestValue);
    if (newFirstNode != nullptr)
    {
        firstNode = newFirstNode;
    }
    printList(firstNode); */
}