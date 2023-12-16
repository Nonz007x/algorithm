#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open a file for writing
    std::ofstream outputFile("example.txt");

    // Check if the file is successfully opened
    if (outputFile.is_open()) {
    // Write data to the file
        std::string result;

        for (int i = 2; i < 1000000; i++) {
            result.append(std::to_string(i)).append(" ");
        }

        outputFile << result;

    // Close the file
         outputFile.close();

        std::cout << "Data has been written to the file.\n";
    } else {
        std::cerr << "Unable to open the file for writing.\n";
    }

    return 0;
}
