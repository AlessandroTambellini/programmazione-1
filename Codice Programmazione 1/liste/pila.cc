#include <iostream>
#include "pila.h"

using namespace std;

static list pila; // value remembered and avaiable just in this file

void init()
{
    pila = nullptr;
}

bool push(int n)
{
    bool isPushed;
    list newNode = new (nothrow) node; // check there's enough memory in the heap
    if (nullptr == newNode)
    {
        isPushed = false;
    }
    else
    {
        newNode->value = n;
        newNode->next = pila;
        pila = newNode;
        isPushed = true;
    }
    return isPushed;
}

// auxiliary function visible and used just in this file
static bool empty()
{
    return (nullptr == pila);
}

bool top(int &n)
{

    bool notEmpty;
    if (empty())
    {
        notEmpty = false;
    }
    else
    {
        n = pila->value;
        notEmpty = true;
    }
    return notEmpty;
}

bool pop()
{

    bool isPopped;
    if (empty())
    {
        isPopped = false;
    }
    else
    {
        list topNode = pila;
        pila = pila->next;
        delete topNode;
        isPopped = true;
    }
    return isPopped;
}

void deinit()
{
    int tmp;
    while (top(tmp))
    {
        pop();
    }
}