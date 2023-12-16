#include <iostream>

int count = 0;
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void heapify(int arr[], int n, int i) {
    count++;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void bubbleSort(int* arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      count++;
      if (arr[j] > arr[j+1]) {
        int temp;
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int concount(int* arr, int n) {
  heapSort(arr, n);
  int count = 1;
  for (int i = 0; i < n-1; i++) {
    if (arr[i+1] != arr[i] + 1) {
      count++;
    }
  }

  return count;
}

int main() {
  int n;
  std::cin >> n;
  int a[n];
  
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::cout << concount(a, n) << std::endl;
  std::cout << count << "\n";
  return 0;
}
