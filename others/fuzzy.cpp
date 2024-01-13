#include <cstdlib> 
#include <iostream> 
#include <random>
#include <time.h>

int main() {
  int n;
  std::cin >> n;

  std::srand(time(0));

  for (int i = 0; i < n; i++) {
    int start = std::rand() % 100000;
    int end = std::rand() % 100000 + start + 1;
    std::cout << start << " " << end << "\n";
  }

  std::cout << "\n";

  return 0;
}