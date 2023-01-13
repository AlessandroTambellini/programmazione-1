#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> array) {
  const unsigned arrLength = array.size();
  for (unsigned i = 0; i < arrLength; i++) {
    unsigned j = i;
    while (j > 0) {
      if (array[j - 1] > array[j]) {
        array[j] = array[j - 1] - array[j];
        array[j - 1] -= array[j];
        array[j] += array[j - 1];
      }
      j--;
    }
  } 
  
  return array;
}
