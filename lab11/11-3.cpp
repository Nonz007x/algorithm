#include <iostream>
#include <vector>

using namespace std;

int ant(int n, int m, vector<vector<int>>& arr, vector<vector<int>>& mem) {
  if (n == 0 && m == 0)
    return arr[n][m];
  if (mem[n][m] != 0)
    return mem[n][m];

  int a = 0;
  int b = 0;
  if (n > 0)
    a = ant(n - 1, m, arr, mem) +  arr[n][m];
  if (m > 0)
    b = ant(n, m - 1, arr, mem) + arr[n][m];
  
  mem[n][m] = max(a, b);
  return mem[n][m];
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n , vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  
  vector<vector<int>> mem(n, vector<int>(m, 0));
  cout << ant(n - 1, m - 1, arr, mem);
  return 0;
}
