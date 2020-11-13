#pragma once
//bubbleSort using arrays
void bubbleSort(int* arr, int n) { //function takes an array and arraysize as input
	for (int i = 1; i < n; i++) { 
	//i loop starts at the beginning of the array and iterates until the end of the array
		
		for (int j = n - 1; j > i; j--) { 
		//j loop starts at the end of the array and decrements until j = i+1
			
			if (arr[j] < a[j - 1]) { 
			//compares the elements in pairs starting at the end of the array
				
				int temp = arr[j]; //swaps arr[j] and arr[j-1] if arr[j-1] is larger than arr[j]
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		} //once j gets to i+1 
	} //i iterates forward and j goes back to the end of the array and the function repeats
}
