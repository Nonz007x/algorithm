#include <iostream>
#include <vector>

using namespace std;
int f(int n, int k, vector<vector<int>> m) {
  if (n == k || k == 0 || k == 1)
    return 1;
  else if (m[n][k] == 1) 
    return m[n][k];
  
  else {
    m[n][k] = f(n - 1, k, m) + f(n - 1, k - 2, m);
    return m[n][k];
  }
}

int g(int n, int m[]) {
  if (n == 1 || n == 2) 
    return 1;
  else if (n == 0) 
    return 0;

  else if (m[n] == 1)
    return m[n];

  else {
    m[n] = g(n - 1, m) + g(n - 2, m) - g(n - 3, m);
    return m[n];
  } 

  return 1;
}

int f2(int n, int k) {
  int m[n + 1][n + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      m[i][j] = 0;
    }
  }
  
  int sum = 0;

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      if (i == j || j <= 1) {
        m[i][j] = 1;
      } else {
        m[i][j] = m[i - 1][j] + m[i - 1][j - 2];
      }
    }
  }
  return m[n][k];
}

int g2(int n) {
  int m[n + 1] = {0};
  m[0] = 0;
  m[1] = 1;
  m[2] = 1;
  for (int i = 3; i <= n; i++) {
    m[i] = m[i - 1] + m[i - 2] - m[i - 3];
  }
  return m[n];
}

int main () {
  int n = 7;
  int m[n + 1] = {0};
  int n2 = 6;
  vector<vector<int>> m2(7, vector<int>(7, 0));


  cout << f(n2, 4, m2);
  cout << "\n";
  cout << g(n, m);
  cout << "\n";
  cout << f2(n2, 4);
  cout << "\n";
  cout << g2(7);
  return 0;
}