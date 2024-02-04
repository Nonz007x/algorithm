#include <iostream>
#include <set>
#include <algorithm>
#include <string>

int subset(int* arr, int nums[], int n, int  k) {
	if (k == n) {
    bool allZero = true;
    for (int i = n - 1; i >= 0; i--) {
      if (arr[i] == 1) {
        std::cout << nums[i] + 1;
        allZero = false;
      }
    }

    if (allZero) {
      std::cout << "0";
    }

    std::cout << "\n";
    return 1;
  }
	else {
    int sum = 0;
    arr[k] = 0;
    sum += subset(arr, nums, n, k + 1);
    arr[k] = 1;
    sum += subset(arr, nums, n, k + 1);

    return sum;
	}
}

int main() {
  int n;
  std::cin >> n;
  int arr[n];
  for (int i = 1; i <= n; i++) {
    arr[i - 1] = n - i;
  }

  std::cout << subset(new int[n], arr, n, 0);
  return 0;
}