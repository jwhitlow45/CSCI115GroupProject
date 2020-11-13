#pragma once

void swap(int* val1, int* val2) {
	int temp  = *val1;
	*val1 = *val2;
	*val2 = temp;
}

void selectionSort(int selection[], int size) { // passes in the array and the size of the array
	for (int i = 0; i < size; i++) { // traverses vector
		int min = i; // the min element is initially the leftmost element
		for (int j = i + 1; j < size; j++) { // j will traverse the vector to the right
			if (selection[j] < selection[min]) // if j finds an element smaller than the min -
				min = j; // the element at j becomes the new min
		}
		swap(&selection[i], &selection[min]); // the minimum will always swap with the element at i even if i is the minimum
	}
}
