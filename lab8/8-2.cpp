#include <iostream>
#include <utility>

using std::pair; 
using std::make_pair;

int count = 0;
pair<int, int> knapsack(pair<int, int> tempItem[], const pair<int ,int> items[], const int n, int k, const int capacity, int sumWeight) {
  count++;
  if (k == n) {
    
    for (int i = 0; i < n; i++) {
      std::cout << tempItem[i].first << " " << tempItem[i].second << "| ";
    }

    std::cout << "\n";
    
    int totalValue = 0;
    int totalWeight = 0;
    for (int i = 0; i < n; ++i) {
        totalValue += tempItem[i].first;
        totalWeight += tempItem[i].second;
    }
    return make_pair(totalValue, totalWeight);
  }

  pair<int, int> a, b;

  if (sumWeight + items[k].second <= capacity) {
    tempItem[k] = items[k];
    a = knapsack(tempItem, items, n, k + 1, capacity, sumWeight + items[k].second);
  }

  tempItem[k] = make_pair(0, 0);
  b = knapsack(tempItem, items, n, k + 1, capacity, sumWeight);

  return (a.first > b.first) ? a : b;
}

int main() {
    int n, c;
    std::cin >> n >> c;
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i].first >> arr[i].second;
    }

    pair<int, int> result = knapsack(new pair<int, int>[n], arr, n, 0, c, 0);
    std::cout << result.first << " " << result.second << " " << count;
    return 0;
}