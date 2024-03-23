#include <iostream>
#include <vector>

using namespace std;

int combination(int n, int k, vector<vector<int>>& m) {
  if (k > n)
    return 0;
  if (n > 0 && k == 0)
    return 1;
  if (n == k && n >= 0)
    return 1;
  if (m[n][k] != 0)
    return m[n][k];
  
  m[n][k] = combination(n - 1, k - 1, m) + combination(n - 1, k, m);
  return m[n][k];
}

int main() {
  int n = 5;
  int k = 2;

  vector<vector<int>> m(n + 1, vector<int>(k + 1, 0));
  cout << combination(n, k, m);
  return 0;
}
