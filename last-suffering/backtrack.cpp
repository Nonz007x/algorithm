#include <iostream>
#include <vector>

using namespace std;

int cot = 0;
void subsetsum(int k, int n, int arr[], int nums[], int sum, int target) {
  cout << cot << "\n";
  if (n == k && sum == target) {
    for (int i = 0; i < n; i++) {
      if (arr[i] != 0) {
        cout << arr[i] << " ";
      }
      cout << "\n";
    }
  } 
  else if (sum + nums[k] <= target) {
    arr[k] == nums[k];
    subsetsum(k + 1, n, arr ,nums, sum + nums[k], target);
    arr[k] == 0;
    subsetsum(k + 1, n, arr ,nums, sum, target);
  }
}

int knapsack(int k, int n, int arr[], pair<int,int> items[], int cap, int w) {
  cot++;
  cout << cot << "\n";
  if (k == n) {
    int value = 0;
    for (int i = 0; i < n; i++) {
      // cout << arr[i] << " ";
      if (arr[i] == 1) {
        value += items[i].second;
      }
    }
    // cout << "\n";
    return value;
  }

  if (w + items[k].first > cap) {
    return knapsack(k + 1, n, arr, items, cap, w);
  }

  int a = -1;
  int b = -1;

  arr[k] = 1;
  a = knapsack(k + 1, n, arr, items, cap, w + items[k].first);
  arr[k] = 0;
  b = knapsack(k + 1, n, arr, items, cap, w);

  return max(a, b);
}

void trapQueen(int arr[], const int n, int currentCol) {
  if (currentCol == n) {
    for (int i = 0; i < currentCol; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
    return;
  }
  else {
    for (int row = 0; row < n; row++) {
      arr[currentCol] = row;
      bool safe = true;
      for (int col = 0; col < currentCol; col++) {  
        if (abs(arr[currentCol] - arr[col]) == abs(currentCol - col) || arr[currentCol] == arr[col]) {
          safe = false;
          break;
        }
      }
      if (safe) trapQueen(arr, n , currentCol + 1);

    } 
  }
}

int maxCoin(vector<int>& coins, vector<int>& arr, int k, int n) {
  if (n == k) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
      if (arr[i] == 1)
        sum += coins[i];
    }
    cout << "\n";
    
    return sum;
  }
  else {

    int a = 0;
    int b = 0;

    if (arr[k - 1] != 1) {
      arr[k] = 1;
      a = maxCoin(coins, arr, k + 1, n);
    }
      arr[k] = 0;
      b = maxCoin(coins, arr, k + 1, n);

    return max(a, b);
  }
}

void coupon(vector<int>& books, int arr[], int k, int n, int value, int count) {
  static int sum = 0;

  if (k == n) {
    if (count >= 3) {
      for (int i = 0; i < n; i++) {
        // cout << arr[i] << " ";
        if (arr[i] == 1) {
          cout << books[i] << " ";
        }
      }
      cout << "\n";
    }
  }
  else {
    
    if (count < 3 && sum + books[k] <= value) {
      arr[k] = 1;
      sum += books[k];
      coupon(books, arr, k + 1, n, value, count + 1);
      sum -= books[k];
    }
    arr[k] = 0;
    coupon(books, arr, k + 1, n, value, count);
  }
}

void comb(int n, int c, int arr[]) {
  if (c == 3) {
    for (int i = 0; i < 3; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
  }
  for (int i = (c == 0) ? 0 : arr[c - 1] + 1; i < n; i++) {
    arr[c] = i;
    comb(n, c + 1, arr);
  }
}

void permute(int n, int c, int arr[], bool used[]) {
  if (c == 2) {
    for (int i = 0; i < 2; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
  } else {
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        arr[c] = i;
        used[i] = true;
        permute(n, c + 1, arr, used);
        used[i] = false;
      }
    }
  }
}

int main() {
  // pair<int,int> items[4] = {{12, 8}, {5, 7}, {4, 4}, {2, 2}};
  // cout << knapsack(0, 4, new int[4], items, 18, 0) << " " << cot;
  // trapQueen(new int[4]{-1}, 4, 0);
  // vector<int> coins = {30, 10, 8, 20, 11, 12, 25, 13, 20, 19};
  // vector<int> arr(coins.size(), 0);
  // cout << maxCoin(coins, arr, 0, 10);
  // int n, v;
  // cin >> n >> v;
  // vector<int> books(n);
  int n = 3;
  int arr[n] = {0};
  bool arr2[n] = {false};
  int c = 0;
  // comb(n, 0, arr);
  permute(n, 0, arr, arr2);
  // for (int i = 0; i < n; i++) {
  //   cin >> books[i];
  // }
  // coupon(books, arr, 0, n, v, 0);
  return 0;
}