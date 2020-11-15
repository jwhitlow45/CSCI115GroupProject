#ifndef HEAP_SORT_H
#define HEAP_SORT_H

/*
Theoretical Running Time of Heap Sort: O(n lg n)
The time complexity is O(n lg n) since there are two main parts to the
heap sort algorithm: building the heap property and then maintaining it on a reduced heap.
Building the max heap property takes O(n) time, and calling max heapify on n - 1 nodes takes
O(n lg n) times (since that's n calls to a lg n function, thus n*lg n). Since we drop
lower terms for asymptotic analysis, the running time is O(n lg n).
*/

// swap :: Params: x - first variable, y - second variable
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

// maxHeapify
// Params: arr - input array, index - desired node index, heapSize - desired heap size
void maxHeapify(int* arr, int index, int heapSize) {
    // Finds the indices of the left and right child of the current node
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = 0;

    // Finds the largest node
    if (left < heapSize && arr[left] > arr[index]) {
        largest = left;
    }
    else {
        largest = index;
    }
    if (right < heapSize && arr[right] > arr[largest]) {
        largest = right;
    }

    // If a new largest node is found, the largest node becomes the parent
    // and we recursively go down the tree.
    if (largest != index) {
        swap(arr[index], arr[largest]);
        maxHeapify(arr, largest, heapSize);
    }
}

// buildMaxHeap
// Params: arr - input array, n - array size
void buildMaxHeap(int* arr, int n) {
    // Satisfies heap property for every parent node, starting at the lower ones.
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, i, n);
    }
}

// heapSort
// Params: arr - input array, n - array size
void heapSort(int* arr, int n) {
    // Creates the heap property.
    buildMaxHeap(arr, n);

    // Iterates through each element
    int heapSize = n;
    for (int i = n - 1; i > 0; i--) {
        // Swaps the first element (max) with the last element
        swap(arr[0], arr[i]);
        
        // Restores heap property on reduced array.
        heapSize--;
        maxHeapify(arr, 0, heapSize);
    }
}

#endif