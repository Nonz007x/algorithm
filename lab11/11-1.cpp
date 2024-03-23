#include <iostream>
#include <vector>

using namespace std;

int sum(int n, int k, int A[], int depth, vector<vector<int>>& m) {
  if (n == 0 && k == 0) {
      return depth;
    }
  if (n == 0 || k < 0) {
    return -1;
  }
  // if (m[n][k] > 0) {
  //   return m[n][k];
  // }

  int a = sum(n - 1, k, A, depth, m);
  int b = sum(n - 1, k - A[n - 1], A, depth + 1, m);
  m[n][k] = max(a, b);
  return m[n][k];
}

int main() {
  int n = 5;
  int k = 3;
  int A[] = {1, 2, 1, 2, 1};

  vector<vector<int>> m(n + 1, vector<int>(k + 1, 0));
  
  cout << sum(n, k, A, 0, m);
  return 0;
}
