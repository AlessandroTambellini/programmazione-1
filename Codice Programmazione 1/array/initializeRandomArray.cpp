#include <iostream>
#include <time.h>

void initializeRandomArray(int *arr, int arrLen)
{
    for (int i = 0; i < arrLen; i++)
    {
        *(arr + i) = rand() % 10;
    }
}
