#include <iostream>
#include "quicksort.h"
#include <string>
#include <sstream>  

std::string buildStream(int* arr, int size) {
  std::stringstream ss;
    
  for (int i = 0; i < size; i++) {
    ss << std::to_string(arr[i]);
  }
    
  return ss.str();
}

std::string searchAndReduce(std::string nums) {
  int i = 0;
  int arrIterator = 0;
  int consecutive = 1;
  int maxConsecutive = 1;
  int tempArr[nums.length()];
  std::stringstream ss;

  for (int i = 0; nums[i] != '\0'; i++) {
    while (nums[i] == nums[i + 1]) {
      i++;
      consecutive++;
    }

    if (consecutive > maxConsecutive) {
      maxConsecutive = consecutive;
      consecutive = 1;
    }
  }

  consecutive = 1;

  for (int i = 0; nums[i] != '\0'; i++) {
    while (nums[i] == nums[i + 1]) {
      i++;
      consecutive++;
    }

    if (consecutive >= maxConsecutive) {
      tempArr[arrIterator++] = nums[i] - '0';
      consecutive = 1;
    }
    ss << nums[i];
  }

  quicksort(tempArr, 0, arrIterator);

  int outputArr[arrIterator];
  int outputArrSize = 0;

  for (int i = 0; i < arrIterator; i++) {
    if (tempArr[i] != tempArr[i + 1]) {
      outputArr[outputArrSize++] = tempArr[i];
    }
  }

  for (int i = 0; i < outputArrSize; i++) {
    std::cout << outputArr[i] << " ";
  }
  std::cout << "\n";
  
  return ss.str();
}

int main () {
  int n;
  std::string numStream;
  std::cin >> n;
  int arr[n];

  for (size_t i = 0; i < n; i++)
    std::cin >> arr[i];

  quicksort(arr, 0, n-1);

  for (auto& num: arr) 
    std::cout << num;
  std::cout << "\n";

  numStream = buildStream(arr, n);
  std::cout << searchAndReduce(numStream) << "\n";
  return 0;
}