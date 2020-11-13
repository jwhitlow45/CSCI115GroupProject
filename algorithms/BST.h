
#ifndef BST_H
#define BST_H
/*
	Author: Ryan Anderson
	Date: 11/5/2020
*/

/*
	This is a barebones BST used for conjunction with a HashTable that utilizes the Chaining Method of
	Collision resolution. A BST was chosen due to its ability to have slightly better running time than
	a linked list, and equivalent run-time in worst case scenario

	This version only takes integers as a parameter and has not been Generalized for other data types
	
	*/
class BST
{

public:
	//Internal Node Class
	class Node
	{
	public:
		//left child, right child, and the int value
		Node* left = nullptr;
		Node* right = nullptr;
		int value = NULL;
		
		
		Node(int value)
		{
			this->value = value;
			this->left = nullptr;
			this->right = nullptr;
		}
			

		int getVal()
		{
			return value;
		}
		~Node()
		{
		}
	};
	//Root node of the BST
	Node* root;
public:

	
	
	//Initialize the BST
	BST()
	{
		root = nullptr;		
	}

	//inserts a val into the BST, calling the overloaded function insert
	void insert(BST* tree, int val)
	{
		
		root = insert(root, val);
	}

	//inserts a new integer value into the BST, this does not allow duplicates.
	Node* insert( Node* node, int val)
	{
		//This ensures that if the root is null, that it becomes itself a new Node that is not null
		if (node == nullptr) return new Node(val);

		// if value is less, go left
		if (val < node->getVal()) node->left = this->insert( node->left, val);
		//else if value is greater go right
		else if (val > node->getVal()) node->right =  this->insert( node->right, val);
		//if value is equal to the current val, do nothing and return
		else return node;
		return node;
	}

	//Searches the BST and returns true if the value is found, false if not
	bool contains(int val)
	{
			
			if (root == nullptr) return false;
			Node* temp = this->root;
			//Iterates through the tree, if it reaches a nullptr, breaks the loop and return false
			//if the value is found, it stops iteration and returns true
			while (temp != nullptr)
			{
				if (val < temp->getVal()) temp = temp->left;
				else if (val > temp->getVal()) temp = temp->right;
				else return true;
			}
		
		
		return false;
	}

	int getVal(int val)
	{
		//indicating an error
		if (!this->contains(val)) return -1;


		Node* temp = root;
		
		while (temp != nullptr)
		{
			if (val < temp->getVal()) temp = temp->left;
			else if (val > temp->getVal()) temp = temp->right;
			else return temp->getVal();
		}

		return -1;
	}
	//Default Destructor
	~BST()
	{
		
	}
	
};
#endif


