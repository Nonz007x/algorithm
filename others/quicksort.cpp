#include <iostream>


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

void quicksort(int* arr, int low, int high) {
  if (low < high) {
    int pivotIndex = lomuto_partition(arr, low ,high);
    quicksort(arr, low, pivotIndex - 1);
    quicksort(arr, pivotIndex + 1, high);
  }
}

int main() {
  int a[] = {2, 3, 1};
  quicksort(a, 0, 2);
  for (const auto num: a)
    std::cout << num << " ";
  std::cout << "\n" << 0b10011 << " ";
  return 0;
}