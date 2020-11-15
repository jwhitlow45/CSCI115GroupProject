#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <iostream>
#include <vector>

// swap
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}


void buildMaxHeap(int* arr, int n) {
    int heapSize = n;
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i, heapSize);
    }
}

void maxHeapify(int* arr, int n, int index, int heapSize) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = 0;
    if (left < n && arr[left] > arr[index]) {
        largest = left;
    }
    else {
        largest = index;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(arr[index], arr[largest]);
        maxHeapify(arr, n, largest, n);
    }
}

void heapSort(int* arr, int n) {
    buildMaxHeap(arr, n);
    int heapSize = n;
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapSize--;
        maxHeapify(arr, n, 0, heapSize);
    }
}

#endif