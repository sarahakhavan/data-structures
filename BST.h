//Sarah Akhavan Kazemzadeh
//9231057
//Data structures / final-project : BST.h 
//[The interface of Binary Search Tree template]


#ifndef __BST
#define __BST

#include <iostream>

namespace DS{
	template <class T>
	class BST
	{
	public:
		struct BSTNode;
	public:

		//data:

		BSTNode* root;
		BSTNode* current;

		//constructors:
		BST();
		//destrcutors:
		~BST();

		//functions:
		void insert(T data);
		void remove(T data);
		T find(T data);
		void clear();
		int size();

	private:
		//private data
		int BST_size;

		//private dunctions
		void freeBST(BSTNode* data);

	};//class BST
}//namespace DS
#endif