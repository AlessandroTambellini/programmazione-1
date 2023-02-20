#include <iostream>
#include <cstring>
#include "queue.h"

using namespace std;

static queue Q;

static bool isEmpty()
{
    return (nullptr == Q.head);
}

void init()
{
    Q.head = nullptr;
}

bool enqueue(int v)
{
    bool isEnqueued;
    queueList newNode = new (nothrow) queueNode;
    if (nullptr == newNode)
    {
        isEnqueued = false;
    }
    else
    {
        newNode->value = v;
        newNode->next = nullptr;
        if (isEmpty())
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

bool first(int &v)
{
    bool isFirst;
    if (isEmpty())
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

bool dequeue()
{
    bool isDequeued;
    if (isEmpty())
    {
        isDequeued = false;
    }
    else
    {
        queueList firstNode = Q.head;
        Q.head = Q.head->next;
        delete firstNode;
        isDequeued = true;
    }
    return isDequeued;
}

void deinit()
{
    int tmp = 0;
    while (first(tmp))
    {
        dequeue();
    }
}

void print()
{
    if (!isEmpty())
    {
        queueList currNode = Q.head;
        do
        {
            cout << currNode->value << ' ';
            currNode = currNode->next;
        } while (currNode != nullptr);
        cout << endl;
    }
}
