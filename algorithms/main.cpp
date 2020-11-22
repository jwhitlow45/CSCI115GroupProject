#include<iostream>	//output to console
#include <string>	//user input
#include <ctime>	//measure algorithm times
#include<fstream>	//outputing results to txt file

#include "bubbleSort.h"
#include "countingSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "radixSort.h"
#include "selectionSort.h"
#include "heapSort.h"

using namespace std;

//returns sorted array of size size
int* getSortArr(int size)
{
	int* arr = new int[size];
	for (size_t i = 0; i < size; i++)
		arr[i] = i;
	return arr;
}

//returns reverse sorted array of size size
int* getReverseSortArr(int size)
{
	int* arr = new int[size];
	for (size_t i = 0; i < size; i++)
		arr[i] = size - i - 1;
	return arr;
}

//returns random array of size size, range [0-50,000)
int* getRandomArr(int size)
{
	srand(4201337);
	int* arr = new int[size];
	for (size_t i = 0; i < size; i++)
		arr[i] = rand() % 50000;
	return arr;
}

//returns array of size size and type arrType
/*
	0-sorted
	1-reverse sorted
	2-random
*/
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

//Funciton allowing calling of specific algorithms
/*
	0-insertionSort
	1-selectionSort
	2-bubbleSort
	3-mergeSort
	4-quickSort
	5-heapSort
	6-countingSort
	7-radixSort
*/
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
	default:
		cout << "ERROR: Not a valid input" << endl;
	}
}

int main()
{
	string userSortAlgo;	//sorting algo from user
	string userArrSize;		//arr size from user
	string userArrOrder;	//arr order from user
	string userNumRepeat;	//number of times to repeat from user
	char userResponse;		//reponse from user to run algorithm again

	//indexed algorithm names and arr orders to allow output to be organized
	string sortNames[8] = { "Insertion Sort","Selection Sort",
							"Bubble Sort", "Merge Sort", "Quick Sort",
							"Heap Sort","Counting Sort", "Radix Sort" };
	string arrOrder[3] = { "inOrder","reverseOrder","randomOrder" };
	fstream FILE;
	FILE.open("output.txt", ios::out);

	do
	{
		cout << "0 - insertionSort\n"
				<< "1 - selectionSort\n"
				<< "2 - bubbleSort\n"
				<< "3 - mergeSort\n"
				<< "4 - quickSort\n"
				<< "5 - heapSort\n"
				<< "6 - countingSort\n"
				<< "7 - radixSort\n";
		cout << "Algorithm to run?: ";
		getline(cin, userSortAlgo);
		cout << "\nNOTE:Algorithms can stack overflow due to space complexity";
		cout << "\nSize of array?: ";
		getline(cin, userArrSize);
		cout << "\n0 - sorted\n"
				<< "1 - reverse sorted\n"
				<< "2 - random\n";
		cout << "Array order?: ";
		getline(cin, userArrOrder);
		cout << "\nNumber of times to repeat?: ";
		getline(cin, userNumRepeat);
		cout << endl << endl;

		//run test user specified number of times
		for (size_t i = 0; i < stoi(userNumRepeat); i++)
		{
			//created new array of user specified size and order
			int* arr = getArr(stoi(userArrSize), stoi(userArrOrder));

			clock_t time_t = clock();	//start time

			sort(arr, stoi(userArrSize), stoi(userSortAlgo)); //perform sort

			time_t = clock() - time_t;	//end time
			string output = sortNames[stoi(userSortAlgo)] +
				"\nSize:" + userArrSize +
				"\nOrder:" + arrOrder[stoi(userArrOrder)] + 
				"\nTime:" + to_string(double(time_t) / CLOCKS_PER_SEC) +
				" seconds\n\n";
			cout << output;	//print results to console
			FILE << output;	//store results in file
			delete[] arr;
		}

		cout << "Run another algorithm?(y/n): ";
		cin >> userResponse;
		cin.ignore();

	} while (tolower(userResponse) == 'y');

	FILE.close();
	return 0;
}