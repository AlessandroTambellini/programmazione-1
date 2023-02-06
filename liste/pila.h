#ifndef PILA_H
#define PILA_H

struct node
{
    char value;
    node *next;
};
typedef node *list;

void init();
bool push(int);
bool top(int &);
bool pop();
void deinit();
void printPila();

#endif