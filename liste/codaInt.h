#ifndef CODAINT_H
#define CODAINT_H

struct codaintNode
{
    int value;
    codaintNode *next;
};
typedef codaintNode *codaintList;

struct codaint
{
    codaintList head;
    codaintList tail;
};

void initCodaint();
bool enqueueCodaint(int v);
bool firstCodaint(int &v);
bool dequeueCodaint();
void deinitCodaint();
void printCodaint();

#endif