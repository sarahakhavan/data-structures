//Sarah Akhavan Kazemzadeh
//9231057
//Data structures / final-project : BST.cpp 
//[implementation of Binary Search Tree and it's inner class (BSTNode)]

#include <iostream>
#include "BST.h"

namespace DS{
	template <class T>
	struct BST<T>::BSTNode
		{
			//data :
			T data;
			BSTNode* parent;
			BSTNode* leftChild; // pointer to the left child
			BSTNode* rightChild; // pointer to the right child

			//constructors of struct BSTNode
			BSTNode(T data)
			:data(data)
			,parent(NULL)
			,leftChild(NULL)
			,rightChild(NULL)
			{}//BSTNode(T data)

			BSTNode(T data,BSTNode* parent)
			:data(data)
			,parent(parent)
			,leftChild(NULL)
			,rightChild(NULL)
			{}//BSTNode(t data,BSTNode parent)

			//destructors
			~BSTNode(){}//~BSTNode

		};//struct BSTNode

		//constructors:
		template <class T>
		BST<T>::BST()
		:root(NULL)
		,current(NULL)
		,BST_size(0)
		{}//BST() / constructor

		//destructors:
		template <class T>
		BST<T>::~BST(){

		} // go delete all the nodes and then ... the end

		template <class T>
		void BST<T>::insert(T data){
			BSTNode* newNode = new BSTNode(data);
			if(root == NULL){// the bst is empty
				root = newNode;
				return;
			}//if
			else{
				BSTNode* prev = NULL;
				BSTNode* current = root;
				while(current){
					prev = current;
					if(newNode->data > current->data ){
						current = current->rightChild;
					}
					else{
						current = current->leftChild;
					}
				}//while

				newNode->parent = prev;
				if(newNode->data > prev->data ){
					prev -> rightChild = newNode;
				}
				else {
					prev->leftChild = newNode;
				}
				
			}
			BST_size ++;
		}//insert

		template<class T>
		void BST<T>::remove(T data){
			BSTNode* current = root;
			BSTNode* node = new BSTNode(data);
			while(current->data != node->data){
				if(node->data > current->data){
					current = current->rightChild;
				}
				else{
					current = current->leftChild;
				}
			}
			~current(); //need to be fixed
		}

		template <class T>
		T BST<T>::find(T data){
			BSTNode* temp = new BSTNode(data);
			BSTNode* current = root;
			while(current && current->data != temp->data){
				if(temp->data > current->data){
					current = current->rightChild;
				}
				else{
					current = current->leftChild;
				}
			}
			if(current)
				return current->data;
			// else throw exception
		}

		template <class T>
		void BST<T>::clear(){
			freeBST(root);
		}

		template <class T>
		int BST<T>::size(){
			return BST_size();
		}

		//private functions

		template <class T>
		void BST<T>::freeBST(BSTNode* node){
			if(node == NULL)
				return;
			if(node->leftChild)
				freeBST(node->leftChild);
			if(node->rightChild)
				freeBST(node->rightChild);
			node = NULL;
		}

}//namespace DS