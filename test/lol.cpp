#include <iostream>
#include <cmath>

int main() {
  int n;
  std::cin >> n;
  int sum = std::pow(2, n);
  for (int i = 1; i <= n; i++) {
    sum += std::pow(2,n-i)*i;
  }

  std::cout << sum << "\n";

  return 0;
}
