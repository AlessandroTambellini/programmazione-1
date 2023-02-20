#include <iostream>
#include <cstdlib>

using namespace std;

void initArray(char v[], int len)
{
    for (int i = 0; i < len; i++)
    {
        v[i] = 'A' + (rand() % 26);
    }
}

void printArray(char v[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void rotateOnce(char *v, int len, int i = 0)
{
    if (i < len - 1)
    {
        v[i] = v[i + 1];
        i++;
        rotateOnce(v, len, i);
    }
}

void rotateArray(char *v, int len, int totalRotations, int currRotation = 0)
{
    if (currRotation < totalRotations)
    {
        char tmp = v[0];
        rotateOnce(v, len);
        v[len - 1] = tmp;
        currRotation++;
        rotateArray(v, len, totalRotations, currRotation);
    }
}

int main()
{
    srand(time(NULL));
    int j, dim;
    char *v;

    cout << "Inserisci la dimensione dell'array: ";
    cin >> dim;
    cout << "Inserisci j: ";
    cin >> j;

    v = new char[dim];

    initArray(v, dim);
    printArray(v, dim);
    rotateArray(v, dim, j);
    printArray(v, dim);

    delete[] v;

    return 0;
}
