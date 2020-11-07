#pragma once

void countingSort(int* arr, int size)
{
	//Determine the range for the Auxiliary Array C by taking the maximum value
	int max = 0;
	for(int i = 0; i < size; i++)
	{
		if(arr[i] > max) max = arr[i];
	}	
	int* B;
	int* C;
	//attempt to allocate more memory
	try{
		//Create the return array
		B = new int[size];	
		// create an auxiliary array
	    C = new int[max+1]{0};
	
	}catch(std::bad_alloc& ba)
	{
		//catch bad_alloc exception
		std::cout<<"Memory Could Not Be Allocated, Terminating Function"<<std::endl;
	}


	for(int j = 0; j < size; j++)
	{
		//count the number of times a certain value appears
		C[arr[j]]++;
	}
	
	//Adjusts for the Off-by-one error later
	C[0]--;
	
	
	for(int k = 1; k <= max; k++)
	{	
		// calculate the amount of elements that will come before the last of the current element
		C[k] = C[k] + C[k-1];
	}
	
	//starting from the end, iterate backwards through the original array and place duplicates into the final array
	for(int l = size-1; l >=0 ; l--)
	{
		B[C[arr[l]]] = arr[l];
		C[arr[l]]--;
	}


	//De-allocate memory
	delete[] C;
	
	//Rre-write original array
	for(int i = 0; i < size; i++)
	{
		arr[i] = B[i];
	}
	delete[] B;		
}

