#include <iostream>
#include <set>
#include <algorithm>
#include <string>

void countingSort(int arr[], int n) {
  int max = INT32_MIN;
  int min = INT32_MAX;

  for (int i = 0; i < n; i++) {
    max = std::max(arr[i], max);
    min = std::min(arr[i], min);
  }

  int size = max - min + 1;
  int counterArr[size] = {0};
  int tempArr[n];

  for (int i = 0; i < n; i++) {
    counterArr[arr[i] - min]++;  
  }

  for (int i = 1; i < size; i++) {
    counterArr[i] += counterArr[i - 1];
  }


  for (int i = 0; i < n; i++) {
    tempArr[--counterArr[arr[i] - min]] = arr[i];
  }

  std::copy(tempArr, tempArr + n, arr);
}

void lexicography(int arr[], int letters[], int n, int k, bool used[]) {
  if (k == n) {
    for (int i = 0; i < n; i++) {
      std::cout << (char)letters[arr[i]] << " ";
    }
    std::cout << "\n";
}
	else {
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        arr[k] = i;
        used[i] = true;
        lexicography(arr, letters, n, k + 1, used);      
        used[i] = false;
      }
    }    
	}
}

void perm(int *arr, int n, int k) {
	if (k == n) {
		for(int i = 0; i < n; i++) {
		std::cout << (char)arr[i] << " ";
		}
		std::cout << "\n";
	}
	else {
		for(int i = k; i < n; i++) {
			std::swap(arr[k], arr[i]);
			
			perm(arr, n, k + 1);
			
			std::swap(arr[k], arr[i]);
		}
	}
}

int main() {
  int n;
  std::cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    char temp;
    std::cin >> temp;
    arr[i] = temp;
  }

  bool used[n] = {false};
  countingSort(arr, n);
  lexicography(new int[n], arr, n, 0, used);
  // perm(arr, n, 0);

  return 0;
}