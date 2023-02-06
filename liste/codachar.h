#ifndef CODACHAR_H
#define CODACHAR_H

const int MAX_DIM = 31;

struct codacharNode
{
    char *name;
    codacharNode *next;
};
typedef codacharNode *codacharList;

struct codachar
{
    codacharList head;
    codacharList tail;
};

void initCodachar();
bool enqueueCodachar(char *);
bool firstCodachar(char *&);
bool dequeueCodachar();
void deinitCodachar();
void printCodachar();

#endif
