#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

std::vector<int> findUnion(const std::vector<int>& arr1, const std::vector<int>& arr2) {
  // std::unordered_set<int> uniqueElements;
  std::unordered_map<int, int> uniqueElements;
  std::vector<int> unionResult;

  for (const auto& arr : {arr1, arr2}) {
    for (int num : arr) {
      if (uniqueElements[num] < 1) { // if not exist
        unionResult.push_back(num);
        uniqueElements[num]++;
      }
    }
  }

  return unionResult;
}

std::vector<int> findIntersection(const std::vector<int>& arr1, const std::vector<int>& arr2) {
  std::unordered_map<int, int> uniqueElements;
  std::vector<int> intersectResult;


  for (const auto& num : arr1) {
    if (uniqueElements[num] < 1) { // if not exist
      uniqueElements[num]++;
    }
  }

  for (const auto& num : arr2) {
    if (uniqueElements[num] >= 1) {
      intersectResult.push_back(num);
    }
  }

  return intersectResult;
}

int main() {
  int n;
  std::vector<int> array1;
  std::vector<int> array2;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int temp;
    std::cin >> temp;
    array1.push_back(temp);
  }

  for (int i = 0; i < n; i++) {
    int temp;
    std::cin >> temp;
    array2.push_back(temp);
  }

  std::vector<int> setUnion = findUnion(array1, array2);
  std::vector<int> setIntersection = findIntersection(array1, array2);

  for (const int num: setIntersection)
    std::cout << num << " ";
  std::cout << "\n";

  for (const int num: setUnion)
    std::cout << num << " ";
  std::cout << "\n";
  

  return 0;
}