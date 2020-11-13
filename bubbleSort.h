#pragma once
#include <iostream>
#include <array>

using namespace std;

void bubbleSort(int* a, int n) { //bubbleSort using arrays
	for (int i = 1; i < n; i++) { //loop starts at the beginning
		for (int j = n - 1; j > i; j--) { //loop starts at the end
			if (a[j] < a[j - 1]) { //compares j and j-1 with eachother
				int temp = a[j]; //swaps j and j-1 if j-1 is larger than j
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}