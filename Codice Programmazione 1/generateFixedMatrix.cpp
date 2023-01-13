#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <time.h>

using namespace std;

void fillArray(int *p_el, int len)
{
  for (int i = 0; i < len; i++)
  {
    *(p_el + i) = rand() % 30;
  }
}

int main()
{
  srand(time(NULL));
  int arr1[rand() % 10][rand() % 10];
  int arr2[rand() % 10][rand() % 10];

  fillArray(&arr2[0][0], sizeof(arr2) / sizeof(arr2[0][0]));

  /*   for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
      for (int j = 0; j < sizeof(arr1[0]) / sizeof(arr1[0][0]); j++) {
        arr1[i][j] = rand() % 20;
        cout << arr1[i][j] << ' ';
      }
      cout << endl;
    }
   */
  for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
  {
    for (int j = 0; j < sizeof(arr2[0]) / sizeof(arr2[0][0]); j++)
    {
      cout << arr2[i][j] << ' ';
    }
    cout << endl;
  }
}
