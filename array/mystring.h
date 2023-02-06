#ifndef MYSTRING_H
#define MYSTRING_H

using namespace std;

int myStrlen(const char *);
int myRecStrlen(const char *, int i = 0);

void myStrcpy(char *, const char *);
void myRecStrcpy(char *strd, const char *strs, int i = 0);

void myStrcat(char *, const char *);
void myRecStrcat(char *, const char *, int, int j = 0);

#endif