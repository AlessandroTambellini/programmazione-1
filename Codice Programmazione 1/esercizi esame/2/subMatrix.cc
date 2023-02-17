#include <iostream>
#include <cstdlib>

using namespace std;

typedef int **matrix;

matrix allocSpace(int rows, int cols)
{
    matrix newMatrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        newMatrix[i] = new int[cols];
    }

    return newMatrix;
}

matrix createMatrix(int rows, int cols)
{
    matrix newMatrix = allocSpace(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            newMatrix[i][j] = rand() % 10;
        }
    }

    return newMatrix;
}

void print_matrix(matrix a, int d1, int d2)
{
    int i, j;

    cout << endl;
    for (i = 0; i < d1; i++)
    {
        for (j = 0; j < d2; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void printSubmatrix(matrix m, int c1, int c2, int subRows, int subCols)
{
    for (int i = c1; i < c1 + subRows; i++)
    {
        for (int j = c2; j < c2 + subCols; j++)
        {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}

void deallocMatrix(matrix m, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] m[i];
    }
    delete[] m;
}

int main()
{
    srand(time(NULL));

    int rows, cols;
    cout << "rows dim: ";
    cin >> rows;
    cout << "cols dim: ";
    cin >> cols;

    matrix myMatrix = createMatrix(rows, cols);
    print_matrix(myMatrix, rows, cols);

    int c1, c2;
    cout << "Specify the submatrix to print\n";
    cout << "Coordinates of the first element\n"
         << "row: ";
    cin >> c1;
    cout << "col: ";
    cin >> c2;
    int subRows, subCols;
    cout << "Specify the dimensions of the submatrix starting from the specified element\n"
         << "num of rows: ";
    cin >> subRows;
    cout << "num of cols: ";
    cin >> subCols;

    subRows = subRows > (rows - c1) ? rows - c1 : subRows;
    subCols = subCols > (cols - c2) ? cols - c2 : subCols;

    printSubmatrix(myMatrix, c1, c2, subRows, subCols);

    deallocMatrix(myMatrix, rows);

    return 0;
}