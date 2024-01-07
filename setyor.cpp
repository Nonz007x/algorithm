#include <iostream>

class Sett {
private:
  struct Node {
    int data;
    Node* left;
    Node* right;

    Node(const int value) : data(value), left(nullptr), right(nullptr) {}
  };

  Node* root = nullptr;

  void insert(Node*& node, const int value) {

    if (!node) {
      node = new Node(value);
    } else if (node->data == value) {
      return;
    } else {
      insert(node->right, value);
    }
  }

  bool contains(Node* node, const int value) const {
    if (!node) {
      return false;
    } else if (node->data == value) {
      return true;
    } else {
      return contains(node->right, value);
    }
  }

  void preorder(Node* current) {
    if (!current)
      return;
    std::cout << current->data << " ";
    preorder(current->left);
    preorder(current->right);
  }

  void inorder(Node* current) {
    if (!current)
      return;
    inorder(current->left);
    std::cout << current->data << " ";
    inorder(current->right);
  }

  void postorder(Node* current) {
    if (!current)
      return;
    postorder(current->left);
    postorder(current->right);
    std::cout << current->data << " ";
  }

  void printAll(Node* current) {
    if (!current)
      return;
    std::cout << current->data << " ";
    printAll(current->right);
  }

public:
  void insert(const int value) {
    insert(root, value);
  } 

  bool contains(const int value) const {
    return contains(root, value);
  }

  void preorder() {
    preorder(root);
  }

  void inorder() {
    inorder(root);
  }

  void postorder() {
    postorder(root);
  }

  void printAll() {
    printAll(root);
  }

};  

int main() {
  Sett* a = new Sett;
  Sett* b = new Sett;
  Sett* intersectSet = new Sett;
  Sett* unionSet = new Sett;

  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int temp;
    std::cin >> temp;
    a->insert(temp);
    unionSet->insert(temp);
  }
  
  for (int i = 0; i < n; i++) {
    int temp;
    std::cin >> temp;
    b->insert(temp);
    unionSet->insert(temp);
    if (a->contains(temp)) {
      intersectSet->insert(temp);
    }
  }

  intersectSet->printAll();
  std::cout << "\n";
  unionSet->printAll();
  
  return 0;
}