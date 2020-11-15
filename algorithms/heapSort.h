#ifndef HEAP_SORT_H
#define HEAP_SORT_H

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void maxHeapify(int* arr, int index, int heapSize) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = 0;
    if (left < heapSize && arr[left] > arr[index]) {
        largest = left;
    }
    else {
        largest = index;
    }
    if (right < heapSize && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(arr[index], arr[largest]);
        maxHeapify(arr, largest, heapSize);
    }
}

void buildMaxHeap(int* arr, int n) {
    int heapSize = n;
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, i, heapSize);
    }
}

// heapSort
// arr - array, n - array size
void heapSort(int* arr, int n) {
    buildMaxHeap(arr, n);
    int heapSize = n;
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapSize--;
        maxHeapify(arr, 0, heapSize);
    }
}

#endif