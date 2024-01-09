#include <iostream>
#include <unordered_map>

int findUnique(int *arr, int n) {
  std::unordered_map<int, int> countMap;
  int uniqueCount = 0;
  for (int i = 0; i < n; i++) {
    if (countMap[arr[i]] == 0) {
      countMap[arr[i]] = 1;
      uniqueCount++; 
    }
  }
  return uniqueCount;
}

int main() {
  int n;
  std::cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  std::cout << findUnique(arr, n);

  return 0;
}