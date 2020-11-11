#include<utility>
using namespace std;

void insertionSort(int arr[], size_t size)
{
	int i = 1;
	while (i < size)
	{
		int j = i;
		while (j > 0 && arr[j - 1] > arr[j])
		{
			swap(arr[j], arr[j - 1]);
			j--;
		}
		i++;
	}
}