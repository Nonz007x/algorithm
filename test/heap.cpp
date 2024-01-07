#include <iostream>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void heapify(int arr[], int n, int parent) {
    int largest = parent;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != parent) {
        swap(arr[parent], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
  int a[] = {1,2,3,4,5};

  heapSort(a, 5);

  for (const auto num: a) {
    std::cout << num << " ";
  }
  return 0;
}