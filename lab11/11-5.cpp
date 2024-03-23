#include <iostream>

using namespace std;

int seq(int n) {
  int m[n];
  m[0] = 1;
  m[1] = 1;

  for (int i = 2; i < n; i++) {
    m[i] = 3 * m[i - 1] + m[i - 2];
  }
  
  return m[n - 1];
}

int main () {

  for (int i = 3; i < 10; i++) {
    cout << seq(i) << "\n";
  }
  return 0;
}