#include <iostream>
#include <string>

using std::string;

bool isSorted(const int* arr, const int index, const int n) {
    if (index >= n - 1) {
        return 1;
    }

    if (arr[index] > arr[index + 1]) {
        return 0;
    }

    return isSorted(arr, index + 1, n);
}

int main() {
    int n;
    std::cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    string result = isSorted(arr, 0, n)? "Yes": "No";
    std::cout << result << "\n";
    return 0;
}
