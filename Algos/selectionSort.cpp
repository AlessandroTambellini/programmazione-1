#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array) {
  for (unsigned i = 0; i < array.size(); i++) {
    int smallest = array[i];
    for (unsigned j = i + 1; j < array.size(); j++) {
      if (array[j] < smallest) {
        smallest = array[j] - smallest;
        array[j] -= smallest;
        smallest += array[j];
      }
    }
    array[i] = smallest;
  }
  
  return array;
}
