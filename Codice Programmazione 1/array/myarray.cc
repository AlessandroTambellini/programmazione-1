#include "myarray.h"

void reverseArray(int *arr, int arrLen)
{
    for (int i = 0; i < arrLen / 2; i++)
    {
        *(arr + i) = *(arr + arrLen - i - 1) - *(arr + i);
        *(arr + arrLen - i - 1) -= *(arr + i);
        *(arr + i) += *(arr + arrLen - i - 1);
    }
}

void printArray(int arr[], int arrLen)
{
    cout << "[ ";
    for (int i = 0; i < arrLen; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << " ]" << endl;
}

void initializeRandomArray(int *arr, int arrLen)
{
    for (int i = 0; i < arrLen; i++)
    {
        *(arr + i) = rand() % 10;
    }
}