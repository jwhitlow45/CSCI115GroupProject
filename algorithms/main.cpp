#include<iostream>
#include "bubbleSort.h"
#include "countingSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "radixSort.h"
#include "selectionSort.h"
#include "heapSort.h"
#include <string>	// input verification
#include<cstdlib>	//srand and rand
#include <ctime>	// reseting seed for quickSort
#include <vector> // output times
#include<fstream>
using namespace std;

static const int GLOBAL_MAX = 200000000;
std::vector<string> sortNames = {"Insertion Sort", "Selection Sort",
								"Bubble Sort", "Merge Sort", "Quick Sort",
								"Heap Sort", "Counting Sort", "Radix Sort"};

//Helper function to call the chosen sorting algorithm
void sort(int* arr, int size, int algNum)
{
	switch (algNum)
	{
	case 0:
		insertionSort(arr, size);
		break;
	case 1:
		selectionSort(arr, size);
		break;
	case 2:
		bubbleSort(arr, size);
		break;
	case 3:
		mergeSort(arr, 0, size - 1);
		break;
	case 4:
		quickSort(arr, 0, size - 1);
		break;
	case 5:
		heapSort(arr, size);
		break;
	case 6:
		countingSort(arr, size);
		break;
	case 7:
		radixSort(arr, size);
		break;
	}
}

int* getSortArr(int size)
{
	int* arr = new int[size];
	for (size_t i = 0; i < size; i++)
		arr[i] = i;
	return arr;
}

int* getReverseSortArr(int size)
{
	int* arr = new int[size];
	for (size_t i = 0; i < size; i++)
		arr[i] = size - i - 1;
	return arr;
}

int* getRandomArr(int size)
{
	srand(4201337);
	int* arr = new int[size];
	for (size_t i = 0; i < size; i++)
		arr[i] = rand() % 50000;
	return arr;
}

int* getArr(int size, int arrType)
{
	switch (arrType)
	{
	case 0:
		return getSortArr(size);
	case 1:
		return getReverseSortArr(size);
	case 2:
		return getRandomArr(size);
	}
}

int main()
{
	int arrSizes[5] = { 1000000,5000000,10000000,100000000,200000000 };
	string arrOrder[3] = { "inOrder","reverseOrder","randomOrder" };
	fstream FILE;
	FILE.open("output-n.txt", ios::out);
	for (size_t sortAlgo = 5; sortAlgo < 8; sortAlgo++)
	{//different sorting algorithms
		for (size_t arrSize = 0; arrSize < 5; arrSize++)
		{//different array sizes
			for (size_t order = 0; order < 3; order++)
			{//different array orders
				for (size_t i = 0; i < 5; i++)
				{//run 5 times each
					//created new array of proper size
					int* arr = getArr(arrSizes[arrSize], order);

					clock_t time_t = clock();	//start time

					sort(arr, arrSizes[arrSize], sortAlgo); //perform sort

					time_t = clock() - time_t;	//end time
					string output = sortNames[sortAlgo] + "\nSize:" +
						to_string(arrSizes[arrSize])+ "\nOrder:" +
						arrOrder[order]+ "\nTime:" +
						to_string(double(time_t) / CLOCKS_PER_SEC)+
						" seconds\n\n";
					cout << output;
					FILE << output;
					delete arr;
				}
			}
		}
		cout << endl;
	}

	cout << "DONE.";
	return 0;
}