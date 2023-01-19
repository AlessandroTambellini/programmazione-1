#ifndef CODA_H
#define CODA_H

const int MAX_DIM = 31;

struct node
{
    char *name;
    node *next;
};
typedef node *list;

struct coda
{
    list head;
    list tail;
};

void init();
bool enqueue(char *);
bool first(char *&);
bool dequeue();
void deinit();
void print();

#endif
