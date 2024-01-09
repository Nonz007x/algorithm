#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <algorithm>

std::array<int, 2> findLeastSum(const int* arr, const int n, const int target) {
    std::array<int, 2> result = {-1, -1};
    std::unordered_map<int, int> numMap;
    int minDifference = INT_MAX;

    for (int i = 0; i < n; i++) {
      numMap[arr[i]]++;
      int complement = target - arr[i];
      int subtractorCount = numMap[complement];

      if (complement == arr[i] && subtractorCount <= 1) // continue if there is only one of it kind to avoid counting itself.
        continue;

      if (subtractorCount > 0 && std::abs(complement - arr[i]) < minDifference) {
        result = {std::min(arr[i], complement), std::max(arr[i], complement)};
        minDifference = std::abs(complement - arr[i]);
      }
    }

    return result;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  std::array<int, 2> result = findLeastSum(arr, n, k);
  std::cout << result[0] << " " << result[1] << "\n";
  return 0;
}