#include <iostream>

// < couponValue
// > 3 books
// no duplicate

void lexicography(int *arr, int nums[], int n, int c, bool used[], int couponValue, bool &found) {
  if (c == 3 && !found) {
    int sum = 0;

    for (int i = 0; i < 3; i++) {
      sum += nums[arr[i]];
    }

    if (sum <= couponValue) {
      for (int i = 0; i < 3; i++) {
        std::cout << nums[arr[i]] << "\n";
      }
      found = true;
    }
  } else if (!found) {
    for (int i = (c == 0) ? 0 : arr[c - 1] + 1; i < n; i++) {
      arr[c] = i;
      lexicography(arr, nums, n, c + 1, used, couponValue, found);
    }
  }

  if (c == 0 && !found) {
    for (int i = 0; i < 3; i++) {
      std::cout << "0\n";
    }
  }
}

int main() {
  int n, couponValue;
  std::cin >> n >> couponValue;
  int arr[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  std::cout << "\n";
  
  bool used[n] = {false};
  bool found = false;
  lexicography(new int[n], arr, n, 0, used, couponValue, found);

  return 0;
}