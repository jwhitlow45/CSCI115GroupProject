#pragma once



void merge(int arr[], int lo, int mid, int hi) {
	int n1 = mid - lo + 1;	//n1 and n2 are the sizes of 2 temps arrays.
	int n2 = hi - mid;

	int* leftArr = new int[n1 + 1];	//dynamically instantiate 2 temp arrays with additional index at the end.
	int* rightArr = new int[n2 + 1];
	leftArr[n1] = INT_MAX;			//Extra room at the end is for INT_MAX in place of infinity which indicates when the left or right side is depleted during comparison.
	rightArr[n2] = INT_MAX;

	for (int k = lo; k <= mid; k++) {			//Copies parameter array's values to left temp array
		leftArr[k - lo] = arr[k];
	}

	for (int k = mid + 1; k <= hi; k++) {		//Copies parameter in array's values to right temp array
		rightArr[k - (mid + 1)] = arr[k];
	}

	int i = 0;		//variable for incrementing left temp array 
	int j = 0;		//variable for incrementing right temp array 

	for (int k = lo; k <= hi; k++) {			//Logic that compares both subarray's elements for return an ascend sorted array:
		if (leftArr[i] <= rightArr[j]) {				//If the value in left temp array is smaller or equal to the value in right temp array,
			arr[k] = leftArr[i];						//then copy the left temp array's value to the original array 
			i++;								//increment the left sub-array
		}
		else {									//If the value in the right temp array is smaller,
			arr[k] = rightArr[j];				//then copy the right temp array's value to the original array 
			j++;								//incremment the right sub-array.
		}
	}

	delete[] leftArr;		//Delete both temp arrays
	delete[] rightArr;
}


void mergeSort(int arr[], int lo, int hi) {
	if (lo < hi) {					//Base case / exit condition: if the array size == 1
		int mid = (lo + hi) / 2;		//If not, find the mid point
		mergeSort(arr, lo, mid);		//Pass in the array's left side as a sub-array 
		mergeSort(arr, mid + 1, hi);	//Pass in the array's right side as a sub-array  
		merge(arr, lo, mid, hi);		//Merge sorted subarrays
	}
}

