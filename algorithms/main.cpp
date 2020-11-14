#include<iostream>
#include "algorithms/bubbleSort.h"
#include "algorithms/countingSort.h"
#include "algorithms/insertionSort.h"
#include "algorithms/mergeSort.h"
#include "algorithms/quickSort.h"
#include "algorithms/radixSort.h"
#include "algorithms/selectionSort.h"
#include <string>
#include <fstream>
#include<cstdlib>
#include <ctime>
#include<vector>
using namespace std;

std::vector<string> sortNames = {" ", "Insertion Sort", "Selection Sort", "Bubble Sort", "Merge Sort", "Quick Sort", "Counting Sort", "Radix Sort"};
//Strucutre to store information about a sorting algorithm 
//and related data for processing
struct info
{
	string algName;
	int inputSize;
	string inputState;
	float algTime;
};
	
	//Stores all the values gather after running algorithms
	std::vector<info> times;

//Helper function to call the chosen sorting algorithm
void sort(int* arr, int size, int algNum)
{
	if(algNum == 1)
	{
		insertionSort(arr, size);
		return;
	}
	else if(algNum == 2)
	{
		selectionSort(arr, size);
		return;
	}
	else if(algNum == 3)
	{
		bubbleSort(arr, size);
		return;
	}
	else if(algNum == 4)
	{
		mergeSort(arr, 0, size-1);
		return;
	}
	else if(algNum == 5)
	{
	
		quickSort(arr, 0, size-1);
		return;
	}
	else if(algNum == 6)
	{
		countingSort(arr, size);
		return;
	}
	else if(algNum == 7)
	{
		radixSort(arr, size);
		return;
	}
	else
	{
		cout<<"Invalid"<<endl;
	}
}

bool isSorted(int* arr, int size)
{
	for(int i = 0; i < size-1; i++)
	{
		if(arr[i] > arr[i+1]) return false;
		
	}
	return true;
}

