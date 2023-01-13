#include <iostream>
#include <time.h>

using namespace std;

void initializeArray(int *arr, unsigned arrLen)
{
    for (unsigned i = 0; i < arrLen; i++)
    {
        *(arr + i) = rand() % 10;
    }
}

int main()
{
    srand(time(NULL));
    int arr[10];
    initializeArray(arr, 10);
}