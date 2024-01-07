void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void heapify(int arr[], int n, int parent) {
    int largest = parent;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;

    if (left < n && arr[left] > arr[parent])
        largest = left;

    if (right < n && arr[right] > arr[parent])
        largest = right;

    if (largest != parent) {
        swap(arr[parent], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}