#include <iostream>
void swap(int *a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;	
}

void subset(int* arr, int n, int  k) {
	if (k == n) {
//	  check(arr);
	for(int i = 0; i < n; i++) {
	std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	}
	else {
    arr[k] = 1;
    subset(arr, n, k + 1);
    arr[k] = 0;
    subset(arr, n, k + 1);
	}
}

void subset2(int* arr, int n, int k) {
	if (n == k) {
	}	
	else {
		for(int i = 0; i < n; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
		int j = (k == 0) ? 1 : arr[k] + 1;
		for(int i = j; i <= n; i++) {
			arr[k] = i;
			subset2(arr, n, k + 1);
		}
	}
}

void perm(int *arr, int n, int k) {
	if (k == n) {
		for(int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}
	else {
		for(int i = k; i < n; i++) {
			swap(&arr[k], &arr[i]);
			
			perm(arr, n, k + 1);
			
			swap(&arr[k], &arr[i]);
		}
	}
}

int plate(int *arr, int *nums, int n, int k) {
	if (k == n) {
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] == 1 && arr[i + 1] == 1) {
				return 0;
			}
		}

		int sum = 0;
		for(int i = 0; i < n; i++) {
			if (arr[i] == 1) {
				sum += nums[i];
			}
		}
		return sum;
	}
	else {
      arr[k] = 1;
      int a = plate(arr, nums, n, k + 1);
      arr[k] = 0;
      int b = plate(arr, nums, n, k + 1);
      return std::max(a, b);
	}
}

int main() {
	int* arr = new int[10];
	int nums[10] = {30, 10, 8, 20, 11, 12, 25, 13, 20, 19};
	for(int i = 0; i < 10; i++) {
		arr[i] = 0;
	}

	// std::cout << plate(arr, nums, 10, 0);
  perm(new int[3]{3, 2, 1}, 3, 0);
	return 0;
}
