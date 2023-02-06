#include "mystring.h"

int myStrlen(const char *s)
{
    int len;
    for (len = 0; s[len] != '\0'; len++)
        ;
    return len;
}

int myRecStrlen(const char *s, int i)
{
    if (s[i] == '\0')
    {
        return i;
    }
    else
    {
        i++;
        return myRecStrlen(s, i);
    }
}

void myStrcpy(char *strd, const char *strs)
{
    int i;
    for (i = 0; strs[i] != '\0'; i++)
    {
        strd[i] = strs[i];
    }
    strd[i] = '\0';
}

void myRecStrcpy(char *strd, const char *strs, int i)
{
    if (strs[i] == '\0')
    {
        strd[i] = '\0';
        return;
    }
    else
    {
        strd[i] = strs[i];
        i++;
        myRecStrcpy(strd, strs, i);
    }
}

void myStrcat(char *strd, const char *strs)
{
    int i = myRecStrlen(strd) - 1;
    for (int j = 0; strs[j] != '\0'; j++, i++)
    {
        strd[i] = strs[j];
    }
    strd[i] = '\0';
}

void myRecStrcat(char *strd, const char *strs, int i, int j)
{
    if (strs[j] == '\0')
    {
        strd[i] = '\0';
        return;
    }
    else
    {
        strd[i] = strs[j];
        i++;
        j++;
        myRecStrcat(strd, strs, i, j);
    }
}