#include <iostream>
#include <algorithm>
#include <iomanip>

double retrieve(int arr[], const int n) {
  std::sort(arr, arr + n);
  int result = 0;
  for (int i = 0; i < n; i++) {
    result += arr[i] * (n - i);
  }

  return result / (double) n;
}

int main() {
  int n;
  std::cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  std::cout << std::fixed << std::setprecision(2) << retrieve(arr, n);
  return 0;
}