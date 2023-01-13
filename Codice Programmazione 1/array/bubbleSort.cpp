void bubbleSort(int *arr, int arrLen)
{
  if (arrLen <= 1)
  {
    return;
  }

  for (int i = 0; i < arrLen; i++)
  {
    for (int j = 0; j < (arrLen - i); j++)
    {
      int next = (j == arrLen - 1) ? arr[j] : arr[j + 1];
      if (arr[j] > next)
      {
        arr[j + 1] = arr[j];
        arr[j] = next;
      }
    }
  }
}
