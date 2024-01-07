#include <iostream>
using namespace std;

void getInput(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}

int inRange(int start, int targetTime, int end) {
  return targetTime >= start && targetTime <= end ? 1 : 0;
}

int main() {
  int n;
    std::cin >> n;
    int arr[n], brr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> brr[i];
    }

  int minTime = arr[0], maxTime = brr[0];
  for (int i = 0; i < n; i++) {
    if (arr[i] < minTime) {
      minTime = arr[i];
    }
    if (brr[i] > maxTime) {
      maxTime = brr[i];
    }
  }

  int maxPresent = 0;
  int idx = -1;
  for (int i = minTime; i <= maxTime; i++) {
    int curPresent = 0;
    for (int j = 0; j < n; j++) {
      curPresent += inRange(arr[j], i, brr[j]);
    }
    if (curPresent > maxPresent) {
      maxPresent = curPresent;
      idx = i;
    }
  }
  cout << idx << " " << maxPresent << endl;
  return 0;
}