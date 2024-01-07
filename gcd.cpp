#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
  int m,n;

  std::cin >> m;
  std::cin >> n;
  
  int count = 0;
  while (m != n) {
    count++;
      if (m > n)
          m = m - n;
      else
          n = n - m;
  }

  std::cout << "GCD: " << m << std::endl;
  std::cout << "Counts: " << count << std::endl;
  return 0;
}

