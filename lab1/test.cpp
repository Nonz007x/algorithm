#include <bits/stdc++.h>
using namespace std;

int counter = 0;
int maxCount = 0;
struct Node {
    int key;
    struct Node *left, *right;
};

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void heapify(int arr[], int arr2[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        swap(arr2[i], arr2[largest]);
        heapify(arr, arr2, n, largest);
    }
}

void heapSort(int arr[], int arr2[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, arr2, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        swap(arr2[0], arr2[i]);
        heapify(arr, arr2, i, 0);
    }
}

Node* newNode(int item)
{
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
void inorder(Node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d, ", root->key);
        inorder(root->right);
    }
}
 
Node* insert(Node* node, int key)
{

    if (node == NULL) {
        counter++;
        if(maxCount < counter) {
            maxCount = counter;
        }
        return newNode(key);
    }

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    return node;
}
 
Node* deleteNode(Node* root, int k)
{
    if (root == NULL)
        return root;

    if (root->key > k) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->key < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }
 
    if (root->left == NULL) {
        counter--;
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        counter--;
        Node* temp = root->left;
        delete root;
        return temp;
    }
 
    else {
        counter--;
        Node* succParent = root;
 
        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
 
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        root->key = succ->key;
 
        delete succ;
        return root;
    }
}

Node* deleteAll(Node* root, int k) {
     while (true) {
        Node* node = deleteNode(root, k);
        if (node == root) {
            break;
        }
        root = node;
    }
    return root;
}

int main()
{
    Node* root = NULL;
    int n;
    cin >> n;
    int a[n];
    int b[n];
    int maxPresentTime = 1;

    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++) {
        cin>>b[i];
    }
    
    heapSort(a, b, n);
    for (int i = 0; i < n; i++) {
        // cout << a[i] << " ";
    }
    // cout << "\n";
    for (int i = 0; i < n; i++) {
        // cout << b[i] << " ";
    }
    // cout << "\n";
    
    int currentTime = a[0];
    int stop = b[0];

    for (int i = 0; i < n; i++) {
        if (stop < b[i]) {
            stop = b[i];
        }
    }

    int i = 0;
    while(currentTime <= stop) {

        if (a[i] == currentTime) {
            root = insert(root, b[i]);
            if (counter == maxCount) {
                maxPresentTime = a[i]; 
            }
            if(a[i+1] == a[i]) {
                currentTime--;
            }
            i++;
        }

        root = deleteAll(root, currentTime);

        // cout << currentTime << ", " << i << ": ";
        // inorder(root);
        // cout << " : " << counter;
        // cout << "\n";
        currentTime++;
    }

    cout << maxPresentTime << " " << maxCount << "\n";
    return 0;
}
