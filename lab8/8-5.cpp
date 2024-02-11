#include <iostream>
int count = 0;
void coupon(int *arr, int nums[], int n, int c, int couponValue, int prevSum) {
  count++;
  if (c == n) {
    std::cout << prevSum << "\n";
    return;
  }
  else if (c >= 3) {
    std::cout << prevSum << "\n";
  }

  for (int i = (c == 0) ? 0 : arr[c - 1] + 1; i < n; i++) {
    arr[c] = i;
    prevSum += nums[i];
    
    if (prevSum <= couponValue) {
      coupon(arr, nums, n, c + 1, couponValue, prevSum);
    }

    prevSum -= nums[i];
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
  std::cout << "\n\n" << count;
  return 0;
}