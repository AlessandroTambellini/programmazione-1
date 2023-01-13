#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <time.h>
#include <vector>

using namespace std;

void initializeMatrix(int matrix[][10], int rows = 10, int cols = 10);
void printMatrix(int matrix[][10], int rows = 10, int cols = 10);
int findIslands(int matrix[][10], int rows = 10, int cols = 10);
int isIsland(int matrix[][10], int row, int col);

int main()
{
  srand(time(NULL));
  int matrix[10][10];

  initializeMatrix(matrix);
  printMatrix(matrix);

  int islands = findIslands(matrix);
  cout << "\nThe matrix has " << islands << " islands" << endl;
}

void initializeMatrix(int matrix[][10], int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      matrix[i][j] = rand() % 2;
    }
  }
}

void printMatrix(int matrix[][10], int rows, int cols)
{
  cout << "[ ";
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (j == 0 && i != 0)
      {
        cout << "  ";
      }
      cout << matrix[i][j];
      if (j == cols - 1 && i != rows - 1)
      {
        cout << '\n';
      }
      else
      {
        cout << ' ';
      }
    }
  }
  cout << "]" << endl;
}

int findIslands(int matrix[][10], int rows, int cols)
{
  int islands = 0;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (matrix[i][j] == 1)
      {
        islands += isIsland(matrix, i, j);
      }
    }
  }

  return islands;
}

int isIsland(int matrix[][10], int row, int col)
{
  int sum = 0;
  for (int i = row - 1; i <= row + 1; i++)
  {
    for (int j = col - 1; j <= col + 1; j++)
    {
      if (i >= 0 && i <= 9 && j >= 0 && j <= 9)
      {
        sum += matrix[i][j];
      }
    }
  }

  return sum == 1 ? 1 : 0;
}