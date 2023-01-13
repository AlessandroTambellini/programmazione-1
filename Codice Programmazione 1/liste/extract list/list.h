#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

struct node
{
    int value;
    node *next;
};

void printList(node *x);
void deleteList(node *x);
void generateList(node *x, int len);

#endif