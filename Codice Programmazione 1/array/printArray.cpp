#include <iostream>

using namespace std;

void printArray(int arr[], int arrLen)
{
    cout << "[ ";
    for (int i = 0; i < arrLen; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << " ]" << endl;
}