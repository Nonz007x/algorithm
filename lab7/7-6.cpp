#include <iostream>

// < coupon
// > 3 books
// no duplicate

void lexicography(int *arr, int nums[], int n, int c, bool used[], int couponValue) {
  if (c == 3) {
    int sum = 0;

    for (int i = 0; i < 3; i++) {
			sum += nums[arr[i]];
		}

    if (sum <= couponValue ) {
      for (int i = 0; i < 3; i++) {
        std::cout << nums[arr[i]] << " ";
      }
      std::cout << "\n";
    }
  } 
  else {
    int sum = 0;
    for (int i = (c == 0) ? 0 : arr[c - 1] + 1; i < n; i++) {
      arr[c] = i;
      lexicography(arr, nums, n, c + 1, used, couponValue);
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
  
  bool used[n] = {false};
  lexicography(new int[n], arr, n, 0, used, couponValue);

  return 0;
}