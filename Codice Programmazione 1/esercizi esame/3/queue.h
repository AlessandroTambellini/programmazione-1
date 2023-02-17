#ifndef QUEUE_H
#define QUEUE_H

struct queueNode
{
    int value;
    queueNode *next;
};
typedef queueNode *queueList;

struct queue
{
    queueList head;
    queueList tail;
};

void init();
bool enqueue(int v);
bool first(int &v);
bool dequeue();
void deinit();
void print();

#endif