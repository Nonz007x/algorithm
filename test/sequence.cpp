#include <iostream>

int sequence(int n) {
    if (n == 1)
        return 1;
    return 2*sequence(n/2) + n;
}
int main() {
    int n;
    std::cin >> n;
    int r = sequence(n);
    std::cout << r << "\n";
}