void reverseArray(int *arr, unsigned arrLen) {
  for (unsigned i = 0; i < arrLen / 2; i++) {
    *(arr + i) = *(arr + arrLen - i - 1) - *(arr + i);
    *(arr + arrLen - i - 1) -= *(arr + i);
    *(arr + i) += *(arr + arrLen - i - 1);
    }
}