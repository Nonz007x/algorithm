#include <iostream>
#include <set>
#include <algorithm>
#include <string>

int lexicography(int *arr, int n, int k, int c) {
  if (c == k) {
    for (int i = 0; i < k; i++) {
      std::cout << arr[i] + 1 << " ";
    }
    std::cout << "\n";
    return 1;
  } else {
    int sum = 0;
    for (int i = (c == 0) ? 0 : arr[c - 1] + 1; i < n; i++) {
      arr[c] = i;
      sum += lexicography(arr, n, k, c + 1);
    }
    return sum;
  }
} 

int main() {
  int n, k;
  std::cin >> n >> k;

  std::cout << lexicography(new int[n], n, k, 0);

  return 0;
}