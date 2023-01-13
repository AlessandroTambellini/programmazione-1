#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void inizializza(int array[], int dim);
void stampa(const int array[], int dim);
void bubblesort(int array[], int dim);
int binarySearch(const int arr[], int minIdx, int maxIdx, int guess);

int main()
{

    const int DIM = 10;
    int array[DIM];

    srand(time(NULL));

    inizializza(array, DIM);
    bubblesort(array, DIM);
    stampa(array, DIM);

    int numero;
    cout << "Inserisci l'elemento da cercare: ";
    cin >> numero;
    cout << "L'indice è " << binarySearch(array, 0, DIM, numero) << endl;

    return 0;
}

void inizializza(int array[], int dim)
{

    for (int i = 0; i < dim; i++)
    {
        array[i] = rand() % 100;
    }
}

void stampa(const int array[], int dim)
{

    for (int i = 0; i < dim; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void bubblesort(int array[], int dim)
{

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int binarySearch(const int arr[], int minIdx, int maxIdx, int guess)
{
    if (maxIdx > minIdx + 1)
    {
        int mid = (maxIdx + minIdx) / 2;
        if (arr[mid] >= guess)
        {
            return binarySearch(arr, minIdx, mid, guess);
        }
        else
        {
            return binarySearch(arr, mid, maxIdx, guess);
        }
    }

    if (arr[minIdx] == guess)
    {
        return minIdx;
    }
    else if (arr[maxIdx] == guess)
    {
        return maxIdx;
    }
    else
    {
        return -1;
    }
}