//For string confirmation to ensure valid input, I have fat finger and always mistype, so this is for me...
bool checkString(string str)
{
	for(int t = 0; t < str.length(); t++)
	{
		if(!isdigit(str.at(t))) return false;
	}
	return true;	
}
/*
void sourceFromFile()
{
	
	
	//Relative path name for the input files, this is subject to change per user
	string relativePathName = "CSCI115GroupProject\\inputs\\";
	//Algorithm Names
	std::vector<string> sortNames = {" ", "Insertion Sort", "Selection Sort", "Bubble Sort", "Merge Sort", "Quick Sort", "Counting Sort", "Radix Sort"};
	
	//File Names, this is subject to change
	vector<string> fileNames = {"smallInputRandom.txt","smallInputReverse.txt","smallInputRandom.txt",  "mediumInputOrder.txt",  "mediumInputReverse.txt",
	 "mediumInputRandom.txt","largeInputOrder.txt", "largeInputReverse.txt", "largeInputRandom.txt" };
	 
	 //Strucutre to store information about a sorting algorithm 
	 //and related data for processing
	struct info
	{
		string algName;
		int inputSize;
		string inputState;
		float algTime;
	};
	
	//Stores all the values gather after running algorithms
	std::vector<info> times;

	
//label to easily restart the program
restart:
	
	//Local variables the pertain to user choices
	int inputSizeChoice, count, order, sortChoice;
	std::string inBuf, orderBuf, fileName, inputState, sortChoiceBuffer;
	
	
	std::cout << "Please make a selection: " << std::endl;
	std::cout << "Please Choose Input Size:\nSmall(1: 1,000)\nMedium(2: 1,000,000)\nLarge(3: 10,000,000)\n>>: ";
	
	do{
		std::getline(std::cin, inBuf);
	}while(inBuf == "" || (inBuf != "1" && inBuf != "2" && inBuf != "3"));
	inputSizeChoice = stoi(inBuf, nullptr, 0);
	std::cout << "Please Choose Input Order:\nAscending(1)\nDescending(2)\nRandomized(3)\n>>: ";


	
		do{
		std::getline(std::cin, orderBuf);
	}while(orderBuf == "" || (orderBuf != "1" && orderBuf != "2" && orderBuf != "3"));
	order = stoi(orderBuf, NULL, 0);
	
	//select the appropriate file name
	if(inputSizeChoice == 1 && order == 1)
	{
		fileName = fileNames[0]; inputState = "Ascending";
	}
	else if(inputSizeChoice == 1 && order == 2)
		{fileName =  fileNames[1]; inputState = "Descending";}
		
	else if(inputSizeChoice == 1 && order == 3)
		{fileName =  fileNames[2]; inputState = "Random";}
	
	else if(inputSizeChoice == 2 && order == 1)
		{fileName =  fileNames[3]; inputState = "Ascending";}
		
	else if(inputSizeChoice == 2 && order == 2)
		{fileName =  fileNames[4]; inputState = "Descending";}
	
	else if(inputSizeChoice == 2 && order == 3)
		{fileName =  fileNames[5]; inputState = "Random";}
	
	else if(inputSizeChoice == 3 && order == 1)
		{fileName =  fileNames[6]; inputState = "Ascending";}
		
	else if(inputSizeChoice == 3 && order == 2)
		{fileName =  fileNames[7]; inputState = "Descending";}
		
	else if(inputSizeChoice == 3 && order == 3)
		{fileName =  fileNames[8]; inputState = "Random";}
	else
		fileName =  fileNames[2]; inputState = "Random";
		
	cout<<"You have Chosen: " << fileName<<endl;
	fileName = relativePathName + fileName;
	
	cout<<"Choose Your Algorithm (Queue Smash Bros Theme):"<<endl;
	std::cout << "Insertion Sort (1)\nSelection Sort(2)\nBubble Sort(3)\nMerge Sort(4)\nQuick Sort(5)\nCounting Sort(6)\nRadix Sort(7)\n>>: ";
	
	do{
		std::getline(std::cin, sortChoiceBuffer);
	}while(sortChoiceBuffer == "" || (sortChoiceBuffer != "1" && sortChoiceBuffer != "2" && sortChoiceBuffer != "3"
										&& sortChoiceBuffer != "4" && sortChoiceBuffer != "5" && sortChoiceBuffer != "6"
										 && sortChoiceBuffer != "7" ));
	sortChoice = stoi(sortChoiceBuffer, NULL, 0);
	
	cout<<"Would you like to automatically repeat this selection? Y/N"<<endl;
	bool doRepeat = false;
	string answer;
	do{
		getline(cin, answer);
	}while(answer != "Y" && answer != "y" && answer != "n"&& answer != "N");
	if(answer == "Y" || answer == "y")
	{
		doRepeat = true;
		
		cout<<"How many times would you like this to repeat?"<<endl;
		string countBuf;
		do{
			getline(cin, countBuf);
		}while(!checkString(countBuf));
		count = stoi(countBuf);
	}
	
repeat:
	try
	{
		int* arr;
		int size;
	
		//Ensure the file has the appropriate .txt extension
		if (fileName.find(".txt") == std::string::npos) fileName += ".txt";
	repCount:
		if(doRepeat)cout<<count<<" more times..."<<endl;
		std::ifstream inputStream;
		inputStream.open(fileName);
		if (inputStream.is_open())
		{
			//First Element in the file is the list size
			std::string sizeBuf;
			std::getline(inputStream, sizeBuf, ',');
			size = stoi(sizeBuf, nullptr, 0);
			//init  a new array
			arr = new int[size];
			int i = 0;
			string temp;
			cout<<"Loading..."<<endl;
			//For larger inputs, this may take a while
			while (std::getline(inputStream, temp, ',')) { arr[i++] = stoi(temp, NULL, 0); }
			
			//clear the screen
			for(int i = 0; i < 50; i++) cout<<endl;
			//start the sorting algorithm
			std::cout << "Successful Read\nSuccessful array initiation" << std::endl;
			cout<<"Starting Sort:  " << sortNames[sortChoice]<<endl;
			//start time in miliseconds
			time_t beg = clock();
			sort(arr, size, sortChoice);
			//total time = ending time - beginning time
			time_t time = clock() - beg;
			//convert to a float for human interpretation
			float secs = (float)time/CLOCKS_PER_SEC;
			cout<<"Verifying correctness..."<<endl;
			//double check the the array is sorted
			if(isSorted(arr, size)) {
				cout<<"All Good"<<endl;
				times.push_back(info{ sortNames[sortChoice], size, inputState, secs});
			}
			else 
			{
				cout<<"Something Went Wrong..."<<endl;
				return;
			}
			std::cout<<"Phew...that took: " << secs <<" seconds"<<endl;
			if(doRepeat)
			{
				if(count > 1)
				{
					delete[] arr;
					inputStream.close();
					count--;
					goto repCount;
				}
				else doRepeat = false;
			}
			//This will replay the current sort for gathering times
			cout<<"Repeat this sort? Y/N"<<endl;
			string answer;
			getline(cin, answer);
			if(answer == "y" || answer == "Y")
			{
				//clear the current array to save memory
				delete[] arr;
				inputStream.close(); //close the input stream
				goto repeat; //jump to repeat label
			}
			cout<<"Start from the Beginning? Y/N"<<endl;
			getline(cin, answer);
			if(answer == "y" || answer == "Y")
			{
				delete[] arr;	// delete array to save memory
				inputStream.close();	//close input stream
				for(int i = 0; i < 50; i++) cout<<endl;	//clear the screen
				goto restart;	//this jumps to the beginning
			}
			
			
		}
		else cout<<"Failure"<<endl;	//file could not be open
		
		if(inputStream.is_open()) inputStream.close();	// close stream if it is still open
	}
	catch (std::exception& e)
	{
		std::cout << "Input Error" << std::endl;
	}
	for(int i = 0; i < 50; i++) cout<<endl; // clear screen
	
	//Output all the data
	for(info j : times)
	{
		cout<<"AlgName: "<<j.algName<<endl;
		cout<<"Input Size: "<<j.inputSize<<endl;
		cout<<"Order: " << j.inputState<<endl;
		cout<<"Time: " << j.algTime <<endl;
		cout<<"==================\n\n"<<endl;
	}
	
}
*/
void soruceFromSrand()
{
restart:	
	int inputSize, order, srandSeed, sortChoice, count;
	std:string inputSizeBuf, orderBuf, srandSeedBuf, sortChoiceBuffer, countBuf, inputState;
	bool doRepeat = false;
	
//=======================================================================================//	
							/*Input Selection*/
	std::cout<<"Please Enter Input Size: ";	
	do{
		getline(cin, inputSizeBuf);
	}while(!checkString(inputSizeBuf));	// check string ensures that the input is a number
	inputSize = stoi(inputSizeBuf, NULL, 0);

//=======================================================================================//	
							/*Order Selection*/

	std::cout << "Please Choose Input Order:\nAscending(1)\nDescending(2)\nRandomized(3)\n>>: ";
	do{
		getline(cin, orderBuf);
	}while(orderBuf == "" || (orderBuf != "1" && orderBuf != "2" && orderBuf != "3"));
	order = stoi(orderBuf, NULL, 0);
	
	if(order == 3)
	{
		cout<<"Please choose Seed Value for RNG: "<<endl;
		do{
		getline(std::cin, srandSeedBuf);
		}while(!checkString(srandSeedBuf));	// check string ensures that the input is a number
		srandSeed = stoi(srandSeedBuf);
	
	}
	
//=======================================================================================//	
							/*Algorithm Selection*/
	cout<<"Choose Your Algorithm (Queue Smash Bros Theme):"<<endl;
	std::cout << "Insertion Sort (1)\nSelection Sort(2)\nBubble Sort(3)\nMerge Sort(4)\nQuick Sort(5)\nCounting Sort(6)\nRadix Sort(7)\n>>: ";
	
	do{
		std::getline(std::cin, sortChoiceBuffer);
	}while(sortChoiceBuffer == "" || (sortChoiceBuffer != "1" && sortChoiceBuffer != "2" && sortChoiceBuffer != "3"
										&& sortChoiceBuffer != "4" && sortChoiceBuffer != "5" && sortChoiceBuffer != "6"
										 && sortChoiceBuffer != "7" ));
	sortChoice = stoi(sortChoiceBuffer, NULL, 0);
	
//=======================================================================================//	
							/*Would You Like Some More*/
	cout<<"Would you like to automatically repeat this selection? Y/N"<<endl;
	doRepeat = false;
	string answer;
	do{
		getline(cin, answer);
	}while(answer != "Y" && answer != "y" && answer != "n"&& answer != "N");
	if(answer == "Y" || answer == "y")
	{
		doRepeat = true;
		
		cout<<"How many times would you like this to repeat?"<<endl;
		string countBuf;
		do{
			getline(cin, countBuf);
		}while(!checkString(countBuf));
		count = stoi(countBuf ,NULL, 0);
	}
repeat:
//=============================================================================================//
						/*ARRAY CREATION*/
						
	repCount:
	
	if(doRepeat)cout<<count<<" more times..."<<endl;
	//instantiate a new array
	int* arr = new int[inputSize];
	
	//fill with asceding values
	if(order == 1)
	{	
		inputState = "Ascending";
		for(int i = 0; i < inputSize; i++)
		{
			arr[i] = i;
		}
	}
	else if(order == 2)	// fill with descending values
	{
		inputState = "Descending";
		for(int i = inputSize-1; i >= 0; i--)
		{
			arr[i] = i;
		}
	}
	else	//default to random
	{
		inputState = "Randomized";
		srand(srandSeed);
		for(int i = 0; i < inputSize; i++) //the seed sets srand to the same set of random ints, this should allow for the same "random" number sets across machines
		{
			arr[i] = rand() % 50000;
		}
	}
	
//=========================================================================//
					/*Starting array Sort*/
			
			std::cout << "Successful Read\nSuccessful array initiation" << std::endl;
			cout<<"Starting Sort:  " << sortNames[sortChoice]<<endl;
			//start time in miliseconds
			time_t beg = clock();
			sort(arr, inputSize, sortChoice);
			//total time = ending time - beginning time
			time_t time = clock() - beg;
			//convert to a float for human interpretation
			float secs = (float)time/CLOCKS_PER_SEC;
			cout<<"Verifying correctness..."<<endl;
			//double check the the array is sorted
			if(isSorted(arr, inputSize)) {
				cout<<"All Good"<<endl;
				times.push_back(info{ sortNames[sortChoice], inputSize, inputState, secs});
			}
			else 
			{
				cout<<"Something Went Wrong..."<<endl;
				return;
			}
			std::cout<<"Phew...that took: " << secs <<" seconds"<<endl;
			if(doRepeat)
			{
				if(count > 1)
				{
					delete[] arr;
					count--;
					goto repCount;
				}
				else doRepeat = false;
			}
			//This will replay the current sort for gathering times
			cout<<"Repeat this sort? Y/N"<<endl;
			answer = "";
			getline(cin, answer);
			if(answer == "y" || answer == "Y")
			{
				//clear the current array to save memory
				delete[] arr;
				
				goto repeat; //jump to repeat label
			}
			cout<<"Start from the Beginning? Y/N"<<endl;
			getline(cin, answer);
			if(answer == "y" || answer == "Y")
			{
				delete[] arr;	// delete array to save memory
				
				for(int i = 0; i < 50; i++) cout<<endl;	//clear the screen
				goto restart;	//this jumps to the beginning
			}
			
		
}

int main()
{
	soruceFromSrand();

}
