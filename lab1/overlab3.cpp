#include <iostream>
#include <vector>
#include <algorithm>

struct Person {
    int time;
    int type; // 0 for entering, 1 for exiting
};

int lomuto_partition(std::vector<Person> &vec, int low, int high) {
    int pivot = vec[high].time;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (vec[j].time < pivot || (vec[j].time == pivot && vec[j].type == 0)) {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }

    std::swap(vec[i + 1], vec[high]);
    return i + 1;
}

void quicksort(std::vector<Person> &vec, int low, int high) {
    if (low < high) {
        int pivotIndex = lomuto_partition(vec, low, high);
        quicksort(vec, low, pivotIndex - 1);
        quicksort(vec, pivotIndex + 1, high);
    }
}


int main() {
  int n;
  std::cin >> n;

  std::vector<Person> classroom;

  for (int i = 0; i < n; i++) {
    int start;
    std::cin >> start;
    classroom.push_back({start, 0});
  }

  for (int i = 0; i < n; i++) {
    int end;
    std::cin >> end;
    classroom.push_back({end, 1});
  }

  quicksort(classroom, 0, n * 2 - 1); // Sort by time

  int maxPresent = 0, currentPresent = 0, maxTime = 0;

  for (const auto& person : classroom) {
    if (person.type == 0) {  // entering
      currentPresent++;
    } else {  // exiting
      currentPresent--;
    }

    if (currentPresent > maxPresent) {
      maxPresent = currentPresent;
      maxTime = person.time;
    }
  }

  std::cout << maxTime << " " << maxPresent << "\n";
  for (const auto& person : classroom) {
    std::cout << "{" << person.time << ", " << person.type << "}, ";
  }
  std::cout << "\n";

  return 0;
}