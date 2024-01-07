#include <iostream>

class Set {
private:
  struct Node {
    int data;
    Node* next;

    Node(const int value) : data(value), next(nullptr) {}
  };

  Node* root = nullptr;

  bool insert(Node*& node, const int value) {

    if (!node) {
      node = new Node(value);
      return true;
    } else if (node->data == value) {
      return false;
    } else {
      insert(node->next, value);
    }
  }

  bool contains(Node* node, const int value) const {
    if (!node) {
      return false;
    } else if (node->data == value) {
      return true;
    } else {
      return contains(node->next, value);
    }
  }

  void printAll(Node* current) {
    if (!current)
      return;
    std::cout << current->data << " ";
    printAll(current->next);
  }

public:
  bool insert(const int value) {
    insert(root, value);
  } 

  bool contains(const int value) const {
    return contains(root, value);
  }

  void printAll() {
    printAll(root);
  }
};

int main() {
  int n;
  Set* set = new Set;
  int specificCount = 0;

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    if (set->insert(num)) {
      specificCount++;
    }
  }

  std::cout << specificCount;

  return 0;
}