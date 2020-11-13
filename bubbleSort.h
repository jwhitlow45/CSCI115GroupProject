#pragma once

void bubbleSort(int* a, int n) { //bubbleSort using arrays
	for (int i = 1; i < n; i++) { //i loop starts at the beginning and iterates until the end of the array
		for (int j = n - 1; j > i; j--) { //j loop starts at the end of the array and decrements till i+1
			if (a[j] < a[j - 1]) { //compares j and j-1 with each other
				int temp = a[j]; //swaps j and j-1 if j-1 is larger than j
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}
