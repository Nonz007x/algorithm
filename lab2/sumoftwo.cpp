#include <iostream>

int main() {
  int n, k;
  std::cin >> n;
  std::cin >> k;
  int arr[n];
  for (int i = 0; i < n;) {
    int num;
    std::cin >> num;
    if (num >= k) {
      arr[i++];
    }
  }
  
  return 0;
}