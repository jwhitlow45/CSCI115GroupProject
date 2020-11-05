#pragma once
#ifndef HASH_H
#define HASH_H
#include "BST.h"

/*
		This is a barebones implementation of a hashtable, it currently does not support
		a delete function for any element, nor does it keep track of the number of 
		elements within the hash table. It utilizes a Chaining method of collision resolution
		by use of Binary Search Trees. Due to their simplicity, and slight performance improvement
		for searching, they were chosen over a linked list. 

		This implementation uses an Array of 10 BST pointers, this ensures some collisions, but also
		reduces overhead memory costs as much as possible.
*/
class HashTable
{
public:
	static const int tableSize = 10;
private:
	
	//returns an index value for a given integer value
	int hashcode(int val)
	{
		return (27 * val) % tableSize;
	}
public:
	/*Main "table" of the hash table
	Uses the static variable tableSize to 
	reserve 10 indexes*/
	BST* table[tableSize];

	HashTable()
	{
		
		//Initialize each index to point to a freshly created BST
		for (int i = 0; i < tableSize; i++)
		{
			table[i] = new BST();
		}
		return;
	}

	/*
		insert() calls the interal hashcode function to determine an index point of the 
		value to be inserted
		Then it checks to see if the value has already been inserted into the BST
		located at the given index. If it has not already been inserted, then it
		proceeds to insert it, otherwise it just returns
	*/
	void insert(int val)
	{
		int index = this->hashcode(val);
		if (!table[index]->contains(val)) table[index]->insert(val);

		return;
	}

	/*
		contains() finds the appropriate index for the integer value passed to it, 
		then runs the contains() method of the BST at that index and
		returns the boolean value that is returned from the BST.
		If the value is found, it returns true, and false otherwise
	*/
	bool contains(int val)
	{
		int index = this->hashcode(val);
		return table[index]->contains(val);

	}

	int get(int val)
	{
		int index = this->hashcode(val);
		return table[index]->getVal(val);
	}


};

#endif

