#pragma once
#include<cmath>
#include<iostream>

int* radixSort(int* arr, int size, int i)
{
	int* C;
	int* B;
	//auxiliary array for counting
	try{
	
		B = new int[size+1];
		C = new int[10]{0};
	}catch(std::bad_alloc ba)
	{
		std::cout<<"Could not allocate sufficient memory"<<std::endl;
		return arr;
	}
	
		
		//init the count array to be full of 0's
		C = new int[10]{0};
		int index;
		
		for(int j = 0; j < size; j++)
		{
	
			//count the number of times a certain value appears
			//the integer is calculated by the number/(10^ radix) %10
			//the reduces the integer down to a number, that when 
			//you take the modulus 10 it returns a single digit value to be sorted by
			index =(arr[j]/((int)(pow(10, i)))) % 10;
			
			C[index]++;
		}
	
		//Adjusts for the Off-by-one error later
		C[0]--;
	
	
		for(int k = 1; k < 10; k++)
		{	
			// calculate the amount of elements that will come before the last of the current element
			C[k] = C[k] + C[k-1];
			
		}
			
		//starting from the end, iterate backwards through the original array and place duplicates into the final array
		for(int l = size-1; l >=0 ; l--)
		{
			
			index = (arr[l]/(int)(pow(10, i))) % 10;
			
			B[C[index]] = arr[l];
			C[index]--;
		}
	
		delete[] C;
		return B;
			

}

void radixSort(int* arr, int size)
{
	//Find the maximum element to determine the radix
	int max = 0;
	for(int i = 0; i < size; i++)
	{
		if(arr[i] > max) max = arr[i];
	}
	
	//Determine how many digits are in the max value, this determines the radix
	int radix = 0;
	while(max > 0)
	{
		radix++;
		max /= 10;
	}
	int* temp = arr;
	std::cout<<radix<<std::endl;
	for(int i = 0; i < radix; i++)
	{
		int* delTemp = temp;
		temp = radixSort(temp, size, i);
		if(delTemp != temp)
		{
			delete[] delTemp;
		} 		
	}
	arr = new int[size];
	for(int q = 0; q < size; q++)
	{
		arr[q] = temp[q];
	}


}
