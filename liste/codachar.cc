#include <iostream>
#include <cstring>
#include "coda.h"

using namespace std;

static codachar Q;

static bool isCodaEmpty()
{
    return (nullptr == Q.head);
}

void initCodachar()
{
    Q.head = nullptr;
}

bool enqueueCodachar(char *n)
{
    bool isEnqueued;
    codacharList newNode = new (nothrow) codacharNode;
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
        if (isCodaEmpty())
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

bool firstCodachar(char *&n)
{
    bool isFirst;
    if (isCodaEmpty())
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

bool dequeueCodachar()
{
    bool isDequeued;
    if (isCodaEmpty())
    {
        isDequeued = false;
    }
    else
    {
        codacharList firstNode;
        firstNode = Q.head;
        Q.head = Q.head->next;
        delete firstNode->name;
        delete firstNode;
        isDequeued = true;
    }
    return isDequeued;
}

void deinitCodachar()
{
    char *tmp;
    while (firstCodachar(tmp))
    {
        delete[] tmp;
        dequeueCodachar();
    }
}

void printCodachar()
{
    if (!isCodaEmpty())
    {
        codacharList currNode = Q.head;
        do
        {
            cout << currNode->name << endl;
            currNode = currNode->next;
        } while (currNode != nullptr);
    }
}
