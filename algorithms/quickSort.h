#pragma once
#include<iostream>
using namespace std;
/*
Swap
1.) Swaps values given array values by index
*/
void swap(int Array[], int &numberA, int &numberB) {
	int temp = Array[numberA];
	Array[numberA] = Array[numberB];
	Array[numberB] = temp;
}

/*
Partition:
1.) Finds a pivot value
	1a. Reason for special calculation is to keep in range of the right side of the array
2.) pivot and left value is swapped
3.) i starts at the second value of the array and j starts at the last value
4.) i increments if the value it is at is less than pivot. Then stops when it finds something great than
5.) j decrements if the value is greater than pivot. Then stops when its less than pivot
6.) if i and j haven't crossed i and j swap values in the array
7.) if they have crossed j and left swap values in the aray
8.) Then the function returns j
*/

int randPartition(int myArray[], int left, int right) {
	int i, j, pivot;
	pivot = (rand() % (right - left)) + left;	// encapsulated rand() % (right-left) and changed order, it works this way for some reason...
	swap(myArray, left, pivot);
	i = left;	//line 34 uses <= which allows you to start from the beginning
	j = right;
	while (true) {
		while (myArray[i] <= myArray[left]) {
			if (i >= right) {	// changed == to >= for safety
				break;
			}
			i++;
		}
		while (myArray[j] > myArray[left]) {	//changed >= to >, if >= then it will potentially go out of bounds
			if (j <= left) {	// changed == to <= for safety
				break;
			}
			j--;
		}
		if (i < j) {
			swap(myArray, i, j);
		}
		else {
			swap(myArray, left, j);
			return j;
		}
	}
}
/*
Quick Sort Function:
1.) Takes Array finds the partition (At this point also sorts it)
2.) When partion is found, quicksort does the same thing to the left side
3.) When left side recursive call is done, right side is called
*/

void quickSort(int myArray[], int left, int right) {
	if (left < right) {
		int part = randPartition(myArray, left, right);
		quickSort(myArray, left, part - 1);
		quickSort(myArray, part + 1, right);
	}
}
