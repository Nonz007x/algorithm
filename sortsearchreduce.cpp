#include <iostream>
#include <string>
#include <sstream>  

int lomuto_partition(int* arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }

  std::swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quicksort(int* arr, int low, int high) {
  if (low < high) {
    int pivotIndex = lomuto_partition(arr, low ,high);
    quicksort(arr, low, pivotIndex - 1);
    quicksort(arr, pivotIndex + 1, high);
  }
}

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

  // search for max consecutive
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