#include <iostream>
#include <utility>

using namespace std;

void gen(int k, int n, int arr[]) {
  if (k == n) {
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
  } else {
    arr[k] = 0;
    gen(k + 1, n, arr);
    arr[k] = 1;
    gen(k + 1, n, arr);
  }
}

void nQueens(int k, int n, int arr[]) {
  if (k == n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        // same diagonal || same row
        if (abs(arr[i] - arr[j]) == abs(j - i) || arr[j] == arr[i]) {
          return;
        }
      } 
    }
  
    for (int i = 0; i < k; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << "\n";
  } else {
    for (int i = 0; i < n; i++) {
      arr[k] = i;
      nQueens(k + 1, n, arr);  
    }    
  }
}

int knapsack(int k, int n, int arr[], pair<int,int> items[], int cap) {
  if (k == n) {
    int weight = 0;
    int value = 0;

    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
      if (arr[i] == 1) {
        weight += items[i].first;
        value += items[i].second;
      }
    }
    cout << "\n";

    if (weight <= cap)
      return value;
    else 
      return -1;

  } else {
    arr[k] = 0;
    int a = knapsack(k + 1, n, arr, items, cap);
    arr[k] = 1;
    int b = knapsack(k + 1, n, arr, items, cap);
    return max(a, b);
  }
}

int subsetsum(int k, int n, int arr[], int nums[], int target) {
  if (k == n) {
    int amount = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] == 1) {
        amount += nums[i];
        count++;
      }
    }

    if (amount == target)
      return count;
    else 
      return INT32_MAX;

  } else {
    arr[k] = 0;
    int a = subsetsum(k + 1, n, arr, nums, target);
    arr[k] = 1;
    int b = subsetsum(k + 1, n, arr, nums, target);
    return min(a, b);
  }
}

void genfor(int n) {
  int arr[n];
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      arr[j] = (i >> j) & 1;
    }
    for (int j = 0; j < n; j++) {
      cout << arr[j] << " ";
    }
    cout << "\n";
  }
}

int main() {
  // gen(0, 3, new int[3]);
  // genfor(4);
  // nQueens(0, 4, new int[4]);
  pair<int,int> items[4] = {{12, 8}, {5, 7}, {4, 4}, {2, 2}};
  cout << knapsack(0, 4, new int[4], items, 18);
  // cout << subsetsum(0, 3, new int[3], new int[3]{1, 5, 25}, 30);
  return 0;
}