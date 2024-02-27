#include <iostream>
#include <functional>
#include <algorithm>

int griddy(const int arr[], const int n) {
  int left = 0;
  int right = 0;
  for(int i = 0; i < n; i++) {
    if (left < right) {
      left += arr[i];
    } else {
      right += arr[i];
    }
  }

  return abs(left - right);
}

int main() {
  int arr[] = {4, 12, 13, 29, 31, 32, 50};
  int n = sizeof(arr) / sizeof(int);
  std::sort(arr, arr + n, std::greater<int>());

  for (int i = 0; i < n; i++)  {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
  
  std::cout << griddy(arr, n);
  return 0;
}