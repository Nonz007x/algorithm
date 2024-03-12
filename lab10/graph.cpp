#include <iostream>

typedef struct Node {
  int val;
} Node;

class LinkList {
  Node* next;

};

void DFS(int, int);
// void resetState(int[], int);
int G[10][10], visited[10], n;
int count = 0;
int main() {
  int i, j;
  std::cin >> n;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      std::cin >> G[i][j];
    }
  }

  for (i = 0; i < n; i++) {
    visited[i] = 0;
  }
  DFS(0, 7);
  std::cout << count << "\n";
  
  return 0;
}

void DFS(int i, const int key) {
  int j;
  std::cout << i << " ";
  if (i == key) {
    count++;
    std::cout << "0" << " ";
    return;
  }
  visited[i] = 1;
  for (j = 0; j < n; j++) {
    if (!visited[j] && G[i][j] == 1) {
      DFS(j, key);
    }
  }
  visited[i] = 0;
}