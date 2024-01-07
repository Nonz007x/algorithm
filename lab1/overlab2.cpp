#include <iostream>
#include <unordered_map>

void overlab(const int* a, const int* b, const int n) {
    std::unordered_map<int, int> timePoints;

    int maxTrafficTime = 0;
    int maxTrafficCount = 1;

    for (int i = 0; i < n; i++) {
        timePoints[a[i]]++;
        timePoints[b[i]]++;

        if (timePoints[a[i]] > maxTrafficCount) {
            maxTrafficCount = timePoints[a[i]];
            maxTrafficTime = a[i];
        }

        if (timePoints[b[i]] > maxTrafficCount) {
            maxTrafficCount = timePoints[b[i]];
            maxTrafficTime = b[i];
        }
    }

    std::cout << maxTrafficTime << " " << maxTrafficCount << "\n";
}

int main() {
    int n;
    std::cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    overlab(a, b, n);   
    return 0;
}