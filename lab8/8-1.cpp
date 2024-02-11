#include <iostream>
#include <algorithm>

int count = 0;
void subsetsum(int* arr, int nums[], int n, int  k, const int target, int sum) {
  count++;
  if (k == n) {
    if (sum == target) {
      for (int i = 0; i < n; i++) {
        if (arr[i] != 0)
          std::cout << arr[i] << " ";
      }
      std::cout << "\n";
    }
    return;
  }

  if (sum + nums[k] <= target) {
    arr[k] = nums[k];
    subsetsum(arr, nums, n, k + 1, target, sum + nums[k]);
    arr[k] = 0;
    subsetsum(arr, nums, n, k + 1, target, sum);
  }
}

int main() {
  int n, t;
  std::cin >> n >> t;
  int arr[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  subsetsum(new int[n]{0}, arr, n, 0, t, 0);
  std::cout << "\n" << count;
  return 0;
}