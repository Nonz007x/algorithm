#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <iomanip>

using std::get;
bool compareRatio(std::tuple<int, int, int>& a, std::tuple<int, int, int>& b) {
  return ((double) get<1>(a) / get<0>(a)) > ((double) get<1>(b) / get<0>(b));
};

double knapsack(const int ws[], const int vs[], const int n, const int cap) {
  std::vector<std::tuple<int, int, int>> ratios;
  double fracRatio[n] = {0.0};
  for (size_t i = 0; i < n; i++) {
    ratios.push_back({ws[i], vs[i], i});
  }

  std::sort(ratios.begin(), ratios.end(), compareRatio);

  double space = cap;
  double netValue = 0;
  for (int i = 0; i < n; i++) {
    int currentWeight = get<0>(ratios[i]);
    int currentValue = get<1>(ratios[i]);
    int currentIndex = get<2>(ratios[i]);
    
    if (currentWeight <= space) {
        space -= currentWeight;
        netValue += currentValue;
        fracRatio[currentIndex] = 1.0;
    } else {
        double fraction = space / (double)currentWeight;
        netValue += fraction * currentValue;
        fracRatio[currentIndex] = fraction;
        break;
    }
  }

  for (int i = 0; i < n; i++) {
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << fracRatio[i] << " ";
  }
  
  std::cout << "\n";

  return netValue;
}

int main() {
  int n, cap;
  std::cin >> n >> cap;
  int ws[n];
  int vs[n];

  for (int i = 0; i < n; i++) {
    std::cin >> ws[i];
  }

  for (int i = 0; i < n; i++) {
    std::cin >> vs[i];
  }

  std::cout << knapsack(ws, vs, n, cap);
  return 0;
}