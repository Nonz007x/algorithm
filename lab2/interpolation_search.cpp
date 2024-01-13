#include <iostream>

void interpolationSearch(const int arr[], const int l, const int h, const int key) {
  if (l <= h && key >= arr[l] && key <= arr[h]) {
    int pos = l + (((key - arr[l]) * (h - l)) / (arr[h] - arr[l]));
    std::cout << pos << " ";
    if (arr[pos] < key) {
      interpolationSearch(arr, pos + 1, h, key);
    } else if (arr[pos] > key) {
      interpolationSearch(arr, l, pos - 1, key);
    } else {
      return;
    }
    } else {
      return;
    }
}

int main() {
  int key, n;

  std::cin >> n;
  std::cin >> key;

  int arr[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  interpolationSearch(arr, 0, n - 1, key);
  return 0;
}