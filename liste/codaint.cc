#include <iostream>
#include <cstring>
#include "codaint.h"

using namespace std;

static codaint Q;

static bool isCodaEmpty()
{
    return (nullptr == Q.head);
}

void initCodaint()
{
    Q.head = nullptr;
}

bool enqueueCodaint(int v)
{
    bool isEnqueued;
    codaintList newNode = new (nothrow) codaintNode;
    if (nullptr == newNode)
    {
        isEnqueued = false;
    }
    else
    {
        newNode->value = v;
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

bool firstCodaint(int &v)
{
    bool isFirst;
    if (isCodaEmpty())
    {
        isFirst = false;
    }
    else
    {
        v = Q.head->value;
        isFirst = true;
    }
    return isFirst;
}

bool dequeueCodaint()
{
    bool isDequeued;
    if (isCodaEmpty())
    {
        isDequeued = false;
    }
    else
    {
        codaintList firstNode;
        firstNode = Q.head;
        Q.head = Q.head->next;
        delete firstNode;
        isDequeued = true;
    }
    return isDequeued;
}

void deinitCodaint()
{
    int tmp = 0;
    while (firstCodaint(tmp))
    {
        dequeueCodaint();
    }
}

void printCodaint()
{
    if (!isCodaEmpty())
    {
        codaintList currNode = Q.head;
        do
        {
            cout << currNode->value << endl;
            currNode = currNode->next;
        } while (currNode != nullptr);
    }
}
