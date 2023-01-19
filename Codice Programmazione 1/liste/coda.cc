#include <iostream>
#include <cstring>
#include "coda.h"

using namespace std;

static coda Q;

static bool vuota()
{
    return (nullptr == Q.head);
}

void init()
{
    Q.head = nullptr;
}

bool enqueue(char *n)
{
    bool isEnqueued;
    list newNode = new (nothrow) node;
    char *tmp = new (nothrow) char[MAX_DIM];
    if (nullptr == newNode)
    {
        isEnqueued = false;
    }
    else
    {
        strcpy(tmp, n);
        newNode->name = tmp;
        newNode->next = nullptr;
        if (vuota())
        {
            Q.head = newNode;
        }
        else
        {
            Q.tail->next = newNode;
        }
        Q.tail = newNode;
        isEnqueued = true;
    }
    return isEnqueued;
}

bool first(char *&n)
{
    bool isFirst;
    if (vuota())
    {
        isFirst = false;
    }
    else
    {
        n = Q.head->name;
        isFirst = true;
    }
    return isFirst;
}

bool dequeue()
{
    bool isDequeued;
    if (vuota())
    {
        isDequeued = false;
    }
    else
    {
        list firstNode;
        firstNode = Q.head;
        Q.head = Q.head->next;
        delete firstNode->name;
        delete firstNode;
        isDequeued = true;
    }
    return isDequeued;
}

void deinit()
{
    char *tmp;
    while (first(tmp))
    {
        delete[] tmp;
        dequeue();
    }
}

void print()
{
    if (!vuota())
    {
        list currNode = Q.head;
        do
        {
            cout << currNode->name << endl;
            currNode = currNode->next;
        } while (currNode != nullptr);
    }
}
