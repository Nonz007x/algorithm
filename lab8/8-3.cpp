#include <iostream>

void trapQueen(int arr[], const int n, int k) {
  if (k == n) {
    for (int i = 0; i < k; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << "\n";
  }
  else {
    int sum = 0;
      for (int j = 0; j < n; j++) {
        arr[k] = j;
        bool niceTry = true;
        for (int i = 0; i < k; i++) {  
          if (abs(arr[k] - arr[i]) == abs(k - i) || arr[k] == arr[i]) {
            niceTry = false;
            break;
          }
        }
        if (niceTry) trapQueen(arr, n , k + 1);
      } 
  }
}

int main() {
  int n = 4;

  trapQueen(new int[n], n, 0);
  return 0;
}