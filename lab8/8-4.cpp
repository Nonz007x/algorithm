#include <iostream>

int plate(int *arr, int *nums, int n, int k, int prevBit) {
	if (k == n) {
		int sum = 0;
    for (int i = 0; i < n; i++) { 
      std::cout << arr[i];
    }
    std::cout << "\n";

		for (int i = 0; i < n; i++) {
			if (arr[i] == 1) {
				sum += nums[i];
			}  
		}
		return sum;
	}
	else {
    int a = INT32_MIN;
    int b = INT32_MIN;
    if (prevBit != 1) {
      arr[k] = 1;
      a = plate(arr, nums, n, k + 1, 1);
    }

    arr[k] = 0;
    b = plate(arr, nums, n, k + 1, 0);
    return std::max(a, b);
	}
}

int main() {
  int n = 10;
	int* arr = new int[n];
	int nums[n] = {30, 10, 8, 20, 11, 12, 25, 13, 20, 19};
	for(int i = 0; i < n; i++) {
		arr[i] = 0;
	}

	std::cout << plate(arr, nums, n, 0, 0);

  // from 1024 to 144
	return 0;
}
