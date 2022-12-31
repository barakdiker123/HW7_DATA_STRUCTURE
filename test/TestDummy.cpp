#include "catch2/catch.hpp"
#include <iostream>
#include <type_traits>

#include "Dummy.h"
#include "MergeSort.h"
#include "QuickSort.h"

SCENARIO("Dummy section") {
  GIVEN("Nothing") {
    THEN("1 is always equal to 1") { REQUIRE(1 == 1); }
  }
}
SCENARIO("Test Merge2 Array") {
  GIVEN("Two arrays") {
    int arr1[] = {1, 3, 5, 6};
    int arr2[] = {2, 4};
    int *arr3 = Merge2Lists(arr1, 4, arr2, 2);
    THEN("The Arrays are merged") {
      for (int i = 0; i < 6; i++)
        REQUIRE(arr3[i] == i + 1);
    }
  }
}

SCENARIO("Checks the function mergesort") {
  GIVEN("An unsorted array") {
    int arr[] = {4, 3, 1, 2};
    THEN("The array should be sorted") {
      int *sorted_arr = MergeSort(arr, 4);
      for (int i = 0; i < 4; i++) {
        REQUIRE(sorted_arr[i] == i + 1);
      }
    }
  }
  GIVEN("Another unsorted array") {
    int arr[] = {4, 3, 1, 2, 6, 5};
    THEN("The array should be sorted") {
      int *sorted_arr = MergeSort(arr, 6);
      for (int i = 0; i < 6; i++) {
        REQUIRE(sorted_arr[i] == i + 1);
      }
    }
  }
}
SCENARIO("Checks the function quicksort") {
  GIVEN("An unsorted array") {
    int arr[] = {4, 3, 1, 2};
    THEN("The array should be sorted") {
      QuickSort(arr, 0, 4);
      for (int i = 0; i < 4; i++)
        std::cout << arr[i] << ",";
      for (int i = 0; i < 4; i++) {
        REQUIRE(arr[i] == i + 1);
      }
    }
  }
  GIVEN("Another unsorted array") {
    int arr[] = {4, 3, 1, 2, 6, 5};
    THEN("The array should be sorted") {
      QuickSort(arr, 0, 6);
      for (int i = 0; i < 6; i++)
        std::cout << arr[i] << ",";
      for (int i = 0; i < 6; i++) {
        REQUIRE(arr[i] == i + 1);
      }
    }
  }
}

SCENARIO("Checks Swap ") {
  int a[] = {1, 2};
  std::swap(a[0], a[1]);
  REQUIRE(a[0] == 2);
  REQUIRE(a[1] == 1);
}

SCENARIO("Checks Rounds via static_cast") {
  GIVEN("The Number 3.14") {
    double a = 3.14;
    THEN("b should be 3") {
      int b = static_cast<int>(a);
      REQUIRE(b == 3);
    }
  }
  GIVEN("The Number 3.5") {
    double a = 3.5;
    THEN("b should be 3") {
      int b = static_cast<int>(a);
      REQUIRE(b == 3);
    }
  }
}
