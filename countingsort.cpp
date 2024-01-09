#include <iostream>

void countingsort(int a[], int n) {
  int b[5];
  for (int i = 0; i < n; i++) {
    int currentCount = 0;
    for (int j = 0; j < n; j++) {
      if (a[i] > a[j]) {
        std::cout << currentCount << " ";
        currentCount++;
      }
    }
    b[currentCount] = a[i];
    std::cout << "\n";
  }
  for (int i = 0; i < 5; i++) {
    std::cout << b[i] << " ";
  }
}

int main() {
  int arr[] = {5, 4, 3, 2, 1};
  countingsort(arr, 5);
  return 0;
}