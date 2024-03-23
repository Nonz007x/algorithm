#include <iostream>
#include <vector>

using namespace std;

int countt = 0;
int step(int n, int m, vector<int>& mem) {
  countt++;
  if (n == 0)
    return 1;
  if (mem[n] != 0)
    return mem[n]; 

  for (int i = 1; i <= m; i++) {
    if (n - i >= 0) {
      mem[n] += step(n - i, m, mem);
    }
  }

  for (int i = 0; i <= 4; i++) {
    cout << mem[i] << " ";
  }
  cout << "\n";
  
  return mem[n];
}
int main() {
  int n = 3;
  vector<int> mem(n + 1, 0);
  cout << step(n, 2, mem);
  cout << "\n" << countt;
  return 0;
}