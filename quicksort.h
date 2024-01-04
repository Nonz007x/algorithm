#include <iostream>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int lomuto_partition(int* arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }

  std::swap(arr[i + 1], arr[high]);
  return i + 1;
}

int partition(int* arr, int low, int high) {
  int pivot = arr[low];
  int i = low + 1;
  int j = high;

  while (true) {
    while (i <= j && arr[i] <= pivot) {
      i++;
    }

    while (j >= i && arr[j] > pivot) {
      j--;
    }

    if (i <= j) {
      std::swap(arr[i], arr[j]);
    } else {
        break;
    }
  }
  std::swap(arr[low], arr[j]);
  return j;
}

void quicksort(int* arr, int low, int high) {
  if (low < high) {
    int pivotIndex = lomuto_partition(arr, low ,high);
    quicksort(arr, low, pivotIndex - 1);
    quicksort(arr, pivotIndex + 1, high);
  }
}