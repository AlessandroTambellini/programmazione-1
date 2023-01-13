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

int findBiggestValue(node *x)
{
    int biggestValue = x->value;
    for (; x != nullptr; x = x->next)
    {
        if (x->value > biggestValue)
        {
            biggestValue = x->value;
        }
    }

    return biggestValue;
}

// it has problemssssssss
node *moveBiggestValueNode(node *x, int biggestValue)
{
    node *prev = nullptr;
    node *toMove = nullptr;
    node *firstNode = nullptr;
    for (; x != nullptr; x = x->next)
    {
        if (x->value == biggestValue && toMove == nullptr) // matching value
        {
            if (prev != nullptr)
            {
                prev->next = x->next;
            }
            else
            {
                if (x->next != nullptr)
                {
                    firstNode = x->next;
                }
            }
            toMove = x;
        }
        else if (x->next == nullptr) // last node
        {
            x->next = toMove;
            toMove->next = nullptr;
        }
        else if (toMove == nullptr) // still searching for value
        {
            prev = x;
        }
    }

    return firstNode;
}

int main()
{
    srand(time(NULL));
    node *firstNode = new node;

    int listLen = rand() % 10;

    generateList(firstNode, listLen);
    printList(firstNode);

    int biggestValue = findBiggestValue(firstNode);
    cout << "Biggest value: " << biggestValue << endl;

    node *newFirstNode = moveBiggestValueNode(firstNode, biggestValue);
    if (newFirstNode != nullptr)
    {
        firstNode = newFirstNode;
    }
    printList(firstNode);
}