#include <iostream>
#include <vector>

using namespace std;

int sum(int n, int k, int A[], vector<vector<int>>& m) {
  if (n == 0 && k == 0) {
      return 0;
    }
  if (n == 0 || k < 0) {
    return -1;
  }
  if (m[n][k] > 0) {
    return m[n][k];
  }

  int a = sum(n - 1, k, A, m);
  int b = 1 + sum(n - 1, k - A[n - 1], A, m);
  m[n][k] = max(a, b);
  return m[n][k];
}

int sumBottomUp(int n, int k, int A[]) {
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
  dp[0][0] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      if (j < A[i - 1]) {
        dp[i][j] = dp[i - 1][j];
      } else {
        int exclude = dp[i - 1][j];
        int include = 1 + dp[i - 1][j - A[i - 1]];
        dp[i][j] = max(exclude, include);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }

}

int knapsack(vector<pair<int,int>> A, int n, int k) {
  vector<vector<int>> mem(n + 1, vector<int>(k + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (A[i - 1].second < j) 
        mem[i][j] = max(A[i - 1].first + mem[i - 1][j - A[i - 1].second], mem[i - 1][j]);
      else
        mem[i][j] = mem[i - 1][j]; 
    }
  }
  return mem[n][k];
} 

int main() {
  int n = 5;
  int k = 5;
  int A[] = {1, 2, 1, 2, 1};

  vector<vector<int>> m(n + 1, vector<int>(k + 1, 0));
  
  // cout << sum(n, k, A, m);
  // sumBottomUp(n, k, A);
  cout << knapsack({{3, 2},{4, 3},{5, 4}}, 3, 7);
  return 0;
}
