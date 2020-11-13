#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "HashTableWChaining.h"


std::vector<int> twoSum(std::vector<int> vec, int sum)
{
	if (vec.size() == 0) return vec;
	std::vector<int> retVec;
	// Using a hash table that utilizes chaining to store the values already seen
	// this allows quick access in O(1) time for every element we pass in the main list
	HashTable seen;

	//currVal is just so i dont have to type vec[i] a lot
	int currVal;
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		//currVal on declared cause i dont want to retype vec[i]
		currVal = vec[i];
		//If the corresponding value that adds to sum has not been seen yet, add the current
		//value to the hash table
		if (!seen.contains(sum - currVal)) seen.insert(currVal);
		else
		{
			//save the current value
			retVec.push_back(currVal);
			//This is a little redundant as i could just push back the sum-currVal, but i wanted to be thorough
			retVec.push_back(seen.get(sum - currVal));
			//Now that you have found a pair, break out of the loop
			break;
		}
	}

	return retVec;
}

int main()
{
	srand(time(0));
	std::vector<int> myVec;

	//Add 25 random values up to 35
	for (int i = 0; i < 25; i++)
	{
		myVec.push_back(rand() % 36);
		//This outputs the values to be able to check correctness
		std::cout << myVec[i] << " ";
	}
	std::cout << "\n\n" << std::endl;

	//initialize the answer vector via the twoSum function, this will have the 2 values that add to 25
	//if there are any
	std::vector<int> twoSumVec = twoSum(myVec, 25);

	//output the needed messages, one for an empty list, one for a populated list
	if (twoSumVec.size() == 0) std::cout << "There are no combinations..." << std::endl;
	else std::cout << "The two values in the original list that add to 25 are: ";
	for (int j : twoSumVec)
	{
		std::cout << j << " ";
	}
	std::cout << "\n" << std::endl;


}