#include <iostream>
#include <limits.h>
#include <unordered_map>
#include <algorithm>
#include <vector>

int freqDiff(const int* arr, const int n) {
    std::unordered_map<int, int> countMap;

    int maxCount = 1;
    int minCount = INT_MAX;

    for (int i = 0; i < n; ++i) {
        int currentElement = arr[i];
        countMap[currentElement]++;

        if (countMap[currentElement] > maxCount) {
            maxCount = countMap[currentElement];
        }
    }

    for (const auto i : countMap) {
        minCount = std::min(i.second, minCount);
    }
    
    int maxMinDiff = maxCount - minCount;
    return maxMinDiff;
}

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int result = freqDiff(arr, n);

    std::cout << result << std::endl;

    return 0;
}
