#include <iostream>
#include <unordered_map>

void overlab(const int* a, const int* b, const int n) {
    std::unordered_map<int ,int> timePoints;
    
    int maxTrafficTime = 0;
    int maxTrafficCount = 1;

    for (int i = 0; i < n; i++) {
        int enteringTime = a[i];
        int exitingTime = b[i];
        timePoints[enteringTime]++;
        timePoints[exitingTime]++;

        if (timePoints[enteringTime] > maxTrafficCount) {
            maxTrafficCount = timePoints[enteringTime];
            maxTrafficTime = enteringTime;
        }

        if (timePoints[exitingTime] > maxTrafficCount) {
            maxTrafficCount = timePoints[exitingTime];
            maxTrafficTime = exitingTime;
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