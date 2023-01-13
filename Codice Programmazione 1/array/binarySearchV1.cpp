#include <iostream>
#include <time.h>

using namespace std;

void initializeOrderedArray(int *arr, int arrLen)
{
    for (int i = 0; i < arrLen; i++)
    {
        int next = rand() % 10;
        cout << next << endl;
        if (i != 0)
        {
            while (next < arr[i - 1])
            {
                next = rand() % 10;
            }
        }
        *(arr + i) = next;
    }
}

void printArray(int arr[], unsigned arrLen)
{
    cout << "[ ";
    for (unsigned i = 0; i < arrLen; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << " ]";
}

void binarySearch(int arr[], int arrLen, int guess, int half)
{
    if (arr[half] == guess)
    {
        cout << "Guess position (index): " << half << endl;
        return;
    }
    else if (half == arrLen - 1 || half == 0)
    {
        cout << "Guess not present in the array." << endl;
        return;
    }
    else if (arr[half] > guess)
    {
        binarySearch(arr, half + 1, guess, (half / 2));
    }
    else
    {
        binarySearch(arr, arrLen, guess, (half + ((arrLen - half) / 2)));
    }
}

int main()
{
    srand(time(NULL));
    int arr[10];
    initializeOrderedArray(arr, 10);
    printArray(arr, 10);

    int guess;
    cout << "Enter a number between 0 and 9: ";
    cin >> guess;

    binarySearch(arr, 10, guess, 10 / 2);
}