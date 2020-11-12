#include<utility>
using namespace std;

void insertionSort(int arr[], size_t size)
{
	int i = 1;			//set i to second element in array (first element is sorted in while loop)
	while (i < size)	//iterate through entire array
	{
		int j = i;		//set j to i
		while (j > 0 && arr[j - 1] > arr[j])	//while j is in the array
		{										//and prev element > current element
			swap(arr[j], arr[j - 1]);				//swap prev and current element
			j--;									//dec j
		}
		i++;									//inc i
	}
}