#include <iostream>

int leastDiff(int *arr, int *nums, int n, int k) {
	if (k == n) {
		int midori = 0;
		int momoi = 0;
    int midoriCount = 0;
    int momoiCount = 0;

		for (int i = 0; i < n; i++) {
			if (arr[i] == 1) {
        midoriCount++;
				midori += nums[i];
			} else {
        momoiCount++;
        momoi += nums[i];
      }
		}

    int result = midoriCount == momoiCount ? abs(midori - momoi) : INT32_MAX;
		return result;
	}
	else {
    arr[k] = 1;
    int a = leastDiff(arr, nums, n, k + 1);
    arr[k] = 0;
    int b = leastDiff(arr, nums, n, k + 1);
    return std::min(a, b);
	}
}

int main() {
  int n;
  std::cin >> n;
  int arr[n * 2];
	int nums[n * 2];
	for(int i = 0; i < n*2; i++) {
		std::cin >> nums[i];
	}

	std::cout << leastDiff(arr, nums, n * 2, 0);
  return 0;
}