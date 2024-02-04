#include <iostream>
#include <set>
#include <algorithm>
#include <string>

int lexicography(int *arr, int n, int k, int c, bool used[]) {
  if (c == k) {
    for (int i = 0; i < k; i++) {
      std::cout << arr[i] + 1 << " ";
    }
    std::cout << "\n";
    return 1;
  } else {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        arr[c] = i;
        used[i] = true;
        sum += lexicography(arr, n, k, c + 1, used);
        used[i] = false;
      }
    }
    return sum;
  }
}

int main() {
  int n, k;
  std::cin >> n >> k;

  bool used[n] = {false};
  std::cout << lexicography(new int[n], n, k, 0, used);

  return 0;
}