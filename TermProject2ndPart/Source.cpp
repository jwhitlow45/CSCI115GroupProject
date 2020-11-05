#include <iostream>
#include "HashTableWChaining.h"
#include <vector>
#include <ctime>
#include <cstdlib>
std::vector<int> twoSum(std::vector<int> vec, int sum)
{
	if (vec.size() == 0) return vec;
	std::vector<int> retVec;
	HashTable seen;
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
			retVec.push_back(currVal);
			//This is a little redundant as i could just push back the sum-currVal, but i wanted to be thorough
			retVec.push_back(seen.get(sum - currVal));
			break;
		}
	}

	return retVec;
}

int main()
{
	srand(time(0));
	std::vector<int> myVec;

	for (int i = 0; i < 25; i++)
	{
		myVec.push_back(rand() % 15);
		std::cout << myVec[i] << " ";
	}
	std::cout << "\n\n" << std::endl;

	std::vector<int> twoSumVec = twoSum(myVec, 25);
	if (twoSumVec.size() == 0) std::cout << "There are no combinations..." << std::endl;
	else std::cout << "The two values in the original list that add to 25 are: ";
	for (int j : twoSumVec)
	{
		std::cout << j << " ";
	}
	


}