

#include "QuickSort.h"
#include <array>

/**
 * @brief This function selects a pivot
 * and put all the elements that are smaller than
 * pivot in the beginning than put the pivot than
 * the rest of the array
 *
 * Like So
 * [All elements smaller than pivot ]:pivot: [All elements greater than pivot ]
 * @side_effect !
 */
int partition(int arr[], int lo, int hi) {
  int pivot = arr[hi - 1];
  int i = lo - 1;
  /// put all the elements that are smaller than pivot
  /// in the beginning
  for (int j = lo; j < hi - 1; j++) {
    if (arr[j] <= pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }
  // put the pivot after the biggest element
  // that is smaller than pivot
  i++;
  std::swap(arr[hi - 1], arr[i]);
  return i;
}

void QuickSort(int arr[], int lo, int hi) {
  if (lo >= hi || lo < 0)
    // OutSide the Range
    return;
  int p = partition(arr, lo, hi);
  QuickSort(arr, lo, p);
  QuickSort(arr, p + 1, hi);
}
