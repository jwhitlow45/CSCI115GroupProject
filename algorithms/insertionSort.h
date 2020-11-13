#include<utility>
using namespace std;

void insertionSort(int arr[], size_t size)
{
	int i = 1;			//set i to second element in array (first element is sorted in while loop)
	while (i < size)	//iterate through entire array
	{
		int j = i;		//set j to i
		while (j > 0 && arr[j - 1] > arr[j])	//move backwards through the array
		{										//until the current element is greater
			swap(arr[j], arr[j - 1]);			//than the element before it
			j--;
		}
		i++;									//move to next element as elements [0..i] have been sorted
	}
}