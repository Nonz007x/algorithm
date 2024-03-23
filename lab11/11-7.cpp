#include <iostream>
#include <vector>

using namespace std;

int tiger(int n, int m, vector<vector<int>>& mem) {
  if (n == 0 && m == 0)
    return 1;
  if (mem[n][m] != 0)
    return mem[n][m];

  int a = 0;
  int b = 0;

  if (n > 0)
    a = tiger(n - 1, m, mem);
  if (m > 0)
    b = tiger(n, m - 1, mem);
  
  mem[n][m] = a + b;
  
  return mem[n][m];
}

int main() {
  int n = 2;
  int m = 5;
  vector<vector<int>> mem(n + 1, vector<int>(m + 1, 0));
  cout << tiger(n - 1, m - 1, mem);
  return 0;
}