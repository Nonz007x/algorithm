#include <iostream>

int leastDiff(int *arr, const int *nums, const int n, int k, int count0, int count1) {
	if (k == n) {
		int midori = 0;
		int momoi = 0;

		for (int i = 0; i < n; i++) {
			if (arr[i] == 1)  midori += nums[i];
      else momoi += nums[i];
		}

		return abs(midori - momoi);
	}

  int a = INT32_MAX, b = INT32_MAX;
  if (count1 < n / 2) {
    arr[k] = 1;
    a = leastDiff(arr, nums, n, k + 1, count0, count1 + 1);
  }

  if (count0 < n / 2) {
    arr[k] = 0;
    b = leastDiff(arr, nums, n, k + 1, count0 + 1, count1) ;
  }
  
  return std::min(a, b);
}

int main() {
  int n;
  std::cin >> n;
  int arr[n * 2];
	int nums[n * 2];
	for(int i = 0; i < n*2; i++) {
		std::cin >> nums[i];
	}

	std::cout << leastDiff(arr, nums, n * 2, 0, 0, 0);
  return 0;
}