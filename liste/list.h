#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

struct node
{
    int value;
    node *next;
};

// analizing stuff
void print(node *s);
int length(node *s);
int recLength(node *s);
int circularLength(node *s, node *x);
int findBiggestValue(node *x);
int findSmallestValue(node *x);
int searchElement(node *x, int guess);

// updating stuff
void generateList(node *&x, int len);
void deleteList(node *&s);
void recDeleteList(node *&s);
void insertLastNode(node *&s, int v);
void insertFirstNode(node *&s, int v);
void insertBefore(node *&s, int v);
void removeFirstNode(node *&s);
void removeNode(node *&p, int v);

// creating new stuff
node *reverse(node *x);
node *copyReverse(node *x);
node *getNthNode(node *s, int nth);
node *prevNode(node *s, node *x);
node *concat(node *s1, node *s2);
node *recConcat(node *s1, node *s2);
node *copySequence(node *s);
node *concatSubsequences(node *s1, node *s2);
node *recConcatSubsequences(node *s1, node *s2);
node *removeNextNode(node *&x);

#endif