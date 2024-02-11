#include <iostream>

// < couponValue
// > 3 books
// no duplicate

void coupon(int *arr, int nums[], int n, int c, int couponValue, int prevSum) {
  if (c == 3) {
    std::cout << prevSum << "\n";
  } else {
    for (int i = (c == 0) ? 0 : arr[c - 1] + 1; i < n; i++) {
      arr[c] = i;
      prevSum += nums[i];
      
      if (prevSum > couponValue) {
        prevSum -= nums[i];
      }
      else {
        coupon(arr, nums, n, c + 1, couponValue, prevSum);
        prevSum -= nums[i];
      }
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
  
  coupon(new int[n], arr, n, 0, couponValue, 0);
  return 0;
}