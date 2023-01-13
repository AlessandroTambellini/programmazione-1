#include <iostream>
#include <cstdlib>

using namespace std;

int **generateMatrix(int rows, int cols)
{
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }

    return matrix;
}

void printMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void deallocateMatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows and columns of the matrix." << endl;
    cout << "rows: ";
    cin >> rows;
    cout << "cols: ";
    cin >> cols;

    srand(time(NULL));
    int **matrix = generateMatrix(rows, cols);
    printMatrix(matrix, rows, cols);

    deallocateMatrix(matrix, rows);

    return 0;
}