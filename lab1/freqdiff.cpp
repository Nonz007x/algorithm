#include <iostream>
#include <limits.h>
#include <unordered_map>
#include <vector>

int freqDiff(const int* arr, const int n) {
    std::unordered_map<int, int> countMap;

    int maxElement = arr[0];
    int maxCount = 1;
    int minCount = INT_MAX;

    for (int i = 0; i < n; ++i) {
        int currentElement = arr[i];
        countMap[currentElement]++;

        if (countMap[currentElement] > maxCount) {
            maxElement = currentElement;
            maxCount = countMap[currentElement];
        }

        if (countMap[currentElement] < minCount) {
            minCount = countMap[currentElement];
        }
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

    std::cout << "Element with maximum occurrence: " << result << std::endl;

    return 0;
}
