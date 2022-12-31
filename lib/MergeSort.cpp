
#include "MergeSort.h"
#include <cmath>

/**
 * @brief -> Assume 2 lists are sorted ,
 * returning a merged sort list
 * */
int *Merge2Lists(int arrA[], int n1, int arrB[], int n2) {
  int *output = new int[n1 + n2];
  int i = 0, j = 0, k = 0;
  while (i < n1 && j < n2) {
    if (arrA[i] > arrB[j]) {
      output[k] = arrB[j];
      k++;
      j++;
    } else {
      output[k] = arrA[i];
      k++;
      i++;
    }
  }
  while (i < n1) {
    output[k] = arrA[i];
    k++;
    i++;
  }
  while (j < n2) {
    output[k] = arrB[j];
    k++;
    j++;
  }
  return output;
}
/**
 * @brief Given an array , sort it
 * */
int *MergeSort(int arrA[], int n) {
  if (n == 1)
    return arrA;
  int n1 = n % 2 == 0 ? static_cast<int>(n / 2) : static_cast<int>(n / 2 + 1);
  int n2 = static_cast<int>(n / 2);
  int *arrLeft = new int[n1];
  int *arrRight = new int[n2];
  for (int i = 0; i < n; i++) {
    if (i < n1) {
      arrLeft[i] = arrA[i];
    } else {
      arrRight[i - n1] = arrA[i];
    }
  }
  arrLeft = MergeSort(arrLeft, n1);
  arrRight = MergeSort(arrRight, n2);
  return Merge2Lists(arrLeft, n1, arrRight, n2);
}

// void splitMerge(int[] arrA, int n1, int[] arrB, int n2) {}
