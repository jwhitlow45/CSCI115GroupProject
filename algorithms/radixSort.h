#pragma once
#include<cmath>
#include<iostream>

void radixSort(int* arr, int size, int radix)
{
	
	try{
	
		int* B = new int[size];
		int* C = new int[10]{0};
		
		int index = 0;
		
		for(int j = 0; j < size; j++)
		{
	
			B[j] = arr[j];	//init the "return" array as a copy of the original array
			//This approach is used to be able to dynamically de-allocate the extra memory inside the function
			
			//count the number of times a certain value appears
			//the integer is calculated by the number/(10^ radix) %10
			//the reduces the integer down to a number, that when 
			//you take the modulus 10 it returns a single digit value to be sorted by
			index =(arr[j]/((int)(pow(10, radix)))) % 10;
			
			C[index]++;
		}
	
		//Adjusts for the Off-by-one error later
		C[0]--;
	
	
		for(int k = 1; k < 10; k++)
		{	
			// calculate the amount of elements that will come before the last of the current element
			C[k] += C[k-1];
			
		}
			
		//starting from the end, iterate backwards through the copy of the original array and place values into the original array corresponding
		// to their relative index number saved in the auxiliary array C
		for(int l = size-1; l >=0 ; l--)
		{
			//grab the "index" number at the current radix
			index = (B[l]/(int)(pow(10, radix))) % 10;	
			//
			//put the value from the copied array into the original array by referencing the index number in C that corresponds
			// to the calculated index above		
			arr[C[index]] = B[l];
			
			//decrement the relative index value in C to show that the element has already been placed
			C[index]--;
		}
		
		// de-allocate the memory for the auxiliary arrays so your machine does not go boom
		delete[] C;
		delete[] B;
			
	}catch(std::bad_alloc ba)
	{
		std::cout<<"Could not allocate sufficient memory"<<std::endl;
		
	}catch(std::exception e)
	{
		std::cout<<"Array out of bounds probably"<<std::endl;
	}
	

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

	// repeat the counting sort method for each radix value
	for(int i = 0; i < radix; i++)
	{
		radixSort(arr, size, i);
	}

}
