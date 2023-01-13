#include <iostream>
#include <fstream>

using namespace std;

void bubbleSort(float *arr, int arrLen)
{
    if (arrLen <= 1)
    {
        return;
    }

    for (int i = 0; i < arrLen; i++)
    {
        for (int j = 0; j < (arrLen - i); j++)
        {
            float next = (j == arrLen - 1) ? arr[j] : arr[j + 1];
            if (arr[j] > next)
            {
                arr[j + 1] = arr[j];
                arr[j] = next;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cout << "Numero di argomenti errato" << endl;
        exit(1);
    }

    fstream input;
    input.open(argv[1], ios::in);
    if (input.fail())
    {
        cout << "Errore nell'apertura del file" << endl;
        exit(1);
    }

    int numOfHighestTemperatures = atoi(argv[2]);
    int numOfTemperatures = atoi(argv[3]);
    float *temperaturs = new float[numOfTemperatures];
    int i = 0;
    while (input >> temperaturs[i])
    {
        i++;
    }

    bubbleSort(temperaturs, numOfTemperatures);
    for (int i = 0; i < numOfHighestTemperatures; i++)
    {
        cout << temperaturs[numOfTemperatures - 1 - i] << ' ';
    }
    cout << endl;

    return 0;
}