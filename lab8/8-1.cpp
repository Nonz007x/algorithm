#include <iostream>
#include <set>
#include <algorithm>
#include <string>

void subsetsum(int* arr, int nums[], int n, int  k, const int target, int sum) {
	if (k == n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] == 1) 
        sum += nums[i];
    }

    if (sum == target) {
      for (int i = 0; i < n; i++) {
        if (arr[i] == 1)
          std::cout << nums[i] << " ";
      }
      std::cout << "\n";
    }
  }
	else {
    arr[k] = 0;
    subsetsum(arr, nums, n, k + 1, target, sum);

    sum += nums[k];
    if (sum <= target) {
      arr[k] = 1;
      subsetsum(arr, nums, n, k + 1, target, sum);
    }
	}
}

int main() {
  int n, t;
  std::cin >> n >> t;
  int arr[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  subsetsum(new int[n], arr, n, 0, t, 0);
  return 0;
}